#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <stdint.h>
#include <iostream>

struct Data{

        std::string petitDa;
        int randomI;
};

class Serializer{

    private:
    Serializer();
    Serializer(const Serializer& orig);
    Serializer& operator=(const Serializer& orig);
    ~Serializer();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif


// 일반적이지 않은 형 변형을 데이터 파괴 없이 무조건 하기 위해..
// https://stackoverflow.com/questions/16543519/serialization-of-struct