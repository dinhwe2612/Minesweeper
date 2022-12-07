#include "Manipulation.h"
#include <windows.h>

pair<int, int> Manipulation::toCoord(int id) {
    return {id / Nrow, id % Ncol};
}
int Manipulation::toId(int x, int y) {
    return x * Nrow + y;
}
void Manipulation::bfs(RenderWindow& window, int id, vector<Cell>& cell, vector<Cell>& cellDraw, int& numCheckedCell) {
    if (stateOfCells[id] == Checked) return;
    stateOfCells[id] = Checked;
    ++numCheckedCell;
//    cout << id << '\n';
    cellDraw[id] = cell[id];
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

            cellDraw[newId] = cell[newId];
            stateOfCells[newId] = Checked;
            ++numCheckedCell;
//            cout << newId << '\n';
            if (cell[newId].IsEmpty()) q.push(newId);
        }
    }
}

void Manipulation::LeftClickOnCell(RenderWindow& window, vector<Cell>& cell, vector<Cell>& cellDraw, bool& isMineExploded, int& numCheckedCell) {
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
                bfs(window, id, cell, cellDraw, numCheckedCell);
            }
            break;
        }
    }
}
void Manipulation::RightClickOnCell(RenderWindow& window, vector<Cell>& cell, vector<Cell>& cellDraw, vector<bool>& Flags, int& numOfFlags) {
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
                cellDraw[id].SetTexture("Images\\Flag.png");
//                cout << "Flag" << '\n';
                stateOfCells[id] = flagPlaced;
                ++numOfFlags;
                Flags[id] = true;
            } else {
//                cout << "UnFlag" << '\n';
                cellDraw[id].SetTexture("Images\\UnCheckedCell.png");
                stateOfCells[id] = Unchecked;
                --numOfFlags;
                Flags[id] = false;
            }
            break;
        }
    }
}
void Manipulation::SaveData() {
    fstream file;
    file.open("Save\\Manipulation.txt");
    for(int id = 0; id < numOfCells; ++id) {
        file << stateOfCells[id] << ' ';
    }
    file.close();
}
void Manipulation::LoadData() {
    fstream file;
    file.open("Save\\Manipulation.txt");
    for(int id = 0; id < numOfCells; ++id) {
        file >> stateOfCells[id];
    }
    file.close();
}
