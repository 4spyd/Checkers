#include "BoardClass.h"


CheckersBoard::CheckersBoard(sf::RenderWindow& window)
{
	float side_size = window.getSize().y - (2 * window.getSize().y / 11);
	float cellSize = side_size / 9.0;
	this->boardBase.setSize({ side_size, side_size });
	this->boardBase.setFillColor(sf::Color(24, 2, 79));
	this->boardBase.setPosition({ (window.getSize().x - side_size) / 2, (window.getSize().y - side_size) / 2 });

	this->frameBase.setSize({ side_size - cellSize + 10.0f, side_size - cellSize + 10.0f });
	this->frameBase.setFillColor(sf::Color(167, 145, 255));
	this->frameBase.setPosition({ boardBase.getPosition().x + (cellSize / 2 - 5), boardBase.getPosition().y + (cellSize / 2 - 5) });
	
	this->boardMatrix.resize(8);
		
	for (int i = 0; i < 64; i++)
	{
		this->boardMatrix[i / 8].push_back(boardCell(cellSize, cellColors[(i + i / 8) % 2]));
		this->boardMatrix[i / 8][i % 8].cellShape.setOrigin({ cellSize / 2, cellSize / 2 });
		this->boardMatrix[i / 8][i % 8].cellShape.setPosition({ 
			cellSize * (i % 8) + cellSize + boardBase.getPosition().x, 
			cellSize * (1 % 8) * (i / 8) + cellSize + boardBase.getPosition().y });
	}
}

void CheckersBoard::drawBoard(sf::RenderWindow& window)
{
	window.draw(boardBase);
	window.draw(frameBase);
	for (std::vector<boardCell> line : boardMatrix)
	{
		for (boardCell cell : line)
		{
			window.draw(cell.cellShape);
		}
	}
}

boardCell::boardCell(float size, sf::Color color)
{
	this->cellShape.setFillColor(color);
	this->cellShape.setSize({ size, size });
	this->cellShape.setOrigin({ size / 2.0f, size / 2.0f });
}

