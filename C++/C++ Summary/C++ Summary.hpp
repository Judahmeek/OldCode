#ifndef EXAMPLE_H //a preprocessor directive to minimize excess linking
#define EXAMPLE_H //other useful directive include #ifdef, #if, #else, #elif, and #undef

/*classes can also be const, which means its data members are read only once initialized*/ derivedClass Example: public baseClass, public otherBaseClass?
//multiple inheritance is possible in C++ although not recommended
{
	friend objects or functions;
public:
	function prototypes and data members; //data members and methods can be referenced by either class.name or by class->name
	Example(); //Constructor
	~Example(); //Destructor
protected:
	same;
private:
	same;
	memberObject;
	returnType privateMethod(parameters); //methods can also be const, which means they do not modify any data members
};

/*Every class has 6 implicit methods: constructor (C::C()), destructor (C::~C()),
copy constructor (C::C(const C)), copy assignment (C& operator= (const C)), move constructor (C::C(C&&)),
and move assignment (C& operator= (C&&)). These methods can be explicitly modified, defaulted, or deleted.*/

#endif
