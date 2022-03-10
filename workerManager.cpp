#include "workerManager.h"
#include"Worker.h"

#include"employee.h"
#include"manager.h"
#include"boss.h"

wokerManager::wokerManager(){
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//读文件

	//1.文件不存在	
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		
		//初始化记录人数
		this->_EmpNum = 0;
		//初始化数组指针
		this->_EmpArray = NULL;
		// 初始化文件是否为空
		this->_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		cout << "文件为空！" << endl;

		this->_EmpNum = 0;
		this->_EmpArray = NULL;
		this->_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，不为空
	int num = this->getEmpNum();
	cout << "职工人数为： " << num << endl;
	this->_EmpNum = num;

		//开辟空间 指向开辟的空间
	this->_EmpArray = new Worker * [this->_EmpNum];
		//将文件中的数据，存到数组中
	this->init_Emp();

	/*for (int i = 0; i < this->_EmpNum; i++) {
		cout << "职工编号： " << this->_EmpArray[i]->_ID;
		cout << "职工姓名： " << this->_EmpArray[i]->_Name;
		cout << "部门编号： " << this->_EmpArray[i]->_DeparmentId << endl;
	}-----test-------*/
}

void wokerManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "******  欢迎使用职工管理系统!  *****" << endl;
	cout << "*********  0.退出管理程序  *********" << endl;
	cout << "*********  1.增加职工信息  *********" << endl;
	cout << "*********  2.显示职工信息  *********" << endl;
	cout << "*********  3.删除离职职工  *********" << endl;
	cout << "*********  4.修改职工信息  *********" << endl;
	cout << "*********  5.查找职工信息  *********" << endl;
	cout << "*********  6.按照编号排序  *********" << endl;
	cout << "*********  7.清空所有文档  *********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}


void wokerManager::exitSystem()
{
	cout << "退出系统成功。" << endl;
	cout << "欢迎下次使用." << endl;
	system("pause");
	system("cls");
	exit(0);
}

void wokerManager::addEmp()
{
	int addNum = 0;	//要添加的职工数
	cout << "请输入要添加的成员个数" << endl;
	cin >> addNum;
	if (addNum <= 0) {
		cout << "输入有误" << endl;
	}
	else {
		//计算添加的新空间大小
		int newSize = this->_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下的数据，拷贝到新空间下
		if (this->_EmpArray != NULL) {
			for (int i = 0; i < this->_EmpNum; i++) {
				newSpace[i] = _EmpArray[i];
			}
		}

		//添加新数据
		for (int i=0; i < addNum; i++) {
			int id;		//职工编号
			string name;//职工姓名
			int dId;	//部门编号

			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl; 
			cout << "3.老板" << endl;
			cin >> dId;

			Worker* worker = NULL;

			switch (dId)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建职工，保存到数组种
			newSpace[this->_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[]this->_EmpArray;

		//更改新空间指向
		this->_EmpArray = newSpace;

		//更新职工人数
		this->_EmpNum = newSize;

		cout << "成功添加" << addNum << "名新职工" << endl;

		//更新职工文件不为空
		this->_FileIsEmpty = false;

		//保存数据到文件中
		this->save();
	}
	system("pause");
	system("cls");
}

void wokerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//输出的方式打开文件--写文件

	//将每个人的数据写入到文件种
	for (int i = 0; i < this->_EmpNum; i++) {
		ofs << this->_EmpArray[i]->_ID << " ";
		ofs << this->_EmpArray[i]->_Name << " ";
		ofs << this->_EmpArray[i]->_DeparmentId << endl;
	}

	ofs.close();
}

int wokerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}

	return num;
}

void wokerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {				//普通职工
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {		//经理
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {		//boss
			worker = new Boss(id, name, dId);
		}
		this->_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void wokerManager::show_Emp()
{
	//判断文件是否为空
	if (this->_FileIsEmpty) {
		cout << "文件不存在" << endl;
	}
	else {
		for (int i = 0; i < _EmpNum; i++) {
			//利用多态程序接口
			this->_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int wokerManager::IsExist(int id)
{
	int index = -1;
	
	for (int i = 0; i < this->_EmpNum;i++) {
		if (this->_EmpArray[i]->_ID == id) {
			index = i;
			break;
		}
	}
	return index;
}

void wokerManager::dele_Emp()
{
	if (this->_FileIsEmpty) {
		cout << "文件不存在或记录为空!" << endl;
	}
	else{
		int id = 0;
		cout << "请输入要删除的职工编号:" << endl;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1) {		//说明职工存在，删除index上的职工
			//数据前移
			for (int i = index; i < this->_EmpNum - 1; i++) {
				this->_EmpArray[i] = this->_EmpArray[i + 1];
			}
			//更新数组中人员个数
			this->_EmpNum--;
			//同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败,未找到该职工" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void wokerManager::modify_Emp()
{
	if (this->_FileIsEmpty) {
		cout << "文件不存在或记录为空!" << endl;
	}
	else {
		int id = 0;
		cout << "请输入要修改的职工编号:" << endl;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret == -1) {
			cout << "操作失败--职工不存在!" << endl;
		}
		else{		
			//说明职工存在，修改arr[ret]上的职工
			cout << "查找到" << id << "号员工." << endl;
			cout << "--------------------------------------" << endl;

			delete this->_EmpArray[ret];

			int newId;
			string newName;
			int newDepaSelect;

			cout << "请输入修改后的职工编号:" << endl;
			cin >> newId;
			cout << "请输入职工姓名：" << endl;
			cin >> newName;
			cout << "请输入修改后的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newDepaSelect;

			Worker* worker = NULL;

			switch (newDepaSelect) {
			case 1:
				worker = new Employee(newId, newName, newDepaSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, newDepaSelect);
				break; 
			case 3:
				worker = new Boss(newId, newName, newDepaSelect);
					break;
			default:
				break;
			}

			this->_EmpArray[ret] = worker;

			cout << "修改成功!" << endl;

			this->save();
		}
	}
	system("pause");
	system("cls");
}



	


wokerManager::~wokerManager()
{
}
