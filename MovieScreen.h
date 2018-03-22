#pragma once

#include "Movie.h"
#include <list>

class MovieScreen
{
public:
	MovieScreen(void);
	MovieScreen(int id, string num, string time, int count, int m_id, Movie& m_movie);
	~MovieScreen(void);

public:	// MovieScreenŬ���� �������
	void set_screenId(int id){screenId = id;}	// ��ũ��ID �Է�
	int get_screenId(){return screenId;}	// ��ũ��ID ����
	void set_screenNum(string Num){screenNum = Num;}//�󿵰���ȣ �Է�
	string get_screenNum(){return screenNum;}	// �󿵰���ȣ ����
	void set_startTime(string time){startTime = time;}	// ���۽ð� �Է�
	string get_startTime(){return startTime;}	// ���۽ð� ����
	void set_seatCount(int count){seatCount = count;}	//���� �¼��� �Է�
	int get_seatCount(){return seatCount;}	//	�����¼��� ����
	void set_movieId(int id){movieId=id;}	// ��ȭ �ε��� �Է�
	int get_movieId(){return movieId;}	// ��ȭ ���̵� ����
	void set_seatCount(){seatCount--;}	// �¼��� �Է�
	void set_returnCount(){seatCount++;}// �¼��� �ǵ�����
public:	// MovieŬ���� �������
	int get_mId(){return movie.get_movieId();}	// ��ȭ ���̵� 
	string get_mTitle(){return movie.get_movieTitle();}	//	��ȭ���� ����
	string get_mRunning(){return movie.get_runningTime();}	// ��ȭ�󿵽ð� ����
	int get_mAge(){return movie.get_ageRequire();}	// �������� ����
	string get_mActor(){return movie.get_mainActor();}	// �ֿ� ����
	
private:
	Movie movie;
	int screenId;	// ��ũ�� ���̵�
	string screenNum;	// �󿵰� ��ȣ
	string startTime;	// ���۽ð�
	int seatCount;	// �¼� ����
	int movieId;	// ��ȭ ���̵�
};

