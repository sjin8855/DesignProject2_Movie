#include "View.h"

View::View(void)
{

}

View::~View(void)
{

}

// 사용자 함수
void View::print_menu()	//메인메뉴
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1.로그인"<<endl;
	cout<<"2.로그아웃"<<endl;
	cout<<"3.종료"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_pmenu()	//사용자 영화예매 메뉴 
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1.영화예매"<<endl;
	cout<<"2.예매취소"<<endl;
	cout<<"3.예매목록"<<endl;
	cout<<"4.뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_login()	// 로그인
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1.사용자 로그인"<<endl;
	cout<<"2.관리자 로그인"<<endl;
	cout<<"3.뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_logout()	// 로그아웃
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 로그아웃"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_close()	//프로그램 종료
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 종료"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_reserve()	// 영화예약
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 영화예약"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_cancelReserve()	// 예매 취소
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 예매취소"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

// 관리자 함수
void View::print_adminMenu()	// 관리자 메뉴
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 스크린 추가"<<endl;
	cout<<"2. 스크린 제거"<<endl;
	cout<<"3. 스크린현황 보기"<<endl;
	cout<<"4. 예매현황 보기"<<endl;
	cout<<"5. 뒤로 가기"<<endl<<endl;

	cout<<"메뉴 선택 : ";
}

void View::print_addScreen()	// 스크린 추가
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 스크린 추가"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_removeScreen()	// 스크린 제거
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 스크린 제거"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_reserveList()	// 예매현황보기 
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 예매현황 보기"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}

void View::print_screenSchedule()	// 스크린현황보기
{
	cout<<"CGV"<<endl<<endl;
	cout<<"1. 스크린현황 보기"<<endl;
	cout<<"2. 뒤로가기"<<endl<<endl;
	cout<<"메뉴 선택 : ";
}