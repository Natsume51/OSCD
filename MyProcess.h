#pragma once
#include "pch.h"
#include "Dlg3.h"
#include "NProcess.h"

class MyProcess : public process //��ҵ�ࣨ������̬�����ȼ������������ȼ���Ҫ�ֶ���������ҵ�൱��
{
protected:
	int priority;
public:
	MyProcess(string ids, int st, int at, int prt);

	int get_priority() const;

	void run() const;//��ҵִ�к���-����ռʽִ��


};

