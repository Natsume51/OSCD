#pragma once
#include "pch.h"
#include "Dlg3.h"
#include "NProcess.h"

class MyProcess : public process //作业类（带（静态）优先级），这里优先级需要手动设置在作业类当中
{
protected:
	int priority;
public:
	MyProcess(string ids, int st, int at, int prt);

	int get_priority() const;

	void run() const;//作业执行函数-非抢占式执行


};

