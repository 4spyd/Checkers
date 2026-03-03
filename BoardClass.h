#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct boardCell
{
	sf::RectangleShape cellShape;
	boardCell(float size = 10.0, sf::Color color = sf::Color::Red);
};

class CheckersBoard
{
	std::vector<sf::Color> cellColors{ sf::Color(8, 13, 115), sf::Color(102, 107, 204) };
public:
	sf::RectangleShape boardBase;
	sf::RectangleShape frameBase;
	std::vector<std::vector<boardCell>> boardMatrix;

	CheckersBoard(sf::RenderWindow& window);

	void drawBoard(sf::RenderWindow& window);
};