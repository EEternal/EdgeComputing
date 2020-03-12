#pragma once
#include <vector>
#include <queue>
#include <map>
using namespace std;

const double REQUIREMENT = 1.5;				//ʱ��Լ��   8 3 1.5
const int E = 10;							//���еı�Ե��������Ŀ
const double Vn = 27;						//������
//const double T = 1;						//С���˶�����

extern vector<int> Es;						//��ѡ�ı�Ե����������
extern double performance[E];				//ÿ����Ե������������
extern deque<double> que[E];				//��Ե�������ϵ��ŶӶ���

struct EdgeServer {
};

struct Task {
	//int num;								//�������
	double task_size;						//�����С
	double result;							//�����С
	double target;							//������ָ����
	double com_t[E];						//ͨѶʱ��
	double process_t[E];					//����ʱ��
	double que_t[E] = { 0 };				//�Ŷ�ʱ��
	double sum_t;							//ѡ����Ե���������������ʱ��
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