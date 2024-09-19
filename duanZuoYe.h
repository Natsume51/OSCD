#pragma once
#include <iostream>
#include "process.h"
#include <string>
#include <vector>
#include "pch.h"
using namespace std;

class duanzuoye {
public:
	//进程运行函数和调度函数
	void process_running(int& current_time, process& current_process);
	void process_add(int current_time, const process_list& P_List,process_list& short_list);
	void scheduling(process_list& short_list);
};

//实例化短作业优先队列
process_list short_list;
int current_time=0;//当前运行时间
int flag = 0;//当前运行进程标志