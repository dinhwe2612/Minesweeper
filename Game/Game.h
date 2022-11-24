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
    vector<Cell> init;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    //012
    //7.3
    //654
    int Nrow, Ncol, numOfCells, numOfMines, sqrtNumOfCells;
    bool isMineExploded, isGamePaused;
    float max_x, max_y;

    void CreateCells();
    pair<int, int> toCoord(int id);
    int toId(int x, int y);
    int CountSurroundedMines(int id);
    void SetImage(int id);

    void SetGameWindowParameters(int n);
    void StartGameWindow(Window &window, Text start, InputBar cellGrid, InputBar NumberOfMines);
public:
    Game() {
        isMineExploded = false;
        isGamePaused = false;
    }
    void CreateGameWindow();
    void CreateSettingsWindow();
};
