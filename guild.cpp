#include "guild.h"
#include <iostream>
#include <algorithm>
#include <cctype>

Guild::~Guild() {
    for (auto p : members) delete p;
}

void Guild::addPlayer(Player* p) {
    members.push_back(p);
}

bool Guild::removePlayer(const std::string& name) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if ((*it)->getName() == name) {
            delete* it;
            members.erase(it);
            return true;
        }
    }
    return false;
}

void Guild::listPlayers() const {
    if (members.empty()) {
        std::cout << "                              ";
        std::cout << "ギルドメンバーがいません" << std::endl;
        return;
    }
    
    for (auto p : members) {
        std::cout << "                              ";
        p->printSimple();
    }
}

void Guild::showPlayerDetail(const std::string& name) const {
    for (auto p : members) {
        if (p->getName() == name) {
            std::cout << "                              ";
            p->printDetail();
            return;
        }
    }
    std::cout << "                              ";
    std::cout << "該当者なし" << std::endl;
}

// 新增功能实现
bool Guild::isPlayerExists(const std::string& name) const {
    for (auto p : members) {
        if (p->getName() == name) {
            return true;
        }
    }
    return false;
}

void Guild::listPlayersSorted() const {
    if (members.empty()) {
        std::cout << "                              ";
        std::cout << "ギルドメンバーがいません" << std::endl;
        return;
    }
    
    // 创建临时向量进行排序
    std::vector<Player*> sortedMembers = members;
    
    // 按HP（等级）降序排序
    std::sort(sortedMembers.begin(), sortedMembers.end(), 
        [](const Player* a, const Player* b) {
            return a->getHp() > b->getHp();
        });
    
    std::cout << "                              ";
    std::cout << "=== レベル順メンバー一覧 ===" << std::endl;
    for (auto p : sortedMembers) {
        std::cout << "                              ";
        p->printSimple();
    }
}

void Guild::searchPlayers(const std::string& partialName) const {
    if (members.empty()) {
        std::cout << "                              ";
        std::cout << "ギルドメンバーがいません" << std::endl;
        return;
    }
    
    std::cout << "                              ";
    std::cout << "検索結果: \"" << partialName << "\"" << std::endl;
    
    bool found = false;
    for (auto p : members) {
        std::string playerName = p->getName();
        // 转换为小写进行比较（不区分大小写）
        std::string lowerPlayerName = playerName;
        std::string lowerPartialName = partialName;
        
        std::transform(lowerPlayerName.begin(), lowerPlayerName.end(), 
                      lowerPlayerName.begin(), ::tolower);
        std::transform(lowerPartialName.begin(), lowerPartialName.end(), 
                      lowerPartialName.begin(), ::tolower);
        
        if (lowerPlayerName.find(lowerPartialName) != std::string::npos) {
            std::cout << "                              ";
            p->printDetail();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "                              ";
        std::cout << "該当者なし" << std::endl;
    }
}

int Guild::getMemberCount() const {
    return static_cast<int>(members.size());
}