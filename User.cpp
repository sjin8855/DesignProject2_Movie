#include "User.h"

User::User(void)
{

}

User::~User(void)
{

}

User::User(string _id, string _pw, string _name, int _age)
{
	id = _id;
	password = _pw;
	name = _name;
	age = _age;
}