#pragma once

#include "Movie.h"
#include <list>

class MovieScreen
{
public:
	MovieScreen(void);
	MovieScreen(int id, string num, string time, int count, int m_id, Movie& m_movie);
	~MovieScreen(void);

public:	// MovieScreen클래스 멤버변수
	void set_screenId(int id){screenId = id;}	// 스크린ID 입력
	int get_screenId(){return screenId;}	// 스크린ID 리턴
	void set_screenNum(string Num){screenNum = Num;}//상영관번호 입력
	string get_screenNum(){return screenNum;}	// 상영관번호 리턴
	void set_startTime(string time){startTime = time;}	// 시작시간 입력
	string get_startTime(){return startTime;}	// 시작시간 리턴
	void set_seatCount(int count){seatCount = count;}	//남은 좌석수 입력
	int get_seatCount(){return seatCount;}	//	남은좌석수 리턴
	void set_movieId(int id){movieId=id;}	// 영화 인덱스 입력
	int get_movieId(){return movieId;}	// 영화 아이디 리턴
	void set_seatCount(){seatCount--;}	// 좌석수 입력
	void set_returnCount(){seatCount++;}// 좌석수 되돌리기
public:	// Movie클래스 멤버변수
	int get_mId(){return movie.get_movieId();}	// 영화 아이디 
	string get_mTitle(){return movie.get_movieTitle();}	//	영화제목 리턴
	string get_mRunning(){return movie.get_runningTime();}	// 영화상영시간 리턴
	int get_mAge(){return movie.get_ageRequire();}	// 관람나이 리턴
	string get_mActor(){return movie.get_mainActor();}	// 주연 리턴
	
private:
	Movie movie;
	int screenId;	// 스크린 아이디
	string screenNum;	// 상영관 번호
	string startTime;	// 시작시간
	int seatCount;	// 좌석 개수
	int movieId;	// 영화 아이디
};

