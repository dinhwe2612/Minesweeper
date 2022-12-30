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
    bool isMine, isEmpty, isOpen;
    void SetIndex(int x, int y);
    void SetPosition(int x, int y);
public:
    Cell() {
        sz = 30;
        texture.loadFromFile("src\\Images\\UnCheckedCell.png");
        shape.setTexture(&texture);
        shape.setSize(Vector2f(sz, sz));
        isMine = false;
        isEmpty = false;
        isOpen = false;
    }
    RectangleShape& GetRectangleShape();
    pair<int, int> GetIndex();
	void SetTexture(string path);
	bool IsEmpty();
	bool IsOpen();
	bool IsMine();
	friend class Game;
};
