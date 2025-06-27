#include <iostream>
#include "guild.h"
#include "player.h"

bool isSaved = false;

int main() {
    Guild guild;
    int choice;
    std::cout << "===================\n||   最强的五人  ||\n===================\n";
	std::cout << "===================\n||   ギルド管理  ||\n===================\n";
    std::string name; int hp, atk, def;
    while (true) {
        std::cout << "===================\n||1. メンバー登録||\n||2. メンバー退会||\n||3. メンバー一覧||\n||4. メンバー詳細||\n||5. 終了        ||\n===================\n||選択:          ||\n===================\n";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "1号的名前: ";
            std::cin >> name;
            std::cout << "1号的HP: ";
            std::cin >> hp;
            std::cout << "1号的ATK: ";
            std::cin >> atk;
            std::cout << "1号的DEF: ";
            std::cin >> def;

            std::cout << "请确认输入的信息：" << std::endl;
            std::cout << "名前: " << name << std::endl;
            std::cout << "HP: " << hp << std::endl;
            std::cout << "ATK: " << atk << std::endl;
            std::cout << "DEF: " << def << std::endl;

            int confirm;
            std::cout << "是否确认？\n1.是  2.否  : ";
            std::cin >> confirm;
            if (confirm == 1) {
                isSaved = true;
                guild.addPlayer(new Player(name, hp, atk, def));
                std::cout << "已保存并返回菜单。" << std::endl;
            }
            else {
                isSaved = false;
                std::cout << "未保存，返回菜单。" << std::endl;
            }
        }
        else if (choice == 2) {
            std::string name;
            std::cout << "退会する名前: ";
            std::cin >> name;
            if (!guild.removePlayer(name)) std::cout << "見つかりません\n";
        }
        else if (choice == 3) {
            guild.listPlayers();
        }
        else if (choice == 4) {
            std::string name;
            std::cout << "詳細を見たい名前: ";
            std::cin >> name;
            guild.showPlayerDetail(name);
        }
        else if (choice == 5) {
            break;
        }
    }
    return 0;
} 