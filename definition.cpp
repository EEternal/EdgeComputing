#include "definition.h"
#include <vector>
#include <windows.h>
#include <iostream>

void initial_ESL(vector<int>& Es) {
	for (int i = 0; i < E; i++) {
		Es.push_back(i);
	}
}

void delete_es(int val) {
	std::vector<int>::iterator pos;
	pos = find(Es.begin(), Es.end(), val);
	if (pos != Es.end())
		Es.erase(pos);
}

void choose_es(int param1, double param2) {
	que[param1 - 1].push_back(param2);
}

void delete_task_in_queue(int param1, double param2) {
	Sleep(DWORD(param2));
	que[param1 - 1].pop_front();
}

bool cmp(pair<int, double> a, pair<int, double> b) {
	return a.second > b.second;
}

int select_main_ES(map<int, double> val, vector<pair<int, double>>& sorted) {
	for (map<int, double>::iterator it = val.begin(); it != val.end(); it++) {
		sorted.push_back(pair<int, double>(it->first, it->second));
	}
	sort(sorted.begin(), sorted.end(), cmp);
	return sorted.front().first;
}