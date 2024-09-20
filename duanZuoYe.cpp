#pragma once
#include "pch.h"
#include "duanZuoYe.h"
#include "process.h"

using namespace std;

duanzuoye::duanzuoye(Dlg2* Dlg, process_list p)
{
	short_list = p;
	dlg = Dlg;
}
//运行进程
void duanzuoye::process_running(int& current_time, process& current_process)
{

	if (current_process.get_run_time() == 1)//有进程执行完毕时标志加一
		flag++;
	current_process.Modify_Run_Time(current_process.get_run_time() - 1);
	current_time++;
//	Sleep(1000);
}

//查找并添加新进程，在shortlist中排序
void duanzuoye::process_add(int current_time, const process_list& P_List)
{
	for (int i = 0; i < P_List.get_nums(); i++)
	{
		if (current_time == P_List.get_list()[i].get_arrive_time())
		{
			short_list.push_process(P_List.get_list()[i]);
			short_list.sort_list_runtime();
		}
	}
}

void duanzuoye::scheduling() {
	//每当新进程加入时进行一次排序，运行服务时间最短的进程
	while (current_time < short_list.get_times()) {
		process_add(current_time, short_list);
		process newp = short_list.get_list().at(flag);
		process_running(current_time, newp);
		short_list.set_item(newp, flag - 1);
		dlg->UpdateQueue(short_list.get_list());
	}

}