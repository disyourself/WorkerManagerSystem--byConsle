#pragma once

#include<iostream>
#include<string>

#include"Worker.h"

#include"boss.h"
#include"employee.h"
#include"manager.h"


using namespace std;

class Boss :public Worker {
public:
	Boss(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepatName();
};
