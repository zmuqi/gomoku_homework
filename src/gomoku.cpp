#include "gomoku.hpp"

Gomoku::Gomoku() {
    reset();
}

void Gomoku::reset() {
    board.assign(SIZE, std::vector<Player>(SIZE, NONE));
    current_player = PLAYER1;
}

bool Gomoku::place(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return false;
    if (board[x][y] != NONE) return false;

    board[x][y] = current_player;
    current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
    return true;
}

bool Gomoku::check_line(int x, int y, int dx, int dy) {
    Player p = board[x][y];
    int count = 1;

    for (int i = 1; i < 5; ++i) {
        int nx = x + dx * i;
        int ny = y + dy * i;
        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
        if (board[nx][ny] == p) count++;
        else break;
    }

    for (int i = 1; i < 5; ++i) {
        int nx = x - dx * i;
        int ny = y - dy * i;
        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
        if (board[nx][ny] == p) count++;
        else break;
    }

    return count >= 5;
}

Player Gomoku::get_winner() {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (board[x][y] == NONE) continue;
            if (check_line(x, y, 1, 0) || check_line(x, y, 0, 1) ||
                check_line(x, y, 1, 1) || check_line(x, y, 1, -1)) {
                return board[x][y];
            }
        }
    }
    return NONE;
}

Player Gomoku::get_cell(int x, int y) const {
    return board[x][y];
}

Player Gomoku::get_current_player() const {
    return current_player;
}

bool Gomoku::is_board_full() const {
    for (auto& row : board)
        for (auto c : row)
            if (c == NONE) return false;
    return true;
}