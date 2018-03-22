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
	void load_user();	// ����� �ε�
	void load_movie();	// ��ȭ �ε�
	void load_reserve();	// ���Ÿ�� �ε�
	void save_movie();	// ��ȭ ����
	void save_reserve();	// ���� ����

public:
	User* login(string _user_id, string _pass_word);	// �α���
	void reserveScreen(string user_id, int movie_num, string name);	// ��ȭ����
	void cancelScreen(string user_id, int movie_num);	// �������
	void addScreen();	// ��ũ�� �߰�
	void removeScreen();	// ��ũ�� ����
	void addMovie(Movie& movie);	// ��ȭ ����ó�� �� �߰�
	bool namecheck(string name);	// ��ȭ �ִ°��ΰ� üũ
	list<Movie>::iterator SearchName(string name);	// ��ȭ �̸����� ��ȭ ����
public:
	void print_searchSchedule(/*int type,*/ string& m_name);	// ��ũ�� ���
	void print_movie();	// ��ȭ ���
	void print_reserve();	// ������ ��ü���
	void print_userReserve(string user_id);	// �α��� ����� ������ ���
	void print_searchSchedule();	//��ũ�� ��ü���
private:
	ScreenSchedule sc;
	list<MovieScreen>::iterator movieScreen;  // ������ ��ȭ
	int user_count;	// ȸ�� ���
	User* userAry[10];	// ����� ����
	list<MReserve> reserveAry;	// ��ȭ������
	list<Movie> movieAry;	// ��ȭ ����
	
	
};

