#pragma once
#include <vector>
#include <queue>
#include <map>
using namespace std;

const double REQUIREMENT = 1.5;				//时间约束   8 3 1.5
const int E = 10;							//所有的边缘服务器数目
const double Vn = 27;						//数据率
//const double T = 1;						//小车运动周期

extern vector<int> Es;						//供选的边缘服务器集合
extern double performance[E];				//每个边缘服务器的性能
extern deque<double> que[E];				//边缘服务器上的排队队列

struct EdgeServer {
};

struct Task {
	//int num;								//任务序号
	double task_size;						//任务大小
	double result;							//结果大小
	double target;							//任务总指令数
	double com_t[E];						//通讯时间
	double process_t[E];					//处理时间
	double que_t[E] = { 0 };				//排队时间
	double sum_t;							//选定边缘服务器后的总运行时间
};

void initial_ESL(vector<int>& Es);
void initial_QL();
void delete_es(int val);
void choose_es(int param1, double param2);
void delete_task_in_queue(int param1, double param2);
int select_main_ES(map<int, double> val, vector<pair<int, double>>& sorted);
bool cmp(pair<int, double> a, pair<int, double> b);
vector<int> CEC(struct  Task t);
int SAE(struct Task t);