#include "Manipulation.h"

void Manipulation::bfs(Window& window, int id, vector<Cell>& cell) {
    if (!cell[id].IsEmpty()) {
        window.draw(cell[id].GetRectangleShape());
        return;
    }
}

void Manipulation::LeftClickOnCell(Window& window, vector<Cell>& cell, bool& isMineExploded) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        for(int id = 0; id < numOfCells; ++id) {
            RectangleShape currentCell = cell[id].GetRectangleShape();
            if (mousePosition.x < currentCell.getPosition().x
|| currentCell.getPosition().x + currentCell.getSize().x < mousePosition.x) continue;
            if (mousePosition.y < currentCell.getPosition().y
|| currentCell.getPosition().y + currentCell.getSize().y < mousePosition.y) continue;
            if (stateOfCells[id] != Unchecked) continue;

            if (cell[id].IsMine()) {
                isMineExploded = true;
            } else {
                bfs(window, id, cell);
            }
            break;
        }
    }
}
void Manipulation::RightClickOnCell(Window& window, vector<Cell>& cell) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Right)) {
        for(int id = 0; id < numOfCells; ++id) {
            RectangleShape currentCell = cell[id].GetRectangleShape();
            if (mousePosition.x < currentCell.getPosition().x
|| currentCell.getPosition().x + currentCell.getSize().x < mousePosition.x) continue;
            if (mousePosition.y < currentCell.getPosition().y
|| currentCell.getPosition().y + currentCell.getSize().y < mousePosition.y) continue;
            if (stateOfCells[id] == Checked) continue;

            if (stateOfCells[id] == Unchecked) {
                currentCell.setTexture(&textureFlag);
                stateOfCells[id] = flagPlaced;
            } else {
                currentCell.setTexture(&textureUncheckedCell);
                stateOfCells[id] = Unchecked;
            }
            break;
        }
    }
}
