#pragma once
#include "../Cell/Cell.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Stats {
private:
    RectangleShape timer, minesCounter, startButton, saveButton;
    Texture textureStartButton, textureSaveButton;
    Text minesCounterText, timerText;
    Font font;
    int startingNumberOfMines;
    int minutes, sz;
    float startButtonX, startButtonY, seconds, saveButtonX, saveButtonY;
public:
    Stats() {
        sz = 30;
        startButtonX = 0;
        startButtonY = 0;
        saveButtonX = 0;
        saveButtonY = 0;

        font.loadFromFile("Fonts\\arial.ttf");

        minesCounter.setSize(Vector2f(2 * sz, sz));
        minesCounter.setFillColor(Color::Black);

        textureStartButton.loadFromFile("Images\\StartButton.png");
        startButton.setSize(Vector2f(sz, sz));
        startButton.setTexture(&textureStartButton);

        textureSaveButton.loadFromFile("Images\\Save.png");
        saveButton.setSize(Vector2f(sz, sz));
        saveButton.setTexture(&textureSaveButton);

        minesCounterText.setFont(font);
        minesCounterText.setCharacterSize(20);
        minesCounterText.setFillColor(Color::Red);

        timerText.setFont(font);
        timerText.setCharacterSize(20);
        timerText.setFillColor(Color::Red);
    }
    void init(int numOfMines) {
        startingNumberOfMines = numOfMines;
        minutes = 0;
        seconds = 0;

        timer.setSize(Vector2f(2 * sz, sz));
        timer.setFillColor(Color::Black);

        minesCounterText.setString(to_string(startingNumberOfMines));

        timerText.setString(to_string(minutes) + ":" + to_string((int)seconds));
    }
    RectangleShape& GetTimerShape();
    RectangleShape& GetMinesCounterShape();
    RectangleShape& GetStartButtonShape();
    RectangleShape& GetSaveButtonShape();
    Text& GetMinesCounterText();
    Text& GetTimerText();
    void SetPosition(float x, float y);
    void UpdateFlags(int numOfFlags);
    void UpdateTimer();
    bool isClickedOnStart(Window& window);
    bool isClickedOnSave(Window& window);

    void SaveData();
    void LoadData();
};
