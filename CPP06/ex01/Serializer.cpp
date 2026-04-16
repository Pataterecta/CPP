#include "Serializer.hpp"

Serializer::Serializer(){
    std::abort();
}

Serializer::Serializer(const Serializer& orig){
    (void)orig;
    std::abort();
}

Serializer& Serializer::operator=(const Serializer& orig){
    (void)orig;
    std::abort();
}

Serializer::~Serializer(){
    std::abort();
}

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t p = reinterpret_cast<uintptr_t> (ptr);
        return (p);
}

Data* Serializer::deserialize(uintptr_t raw){
    Data* Dp = reinterpret_cast<Data*> (raw);
        return Dp;
}