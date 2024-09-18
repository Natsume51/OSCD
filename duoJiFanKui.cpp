#include <iostream>
#include <string>
#include <vector>
#include "process.h"
#include "pch.h"
#include "duoJiFanKui.h"
#include "MFCApplication1Dlg.h"
#include "Dlg1.h"
using namespace std;

duojifankui::duojifankui(Dlg1* dlg,process_list& L, int time_slice1, int time_slice2, int time_slice3)
{
	Dlg = dlg;
	current_time = 0;
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	auto listp = L.get_list();
	queue_1.assign(listp.begin(), listp.end());
	totalTime = L.get_times();
}
//将进程队列中的进程拉取到一级队列中，并初始化三个队列的时间片
duojifankui::duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3)
{
	current_time = 0;
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	auto listp = L.get_list();
	queue_1.assign(listp.begin(), listp.end());
	totalTime = L.get_times();
}
//进程运行函数
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
	//————————————————————————————————>>使用sleep函数模拟进程实际运行时间<<———————————————————————————————————————————
	//Sleep(ts * 1000);
}

//队列处理过程：
//L1是当前级队列，L2是下一级队列
//处理当前队列的第一个进程，若该进程没有执行完则将其放入下一级队列，若进程执行完则将其放入结束队列
//循环处理直到当前队列处理完毕
//若当前队列L1为第三级队列，则L2也是第三级队列
void duojifankui::queue_processing(vector<process>& L1,vector<process>&L2, int ts, int queue_idx)
{
	int num = L1.size();
	for (int i = 0; i < num; i++)
	{
		process_running(ts, L1.at(0));
		if (!(L1.at(0).get_finish_time()))//1
		{
			finish_queue.push_back(L1.at(0));
			L1.erase(L1.begin());
		}
		else
		{
			L2.push_back(L1.at(0));
			L1.erase(L1.begin());
		}
		Dlg->UpdateQueue(queue_1, 0);
		Dlg->UpdateQueue(queue_2, 1);
		Dlg->UpdateQueue(queue_3, 2);
		Dlg->TotalProgressStep(current_time / totalTime - Dlg->m_TotalProCtrl.GetPos());
		//每个进程运行结束后检测有无新进程到达
		if (queue_idx != 1 && !queue_1.empty())
		{
			queue_processing(queue_1, queue_2, ts1, 1);
		}
	}
}

//调度过程函数
void duojifankui::scheduling()
{
	//在一个进程时间片用完后开始调度
	//检查队列1，若队列1空则检查队列2，最后检查队列3
	//若遇到队列非空，则运行该队列的第一个进程
	//所有进程运行完毕后结束调度算法
	while (!(queue_1.empty() && queue_2.empty() && queue_3.empty()))
	{
		if (!queue_1.empty())
		{
			queue_processing(queue_1, queue_2, ts1, 1);
		}
		if (!queue_2.empty())
		{
			queue_processing(queue_2, queue_3, ts2, 2);
		}
		if (!queue_3.empty())
		{
			queue_processing(queue_3, queue_3, ts3, 3);
		}

	}
}
