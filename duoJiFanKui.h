#pragma once
#include <iostream>
#include "process.h"
using namespace std;
class duojifankui
{
public:
	//�����̶����еĽ�����ȡ��һ�������У�����ʼ���������е�ʱ��Ƭ
	duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3);
private:
	//�������е�ʱ��Ƭ
	int ts1, ts2, ts3;
	//��ǰʱ�䣬��ʼ��Ϊ0����process_running���޸���ֵ
	int current_time;
	//��������+���н����Ľ��̶���
	vector<process> queue_1;
	vector<process> queue_2;
	vector<process> queue_3;
	vector<process> finish_queue;
	//�������к����͵��Ⱥ���
	void process_running(int ts, process& current_process);
	void queue_processing(vector<process>& L1, vector<process>& L2, int ts);
	void scheduling();

};