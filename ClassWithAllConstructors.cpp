#include "ClassWithAllConstructors.h"

//Rule of Zero
ClassWithAllConstructors1::ClassWithAllConstructors1() : _text("Empty") {}

//!=====================================================================!//

//Rule of Five
ClassWithAllConstructors2::ClassWithAllConstructors2() : _text(new std::string("Empty")), PrintEnabled(true)
{
}

ClassWithAllConstructors2::~ClassWithAllConstructors2()
{
    if(PrintEnabled) std::cout << "[destructor] freeing memory address " << _text << std::endl;
    delete _text;
}

// Parameterized constructor
ClassWithAllConstructors2::ClassWithAllConstructors2(std::string text) :_text(new std::string(text)), PrintEnabled(true)
{

    if(PrintEnabled) std::cout << "[parameterized constructor] String memory address " << _text << std::endl;    
}

// Copy constructor
ClassWithAllConstructors2::ClassWithAllConstructors2(const ClassWithAllConstructors2& other) : _text(new std::string(*other._text)), PrintEnabled(other.PrintEnabled)
{
    
    if(PrintEnabled) std::cout << "[copy constructor] String memory address " << _text << " | " << other._text << std::endl;    
}

// Move constructor
ClassWithAllConstructors2::ClassWithAllConstructors2(ClassWithAllConstructors2&& other) noexcept 
    : _text(std::exchange(other._text, nullptr)), PrintEnabled(other.PrintEnabled)
{
    if(PrintEnabled) std::cout << "[move constructor] String memory address " << _text << " | " << other._text << std::endl;    
}

//!=====================================================================!//

// Rule of Five5 using share pointers
ClassWithAllConstructors3::ClassWithAllConstructors3() : _text(std::make_shared<std::string>("Empty")) , PrintEnabled(true)
{
}

ClassWithAllConstructors3::~ClassWithAllConstructors3()
{
    if(PrintEnabled) std::cout << "[destructor] freeing memory address " << _text << std::endl;
    //delete _text; // share_ptr will manage the resource making it free and avoiding memory leak
}

// Parameterized constructor
ClassWithAllConstructors3::ClassWithAllConstructors3(std::string text) : _text(std::make_shared<std::string>(text)) , PrintEnabled(true)
{

    if(PrintEnabled) std::cout << "[parameterized constructor] String memory address " << _text << std::endl;    
}

// Copy constructor
ClassWithAllConstructors3::ClassWithAllConstructors3(const ClassWithAllConstructors3& other) : _text(other._text), PrintEnabled(other.PrintEnabled)
{
    
    if(PrintEnabled) std::cout << "[copy constructor] String memory address " << _text << " | " << other._text << std::endl;
    if(PrintEnabled) std::cout << "[copy constructor] share_ptr counter " <<  _text.use_count() << std::endl;    
}

// Move constructor
ClassWithAllConstructors3::ClassWithAllConstructors3(ClassWithAllConstructors3&& other) noexcept 
    : _text(std::move(other._text)), PrintEnabled(other.PrintEnabled)
{
    
    if(PrintEnabled) std::cout << "[move constructor] String memory address " << _text << " | " << other._text << std::endl;    
    if(PrintEnabled) std::cout << "[move constructor] share_ptr counter " <<  _text.use_count() << std::endl;    
}

/*

ClassWithAllConstructors2::ClassWithAllConstructors2() : _text(new std::string("Empty"))
{
    if(PrintEnabled) std::cout << "[default constructor] String memory address " << _text << std::endl;
}

// Parameterized constructor
ClassWithAllConstructors2::ClassWithAllConstructors2(std::string text) : _text(new std::string(text))
{

    if(PrintEnabled) std::cout << "[parameterized constructor] String memory address " << _text << std::endl;    
}

ClassWithAllConstructors2::ClassWithAllConstructors2(bool PrintEnabled)
{
    this->PrintEnabled = PrintEnabled;
}

// Copy constructor
ClassWithAllConstructors2::ClassWithAllConstructors2(const ClassWithAllConstructors2& other) : _text(new std::string(*other._text))
{
    if(PrintEnabled) std::cout << "[copy constructor] String memory address " << _text << " | " << other._text << std::endl;    
  
}

// Copy Assign constructor
ClassWithAllConstructors2 &ClassWithAllConstructors2::operator=(const ClassWithAllConstructors2 &other) 
{
    *_text = *other._text;
    if(PrintEnabled) std::cout << "[copy constructor] String memory address " << _text << " | " << other._text << std::endl;    
    return *this;
  
}

// Move constructor
ClassWithAllConstructors2::ClassWithAllConstructors2(ClassWithAllConstructors2&& other) noexcept : _text(nullptr)
{
    //free(_text);
    _text = other._text;
    other._text = nullptr;
    if(PrintEnabled) std::cout << "[move constructor] String memory address " << _text << " | " << other._text << std::endl;    
}

ClassWithAllConstructors2::~ClassWithAllConstructors2()
{
    if(PrintEnabled) std::cout << "[destructor] freeing memory address " << _text << std::endl;
    delete _text;
    //_text = nullptr;
}
*/


