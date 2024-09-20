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
//���н���
void duanzuoye::process_running(int& current_time, process& current_process)
{

	if (current_process.get_run_time() == 1)//�н���ִ�����ʱ��־��һ
		flag++;
	current_process.Modify_Run_Time(current_process.get_run_time() - 1);
	current_time++;
//	Sleep(1000);
}

//���Ҳ�����½��̣���shortlist������
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
	//ÿ���½��̼���ʱ����һ���������з���ʱ����̵Ľ���
	while (current_time < short_list.get_times()) {
		process_add(current_time, short_list);
		process newp = short_list.get_list().at(flag);
		process_running(current_time, newp);
		short_list.set_item(newp, flag - 1);
		dlg->UpdateQueue(short_list.get_list());
	}

}