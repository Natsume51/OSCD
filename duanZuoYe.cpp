#include "duanzuoye.h"
using namespace std;

//运行进程
void duanzuoye::process_running(int& current_time, process& current_process) {

	cout << current_process.get_process_name() << endl;
	if (current_process.get_run_time() == 1)//有进程执行完毕时标志加一
		flag++;
	current_process.Modify_Run_Time(current_process.get_run_time() - 1);
	current_time++;
	Sleep(1000);
}

//查找并添加新进程，在shortlist中排序
 void duanzuoye::process_add(int current_time, const process_list& P_List,process_list& short_list) {
	 for (int i = 0; i < P_List.get_nums(); i++) {
		 if (current_time == P_List.get_list()[i].get_arrive_time()) {
			 short_list.push_process(P_List.get_list()[i]);
			 short_list.sort_list_runtime();
		 }
	 }
}

void duanzuoye::scheduling(process_list& short_list) {
	//每当新进程加入时进行一次排序，运行服务时间最短的进程
	while (current_time < short_list.get_times()){
		process_add(current_time, P_List, short_list);
		process_running(current_time, short_list.get_list()[flag]);
	}

}