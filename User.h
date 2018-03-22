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
	string get_userId(){return id;}	// ID 리턴
	string get_userPw(){return password;}	// 비밀번호 리턴
	string get_userName(){return name;}	// 이름 리턴
	int get_userAge(){return age;}	// 나이 리턴

	void set_userId(string _id){id=_id;};	// ID 입력
	void set_userPw(string _password){password=_password;};	// PW 입력
	void set_userName(string _name){name=_name;};	// 이름 입력
	void set_userAge(int _age){age = _age;};	//나이 입력

private:
	string id;	// 아이디
	string password;	// 비밀번호
	string name;	// 이름
	int age;	// 나이

};

