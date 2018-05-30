#ifndef SNAKE_H
#define SNAKE_H
#include "Fruit.h"
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

struct posi
{
	int x;
	int y;
};
class Snake
{
private:
	posi body[400];
	int x;
	int y;
	int direction;
	int length;
public:
	Snake(int);
	void move();
	void setDirection(int d)
	{
		direction = d;
	}
	void draw(sf::RenderWindow &);
	void addBody()
	{
		length++;
	}
	bool eatFruit(Fruit &);
	bool hitWall();
	bool hitBody(Snake &);
	bool fruitCollision(Fruit &);
	~Snake() {}

};

#endif // !SNAKE_H