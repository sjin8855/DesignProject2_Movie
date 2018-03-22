#include "ScreenSchedule.h"

ScreenSchedule::ScreenSchedule(void)
{
}

ScreenSchedule::~ScreenSchedule(void)
{

}

void ScreenSchedule::load_screen()	// 파일로드
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

void ScreenSchedule::print_searchSchedule(string& m_name) // 영화이름으로 스케쥴 검색
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

void ScreenSchedule::print_searchSchedule()	// aryScreen 출력
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

void ScreenSchedule::addScreen(MovieScreen& ms)	// 스크린 추가
{
	list<MovieScreen>::iterator add_start = aryScreen.begin();
	bool check = false;
	while(add_start!=--aryScreen.end())
	{
		if(add_start->get_screenId()==ms.get_screenId())
		{
			cout<<"인덱스가 중복되었습니다"<<endl;
			check = true;
			return ;
		}
		add_start++;
	}
	if(add_start->get_screenId() == ms.get_screenId())
	{
		cout<<"인덱스가 중복되었습니다."<<endl;
		check = true;
		return ;
	}
	if(check==false)
	{
		cout<<"추가되었습니다."<<endl;
		aryScreen.push_back(ms);
		save_screen();
	}
}

list<MovieScreen>::iterator ScreenSchedule::reserveSchedule(int m_index) // 영화 예약
{
	list<MovieScreen>::iterator start;
	list<MovieScreen>::iterator end;
	list<MovieScreen>::iterator noting;	//없을경우

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

void ScreenSchedule::removeScreen(int id)// 스크린 삭제
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
		cout<<"입력한 인덱스의 스크린이 제거되었습니다."<<endl;
		save_screen();
	}
	else
		cout<<"입력한 인덱스가 존재하지 않습니다."<<endl;
}

void ScreenSchedule::calculateTime()	// 현재시간 구하기
{
	time_t timer = time(NULL);    //라이브러리에서 시스템 시간을 저장하도록 정의된 자료형이 time_t
	struct tm t;  
	localtime_s(&t, &timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	int buf;
	char target[10];

	//년
	buf = t.tm_year + 1900;
	itoa(buf,target,10);   // int형을 char형으로 변환
	currentTime.append(target);	// currentTime변수 뒤에 append해준다.


	// 월
	buf = t.tm_mon + 1;
	if(buf < 10) //  자리수가 한자리 숫자인 경우 앞에 0을 붙여준다
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

	//일
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

	//시
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

	//분
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