#include "ScreenSchedule.h"

ScreenSchedule::ScreenSchedule(void)
{
}

ScreenSchedule::~ScreenSchedule(void)
{

}

void ScreenSchedule::load_screen()	// ���Ϸε�
{
	MovieScreen screen;
	string s_num, s_time;
	int index, s_seat, s_id, m_id, m_age;
	string m_title, m_running, m_actor;
	calculateTime();		
	ifstream fis("screen.txt");
	string record;
	while(getline(fis, record))
	{
		stringstream spacing(record);
		spacing >> index >> s_num >> s_time >> s_seat >> s_id;
		if(s_time > currentTime)
		{
			ifstream fim("movie.txt");
			string m_record;
			while(getline(fim, m_record))
			{
				stringstream spacing(m_record);
				spacing >> m_id >> m_title >> m_running >> m_age >> m_actor;
				if(s_id == m_id)
				{
					Movie movie(m_id, m_title, m_running, m_age, m_actor);
					MovieScreen m_screen(index, s_num, s_time, s_seat, s_id, movie);
					aryScreen.push_back(m_screen);
				}
			}
		}
	}	

}

void ScreenSchedule::save_screen()
{
	ofstream ofs;
	ofs.open("screen.txt");
	list<MovieScreen>::iterator screen = aryScreen.begin();
	while(screen!=--aryScreen.end())
	{
		ofs <<screen->get_screenId()<<" "<<screen->get_screenNum()<<" "
			<<screen->get_startTime()<<" "<<screen->get_seatCount()<<" "
			<<screen->get_mId()<<endl;
		screen++;
	}
	ofs	<<screen->get_screenId()<<" "<<screen->get_screenNum()<<" "
		<<screen->get_startTime()<<" "<<screen->get_seatCount()<<" "
		<<screen->get_mId()<<endl;


}

void ScreenSchedule::print_searchSchedule(string& m_name) // ��ȭ�̸����� ������ �˻�
{
	list<MovieScreen>::iterator checkStart;
	list<MovieScreen>::iterator checkEnd;
	checkStart = aryScreen.begin();
	checkEnd = --aryScreen.end();
	while(checkStart!=checkEnd)
	{
		if(checkStart->get_mTitle()==m_name)
		{
			cout<<checkStart->get_screenId()<<"  "<<checkStart->get_screenNum()<<"  "
			<<checkStart->get_startTime()<<"  "<<checkStart->get_seatCount()<<"  "
			<<checkStart->get_mTitle()<<"  "<<checkStart->get_mRunning()<<"  "
			<<checkStart->get_mAge()<<"  "<<checkStart->get_mActor()<<endl;
		}
	checkStart++;
	}
	if(checkStart==checkEnd)
	{
		if(checkStart->get_mTitle()==m_name)
		{
			cout<<checkStart->get_screenId()<<"  "<<checkStart->get_screenNum()<<"  "
			<<checkStart->get_startTime()<<"  "<<checkStart->get_seatCount()<<"  "
			<<checkStart->get_mTitle()<<"  "<<checkStart->get_mRunning()<<"  "
			<<checkStart->get_mAge()<<"  "<<checkStart->get_mActor()<<endl;
		}
	}
}	

void ScreenSchedule::print_searchSchedule()	// aryScreen ���
{
	list<MovieScreen>::iterator checkStart = aryScreen.begin();
	list<MovieScreen>::iterator checkEnd = --aryScreen.end();
	while(checkStart!=checkEnd)
	{
		cout<<checkStart->get_screenId()<<"  "<<checkStart->get_screenNum()<<"  "
			<<checkStart->get_startTime()<<"  "<<checkStart->get_seatCount()<<"  "
			<<checkStart->get_mTitle()<<"  "<<checkStart->get_mRunning()<<"  "
			<<checkStart->get_mAge()<<"  "<<checkStart->get_mActor()<<endl;

	checkStart++;
	}

	if(checkStart==checkEnd)
	{
		cout<<checkStart->get_screenId()<<"  "<<checkStart->get_screenNum()<<"  "
			<<checkStart->get_startTime()<<"  "<<checkStart->get_seatCount()<<"  "
			<<checkStart->get_mTitle()<<"  "<<checkStart->get_mRunning()<<"  "
			<<checkStart->get_mAge()<<"  "<<checkStart->get_mActor()<<endl;
	}
}

void ScreenSchedule::addScreen(MovieScreen& ms)	// ��ũ�� �߰�
{
	list<MovieScreen>::iterator add_start = aryScreen.begin();
	bool check = false;
	while(add_start!=--aryScreen.end())
	{
		if(add_start->get_screenId()==ms.get_screenId())
		{
			cout<<"�ε����� �ߺ��Ǿ����ϴ�"<<endl;
			check = true;
			return ;
		}
		add_start++;
	}
	if(add_start->get_screenId() == ms.get_screenId())
	{
		cout<<"�ε����� �ߺ��Ǿ����ϴ�."<<endl;
		check = true;
		return ;
	}
	if(check==false)
	{
		cout<<"�߰��Ǿ����ϴ�."<<endl;
		aryScreen.push_back(ms);
		save_screen();
	}
}

list<MovieScreen>::iterator ScreenSchedule::reserveSchedule(int m_index) // ��ȭ ����
{
	list<MovieScreen>::iterator start;
	list<MovieScreen>::iterator end;
	list<MovieScreen>::iterator noting;	//�������

	start = aryScreen.begin();
	end = --aryScreen.end();
	while(start!=end)
	{
		if(start->get_screenId()==m_index)
			return start;
		start++;
	}
	if(start==end)
		if(start->get_screenId()==m_index)
			return start;
	return noting;
}

void ScreenSchedule::removeScreen(int id)// ��ũ�� ����
{
	list<MovieScreen>::iterator remove;
	remove = aryScreen.begin();
	bool check = false;
	while(remove!=--aryScreen.end())
	{
		if(remove->get_screenId() == id)
		{
			check = true;
			break;
		}
		remove++;
	}
	if(remove->get_screenId() == id)
	{
		check = true;
	}

	if(check == true)
	{
		aryScreen.erase(remove);
		cout<<"�Է��� �ε����� ��ũ���� ���ŵǾ����ϴ�."<<endl;
		save_screen();
	}
	else
		cout<<"�Է��� �ε����� �������� �ʽ��ϴ�."<<endl;
}

void ScreenSchedule::calculateTime()	// ����ð� ���ϱ�
{
	time_t timer = time(NULL);    //���̺귯������ �ý��� �ð��� �����ϵ��� ���ǵ� �ڷ����� time_t
	struct tm t;  
	localtime_s(&t, &timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�
	int buf;
	char target[10];

	//��
	buf = t.tm_year + 1900;
	itoa(buf,target,10);   // int���� char������ ��ȯ
	currentTime.append(target);	// currentTime���� �ڿ� append���ش�.


	// ��
	buf = t.tm_mon + 1;
	if(buf < 10) //  �ڸ����� ���ڸ� ������ ��� �տ� 0�� �ٿ��ش�
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//��
	buf = t.tm_mday;
	if(buf < 10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//��
	buf = t.tm_hour;
	if(buf < 10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//��
	buf = t.tm_min;
	if(buf < 10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
		//cout << currentTime << endl;
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}
}