#include "ScalarConverter.hpp"

ScalarConvert::ScalarConvert(){
    std::abort(); // even for the class members, abort so to show it shouldn't be from the programmer's side
}

ScalarConvert::ScalarConvert(const ScalarConvert& orig){
    (void)orig;
    std::abort();
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& orig){
    (void)orig;
    std::abort();
}

void ScalarConvert::printLits(struct ScalarConvert::branchP& s){

}


void ScalarConvert::litConvert(const std::string& rep, struct ScalarConvert::branchP& s){
    // 이거 아님 반환값임.. const char* end_ptr = rep.c_str() + rep.size();

    s.isChar = false;
    s.isF = false;
    s.isNan = false;
    s.isInf = false;
    s.isValid = false;
    s.val = 0.0;

    char* end_ptr;
    end_ptr = NULL;
    s.val = std::strtod(rep.c_str(), &end_ptr);
    int len = rep.size();

    if (*end_ptr != '\0')
    {
        if (end_ptr == NULL && !isdigit(*(rep.c_str())) && (len == 1)){
            s.isValid = true;
            s.isChar = true;
            return ;
        }
        else if (*end_ptr == 'f' && *(end_ptr + 1) == '\0'){
            s.isValid = true;
            s.isF = true;
            if (rep == "nanf" || rep == "+nanf" || rep == "-nanf"){
                s.isNan = true;
            }
            else if (rep == "inff" || rep == "+inff" || rep == "infinityf" || rep == "+infinityf" || rep == "-infinityf"){
                s.isInf = true;
            }
        }
        return ; // 위의 두 경우 제외하곤 다 invalid 되어라
    }

    else if (*end_ptr == '\0'){
        s.isValid = true;
        if (rep == "nan" || rep == "+nan" || rep == "-nan"){
            s.isNan = true;
        }
        else if (rep == "inf" || rep == "+inf" || rep == "-inf" || rep == "infinity" || rep == "-infinity") {
            s.isInf = true;
        }
        return ;
    }
    return ;
}

void ScalarConvert::doConvert(const std::string& rep){
    branchP s;
    litConvert(rep, s);
    printLits(s);
}

ScalarConvert::~ScalarConvert(){
    std::abort();
}

// std::atof

// std::strtod

// inf inff +inf +inff 
// -inf -inff
// nan..
// etc
// 예외 처리가 중요한 과제임 ㅋㅋㅋ 씨부럴.. 