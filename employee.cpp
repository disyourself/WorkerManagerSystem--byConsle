#include "employee.h"


Employee::Employee(int id,string name,int dId) {
	this->_ID = id;
	this->_Name = name;
	this->_DeparmentId = dId;
}

void Employee::showInfo() {
	cout << "ְ�����" << this->_ID;
	cout << "\tְ������" << this->_Name;
	cout << "\t��λ" << this->getDepatName();
	cout << "\t��λְ��:��ɾ�����������" << endl;
}

string Employee::getDepatName() {
	return"Ա��";
}