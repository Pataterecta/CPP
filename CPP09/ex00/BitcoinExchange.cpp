#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& orig) : _datas(orig._datas)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& orig)
{
    if (this != &orig)
    {
        this->_datas = orig._datas;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

bool BitcoinExchange::parseDouble(const std::string& str, double& resD)
{
    char* end_ptr;
    end_ptr = NULL;
    errno = 0;

    if (str.empty())
    {
        // no value which is contrary to "date | value"
        return false;
    }
    resD = std::strtod(str.c_str(), &end_ptr);
    if (errno == ERANGE)
    {
        // std::cerr << "Error: ERANGE overflow or underflow.\n";
        return false;
    }
    while (*end_ptr != '\0' && std::isspace(static_cast<unsigned char>(*end_ptr)))
        end_ptr++;
    if (*end_ptr != '\0' || end_ptr == str.c_str())
    {   
        // std::cerr << "Error: value is not only numbers.\n";
        return false;
    }
    if (std::isnan(resD) == true) // "nanf" "+nanf" "-nanf" NaN INFINITY kind of
    {   
        // std::cerr << "Error: value is nan.\n";
        return false;
    }
    if (std::isinf(resD) == true)
    {
        // std::cerr << "Error: value is inf.\n";
        return false;
    }
    return true;
}

bool BitcoinExchange::parsePosInt(const std::string& str, int& out)
{
    char* end_ptr;
    end_ptr = NULL;
    errno = 0;

    // 2011-01-03
    long val = std::strtol(str.c_str(), &end_ptr, 10);

    if (str.empty() || *end_ptr != '\0' || errno == ERANGE || end_ptr == str.c_str())
        return false;

    if (val < 0 || val > std::numeric_limits<int>::max()) // value check before casting
        return false;

    out = static_cast<int>(val);
  
    return true;
}

bool twonineY(int y)
{
    if (y % 4 != 0)
        return false;
    if (y % 100 != 0)
        return true;
    return (y % 400 == 0); // %100 oki and then %400 oki -> 윤년 아님 평년
    // true for leap year
}

bool BitcoinExchange::parseDate(const std::string& str)
{
    int y;
    int m;
    int d;
    if (str.size() != 10)
        return false;
    if (str[4] != '-' || str[7] != '-')
        return false;
    
    std::string year = str.substr(0, 4);
    if (!parsePosInt(year, y))
        return false;

    std::string month = str.substr(5, 2);
    if (!parsePosInt(month, m))
        return false;

    std::string day = str.substr(8, 2);
    if (!parsePosInt(day, d))
        return false;
    
    // if (y <= 2008) // need to check on 2009 better on the other func
    //     return false;
    
    if (m < 1 || m > 12)
        return false;
    
    int ndays[] = {31, 28 + twonineY(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 4로 나눠 떨어지면 윤년 -> 100으로 나눠 떨어지면 평년 -> 근데 400으로 나눠 떨어지면 윤년
    if (d < 1 || d > ndays[m - 1])
        return false;
    return true;
}

void BitcoinExchange::trim(std::string &str)
{
    size_t start = str.find_first_not_of(" \t\v\f\r\n");
    if (start == std::string::npos)
    {
        str.clear();
        return ;
    }
    size_t end = str.find_last_not_of(" \t\v\f\r\n");
    str = str.substr(start, end - start + 1);
}

void BitcoinExchange::parseCsv(std::ifstream&  givenCsv)
{
    std::string line;

    std::getline(givenCsv, line); 
    // trim(line); // for the header I chose to go strict.. only soft with user input probable part
    if (line != "date,exchange_rate")
    {
        std::cerr << "Error: wrong header on data file.\n";
        return ;
    }

    while (std::getline(givenCsv, line)) // from the second line
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);
        trim(date);
        trim(rateStr);
    
        double rate;
        if (!parseDate(date) || rateStr.empty() || !parseDouble(rateStr, rate))
        {
            std::cerr << "Error: corrupted csv file.\n";
            return ;
        }
        if (rate < 0)
        {
            std::cerr << "Error: corrupted csv file.\n";
        }
        _datas[date] = rate;
    }
    // givenCsv.close(); // c++ close check no need
    
}

void BitcoinExchange::treatInf(std::ifstream&  inputf)
{
    if (_datas.empty())
    {
        std::cerr << "Error: empty csv database to compare.\n"; // extra, for the coherence
        return ;
    }
    
    std::string line;
    std::getline(inputf, line);
    // trim(line); // for the header I chose to go strict.. only soft with user input probable part
    if (line != "date | value")
    {
        std::cerr << "Error: wrong header on data file.\n";
        return ;
    }

    while (std::getline(inputf, line)) // from the second line
    {
        if (line.empty()) // header i will take it to be on the first line and others empty ignore
        {
            std::cerr << "Error: empty line on data space.\n";    // pls dont criticize this its for tue user experience so to compare line by line
            continue;
        }
        size_t pipe_ = line.find("|");
        if (pipe_ == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << '\n';    
            continue;
        }
        std::string date = line.substr(0, pipe_);
        trim(date);
        std::string valueStr = line.substr(pipe_ + 1);
        trim(valueStr);
        
        double value;
        if (!parseDate(date) || valueStr.empty() || !parseDouble(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << '\n';
            continue ;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number.\n";
            continue ;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number.\n"; // theres a typo on the subject..
            continue ;
        }

        std::map<std::string, double>::iterator it = _datas.lower_bound(date);
        if (it == _datas.begin() && it->first != date)
        {
            std::cerr << "Error: bad input => " << line << '\n';
            continue ;
        }
        if (it == _datas.end() || it->first != date) 
            --it;
        std::cout << date << " => " << value << " = " << value * it->second <<'\n';
    }    
}