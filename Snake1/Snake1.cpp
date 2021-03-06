// Snake1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include "Snake.h"
#include"Fruit.h"
#include<iostream>

int main()
{
	sf::Style::Default;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake");
	Snake snake(1);
	Snake snake2(2);
	Fruit fruit;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				snake.setDirection(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				snake.setDirection(2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				snake.setDirection(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				snake.setDirection(4);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				snake2.setDirection(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				snake2.setDirection(2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				snake2.setDirection(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				snake2.setDirection(4);
			}
		}
		snake.move();
		snake2.move();
		if (snake.eatFruit(fruit)||snake2.eatFruit(fruit))
		{
			if (snake.eatFruit(fruit))
				snake.addBody();
			else snake2.addBody();
			fruit.generate();

			while (snake.fruitCollision(fruit)||snake2.fruitCollision(fruit))
				fruit.generate();
		}
		if (snake.hitBody(snake2) || snake.hitWall())
		{
			snake = Snake(1);
			std::cout << "Game Over" << std::endl;
		}
		if (snake2.hitBody(snake) || snake.hitWall())
		{
			snake2 = Snake(2);
			std::cout << "Game Over" << std::endl;
		}
		window.clear();
		snake.draw(window);
		snake2.draw(window);
		fruit.draw(window);
		window.display();
		sf::Time t1 = sf::seconds(1);
		sf::sleep(t1);
	}
	return 0;
}

