#include <iostream>
using namespace std;
//process类声明
class process
{
public:
	int arrive_time; //到达时间
	int serve_time; //服务时间
	int run_time; //剩余运行时间
	int finish_time; //结束时间
	string process_name;
	void set_process_name(string pname);
	void set_process_serve_time(int ptime);
	//创建进程
	process(string pname, int ptime);
};
