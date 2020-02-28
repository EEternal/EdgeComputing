#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include "definition.h"
using namespace std;

int SAE(struct Task t){
    srand((int)time(0));
    for (int i = 0; i < E; i++) {
        t.com_t[i] = (t.task_size + t.result) / Vn;
         t.process_t[i] = t.target / performance[i];
        for (int j = 0; j < int(que[i].size()); j++) {
            t.que_t[i] += que[i].at(j);
        }
        if (t.que_t[i] >= REQUIREMENT) {
            delete_es(i);
        }
        else {
             double tmp1 = t.com_t[i] + t.que_t[i] + t.process_t[i];
            if (tmp1 > REQUIREMENT) {
                delete_es(i);
            }
        }
    }
    if (Es.size() == 0)
        return -1;
    else if (Es.size() == 1)
        return 0;
    else {
        int tmp2 = rand() % Es.size() + 1;
        int result = Es[tmp2 - 1];
        t.sum_t = t.com_t[result] + t.que_t[result] + t.process_t[result];
        choose_es(result, t.sum_t);
        delete_task_in_queue(result, t.sum_t);
        return result;
    }
 }