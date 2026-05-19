#ifndef GOMOKU_HPP
#define GOMOKU_HPP

#include <vector>

enum Player { NONE, PLAYER1, PLAYER2 };

class Gomoku {
private:
    static const int SIZE = 15;
    std::vector<std::vector<Player>> board;
    Player current_player;

    bool check_line(int x, int y, int dx, int dy);

public:
    Gomoku();
    void reset();
    bool place(int x, int y);
    Player get_winner();
    Player get_cell(int x, int y) const;
    Player get_current_player() const;
    bool is_board_full() const;
};

#endif