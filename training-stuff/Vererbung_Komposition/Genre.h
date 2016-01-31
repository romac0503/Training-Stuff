#pragma once

#include <iostream>

class Genre
{
public:
	enum Genres { ACTION = 0, WESTERN = 1, DRAMA = 2, COMEDY = 3, SIFI = 4, HORROR = 5 };
	Genres _genre;

	Genre(){}
	Genre(Genres genre) :_genre(genre){}

	void setGenre(unsigned int n)
	{
		switch (n)
		{
		case 0:
			_genre = Genres::ACTION;
			break;
		case 1:
			_genre = Genres::COMEDY;
			break;
		case 2:
			_genre = Genres::DRAMA;
			break;
		case 3:
			_genre = Genres::HORROR;
			break;
		case 4:
			_genre = Genres::SIFI;
			break;
		case 5:
			_genre = Genres::WESTERN;
			break;
		default:
			_genre = Genres::ACTION;
			break;
		}
	}

};