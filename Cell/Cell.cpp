#include "Cell.h"

void Cell::SetIndex(int x, int y) {
    idX = x, idY = y;
}
void Cell::SetPosition(int x, int y) {
    shape.setPosition(x, y);
}
RectangleShape& Cell::GetRectangleShape() {
    return shape;
}
pair<int, int> Cell::GetIndex() {
    return {idX, idY};
}
void Cell::SetIsAbleToOpen(bool i) {
    isAbleToOpen = i;
}
void Cell::SetTexture(string path) {
    texture.loadFromFile(path);
}
bool Cell::IsEmpty() {
    return isEmpty;
}
bool Cell::IsAbleToOpen() {
    return isAbleToOpen;
}
bool Cell::IsMine() {
    return isMine;
}
