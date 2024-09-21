#include "NProcess.h"
#include "MyProcess.h"
#include "pch.h"
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
#include "priority_scheduling.h"
using namespace std;



MyProcess::MyProcess(string ids, int st, int at, int prt) :process(ids, st, at), priority(prt) {};

int MyProcess::get_priority() const
{
	return priority;
}

void MyProcess::run() const
{
	Sleep(this->get_serve_time() * 1000);
}


bool NPSP_Scheduling::compare(const MyProcess& a, const MyProcess& b) const
{
	if (a.get_priority() != b.get_priority())
		return a.get_priority() > b.get_priority();
	else
		return a.get_arrive_time() < b.get_arrive_time();
}

NPSP_Scheduling::NPSP_Scheduling(Dlg3* Dlg, vector<MyProcess>& processlist)
{
	
	backup_process.assign(processlist.begin(), processlist.end());
	dlg = Dlg;
}


void NPSP_Scheduling::set_backup_process(vector<MyProcess>& processlist)
{
	backup_process.assign(processlist.begin(), processlist.end());
}

void NPSP_Scheduling::schedule()
{

	sort(backup_process.begin(), backup_process.end(), [this](const MyProcess& a, const MyProcess& b) { return this->compare(a, b); });

	for (auto& process : backup_process)
	{
		dlg->UpdateQueue(backup_process, 0);
		process.run();
	}

	backup_process.clear();
}