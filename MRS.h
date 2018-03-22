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
	void login(string _user_id, string _password);	// 로그인
	void print_start();		// 프로그램 시작화면
	void print_userReserve(string user_id);// 사용자 예약목록 출력

private:
	Theater th;
	View vw;
	User* current_user;	// 로그인 사용자
	list<int> pro;	// 뷰 저장

};

