#include "stdafx.h"
#include "Fruit.h"
#include<cstdlib>
#include<ctime>

Fruit::Fruit()
{
	unsigned seed = time(0);
	srand(0);
	x = (rand() % 25 + 1);
	y = (rand() % 25 + 1);
}
void Fruit::draw(sf::RenderWindow &frt)
{
	sf::Texture fTexture;
	fTexture.loadFromFile("apple.png");
	sf::RectangleShape rect(sf::Vector2f(20.0f, 20.0f));
	rect.setTexture(&fTexture);
	rect.setPosition(20*x, 20*y);
	frt.draw(rect);
}
void Fruit::generate()
{
	unsigned seed = time(0);
	srand(0);
	x = (rand() % 25 + 1);
	y = (rand() % 25 + 1);
}

Fruit::~Fruit()
{
}
