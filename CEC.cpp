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
		for (int j = 0; j < int(que[i].size()); j++) {
            t.que_t[i] += que[i].at(j);
        }
		instructions = (REQUIREMENT - t.que_t[i]) * performance[i];
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
	//divide
	for (int i = 0; i < int(Result.size()); i++) {
		double t_task = REQUIREMENT - t.que_t[Result.at(i) - 1];
		choose_es(Result.at(i), t_task);
		delete_task_in_queue(Result.at(i), t_task);
	}
	//merge
	return Result;
}