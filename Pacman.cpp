#include "Pacman.h"


Pacman::Pacman(const v2f& vVelocity, const v2f& vPosition) :
	velocity(vVelocity),
	position(vPosition)
{
	texture.loadFromFile("pacman.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.scale({ 2, 2 });
	rect.setSize({ 32, 32 });
	sprite.setPosition({ vPosition.x, vPosition.y });
	rect.setPosition({ vPosition.x, vPosition.y });
	atDestination = false;
}


Pacman::~Pacman()
{
}

void Pacman::drawTo(RenderWindow &window)
{
	window.draw(sprite);
}

void Pacman::move()
{
	if (!atDestination)
	{
		rect.move(velocity.x, velocity.y);
		position = position + velocity;
	}

}

void Pacman::updateSpritePosition()
{
	sprite.setPosition(rect.getPosition());
}