#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;


class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        explicit Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        std::string short_color_string() const {
            if (color == Color::WHITE)
                return "w";
            else
                return "b";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Return short version of color and type
        virtual std::string short_type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        explicit King(Color color) : Piece(color) {}

        std::string type() const override {return this->color_string() + " king";}
        std::string short_type() const override {return this->short_color_string() + "KI";}

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return std::abs(from_x - to_x) < 2 && std::abs(from_y - to_y) < 2;
        }
    };

    class Knight : public Piece {
    public:
        explicit Knight(Color color) : Piece(color) {}

        std::string type() const override {return this->color_string() + " knight";}
        std::string short_type() const override {return this->short_color_string() + "KN";}

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return (std::abs(from_x - to_x) == 2 && std::abs(from_y - to_y) == 1) || (std::abs(from_x - to_x) == 1 && std::abs(from_y - to_y) == 2);
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    function<void()> after_piece_move;

    /// Move a chess piece if it is a valid move
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                if (on_piece_move)
                    on_piece_move(*piece_from, from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (on_piece_removed)
                            on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (on_lost_game)
                                on_lost_game(king->color);
                        }
                    } else {
                        if (on_piece_move_invalid)
                            on_piece_move_invalid(*piece_from, from, to);
                        if (after_piece_move) after_piece_move();
                        return false;
                    }
                }
                piece_to = std::move(piece_from);
                if (after_piece_move) after_piece_move();
                return true;
            } else {
                if (on_piece_move_invalid)
                    on_piece_move_invalid(*piece_from, from, to);
                if (after_piece_move) after_piece_move();
                return false;
            }
        } else {
            if (on_piece_move_missing)
                on_piece_move_missing(from);
            if (after_piece_move) after_piece_move();
            return false;
        }
    }
};


