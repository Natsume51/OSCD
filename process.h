#include <iostream>
#include <vector>
using namespace std;
//process������
class process
{
public:
	//��������ʱ������������ͷ���ʱ��
	process(string pname, int ptime);
	process(const process& P);

private:
	int arrive_time; //����ʱ��
	int serve_time; //����ʱ��
	int run_time; //ʣ������ʱ��
	int finish_time; //����ʱ��
	string process_name; //������
};

//���̶����ࣺ�ڶԻ����е���������̣�������Ӧ��Ϣ�󣬽������Ľ��̷���ö���
class process_list
{
public:
	//��һ�����̷��������
	void push_process(process);
	//��ȡ��������
	int get_nums() const;
	//��ȡ���̶���
	vector<process> get_list() const;
private:
	vector <process> p_list;
};