#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->_ID = id;
	this->_DeparmentId = dId;
	this->_Name = name;
}

void Boss::showInfo()
{
	cout << "ְ�����:" << this->_ID;
	cout << "\tְ������:" << this->_Name;
	cout << "\t��λ:" << this->getDepatName();
	cout << "\t��λְ��:����˾����Ա��" << endl;
}

string Boss::getDepatName()
{
	return string("�ϰ�");
}