#include "MovieScreen.h"
MovieScreen::MovieScreen(void)
{

}

MovieScreen::MovieScreen(int id, string num, string time, int count, int m_id, Movie& m_movie)
{
	screenId = id;
	screenNum = num;
	startTime = time;
	seatCount = count;
	movieId = m_id;
	movie = m_movie;
}

MovieScreen::~MovieScreen(void)
{

}