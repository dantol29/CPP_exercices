# C++ Practice
## 1. Intro to OOP
### ex00 - simple megaphone
```
Introduction to output stream in C++
std::out, std::in, std::endl, <<, >>
```

### ex01 - encapsulation
```
Encapsulation principles - All attributes have to be private and accesesed through getters and setters
```
<pre lang=c++> class Example{
      private:
        std::string _name;
      public:
        std::string getName() const;
        void setName(std::string);
}</pre>

### ex02 - static functions and variables
```
Static variables in a class are shared among all instances of that class and are initialized only once
```
<pre lang=c++> class Example{
        private:
          static int _nbAccounts;
        public:
          static int getNbAccounts() const;
}</pre>

## 2. Memory allocation, references
### ex00 - simple class allocation
```
It is considered bad practice to use malloc in C++ because it does not construct objects
```
<pre lang=c++>Zombie* obj = new Zombie(name);
delete obj;</pre>

### ex01 - multiple objects allocation
```
This is the syntax to allocate multiple objects on the heap
```
<pre lang=c++>Zombie* objs = new Zombie[N];
delete[] objs;</pre>

### ex02 - the difference between pointers and references
```
References cannot be reassigned to refer to a different object, and they cannot be NULL
References do not require memory management, as they are simply aliases for existing objects
```
<pre lang=c++>std::string test = "HI THIS IS BRAIN";
std::string* testPTR = &test;
std::string& testREF = test;
std::cout << "The memory address of the string variable: " << &test << std::endl;
std::cout << "The memory address held by stringPTR: " << testPTR << std::endl;
std::cout << "The memory address held by stringREF: " << &testREF << std::endl;
std::cout << "The value of the string variable: " << test << std::endl;
std::cout << "The value pointed by stringPTR: " << *testPTR << std::endl;
std::cout << "The value pointed by stringREF: " << testREF << std::endl;</pre>

### ex03 - when to choose references over pointers?
```
```
<pre lang=c++></pre>
### ex04 - filestream
```
```
<pre lang=c++></pre>
### ex05 - pointers to members
```
```
<pre lang=c++></pre>
### ex06 - switch
```
```
<pre lang=c++></pre>
## 3. Orthodox Canonical Form and Fixed-Point numbers
### ex00 - structure of canonical form
```
```
<pre lang=c++></pre>
### ex01 - fixed-point conversion
```
```
<pre lang=c++></pre>
### ex02 - operator overloads
```
```
<pre lang=c++></pre>
### ex03 - point inside of a triangle
```
```
<pre lang=c++></pre>
## 4. Inheritance
### ex00 - setup of a class
```
```
<pre lang=c++></pre>
### ex01 - public inheritance, protected keyword
```
```
<pre lang=c++></pre>
### ex02 - member override
```
```
<pre lang=c++></pre>
### ex03 - diamond problem (multiple inheritance)
```
```
<pre lang=c++></pre>
## 5. Polymorphism
