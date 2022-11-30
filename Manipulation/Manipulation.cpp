#include "Manipulation.h"
#include <windows.h>

void Manipulation::bfs(RenderWindow& window, int id, vector<Cell>& cell) {
    window.draw(cell[id].GetRectangleShape());
    if (!cell[id].IsEmpty()) return;
    queue<int> q;
    q.push(id);
    while(q.size()) {
        int curId = q.front();
        q.pop();
        int curX, curY; tie(curX, curY) = toCoord(curId);
        for(int i = 0; i < 8; ++i) {
            int newX = curX + dx[i], newY = curY + dy[i];
            int newId = toId(newX, newY);

            if (newX < 0 || newY < 0 || newX >= Nrow || newY >= Ncol) continue;
            if (cell[newId].IsMine() || stateOfCells[newId] == Checked || stateOfCells[newId] == flagPlaced) continue;

            window.draw(cell[newId].GetRectangleShape());
            if (cell[newId].IsEmpty()) q.push(newId);
        }
    }
}

void Manipulation::LeftClickOnCell(RenderWindow& window, vector<Cell>& cell, bool& isMineExploded) {
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
void Manipulation::RightClickOnCell(RenderWindow& window, vector<Cell>& cell) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Right)) {
        int cnt = 0;
        for(int id = 0; id < numOfCells; ++id) {
            RectangleShape& currentCell = cell[id].GetRectangleShape();
            if (mousePosition.x < currentCell.getPosition().x
|| currentCell.getPosition().x + currentCell.getSize().x < mousePosition.x) continue;
            if (mousePosition.y < currentCell.getPosition().y
|| currentCell.getPosition().y + currentCell.getSize().y < mousePosition.y) continue;
            if (stateOfCells[id] == Checked) continue;
            ++cnt;
            if (stateOfCells[id] == Unchecked) {
                cell[id].SetTexture("Images\\Flag.png");
                cout << "Flag" << '\n';
                stateOfCells[id] = flagPlaced;
            } else {
                cout << "UnFlag" << '\n';
                cell[id].SetTexture("Images\\UnCheckedCell.png");
                stateOfCells[id] = Unchecked;
            }
            break;
        }
    }
}
