#pragma once
#include <iostream>
#include <vector>
using namespace std;
//process类声明
class process
{
public:
	//创建进程时需输入进程名和服务时间
	process(string pname, int ptime);
	//----添加输入到达时间
	process(string pname, int ptime, int pArrTime);

	process(const process& P);
	//获取进程各种信息的接口
	int get_arrive_time();
	int get_serve_time() const;
	int get_run_time();
	int get_finish_time();
	string get_process_name();
	//修改进程剩余运行时间和结束时间的函数接口
	void Modify_Run_Time(int newTime);
	void Modify_Finish_Time(int newTime);
private:
	int arrive_time; //到达时间
	int serve_time; //服务时间
	int run_time; //剩余运行时间
	int finish_time; //结束时间
	string process_name; //进程名
};

//进程队列类：在对话框中点击创建进程，输入相应信息后，将创建的进程放入该队列，可以将其作为进程的就绪队列
class process_list
{
public:
	int get_times() const;
	//将一个进程放入队列中
	void push_process(process);
	//获取进程数量
	int get_nums() const;
	//获取进程队列
	vector<process> get_list() const;
private:
	vector <process> p_list;
};