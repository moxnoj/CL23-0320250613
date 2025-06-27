#include "guild.h"
#include <iostream>
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
    for (auto p : members) p->printSimple();
}
void Guild::showPlayerDetail(const std::string& name) const {
    for (auto p : members) {
        if (p->getName() == name) {
            p->printDetail();
            return;
        }
    }
    std::cout << "見つかりませんでした" << std::endl;
}