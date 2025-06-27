#include "menu.h"
#include "player.h"
#include <iostream>
#include <limits>

Menu::Menu(Guild& g) : guild(g) {}

void Menu::showMainMenu() const {
    std::cout << "===================\n||   fairy tail  ||\n===================\n";
    std::cout << "===================\n||   ギルド管理  ||\n===================\n";
    std::cout << "===================\n||1. メンバー登録||\n||2. メンバー退会||\n||3. メンバー一覧||\n||4. メンバー詳細||\n||5. レベル順一覧||\n||6. メンバー検索||\n||7. ギルド統計  ||\n||8. 終了        ||\n===================\n||選択:          ||\n===================\n";
}

void Menu::handleChoice(int choice) {
    switch (choice) {
        case 1:
            registerPlayer();
            break;
        case 2:
            removePlayer();
            break;
        case 3:
            listPlayers();
            break;
        case 4:
            showPlayerDetail();
            break;
        case 5:
            listPlayersSorted();
            break;
        case 6:
            searchPlayers();
            break;
        case 7:
            showGuildStats();
            break;
        case 8:
            std::cout << "                              ";
            std::cout << "プログラムを終了します。" << std::endl;
            break;
        default:
            std::cout << "                              ";
            std::cout << "無効な選択です。1-8の数字を入力してください。" << std::endl;
            break;
    }
}

void Menu::registerPlayer() {
    std::string name, job;
    int hp, atk, def;
    
    std::cout << "                              ";
    std::cout << "=== メンバー登録 ===" << std::endl;
    std::cout << "                              ";
    std::cout << "名前を入力してください: ";
    std::cin >> name;
    
    // 检查是否已存在同名玩家
    if (guild.isPlayerExists(name)) {
        std::cout << "                              ";
        std::cout << "警告: 同名のプレイヤーが既に存在します！" << std::endl;
        std::cout << "                              ";
        std::cout << "登録を続行しますか？(1: はい / 2: いいえ): ";
        int confirm;
        std::cin >> confirm;
        if (confirm != 1) {
            std::cout << "                              ";
            std::cout << "登録をキャンセルしました。" << std::endl;
            return;
        }
    }
    
    // 职业选择
    std::cout << "                              ";
    std::cout << "職業を選択してください:" << std::endl;
    std::cout << "                              ";
    std::cout << "1. 戦士  2. 魔法使い  3. 弓使い  4. 盗賊  5. その他" << std::endl;
    std::cout << "                              ";
    std::cout << "選択 (1-5): ";
    int jobChoice;
    std::cin >> jobChoice;
    
    switch (jobChoice) {
        case 1: job = "戦士"; break;
        case 2: job = "魔法使い"; break;
        case 3: job = "弓使い"; break;
        case 4: job = "盗賊"; break;
        case 5: 
            std::cout << "                              ";
            std::cout << "職業名を入力してください: ";
            std::cin >> job;
            break;
        default: 
            job = "冒険者";
            std::cout << "                              ";
            std::cout << "デフォルト職業「冒険者」に設定しました。" << std::endl;
            break;
    }
    
    std::cout << "                              ";
    std::cout << "HPを入力してください: ";
    std::cin >> hp;
    
    // 输入验证
    if (hp <= 0) {
        std::cout << "                              ";
        std::cout << "エラー: HPは正の数である必要があります。" << std::endl;
        return;
    }
    
    std::cout << "                              ";
    std::cout << "ATKを入力してください: ";
    std::cin >> atk;
    
    if (atk < 0) {
        std::cout << "                              ";
        std::cout << "エラー: ATKは0以上の数である必要があります。" << std::endl;
        return;
    }
    
    std::cout << "                              ";
    std::cout << "DEFを入力してください: ";
    std::cin >> def;
    
    if (def < 0) {
        std::cout << "                              ";
        std::cout << "エラー: DEFは0以上の数である必要があります。" << std::endl;
        return;
    }

    std::cout << "                              ";
    std::cout << "=== 登録情報確認 ===" << std::endl;
    std::cout << "                              ";
    std::cout << "名前: " << name << std::endl;
    std::cout << "                              ";
    std::cout << "職業: " << job << std::endl;
    std::cout << "                              ";
    std::cout << "HP: " << hp << std::endl;
    std::cout << "                              ";
    std::cout << "ATK: " << atk << std::endl;
    std::cout << "                              ";
    std::cout << "DEF: " << def << std::endl;

    int confirm;
    std::cout << "                              ";
    std::cout << "登録を確定しますか？(1: はい / 2: いいえ): ";
    std::cin >> confirm;
    
    if (confirm == 1) {
        guild.addPlayer(new Player(name, hp, atk, def, job));
        std::cout << "                              ";
        std::cout << "メンバー登録が完了しました！" << std::endl;
    } else {
        std::cout << "                              ";
        std::cout << "登録をキャンセルしました。" << std::endl;
    }
}

void Menu::removePlayer() {
    std::string name;
    std::cout << "                              ";
    std::cout << "=== メンバー退会 ===" << std::endl;
    std::cout << "                              ";
    std::cout << "退会するメンバーの名前を入力してください: ";
    std::cin >> name;
    
    if (guild.removePlayer(name)) {
        std::cout << "                              ";
        std::cout << "メンバー退会が完了しました。" << std::endl;
    } else {
        std::cout << "                              ";
        std::cout << "該当者なし" << std::endl;
    }
}

void Menu::listPlayers() {
    std::cout << "                              ";
    std::cout << "=== メンバー一覧 ===" << std::endl;
    guild.listPlayers();
}

void Menu::showPlayerDetail() {
    std::string name;
    std::cout << "                              ";
    std::cout << "=== メンバー詳細 ===" << std::endl;
    std::cout << "                              ";
    std::cout << "詳細を表示するメンバーの名前を入力してください: ";
    std::cin >> name;
    guild.showPlayerDetail(name);
}

void Menu::listPlayersSorted() {
    std::cout << "                              ";
    std::cout << "=== レベル順メンバー一覧 ===" << std::endl;
    guild.listPlayersSorted();
}

void Menu::searchPlayers() {
    std::string partialName;
    std::cout << "                              ";
    std::cout << "=== メンバー検索 ===" << std::endl;
    std::cout << "                              ";
    std::cout << "検索する名前の一部を入力してください: ";
    std::cin >> partialName;
    guild.searchPlayers(partialName);
}

void Menu::showGuildStats() {
    std::cout << "                              ";
    std::cout << "=== ギルド統計 ===" << std::endl;
    std::cout << "                              ";
    std::cout << "総メンバー数: " << guild.getMemberCount() << "人" << std::endl;
    
    if (guild.getMemberCount() > 0) {
        std::cout << "                              ";
        std::cout << "ギルドは活発です！" << std::endl;
    } else {
        std::cout << "                              ";
        std::cout << "ギルドは空です。新しいメンバーを募集しましょう！" << std::endl;
    }
} 