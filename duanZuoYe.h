#pragma once
#include "pch.h"
#include "process.h"
#include <iostream>
#include <string>
#include <vector>
#include "Dlg2.h"
using namespace std;

class duanzuoye {
public:
	duanzuoye(Dlg2* Dlg, process_list p);
	//ʵ��������ҵ���ȶ���
	process_list short_list;
	int current_time = 0;//��ǰ����ʱ��
	int flag = 0;//��ǰ���н��̱�־
	Dlg2* dlg;
	//�������к����͵��Ⱥ���
	void process_running(int& current_time, process& current_process);
	void process_add(int current_time, const process_list& P_List);
	void scheduling();
};
