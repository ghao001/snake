#include "stdafx.h"
#include "Snake.h"


Snake::Snake(int player)
{
	if (player == 2)
	{
		x = 10;
		y = 6;
	}
	else
	{
		x = 16;
		y = 16;
	}
	body[0].x = x;
	body[0].y = y;
	direction = 1;
	length = 1;
}
void Snake::move()
{
	for (int i = length - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	switch (direction)
	{
	case 1:
		y--;
		break;
	case 2:
		y++;
		break;
	case 3:
		x++;
		break;
	case 4:
		x--;
		break;
	}
	body[0].x = x;
	body[0].y = y;
}
void Snake::draw(sf::RenderWindow & snk)
{
	sf::RectangleShape rect(sf::Vector2f(20.0f, 20.0f));
	rect.setFillColor(sf::Color::Blue);
	for (int i=0;i<length;i++)
	{
		rect.setPosition(20*body[i].x, 20*body[i].y);
		snk.draw(rect);
	}
}
bool Snake::eatFruit(Fruit & frt)
{
	if (x == frt.getX() && y == frt.getY())
		return true;
	else return false;
}
bool Snake::hitWall()
{
	if (x == -1 || x == 500 || y == -1 || y == 500)
		return true;
	else return false;
}
bool Snake::hitBody(Snake & player2)
{
	for (int i = 2; i < length; i++)
	{
		if (x == body[i].x&&y == body[i].y)
			return true;
	}
	for (int i = 0; i < player2.length; i++)
	{
		if (x == player2.body[i].x&&player2.body[i].y == y)
			return true;
	}
	return false;
}
bool Snake::fruitCollision(Fruit & frt)
{
	for (int i = 0; i < length; i++)
	{
		if (x == frt.getX()&&y == frt.getY())
			return true;
	}
	return false;
}





