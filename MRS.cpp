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

void CGV::login(string _user_id, string _password)	// �α���
{
	th.login(_user_id, _password);
}

void CGV::print_start()		// ���α׷� ����ȭ��
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
				if(current_user==NULL)	//�̹� �α������ΰ� Ȯ��
				{
					pro.push_back(input);
					vw.print_login();
					cin>>input;

					switch(input)
					{
					case 1:

						cout<<"���̵� �Է����ּ��� : ";
						cin>>id;
						cout<<"��й�ȣ�� �Է����ּ��� : ";
						cin>>pw;
						if(id!="100")
						{
							current_user = th.login(id,pw);
							if(current_user!=NULL)		//�α��� ������
							{
								system("pause");
								system("cls");
								vw.print_pmenu();
								cin>>input;
								pro.push_back(input);
								system("cls");
								switch(input)
								{
								case 1:	//��ȭ ����
									th.print_movie();
									cout<<"������ ��ȭ�̸��� �Է��ϼ��� : ";
									cin>>movie_name;
									system("cls");
									th.print_searchSchedule(movie_name);
									cout<<"������ ��ȭ �ε��� �Է��ϼ��� : ";
									cin>>movie_index;
									th.reserveScreen(current_user->get_userId(), movie_index, movie_name);
									pro.pop_back();
									input = 2;
									break;

								case 2:	//��ȭ ���
									vw.print_cancelReserve();
									cin >> input;
									pro.push_back(input);
									system("cls");
									switch(input)
									{
									case 1:
										th.print_userReserve(current_user->get_userId());
										cout<<"����� ��ȭ �ε����� �Է��ϼ��� : ";
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

								case 3:	// ���ฮ��Ʈ ���
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

								case 4:	//�ڷ� ����
									pro.pop_back();
									input = 1;
									break;

								default:
									cout<<"�߸� �Է��Ͽ����ϴ�."<<endl;
									pro.pop_back();
									input = 1;
									break;
								}
								break;
							}
							else		// �α��� ������ ���
							{
								pro.pop_back();
								input = 1;
							}
						}//�α��� ���̵� 100�϶�

						else
						{
							cout<<"������ ���̵��Դϴ�. �����ڷ� �α������ּ���."<<endl;
							pro.pop_back();
							input = 1;
							system("pause");
							system("cls");
						}
						break;
						//break;
					case 2:
						cout<<"������ ���̵� �Է����ּ��� : ";
						cin>>id;
						cout<<"��й�ȣ�� �Է����ּ��� : ";
						cin>>pw;
						if(id=="100")	//������ ���̵� : 100
						{
							current_user = th.login(id,pw);
							system("pause");
							system("cls");
							if(current_user!=NULL)	//������ �α��� ����
							{
								vw.print_adminMenu();
								cin>>input;
								pro.push_back(input);
								system("cls");
								switch (input)
								{
								case 1:		// ��ũ�� �߰�
									vw.print_addScreen();
									cin >> input;
									switch(input)
									{
									case 1:		//��ũ���߰�
										th.addScreen();
										pro.pop_back();
										input = 3;
										break;
									case 2:		//�ڷΰ���
										pro.pop_back();
										input = 3;
										break;
									}
									break;		//case 1 �극��ũ

								case 2:		// ��ũ�� ����
									vw.print_removeScreen();
									cin >> input;
									system("cls");
									switch(input)
									{
									case 1:	//��ũ�� ����
										th.removeScreen();
										pro.pop_back();
										input = 3;
										break;
									case 2:	//�ڷ� ����
										pro.pop_back();
										input = 3;
										break;
									}
									break;		//case 2 �극��ũ

								case 3:		//��ũ�� ��Ȳ����
									vw.print_screenSchedule();
									cin >> input;
									system("cls");
									switch(input)
									{
									case 1:	//��ũ�� ��Ȳ����
										th.print_searchSchedule();
										pro.pop_back();
										input = 3;
										break;

									case 2:
										pro.pop_back();
										input = 3;
										break;
									}

									break;	//case 3 �극��ũ

								case 4:	//������Ȳ����
									vw.print_reserveList();
									cin >> input;
									system("cls");
									switch(input)
									{
									case 1:	//������Ȳ����
										th.print_reserve();	//���Ÿ�� ��ü���
										pro.pop_back();
										input = 3;
										break;

									case 2: // �ڷΰ���
										pro.pop_back();
										input = 3;
										break;
									}
									break; // case 4 �극��ũ

								case 5: // �ڷΰ���
									pro.pop_back();
									input = 1;
									break;//case 5 break;
								}

							}

							else		// ������ �α��� ����
							{
								pro.pop_back();
								input = pro.back();
							}
						}
						else	///������ ���̵� �ٸ���
						{
							cout<<"������ ���̵� ��ġ���� �ʽ��ϴ�."<<endl;
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
					cout<<"�̹� �α��� ���Դϴ�."<<endl;
					pro.pop_back();
					input = 1;
					system("pause");
					system("cls");
					break;
				}
				break;

			case 2:	//�α׾ƿ� �޴�
				if(current_user !=NULL)
				{	vw.print_logout();
				cin >> input;
				pro.push_back(input);					
				if(input == 1)
				{
					current_user = NULL;
					cout<<"�α׾ƿ� �Ͽ����ϴ�."<<endl;
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
					cout<<"�߸��Է��ϼ̽��ϴ�."<<endl;
					pro.pop_back();
					input = pro.back();
					system("pause");
					system("cls");
				}
				}

				else
				{
					cout<<"�α��� ���� �ƴմϴ�."<<endl;
					pro.pop_back();
					input = 1;
					system("pause");
					system("cls");
				}

				break;//case 2 �α׾ƿ��޴� break
			case 3:	//���� �޴�
				vw.print_close();
				cin >> input;
				pro.push_back(input);
				if(input == 1)
				{
					cout<<"�ý����� �����մϴ�."<<endl;
					exit(100);
				}
				else if(input == 2)
				{
					pro.pop_back();
					input = pro.back();
				}
				else
				{
					cout<<"�߸��Է��ϼ̽��ϴ�."<<endl;
					pro.pop_back();
					input = pro.back();
				}
				break;	//case3 / ����޴� break;
			}
			break;	// ��ü case 1 break;
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
				cout<<"������ ��ȭ�̸��� �Է��ϼ��� : ";
				cin>>movie_name;
				system("cls");
				th.print_searchSchedule(movie_name);
				cout<<"������ ��ȭ �ε��� �Է��ϼ��� : ";
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
					cout<<"����� ��ȭ �ε����� �Է��ϼ��� : ";
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
				cout<<"�߸� �Է��Ͽ����ϴ�."<<endl;
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
			case 1:		// ��ũ�� �߰�
				vw.print_addScreen();
				cin >> input;
				switch(input)
				{
				case 1:		//��ũ���߰�
					th.addScreen();
					pro.pop_back();
					input = 3;
					break;
				case 2:		//�ڷΰ���
					pro.pop_back();
					input = 3;
					break;
				}
				break;		//case 1 �극��ũ

			case 2:		// ��ũ�� ����
				vw.print_removeScreen();
				cin >> input;
				system("cls");
				switch(input)
				{
				case 1:	//��ũ�� ����
					th.removeScreen();
					pro.pop_back();
					input = 3;
					break;
				case 2:	//�ڷ� ����
					pro.pop_back();
					input = 3;
					break;
				}
				break;		//case 2 �극��ũ

			case 3:		//��ũ�� ��Ȳ����
				vw.print_screenSchedule();
				cin >> input;
				system("cls");
				switch(input)
				{
				case 1:	//��ũ�� ��Ȳ����
					th.print_searchSchedule();
					pro.pop_back();
					input = 3;
					break;

				case 2:
					pro.pop_back();
					input = 3;
					break;
				}

				break;	//case 3 �극��ũ

			case 4:	//������Ȳ����
				vw.print_reserveList();
				cin >> input;
				system("cls");
				switch(input)
				{
				case 1:	//������Ȳ����
					th.print_reserve();	//���Ÿ�� ��ü���
					pro.pop_back();
					input = 3;
					break;

				case 2: // �ڷΰ���
					pro.pop_back();
					input = 3;
					break;
				}
				break; // case 4 �극��ũ

			case 5: // �ڷΰ���
				pro.pop_back();
				input = 1;
				break;//case 5 break;
			}
			break;//case 3 break;
		}
	}
}
void CGV::print_userReserve(string user_id)// ����� ������ ���
{

}