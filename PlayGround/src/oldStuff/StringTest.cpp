#include "StringTest.h"

StringTest& StringTest::operator=(const StringTest other) {
    std::cout << "Assign\n";
    if (this != &other) {
        m_Size = other.m_Size;
        myBuffer = new char[m_Size + 1];
        memcpy(myBuffer, other.myBuffer, m_Size + 1);
    }
    return *this;
}

StringTest::StringTest(const char* str)
{
    m_Size = strlen(str);
    myBuffer = new char[m_Size + 1];
    memcpy(myBuffer, str, m_Size);
    myBuffer[m_Size] = 0;
}

StringTest::StringTest(const StringTest& other)
    : m_Size(other.m_Size)
{
    myBuffer = new char[m_Size + 1];
    memcpy(myBuffer, other.myBuffer, m_Size + 1);
}

char& StringTest::operator[](unsigned int i)
{
    return myBuffer[i];
}

StringTest::~StringTest()
{
    delete[] myBuffer;
}

std::ostream& operator<<(std::ostream& stream, const StringTest& string) {
    stream << string.myBuffer;
    return stream;
}
