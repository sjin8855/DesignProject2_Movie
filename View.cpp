#include "View.h"

View::View(void)
{

}

View::~View(void)
{

}

// ����� �Լ�
void View::print_menu()	//���θ޴�
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1.�α���"<<endl;
	cout<<"2.�α׾ƿ�"<<endl;
	cout<<"3.����"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_pmenu()	//����� ��ȭ���� �޴� 
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1.��ȭ����"<<endl;
	cout<<"2.�������"<<endl;
	cout<<"3.���Ÿ��"<<endl;
	cout<<"4.�ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_login()	// �α���
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1.����� �α���"<<endl;
	cout<<"2.������ �α���"<<endl;
	cout<<"3.�ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_logout()	// �α׾ƿ�
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. �α׾ƿ�"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_close()	//���α׷� ����
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ����"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_reserve()	// ��ȭ����
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ��ȭ����"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_cancelReserve()	// ���� ���
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. �������"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

// ������ �Լ�
void View::print_adminMenu()	// ������ �޴�
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ��ũ�� �߰�"<<endl;
	cout<<"2. ��ũ�� ����"<<endl;
	cout<<"3. ��ũ����Ȳ ����"<<endl;
	cout<<"4. ������Ȳ ����"<<endl;
	cout<<"5. �ڷ� ����"<<endl<<endl;

	cout<<"�޴� ���� : ";
}

void View::print_addScreen()	// ��ũ�� �߰�
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ��ũ�� �߰�"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_removeScreen()	// ��ũ�� ����
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ��ũ�� ����"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_reserveList()	// ������Ȳ���� 
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ������Ȳ ����"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}

void View::print_screenSchedule()	// ��ũ����Ȳ����
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. ��ũ����Ȳ ����"<<endl;
	cout<<"2. �ڷΰ���"<<endl<<endl;
	cout<<"�޴� ���� : ";
}