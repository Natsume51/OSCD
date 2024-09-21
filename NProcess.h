#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "pch.h"
#include <algorithm>
#include <numeric>
using namespace std;
//process������
class process
{
public:
	//��������ʱ������������ͷ���ʱ��
	process(string pname, int ptime);
	//----������뵽��ʱ��
	process(string pname, int ptime, int pArrTime);

	process(const process& P);
	//��ȡ���̸�����Ϣ�Ľӿ�
	int get_arrive_time() const;
	int get_serve_time() const;
	int get_run_time();
	int get_finish_time();
	string get_process_name();
	//�޸Ľ���ʣ������ʱ��ͽ���ʱ��ĺ����ӿ�
	void Modify_Run_Time(int newTime);
	void Modify_Finish_Time(int newTime);
private:
	int arrive_time; //����ʱ��
	int serve_time; //����ʱ��
	int run_time; //ʣ������ʱ��
	int finish_time; //����ʱ��
	string process_name; //������
};

//���̶����ࣺ�ڶԻ����е���������̣�������Ӧ��Ϣ�󣬽������Ľ��̷���ö��У����Խ�����Ϊ���̵ľ�������
class process_list
{
public:
	void set_item(process p, int num);
	//��һ�����̷��������
	void push_process(process);
	//��ȡ��������
	int get_nums() const;
	//��ȡ���̶���
	vector<process> get_list() const;
	//���̶������򣨰�����ʱ�䣩
	void sort_list_runtime();
	//��ȡ�ܷ���ʱ��
	int get_times();
private:
	vector <process> p_list;
};
