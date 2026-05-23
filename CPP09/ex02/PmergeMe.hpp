#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <string>
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <cctype>
#include <limits>
#include <cerrno>

class PmergeMe
{
    private:
    std::vector<int> _raw;
    

    std::vector<int> _vec;
    std::deque<int> _deq;

    std::vector<int> jacobIndexV(int b_idx); // gonna make index from jacobsthal like 13254.. comparing to the array to be put in's to index
    std::deque<int> jacobIndexD(int b_idx);
    
    bool parsePosInt(const std::string& str, int& out);
    
    void putAsJV(const std::vector<int>& value, std::vector<int>& pair, std::vector<int>& resBigs, std::vector<int>& smalls);
    void putAsJD(const std::deque<int>& value, std::deque<int>& pair, std::deque<int>& resBigs, std::deque<int>& smalls);


    static bool compValofIdxV(int a, int b);
    static bool compValofIdxD(int a, int b);

    void sortIndexesV(const std::vector<int>& value, std::vector<int>& indexes);
    void sortIndexesD(const std::deque<int>& value, std::deque<int>& indexes);


    bool compareRes() const; // check if both output same
    void printTime(double vecT, double deqT) const;

    void printAll() const; // actually this to use, once comparaison done, gonna print all, but result as checked with one container only

        
    void makePairV(const std::vector<int>& value, const std::vector<int>& indexes, std::vector<int>& pair, std::vector<int>& resBigs, std::vector<int>& smalls);
    void makePairD(const std::deque<int>& value, const std::deque<int>& indexes, std::deque<int>& pair, std::deque<int>& resBigs, std::deque<int>& smalls);

    void sortV(std::vector<int> &vec);
    void sortD(std::deque<int> &deq);

    public:
    PmergeMe();
    PmergeMe(const PmergeMe& orig);
    PmergeMe& operator=(const PmergeMe& orig);
    ~PmergeMe();

    void inputParse(int ac, char **av); // parse input from main

    void calTime();
};

#endif

/*

test : 
ARGS=$(shuf -i 1-3000)
./PmergeMe $ARGS

./PmergeMe 01 2 3 4

why diff -> deque, segmented memory, cache locality weakness

*/