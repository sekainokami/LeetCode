## Commonly Asked C++ Interview Questions

#### What are the differences between C and C++?  
1. C++ is a kind of superset of C, most of C programs except few exceptions work in C++ as well.
2. C is a procedural programming language, but C++ supports both procedural and Object Oriented programming.
3. Since C++ supports object oriented programming, it supports features like function overloading, templates, inheritance, virtual functions, friend functions. These features are absent in C.
4. C++ supports exception handling at language level, in C exception handling is done in traditional if-else style.
5. C++ supports references, C doesn’t.
6. In C, scanf() and printf() are mainly used input/output. C++ mainly uses streams to perform input and output operations. cin is standard input stream and cout is standard output stream.

#### What are the differences between references and pointers?
Both references and pointers can be used to change local variables of one function inside another function. Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, to get efficiency gain.
Despite above similarities, there are following differences between references and pointers.

References are less powerful than pointers
1. Once a reference is created, __it cannot be later made to reference another object__; it cannot be reseated. This is often done with pointers.
2. References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
3. __A reference must be initialized when declared__. There is no such restriction with pointers

Due to the above limitations, references in C++ cannot be used for implementing data structures like Linked List, Tree, etc. In Java, references don’t have above restrictions, and can be used to implement all data structures. References being more powerful in Java, is the main reason Java doesn’t need pointers.

References are safer and easier to use:
1. Safer: Since references must be initialized, wild references like wild pointers are unlikely to exist. It is still possible to have references that don’t refer to a valid location (See questions 5 and 6 in the below exercise )
2. Easier to use: References don’t need dereferencing operator to access the value. They can be used like normal variables. ‘&’ operator is needed only at the time of declaration. Also, members of an object reference can be accessed with dot operator (‘.’), unlike pointers where arrow operator (->) is needed to access members.

#### What are virtual functions – Write an example?
Virtual functions are used with inheritance, they are called according to the type of object pointed or referred, not according to the type of pointer or reference. In other words, virtual functions are resolved late, at runtime. ___Virtual___ keyword is used to make a function virtual.

Following things are necessary to write a C++ program with runtime polymorphism (use of virtual functions)
1. A base class and a derived class.
2. A function with same name in base class and derived class.
3. A pointer or reference of base class type pointing or referring to an object of derived class.

#### What is this pointer?
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘this’ pointer is a constant pointer that holds the memory address of the current object. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

#### What are VTABLE and VPTR?
vtable is a table of function pointers. It is maintained per class.
vptr is a pointer to vtable. __It is maintained per object.__
Compiler adds additional code at two places to maintain and use vtable and vptr.
1. Code in every constructor. This code sets vptr of the object being created. This code sets vptr to point to vtable of the class.
2. Code with polymorphic function call. Wherever a polymorphic call is made, compiler inserts code to first look for vptr using base class pointer or reference.

#### Major Differences between JAVA and C++
There are lot of differences, some of the major differences are:
* Java has automatic garbage collection whereas C++ has destructors , which are automatically invoked when the object is destroyed.
* Java does not support pointers, templates, unions, operator overloading, structures etc.
* C++ has no in built support for threads,whereas in Java there is a Thread class that you inherit to create a new thread
No goto in JAVA
* C++ support multiple inheritance, method overloading and operator overloading but JAVA only has method overloading.
* Java is interpreted and hence platform independent whereas C++ isn’t. At compilation time, Java Source code converts into JVM byte code. The interpreter execute this bytecode at run time and gives output. C++ run and compile using compiler which converts source code into machine level language.

#### What are C++ access specifiers ?
Access specifiers are used to define how the members (functions and variables) can be accessed outside the class.

* Private: Members declared as private are accessible only within the same class and they cannot be accessed outside the class they are declared. Child classes are also not allowed to access private members of parent.
* Public: Members declared as public are accessible from anywhere.
* Protected: Only the class and its child classes can access protected members.

#### Major C++ features
__Class__: Class is a blueprint of data and functions or methods. Class does not take any space.
* Object: Objects are basic run-time entities in an object oriented system, objects are instances of a class these are defined user defined data types.
* Encapsulation and Data abstraction: Wrapping up(combining) of data and functions into a single unit is known as encapsulation. The data is not accessible to the outside world and only those functions which are wrapping in the class can access it. This insulation of the data from direct access by the program is called data hiding or information hiding.
* Data abstraction – providing only needed information to the outside world and hiding implementation details. For example, consider a class Complex with public functions as getReal() and getImag(). We may implement the class as an array of size 2 or as two variables. The advantage of abstractions is, we can change implementation at any point, users of Complex class wont’t be affected as our method interface remains same. Had our implementation be public, we would not have been able to change it.
* Inheritance: Inheritance is the process by which objects of one class acquire the properties of objects of another class. It supports the concept of hierarchical classification. Inheritance provides reusability. This means that we can add additional features to an existing class without modifying it.
* Polymorphism: Polymorphism means ability to take more than one form. An operation may exhibit different behaviors in different instances. The behavior depends upon the types of data used in the operation.
* Dynamic Binding: In dynamic binding, the code to be executed in response to function call is decided at runtime. C++ has virtual functions to support this.
* Message Passing: Objects communicate with one another by sending and receiving information to each other. A message for an object is a request for execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results. Message passing involves specifying the name of the object, the name of the function and the information to be sent.

#### Structure vs class in C++
In C++, a structure is same as class except the following differences:
* Members of a class are private by default and members of struct are public by default.
* When deriving a struct from a class/struct, default access-specifier for a base class/struct is public. And when deriving a class, default access specifier is private.

#### Malloc() vs new / Delete vs Free
Following are the differences between malloc() and operator new.
* new is an operator, while malloc() is a function.
* new returns exact data type, while malloc() returns void \*.
* new calls constructors( class instances are initalized and deinitialized automatically), while malloc() does not( classes won’t get initalized or deinitialized automatically
* Syntax:
  1. int\* n = new int(10);  _// initialization with new()_
  2. str = (char\*) malloc(15); _//malloc()_
* __free()__ is used on resources allocated by malloc( ), or calloc( ) in C
* __delete__ is used on resources allocated by new in C++

#### Inline Functions
C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small.

The syntax for defining the function inline is:

```c++
inline return-type function-name(parameters)
{
_// function code_
}
```

_Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining._

#### Friend class and function in C++
A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class. For example a LinkedList class may be allowed to access private members of Node.

Friend Function Like friend class, a friend function can be given special grant to access private and protected members. A friend function can be:

* A method of another class  
* A global function

__Important points about friend functions and classes:__

1. Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.
2. Friendship is not mutual. If a class A is friend of B, then B doesn’t become friend of A automatically.
3. Friendship is not inherited (See this for more details)
4. The concept of friends is not there in Java.

#### Function overloading VS Operator Overloading
Function overloading is a feature in C++ where two or more functions can have the same name but different type of parameters and  different number of parameters.

_Note: Overloading of functions with different return types are not allowed._

Operating overloading allows us to  make operators to work for user defined classes. For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +.

Other example classes where arithmetic operators may be overloaded are Complex Number, Fractional Number, Big Integer, etc.

#### Copy Constructor
A copy constructor is a member function which initializes an object using another object of the same class. A copy constructor has the following general function prototype: ClassName (const ClassName &old_obj);

Point(int x1, int y1) { x = x1; y = y1; }

_// Copy constructor_

Point(const Point &p2) {x = p2.x; y = p2.y; }

When is copy constructor called?

In C++, a Copy Constructor may be called in following cases:

1. When an object of the class is returned by value.
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. When compiler generates a temporary object.

#### Can we make copy constructor private?
Yes, a copy constructor can be made private

#### What is Inheritance?
Different kinds of objects often have a certain amount in common with each other. Yet each also defines additional features that make them different. Object-oriented programming allows classes to inherit commonly used state and behavior from other classes

#### What is Static Member?
__Static__ is a keyword in C++ used to give special characteristics to an element. Static elements are allocated storage only once in a program lifetime in static storage area. And they have a scope till the program lifetime. Static Keyword can be used with following,

Interesting facts about Static Members Functions  in C++

* static member functions do not have this pointer.
* A static member function cannot be virtual
* Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.
* static member function can not be declared const, volatile, or const volatile.
