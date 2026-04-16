https://hwan-shell.tistory.com/219

-------ex00

good example to check : 
bash-5.2$ ./convert 42.0000020000000000000000f
char: '*'
int: 42
float: 42.0f
double: 42.0

error case : 
    double x = s.val;
    double div = 0.0;
    double imRound;
    imRound = std::modf(x, &div);
    if (imRound == 0){
        std::cout << "float: " << div << ".0f\n";
        return ;
    }
    else{
        float f_val = static_cast<float>(s.val);
        std::cout << "float: " << f_val << "f\n";
    }

in this case result : 


➜  ex00 git:(main) ✗ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
➜  ex00 git:(main) ✗ ./convert 42.00f
char: '*'
int: 42
float: 42.0f
double: 42.0
➜  ex00 git:(main) ✗ ./convert 42.000000f
char: '*'
int: 42
float: 42.0f
double: 42.0
➜  ex00 git:(main) ✗ ./convert 42.000020f
char: '*'
int: 42
float: 42f
double: 42
➜  ex00 git:(main) ✗ ./convert 42.00002f 
char: '*'
int: 42
float: 42f
double: 42
➜  ex00 git:(main) ✗ ./convert 42.000020f
char: '*'
int: 42
float: 42f
double: 42
➜  ex00 git:(main) ✗ 42.022
bash: 42.022: command not found...
➜  ex00 git:(main) ✗ ./convert 42.022
char: '*'
int: 42
float: 42.022f
double: 42.022
➜  ex00 git:(main) ✗ ./convert 42.0220f
char: '*'
int: 42
float: 42.022f
double: 42.022

에러케이스!!!!!

modf 소수점 분리하기

https://cplusplus.com/reference/limits/numeric_limits/ 

https://koor.fr/C/cstdlib/strtod.wp

// https://stackoverflow.com/questions/19090328/protected-constructor-to-make-base-class-not-instantiable
// https://www.geekinterview.com/question_details/21355
// NOT correct since a class with a private constructor can be instantiated through a static member function of the class. Try out the following code:
//  we cannot instantiate the class if there is only one constructor and that only constructor is private, otherwise, if there is at least one constructor is public, then that class is instantiatable.
//->>>>> so put every fk constructors in the private ! lol
// class PrivateConstructor{

//       private PrivateConstructor() {

//                Console.WriteLine("Instantiating private constructor");

// }

// public static void CreateObj()

// {

// PrivateConstructor p = new PrivateConstructor();

// }

// }

// Even after having the constructor as private a class can be instantiated and can access non static members...

// check the following code ...

// using System;

// class PrivateConstructor{

//     private PrivateConstructor()
//  {
//          Console.WriteLine("Instantiating private constructor");
//  }

//  public static PrivateConstructor CreateObj()
//  {
//   PrivateConstructor p = new PrivateConstructor();
//   return p;
//  }
//  public void message()
//  {
//   Console.WriteLine("Calling non static member..");
//  }

// }
// class createObjClass
// {
//  public static void Main()
//  {
//   PrivateConstructor pc = PrivateConstructor.CreateObj();
//   pc.message();
//  }
// }

// Would like to know the comments on this...

// Thanks 