#include <SFML\Graphics.hpp>
#include "myVector.h"
using namespace sf;


class Pacman
{
public:
	Pacman(const v2f& vVelocity, const v2f& vPosistion);
	~Pacman();

	void drawTo(RenderWindow &window);

	void move();
	
	void updateSpritePosition();

	Texture texture;
	RectangleShape rect;
	Sprite sprite;

	bool atDestination; 

	v2f velocity;
	v2f position;
	v2f dir;
};

