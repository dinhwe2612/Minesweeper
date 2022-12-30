#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class InputBar {
public:
    String startingInput, input, addedNumber;
    Text inputText;
    Font font;
    RectangleShape inputShape;
    int szX, szY, coordX, coordY;
    bool IsAddedNumberInteger();
public:
    InputBar(int sX, int sY, int cX, int cY, String in) {
        szX = sX, szY = sY;
        coordX = cX, coordY = cY;
        input = startingInput = in;
        font.loadFromFile("src\\Fonts\\arial.ttf");

        inputShape.setFillColor(Color::White);
        inputShape.setSize(Vector2f(szX, szY));
        inputShape.setPosition(coordX, coordY);

        inputText.setFillColor(Color::Black);
        inputText.setCharacterSize(20);
        inputText.setPosition(coordX, coordY);
        inputText.setString(startingInput);
        inputText.setFont(font);
    }
    Text& GetInputText();
    RectangleShape& GetInputShape();
    int GetInput();
    void MouseOverInputBox(Window& window);
    void SetInputText(Window& window, Event& event);
};
