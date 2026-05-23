#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <math.h>
#include <cctype>
#include <stdlib.h>


class BitcoinExchange
{

    private:
    std::map<std::string, double> _datas;

    void trim(std::string &str);
    bool parsePosInt(const std::string& str, int& date);
    bool parseDate(const std::string& str);
    bool parseDouble(const std::string& str, double& resD);

    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& orig);
    BitcoinExchange& operator=(const BitcoinExchange& orig);
    ~BitcoinExchange();

    void parseCsv(std::ifstream&);
    void treatInf(std::ifstream&  givenCsv);


};

#endif