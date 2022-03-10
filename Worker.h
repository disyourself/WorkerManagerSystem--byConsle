#pragma once

#include<iostream>
#include<string>


using namespace std;

//职工抽象类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDepatName() = 0;


	int _ID;	//职工编号
	string _Name;	//职工姓名
	int _DeparmentId;  //部门编号
};

