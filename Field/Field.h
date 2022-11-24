#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Field {
public:
    Field(float x, float y) {
        texture.loadFromFile("Images\\MinesweeperField.png");
        shape.setSize(Vector2f(x, y));
        shape.setPosition(0, 0);
        shape.setTexture(&texture);
    }
    RectangleShape& GetRectangleShape();
};
