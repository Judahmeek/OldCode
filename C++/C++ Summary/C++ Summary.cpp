Activating a program
/*In order to run this program, you must link all the files together through a makefile, run the files through a
compiler and a linker, and then run the resulting executible file.*/

Linking modules/headers/etc
#include <cstdlib> //#include links header and implementation files
#include exampleImpl.h
#include exampleImpl.cpp

namespaces
using std::cin; //includes object from std namespace, to include all std variables use "using namespace std;"
using newType = existingType; //preferred way to create type aliases
typedef existingType newType; //old way to create type aliases

program structure
void function(int parameter); /*function prototype, provides the compiler with a "name" for the function
variable types: char, int, double, bool, void, nullptr
type casting: (type) variable*/ IMPORTANT!!! In C++, the explicit keyword is your best friend. Put it in front of every variable possible.

int main(int argc, char* argv[]){ //every program must have one and only one main function. char* argv[] is an array of char pointers
}

operators //Can be overloaded: returnType leftOperand/Namespace::operator=( type rightOperand )
assignment: =
arithmetic; +, -, *, /, %
bitwise: &, |, ^, ~, <<, >>
compound assignment: +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=
in/decrement: ++, --
comparison: ==, !=, <, >, <=, >=
logical: !, &&, ||
conditional: statement ? ifTrue : ifFalse
Special operators: sizeof(x), typedef(x)
 
Input from Standard input
cin >> stringVariable;

Output to standard output
cout << "String";

Input from file
#include <iostream>
#include <fstream>
ifstream myFile;
myFile.open("path/to/file");
if(myFile.is_open){
	while(!myFile.eof()){
		myFile >> stringVar;
		//do things
	}
}

Output to file
ofstream myFile;
//same as above
	myFile << stringVar;
}
myFile.close;

variable scope: package, file, function, block, class/"static"
Flow control: if, else, switch
Repetition: while, do while, for, for-each
Functions: pass by value, pass by reference
overloading: returnType namespace::sameFunctionName( different parameters){};

Array initialization// elementVariable = arrayName[index]; 
type foo[number];
type bar[number] = {element1, element2, etc...};

//C style arrays are not self aware, so if you pass one as a function argument, you should also pass the size of the array.

Strings: finding substrings, concatenation, comparison

Objects: initialization, modification, deletion
object = new constructor() or struct //struct structure: struct name {dataType dataMember, otherType otherMember, etc... }
delete object; //calls object's destructor

Structs
unions: different types sharing the same memory address
enum struct: array of constants

Standard objects: vectors, lists, stacks, deques, queques, maps, sets

Inheritance: multiple inheritance //covered in example.h
polymorphism: /*using a baseClass pointer aimed at a derivedClass, you can call any method that the baseClass has. If the method has been overwritten by the derivedClass, then that
behavior will be implemented instead*/ C++'s virtual method = java's abstract method. If a virtual method =0 / has no implementation, then the class is abstract

Exception Handling:
try, catch(exception e), catch(...)

Special Features:
generics
template <class T>
returnType function(T arg){ //classes can also be templates: class Example{T genericDataMember; }
}

pointers //variables that contain memory addresses of variables or objects
object *pointer = &object; //& is an operator which returns the address of object
objectsAddress = pointer;
object = *pointer;
object **seriousPointer = &pointer; //just keep adding asterisks
returnType (*functionPointer) (parameters) = functionName; //pointers can point to functions as well
pointer = null; //killing a pointer

const
const int = 1; //constant variables can not be modified after initialization
const int* const pointer = &x; //constant pointer to const int. either const could be removed

type-casting //Since C++ is strongly typed, type casting is required more often then not
dynamic_cast <newType> (oldType) //Strictest cast. Uses runtime type info to confirm type safety
static_cast same //Allows casts between any related classes. No safety checks
reinterpret_cast same //Allows any type of casting. Dangerous
const_cast same //Should only be used to make a non constant variable constant so said variable can be used with constant functions
