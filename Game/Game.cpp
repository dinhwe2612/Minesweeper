#include "Game.h"
#include <random>
#include <ctime>

void Game::CreateCells() {
    cell.resize(Nrow + 2, vector<Cell>(Ncol + 2));
    int curNumOfMines = 0;
    for(int i = 1; i <= Nrow; ++i) {
        for(int j = 1; j <= Ncol; ++j) {
            bool BOOM = min(rand() % 2, numOfMines - curNumOfMines);
            cell[i][j].isMine = BOOM;
            curNumOfMines += BOOM;
            cell[i][j].SetIndex(i, j);
            cell[i][j].SetPosition((i - 1) * cell[i][j].sz + sqrtNumOfCells * 0.5f, (j - 1) * cell[i][j].sz + sqrtNumOfCells * 5.7f);
            SetImage(i, j);
        }
    }
}
int Game::CountSurroundedMines(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 8; ++i) {
        int u = x + dx[i], v = y + dy[i];
        cnt += cell[u][v].isMine;
    }
    return cnt;
}
void Game::SetImage(int x, int y) {
    if (cell[x][y].IsMine()) {
        cell[x][y].SetTexture("Images\\Mine.png");
        return;
    }
    switch(CountSurroundedMines(x, y)) {
        case 0:
            cell[x][y].SetTexture("Images\\EmptyCell.png");
            cell[x][y].isEmpty = true;
            break;
        case 1:
            cell[x][y].SetTexture("Images\\One.png");
            break;
        case 2:
            cell[x][y].SetTexture("Images\\Two.png");
            break;
        case 3:
            cell[x][y].SetTexture("Images\\Three.png");
            break;
        case 4:
            cell[x][y].SetTexture("Images\\Four.png");
            break;
        case 5:
            cell[x][y].SetTexture("Images\\Five.png");
            break;
        case 6:
            cell[x][y].SetTexture("Images\\Six.png");
            break;
        case 7:
            cell[x][y].SetTexture("Images\\Seven.png");
            break;
        case 8:
            cell[x][y].SetTexture("Images\\Eighth.png");
            break;
    }
}
//////////////////////////////////////////////////////////
void Game::SetGameWindowParameters(int n)
{
	if (n < 100) {
		sqrtNumOfCells = 10;
		numOfCells = 100;
	}
	else if (n > 400) {
		sqrtNumOfCells = 20;
		numOfCells = 400;
	}
	else {
		sqrtNumOfCells = round(sqrt(n));
		numOfCells = pow(sqrtNumOfCells, 2);
	}

	x = sqrtNumOfCells * 31.f;
	y = sqrtNumOfCells * 36.7f;

	if (numOfMines >= numOfCells) {
		numOfMines  = numOfCells - 1;
	}
	else if (numOfMines <= 0) {
		numOfMines = 1;
	}
}
void Game::StartGameWindow(Window& window, Text start, InputBar cellGrid, InputBar NumberOfMines) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (mousePosition.x >= start.getPosition().x && mousePosition.x <= 210) {
        if (mousePosition.y >= start.getPosition().y && mousePosition.y <= 166) {
            start.setFillColor(Color::Yellow);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                numOfMines = NumberOfMines.GetInput();
                SetGameWindowParameters(cellGrid.GetInput());
                window.close();
//                CreateGameWindow();
            }
        } else {
            start.setFillColor(Color::White);
        }
    }
}
void Game::CreateGameWindow() {
    RenderWindow window(VideoMode(x, y), "Minesweeper", Style::Titlebar | Style::Close);
    Event event;
    Field field(x, y);

    sf::Font font;
	sf::Text win;
	font.loadFromFile("Fonts\\arial.ttf");
	win.setFont(font);
	win.setFillColor(sf::Color::Green);
	win.setString("You Win!");
	win.setCharacterSize(40);
	win.setPosition(x / 2 - 100, y / 2);

	sf::Text lose;
	font.loadFromFile("Fonts\\arial.ttf");
	lose.setFont(font);
	lose.setFillColor(sf::Color::Red);
	lose.setString("You Lose!");
	lose.setCharacterSize(40);
	lose.setPosition(x / 2 - 100, y / 2);

    CreateCells();

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                CreateSettingsWindow();
            }
        }

    }
}
void Game::CreateSettingsWindow() {
    RenderWindow window(VideoMode(310.f, 367.f), "Settings", Style::Titlebar | Style::Close);
    Event event;
    InputBar cellGrid(170, 30, 7.f, 317.f, "cell grid X*X = ");
    InputBar minesNumber(120, 30, 183.f, 317.f, "mines = ");

    Font font;
    Text start;
    font.loadFromFile("Fonts\\arial.ttf");
    start.setFont(font);
    start.setFillColor(Color::White);
    start.setString("Start");
    start.setCharacterSize(60);
    start.setPosition(85.f, 103.f);

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

        window.clear();
        window.draw(cellGrid.GetInputShape());
        window.draw(cellGrid.inputText);
        window.draw(minesNumber.GetInputShape());
        window.draw(minesNumber.GetInputText());
        window.draw(start);
        window.display();
    }
}
