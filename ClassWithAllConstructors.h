#include <string>
#include <iostream> // std::cout
#include <utility>  // std:exchanged
#include <memory>   // std::shared_ptr
#ifndef CLASSWITHALLCONSTRUCTORS_H
#define CLASSWITHALLCONSTRUCTORS_H

#pragma once


// Rule of Zero
class ClassWithAllConstructors1
{
public:
    std::string _text;
    ClassWithAllConstructors1();
};

class ClassWithAllConstructors2
{

// Rule of Five
public:
    bool PrintEnabled = true;
    std::string *_text;
    // Default constructor
    ClassWithAllConstructors2();

    // Parameterized constructor
    ClassWithAllConstructors2(std::string text);

    // Copy constructor
    ClassWithAllConstructors2(const ClassWithAllConstructors2& other);

     // Copy Assigned constructor
    ClassWithAllConstructors2& operator=(const ClassWithAllConstructors2& other);

    // Move constructor
    ClassWithAllConstructors2(ClassWithAllConstructors2&& other) noexcept;

    // Move Assigned constructor
    ClassWithAllConstructors2& operator=(ClassWithAllConstructors2&& other);

    // Destructor
    ~ClassWithAllConstructors2();
};


// Rule of Five5 using share pointers
class ClassWithAllConstructors3
{

public:
    bool PrintEnabled = true;
    std::shared_ptr <std::string> _text;

    // Default constructor
    ClassWithAllConstructors3();

    // Parameterized constructor
    ClassWithAllConstructors3(std::string text);

    // Copy constructor
    ClassWithAllConstructors3(const ClassWithAllConstructors3& other);

     // Copy Assigned constructor
    ClassWithAllConstructors3& operator=(const ClassWithAllConstructors3& other);

    // Move constructor
    ClassWithAllConstructors3(ClassWithAllConstructors3&& other) noexcept;

    // Move Assigned constructor
    ClassWithAllConstructors3& operator=(ClassWithAllConstructors3&& other);

    // Destructor
    ~ClassWithAllConstructors3();
};

#endif