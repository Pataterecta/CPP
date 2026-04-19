#include "Span.hpp"
#include <climits>

Span::Span() : _size(0), _resShort(0) {
    _intos.reserve(0);
}

// Span::Span(unsigned int N) { 
// in this Case Span sp = Span(-1) works cuz C++ changes it by itself
// so to check range of negative value should put it on int (wow)
Span::Span(int N) {
    if (N <= 0)
        throw std::out_of_range("U think its even needed?");
    _intos.reserve(N);
    _size = N;
}

Span::Span(const Span& orig){
    _intos = orig._intos;
    _resShort = orig._resShort;
}

Span& Span::operator=(const Span& orig){
    if (this != &orig){  // vector deepcopy
        _intos = orig._intos;
        _resShort = orig._resShort;
    }
    return (*this);
}

void Span::addNumber(int val){
    if (_intos.size() >= _size) // actually == is enough tho
        throw E1_alreadyN();
    _intos.push_back(val);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    
    if (std::distance(begin, end) == 0)
        throw std::out_of_range("U think its even needed?");
    if (_intos.size() + std::distance(begin, end) > _size)
        throw std::out_of_range("you put too much");
    std::vector<int>::iterator it = begin;
    for (; it != end; ++it)
    {
        _intos.push_back(*it);
    }
}

unsigned int Span::shortestSpan(void) { // 정렬헀으니 abs 필요 없음..
    if (_intos.size() == 0 || _intos.size() == 1)
        throw E2_noSpan();
    std::sort(_intos.begin(), _intos.end()); // 이터레이터 무효화 안함, 재할당 없음 = UB 없음, 순서 논리랑 별개로
    std::vector<int>::iterator it = _intos.begin();
    // init _resShort
    long long diff = static_cast<long long int>(*(it + 1)) - static_cast<long long int>(*it);
    if (diff > UINT_MAX)
        throw overflower(); 
    _resShort = (diff);
    while (it != _intos.end() - 1)
    {
        if ((static_cast<long long int>(*(it + 1)) - static_cast<long long int>(*it)) > UINT_MAX)
            throw overflower(); 
        unsigned int val = (*(it + 1) - *it); // 이 값이랑 다음에 구한 값이랑 비교해서 더 작은 걸 남겨야 하는디
        if (val < _resShort)
            _resShort = val;
        ++it;
    }
    return _resShort;
}

unsigned int Span::longestSpan(void) const{
    if (_intos.size() == 0 || _intos.size() == 1)
        throw E2_noSpan();
    long long int min = *(std::min_element(_intos.begin(), _intos.end()));
    long long int max = *(std::max_element(_intos.begin(), _intos.end()));
    // if ((max - min) > UINT_MAX)
    //     throw overflower();
    return std::abs(max - min);
}

const char* Span::E1_alreadyN::what() const throw(){
    return "already N elements stored";
}

const char* Span::E2_noSpan::what() const throw(){
    return "no member stored or only one ? no span";
}

const char* Span::overflower::what() const throw(){
    return "overflow detected";
}

Span::~Span(){

}

// copying a vector https://www.geeksforgeeks.org/cpp/ways-copy-vector-c/
// min max https://stackoverflow.com/questions/13015932/how-to-find-minimum-value-from-vector
// std::span https://nx006.tistory.com/5 C++20