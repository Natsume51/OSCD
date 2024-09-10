#include <iostream>
#include <string>
#include <vector>
#include "process.h"
#include "pch.h"
#include "duoJiFanKui.h"
using namespace std;

duojifankui::duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3)
{
	current_time = 0;
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	queue_1.assign(L.get_list().begin(), L.get_list().end());
}

void duojifankui::process_running(int ts, process& current_process)
{
	//修改当前时间
	current_time += ts;
	//修改进程数据
	int run_time = current_process.get_run_time() - ts;
	current_process.Modify_Run_Time(run_time);
	if (!(run_time > 0))
	{
		current_process.Modify_Finish_Time(current_time);
	}
}

//队列处理过程：
//L1是当前级队列，L2是下一级队列
//处理当前队列的第一个进程，若该进程没有执行完则将其放入下一级队列，若进程执行完则将其放入结束队列
//循环处理直到当前队列处理完毕
//若当前队列L1为第三级队列，则L2也是第三级队列
void duojifankui::queue_processing(vector<process>& L1,vector<process>&L2, int ts)
{
	int num = L1.size();
	for (int i = 0; i < num; i++)
	{
		process_running(ts, L1.at(0));
		if (L1.at(0).get_finish_time())
		{
			finish_queue.push_back(L1.at(0));
			L1.erase(L1.begin());
		}
		L2.push_back(L1.at(0));
		L1.erase(L1.begin());
	}
}

void duojifankui::scheduling()
{
	//在一个进程时间片用完后开始调度
	//检查队列1，若队列1空则检查队列2，最后检查队列3
	//若遇到队列非空，则运行该队列的第一个程序
	//所有进程运行完毕后结束调度算法

	//todo:实现抢占式效果，每次处理完一个进程时间片后检查有无新到达进程
	//todo:用sleep函数模拟实际处理的时间
	while (!(queue_1.empty() && queue_2.empty() && queue_3.empty()))
	{
		if (!queue_1.empty())
		{
			queue_processing(queue_1, queue_2, ts1);
		}
		if (!queue_2.empty())
		{
			queue_processing(queue_2, queue_3, ts2);
		}
		if (!queue_3.empty())
		{
			queue_processing(queue_3, queue_3, ts3);
		}
	}
}
