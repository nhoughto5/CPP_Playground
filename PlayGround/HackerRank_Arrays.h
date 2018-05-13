#pragma once
#include "stdafx.h"
#include <fstream>
using namespace std;
struct entry {
	int cmd,x, y;
	entry(int c, int x_, int y_) {
		cmd = c;
		x = x_;
		y = y_;
	}
};
vector<entry*> load() {
	std::ifstream infile("data.txt");
	vector<entry*> ret;
	int cmd, x, y;
	while (infile >> cmd >> x >> y) {
		ret.push_back(new entry(cmd, x, y));
	}
	return ret;
}
void dynamicArray() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N = 100, Q = 100, lastAnswer = 0;
	vector<entry*> queries = load();
	vector<vector<int>> seq(N, vector<int>(0));
	for (int i = 0; i < Q; ++i) {
		int cmd, x, y;
		cmd = queries[i]->cmd, x = queries[i]->x, y = queries[i]->y;
		int index = (x ^ lastAnswer) % N;
		switch (cmd) {
			case 1:
				seq[index].push_back(y);
				break;
			case 2:
				lastAnswer = seq[index][y%seq[index].size()];
				cout << lastAnswer << "\n";
				break;
			default:
				break;
		}
	}
}