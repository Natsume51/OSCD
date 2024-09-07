#include <iostream>
#include <string>
#include "pch.h"
#include "process.h"
using namespace std;
//process¿‡ µœ÷



process::process(string pname, int ptime)
{
	arrive_time = 0;
	process_name = pname;
	serve_time = ptime;
	run_time = arrive_time;
}

process::process(const process& P)
{
	arrive_time = P.arrive_time;
	serve_time = P.serve_time;
	process_name = P.process_name;
}

void process_list::push_process(process P)
{
	p_list.push_back(P);
}

int process_list::get_nums() const
{
	return (int)p_list.size();
}

vector<process> process_list::get_list() const
{
	return p_list;
}