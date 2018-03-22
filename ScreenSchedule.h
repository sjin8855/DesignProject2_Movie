#pragma once
#include "MovieScreen.h"
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>

class ScreenSchedule
{
public:
	ScreenSchedule(void);
	~ScreenSchedule(void);

public:
	void load_screen();	// 파일로드
	void save_screen(); // 스크린 세이브
	void print_searchSchedule(string& m_name); // 영화이름으로 스케쥴 검색
	void print_searchSchedule();	// aryScreen 출력
	void addScreen(MovieScreen& ms);	// 스크린 추가
	list<MovieScreen>::iterator reserveSchedule(int m_index); // 영화 예약
	void removeScreen(int id);// 스크린 삭제
	void calculateTime();	// 현재시간 구하기
	string get_currentTime(){return currentTime;}//현재시간 리턴

private:
	string currentTime; // 현재시간
	list<MovieScreen> aryScreen;	// 스크린 저장
};

