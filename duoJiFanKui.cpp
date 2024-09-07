#include <iostream>
#include <string>
#include <vector>
#include "pch.h"
#include "duoJiFanKui.h"
using namespace std;

duojifankui::duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3)
{
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	ready_queue.assign(L.get_list().begin(), L.get_list().end());
}

void duojifankui::process_running(int ts)
{
	//修改进程数据
}

void duojifankui::scheduling()
{
	//在一个进程时间片用完后开始调度

	//检查队列1，若队列1空则检查队列2，最后检查队列3
	//若遇到队列非空，则运行该队列的第一个程序
	
	//所有进程运行完毕后结束调度算法
}