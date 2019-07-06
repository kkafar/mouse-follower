#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <conio.h>
#include "myVector.h"
#include "Pacman.h"
#include <time.h>
#include <cmath>
#include <vector>
using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));

	RenderWindow game(VideoMode::getDesktopMode() , "GAME", Style::Default);
	game.setFramerateLimit(60);

	Pacman pac({ 3, 0 }, { 0, 0 });
	vector<Pacman> vPac;
	vPac.push_back(pac);
	v2f mousePosition;

	float x, y;

	while (game.isOpen())
	{
		Event e;

		while (game.pollEvent(e))
		{
			if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				game.close();

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				x = rand() % game.getSize().x;
				y = rand() % game.getSize().y;
				pac.position = { x, y };
				pac.sprite.setPosition({ x, y });
				pac.rect.setPosition({ x, y });
				vPac.push_back(pac);
			}

			if (Mouse::isButtonPressed(Mouse::Right))
				pac.rect.setPosition({ mousePosition.x , mousePosition.y });

			// pobieranie pozycji myszki do wektora własnego typu (z określonymi działaniami na nim)
			mousePosition.x = Mouse::getPosition(game).x;
			mousePosition.y = Mouse::getPosition(game).y;
		}

		//cout << "Pac position: X = " << pac.position.x << " Y = " << pac.position.y << "\n";
		//cout << "Pac velocityV [" << pac.velocity.x << "; " << pac.velocity.y << "]\n";
	
		for (auto i = vPac.begin(); i != vPac.end(); ++i)
		{
			i->dir = mousePosition - i->position;
			i->dir.normalizeVector();
			i->velocity = 5 * i->dir;
			i->move();

			if (mousePosition.x >= i->position.x && mousePosition.x <= (i->position.x + 32) && mousePosition.y >= i->position.y && mousePosition.y <= (i->position.y + 32))
				i->atDestination = true;

			else
				i->atDestination = false;
		}


		for (auto i = vPac.begin(); i != vPac.end(); ++i)
			i->updateSpritePosition();
		
		game.clear();
		
		for (auto i = vPac.begin(); i != vPac.end(); ++i)
			i->drawTo(game);

		game.display();
	}

	_getch();
	

	return 0;
}
