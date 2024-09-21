#pragma once
#include "pch.h"
#include "duanZuoYe.h"
#include "NProcess.h"

using namespace std;

duanzuoye::duanzuoye(Dlg2* Dlg, process_list p)
{
	p_list = p;
	dlg = Dlg;
}
//运行进程
void duanzuoye::process_running(int& current_time, process& current_process)
{

	current_process.Modify_Run_Time(current_process.get_run_time() - 1);
	current_time++;	
	short_list.set_item(current_process, flag);
	if (current_process.get_run_time() == 0)//有进程执行完毕时标志加一
		flag++;
	Sleep(1000);
}

//查找并添加新进程，在shortlist中排序
void duanzuoye::process_add(int current_time)
{
	for (int i = 0; i < p_list.get_nums(); i++)
	{
		if (current_time == p_list.get_list()[i].get_arrive_time())
		{
			short_list.push_process(p_list.get_list()[i]);
			dlg->UpdateQueue(short_list.get_list(), 0);
			short_list.sort_list_runtime();
		}
	}
}

void duanzuoye::scheduling() {
	//每当新进程加入时进行一次排序，运行服务时间最短的进程
	while (current_time < p_list.get_times()) {
		process_add(current_time);
		process_running(current_time, short_list.get_list().at(flag));
		dlg->UpdateQueue(short_list.get_list(),0);
	}
}