#include "Stats.h"

void Stats::UpdateTimer() {
    seconds += 0.047;
    if (seconds >= 60) {
        ++minutes;
        seconds = 0;
    }
    int s = seconds;
    timerText.setString(to_string(minutes) + ":" + to_string(s));
}

RectangleShape& Stats::GetTimerShape() {
    return timer;
}
RectangleShape& Stats::GetMinesCounterShape() {
    return minesCounter;
}
RectangleShape& Stats::GetStartButtonShape() {
    return startButton;
}
RectangleShape& Stats::GetSaveButtonShape() {
    return saveButton;
}
Text& Stats::GetMinesCounterText() {
    return minesCounterText;
}
Text& Stats::GetTimerText() {
    return timerText;
}
void Stats::SetPosition(float x, float y) {
    startButtonX = (x / 2) - 10.f;
    startButtonY = (y / 17) - 6.f;
    startButton.setPosition(startButtonX, startButtonY);
    saveButtonX = (x / 2) - 60.f;
    saveButtonY = (y / 17) - 6.f;
    saveButton.setPosition(saveButtonX, saveButtonY);
    timer.setPosition((x / 3) - 90.f, (y / 17) - 6.f);
    timerText.setPosition((x / 3) - 80.f, (y / 17) - 6.f);
    minesCounter.setPosition((x / 3) + (x / 3) + 30.f, (y / 17) - 6.f);
    minesCounterText.setPosition((x / 3) + (x / 3) + 50.f, (y / 17) - 6.f);
}
void Stats::UpdateFlags(int numOfFlags) {
    minesCounterText.setString(to_string(startingNumberOfMines - numOfFlags));
}
bool Stats::isClickedOnStart(Window& window) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (startButtonX <= mousePosition.x && mousePosition.x <= startButtonX + sz) {
            if (startButtonY <= mousePosition.y && mousePosition.y <= startButtonY + sz) {
                return true;
            }
        }
    }
    return false;
}
bool Stats::isClickedOnSave(Window& window) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (saveButtonX <= mousePosition.x && mousePosition.x <= saveButtonX + sz) {
            if (saveButtonY <= mousePosition.y && mousePosition.y <= saveButtonY + sz) {
//                cout << "save" << ' ';
                return true;
            }
        }
    }
    return false;
}
void Stats::SaveData() {
    fstream file;
    file.open("Save\\Stats.txt");
    file << minutes << ' ' << seconds;
    file.close();
}
void Stats::LoadData() {
    fstream file;
    file.open("Save\\Stats.txt");
    file >> minutes >> seconds;
    file.close();
}
