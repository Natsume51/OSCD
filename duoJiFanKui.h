#pragma once
#include <iostream>
#include "process.h"
using namespace std;
class duojifankui
{
public:
	//将进程队列中的进程拉取到就绪队列中，并初始化三个队列的时间片
	duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3);
private:
	//三个队列的时间片
	int ts1, ts2, ts3;
	//就绪队列+三级队列
	vector<process> ready_queue;
	vector<process> queue_1;
	vector<process> queue_2;
	vector<process> queue_3;
	//进程运行函数和调度函数
	void process_running(int ts);
	void scheduling();

};