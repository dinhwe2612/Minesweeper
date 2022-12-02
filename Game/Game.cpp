#include "Game.h"
#include "../Field/Field.h"
#include "../Manipulation/Manipulation.h"
#include "../Stats/Stats.h"
#include <random>
#include <ctime>
#include <windows.h>

void Game::CreateCells() {
    init();
    //for random
    vector<int> Ids;
    for(int id = 0; id < numOfCells; ++id) Ids.push_back(id);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(Ids.begin(), Ids.end(), rng);
    for(int i = 0; i < numOfMines; ++i) IdMineCells.push_back(Ids[i]);
    cout << "Mines: ";
    for(int i = 0; i < numOfMines; ++i) {
        int id = IdMineCells[i];
        cell[id].isMine = true;
        cout << id << ' ';
    }
    cout << '\n';
    //
    for(int id = 0, i = 0, j = 0; id < numOfCells; ++id) {
        SetImage(id);

        cellDraw[id].SetPosition(i * cellDraw[id].sz + sqrtNumOfCells * 0.5f, j * cellDraw[id].sz + sqrtNumOfCells * 5.7f);
        cell[id].SetPosition(i * cell[id].sz + sqrtNumOfCells * 0.5f, j * cell[id].sz + sqrtNumOfCells * 5.7f);

        if (++i == sqrtNumOfCells) {
            i = 0;
            ++j;
        }
    }
    for(int id = 0, i = 0, j = 0; id < numOfCells; ++id) {
        cout << CountSurroundedMines(id) << ' ';

        if (++i == sqrtNumOfCells) {
            i = 0;
            ++j;cout << '\n';
        }
    }
}
pair<int, int> Game::toCoord(int id) {
    return {id / Nrow, id % Ncol};
}
int Game::toId(int x, int y) {
    return x * Nrow + y;
}
int Game::CountSurroundedMines(int id) {
    int cnt = 0;
    int x, y; tie(x, y) = toCoord(id);

    for(int i = 0; i < 8; ++i) {
        int u = x + dx[i], v = y + dy[i];

        if (u < 0 || v < 0 || u >= Nrow || v >= Ncol) continue;

        int near_id = toId(u, v);
        cnt += cell[near_id].isMine;
    }
    return cnt;
}
void Game::SetImage(int id) {
    cellDraw[id].SetTexture("Images\\UnCheckedCell.png");
    if (cell[id].IsMine()) {
        cell[id].SetTexture("Images\\Mine.png");
        return;
    }
    switch(CountSurroundedMines(id)) {
        case 0:
            cell[id].SetTexture("Images\\EmptyCell.png");
            cell[id].isEmpty = true;
            break;
        case 1:
            cell[id].SetTexture("Images\\One.png");
            break;
        case 2:
            cell[id].SetTexture("Images\\Two.png");
            break;
        case 3:
            cell[id].SetTexture("Images\\Three.png");
            break;
        case 4:
            cell[id].SetTexture("Images\\Four.png");
            break;
        case 5:
            cell[id].SetTexture("Images\\Five.png");
            break;
        case 6:
            cell[id].SetTexture("Images\\Six.png");
            break;
        case 7:
            cell[id].SetTexture("Images\\Seven.png");
            break;
        case 8:
            cell[id].SetTexture("Images\\Eighth.png");
            break;
    }
}
//////////////////////////////////////////////////////////
void Game::SetGameWindowParameters(int n) {
	if (n < 100) {
		sqrtNumOfCells = 10;
		numOfCells = 100;
		Nrow = sqrtNumOfCells, Ncol = sqrtNumOfCells;
	}
	else if (n > 400) {
		sqrtNumOfCells = 20;
		numOfCells = 400;
		Nrow = sqrtNumOfCells, Ncol = sqrtNumOfCells;
	}
	else {
		sqrtNumOfCells = round(sqrt(n));
		numOfCells = pow(sqrtNumOfCells, 2);
		Nrow = sqrtNumOfCells, Ncol = sqrtNumOfCells;
	}

	max_x = sqrtNumOfCells * 31.f;
	max_y = sqrtNumOfCells * 36.7f;

	if (numOfMines >= numOfCells) {
		numOfMines  = numOfCells - 1;
	}
	else if (numOfMines <= 0) {
		numOfMines = 1;
	}
	cout << max_x << ' ' << max_y << ' ' << sqrtNumOfCells << ' ' << numOfCells << ' ' << numOfMines << '\n';
}
void Game::CreateGameWindow() {
    Sleep(80);
    RenderWindow window(VideoMode(max_x, max_y), "Minesweeper", Style::Titlebar | Style::Close);
    Event event;
    Field field(max_x, max_y);

    Manipulation Player;
    Player.init(numOfCells, Nrow, Ncol);

    Stats gameStats;
    gameStats.init(numOfMines);
    gameStats.SetPosition(max_x, max_y);

    if (isContinueGame == true) {
        LoadData();
        gameStats.LoadData();
        Player.LoadData();
    } else CreateCells();

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                CLOSE:
                window.close();
                CreateSettingsWindow();
            }
        }

        if (isGamePaused == false) {
            Player.LeftClickOnCell(window, cell, cellDraw, isMineExploded, numCheckedCell);
            Player.RightClickOnCell(window, cell, cellDraw, Flags, numOfFlags);
            Sleep(44);
            gameStats.UpdateFlags(numOfFlags);
            gameStats.UpdateTimer();
            cout << numCheckedCell << '\n';
        }

        if (gameStats.isClickedOnStart(window) == true) {
            CreateCells();

            gameStats.init(numOfMines);
            Player.init(numOfCells, Nrow, Ncol);
        }

        if (isGamePaused == false && gameStats.isClickedOnSave(window) == true) {
            SaveData();
            Player.SaveData();
            gameStats.SaveData();
            cout << "YES" << endl;
            goto CLOSE;
        }

        window.clear();
        window.draw(field.GetRectangleShape());

        for(int id = 0; id < numOfCells; ++id) {
            window.draw(cellDraw[id].GetRectangleShape());
        }

        if (isMineExploded == true) {
            Lose(window);
        }

        if (numCheckedCell + numOfMines == numOfCells) {
            Win(window);
        }

        window.draw(gameStats.GetStartButtonShape());
        window.draw(gameStats.GetSaveButtonShape());
		window.draw(gameStats.GetMinesCounterShape());
		window.draw(gameStats.GetTimerShape());
		window.draw(gameStats.GetMinesCounterText());
		window.draw(gameStats.GetTimerText());

        window.display();
    }
}

void Game::Win(RenderWindow& window) {
    Font font;
	Text win;
	font.loadFromFile("Fonts\\arial.ttf");
	win.setFont(font);
	win.setFillColor(Color::Green);
	win.setString("You Win!");
	win.setCharacterSize(40);
	win.setPosition(max_x / 2 - 82, max_y / 2 - 30);

    window.draw(win);
    isGamePaused = true;
}

void Game::Lose(RenderWindow& window) {
    Font font;
    Text lose;
	font.loadFromFile("Fonts\\arial.ttf");
	lose.setFont(font);
	lose.setFillColor(Color::Red);
	lose.setString("You Lose!");
	lose.setCharacterSize(40);
	lose.setPosition(max_x / 2 - 82, max_y / 2 - 30);

    for(int id = 0; id < numOfCells; ++id) {
        if (Flags[id] == true) {
            if (cell[id].IsMine() == true) {
                cellDraw[id].SetTexture("Images\\Mine.png");
            } else {
                cellDraw[id].SetTexture("Images\\NotAMine.png");
            }
        } else if (cell[id].IsMine() == true) {
            cellDraw[id].SetTexture("Images\\ExplodedMine.png");
        }
        window.draw(cellDraw[id].GetRectangleShape());
    }

    window.draw(lose);
    isGamePaused = true;
}

void Game::SaveData() {
    fstream fout;
    fout.open("Save\\Game.txt");

    fout << numOfCells << ' ' << numOfMines << ' ' << sqrtNumOfCells << ' ' << Nrow << ' ' << Ncol << '\n';
    fout << numCheckedCell << ' ' << numOfFlags << '\n';
    for(int id : IdMineCells) fout << id << ' ';fout << '\n';
    for(int id = 0; id < numOfCells; ++id) fout << Flags[id] << ' ';fout << '\n';

    fout.close();
}
void Game::LoadData() {
    fstream fin;
    fin.open("Save\\Game.txt");

    fin >> numOfCells >> numOfMines >> sqrtNumOfCells >> Nrow >> Ncol;
    init();
    fin >> numCheckedCell >> numOfFlags;
    for(int i = 0; i < numOfMines; ++i) {
        int id; fin >> id;
        IdMineCells.push_back(id);
        cell[id].isMine = true;
    }
    fin.close();

    fin.open("Save\\Manipulation.txt");
    for(int id = 0, i = 0, j = 0; id < numOfCells; ++id) {
        SetImage(id);

        int st; fin >> st;
        if (st == 0) cellDraw[id].SetTexture("Images\\UnCheckedCell.png");
        else if (st == 1) cellDraw[id] = cell[id];
        else cellDraw[id].SetTexture("Images\\Flag.png");

        cellDraw[id].SetPosition(i * cellDraw[id].sz + sqrtNumOfCells * 0.5f, j * cellDraw[id].sz + sqrtNumOfCells * 5.7f);
        cell[id].SetPosition(i * cell[id].sz + sqrtNumOfCells * 0.5f, j * cell[id].sz + sqrtNumOfCells * 5.7f);

        if (++i == sqrtNumOfCells) {
            i = 0;
            ++j;
        }
    }
    fin.close();
}
