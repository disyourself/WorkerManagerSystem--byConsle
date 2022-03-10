#include "employee.h"


Employee::Employee(int id,string name,int dId) {
	this->_ID = id;
	this->_Name = name;
	this->_DeparmentId = dId;
}

void Employee::showInfo() {
	cout << "职工编号" << this->_ID;
	cout << "\t职工姓名" << this->_Name;
	cout << "\t岗位" << this->getDepatName();
	cout << "\t岗位职责:完成经理交给的任务" << endl;
}

string Employee::getDepatName() {
	return"员工";
}