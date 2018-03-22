#pragma once
#include <iostream>
#include <string>
using namespace std;

class View
{
public:
	View(void);
	~View(void);

public:	// 사용자 함수
	void print_menu();	//메인메뉴
	void print_pmenu();	//사용자 영화예매 메뉴 
	void print_login();	// 로그인
	void print_logout();	// 로그아웃
	void print_close();	//프로그램 종료
	void print_reserve();	// 영화예약
	void print_cancelReserve();	// 예매 취소

public: // 관리자 함수
	void print_adminMenu();	// 관리자 메뉴
	void print_addScreen();	// 스크린 추가
	void print_removeScreen();	// 스크린 제거
	void print_reserveList();	// 예매현황보기 
	void print_screenSchedule();	// 스크린현황보기

};

