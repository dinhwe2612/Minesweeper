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
void Cell::SetTexture(string path) {
    texture.loadFromFile(path);
}
bool Cell::IsEmpty() {
    return isEmpty;
}
bool Cell::IsOpen() {
    return isOpen;
}
bool Cell::IsMine() {
    return isMine;
}
