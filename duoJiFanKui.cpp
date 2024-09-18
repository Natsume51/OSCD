#include <iostream>
#include <string>
#include <vector>
#include "process.h"
#include "pch.h"
#include "duoJiFanKui.h"
#include "MFCApplication1Dlg.h"
#include "Dlg1.h"
using namespace std;

duojifankui::duojifankui(Dlg1* dlg,process_list& L, int time_slice1, int time_slice2, int time_slice3)
{
	Dlg = dlg;
	current_time = 0;
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	auto listp = L.get_list();
	queue_1.assign(listp.begin(), listp.end());
	totalTime = L.get_times();
}
//�����̶����еĽ�����ȡ��һ�������У�����ʼ���������е�ʱ��Ƭ
duojifankui::duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3)
{
	current_time = 0;
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	auto listp = L.get_list();
	queue_1.assign(listp.begin(), listp.end());
	totalTime = L.get_times();
}
//�������к���
void duojifankui::process_running(int ts, process& current_process)
{
	//�޸ĵ�ǰʱ��
	current_time += ts;
	//�޸Ľ�������
	int run_time = current_process.get_run_time() - ts;
	current_process.Modify_Run_Time(run_time);
	if (!(run_time > 0))
	{
		current_process.Modify_Finish_Time(current_time);
	}
	//����������������������������������������������������������������>>ʹ��sleep����ģ�����ʵ������ʱ��<<��������������������������������������������������������������������������������������
	//Sleep(ts * 1000);
}

//���д�����̣�
//L1�ǵ�ǰ�����У�L2����һ������
//����ǰ���еĵ�һ�����̣����ý���û��ִ�������������һ�����У�������ִ������������������
//ѭ������ֱ����ǰ���д������
//����ǰ����L1Ϊ���������У���L2Ҳ�ǵ���������
void duojifankui::queue_processing(vector<process>& L1,vector<process>&L2, int ts, int queue_idx)
{
	int num = L1.size();
	for (int i = 0; i < num; i++)
	{
		process_running(ts, L1.at(0));
		if (!(L1.at(0).get_finish_time()))//1
		{
			finish_queue.push_back(L1.at(0));
			L1.erase(L1.begin());
		}
		else
		{
			L2.push_back(L1.at(0));
			L1.erase(L1.begin());
		}
		Dlg->UpdateQueue(queue_1, 0);
		Dlg->UpdateQueue(queue_2, 1);
		Dlg->UpdateQueue(queue_3, 2);
		Dlg->TotalProgressStep(current_time / totalTime - Dlg->m_TotalProCtrl.GetPos());
		//ÿ���������н������������½��̵���
		if (queue_idx != 1 && !queue_1.empty())
		{
			queue_processing(queue_1, queue_2, ts1, 1);
		}
	}
}

//���ȹ��̺���
void duojifankui::scheduling()
{
	//��һ������ʱ��Ƭ�����ʼ����
	//������1��������1���������2����������3
	//���������зǿգ������иö��еĵ�һ������
	//���н���������Ϻ���������㷨
	while (!(queue_1.empty() && queue_2.empty() && queue_3.empty()))
	{
		if (!queue_1.empty())
		{
			queue_processing(queue_1, queue_2, ts1, 1);
		}
		if (!queue_2.empty())
		{
			queue_processing(queue_2, queue_3, ts2, 2);
		}
		if (!queue_3.empty())
		{
			queue_processing(queue_3, queue_3, ts3, 3);
		}

	}
}
