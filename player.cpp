#include "player.h"
#include <iostream>

Player::Player(const std::string& name, int hp, int atk, int def, const std::string& job)
    : name(name), hp(hp), atk(atk), def(def), job(job) {
}

std::string Player::getName() const {
    return name;
}

void Player::printSimple() const {
    std::cout << "名前: " << name << " (職業: " << job << ")" << std::endl;
}

void Player::printDetail() const {
    std::cout << "===================" << std::endl;
    std::cout << "名前: " << name << std::endl;
    std::cout << "職業: " << job << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "ATK: " << atk << std::endl;
    std::cout << "DEF: " << def << std::endl;
    std::cout << "===================" << std::endl;
}

int Player::getHp() const {
    return hp;
}

int Player::getAtk() const {
    return atk;
}

int Player::getDef() const {
    return def;
}

std::string Player::getJob() const {
    return job;
}

void Player::setJob(const std::string& newJob) {
    job = newJob;
}