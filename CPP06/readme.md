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