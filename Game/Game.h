#pragma once
#include "../Cell/Cell.h"
#include "../InputBar/InpuBar.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Game {
private:
    vector<Cell> cell;
    vector<Cell> cellDraw;
    vector<int> IdMineCells;
    int numOfCells, numOfMines, sqrtNumOfCells;
    int Nrow, Ncol;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<bool> Flags;
    //012
    //7.3
    //654
    bool isMineExploded, isGamePaused;
    float max_x, max_y;

    void CreateCells();
    int CountSurroundedMines(int id);
    void SetImage(int id);
    pair<int, int> toCoord(int id);
    int toId(int x, int y);

    void Win(RenderWindow& window);
    void Lose(RenderWindow& window);

    void SetGameWindowParameters(int n);
    void StartGameWindow(RenderWindow &window, Text start, InputBar cellGrid, InputBar NumberOfMines);

public:
    Game() {
        isMineExploded = false;
        isGamePaused = false;
    }
    void CreateGameWindow();
    void CreateSettingsWindow();
};
