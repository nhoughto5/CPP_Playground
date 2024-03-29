#include <iostream>
#include <vector>
#include "utils/Timer.h"
#include "dynamicProgramming/DynamicProgramming.h"
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

int main() {
    Timer t;

    DynamicProgramming a;
    cout << "Case 1: " << a.howSum(7, { 5,3,4,7 }) << endl;
}