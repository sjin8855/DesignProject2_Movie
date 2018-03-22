#include "Theater.h"

Theater::Theater(void)
{
	user_count=0;
}

Theater::~Theater(void)
{

}

void Theater::load_user()	// 사용자 로드
{
	user_count=0;
	string _id, _password, _name ;
	int _age;

	ifstream fin("user.txt");
	string record;
	while(getline(fin, record))
	{
		User* user = new User;
		stringstream spacing(record);
		spacing >> _id >> _password >> _name >> _age;
		user->set_userId(_id);
		user->set_userPw(_password);
		user->set_userName(_name);
		user->set_userAge(_age);
		userAry[user_count] = user;
		user_count++;
	}

}

void Theater::load_movie()	// 영화 로드
{
	int m_id, m_age;
	string m_title, m_running, m_actor;

	ifstream fin("movie.txt");
	string record;
	while(getline(fin, record))
	{
		stringstream spacing(record);
		spacing >> m_id >> m_title >> m_running >>         
			m_age >> m_actor;
		Movie movie(m_id, m_title, m_running, m_age, m_actor);
		movieAry.push_back(movie);
	}
	sc.load_screen();
}
void Theater::load_reserve()	// 예매목록 로드
{
	string id, movie_name, start_time, sight;
	int index;
	ifstream fin("reserve.txt");
	string record;
	while(getline(fin, record))
	{
		
		stringstream spacing(record);
		spacing >> id >> sight >> movie_name >> start_time >> index;
		if(start_time > sc.get_currentTime())
		{
			MReserve reserve;
			reserve.user_id = id;
			reserve.screenNum = sight;
			reserve.movieTitle = movie_name;
			reserve.runningTime = start_time;
			reserve.index = index;
		
			reserveAry.push_back(reserve);
		}
	}

}

void Theater::save_movie()	// 영화 저장
{
	ofstream ofs;
	ofs.open("movie.txt");
	list<Movie>::iterator movie = movieAry.begin();
	while(movie!=--movieAry.end())
	{
		ofs <<movie->get_movieId()<<" "<<movie->get_movieTitle()<<" "
			<<movie->get_runningTime()<<" "<<movie->get_ageRequire()<<" "
			<<movie->get_mainActor()<<endl;
		movie++;
	}
	ofs <<movie->get_movieId()<<" "<<movie->get_movieTitle()<<" "
			<<movie->get_runningTime()<<" "<<movie->get_ageRequire()<<" "
			<<movie->get_mainActor();
}

void Theater::save_reserve()	// 예약 저장
{
	ofstream ofs;
	ofs.open("reserve.txt");
	list<MReserve>::iterator reserve = reserveAry.begin();
	while(reserve!=--reserveAry.end())
	{
		ofs <<reserve->user_id<<" "<<reserve->screenNum<<" "
			<<reserve->movieTitle<<" "<<reserve->runningTime<<" "
			<<reserve->index<<endl;
		reserve++;
	}
	ofs <<reserve->user_id<<" "<<reserve->screenNum<<" "
			<<reserve->movieTitle<<" "<<reserve->runningTime<<" "
			<<reserve->index;
}

User* Theater::login(string _user_id, string _pass_word)	// 로그인
{
	for(int i=0; i<user_count; i++)
	{
		if(userAry[i]->get_userId()==_user_id)
			if(userAry[i]->get_userPw()==_pass_word)
			{
				cout<<"로그인되었습니다."<<endl;
				return userAry[i];
			}
	}
	cout<<"로그인에 실패하였습니다."<<endl;
	return NULL;
}

void Theater::reserveScreen(string user_id, int movie_num, string name)	// 영화예약
{
	MReserve reserve;
	list<MovieScreen>::iterator movie;
	movie = sc.reserveSchedule(movie_num);
	if(movie->get_mTitle() == name)
	{
		reserve.movieTitle = movie->get_mTitle();
		reserve.runningTime = movie->get_startTime();
		reserve.screenNum = movie->get_screenNum();
		reserve.user_id = user_id;
		reserve.index = movie->get_screenId();
		reserveAry.push_back(reserve);
		cout<<movie->get_screenId()<<"  "<<movie->get_screenId()<<"  "
			<<movie->get_screenNum()<<"  "<<movie->get_mRunning()<<"  "
			<<movie->get_seatCount()<<"  "<<movie->get_mTitle()<<"  "
			<<movie->get_startTime()<<"  "<<movie->get_mActor()<<endl;
		cout<<"영화예매가 완료되었습니다."<<endl;
		save_reserve();
		movie->set_seatCount();
		sc.save_screen();
		
	}

	else
		cout<<"인덱스의 값이 올바르지 않습니다."<<endl;
}

void Theater::cancelScreen(string user_id, int movie_num)	// 예약취소
{
	list<MReserve>::iterator reserve;
	list<MovieScreen>::iterator movie;
	movie = sc.reserveSchedule(movie_num);
	reserve = reserveAry.begin();
	MReserve cancel;
	cancel.user_id = user_id;
	cancel.index = movie_num;
	bool check = false;	// 인덱스의 같은지 유무 파학
	while(reserve!=reserveAry.end())
	{
		if(reserve->index == cancel.index)
		{
			check = true;	//인덱스가 같다.
			break;
		}
		reserve++;
	}
	if(check == true)
	{
		reserveAry.erase(reserve);
		cout<<"예매 취소하였습니다."<<endl;
		movie->set_returnCount();
		save_reserve();
		sc.save_screen();
	}
	else
		cout<<"예매 취소하려는 인덱스가 존재하지 않습니다."<<endl;
}

void Theater::addMovie(Movie& movie)	// 영화 예외처리 후 추가
{
	movieAry.push_back(movie);
}

void Theater::addScreen()	// 스크린 추가
{
	string moviename, runningtime, mainactor, screennum, starttime;
	list<Movie>::iterator make;
	int age, movieid, screenid, seatcount, _movieid;

	cout<<"추가할 스크린 정보를 입력하세요."<<endl;
	cout<<"추가할 영화이름을 입력하세요 : "<<endl;
	cin>>moviename;
	if(namecheck(moviename)==true)
	{
		cout<<"상영시간, 관람가능나이, 주연, 영화인덱스를 차례대로 입력하세요."<<endl;
		cin>>runningtime>>age>>mainactor>>movieid;
	}
	else
	{
		cout<<"추가하려는 영화가 이미 있습니다. 다음단계로 넘어갑니다."<<endl;
		make = SearchName(moviename);
		runningtime = make->get_runningTime();
		age = make->get_ageRequire();
		mainactor = make->get_mainActor();
		movieid = make->get_movieId();
		Movie movie(movieid,moviename,runningtime,age,mainactor);
	}
	
	Movie movie(movieid,moviename,runningtime,age,mainactor);
	if(namecheck(moviename)==true)
	{
		addMovie(movie);
		save_movie();
	}
	cout<<"상영관, 시작시간, 좌석개수, 영화아이디, 상영관 인덱스를 차례대로 입력하세요."<<endl;
	cin>>screennum>>starttime>>seatcount>>_movieid>>screenid;
	MovieScreen moviescreen(screenid,screennum,starttime,seatcount,_movieid,movie);
	if(starttime>sc.get_currentTime())
		sc.addScreen(moviescreen);
	else
		cout<<"이미 시작시간이 지났습니다. 추가를 취소합니다."<<endl;
}

void Theater::removeScreen()	// 스크린 삭제
{
	int index;
	print_searchSchedule();
	cout<<endl<<endl;
	cout<<"삭제하고 싶은 Index를 입력해주세요"<<endl;
	cin >> index;
	sc.removeScreen(index);
}

void Theater::print_searchSchedule(/*int type,*/string& m_name)	// 스크린 출력
{
	sc.print_searchSchedule(m_name);
}

void Theater::print_searchSchedule()
{
	sc.print_searchSchedule();
}

void Theater::print_movie()	// 영화 출력
{
	list<Movie>::iterator movie = movieAry.begin();
	list<Movie>::iterator end_movie = --movieAry.end();
	while(movie!=end_movie)
	{
		cout<<movie->get_movieId()<<"  "<<movie->get_movieTitle()<<"  "
			<<movie->get_runningTime()<<"  "<<movie->get_ageRequire()<<"  "
			<<movie->get_mainActor()<<endl;
		movie++;
	}

	if(movie==end_movie)
	{
		cout<<movie->get_movieId()<<"  "<<movie->get_movieTitle()<<"  "
			<<movie->get_runningTime()<<"  "<<movie->get_ageRequire()<<"  "
			<<movie->get_mainActor()<<endl;
	}
}

void Theater::print_reserve()	// 예약목록 전체출력
{
	list<MReserve>::iterator start_reserve=reserveAry.begin();
	list<MReserve>::iterator end_reserve=--reserveAry.end();
	while(start_reserve != end_reserve)
	{
		cout<<start_reserve->user_id <<"    "<<start_reserve->movieTitle<<"    "
			<<start_reserve->screenNum<<"    "<<start_reserve->runningTime<<endl;
		start_reserve++;
	}
	if(start_reserve == end_reserve)
	{
		cout<<start_reserve->user_id <<"    "<<start_reserve->movieTitle<<"    "
			<<start_reserve->screenNum<<"    "<<start_reserve->runningTime<<endl;
		start_reserve++;
	}
}

void Theater::print_userReserve(string user_id)	// 로그인 사용자 예약목록 출력
{
	list<MReserve>::iterator start_reserve=reserveAry.begin();
	list<MReserve>::iterator end_reserve=--reserveAry.end();
	while(start_reserve != end_reserve)
	{
		if(start_reserve->user_id==user_id)
		{
			cout<<start_reserve->index<<"    "<<start_reserve->user_id <<"    "
				<<start_reserve->movieTitle<<"    "<<start_reserve->screenNum<<"    "
				<<start_reserve->runningTime<<endl;
		}
		start_reserve++;
	}
	if(start_reserve == end_reserve)
	{
		if(start_reserve->user_id==user_id)
		{
			cout<<start_reserve->index<<"    "<<start_reserve->user_id <<"    "
				<<start_reserve->movieTitle<<"    "<<start_reserve->screenNum<<"    "
				<<start_reserve->runningTime<<endl;
		}
	}
}

bool Theater::namecheck(string name)	// 영화 있는것인가 체크
{
	list<Movie>::iterator check_start;
	check_start = movieAry.begin();

	while(check_start!=--movieAry.end())
	{
		if(check_start->get_movieTitle() == name)
			return false;
		check_start++;
	}

	if(check_start->get_movieTitle() == name)
		return false;
	return true;
}

list<Movie>::iterator Theater::SearchName(string name)
{
	list<Movie>::iterator check_start;
	check_start = movieAry.begin();

	while(check_start!=--movieAry.end())
	{
		if(check_start->get_movieTitle() == name)
			return check_start;
		check_start++;
	}

	if(check_start->get_movieTitle() == name)
		return check_start;
}