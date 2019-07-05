#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <conio.h>
#include "myVector.h"
#include "Pacman.h"
#include <cmath>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow game(VideoMode(800, 600), "GAME", Style::Default);
	game.setFramerateLimit(60);

	Pacman pac({ 3, 0 }, { 0, 0 });

	v2f dir, mousePosition;

	while (game.isOpen())
	{
		Event e;

		while (game.pollEvent(e))
		{
			if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				game.close();

			if (Mouse::isButtonPressed(Mouse::Left))
				pac.atDestination = true;

			if (Mouse::isButtonPressed(Mouse::Right))
				pac.rect.setPosition({ mousePosition.x , mousePosition.y });

			// pobieranie pozycji myszki do wektora w³asnego typu (z okreœlonymi dzia³aniami na nim)
			mousePosition.x = Mouse::getPosition(game).x;
			mousePosition.y = Mouse::getPosition(game).y;
		}

		//cout << "Pac position: X = " << pac.position.x << " Y = " << pac.position.y << "\n";
		//cout << "Pac velocityV [" << pac.velocity.x << "; " << pac.velocity.y << "]\n";
	
		dir = mousePosition - pac.position;

		dir.normalizeVector();
		pac.velocity = 3 * dir;

		pac.move();

		if (mousePosition.x >= pac.position.x && mousePosition.x <= (pac.position.x + 32) && mousePosition.y >= pac.position.y && mousePosition.y <= (pac.position.y + 32))
			pac.atDestination = true;

		else
			pac.atDestination = false;

		pac.updateSpritePosition();
		game.clear();
		pac.drawTo(game);
		game.display();
	}

	_getch();

	return 0;
}