#pragma once
#include <iostream>
#include <string>
using namespace std;

class View
{
public:
	View(void);
	~View(void);

public:	// ����� �Լ�
	void print_menu();	//���θ޴�
	void print_pmenu();	//����� ��ȭ���� �޴� 
	void print_login();	// �α���
	void print_logout();	// �α׾ƿ�
	void print_close();	//���α׷� ����
	void print_reserve();	// ��ȭ����
	void print_cancelReserve();	// ���� ���

public: // ������ �Լ�
	void print_adminMenu();	// ������ �޴�
	void print_addScreen();	// ��ũ�� �߰�
	void print_removeScreen();	// ��ũ�� ����
	void print_reserveList();	// ������Ȳ���� 
	void print_screenSchedule();	// ��ũ����Ȳ����

};

