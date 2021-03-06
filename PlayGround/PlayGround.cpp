// PlayGround.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Timer.h"
//#include "Utils.h"
//#include "RandomTasks.h"
//#include "GeeksForGeeksMedium.h"
//#include "BinaryTree.h"
//#include "LinkedList.h"
//#include "HackerRank_Arrays.h"
//#include "IKMTest.h"
//#include <iostream> 
//#include <map>
//#include <algorithm>
//#include <numeric>
//#include <unordered_set>
using namespace std;

class String {
    char* myBuffer;
    int m_Size;
public:
    String(const char* str) {
        m_Size = strlen(str);
        myBuffer = new char[m_Size + 1];
        memcpy(myBuffer, str, m_Size);
        myBuffer[m_Size] = 0;
    }

    String(const String& other) 
        : m_Size(other.m_Size)
    {
        myBuffer = new char[m_Size + 1];
        memcpy(myBuffer, other.myBuffer, m_Size + 1);

    }

    char& operator[](unsigned int i) {
        return myBuffer[i];
    }

    ~String() {
        delete[] myBuffer;
    }

    String& operator=(const String other);
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

String& String::operator=(const String other) {
    std::cout << "Assign\n";
    if (this != &other) {
        m_Size = other.m_Size;
        myBuffer = new char[m_Size + 1];
        memcpy(myBuffer, other.myBuffer, m_Size + 1);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.myBuffer;
    return stream;
}

int main() {
    Timer t;
    String str1 = "Nick";
    String str2 = str1;
    str1 = str2;
    str2[1] = 'o';

    std::cout << str1 << "\n";
    std::cout << str2 << "\n";
}