#include <iostream>
using namespace std;
//process������
class process
{
public:
	int arrive_time; //����ʱ��
	int serve_time; //����ʱ��
	int run_time; //ʣ������ʱ��
	int finish_time; //����ʱ��
	string process_name;
	void set_process_name(string pname);
	void set_process_serve_time(int ptime);
	//��������
	process(string pname, int ptime);
};
