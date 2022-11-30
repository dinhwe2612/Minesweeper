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

    int numOfMines, sqrtNumOfCells;
    bool isMineExploded, isGamePaused;
    float max_x, max_y;

    void CreateCells();
    int CountSurroundedMines(int id);
    void SetImage(int id);

    void SetGameWindowParameters(int n);
    void StartGameWindow(Window &window, Text start, InputBar cellGrid, InputBar NumberOfMines);
protected:
    int Nrow, Ncol, numOfCells;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    //012
    //7.3
    //654
    pair<int, int> toCoord(int id);
    int toId(int x, int y);
public:
    Game() {
        isMineExploded = false;
        isGamePaused = false;
    }
    void CreateGameWindow();
    void CreateSettingsWindow();
};
