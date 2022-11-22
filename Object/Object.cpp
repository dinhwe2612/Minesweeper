#include "Object.h"

void Cell::SetPosition(int x, int y) {
    shape.setPosition(x, y);
}

void Cell::SetTexture(string path) {
    texture.loadFromFile(path);
}

bool Cell::IsEmpty() {
    return isEmpty;
}

bool Cell::IsMine() {
    return isMine;
}
