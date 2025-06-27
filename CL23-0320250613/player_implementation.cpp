#include "example_framework.h"

// 构造函数 - 初始化玩家属性
Player::Player(const std::string& name, int hp, int atk, int def) 
    : name(name), hp(hp), atk(atk), def(def) {
    // 确保属性值在合理范围内
    if (this->hp < 0) this->hp = 0;
    if (this->atk < 0) this->atk = 0;
    if (this->def < 0) this->def = 0;
}

// 获取玩家姓名
std::string Player::getName() const {
    return name;
}

// 获取玩家生命值
int Player::getHp() const {
    return hp;
}

// 获取玩家攻击力
int Player::getAtk() const {
    return atk;
}

// 获取玩家防御力
int Player::getDef() const {
    return def;
}

// 显示玩家基本信息
void Player::printSimple() const {
    std::cout << "名前: " << name << std::endl;
}

// 显示玩家详细信息
void Player::printDetail() const {
    std::cout << "===================" << std::endl;
    std::cout << "名前: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "ATK: " << atk << std::endl;
    std::cout << "DEF: " << def << std::endl;
    std::cout << "===================" << std::endl;
}

// 玩家受到伤害
void Player::takeDamage(int damage) {
    // 计算实际伤害（考虑防御力）
    int actualDamage = damage - def;
    if (actualDamage < 0) actualDamage = 0;
    
    // 减少生命值
    hp -= actualDamage;
    if (hp < 0) hp = 0;
    
    std::cout << name << " 受到了 " << actualDamage << " 点伤害！" << std::endl;
    if (hp == 0) {
        std::cout << name << " 倒下了！" << std::endl;
    }
}

// 玩家恢复生命值
void Player::heal(int amount) {
    if (amount > 0) {
        hp += amount;
        std::cout << name << " 恢复了 " << amount << " 点生命值！" << std::endl;
    }
} 