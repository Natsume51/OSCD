#include <iostream>
#include <string>
#include <vector>
#include "process.h"
#include "pch.h"
#include "duoJiFanKui.h"
using namespace std;

duojifankui::duojifankui(const process_list& L,int time_slice1, int time_slice2, int time_slice3)
{
	ts1 = time_slice1;
	ts2 = time_slice2;
	ts3 = time_slice3;
	queue_1.assign(L.get_list().begin(), L.get_list().end());
}

void duojifankui::process_running(int ts, process& current_process)
{
	//�޸Ľ�������
	current_process
}

void duojifankui::scheduling()
{
	//��һ������ʱ��Ƭ�����ʼ����

	//������1��������1���������2����������3
	//���������зǿգ������иö��еĵ�һ������
	
	//���н���������Ϻ���������㷨
}
