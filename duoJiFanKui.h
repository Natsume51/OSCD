#pragma once
#include <iostream>
#include "NProcess.h"
#include "Dlg1.h"
using namespace std;
class duojifankui
{
public:
	duojifankui(Dlg1* dlg, process_list& L, int time_slice1, int time_slice2, int time_slice3);
	//将进程队列中的进程拉取到一级队列中，并初始化三个队列的时间片
	duojifankui(process_list& L,int time_slice1, int time_slice2, int time_slice3);
	//调度过程函数
	void scheduling();
private:
	int totalTime;
	Dlg1* Dlg;
	//三个队列的时间片
	int ts1, ts2, ts3;
	//当前时间，初始化为0，在process_running中修改其值
	int current_time;
	//三个队列+运行结束的进程队列
	vector<process> queue_1;
	vector<process> queue_2;
	vector<process> queue_3;
	vector<process> finish_queue;
	//进程运行函数和队列内过程函数
	void process_running(int ts, process& current_process);
	void queue_processing(vector<process>& L1, vector<process>& L2, int ts, int queue_idx);
};