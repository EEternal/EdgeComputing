#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include "definition.h"
using namespace std;

vector<int> CEC(struct  Task t) {
	double instructions;
	int main_ES;
	double temp_sum = 0;
	map<int, double> IN;
	vector<int> Result;
	vector<pair<int, double>> sorted;
	for (int i = 0; i < E; i++) {
		instructions = 1;						//????
		IN.insert(pair<int, double>(i, instructions));
	}
	main_ES = select_main_ES(IN, sorted);
	for (int i = 1; i < E; i++) {
		temp_sum += sorted.at(i).second;
		Result.push_back(sorted.at(i).first);
		if (temp_sum > t.target) {
			break;
		}
	}
	return Result;
}