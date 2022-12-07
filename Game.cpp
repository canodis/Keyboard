#include "Game.hpp"
#include <stdlib.h>
#include <fstream>

void	Game::initWords()
{
	std::ifstream	readFile;

	readFile.open("words");
	all_words = (std::string *)malloc(sizeof(std::string) * 5000);
	char	c;
	for (int index; !readFile.eof(); index++)
	{
		readFile >> std::noskipws >> c;
		while (c != '\n')
		{
			all_words[index] += c;
			readFile >> std::noskipws >> c;
		}
	}
}

Game::~Game() { delete all_words; }

void	Game::eventHandler()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code >= 0 && event.key.code <= 25)
			{
				userString += 97 + event.key.code;
				str_index++;
			}
			if (str_index > 0 && event.key.code == 59)
			{
				userString.erase(userString.end() - 1);
				str_index--;
			}
			if (event.key.code == 57 || event.key.code == 58)
			{
				if (mainString.compare(userString) == 0)
					score++;
				scoreText.setString(std::to_string(score));
				userString.erase();
				str_index = 0;
				mainString = all_words[random_range()];
				mainText.setString(mainString);
			} 
			usertext.setString(userString);
			std::cout << mainString.size() << std::endl;
		}
	}
}

void	Game::inputHandler()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();;
}

Game::Game(void)
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "canodis");
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Font load fail !" << std::endl;
	setText(usertext, sf::Vector2f(1, 1), sf::Color::Red, font);
	setText(mainText, sf::Vector2f(2, 2), sf::Color::Blue, font);
	setText(scoreText, sf::Vector2f(0.6f, 0.6f), sf::Color::Yellow, font);
	setRectangle(textArea, WIDTH, HEIGHT, sf::Color::White);
	mainArea.setPosition(WIDTH / 6, HEIGHT / 6);
	mainArea.setFillColor(sf::Color::White);
	mainArea.setSize(sf::Vector2f(WIDTH - (WIDTH / 6) * 2, 250));
	usertext.setPosition(WIDTH / 6 + 25, HEIGHT * 3 / 4 + 25);
	mainText.setPosition(WIDTH / 6 + 25, HEIGHT / 6 + 75);
	scoreText.setPosition(0, 0);
	initWords();
	str_index = 0;
	mainString = all_words[random_range()];
	mainText.setString(mainString);
	scoreText.setString(std::to_string(score));
}

Game::Game(int width, int height, std::string title) : str_index(0)
{
	window.create(sf::VideoMode(width, height), title);
}