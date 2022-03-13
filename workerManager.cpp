#include "workerManager.h"
#include"Worker.h"

#include"employee.h"
#include"manager.h"
#include"boss.h"

wokerManager::wokerManager(){
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�

	//1.�ļ�������	
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		
		//��ʼ����¼����
		this->_EmpNum = 0;
		//��ʼ������ָ��
		this->_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;

		this->_EmpNum = 0;
		this->_EmpArray = NULL;
		this->_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ���Ϊ��
	int num = this->getEmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->_EmpNum = num;

		//���ٿռ� ָ�򿪱ٵĿռ�
	this->_EmpArray = new Worker * [this->_EmpNum];
		//���ļ��е����ݣ��浽������
	this->init_Emp();

	/*for (int i = 0; i < this->_EmpNum; i++) {
		cout << "ְ����ţ� " << this->_EmpArray[i]->_ID;
		cout << "ְ�������� " << this->_EmpArray[i]->_Name;
		cout << "���ű�ţ� " << this->_EmpArray[i]->_DeparmentId << endl;
	}-----test-------*/
}

void wokerManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "******  ��ӭʹ��ְ������ϵͳ!  *****" << endl;
	cout << "*********  0.�˳��������  *********" << endl;
	cout << "*********  1.����ְ����Ϣ  *********" << endl;
	cout << "*********  2.��ʾְ����Ϣ  *********" << endl;
	cout << "*********  3.ɾ����ְְ��  *********" << endl;
	cout << "*********  4.�޸�ְ����Ϣ  *********" << endl;
	cout << "*********  5.����ְ����Ϣ  *********" << endl;
	cout << "*********  6.���ձ������  *********" << endl;
	cout << "*********  7.��������ĵ�  *********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}


void wokerManager::exitSystem()
{
	cout << "�˳�ϵͳ�ɹ���" << endl;
	cout << "��ӭ�´�ʹ��." << endl;
	system("pause");
	system("cls");
	exit(0);
}

void wokerManager::addEmp()
{
	int addNum = 0;	//Ҫ��ӵ�ְ����
	cout << "������Ҫ��ӵĳ�Ա����" << endl;
	cin >> addNum;
	if (addNum <= 0) {
		cout << "��������" << endl;
	}
	else {
		//������ӵ��¿ռ��С
		int newSize = this->_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->_EmpArray != NULL) {
			for (int i = 0; i < this->_EmpNum; i++) {
				newSpace[i] = _EmpArray[i];
			}
		}

		//���������
		for (int i=0; i < addNum; i++) {
			int id;		//ְ�����
			string name;//ְ������
			int dId;	//���ű��

			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl; 
			cout << "3.�ϰ�" << endl;
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

			//������ְ�������浽������
			newSpace[this->_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[]this->_EmpArray;

		//�����¿ռ�ָ��
		this->_EmpArray = newSpace;

		//����ְ������
		this->_EmpNum = newSize;

		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//����ְ���ļ���Ϊ��
		this->_FileIsEmpty = false;

		//�������ݵ��ļ���
		this->save();
	}
	system("pause");
	system("cls");
}

void wokerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//����ķ�ʽ���ļ�--д�ļ�

	//��ÿ���˵�����д�뵽�ļ���
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
		if (dId == 1) {				//��ְͨ��
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {		//����
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->_FileIsEmpty) {
		cout << "�ļ�������" << endl;
	}
	else {
		for (int i = 0; i < _EmpNum; i++) {
			//���ö�̬����ӿ�
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

int wokerManager::IsExist(string name)
{
	int index = -1;

	for (int i = 0; i < this->_EmpNum; i++) {
		if (this->_EmpArray[i]->_Name == name) {
			index = i;
			break;
		}
	}
	return index;
}

void wokerManager::dele_Emp()
{
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else{
		int id = 0;
		cout << "������Ҫɾ����ְ�����:" << endl;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1) {		//˵��ְ�����ڣ�ɾ��index�ϵ�ְ��
			//����ǰ��
			for (int i = index; i < this->_EmpNum - 1; i++) {
				this->_EmpArray[i] = this->_EmpArray[i + 1];
			}
			//������������Ա����
			this->_EmpNum--;
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ��,δ�ҵ���ְ��" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void wokerManager::modify_Emp()
{
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		int id = 0;
		cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret == -1) {
			cout << "����ʧ��--ְ��������!" << endl;
		}
		else{		
			//˵��ְ�����ڣ��޸�arr[ret]�ϵ�ְ��
			cout << "���ҵ�" << id << "��Ա��." << endl;
			cout << "--------------------------------------" << endl;

			delete this->_EmpArray[ret];

			int newId;
			string newName;
			int newDepaSelect;

			cout << "�������޸ĺ��ְ�����:" << endl;
			cin >> newId;
			cout << "������ְ��������" << endl;
			cin >> newName;
			cout << "�������޸ĺ�ĸ�λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			cout << "�޸ĳɹ�!" << endl;

			this->save();
		}
	}
	system("pause");
	system("cls");
}

void wokerManager::find_Emp()
{
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		cout << "���������Ա���ķ�ʽ:" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;

		int select = 0;
		cin >> select;

		//���ձ��
		if (select == 1) {
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			int id;
			cin>>id;

			int ret = this->IsExist(id);

			if (ret == -1) {
				cout << "���ҵ�Ա�������ڣ�" << endl;
			}
			else {
				cout << "���ҵ�" << id << "��Ա����Ϣ" << endl;
				_EmpArray[ret]->showInfo();
			}
		}
		//��������
		else if (select == 2) {
			cout << "������Ҫ���ҵ�Ա������:" << endl;
			string name;
			cin >> name;

			int ret = this->IsExist(name);

			if (ret == -1) {
				cout << "���ҵ�Ա�������ڣ�" << endl;
			}
			else {
				cout << "���ҵ�" << ret<<"��"<<name << "Ա����Ϣ" << endl;
				_EmpArray[ret]->showInfo();
			}
		}
	}
	system("pause");
	system("cls");
}

void wokerManager::sort_Emp()
{
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ�Ϊ��!!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ:  " << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < _EmpNum; i++) {
			int minOrMax = i;	//������Сֵ �� ���ֵ�±�
			for(int j=i+1;j<this->_EmpNum;j++){
				// ����
				if (select == 1) {
					if (this->_EmpArray[minOrMax]->_ID > this->_EmpArray[j]->_ID) {
						minOrMax = j;
					}
				}
				//����
				else {
					if (this->_EmpArray[minOrMax]->_ID < this->_EmpArray[j]->_ID) {
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��ǣ��������--��������
			if (i != minOrMax) {
				Worker* temp = this->_EmpArray[i];
				_EmpArray[i] = _EmpArray[minOrMax];
				_EmpArray[minOrMax] = temp;
			}				
		}
		cout << "����ɹ��������Ľ��Ϊ" << endl;
		this->save();   //�����Ľ�����浽�ļ���
		this->show_Emp();
	}
}

void wokerManager::dele_AllData()
{
	cout << "ȷ�����?" << endl;
	cout << "����-1-ȷ��" << endl;
	int select=0;
	cin >> select;
	if (select == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);	//ɾ���ļ����ٴ���
		ofs.close();

		//����������
		if (this->_EmpArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->_EmpNum; i++) {
				delete this->_EmpArray[i];
				this->_EmpArray[i] = NULL;
			}
			//ɾ������������ָ��
			delete[] this->_EmpArray;
			this->_EmpArray = NULL;
			this->_EmpNum = 0;
			this->_FileIsEmpty = true;
		}
		cout << "����ɹ�!" << endl;
	}
	system("pause");
	system("cls");
}



	


wokerManager::~wokerManager()
{
}
