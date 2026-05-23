#include "PmergeMe.hpp"

static const std::vector<int>* valofIdxV = NULL;
static const std::deque<int>* valofIdxD = NULL;

PmergeMe::PmergeMe(){

}

PmergeMe::PmergeMe(const PmergeMe& orig)
{
  *this = orig;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& orig){

      if (this != &orig)
    {
        _vec = orig._vec;
        _deq = orig._deq;
        _raw = orig._raw;
    }
    return *this;
}

PmergeMe::~PmergeMe(){

}

bool PmergeMe::parsePosInt(const std::string& str, int& out)
{
    char* end_ptr;
    end_ptr = NULL;
    errno = 0;

    long val = std::strtol(str.c_str(), &end_ptr, 10);
    
    if (str.empty() || *end_ptr != '\0' || errno == ERANGE || end_ptr == str.c_str())
        return false;

    if (std::isspace(static_cast<unsigned char>(str[0])))
        return false;

    if (val < 0 || val > std::numeric_limits<int>::max()) // value check before casting
        return false;

    out = static_cast<int>(val);
  
    return true;
}

void PmergeMe::inputParse(int ac, char **av)
{
    _raw.clear();
    _vec.clear();
    _deq.clear();

    for (int i = 1; i < ac; ++i)
    {
        std::string s_element(av[i]);

        if (s_element.empty())
            throw std::runtime_error("Error");
        if (s_element.size() > 1 && s_element[0] == '0')
            throw std::runtime_error("Error");
        // for (size_t j = 0; j < s_element.size(); ++j)
        // {
        //     if (!std::isdigit(static_cast<unsigned char>(s_element[j]))) // '-' would be detected here
        //         throw std::runtime_error("Error");
        // }
    
        int element;
        if (!parsePosInt(s_element, element))
            throw std::runtime_error("Error");

        // if (element > INT_MAX)
        //     throw std::runtime_error("Error");
        
        _raw.push_back(element);
        _vec.push_back(element);
        _deq.push_back(element);

    }
}

std::vector<int> PmergeMe::jacobIndexV(int b_idx)
{
    std::vector<int> j_index;
    int n0 = 0;
    int n1 = 1;


    if (b_idx == 0)
        return j_index; // vide
    if (b_idx == 1)
    {    
        j_index.push_back(1);
        return j_index;
    }

    j_index.push_back(1);
   
    while (42)
    {
        int next = n1 + n0 * 2; // 1 3 5 11 ...
        if (next > b_idx)
            break;
        if (next != 1)
            j_index.push_back(next);
        if (j_index.size() > 1)
        {
           int tempback = j_index.back(); // 1 3 2 5 4 ...
           while (tempback > n1 + 1)
           {
                j_index.push_back(--tempback);
           }
        }
        n0 = n1;
        n1 = next;
    }

   
    while (b_idx > n1)
        j_index.push_back(b_idx--);
    
    // for (int i = 0; i <= 10; ++i) {
    // std::vector<int> j = jacobIndex(i);
    // std::cout << i << ": ";
    // for (size_t k = 0; k < j.size(); ++k)
    //     std::cout << j[k] << " ";
    // std::cout << std::endl;
    // }

    return (j_index);
}

std::deque<int> PmergeMe::jacobIndexD(int b_idx)
{
    std::deque<int> j_index;
    int n0 = 0;
    int n1 = 1;


    if (b_idx == 0)
        return j_index; // vide
    if (b_idx == 1)
    {    
        j_index.push_back(1);
        return j_index;
    }

    j_index.push_back(1);
   
    while (42)
    {
        int next = n1 + n0 * 2;
        if (next > b_idx)
            break;
        if (next != 1)
            j_index.push_back(next);
        if (j_index.size() > 1)
        {
           int tempback = j_index.back();
           while (tempback > n1 + 1)
           {
                j_index.push_back(--tempback);
           }
        }
        n0 = n1;
        n1 = next;
    }

   
    while (b_idx > n1)
        j_index.push_back(b_idx--);
    
    // for (int i = 0; i <= 10; ++i) {
    // std::vector<int> j = jacobIndex(i);
    // std::cout << i << ": ";
    // for (size_t k = 0; k < j.size(); ++k)
    //     std::cout << j[k] << " ";
    // std::cout << std::endl;
    // }

    return (j_index);
}

void PmergeMe::makePairV(const std::vector<int>& value, const std::vector<int>& indexes, std::vector<int>& pair, std::vector<int>& resBigs, std::vector<int>& smalls)
{
    pair.assign(value.size(), -1);
    resBigs.clear();
    smalls.clear();

    for (size_t i = 0; i + 1 < indexes.size(); i += 2)
    {
        int a = indexes[i];
        int b = indexes[i + 1];

        int big = a;
        int small = b;

        if (value[big] < value[small])
            std::swap(big, small);
        pair[big] = small;
        pair[small] = big;

        resBigs.push_back(big);
        smalls.push_back(small);
    }
}

void PmergeMe::makePairD(const std::deque<int>& value, const std::deque<int>& indexes, std::deque<int>& pair, std::deque<int>& resBigs, std::deque<int>& smalls)
{
    pair.assign(value.size(), -1);
    resBigs.clear();
    smalls.clear();

    for (size_t i = 0; i + 1 < indexes.size(); i += 2)
    {
        int a = indexes[i];
        int b = indexes[i + 1];

        int big = a;
        int small = b;

        if (value[big] < value[small])
            std::swap(big, small);
        pair[big] = small;
        pair[small] = big;

        resBigs.push_back(big);
        smalls.push_back(small);
    }
}


bool PmergeMe::compValofIdxV(int a, int b)
{
    return (*valofIdxV)[a] < (*valofIdxV)[b];
}

bool PmergeMe::compValofIdxD(int a, int b)
{
    return (*valofIdxD)[a] < (*valofIdxD)[b];
}


void    PmergeMe::putAsJV(const std::vector<int>& value, std::vector<int>& pair, std::vector<int>& resBigs, std::vector<int>& smalls)
{

    int  s_idx = smalls.size();
    std::vector<int> j_idx = jacobIndexV(s_idx);

    valofIdxV = &value;

    std::vector<int>::iterator it = j_idx.begin();
    for (; it != j_idx.end(); ++it)
    {
        int smallPos = *it - 1; // 인덱스 접근 0부터니까
        
        if (smallPos < 0 || smallPos >= static_cast<int>(smalls.size()))
            continue;
        
        int smallIndex = smalls[smallPos];
        int bigIndex = pair[smallIndex];

        std::vector<int>::iterator bound = std::find(resBigs.begin(), resBigs.end(), bigIndex);
       
        // if (bound == resBigs.end()) // debug
        // {
        //     std::cerr << "Error: pair big not found\n";
        // }

        std::vector<int>::iterator pair_pos = std::lower_bound(resBigs.begin(), bound, smallIndex, compValofIdxV);
        
        resBigs.insert(pair_pos, smallIndex);
        // put as jacobIndex with logic
        // use index to take out the small value from pairs
        // and then put it at the middle of _vec or _deq
        // and then move it checking its value comparing to the already existing values

    }
}


void    PmergeMe::putAsJD(const std::deque<int>& value, std::deque<int>& pair, std::deque<int>& resBigs, std::deque<int>& smalls)
{

    int  s_idx = smalls.size();
    std::deque<int> j_idx = jacobIndexD(s_idx);

    valofIdxD = &value;

    std::deque<int>::iterator it = j_idx.begin();
    for (; it != j_idx.end(); ++it) // if empty then begin = end so not go into for
    {
        int smallPos = *it - 1; // 인덱스 접근 0부터니까
        
        if (smallPos < 0 || smallPos >= static_cast<int>(smalls.size()))
            continue;
        
        int smallIndex = smalls[smallPos];
        int bigIndex = pair[smallIndex];

        std::deque<int>::iterator bound = std::find(resBigs.begin(), resBigs.end(), bigIndex);
       
        // if (bound == resBigs.end()) // debug
        // {
        //     std::cerr << "Error: pair big not found\n";
        // }

        std::deque<int>::iterator pair_pos = std::lower_bound(resBigs.begin(), bound, smallIndex, compValofIdxD);
        
        resBigs.insert(pair_pos, smallIndex);
        // put as jacobIndex with logic
        // use index to take out the small value from pairs
        // and then put it at the middle of _vec or _deq
        // and then move it checking its value comparing to the already existing values

    }
}

void PmergeMe::sortIndexesV(const std::vector<int>& value, std::vector<int>& indexes)
{
    if (indexes.size() <= 1) // base
        return ;

    std::vector<int> pair;
    std::vector<int> resBigs;
    std::vector<int> smalls;
    
    makePairV(value, indexes, pair, resBigs, smalls);

    valofIdxV = &value;
    sortIndexesV(value, resBigs);

    putAsJV(value, pair, resBigs, smalls);

    if (indexes.size() % 2 == 1)
    {
        int alone = indexes[indexes.size() - 1];
        std::vector<int>::iterator pos = std::lower_bound(resBigs.begin(), resBigs.end(), alone, compValofIdxV);
        resBigs.insert(pos, alone);
    }
    indexes = resBigs;
}


void PmergeMe::sortV(std::vector<int> &vec)
{
    if (vec.size() <= 1) // base
        return ;

    std::vector<int> indexes;
    for (size_t i = 0; i < vec.size(); ++i)
        indexes.push_back(i);
    
    sortIndexesV(vec, indexes);

    std::vector<int> sorted;
    for (size_t i = 0; i < indexes.size(); ++i)
        sorted.push_back(vec[indexes[i]]);

    vec = sorted;
}

void PmergeMe::sortIndexesD(const std::deque<int>& value, std::deque<int>& indexes)
{
    if (indexes.size() <= 1) // base
        return ;

    std::deque<int> pair;
    std::deque<int> resBigs;
    std::deque<int> smalls;
    
    makePairD(value, indexes, pair, resBigs, smalls);

    valofIdxD = &value;
    sortIndexesD(value, resBigs);

    putAsJD(value, pair, resBigs, smalls);

    if (indexes.size() % 2 == 1)
    {
        int alone = indexes[indexes.size() - 1];
        std::deque<int>::iterator pos = std::lower_bound(resBigs.begin(), resBigs.end(), alone, compValofIdxD);
        resBigs.insert(pos, alone);
    }
    indexes = resBigs;
}

void PmergeMe::sortD(std::deque<int> &deq)
{
    if (deq.size() <= 1) // base
        return ;

    std::deque<int> indexes;
    for (size_t i = 0; i < deq.size(); ++i)
        indexes.push_back(i);
    
    sortIndexesD(deq, indexes);

    std::deque<int> sorted;
    for (size_t i = 0; i < indexes.size(); ++i)
        sorted.push_back(deq[indexes[i]]);

    deq = sorted;
}

bool PmergeMe::compareRes() const
{
    if (_vec.size() == _deq.size() && std::equal(_vec.begin(), _vec.end(), _deq.begin()))
        return true;
    std::cerr << "Two containers' result not same\n"; // only appears when debug
    return false;
}

void PmergeMe::printTime(double vecT, double deqT) const
{
    std::cout << "Time to process a range of "   << _vec.size()
              << " elements with std::vector : " << vecT
              << " us\n";

    std::cout << "Time to process a range of "   << _deq.size()
              << " elements with std::deque : "  << deqT
              << " us\n";
}

void PmergeMe::calTime()
{
    clock_t startV = clock();
    sortV(_vec);
    clock_t endV = clock();
    double vecT = static_cast<double>(endV - startV) / CLOCKS_PER_SEC * 1000000; // seconds to microseconds

    clock_t startD = clock();
    sortD(_deq);
    clock_t endD = clock();
    double deqT = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000000;

    if (compareRes() == true)
    {
        printAll();
        printTime(vecT, deqT);
    }

}


void PmergeMe::printAll() const // actually this to use, once comparaison done, gonna print all, but result as checked with one container only
{
    std::cout << "Before: ";

    for (size_t i = 0; i < _raw.size(); ++i)
        std::cout << _raw[i] << " ";
    std::cout << std::endl;

    std::cout << "After: ";

    for (size_t i = 0; i < _vec.size(); ++i) // first container used
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}