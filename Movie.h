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
	int get_movieId(){return movieId;}	// ��ȭID ����
	string get_movieTitle(){return movieTitle;}	// ��ȭ���� ����
	string get_runningTime(){return runningTime;}	// �󿵽ð� ����
	int get_ageRequire(){return ageRequire;}	// �������� ����
	string get_mainActor(){return mainActor;}	// �ֿ� ����

private:
	int movieId;	// ��ȭ ���̵�
	string movieTitle;	// ��ȭ ����
	string runningTime;	// �󿵽ð�
	int ageRequire;	// ���� ����
	string mainActor;	// �ֿ�
};
#endif
