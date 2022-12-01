#include "Game.h"

void Game::StartGameWindow(RenderWindow& window, Text& start, InputBar cellGrid, InputBar NumberOfMines) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (start.getPosition().x <= mousePosition.x && mousePosition.x <= 210) {
        if (start.getPosition().y <= mousePosition.y && mousePosition.y <= 166) {
            start.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                numOfMines = NumberOfMines.GetInput();
                SetGameWindowParameters(cellGrid.GetInput());
                window.close();
                CreateGameWindow();
            }
        } else {
            start.setFillColor(Color::White);
        }
    } else {
        start.setFillColor(Color::White);
    }
}
void Game::ContinueGameWindow(RenderWindow& window, Text& continuee) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (continuee.getPosition().x <= mousePosition.x && mousePosition.x <= 210) {
        if (continuee.getPosition().y <= mousePosition.y && mousePosition.y <= 220) {
            continuee.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
//                if (GetPreviousGame() == true) {
//                    CreateGameWindow();
//                } else {
//
//                }
            }
        } else {
            continuee.setFillColor(Color::White);
        }
    } else {
        continuee.setFillColor(Color::White);
    }
}
void Game::CreateSettingsWindow() {
    RenderWindow window(VideoMode(310.f, 367.f), "Settings", Style::Titlebar | Style::Close);
    Event event;
    InputBar cellGrid(170, 30, 7.f, 317.f, "Cell grid X*X = ");
    InputBar minesNumber(120, 30, 183.f, 317.f, "Mines = ");

    Font font;
    Text start;
    font.loadFromFile("Fonts\\arial.ttf");
    start.setFont(font);
    start.setFillColor(Color::White);
    start.setString("Start");
    start.setCharacterSize(60);
    start.setPosition(85.f, 103.f);

    Text continuee;
    continuee.setFont(font);
    start.setFillColor(Color::White);
    continuee.setString("Continue");
    continuee.setCharacterSize(30);
    continuee.setPosition(85.f, 183.f);

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::TextEntered) {
                cellGrid.SetInputText(window, event);
                minesNumber.SetInputText(window, event);
            }
        }
        cellGrid.MouseOverInputBox(window);
        minesNumber.MouseOverInputBox(window);
        StartGameWindow(window, start, cellGrid, minesNumber);
        ContinueGameWindow(window, continuee);

        window.clear();
        window.draw(cellGrid.GetInputShape());
        window.draw(cellGrid.inputText);
        window.draw(minesNumber.GetInputShape());
        window.draw(minesNumber.GetInputText());
        window.draw(start);
        window.draw(continuee);
        window.display();
    }
}
