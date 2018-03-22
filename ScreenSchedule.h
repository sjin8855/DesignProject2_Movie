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
	void load_screen();	// ���Ϸε�
	void save_screen(); // ��ũ�� ���̺�
	void print_searchSchedule(string& m_name); // ��ȭ�̸����� ������ �˻�
	void print_searchSchedule();	// aryScreen ���
	void addScreen(MovieScreen& ms);	// ��ũ�� �߰�
	list<MovieScreen>::iterator reserveSchedule(int m_index); // ��ȭ ����
	void removeScreen(int id);// ��ũ�� ����
	void calculateTime();	// ����ð� ���ϱ�
	string get_currentTime(){return currentTime;}//����ð� ����

private:
	string currentTime; // ����ð�
	list<MovieScreen> aryScreen;	// ��ũ�� ����
};

