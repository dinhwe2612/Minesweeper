#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Cell {
private:
    RectangleShape shape;
	Texture texture;
    int sz, idX, idY;
    bool isMine, isEmpty, isAbleToOpen;
    void SetIndex(int x, int y);
    void SetPosition(int x, int y);
public:
    Cell() {
        sz = 30;
        texture.loadFromFile("Images\\UnCheckedCell.png");
        shape.setSize(Vector2f(sz, sz));
        shape.setTexture(&texture);
        isMine = false;
        isEmpty = false;
        isAbleToOpen = false;
    }
    RectangleShape& GetRactangleShape();
    pair<int, int> GetIndex();
    void SetIsAbleToOpen(bool i);
	void SetTexture(string path);
	bool IsEmpty();
	bool IsAbleToOpen();
	bool IsMine();
	friend class Game;
};
