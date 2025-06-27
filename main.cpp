#include <iostream>
#include "guild.h"
#include "menu.h"

int main() {
    Guild guild;
    Menu menu(guild);
    int choice;
    
    std::cout << "                              ";
    std::cout << "=== ギルガメッシュの酒場へようこそ！ ===" << std::endl;
    std::cout << "                              ";
    std::cout << "妖精の尾ギルド管理システム" << std::endl;
    std::cout << "                              ";
    std::cout << "=====================================" << std::endl;
    
    while (true) {
        menu.showMainMenu();
        std::cin >> choice;
        
        if (choice == 8) {
            break;
        }
        
        menu.handleChoice(choice);
        
        // 按任意键继续
        std::cout << "                              ";
        std::cout << "続行するにはEnterキーを押してください...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        
        // 清屏（Windows）
        system("cls");
    }
    
    std::cout << "                              ";
    std::cout << "ギルガメッシュの酒場を利用していただき、ありがとうございました！" << std::endl;
    return 0;
}