#include <iostream>
#include "process.h"
using namespace std;
//process¿‡ µœ÷

void process::set_process_name(string pname)
{
	process_name = pname;
}

void process::set_process_serve_time(int ptime)
{
	serve_time = ptime;
}

process::process(string pname, int ptime)
{
	arrive_time = 0;
	set_process_name(pname);
	set_process_serve_time(ptime);
	run_time = arrive_time;
}

