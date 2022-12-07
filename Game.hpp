#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

# define WIDTH 640
# define HEIGHT 480

class	Game
{
public:
	Game();
	Game(int width, int height, std::string title);
	~Game();
	void	eventHandler();
	void	inputHandler();
	void	initWords();

public:
	sf::RenderWindow	window;
	sf::Text			usertext;
	sf::Text			mainText;
	sf::Text			scoreText;
	sf::RectangleShape	textArea;
	sf::RectangleShape	mainArea;
private:
	std::string			userString;
	std::string			mainString;
	std::string			scoreString;
	std::string			*all_words;
	sf::Event			event;
	sf::Font			font;
	int					str_index;
	int					score;
};

void	setText(sf::Text &text, sf::Vector2f scales, sf::Color color, sf::Font &font);
void	setRectangle(sf::RectangleShape &rs, int width, int height, sf::Color color);
int		random_range();
