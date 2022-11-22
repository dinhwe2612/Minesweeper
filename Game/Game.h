struct Game {
    vector<vector<int>> cntBoom;
    vector<vector<bool>> haveBoom;
    vector<vector<bool>> visited;
    int Boom, Nrow, Ncol;
    bool LOSE;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    Game(int _Nrow, int _Ncol) {
        Nrow = _Nrow;
        Ncol = _Ncol;
        Boom = 2;
        LOSE = false;
        cntBoom.resize(Nrow + 2, vector<int>(Ncol + 2, 0));
        haveBoom.resize(Nrow + 2, vector<bool>(Ncol + 2, false));
        visited.resize(Nrow + 2, vector<bool>(Ncol + 2, false));
    }
    //012
    //7.3
    //654
    void updateBoom(int x, int y);
    void CreateBoard();
    void bfs0(int x, int y);
};
