#include <iostream>
#include <vector>
#include <string>

// 玩家类 - 存储玩家的基本信息
class Player {
private:
    std::string name;    // 玩家姓名
    int hp;              // 生命值
    int atk;             // 攻击力
    int def;             // 防御力
    
public:
    // 构造函数 - 初始化玩家属性
    Player(const std::string& name, int hp, int atk, int def);
    
    // 获取玩家姓名
    std::string getName() const;
    
    // 获取玩家生命值
    int getHp() const;
    
    // 获取玩家攻击力
    int getAtk() const;
    
    // 获取玩家防御力
    int getDef() const;
    
    // 显示玩家基本信息
    void printSimple() const;
    
    // 显示玩家详细信息
    void printDetail() const;
    
    // 玩家受到伤害
    void takeDamage(int damage);
    
    // 玩家恢复生命值
    void heal(int amount);
};

// 公会类 - 管理多个玩家
class Guild {
private:
    std::vector<Player*> members;    // 公会成员列表
    std::string guildName;           // 公会名称
    int maxMembers;                  // 最大成员数
    
public:
    // 构造函数 - 初始化公会
    Guild(const std::string& name, int maxSize = 10);
    
    // 析构函数 - 清理内存
    ~Guild();
    
    // 添加新成员到公会
    bool addPlayer(Player* player);
    
    // 从公会移除成员
    bool removePlayer(const std::string& playerName);
    
    // 显示所有公会成员
    void listPlayers() const;
    
    // 显示指定成员的详细信息
    void showPlayerDetail(const std::string& playerName) const;
    
    // 查找公会成员
    Player* findPlayer(const std::string& playerName) const;
    
    // 获取公会成员数量
    int getMemberCount() const;
    
    // 检查公会是否已满
    bool isFull() const;
    
    // 获取公会名称
    std::string getGuildName() const;
};

// 游戏管理器类 - 控制整个游戏流程
class GameManager {
private:
    Guild* currentGuild;             // 当前公会
    bool gameRunning;                // 游戏运行状态
    
public:
    // 构造函数 - 初始化游戏
    GameManager();
    
    // 析构函数 - 清理资源
    ~GameManager();
    
    // 显示主菜单
    void showMainMenu() const;
    
    // 处理用户输入
    void handleUserInput(int choice);
    
    // 添加新成员流程
    void addMemberProcess();
    
    // 移除成员流程
    void removeMemberProcess();
    
    // 显示成员列表流程
    void showMemberListProcess();
    
    // 显示成员详情流程
    void showMemberDetailProcess();
    
    // 运行游戏主循环
    void run();
    
    // 退出游戏
    void exitGame();
};

// 工具函数 - 输入验证
namespace Utils {
    // 验证输入是否为有效数字
    bool isValidNumber(const std::string& input);
    
    // 获取用户输入的数字
    int getValidNumber(const std::string& prompt, int min, int max);
    
    // 获取用户输入的字符串
    std::string getValidString(const std::string& prompt);
    
    // 清屏
    void clearScreen();
    
    // 暂停程序
    void pause();
}

// 主函数 - 程序入口点
int main() {
    // 创建游戏管理器
    GameManager game;
    
    // 运行游戏
    game.run();
    
    return 0;
} 