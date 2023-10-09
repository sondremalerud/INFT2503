#pragma once

#include "ChessBoard.hpp"
using namespace std;

class ChessBoardPrint {
public:
    ChessBoard &board;

    ChessBoardPrint(ChessBoard &board_) : board(board_) {

        board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_lost_game = [](ChessBoard::Color color) {
            if (color == ChessBoard::Color::WHITE)
                cout << "Black";
            else
                cout << "White";
            cout << " won the game" << endl;
        };
        board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_piece_move_missing = [](const string &square) {
            cout << "no piece at " << square << endl;
        };

        board.after_piece_move = [this]() {
            for (auto & square : board.squares)
            {
                for (const auto & j : square)
                {
                    if (!j) cout << "[   ]";
                    else cout << "[" << j->short_type() << "]";
                }
                cout << endl;
            }
        };

    }

};