#include <bits/stdc++.h>
#include <random>
#include <ctime>
using namespace std;
#include "Game.h"

void Game::updateBoom(int x, int y) {
    for(int i = 0; i < 8; ++i) {
        ++cntBoom[x + dx[i]][y + dy[i]];
    }
}

void Game::CreateBoard() {
    random_device rd;
    seed_seq seed{rd(), rd(), rd(), rd()};
    mt19937 mt(seed);
    auto rand_range = [&](int l, int r) {
        return mt() % (r - l + 1) + l;
    };

    for(int i = 1; i <= Nrow; ++i) {
        for(int j = 1; j <= Ncol; ++j) {
            if (haveBoom[i][j] = rand_range(0, min(1, Boom))) --Boom, updateBoom(i, j);
        }
    }
}

void Game::bfs0(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while(q.size()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for(int i = 0; i < 8; ++i) {
            int _u = x + dx[i], _v = y + dy[i];
            if (visited[_u][_v]) continue;
            visited[_u][_v] = true;
            if (cntBoom[_u][_v] == 0) q.push({_u, _v});
        }
    }
}
