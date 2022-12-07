#include "Game.h"

void Game::StartButton(RenderWindow& window, Text& start) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (start.getPosition().x <= mousePosition.x && mousePosition.x <= 210) {
        if (start.getPosition().y <= mousePosition.y && mousePosition.y <= 166) {
            start.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close();
                isContinueGame = false;
                CreateLevelWindow();
            }
        } else {
            start.setFillColor(Color::White);
        }
    } else {
        start.setFillColor(Color::White);
    }
}
void Game::ContinueButton(RenderWindow& window, Text& continuee) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (continuee.getPosition().x <= mousePosition.x && mousePosition.x <= 210) {
        if (continuee.getPosition().y <= mousePosition.y && mousePosition.y <= 220) {
            continuee.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                LoadData();
                SetGameWindowParameters(numOfCells);
                window.close();
                isContinueGame = true;
                CreateGameWindow();
            }
        } else {
            continuee.setFillColor(Color::White);
        }
    } else {
        continuee.setFillColor(Color::White);
    }
}
void Game::LeaderBoardButton(RenderWindow& window, Text& Leaderboard) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Leaderboard.getPosition().x <= mousePosition.x && mousePosition.x <= 240) {
        if (Leaderboard.getPosition().y <= mousePosition.y && mousePosition.y <= 260) {
            Leaderboard.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close();
                CreateLeaderBoardWindow();
            }
        } else {
            Leaderboard.setFillColor(Color::White);
        }
    } else {
        Leaderboard.setFillColor(Color::White);
    }
}
void Game::beginnerButton(RenderWindow& window, Text& text) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (text.getPosition().x <= mousePosition.x && mousePosition.x <= 240) {
        if (text.getPosition().y <= mousePosition.y && mousePosition.y <= 120) {
            text.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close();
                level = 1;
                SetGameWindowParameters(100);
                numOfMines = 12;
                CreateGameWindow();
            }
        } else {
            text.setFillColor(Color::Green);
        }
    } else {
        text.setFillColor(Color::Green);
    }
}
void Game::intermediateButton(RenderWindow& window, Text& text) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (text.getPosition().x <= mousePosition.x && mousePosition.x <= 270) {
        if (text.getPosition().y <= mousePosition.y && mousePosition.y <= 180) {
            text.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close();
                level = 2;
                SetGameWindowParameters(225);
                numOfMines = 30;
                CreateGameWindow();
            }
        } else {
            text.setFillColor(Color::Blue);
        }
    } else {
        text.setFillColor(Color::Blue);
    }
}
void Game::expertButton(RenderWindow& window, Text& text) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (text.getPosition().x <= mousePosition.x && mousePosition.x <= 218) {
        if (text.getPosition().y <= mousePosition.y && mousePosition.y <= 232) {
            text.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close();
                level = 3;
                SetGameWindowParameters(400);
                numOfMines = 60;
                CreateGameWindow();
            }
        } else {
            text.setFillColor(Color::Red);
        }
    } else {
        text.setFillColor(Color::Red);
    }
}
void Game::customButton(RenderWindow& window, Text& text, InputBar cellgrid, InputBar NumberOfMines) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (text.getPosition().x <= mousePosition.x && mousePosition.x <= 230) {
        if (text.getPosition().y <= mousePosition.y && mousePosition.y <= 290) {
            text.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close();
                level = 0;
                SetGameWindowParameters(cellgrid.GetInput());
                numOfMines = NumberOfMines.GetInput();
                CreateGameWindow();
            }
        } else {
            text.setFillColor(Color::White);
        }
    } else {
        text.setFillColor(Color::White);
    }
}
