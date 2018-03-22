#include "Theater.h"

Theater::Theater(void)
{
	user_count=0;
}

Theater::~Theater(void)
{

}

void Theater::load_user()	// ����� �ε�
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

void Theater::load_movie()	// ��ȭ �ε�
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
void Theater::load_reserve()	// ���Ÿ�� �ε�
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

void Theater::save_movie()	// ��ȭ ����
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

void Theater::save_reserve()	// ���� ����
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

User* Theater::login(string _user_id, string _pass_word)	// �α���
{
	for(int i=0; i<user_count; i++)
	{
		if(userAry[i]->get_userId()==_user_id)
			if(userAry[i]->get_userPw()==_pass_word)
			{
				cout<<"�α��εǾ����ϴ�."<<endl;
				return userAry[i];
			}
	}
	cout<<"�α��ο� �����Ͽ����ϴ�."<<endl;
	return NULL;
}

void Theater::reserveScreen(string user_id, int movie_num, string name)	// ��ȭ����
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
		cout<<"��ȭ���Ű� �Ϸ�Ǿ����ϴ�."<<endl;
		save_reserve();
		movie->set_seatCount();
		sc.save_screen();
		
	}

	else
		cout<<"�ε����� ���� �ùٸ��� �ʽ��ϴ�."<<endl;
}

void Theater::cancelScreen(string user_id, int movie_num)	// �������
{
	list<MReserve>::iterator reserve;
	list<MovieScreen>::iterator movie;
	movie = sc.reserveSchedule(movie_num);
	reserve = reserveAry.begin();
	MReserve cancel;
	cancel.user_id = user_id;
	cancel.index = movie_num;
	bool check = false;	// �ε����� ������ ���� ����
	while(reserve!=reserveAry.end())
	{
		if(reserve->index == cancel.index)
		{
			check = true;	//�ε����� ����.
			break;
		}
		reserve++;
	}
	if(check == true)
	{
		reserveAry.erase(reserve);
		cout<<"���� ����Ͽ����ϴ�."<<endl;
		movie->set_returnCount();
		save_reserve();
		sc.save_screen();
	}
	else
		cout<<"���� ����Ϸ��� �ε����� �������� �ʽ��ϴ�."<<endl;
}

void Theater::addMovie(Movie& movie)	// ��ȭ ����ó�� �� �߰�
{
	movieAry.push_back(movie);
}

void Theater::addScreen()	// ��ũ�� �߰�
{
	string moviename, runningtime, mainactor, screennum, starttime;
	list<Movie>::iterator make;
	int age, movieid, screenid, seatcount, _movieid;

	cout<<"�߰��� ��ũ�� ������ �Է��ϼ���."<<endl;
	cout<<"�߰��� ��ȭ�̸��� �Է��ϼ��� : "<<endl;
	cin>>moviename;
	if(namecheck(moviename)==true)
	{
		cout<<"�󿵽ð�, �������ɳ���, �ֿ�, ��ȭ�ε����� ���ʴ�� �Է��ϼ���."<<endl;
		cin>>runningtime>>age>>mainactor>>movieid;
	}
	else
	{
		cout<<"�߰��Ϸ��� ��ȭ�� �̹� �ֽ��ϴ�. �����ܰ�� �Ѿ�ϴ�."<<endl;
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
	cout<<"�󿵰�, ���۽ð�, �¼�����, ��ȭ���̵�, �󿵰� �ε����� ���ʴ�� �Է��ϼ���."<<endl;
	cin>>screennum>>starttime>>seatcount>>_movieid>>screenid;
	MovieScreen moviescreen(screenid,screennum,starttime,seatcount,_movieid,movie);
	if(starttime>sc.get_currentTime())
		sc.addScreen(moviescreen);
	else
		cout<<"�̹� ���۽ð��� �������ϴ�. �߰��� ����մϴ�."<<endl;
}

void Theater::removeScreen()	// ��ũ�� ����
{
	int index;
	print_searchSchedule();
	cout<<endl<<endl;
	cout<<"�����ϰ� ���� Index�� �Է����ּ���"<<endl;
	cin >> index;
	sc.removeScreen(index);
}

void Theater::print_searchSchedule(/*int type,*/string& m_name)	// ��ũ�� ���
{
	sc.print_searchSchedule(m_name);
}

void Theater::print_searchSchedule()
{
	sc.print_searchSchedule();
}

void Theater::print_movie()	// ��ȭ ���
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

void Theater::print_reserve()	// ������ ��ü���
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

void Theater::print_userReserve(string user_id)	// �α��� ����� ������ ���
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

bool Theater::namecheck(string name)	// ��ȭ �ִ°��ΰ� üũ
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