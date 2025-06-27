#pragma once
#include <vector>
#include <string>
#include "player.h"
class Guild {
    std::vector<Player*> members;
public:
    ~Guild();
    void addPlayer(Player* p);
    bool removePlayer(const std::string& name);
    void listPlayers() const;
    void showPlayerDetail(const std::string& name) const;
};
