#include <SFML/Graphics.hpp>
#include <sys/time.h>

void	setText(sf::Text &text, sf::Vector2f scales, sf::Color color, sf::Font &font)
{
	text.setFont(font);
	text.setScale(scales);
	text.setFillColor(color);
}

void	setRectangle(sf::RectangleShape &rs, int width, int height, sf::Color color)
{
	rs.setPosition(width / 6, height * 3 / 4);
	rs.setFillColor(sf::Color::White);
	rs.setSize(sf::Vector2f(width - (width / 6) * 2, 100));
}

int	random_range()
{
	struct timeval t;
	gettimeofday(&t, 0);
	srand(t.tv_sec + t.tv_usec);
	return (rand() % 4999);
}