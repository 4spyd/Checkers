#include "CheckersControlFunctions.h"
#include "CheckerClass.h"
#include "BoardClass.h"
#include <optional>
#include <thread>
#include <vector>

std::vector<Checker> whiteCheckers;
std::vector<Checker> blackCheckers;

int main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;

	Checker* _draggedChecker = nullptr;
	sf::Vector2f _holdingDistance;

	sf::RenderWindow window;

	window.create(sf::VideoMode::getDesktopMode(), "Checkers", sf::Style::None, sf::State::Fullscreen, settings);
	window.setVerticalSyncEnabled(true);
	
	CheckersBoard Board(window);

	startGame(Board, whiteCheckers, blackCheckers);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			if (auto KeyInput = event->getIf<sf::Event::KeyPressed>())
			{
				if (KeyInput->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}

			if (auto MouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
			{
				if (!_draggedChecker && MouseButtonPressed->button == sf::Mouse::Button::Left)
				{
					for (Checker& checker : whiteCheckers)
					{
						if (isMouseOn(checker))
						{
							_draggedChecker = &checker;
							_holdingDistance = sf::Vector2f(
								sf::Mouse::getPosition().x - checker.circle.getPosition().x,
								sf::Mouse::getPosition().y - checker.circle.getPosition().y
							);

							break;
						}
					}
					for (Checker& checker : blackCheckers)
					{
						if (isMouseOn(checker))
						{
							_draggedChecker = &checker;
							_holdingDistance = sf::Vector2f(
								sf::Mouse::getPosition().x - checker.circle.getPosition().x,
								sf::Mouse::getPosition().y - checker.circle.getPosition().y
							);

							break;
						}
					}
				}
			}

			if (auto MouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
			{
				if (_draggedChecker) {
					_draggedChecker = nullptr;
				}
			}
		}

		if (_draggedChecker)
			_draggedChecker->circle.setPosition(sf::Vector2f(sf::Mouse::getPosition()) - _holdingDistance);

		window.clear(sf::Color(40, 7, 173));

		Board.drawBoard(window);

		for (Checker checker : whiteCheckers)
			window.draw(checker.circle);

		for (Checker checker : blackCheckers)
			window.draw(checker.circle);

		window.display();
	}

	return 0;
}