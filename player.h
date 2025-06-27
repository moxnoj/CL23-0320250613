#pragma once
#include <string>
#include <iostream>

class Player {
    std::string name;
    int hp, atk, def;
    std::string job;
public:
    Player(const std::string& name, int hp, int atk, int def, const std::string& job = "冒険者");
    std::string getName() const;
    void printSimple() const;
    void printDetail() const;
    int getHp() const;
    int getAtk() const;
    int getDef() const;
    std::string getJob() const;
    void setJob(const std::string& newJob);
};