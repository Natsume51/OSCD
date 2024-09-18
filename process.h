#pragma once
#include <iostream>
#include <vector>
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
	int get_arrive_time();
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
	int get_times() const;
	//��һ�����̷��������
	void push_process(process);
	//��ȡ��������
	int get_nums() const;
	//��ȡ���̶���
	vector<process> get_list() const;
private:
	vector <process> p_list;
};