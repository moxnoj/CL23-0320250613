#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"

class Guild {
    std::vector<Player*> members;
public:
    ~Guild();
    void addPlayer(Player* p);
    bool removePlayer(const std::string& name);
    void listPlayers() const;
    void showPlayerDetail(const std::string& name) const;
    
    // 新增功能
    bool isPlayerExists(const std::string& name) const;
    void listPlayersSorted() const;
    void searchPlayers(const std::string& partialName) const;
    int getMemberCount() const;
};
