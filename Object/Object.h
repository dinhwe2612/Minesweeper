#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

struct Cell {
    sf::RectangleShape shape;
	sf::Texture texture;
	virtual sf::RectangleShape& GetRectangleShape() = 0;
    int sz, index;
    bool isMine, isNum, isEmpty;
    Cell() {
		sz = 30;
		index = 0;
		texture.loadFromFile("Images\\UnCheckedCell.png");
		shape.setSize(sf::Vector2f(sz, sz));
		shape.setTexture(&texture);
		isMine = false;
		isNum = false;
		isEmpty = false;
    }
    void SetPosition(int x, int y);
    void SetTexture(string path);
    bool IsEmpty();
    bool IsMine();
};
