#include "Game.h"
#include <ctime>
#include <windows.h>

void Game::CreateLevelWindow() {
    Sleep(200);
    RenderWindow window(VideoMode(310.f, 367.f), "Level", Style::Titlebar | Style::Close);
    Event event;
    InputBar cellGrid(170, 30, 7.f, 317.f, "Cell grid X*X = ");
    InputBar minesNumber(120, 30, 183.f, 317.f, "Mines = ");

    Font font;
    font.loadFromFile("src\\Fonts\\arial.ttf");
    Text TextBeginner;
    TextBeginner.setFont(font);
    TextBeginner.setFillColor(Color::Green);
    TextBeginner.setString("Beginner");
    TextBeginner.setCharacterSize(40);
    TextBeginner.setPosition(77, 70);
    Text TextIntermediate;
    TextIntermediate.setFont(font);
    TextIntermediate.setFillColor(Color::Blue);
    TextIntermediate.setString("Intermediate");
    TextIntermediate.setCharacterSize(40);
    TextIntermediate.setPosition(47, 130);
    Text TextExpert;
    TextExpert.setFont(font);
    TextExpert.setFillColor(Color::Red);
    TextExpert.setString("Expert");
    TextExpert.setCharacterSize(40);
    TextExpert.setPosition(93, 190);
    Text custom;
    custom.setFont(font);
    custom.setFillColor(Color::White);
    custom.setString("Custom");
    custom.setCharacterSize(40);
    custom.setPosition(87, 250);

    while(window.isOpen()) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                CreateSettingsWindow();
            }
            if (event.type == Event::TextEntered) {
                cellGrid.SetInputText(window, event);
                minesNumber.SetInputText(window, event);
            }
        }

        cellGrid.MouseOverInputBox(window);
        minesNumber.MouseOverInputBox(window);

        beginnerButton(window, TextBeginner);
        intermediateButton(window, TextIntermediate);
        expertButton(window, TextExpert);
        customButton(window, custom, cellGrid, minesNumber);

        window.clear();

        window.draw(TextBeginner);
        window.draw(TextIntermediate);
        window.draw(TextExpert);
        window.draw(custom);
        window.draw(cellGrid.GetInputShape());
        window.draw(cellGrid.inputText);
        window.draw(minesNumber.GetInputShape());
        window.draw(minesNumber.GetInputText());

        window.display();
    }
}
void PrintScores(RenderWindow& window, int x, string s) {
    Font font;
    Text text;
    font.loadFromFile("src\\Fonts\\arial.ttf");
    text.setFont(font);
    fstream file;
    text.setFillColor(Color::Green);
    text.setString(s);
    text.setCharacterSize(30);
    text.setPosition(x, 0);
    window.draw(text);
    file.open("src\\Save\\" + s + ".txt");
    int numOfScores = 0;
    file >> numOfScores;
    text.setCharacterSize(20);
    text.setFillColor(Color::White);
    for(int i = 0; i < numOfScores; ++i) {
        int minu;
        float sec; file >> minu >> sec;
        int sec2 = round(sec * 100);
        string tmp = to_string(i + 1) + "# ";
        if (minu) tmp += to_string(minu) + "m";
        tmp += " " + to_string(sec2/100) + "." + to_string(sec2%100) + "s";
        text.setString(tmp);
        text.setPosition(x, 10 + (i + 1) * 30);
        window.draw(text);
    }
    file.close();
}
void Game::CreateLeaderBoardWindow() {
    RenderWindow window(VideoMode(600.f, 400.f), "Leaderboard", Style::Titlebar | Style::Close);
    Event event;

    PrintScores(window, 25, "Beginner");
    PrintScores(window, 225, "Intermediate");
    PrintScores(window, 485, "Expert");

    window.display();

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                CreateSettingsWindow();
            }
        }
    }
}
void Game::CreateSettingsWindow() {
    RenderWindow window(VideoMode(310.f, 367.f), "Settings", Style::Titlebar | Style::Close);
    Event event;

    Font font;
    Text start;
    font.loadFromFile("src\\Fonts\\arial.ttf");
    start.setFont(font);
    start.setFillColor(Color::White);
    start.setString("Start");
    start.setCharacterSize(60);
    start.setPosition(85.f, 103.f);

    Text continuee;
    continuee.setFont(font);
    continuee.setFillColor(Color::White);
    continuee.setString("Continue");
    continuee.setCharacterSize(30);
    continuee.setPosition(87.f, 180.f);

    Text Leaderboard;
    Leaderboard.setFont(font);
    Leaderboard.setFillColor(Color::White);
    Leaderboard.setString("Leaderboard");
    Leaderboard.setCharacterSize(28);
    Leaderboard.setPosition(74.f, 223.f);

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        StartButton(window, start);
        ContinueButton(window, continuee);
        LeaderBoardButton(window, Leaderboard);

        window.clear();
        window.draw(start);
        window.draw(continuee);
        window.draw(Leaderboard);
        window.display();
    }
}
