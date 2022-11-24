#pragma once
#include "../Cell/Cell.h"
#include "../InputBar/InpuBar.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Game {
private:
    vector<vector<Cell>> cell;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    //012
    //7.3
    //654
    int Nrow, Ncol, numOfCells, numOfMines, sqrtNumOfCells;
    bool isMineExploded, isGamePaused;
    float x, y;

    void CreateCells();
    int CountSurroundedMines(int x, int y);
    void SetImage(int x, int y);

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
