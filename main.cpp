#include "Game.hpp"

int main()
{
	Game	game;

	while (game.window.isOpen())
	{
		game.eventHandler();
		game.inputHandler();
		game.window.clear(sf::Color(0xAFC1D6FF));
		game.window.draw(game.textArea);
		game.window.draw(game.mainArea);
		game.window.draw(game.usertext);
		game.window.draw(game.mainText);
		game.window.draw(game.scoreText);
		game.window.display();
	}
}