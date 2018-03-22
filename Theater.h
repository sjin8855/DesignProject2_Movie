#pragma once

#include "ScreenSchedule.h"
#include "User.h"


struct MReserve
{
	string user_id;
	string movieTitle;
	string runningTime;
	string screenNum;
	int index;
};

class Theater
{
public:
	Theater(void);
	~Theater(void);

public:
	void load_user();	// 사용자 로드
	void load_movie();	// 영화 로드
	void load_reserve();	// 예매목록 로드
	void save_movie();	// 영화 저장
	void save_reserve();	// 예약 저장

public:
	User* login(string _user_id, string _pass_word);	// 로그인
	void reserveScreen(string user_id, int movie_num, string name);	// 영화예약
	void cancelScreen(string user_id, int movie_num);	// 예약취소
	void addScreen();	// 스크린 추가
	void removeScreen();	// 스크린 삭제
	void addMovie(Movie& movie);	// 영화 예외처리 후 추가
	bool namecheck(string name);	// 영화 있는것인가 체크
	list<Movie>::iterator SearchName(string name);	// 영화 이름으로 영화 리턴
public:
	void print_searchSchedule(/*int type,*/ string& m_name);	// 스크린 출력
	void print_movie();	// 영화 출력
	void print_reserve();	// 예약목록 전체출력
	void print_userReserve(string user_id);	// 로그인 사용자 예약목록 출력
	void print_searchSchedule();	//스크린 전체출력
private:
	ScreenSchedule sc;
	list<MovieScreen>::iterator movieScreen;  // 예매할 영화
	int user_count;	// 회원 명수
	User* userAry[10];	// 사용자 저장
	list<MReserve> reserveAry;	// 영화예약목록
	list<Movie> movieAry;	// 영화 저장
	
	
};

