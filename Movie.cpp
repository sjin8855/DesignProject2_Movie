#include "Movie.h"

Movie::Movie(void)
{
	
}

Movie::Movie(int id, string title, string time, int age, string actor)
{
	movieId= id;
	movieTitle = title;
	runningTime = time;
	ageRequire = age;
	mainActor = actor;
}

Movie::~Movie(void)
{

}