#pragma once
#include <iostream>
#include "process.h"
#include <string>
#include <vector>
#include "pch.h"
using namespace std;

class duanzuoye {
public:
	//�������к����͵��Ⱥ���
	void process_running(int& current_time, process& current_process);
	void process_add(int current_time, const process_list& P_List,process_list& short_list);
	void scheduling(process_list& short_list);
};

//ʵ��������ҵ���ȶ���
process_list short_list;
int current_time=0;//��ǰ����ʱ��
int flag = 0;//��ǰ���н��̱�־