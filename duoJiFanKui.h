#pragma once
#include <iostream>
#include "process.h"
using namespace std;
class duojifankui
{
public:
	//将进程队列中的进程拉取到一级队列中，并初始化三个队列的时间片
	duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3);
private:
	//三个队列的时间片
	int ts1, ts2, ts3;
	//当前时间，初始化为0，在process_running中修改其值
	int current_time;
	//三个队列+运行结束的进程队列
	vector<process> queue_1;
	vector<process> queue_2;
	vector<process> queue_3;
	vector<process> finish_queue;
	//进程运行函数和调度函数
	void process_running(int ts, process& current_process);
	void queue_processing(vector<process>& L1, vector<process>& L2, int ts);
	void scheduling();

};