#pragma once

#include "Theater.h"
#include "View.h"
#include <list>

class CGV
{
public:
	CGV(void);
	~CGV(void);

public:
	void login(string _user_id, string _password);	// �α���
	void print_start();		// ���α׷� ����ȭ��
	void print_userReserve(string user_id);// ����� ������ ���

private:
	Theater th;
	View vw;
	User* current_user;	// �α��� �����
	list<int> pro;	// �� ����

};

