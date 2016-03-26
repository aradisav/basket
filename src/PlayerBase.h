//
// Created by Aleksandar Radisavljevic on 3/25/16.
//

#ifndef BASKET_PLAYERBASE_H
#define BASKET_PLAYERBASE_H

#include <string>
#include <vector>

class Player {

public:
    Player() : n_games(0) { };

    Player(const Player &p) {
        this->name = p.getName();
        this->n_games = p.getN_games();
    }

    Player(std::string name, int n_games = 0) {
        this->name = name;
        this->n_games = n_games;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Player::name = name;
    }

    int getN_games() const {
        return n_games;
    }

    void setN_games(int n_games) {
        Player::n_games = n_games;
    }

private:
    std::string name;
    int n_games;

};

class PlayerBase {
public:
    int init_players_from_file(std::string file_name);


    void add_player(std::string name);


    std::vector<Player> players;
};


#endif //BASKET_PLAYERBASE_H
