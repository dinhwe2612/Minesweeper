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
    int numCheckedCell;
    int numOfFlags;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<bool> Flags;
    bool isMineExploded, isGamePaused;
    bool isContinueGame;
    float max_x, max_y;
    int level;

    void CreateCells();
    int CountSurroundedMines(int id);
    void SetImage(int id);
    pair<int, int> toCoord(int id);
    int toId(int x, int y);

    void Win(RenderWindow& window);
    void Lose(RenderWindow& window);

    void SetGameWindowParameters(int n);
    void StartButton(RenderWindow &window, Text& start);
    void ContinueButton(RenderWindow& window, Text& continuee);
    void LeaderBoardButton(RenderWindow& window, Text& Leaderboard);
    void beginnerButton(RenderWindow& window, Text& text);
    void intermediateButton(RenderWindow& window, Text& text);
    void expertButton(RenderWindow& window, Text& text);
    void customButton(RenderWindow& window, Text& text, InputBar cellgrid, InputBar NumberOfMines);
public:
    void init() {
        isMineExploded = false;
        isGamePaused = false;
        numCheckedCell = 0;
        numOfFlags = 0;
        Flags.assign(numOfCells, false);
        IdMineCells.clear();
        cell.clear();
        cellDraw.clear();
        cell.resize(numOfCells);
        cellDraw.resize(numOfCells);
    }
    void CreateGameWindow();
    void CreateStartWindow();
    void CreateSettingsWindow();
    void CreateLeaderBoardWindow();

    void SaveData();
    void LoadData();
    void updateLeaderBoard(pair<int, float> time);
};
