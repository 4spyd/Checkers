#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


struct Checker
{
	sf::CircleShape circle;
	sf::Vector2i BoardPosition;
	bool isKing = false;

	Checker(
		float radius = 10.0,
		sf::Vector2f GPos = sf::Vector2f(0.0, 0.0),
		sf::Vector2i BPos = sf::Vector2i(1, 1),
		sf::Color color = sf::Color(255, 0, 0)
	);
};