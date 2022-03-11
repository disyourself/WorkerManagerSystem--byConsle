#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include<vector>

#include"Worker.h"

#define FILENAME "DataBase/empList.txt"


using namespace std;


class wokerManager
{
public:

	wokerManager();

	bool _FileIsEmpty;	//判断文件是否为空
	int _EmpNum;		//记录职工人数
	Worker** _EmpArray;	//职工数组指针
	
	//展示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//添加职工
	void addEmp();

	//保存文件
	void save();

	//统计文件中人数
	int getEmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void show_Emp();

	//判断职工是否存在
	int IsExist(int id);
	int IsExist(string name);

	//删除职工
	void dele_Emp();

	//修改职工信息
	void modify_Emp();

	//查找员工
	void find_Emp();

	//按职工编号排序
	void sort_Emp();

	//清空所有文档
	void dele_AllData();


	~wokerManager();
};

