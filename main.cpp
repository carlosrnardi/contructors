#include "ClassWithAllConstructors.h"
#include <vector>

int main() {
    {
        std::cout << "Example of Rule of Zero \n";
        std::vector<ClassWithAllConstructors1> objects;
        std::cout << "creating object number 1\n";
        objects.push_back(ClassWithAllConstructors1());
        std::cout << "creating object number 2\n";
        objects.push_back(ClassWithAllConstructors1());
        std::cout << "creating object number 3\n";
        objects.emplace_back();
        std::cout << "End of scope\n";
    }    
    std::cout << "End of example 1\n\n-------------------------------------------------\n\n";    

    {
        std::cout << "Example of Rule of Five without resizing vector\n";
        std::vector<ClassWithAllConstructors2> objects2;
        //objects2.reserve(2);
        std::cout << "creating object number 1 [default constructor]\n";
        objects2.push_back(ClassWithAllConstructors2());
        std::cout << "creating object number 2 [parametrize constructor]\n";
        objects2.push_back(ClassWithAllConstructors2("Text"));
        std::cout << "creating object number 3 [emplace_back]\n";
        objects2.emplace_back("Test");
        //std::cout << "creating object number 4 - wrong way to do it\n";
        //objects2.emplace_back(ClassWithAllConstructors("Test"));
        std::cout << "End of scope\n";
    }
    std::cout << "End of example 2\n\n-------------------------------------------------\n\n";

    {
        std::cout << "Example of Rule of Five resizing vector\n";
        std::vector<ClassWithAllConstructors2> objects2;
        objects2.reserve(10);
        std::cout << "creating object number 1 [default constructor]\n";
        objects2.push_back(ClassWithAllConstructors2());
        std::cout << "creating object number 2 [parametrize constructor]\n";
        objects2.push_back(ClassWithAllConstructors2("Text"));
        std::cout << "creating object number 3 [emplace_back]\n";
        objects2.emplace_back("Test");
        //std::cout << "creating object number 4 - wrong way to do it\n";
        //objects2.emplace_back(ClassWithAllConstructors("Test"));     
        std::cout << "End of scope\n";   
    }   
    std::cout << "End of example 3\n\n-------------------------------------------------\n\n";     

    {
        std::cout << "Example of Rule of Five share_ptr \n";
        std::vector<ClassWithAllConstructors3> objects3;
        objects3.reserve(10);
        std::cout << "creating object number 1 [default constructor]\n";
        objects3.push_back(ClassWithAllConstructors3());
        std::cout << "creating object number 2 [parametrize constructor]\n";
        objects3.push_back(ClassWithAllConstructors3("Text"));
        std::cout << "creating object number 3 [emplace_back]\n";
        objects3.emplace_back("Test");
        //std::cout << "creating object number 4 - wrong way to do it\n";
        //objects2.emplace_back(ClassWithAllConstructors("Test"));     
        std::cout << "End of scope\n";   
    }   
    std::cout << "End of example 4\n\n-------------------------------------------------\n\n";   

    {
        std::cout << "Example of multiple interations on vector of objects\n";
        std::vector<ClassWithAllConstructors2> objects4;
        objects4.reserve(10);

        for (int count=0; count<10; count++)
        {
            objects4.emplace_back(ClassWithAllConstructors2());
            objects4.at(count).PrintEnabled = false;
            //objects3.end()->_text = "Test2";
        }

        for (auto iter = objects4.begin() ; iter != objects4.end(); iter++)
        {
            std::cout << *iter->_text << std::endl;
        }

        std::cout << "Number of objects = " << objects4.size() << std::endl;

        for (auto &obj : objects4)
        {
            std::cout << *obj._text << std::endl;
        }

        std::cout << "Size of object4 " << objects4.size() << std::endl;
        std::cout << "End of scope\n";
    }

    std::cout << "End of example 5\n\n-------------------------------------------------\n\n";    

    {
        std::cout << "Difference between copy constructor and copy assign operator\n\n";
        ClassWithAllConstructors3 objectA {"Object A"};
        std::cout << "Objeect A [" << *objectA._text << "] address [" << objectA._text << "]\n";
        ClassWithAllConstructors3 objectB (objectA);
        std::cout << "Objeect B [" << *objectB._text << "] address [" << objectB._text << "]\n";
        ClassWithAllConstructors3 objectC {"Object C"};
        std::cout << "Objeect C [" << *objectC._text << "] address [" << objectC._text << "]\n";
        ClassWithAllConstructors3 objectD;
        std::cout << "Objeect D [" << *objectD._text << "] address [" << objectD._text << "]\n";
        objectD = objectA;
        std::cout << "Objeect D=A [" << *objectD._text << "] address [" << objectD._text << "]\n";
        ClassWithAllConstructors3 objectE;
        std::cout << "Objeect E [" << *objectE._text << "] address [" << objectE._text << "]\n";
        objectE = std::move(objectA);
        std::cout << "Objeect E move A [" << *objectE._text << "] address [" << objectE._text << "]\n";            

        std::cout << "Objeect A is in a unspecified state - address [" << objectA._text << "]\n";
        std::cout << "Objeect B [" << *objectB._text << "] address [" << objectB._text << "]\n";
        std::cout << "Objeect C [" << *objectC._text << "] address [" << objectC._text << "]\n";
        std::cout << "Objeect D [" << *objectD._text << "] address [" << objectD._text << "]\n";
        std::cout << "Objeect E [" << *objectE._text << "] address [" << objectE._text << "]\n";
    }

    std::cout << "End of example 6\n\n-------------------------------------------------\n\n";    
    std::cout << "End of program \n";
    return 0;
}