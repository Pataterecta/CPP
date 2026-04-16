#include "Serializer.hpp"

int main(void)
{
    std::cout << "this exo of this module is.. hmm well :)\n";

    Data* miaou = new Data;
    miaou->petitDa = "spidercat";
    miaou->randomI = 999;
    uintptr_t p = Serializer::serialize(miaou);
    std::cout << reinterpret_cast<Data*>(p)->randomI << std::endl;
    std::cout << reinterpret_cast<Data*>(p)->petitDa << std::endl;

    std::cout << "---------------testttttt\n";
    std::cout << miaou->petitDa << std::endl; 

    std::cout << "----------------testttttt\n";
    Data* pointos = Serializer::deserialize(p);
    std::cout << pointos->petitDa << " and " << pointos->randomI << std::endl;

    std::cout <<  "delete(pointos) is same cuz same adress :)\n";
    delete(miaou);
    

    return (0);
}