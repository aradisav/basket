//============================================================================
// Name        : basket.cpp
// Author      : Alex
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include "PlayerBase.h"

using namespace std;

#define PRICE_PER_GAME 3500;

int main(int argc, char **argv) {

    if (argc != 3) {
        cout << "Usage: basket max_players_per_game " << endl;
        return 1;
    }

    //Load players
    ifstream file;
    file.open("etc/players", ios::in);
    if (!file.is_open()) return 3;

    vector<Player> players;
    string line;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        else {
            players.push_back(Player(line));
        }

    }


    unsigned long num_of_players = players.size();

    long num_of_games = stol(argv[1]);
    long max_players_per_game = stol(argv[2]);

    float total_price_per_month = num_of_games * PRICE_PER_GAME;
    total_price_per_month *= 0.45;

    if (max_players_per_game > num_of_players) max_players_per_game = num_of_players;
    cout << "Players: " << num_of_players << " Games: " << num_of_games
    << " Players per game: " << max_players_per_game << endl;

    long num_of_slots = max_players_per_game * num_of_games;

    double min_games_per_player = floor(num_of_slots / num_of_players);

    double free_slots = num_of_slots - (min_games_per_player * num_of_players);

    cout << "min_games_per_player: " << min_games_per_player << endl;
    cout << "free_slots: " << free_slots << endl;

    // obtain a time-based seed:
    long long int seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(players.begin(), players.end(), std::default_random_engine((unsigned int) seed));

    int w = 0;
    for (int i = 0; i < num_of_slots; i++) {

        if (i % max_players_per_game == 0)
            cout << endl << "WEEK: " << ++w << endl;
        cout << players[i % players.size()].getName() << "\t" << endl;
        auto &player = players[i % players.size()];
        player.setN_games(player.getN_games() + 1);
    }

    cout << endl << "totals" << endl;
    for (auto const &p: players) {
        cout << p.getName() << "\t" << p.getN_games() << " price: " <<
        p.getN_games() * (total_price_per_month / num_of_slots) << endl;
    }


    return 0;

}