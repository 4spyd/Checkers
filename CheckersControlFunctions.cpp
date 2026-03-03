#include "CheckersControlFunctions.h"

void startGame(const CheckersBoard& board, std::vector<Checker>& whiteCheckers, std::vector<Checker>& blackCheckers)
{
	float checkerRadius = board.boardMatrix[0][0].cellShape.getSize().x / 2.0f - 4.0f;


	for (int i = 0; i < 2; ++i)
	{
		for (int x = 0; x < 8; x += 2)
		{
			whiteCheckers.push_back(
				Checker(checkerRadius, board.boardMatrix[i][x + i].cellShape.getPosition(), { i, x + i }, sf::Color(117, 142, 217))
			);
			blackCheckers.push_back(
				Checker(checkerRadius, board.boardMatrix[i + 6][x + i].cellShape.getPosition(), { i + 6, x + i }, sf::Color(94, 3, 143))
			);
		}
	}
}

bool isMouseOn(Checker& checker)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	float distance_to_cursour = sf::Vector2f(
		(mousePos.x - checker.circle.getPosition().x), 
		(mousePos.y - checker.circle.getPosition().y)
	).length();

	if (distance_to_cursour < checker.circle.getRadius()) return true;
	return false;
}
