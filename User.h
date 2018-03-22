#pragma once

#include <iostream>
#include <string>
#include <list>
using namespace std;

class User
{
public:
	User(void);
	~User(void);
	User(string _id, string _pw, string _name, int _age);

public:
	string get_userId(){return id;}	// ID ����
	string get_userPw(){return password;}	// ��й�ȣ ����
	string get_userName(){return name;}	// �̸� ����
	int get_userAge(){return age;}	// ���� ����

	void set_userId(string _id){id=_id;};	// ID �Է�
	void set_userPw(string _password){password=_password;};	// PW �Է�
	void set_userName(string _name){name=_name;};	// �̸� �Է�
	void set_userAge(int _age){age = _age;};	//���� �Է�

private:
	string id;	// ���̵�
	string password;	// ��й�ȣ
	string name;	// �̸�
	int age;	// ����

};

