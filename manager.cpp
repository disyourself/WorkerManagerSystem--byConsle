#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->_ID = id;
	this->_DeparmentId = dId;
	this->_Name = name;
}

void Manager::showInfo()
{
	cout << "职工编号:" << this->_ID;
	cout << "\t职工姓名:" << this->_Name;
	cout << "\t岗位:" << this->getDepatName();
	cout << "\t岗位职责:管理员工完成项目" << endl;
}

string Manager::getDepatName()
{
	return string("经理");
}
