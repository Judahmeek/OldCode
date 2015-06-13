/*Attempt at Java quick reference

Subjects covered:
Activating a program
Linking modules/headers/etc
Comments (all types)
All operators (Point out special types)
Input from Standard input
Input from file
Output to standard output
Output to file
variable scope
Flow control: if, else, switch, conditional operator
Repetition: while, do while, for, for-each
Functions: pass by value, pass by reference
Arrays: initialization, transversal
Strings: finding substrings, concatenation, comparison
Objects: declaration, creation, initialization, modification, deletion
Standard objects: lists, hash tables / dictionaries, etc
Inheritance: polymorphism, multiple inheritance
*/

//Activating a program
/*In order to run this program, you must run the  java files through a
compiler and a linker, and then run the resulting jar file.*/

package example; // All java files are in packages. Files without designated packages are placed in the "default" package

//Linking modules/headers/etc
import java.lang.*;
import java.util.someSpecificClass;

/**
 *
 * @author ThatOtherGuy
 */
public class Example { //Everything in java goes in a class

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
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
Special operators: instanceof(x)
 
//Input from Standard input
Scanner scanner = new Scanner(System.in);
String input = scanner.nextLine();

//Output to standard output
System.out.println("String");

//Input from file
FileReader reader = new FileReader("input.txt");
Scanner in = new Scanner(reader); 

//Output to file
PrintWriter out = new PrintWriter("output.txt");
out.println("Hello, World!"); 
out.close;

variable scope: package, file, function, block, class/"static"
Flow control: if, else, switch
Repetition: while, do while, for, for-each
Functions: pass by value (primitive variables only), pass by reference
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

Standard objects: arraylists, stacks, deques, queques, maps, sets

Inheritance:
polymorphism: /*using a baseClass pointer aimed at a derivedClass, you can call any method that the baseClass has. If the method has been overwritten by the derivedClass, then that
behavior will be implemented instead*/ C++'s virtual method = java's abstract method. If a virtual method =0 / has no implementation, then the class is abstract

Exception Handling:
try, catch(exception e), finally

Special Features:
generics
template <class T>
returnType function(T arg){ //classes can also be templates: class Example{T genericDataMember; }
}

const
const int = 1; //constant variables can not be modified after initialization
const int* const pointer = &x; //constant pointer to const int. either const could be removed