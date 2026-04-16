#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>

class ScalarConvert {

    private:
    ScalarConvert();
    ScalarConvert(const ScalarConvert& orig);
    ScalarConvert& operator=(const ScalarConvert& orig);
    ~ScalarConvert();

    struct branchP{

        bool isF;
        bool isChar;
        bool isNan;
        bool isInf;
        bool isValid;

        double val;
    };

    static void litConvert(const std::string& rep, struct ScalarConvert::branchP&);

    static void printLits(struct ScalarConvert::branchP&);

    public:
    static void doConvert(const std::string& rep);

};

#endif

// static class 정적 멤버만 가지고 있어야 함 singleton

//mettre dans le private la forme canonique

