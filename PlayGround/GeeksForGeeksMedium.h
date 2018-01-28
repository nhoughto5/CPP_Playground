#pragma once
#include "stdafx.h"
using namespace std;

bool divisBy20(string num) {
	int lastTwo = stoi(num.substr(num.size() - 2, 2));
	return lastTwo % 5 == 0 && lastTwo % 4 == 0;
}

