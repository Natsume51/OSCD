#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "pch.h"
#include "process.h"
using namespace std;
class duanzuoye {
public:
	//�����̶����еĽ�����ȡ������������
	duanzuoye(const process_list& L);
	//�������к����͵��Ⱥ���
	void process_running(int ts);
	void scheduling();
private:
	vector<process> ready_queue;
};
