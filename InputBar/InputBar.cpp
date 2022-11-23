#include "InpuBar.h"

bool InputBar::IsAddedNumberInteger() {
    for(char ch : addedNumber) {
        if (ch < 'A' || ch > 'Z') {
            return false;
        }
    }
    return true;
}
Text& InputBar::GetInputText() {
    return inputText;
}
RectangleShape& InputBar::GetInputShape() {
    return inputShape;
}
int InputBar::GetInput() {
    if (addedNumber.getSize() == 0 || IsAddedNumberInteger() == false) {
        return 1;
    } else {
        string number = addedNumber;
        return stoi(number);
    }
}
void InputBar::MouseOverInputBox(Window& window) {
    Vector2i mousePosition = Mouse::getPosition(window);
    if (mousePosition.x >= inputShape.getPosition().x && mousePosition.x <= inputShape.getPosition().x + szX) {
        if (mousePosition.y >= inputShape.getPosition().y && mousePosition.y <= inputShape.getPosition().y + szY) {
            inputText.setFillColor(Color::Blue);
        }
    } else {
        inputText.setFillColor(Color::Black);
    }
}
void InputBar::SetInputText(Window& window, Event& event) {
    Vector2i mousePosition = Mouse::getPosition(window);
    if (mousePosition.x >= inputShape.getPosition().x && mousePosition.x <= inputShape.getPosition().x + szX) {
        if (mousePosition.y >= inputShape.getPosition().y && mousePosition.y <= inputShape.getPosition().y + szY) {
            input += event.text.unicode;
            addedNumber += event.text.unicode;

            if (addedNumber.getSize() > 3) {
                input = startingInput + event.text.unicode;
                addedNumber = "";
            }
            inputText.setString(input);
        }
    }
}
