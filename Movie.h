#ifndef _MOVIE_H
#define _MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
	Movie(void);
	Movie(int id, string title, string time, int age, string actor);
	~Movie(void);

public:
	int get_movieId(){return movieId;}	// 영화ID 리턴
	string get_movieTitle(){return movieTitle;}	// 영화제목 리턴
	string get_runningTime(){return runningTime;}	// 상영시간 리턴
	int get_ageRequire(){return ageRequire;}	// 관람나이 리턴
	string get_mainActor(){return mainActor;}	// 주연 리턴

private:
	int movieId;	// 영화 아이디
	string movieTitle;	// 영화 제목
	string runningTime;	// 상영시간
	int ageRequire;	// 관람 나이
	string mainActor;	// 주연
};
#endif
