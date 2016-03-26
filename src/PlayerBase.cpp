//
// Created by Aleksandar Radisavljevic on 3/25/16.
//
#include "PlayerBase.h"
#include <fstream>


void PlayerBase::add_player(std::string name) {
    auto p = new Player(name);
    players.push_back(*p);
}

int PlayerBase::init_players_from_file(std::string file_name) {
    //Load players
    std::ifstream file;
    file.open(file_name, std::ios::in);
    if (!file.is_open()) return 3;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        else {
            add_player(line);
        }

    }
    return 0;
}