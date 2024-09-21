#pragma once
#include "pch.h"
#include "NProcess.h"
#include <iostream>
#include <string>
#include <vector>
#include "Dlg2.h"
using namespace std;

class duanzuoye {
public:
	duanzuoye(Dlg2* Dlg, process_list p);
	//实例化短作业优先队列
	process_list p_list;
	process_list short_list;
	int current_time = 0;//当前运行时间
	int flag = 0;//当前运行进程标志
	Dlg2* dlg;
	//进程运行函数和调度函数
	void process_running(int& current_time, process& current_process);
	void process_add(int current_time);
	void scheduling();
};
