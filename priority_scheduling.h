#pragma once
#include "NProcess.h"
#include "pch.h"
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#pragma once
#include <algorithm>
#include <string>
#include <Windows.h>
#include "Dlg3.h"
#include "MyProcess.h"
using namespace std;

class NPSP_Scheduling
{
private:
	vector<MyProcess> backup_process;
	Dlg3* dlg;
	bool compare(const MyProcess& a, const MyProcess& b) const; // 重载compare函数，实现非抢占式静态优先权调度策略的比较逻辑

public:
	NPSP_Scheduling(Dlg3* dlg,vector<MyProcess>& processlist);

	NPSP_Scheduling();

	void set_backup_process(vector<MyProcess>& processlist);

	void schedule(); // 非抢占式静态优先权调度策略

};
