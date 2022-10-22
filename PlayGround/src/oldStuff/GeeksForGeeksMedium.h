#pragma once
#include "stdafx.h"
using namespace std;

bool divisBy20(string num) {
	int lastTwo = stoi(num.substr(num.size() - 2, 2));
	return lastTwo % 5 == 0 && lastTwo % 4 == 0;
}

template<class T>
void printVector(vector<T>& input) {
	for (int i = 0; i < input.size(); ++i) {
		std::cout << input[i] << "    ";
	}
	std::cout << "\n";
}

template<class T>
void templateSort(vector<T>& input) {
	int n = input.size();
	bool b = true;
	while (b) {
		b = false;
		for (size_t i = 0; i < n-1; ++i) {
			if (input[i] > input[i+1]) {
				T temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
				b = true;
			}
		}
	}
}

int longesSubArrayWithKOddNumbers(int arr[], int n, int k) {
	int max = 0, count = 0, start = 0;
	for (size_t i = 0; i < n; ++i) {
		if (arr[i] % 2 != 0) count++;
		while (count > k && start<= i) {
			if (arr[start++] % 2 != 0) {
				count--;
			}
		}
		if (count == k) {
			if (max < (i - start + 1)) {
				max = (i - start + 1);
			}
		}
	}
	return max;
}

