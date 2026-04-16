#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

class ScalarConvert {

    private:
    ScalarConvert();
    ScalarConvert(const ScalarConvert& orig);
    ScalarConvert& operator=(const ScalarConvert& orig);
    ~ScalarConvert();

    public:
    static void doConvert(const std::string& rep);

};

struct branchP{

        bool isF;
        bool isChar;
        bool isNan;
        bool isInf;
        bool isValid;

        bool wantSomeErrno;

        int afterPLen;

        double val;
    };

#endif

// static class 정적 멤버만 가지고 있어야 함 singleton

//mettre dans le private la forme canonique

