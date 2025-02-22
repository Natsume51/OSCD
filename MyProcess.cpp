#include <iostream>
#include <string>
#include "pch.h"
#include "NProcess.h"
using namespace std;
//process窃糞��



process::process(string pname, int ptime)
{
	arrive_time = 0;
	process_name = pname;
	serve_time = ptime;
	run_time = serve_time;
	finish_time = 0;
}

process::process(string pname, int ptime, int pArrTime)
{
	arrive_time = pArrTime;
	process_name = pname;
	serve_time = ptime;
	run_time = serve_time;
	finish_time = 0;
}
process::process(const process& P)
{
	arrive_time = P.arrive_time;
	serve_time = P.serve_time;
	process_name = P.process_name;
	run_time = P.run_time;
	finish_time = P.finish_time;
}
void process::Modify_Run_Time(int newTime)
{
	run_time = newTime;
}

void process::Modify_Finish_Time(int newTime)
{
	finish_time = newTime;
}

int process::get_arrive_time() const
{
	return arrive_time;
}
int process::get_serve_time() const
{
	return serve_time;
}
int process::get_run_time()
{
	return run_time;
}
int process::get_finish_time()
{
	return finish_time;
}
string process::get_process_name()
{
	return process_name;
}

//！！！！！！！！！！！！！！！！！！！！！！
void process_list::push_process(process P)
{
	p_list.push_back(P);
}

int process_list::get_nums() const
{
	return (int)p_list.size();
}

void process_list::set_item(process p, int num)
{
	p_list[num] = p;
}

vector<process> process_list::get_list() const
{
	return p_list;
}

bool cmp(process x, process y)
{
	return x.get_run_time() < y.get_run_time();
}

void process_list::sort_list_runtime()
{
	sort(p_list.begin(), p_list.end(), cmp);
}

int process_list::get_times(){
	int sum = 0;
	for (int i = 0; i < get_nums(); i++) {
		sum += p_list[i].get_serve_time();
	}
	return sum;
}
