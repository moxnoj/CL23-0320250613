#include "player.h"

Player::Player(const std::string& name, int hp, int atk, int def) 
    : name(name), hp(hp), atk(atk), def(def) {
}

std::string Player::getName() const {
    return name;
}

void Player::printSimple() const {
    std::cout << "名前: " << name << std::endl;
}

void Player::printDetail() const {
    std::cout << "===================" << std::endl;
    std::cout << "名前: " << name << std::endl;
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