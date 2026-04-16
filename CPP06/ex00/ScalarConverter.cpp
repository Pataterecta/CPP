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
    std::abort(); // means I don't even want to represent it as its doable
}

void ScalarConvert::printChar(struct ScalarConvert::branchP& s){
    if (!s.isValid || s.isNan || s.isInf){
        std::cout << "char: impossible\n";
        return ;
    }
    else if (s.val < 0 || s.val > 127){
        std::cout << "char: impossible\n";
        return ;
    }
    char c = static_cast<char>(s.val);
    if (!std::isprint(s.val)){
        std::cout << "char: Non displayable\n";
        return ;
    }
    else {
        std::cout << "char: '" << c << "'\n"; // a verifier
        return ;
    }
}

void ScalarConvert::printInt(struct ScalarConvert::branchP& s){
    if (!s.isValid || s.isNan || s.isInf){
        std::cout << "int: impossible\n";
        return ;
    }
    else if (std::numeric_limits<int>::min() > s.val || std::numeric_limits<int>::max() < s.val){
        std::cout << "int: impossible\n";
        return ;
    }
    int s_int = static_cast<int>(s.val);
    std::cout << "int: " << s_int << std::endl;
}

void ScalarConvert::printFloat(struct ScalarConvert::branchP& s) {
    if (!s.isValid) {
        std::cout << "float: impossible\n";
        return;
    }
    if (s.isNan || s.isInf) {
        std::cout << "float: " << static_cast<float>(s.val) << "f\n";
        return;
    }

    float f_val = static_cast<float>(s.val);
    std::ostringstream o;
    o << f_val;
    std::string out = o.str();
    if (out.find('.') == std::string::npos && out.find('e') == std::string::npos && out.find('E') == std::string::npos)
        out += ".0";
    std::cout << "float: " << out << "f\n";
    
    // float f_val = static_cast<float>(s.val);
    // double intpart = 0.0;
    // double imRound = std::modf(static_cast<double>(f_val), &intpart);

    // if (imRound == 0.0)
    //     std::cout << "float: " << intpart << ".0f\n";
    // else
    //     std::cout << "float: " << f_val << "f\n";
}

void ScalarConvert::printDouble(struct ScalarConvert::branchP& s){
    if (!s.isValid){
        std::cout << "double: impossible\n";
        return ;
    }
    else if (s.isNan || s.isInf){
        std::cout << "double: " << s.val << std::endl;
        return ;
    }
    std::ostringstream o;
    o << s.val;
    std::string out = o.str();
    if (out.find('.') == std::string::npos && out.find('e') == std::string::npos && out.find('E') == std::string::npos)
        out += ".0";
    std::cout << "double: " << out << "\n";
    // double x = s.val;
    // double div = 0.0;
    // double imRound;
    // imRound = std::modf(x, &div);
    // if (imRound == 0.0){
    //     std::cout << "double: " << div << ".0\n";
    //     return ;
    // }
    // else{
    //     std::cout << "double: " << s.val << std::endl;
    // }
}

void ScalarConvert::printLits(struct ScalarConvert::branchP& s){

    printChar(s);
    printInt(s);
    printFloat(s);
    printDouble(s);

}


void ScalarConvert::litConvert(const std::string& rep, struct ScalarConvert::branchP& s){
    // 이거 아님 반환값임.. const char* end_ptr = rep.c_str() + rep.size();

    s.isChar = false;
    s.isF = false;
    s.isNan = false;
    s.isInf = false;
    s.isValid = false;
    s.wantSomeErrno = false; // just to debug etc if we want to check if its pure overflow detect
    s.val = 0.0;

    char* end_ptr;
    end_ptr = NULL;
    s.val = std::strtod(rep.c_str(), &end_ptr);
    int len = rep.size();

    if (errno == ERANGE)
        s.wantSomeErrno = true;
    if (*end_ptr != '\0')
    {
        if (end_ptr == NULL && !isdigit(*(rep.c_str())) && (len == 1)){
            s.isValid = true;
            s.isChar = true;
            return ;
        }
        else if (*end_ptr == 'f' && *(end_ptr + 1) == '\0'){ // float
            s.isValid = true;
            s.isF = true;
            if (std::isnan(s.val) == 1) //if (rep == "nanf" || rep == "+nanf" || rep == "-nanf") cuz other NaN INFINITY kind of
                s.isNan = true;
            else if (std::isinf(s.val) == 1) //else if (rep == "inff" || rep == "+inff" || rep == "infinityf" || rep == "+infinityf" || rep == "-infinityf"){
                s.isInf = true;
        }
        return ; // 위의 두 경우 제외하곤 다 invalid 되어라
    }

    else if (*end_ptr == '\0'){ // double
        s.isValid = true;
        if (std::isnan(s.val) == 1) //if (rep == "nan" || rep == "+nan" || rep == "-nan")
            s.isNan = true;
        else if (std::isinf(s.val) == 1)//else if (rep == "inf" || rep == "+inf" || rep == "-inf" || rep == "infinity" || rep == "-infinity")
            s.isInf = true;
        return ;
    }
    return ;
}

void ScalarConvert::doConvert(const std::string& rep){
    branchP s;
    litConvert(rep, s);
    printLits(s); // receiver would take it as a reference of struct
}

ScalarConvert::~ScalarConvert(){
    std::abort();
}
