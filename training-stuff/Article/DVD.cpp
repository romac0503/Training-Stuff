#include "DVD.h"


DVD::DVD()
{
	_name = "";
	_price = 0;
	_genre.ACTION;
	_articleNumber = 0;
}

void DVD::getGenre() const
{
	if (_genre.ACTION)
		std::cout << "# Genre:\t Action" << std::endl;
	else if (_genre.COMEDY)
		std::cout << "# Genre:\t Comedy" << std::endl;
	else if (_genre.DRAMA)
		std::cout << "# Genre:\t Drama" << std::endl;
	else if (_genre.HORROR)
		std::cout << "# Genre:\t Horror" << std::endl;
	else if (_genre.SIFI)
		std::cout << "# Genre:\t SiFi" << std::endl;
	else if (_genre.WESTERN)
		std::cout << "# Genre:\t Western" << std::endl;
	else
		std::cout << "# No genre set!" << std::endl;
}

void DVD::setGenre(unsigned genre)
{
	_genre.setGenre(genre);
}

void DVD::print() const
{
	Article::print();
	getGenre();
	std::cout << "######################################" << std::endl;
}

void DVD::edit()
{
	Article::edit();
	std::cout << "Do you want to edit the genre of the DVD? j/n?";

	bool tmpChoice = Article::checkAnswer();

	if (tmpChoice)
	{
		std::cout << "Type the number for the genre (Action = 0, Comedy = 1; Drama = 2, Horro = 3, SiFi = 4, Western = 5: \t";
		unsigned tmpGenre = 0;
		std::cin >> tmpGenre;
		setGenre(tmpGenre);
	}
	
}
