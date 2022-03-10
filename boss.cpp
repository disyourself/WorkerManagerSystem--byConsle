#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->_ID = id;
	this->_DeparmentId = dId;
	this->_Name = name;
}

void Boss::showInfo()
{
	cout << "职工编号:" << this->_ID;
	cout << "\t职工姓名:" << this->_Name;
	cout << "\t岗位:" << this->getDepatName();
	cout << "\t岗位职责:管理公司所有员工" << endl;
}

string Boss::getDepatName()
{
	return string("老板");
}