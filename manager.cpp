#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->_ID = id;
	this->_DeparmentId = dId;
	this->_Name = name;
}

void Manager::showInfo()
{
	cout << "ְ�����:" << this->_ID;
	cout << "\tְ������:" << this->_Name;
	cout << "\t��λ:" << this->getDepatName();
	cout << "\t��λְ��:����Ա�������Ŀ" << endl;
}

string Manager::getDepatName()
{
	return string("����");
}
