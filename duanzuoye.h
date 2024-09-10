#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "pch.h"
#include "process.h"
using namespace std;
class duanzuoye {
public:
	//将进程队列中的进程拉取到就绪队列中
	duanzuoye(const process_list& L);
	//进程运行函数和调度函数
	void process_running(int ts);
	void scheduling();
private:
	vector<process> ready_queue;
};
