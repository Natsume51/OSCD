#pragma once
#include <iostream>
#include "NProcess.h"
#include "Dlg1.h"
using namespace std;
class duojifankui
{
public:
	duojifankui(Dlg1* dlg, process_list& L, int time_slice1, int time_slice2, int time_slice3);
	//�����̶����еĽ�����ȡ��һ�������У�����ʼ���������е�ʱ��Ƭ
	duojifankui(process_list& L,int time_slice1, int time_slice2, int time_slice3);
	//���ȹ��̺���
	void scheduling();
private:
	int totalTime;
	Dlg1* Dlg;
	//�������е�ʱ��Ƭ
	int ts1, ts2, ts3;
	//��ǰʱ�䣬��ʼ��Ϊ0����process_running���޸���ֵ
	int current_time;
	//��������+���н����Ľ��̶���
	vector<process> queue_1;
	vector<process> queue_2;
	vector<process> queue_3;
	vector<process> finish_queue;
	//�������к����Ͷ����ڹ��̺���
	void process_running(int ts, process& current_process);
	void queue_processing(vector<process>& L1, vector<process>& L2, int ts, int queue_idx);
};