#include "MRS.h"

CGV::CGV(void)
{
	th.load_movie();
	th.load_reserve();
	th.load_user();
	current_user = NULL;
}

CGV::~CGV(void)
{

}

void CGV::login(string _user_id, string _password)	// 로그인
{
	th.login(_user_id, _password);
}

void CGV::print_start()		// 프로그램 시작화면
{
	string id, pw, movie_name;
	int input =1;
	int movie_index;
	while(true)
	{
		switch(input)
		{
		case 1 :
			pro.push_back(input);
			vw.print_menu();
			cin >> input;
			system("cls");
			switch(input)
			{
			case 1:
				if(current_user==NULL)	//이미 로그인중인가 확인
				{
					pro.push_back(input);
					vw.print_login();
					cin>>input;

					switch(input)
					{
					case 1:

						cout<<"아이디를 입력해주세요 : ";
						cin>>id;
						cout<<"비밀번호를 입력해주세요 : ";
						cin>>pw;
						if(id!="100")
						{
							current_user = th.login(id,pw);
							if(current_user!=NULL)		//로그인 성공시
							{
								system("pause");
								system("cls");
								vw.print_pmenu();
								cin>>input;
								pro.push_back(input);
								system("cls");
								switch(input)
								{
								case 1:	//영화 예약
									th.print_movie();
									cout<<"예약할 영화이름을 입력하세요 : ";
									cin>>movie_name;
									system("cls");
									th.print_searchSchedule(movie_name);
									cout<<"예약할 영화 인덱스 입력하세요 : ";
									cin>>movie_index;
									th.reserveScreen(current_user->get_userId(), movie_index, movie_name);
									pro.pop_back();
									input = 2;
									break;

								case 2:	//영화 취소
									vw.print_cancelReserve();
									cin >> input;
									pro.push_back(input);
									system("cls");
									switch(input)
									{
									case 1:
										th.print_userReserve(current_user->get_userId());
										cout<<"취소할 영화 인덱스를 입력하세요 : ";
										cin>>movie_index;
										th.cancelScreen(current_user->get_userId(), movie_index);
										pro.pop_back();
										input = 2;
										break;

									case 2:
										pro.pop_back();
										input = 2;
									}
									break;

								case 3:	// 예약리스트 출력
									vw.print_reserveList();
									cin >> input;
									pro.push_back(input);
									system("cls");
									switch(input)
									{
									case 1:
										th.print_userReserve(current_user->get_userId());
										pro.pop_back();
										input = 2;
										break;

									case 2:
										pro.pop_back();
										input = 2;
										break;
									}
									break;

								case 4:	//뒤로 가기
									pro.pop_back();
									input = 1;
									break;

								default:
									cout<<"잘못 입력하였습니다."<<endl;
									pro.pop_back();
									input = 1;
									break;
								}
								break;
							}
							else		// 로그인 실패일 경우
							{
								pro.pop_back();
								input = 1;
							}
						}//로그인 아이디 100일때

						else
						{
							cout<<"관리자 아이디입니다. 관리자로 로그인해주세요."<<endl;
							pro.pop_back();
							input = 1;
							system("pause");
							system("cls");
						}
						break;
						//break;
					case 2:
						cout<<"관리자 아이디를 입력해주세요 : ";
						cin>>id;
						cout<<"비밀번호를 입력해주세요 : ";
						cin>>pw;
						if(id=="100")	//관리자 아이디 : 100
						{
							current_user = th.login(id,pw);
							system("pause");
							system("cls");
							if(current_user!=NULL)	//관리자 로그인 성공
							{
								vw.print_adminMenu();
								cin>>input;
								pro.push_back(input);
								system("cls");
								switch (input)
								{
								case 1:		// 스크린 추가
									vw.print_addScreen();
									cin >> input;
									switch(input)
									{
									case 1:		//스크린추가
										th.addScreen();
										pro.pop_back();
										input = 3;
										break;
									case 2:		//뒤로가기
										pro.pop_back();
										input = 3;
										break;
									}
									break;		//case 1 브레이크

								case 2:		// 스크린 삭제
									vw.print_removeScreen();
									cin >> input;
									system("cls");
									switch(input)
									{
									case 1:	//스크린 삭제
										th.removeScreen();
										pro.pop_back();
										input = 3;
										break;
									case 2:	//뒤로 가기
										pro.pop_back();
										input = 3;
										break;
									}
									break;		//case 2 브레이크

								case 3:		//스크린 현황보기
									vw.print_screenSchedule();
									cin >> input;
									system("cls");
									switch(input)
									{
									case 1:	//스크린 현황보기
										th.print_searchSchedule();
										pro.pop_back();
										input = 3;
										break;

									case 2:
										pro.pop_back();
										input = 3;
										break;
									}

									break;	//case 3 브레이크

								case 4:	//예매현황보기
									vw.print_reserveList();
									cin >> input;
									system("cls");
									switch(input)
									{
									case 1:	//예매현황보기
										th.print_reserve();	//예매목록 전체출력
										pro.pop_back();
										input = 3;
										break;

									case 2: // 뒤로가기
										pro.pop_back();
										input = 3;
										break;
									}
									break; // case 4 브레이크

								case 5: // 뒤로가기
									pro.pop_back();
									input = 1;
									break;//case 5 break;
								}

							}

							else		// 관리자 로그인 실패
							{
								pro.pop_back();
								input = pro.back();
							}
						}
						else	///관리자 아이디가 다를때
						{
							cout<<"관리자 아이디가 일치하지 않습니다."<<endl;
							pro.pop_back();
							input = pro.back();
							system("pause");
							system("cls");
						}

						break;

					case 3:
						pro.pop_back();
						input = 1;
						break;
					}		
				}
				else
				{
					cout<<"이미 로그인 중입니다."<<endl;
					pro.pop_back();
					input = 1;
					system("pause");
					system("cls");
					break;
				}
				break;

			case 2:	//로그아웃 메뉴
				if(current_user !=NULL)
				{	vw.print_logout();
				cin >> input;
				pro.push_back(input);					
				if(input == 1)
				{
					current_user = NULL;
					cout<<"로그아웃 하였습니다."<<endl;
					system("pause");
					system("cls");
				}
				else if(input == 2)
				{
					pro.pop_back();
					input = pro.back();
				}
				else
				{
					cout<<"잘못입력하셨습니다."<<endl;
					pro.pop_back();
					input = pro.back();
					system("pause");
					system("cls");
				}
				}

				else
				{
					cout<<"로그인 중이 아닙니다."<<endl;
					pro.pop_back();
					input = 1;
					system("pause");
					system("cls");
				}

				break;//case 2 로그아웃메뉴 break
			case 3:	//종료 메뉴
				vw.print_close();
				cin >> input;
				pro.push_back(input);
				if(input == 1)
				{
					cout<<"시스템을 종료합니다."<<endl;
					exit(100);
				}
				else if(input == 2)
				{
					pro.pop_back();
					input = pro.back();
				}
				else
				{
					cout<<"잘못입력하셨습니다."<<endl;
					pro.pop_back();
					input = pro.back();
				}
				break;	//case3 / 종료메뉴 break;
			}
			break;	// 전체 case 1 break;
		case 2:	// input 2
			system("pause");
			system("cls");
			vw.print_pmenu();
			cin>>input;
			pro.push_back(input);
			system("cls");
			switch(input)
			{
			case 1:
				th.print_movie();
				cout<<"예약할 영화이름을 입력하세요 : ";
				cin>>movie_name;
				system("cls");
				th.print_searchSchedule(movie_name);
				cout<<"예약할 영화 인덱스 입력하세요 : ";
				cin>>movie_index;
				th.reserveScreen(current_user->get_userId(), movie_index, movie_name);
				pro.pop_back();
				input = 2;
				break;

			case 2:
				pro.push_back(input);
				vw.print_cancelReserve();
				cin >> input;
				pro.push_back(input);
				system("cls");
				switch(input)
				{
				case 1:
					th.print_userReserve(current_user->get_userId());
					cout<<"취소할 영화 인덱스를 입력하세요 : ";
					cin>>movie_index;
					th.cancelScreen(current_user->get_userId(), movie_index);
					pro.pop_back();
					input = 2;
					break;

				case 2:
					pro.pop_back();
					input = 2;
				}
				break;

			case 3:
				vw.print_reserveList();
				cin >> input;
				pro.push_back(input);
				system("cls");
				switch(input)
				{
				case 1:
					th.print_userReserve(current_user->get_userId());
					pro.pop_back();
					input = 2;
					break;

				case 2:
					pro.pop_back();
					input = 2;
					break;
				}
				break;

			case 4:
				pro.pop_back();
				input = 1;
				break;

			default:
				cout<<"잘못 입력하였습니다."<<endl;
				pro.pop_back();
				input = 2;
				break;
			}
			break; // case 2 break;

		case 3:	//input = 3
			system("pause");
			system("cls");
			vw.print_adminMenu();
			cin>>input;
			pro.push_back(input);
			system("cls");
			switch (input)
			{
			case 1:		// 스크린 추가
				vw.print_addScreen();
				cin >> input;
				switch(input)
				{
				case 1:		//스크린추가
					th.addScreen();
					pro.pop_back();
					input = 3;
					break;
				case 2:		//뒤로가기
					pro.pop_back();
					input = 3;
					break;
				}
				break;		//case 1 브레이크

			case 2:		// 스크린 삭제
				vw.print_removeScreen();
				cin >> input;
				system("cls");
				switch(input)
				{
				case 1:	//스크린 삭제
					th.removeScreen();
					pro.pop_back();
					input = 3;
					break;
				case 2:	//뒤로 가기
					pro.pop_back();
					input = 3;
					break;
				}
				break;		//case 2 브레이크

			case 3:		//스크린 현황보기
				vw.print_screenSchedule();
				cin >> input;
				system("cls");
				switch(input)
				{
				case 1:	//스크린 현황보기
					th.print_searchSchedule();
					pro.pop_back();
					input = 3;
					break;

				case 2:
					pro.pop_back();
					input = 3;
					break;
				}

				break;	//case 3 브레이크

			case 4:	//예매현황보기
				vw.print_reserveList();
				cin >> input;
				system("cls");
				switch(input)
				{
				case 1:	//예매현황보기
					th.print_reserve();	//예매목록 전체출력
					pro.pop_back();
					input = 3;
					break;

				case 2: // 뒤로가기
					pro.pop_back();
					input = 3;
					break;
				}
				break; // case 4 브레이크

			case 5: // 뒤로가기
				pro.pop_back();
				input = 1;
				break;//case 5 break;
			}
			break;//case 3 break;
		}
	}
}
void CGV::print_userReserve(string user_id)// 사용자 예약목록 출력
{

}