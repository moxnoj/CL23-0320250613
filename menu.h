#pragma once
#include <iostream>
#include <string>
#include "guild.h"

class Menu {
private:
    Guild& guild;
    
public:
    Menu(Guild& g);
    void showMainMenu() const;
    void handleChoice(int choice);
    void registerPlayer();
    void removePlayer();
    void listPlayers();
    void showPlayerDetail();
    void listPlayersSorted();
    void searchPlayers();
    void showGuildStats();
}; 