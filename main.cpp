#include<iostream>
#include<string>


#include"Worker.h"
#include"workerManager.h"

#include"boss.h"
#include"employee.h"
#include"manager.h"


//void test();

int main() {

	//ʵ����manager����
	wokerManager wm;

	int choice;

	while (1) {

		wm.showMenu();

		cin>>choice;

		switch(choice){
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3: 
			wm.dele_Emp();
			break;
		case 4:
			wm.modify_Emp();
			break;
		case 5:
			wm.find_Emp();
			break;
		case 6:
			wm.sort_Emp();
			break;
		case 7:
			wm.dele_AllData();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}




//���Դ���
//void test() {
//	Worker* worker = NULL;
//
//	worker = new Employee(1, "����", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "����g", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "����w", 3);
//	worker->showInfo();
//	delete worker;
//
//	worker = NULL;
//
//	system("pause");
//}