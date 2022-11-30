#pragma once
#include "../Game/Game.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Manipulation : public Game {
private:
    Texture FlagCell, UnCheckedCell, MineExplodedCell, NotAMineCell;
    int numOfCells, Unchecked = 0, Checked = 1, flagPlaced = 2;
    vector<int> stateOfCells;


    void bfs(RenderWindow& window, int id, vector<Cell>& cell);
public:
    Manipulation(int num) {
        numOfCells = num;
        cout << num << endl;
        stateOfCells.assign(num, 0);//unchecked
        FlagCell.loadFromFile("Images\\Flag.png");
        UnCheckedCell.loadFromFile("Images\\UnCheckedCell.png");
        MineExplodedCell.loadFromFile("Images\\ExplodedMine.png");
        NotAMineCell.loadFromFile("Images\\NotAMine.png");
    }
    void LeftClickOnCell(RenderWindow& window, vector<Cell>& cell, bool& isMineExploded);
    void RightClickOnCell(RenderWindow& window, vector<Cell>& cell);
};
