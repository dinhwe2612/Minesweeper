#pragma once
#include "../Game/Game.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Manipulation : public Game {
private:
    Texture textureFlag, textureUncheckedCell, textureMineExploded;
    int numOfCells, Unchecked = 0, Checked = 1, flagPlaced = 2;
    vector<int> stateOfCells;

    void bfs(Window& window, int id, vector<Cell>& cell);
public:
    Manipulation(int num) {
        numOfCells = num;
        stateOfCells.assign(num, 0);//unchecked
        textureFlag.loadFromFile("Images\\Flag.png");
        textureUncheckedCell.loadFromFile("Images\\UnCheckedCell.png");
        textureMineExploded.loadFromFile("Images\\ExplodedMine.png");
    }
    void LeftClickOnCell(Window& window, vector<Cell>& cell, bool& isMineExploded);
    void RightClickOnCell(Window& window, vector<Cell>& cell);
};
