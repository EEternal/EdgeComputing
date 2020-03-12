#include <iostream>
#include <vector>
#include "definition.h"

using namespace std;

vector<int> Es;
double performance[E] = {
	1300, 1700, 1200, 1600, 1400, 1800, 1100, 1500, 1900, 1000};
deque<double> que[E];

int main() {
	initial_ESL(Es);
	//initial_QL();
	struct Task t;
	t.task_size = 25;
	t.result = 1;
	t.target = 10000;
	int result1;
	result1 = SAE(t);
	if (result1 != -1) {
		cout<<"选中的边缘服务器序号是" << result1;
		return 0;
	}
	else{
		vector<int> result2 = CEC(t);
		cout << "选中的边缘服务器序号是： ";
		for (int i = 0; i < int(result2.size()); i++) {
			cout << result2.at(i) <<' ';
		}
		return 0;
	}
}