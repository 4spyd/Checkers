#pragma once
#include <SFML/Graphics.hpp>
#include "CheckerClass.h"
#include "BoardClass.h"
#include <vector>

void startGame(const CheckersBoard& board, std::vector<Checker>& whiteCheckers, std::vector<Checker>& blackCheckers);

bool isMouseOn(Checker& checker);
