#pragma once
#include <ostream>
#include <iostream>
class StringTest
{
    char* myBuffer;
    int m_Size;
public:
    StringTest(const char* str);

    StringTest(const StringTest& other);

    char& operator[](unsigned int i);

    ~StringTest();

    StringTest& operator=(const StringTest other);
    friend std::ostream& operator<<(std::ostream& stream, const StringTest& string);
};

