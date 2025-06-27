#pragma once
#include <string>
#include <iostream>

class Player {
    std::string name;
    int hp, atk, def;
public:
    Player(const std::string& name, int hp, int atk, int def);
    std::string getName() const;
    void printSimple() const;
    void printDetail() const;
    int getHp() const;
    int getAtk() const;
    int getDef() const;
}; 