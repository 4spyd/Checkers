#include "CheckerClass.h"

//black checker color: 10, 12, 69
//white checker color: 117, 142, 217

Checker::Checker(float radius, sf::Vector2f GPos, sf::Vector2i BPos, sf::Color color) : BoardPosition(BPos)
{
	if (radius <= 0.0) radius = 10.0;

	this->circle.setOrigin(sf::Vector2f(radius, radius));
	this->circle.setRadius(radius);
	this->circle.setFillColor(color);
	this->circle.setPosition(GPos);
}