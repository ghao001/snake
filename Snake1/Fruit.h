#ifndef FRUIT_H
#define FRUIT_H

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<cstdlib>
#include<ctime>
class Fruit
{
private:
	int x;
	int y;
public:
	Fruit();
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void draw(sf::RenderWindow &);
	void generate();
	~Fruit();
};
#endif // !FRUIT_H
