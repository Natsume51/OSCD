#include <iostream>
#include <string>
#include <vector>
#include "process.h"
#include "pch.h"
#include "duoJiFanKui.h"
using namespace std;

duojifankui::duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3)
{
	current_time = 0;
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	queue_1.assign(L.get_list().begin(), L.get_list().end());
}

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
}

//���д�����̣�
//L1�ǵ�ǰ�����У�L2����һ������
//����ǰ���еĵ�һ�����̣����ý���û��ִ�������������һ�����У�������ִ������������������
//ѭ������ֱ����ǰ���д������
//����ǰ����L1Ϊ���������У���L2Ҳ�ǵ���������
void duojifankui::queue_processing(vector<process>& L1,vector<process>&L2, int ts)
{
	int num = L1.size();
	for (int i = 0; i < num; i++)
	{
		process_running(ts, L1.at(0));
		if (L1.at(0).get_finish_time())
		{
			finish_queue.push_back(L1.at(0));
			L1.erase(L1.begin());
		}
		L2.push_back(L1.at(0));
		L1.erase(L1.begin());
	}
}

void duojifankui::scheduling()
{
	//��һ������ʱ��Ƭ�����ʼ����
	//������1��������1���������2����������3
	//���������зǿգ������иö��еĵ�һ������
	//���н���������Ϻ���������㷨

	//todo:ʵ����ռʽЧ����ÿ�δ�����һ������ʱ��Ƭ���������µ������
	//todo:��sleep����ģ��ʵ�ʴ����ʱ��
	while (!(queue_1.empty() && queue_2.empty() && queue_3.empty()))
	{
		if (!queue_1.empty())
		{
			queue_processing(queue_1, queue_2, ts1);
		}
		if (!queue_2.empty())
		{
			queue_processing(queue_2, queue_3, ts2);
		}
		if (!queue_3.empty())
		{
			queue_processing(queue_3, queue_3, ts3);
		}
	}
}
