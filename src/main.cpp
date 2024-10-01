#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>


std::ofstream record;

enum winOrLose
{
    PLAYER_WIN,
    DRAW,
    PLAYER_LOSE   
};

enum Shots
{
    THREE_POINT_SHOT = 1,
    MEDIUM_SHOT,
    LAY_UP_SHOT,
    COMBINATIONT_SHOT,
    RULES_SHOT,
    DIRTY_SHOT,
    HAND_GOD_SHOT
};

enum defense
{
    CHOICE_DEFENSE,
    PRESSING,
    PERSONAL_DEFENSE,
    ZONE_DEFENSE,
    NONE_DEFENSE,
    RULES_DEFENSE
};

enum playerHints
{
    EXPERT = 1,
    AMATEUR,
    NOOB
};

enum spirit
{
    MAX_SPIRIT = 10,
    MIN_SPIRIT = -10,
    DIRTY_SPIRIT = -10,
    GOD_SPIRIT = 10,
    MORE_POINT = 5,
};

enum posessionBall
{
    PLAYER_BALL = 1,
    OPPONENT_BALL,
    PROCENT_BALL_PLAYER = 40

};

enum situationShow
{
    FIRST_STORY = 1,
    SECOND_STORY,
    THIRD_STORY
};

enum testing
{
    TEST = 1,
    UNTEST
};

namespace test
{
    bool testingEnabled{};
    const std::string TESTING_ENABLED = "����� ������������ �������!\n";
    const std::string CHOICE_TEAM_SPIRIT = "\n�������� ����:\n�������� ������� ���������� ���� �� -10 �� 10: ";
    const std::string CHOICE_SCENE = "�������� ���� ���� ��� ����� ������� �� 1 �� 3.\n��� ����� �����: ";
    const std::string NONE_SCENE = "������� � ���� ��� ��� ����!\n";
    const std::string TEST_THREE_PRESSING = "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_THREE_PERSONAL_DEFENSE = "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"������ �����\" - (+15%)\n3.��������� ��� ";
    const std::string TEST_THREE_ZONE_DEFENSE = "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"������ ������\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_THREE_NONE_DEFENSE = "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"��� ������\" - (+20%)\n3.��������� ��� ";
    const std::string TEST_MEDIUM_PRESSING = "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_MEDIUM_PERSONAL_DEFENSE = "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"������ �����\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_MEDIUM_ZONE_DEFENSE = "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"������ ������\" - (+15%)\n3.��������� ��� ";
    const std::string TEST_MEDIUM_NONE_DEFENSE = "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"��� ������\" - (+20%)\n3.��������� ��� ";
    const std::string TEST_LAY_UP_PRESSING = "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_LAY_UP_PERSONAL_DEFENSE = "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"������ �����\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_LAY_UP_ZONE_DEFENSE = "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"������ ������\" - (+15%)\n3.��������� ��� ";
    const std::string TEST_LAY_UP_NONE_DEFENSE = "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"��� ������\" - (+20%)\n3.��������� ��� ";
    const std::string TEST_COMBINATION_PRESSING = "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_COMBINATION_PERSONAL_DEFENSE = "�������� ��������� : \n1.������� ���� - 55 % .\n2.������ \"������ �����\" - (+15%)\n3.��������� ��� ";
    const std::string TEST_COMBINATION_ZONE_DEFENSE = "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"������ ������\" - (-10%)\n3.��������� ��� ";
    const std::string TEST_COMBINATION_NONE_DEFENSE = "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"���� ������\" - (+20%)\n3.��������� ��� ";
    const std::string TEST_DIRTY = "�������� ���������:\n����������� ��������� 70%\n";
    const std::string TEST_HAND_GOD = "�������� ���������:\n����������� ��������� 100%\n";
}

namespace menu
{
    int startGame{};
    int jump{};
    int hint{};
    const int RULES_GAME{ 1 };
    const int TOURNAMENT{ 3 };
    const int AUTHOR_GAME{ 4 };
    const int EXIT_GAME{ 5 };
    std::string rules{};
    std::string rulesShot{};
    std::string rulesDefense{};
    const std::string CHOICE_MENU = "�������� ������� ������� ����:\n1.�������� �����.\n2.����� ������������.\n��� �����: ";
    const std::string REPEAT = "�� �������!\n��� �����: ";
    const std::string OPPONENT_NAME_CHOICE = "������� ������� Enter, ��� ������������ �������� ���������� ���\n������� �������� ������� ����������: ";
    const std::string START_DEFENSE = "����� ��������� ������� �����...";
    const std::string WIN_BALL_JUMP = "����� ����������� ��� ����� � ����������� ����� �...\n����������� ���������� �������: ";
    const std::string TIMEOUT = "\n������ �������, ������ ������� ����� �� �������!\n��������� ����� ��������� �����!\n\n";
    const std::string SECOND_TIME = "���������� ������ ����! �������!!!\n\n";
    const std::string FINAL = "��������� ������� ����� �������! ����� ���� �������!\n��������� ���� �� �����:\n";
    const std::string HOORAY = "����������� � ������� ������� ";
    const std::string DRAW = "������� ���������� �� �������, �� � ��������� ��� ������� ����������!\n\n";
    const std::string WELCOME = "����� ���������� � ���� \"���������\"\n";
    const std::string START_MENU = "1. ������� ����.\n2. ������ ����.\n3. ����� �������.\n4. �� ������.\n5. ����� �� ����.\n\n��� ����������� �������� ��������: ";
    const std::string CHOICE_HINT = "�������� ����� ���������:\n1.�������(��� ���������).\n2.��������(��������� ���������� �� ������� �������)\n3.�������(��������� ��������� ������)\n\n��� �����: ";
    const std::string AUTHOR = "������ ���������� ��� Dialas ������������.\n�����: ���������� ����(���: mee1b).\n������: 1.0.8.\n\n";
    const std::string TABLO = "����: ";
}

namespace engine
{
    const int ATTACK_TIME{ 24 };
    const int THREE_POINT{ 3 };
    const int TWO_POINT{ 2 };
    const int FREE_THROW_POINT{ 1 };
    const int THREE_POINT_AND_PRESSING{ 70 };
    const int THREE_POINT_AND_PERSONAL_DEFENSE{ 55 };
    const int THREE_POINT_AND_ZONE_DEFENSE{ 80 };
    const int THREE_POINT_AND_NONE_DEFENSE{ 50 };
    const int MEDIUM_SHOT_AND_PRESSING{ 60 };
    const int MEDIUM_SHOT_AND_PERSONAL_DEFENSE{ 70 };
    const int MEDIUM_SHOT_AND_ZONE_DEFENSE{ 40 };
    const int MEDIUM_SHOT_AND_NONE_DEFENSE{ 40 };
    const int LAY_UP_AND_PRESSING{ 50 };
    const int LAY_UP_AND_PERSONAL_DEFENSE{ 60 };
    const int LAY_UP_AND_ZONE_DEFENSE{ 30 };
    const int LAY_UP_AND_NONE_DEFENSE{ 30 };
    const int COMBINATION_AND_PRESSING{ 65 };
    const int COMBINATION_AND_PERSONAL_DEFENSE{ 45 };
    const int COMBINATION_AND_ZONE_DEFENSE{ 70 };
    const int COMBINATION_AND_NONE_DEFENSE{ 40 };
    const int PROCENT_REBOUND{ 90 };
    const int PERIOD_FINISH{ 240 };
    const int PERIOD_START{ 0 };
    const int GOOD_STEAL_OPPONENT_ON_PLAYER{ 80 };
    const int GOOD_BLOCK_OPPONENT_ON_PLAYER{ 75 };
    const int SWITCH_DEFENSE{ 1 };
    const int ZERO{ 0 };
    const int ONE_UP{ 1 };
    int allTeamTournament{ 8 };
    int probalityJump{};
    int probalityRebound{};
    int period{};
    int userChoice{};
    int howGame{ 1 };
    int resoultTournament{};
    int countPersonalDefense{};
    int countZoneDefense{};
    const int ALL_TOURNAMENT_GAME{ 3 };
    const int MAX_DRAW{ 2 };
    std::string userText{};
    const std::string EMPTY_STRING = "";
    const char COMMENT_CHAR = '*';
    const std::string USER_HISTORY_FILE = "text_game.txt";
}

namespace history
{
    const int PROBALITY_WIN{ 50 }; // 50% ���� ������ � �������
    const int ADD_SPIRIT_VICTORY{ 10 };
    const int REM_SPIRIT_FAIL{ -10 };
    const int NONE_RISC_SPIRIT{ -5 };
    const std::string YOUR_TEAM_SPIRIT = "\n��� ��������� ��� ����� ";
    const std::string STANDART_OPPONENT_NAME = "������� ��������";
    const std::string PLAYER_TEAM_NAME = "������� �������";
}

namespace attack
{
    const std::string SHOT_CHOICE = "�������! ����� ������ ������ � ���� �����? ";
    const std::string SHOT_CHOICE_AND_HINT = "�������! ����� ������ ������ � ���� �����?(����� ���������� ���� ������� ������� 5): ";
    const std::string SUPERPOWER_HINT = "���� ��������� ��� ����� -10 ��� ������:\n6.������� ����(��� ����, ���� 10 � ���������� ����).\n���� ��������� ��� ����� 10 ��� ������:\n7.���� ����(��� ����, ���� 10 � ���������� ����).\n\n";
    const std::string UNKNOW_TACTICS = "�� ����������� �� �� ��������� ����� ������, �������!\n����� ������� ��, ��� �� ��� �����!\n";
    const std::string OPEN_DIRTY = "6. ��� ��������� ��� ������, ������ ����� \"������� ����\".\n";
    const std::string OPEN_HAND = "7. ��� ��������� ��� �� �������, ������ ����� \"���� ����\".\n";
    const std::string THREE_POINT = "����������� ������!!!\n";
    const std::string ADD_THREE = "��� ���� � �������!!!\n";
    const std::string LOSE_SHOT = "������! ��� � �������, ��� �� �� ���������?\n";
    const std::string MEDIUM_SHOT = "������� ������!!!\n";
    const std::string ADD_TWO = "��� ���� � �������!!!\n";
    const std::string LAY_UP = "��� �� ��� - ���!!!\n";
    const std::string COMBINATION = "��������, ������ ����������� ����������!!!\n";
    const std::string ADD_HAND = "����� ���������� ������!!!\n�� ������, � ����������.\n��� ���� � �������!\n\n";
    const std::string RESET_HAND = "��� ��� ������������ ������!\n�� ������ �� ����� ����� ��� � �������, ����� ��������� ������� ������� ����� ���������!\n\n";
    const std::string ADD_DIRTY = "��� �� ���!!!\n�� ����� ������ �� �����.\n��� ���� � �������!\n\n";
    const std::string FAIL_DIRTY = "��� �� ���!!!\n����� ��������� �������� ������ � ������ ������� ";
    const std::string REALESE_DIRTY_PENALTY = " ��������� �������� ������!\n\n";
    const std::string IN_ATTACK = " � �����:\n";
    const std::string REBOUND_IN_ATTACK = "\n������ � ����� �� ��������: ";
    const std::string STEAL_GOOD = "��� ����������!\n\n��� ��������� ������� ";
    const std::string BLOCK_GOOD = "��� ��� ����-���!\n\n��� ��������� ������� ";
    bool steal{ false };
    bool block{ false };
    
}

namespace defend
{
    const std::string SHOW_HINT = "(����� ���������� ����� ������ ������� 5.)";
    const std::string QUESTION_DEFENSE = "����� ����� ���� ������? ";
    const std::string UNKNOW_TACTICS = "�� ����������� �� �� ��������� ��� �����, �������!\n����� ������� ��, ��� �� ��� �����!\n";
    const std::string REBOUND_IN_DEFENSE = "\n������ � ������ �� ��������: ";
}

struct Situation
{
    int probalityVictory{};
    int playerChoice{};
    const int ACTION{ 1 };
    const int UNACTION{ 2 };
    std::string scene{};
    std::string choice{};
    std::string riscNone{};
    std::string riscVictory{};
    std::string riscFail{};
};

struct Opponent
{
    int score{};
    int hit{};
    int shot{};
    int defense{};
    int teamSpiritOpponent{ 0 };
    int probalityDirtyGame{};
    const int PROCENT_DIRTY_GAME = 50;
    const int DIRTY_DEEP = 5;
    const int ENTER_ON_DIRTY = 30;
    std::string name{};
};

struct Player
{
    int score{};
    int hit{};
    int shot{};
    int defense{};
    int teamSpirit{};
    int probalityDirtyGame{};
    const int PROCENT_DIRTY_GAME{ 30 };
    std::string name{};
};

void recording(std::string comment);
void recording(int comment);
void userComment(std::string userText, std::string gameText, int& userChoice);
void userComment(std::string gameText, std::string& userChoice);
int tournament(Player& player, Opponent& opponent);
void startMenu();
void hints();
void author();
void gameRulesRecord();
void gameRules();
void situationOne(int& teamSpirit);
void situationTwo(int& teamSpirit);
void situationThree(int& teamSpitit);
void choiceDefense(int& defense);
void jumpBall(int& jump);
void probabilityHitPlayer(int& hit, int teamSpirit);
void probabilityHitOpponent(int& hit, int teamSpiritOpponent);
void probalityStealOpponentOnPlayer(bool& steal);
void probalityBlockOpponentOnPlayer(bool& block);
void attackShot(int& shot, int teamSpirit);
bool playerAttack(Player& player, Opponent& opponent);
bool opponentAttack(Player& player, Opponent& opponent);
bool rebound();
void game(Player& player, Opponent& opponent);
void score(int scorePlayer, int scoreOpponent);
void deleteName(std::vector<std::string>& namesTeamOpponent, int choiceTeamName);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(0)));
    record.open(engine::USER_HISTORY_FILE);
    record.close();
    record.open(engine::USER_HISTORY_FILE);
    record.close();


    Opponent opponent{};
    Player player{};

    std::cout << menu::CHOICE_MENU;
    recording(menu::CHOICE_MENU);
    getline(std::cin, engine::userText);
    userComment(engine::userText, menu::CHOICE_MENU, engine::userChoice);
    recording(engine::userChoice);
    while (engine::userChoice < TEST || engine::userChoice > UNTEST)
    {
        std::cout << menu::REPEAT;
        recording(menu::REPEAT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::CHOICE_MENU, engine::userChoice);
        recording(menu::REPEAT);
    }
    switch (engine::userChoice)
    {
    case TEST:
        test::testingEnabled = true;
        break;
    case UNTEST:
        test::testingEnabled = false;
        break;
    }
    system("cls");

    if (test::testingEnabled)
    {
        std::cout << test::TESTING_ENABLED;
        recording(test::TESTING_ENABLED);
        Sleep(1500);
        system("cls");
    }

    gameRulesRecord();
    startMenu();
    if (menu::startGame == menu::EXIT_GAME) { return 0; }
    else if (menu::startGame == menu::TOURNAMENT)
    {
        engine::resoultTournament = tournament(player, opponent);
        switch (engine::resoultTournament)
        {
        case PLAYER_LOSE: 
            system("cls");
            std::cout << "� ���������, �� �������� ������.\n�� �� ����� ���! ���� ������ �� ���������!\n����� � ��������� ���!";
            system("pause");
            return 0;
        case DRAW:
            system("cls");
            std::cout << "� ���������, �� �������� ������. ��-�� �������� ���������� ������ �� ������� �����.\n�� �� ����� ���! ���� ������ �� ���������!\n����� � ��������� ���!";
            system("pause");
            return 0;
        case PLAYER_WIN:
            std::cout << "��� �� �������!!!\n������� ��� ���� ����� ������ � ���� �����!\n����� ������ ���� � ����� ���������!\n������ �� ���, �� ����� ������������� ����! ������� ���� ����� ������!!!";
            system("pause");
            return 0;
        }
    }

    hints();

    std::cout << menu::OPPONENT_NAME_CHOICE;
    recording(menu::OPPONENT_NAME_CHOICE);
    std::getline(std::cin, opponent.name);
    if (opponent.name != engine::EMPTY_STRING)
    {
        userComment(menu::OPPONENT_NAME_CHOICE, opponent.name);
    }
    if (opponent.name == engine::EMPTY_STRING)
    {
        opponent.name = history::STANDART_OPPONENT_NAME;
    }
    
    recording(opponent.name);

    if (test::testingEnabled)
    {
        std::cout << test::CHOICE_TEAM_SPIRIT;
        recording(test::CHOICE_TEAM_SPIRIT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, test::CHOICE_TEAM_SPIRIT, player.teamSpirit);
        while (player.teamSpirit > MAX_SPIRIT || player.teamSpirit < MIN_SPIRIT)
        {
            std::cout << menu::REPEAT;
            getline(std::cin, engine::userText);
            userComment(engine::userText, menu::REPEAT, player.teamSpirit);
        }
        recording(player.teamSpirit);
        system("cls");
        std::cout << test::CHOICE_SCENE;
        recording(test::CHOICE_SCENE);
        int show;
        getline(std::cin, engine::userText);
        userComment(engine::userText, test::CHOICE_SCENE, show);
        recording(show);
        switch (show)
        {
        case FIRST_STORY:
            situationOne(player.teamSpirit);
            break;
        case SECOND_STORY:
            situationTwo(player.teamSpirit);
            break;
        case THIRD_STORY:
            situationThree(player.teamSpirit);
            break;
        default:
            std::cout << test::NONE_SCENE;
            recording(test::NONE_SCENE);
            Sleep(1000);
            system("cls");
            break;
        }

    }
    
    std::cout << menu::START_DEFENSE;
    recording(menu::START_DEFENSE);
    choiceDefense(player.defense);
    recording(player.defense);
    player.name = history::PLAYER_TEAM_NAME;
    opponent.defense = player.defense;
    std::cout << "\n";

    system("cls");

    jumpBall(menu::jump);
    if (menu::jump == PLAYER_BALL)
    {
        std::cout << menu::WIN_BALL_JUMP;
        recording(menu::WIN_BALL_JUMP);
        std::cout << player.name << ".\n\n";
        recording(player.name);
    }
    else
    {
        std::cout << menu::WIN_BALL_JUMP;
        recording(menu::WIN_BALL_JUMP);
        std::cout << opponent.name << ".\n\n";
        recording(opponent.name);
    }

    game(player, opponent);
    std::cout << menu::TIMEOUT;
    recording(menu::TIMEOUT);
    system("pause");
    system("cls");
    std::cout << menu::SECOND_TIME;
    recording(menu::SECOND_TIME);
    if (menu::jump == PLAYER_BALL)
    {
        menu::jump = OPPONENT_BALL;
    }
    else
    {
        menu::jump = PLAYER_BALL;
    }
    engine::period = engine::PERIOD_START;
    game(player, opponent);
    std::cout << menu::FINAL;
    recording(menu::FINAL);
    std::cout << player.name;
    recording(player.name);
    std::cout << ' ';
    std::cout << player.score;
    recording(player.score);
    std::cout << ' ';
    std::cout << opponent.name;
    recording(opponent.name);
    std::cout << ": ";
    std::cout  << opponent.score << ".\n";
    recording(opponent.score);
    if (player.score > opponent.score)
    {
        std::cout << menu::HOORAY;
        recording(menu::HOORAY);
        std::cout << player.name;
        recording(player.name);
    }
    else if (player.score < opponent.score)
    {
        std::cout << menu::HOORAY;
        recording(menu::HOORAY);
        std::cout << opponent.name;
        recording(opponent.name);
    }
    else
    {
        std::cout << menu::DRAW;
        recording(menu::DRAW);
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}

void recording(std::string comment)
{
    record.open(engine::USER_HISTORY_FILE, std::ios::app);
    if (record.is_open())
    {
        record << comment << std::endl;
        record.close();
    }
}

void recording(int comment)
{
    record.open(engine::USER_HISTORY_FILE, std::ios::app);
    if (record.is_open())
    {
        record << comment << std::endl;
        record.close();
    }
}

void userComment(std::string userText, std::string gameText, int& userChoice)
{
    while (userText[0] == engine::COMMENT_CHAR || userText == engine::EMPTY_STRING)
    {
        if (userText == engine::EMPTY_STRING)
        {
            std::cout << gameText;
            getline(std::cin, userText);
            continue;
        }
        record.open(engine::USER_HISTORY_FILE, std::ios::app);
        record << userText << std::endl;
        record.close();
        std::cout << gameText;
        getline(std::cin, userText);
    }
    userChoice = stoi(userText);
}

void userComment(std::string gameText, std::string& userChoice)
{
    while (userChoice[0] == engine::COMMENT_CHAR)
    {
        record.open(engine::USER_HISTORY_FILE, std::ios::app);
        record << userChoice << std::endl;
        record.close();
        std::cout << gameText;
        getline(std::cin, userChoice);
    }
}

int tournament(Player& player, Opponent& opponent)
{
    int gamesDraw{ 0 };
    std::vector<std::string> namesTeamOpponent{ "������� ������", "������� ����������", "������� ������", "������� �����", "���������� �������", "������� ������", "������� ��������", "������� �������"};

    int choiceTeamName{};
    hints();
    player.name = history::PLAYER_TEAM_NAME;
    recording(player.name);
    while (engine::howGame <= engine::ALL_TOURNAMENT_GAME)
    {
        menu::jump = 0;
        player.score = 0;
        opponent.score = 0;
        engine::period = engine::PERIOD_START;
        choiceTeamName = rand() % engine::allTeamTournament;

        opponent.name = namesTeamOpponent[choiceTeamName];
        deleteName(namesTeamOpponent, choiceTeamName);

        

        switch (engine::howGame)
        {
        case 1:
            system("cls");
            situationOne(player.teamSpirit);
            std::cout << "������ ���� ������� ������ ������� " << opponent.name << std::endl;
            break;
        case 2:
            system("cls");
            situationTwo(player.teamSpirit);
            std::cout << "��������� ������� ������ ������� " << opponent.name << std::endl;
            opponent.teamSpiritOpponent += MORE_POINT;
            break;
        case 3:
            system("cls");
            situationThree(player.teamSpirit);
            std::cout << "��������� ���� ������� ������ ������� " << opponent.name << std::endl;
            opponent.teamSpiritOpponent += MORE_POINT;
            break;
        }

        std::cout << menu::START_DEFENSE;
        recording(menu::START_DEFENSE);
        choiceDefense(player.defense);
        recording(player.defense);
        opponent.defense = player.defense;
        std::cout << "\n";

        system("cls");

        jumpBall(menu::jump);
        if (menu::jump == PLAYER_BALL)
        {
            std::cout << menu::WIN_BALL_JUMP;
            recording(menu::WIN_BALL_JUMP);
            std::cout << player.name << ".\n\n";
            recording(player.name);
        }
        else
        {
            std::cout << menu::WIN_BALL_JUMP;
            recording(menu::WIN_BALL_JUMP);
            std::cout << opponent.name << ".\n\n";
            recording(opponent.name);
        }

        game(player, opponent);
        std::cout << menu::TIMEOUT;
        recording(menu::TIMEOUT);
        system("pause");
        system("cls");
        std::cout << menu::SECOND_TIME;
        recording(menu::SECOND_TIME);
        if (menu::jump == PLAYER_BALL)
        {
            menu::jump = OPPONENT_BALL;
        }
        else
        {
            menu::jump = PLAYER_BALL;
        }
        engine::period = engine::PERIOD_START;
        game(player, opponent);
        std::cout << menu::FINAL;
        recording(menu::FINAL);
        std::cout << player.name;
        recording(player.name);
        std::cout << ' ';
        std::cout << player.score;
        recording(player.score);
        std::cout << ' ';
        std::cout << opponent.name;
        recording(opponent.name);
        std::cout << ": ";
        std::cout << opponent.score << ".\n";
        recording(opponent.score);
        if (player.score > opponent.score)
        {
            std::cout << menu::HOORAY;
            recording(menu::HOORAY);
            std::cout << player.name;
            recording(player.name);
        }
        else if (player.score < opponent.score)
        {
            system("pause");
            return PLAYER_LOSE;
        }
        else
        {
            if (gamesDraw == engine::MAX_DRAW) { system("pause");  return DRAW; }
            std::cout << menu::DRAW;
            recording(menu::DRAW);
            gamesDraw++;
        }
        std::cout << std::endl;
        system("pause");
        system("cls");

        engine::howGame++;
    }
    return PLAYER_WIN;
}

void startMenu()
{
    std::cout << menu::WELCOME;
    recording(menu::WELCOME);
    std::cout << menu::START_MENU;
    recording(menu::START_MENU);
    getline(std::cin, engine::userText);
    userComment(engine::userText, menu::START_MENU, menu::startGame);
    recording(menu::startGame);
    std::cout << "\n";
    while (menu::startGame < menu::RULES_GAME || menu::startGame > menu::EXIT_GAME)
    {
        std::cout << menu::REPEAT;
        recording(menu::REPEAT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::START_MENU, menu::startGame);
    }
    if (menu::startGame == menu::RULES_GAME || menu::startGame == menu::AUTHOR_GAME)

    {
        while (menu::startGame == menu::RULES_GAME || menu::startGame == menu::AUTHOR_GAME)
        {
            if (menu::startGame == menu::RULES_GAME)
            {
                system("cls");
                gameRules();
                std::cout << menu::START_MENU;
                recording(menu::START_MENU);
                getline(std::cin, engine::userText);
                userComment(engine::userText, menu::START_MENU, menu::startGame);
                recording(menu::startGame);
                std::cout << "\n";
            }
            else if (menu::startGame == menu::AUTHOR_GAME)
            {
                system("cls");
                author();
                std::cout << menu::START_MENU;
                recording(menu::START_MENU);
                getline(std::cin, engine::userText);
                userComment(engine::userText, menu::START_MENU, menu::startGame);
                recording(menu::startGame);
                std::cout << "\n";
            }
        }
    }
}

void hints()
{
    std::cout << menu::CHOICE_HINT;
    recording(menu::CHOICE_HINT);
    getline(std::cin, engine::userText);
    userComment(engine::userText, menu::CHOICE_HINT, menu::hint);
    recording(menu::hint);
    while (menu::hint > NOOB || menu::hint < EXPERT)
    {
        std::cout << menu::REPEAT;
        recording(menu::REPEAT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::REPEAT, menu::hint);
    }
}

void author()
{
    std::cout << menu::AUTHOR;
    recording(menu::AUTHOR);
    system("pause");
    system("cls");
}

void gameRulesRecord()
{
    // ��������� ���� � ����������
    menu::rules =
        "��� ������������� ���� �������� �������. "
        "�� ������ ��������� � ������������ ����� �������.\n"
        "���� ������ 2 ����� �� 4 ������. ���� ����� ������ 24 �������.\n\n";
    menu::rulesShot =
        "������� ������ ��������� �������:\n"
        "1. ������� (�����������) ������ � ������;\n2. ������� (�����������) ������ � ������;\n3. ��� - ��� (��� ����);\n4. ���������� � ������ (��� ����);\n\n"
        "�� ��������� ������:\n1. ������� ������� ���������.\n2. ������.\n3. ��������� ���.\n\n"
        "��������� ��� �����, ��� �������(�������� ����� � �������� �������� ��������� �������� �������).\n��� � ��������(������ ����� ��� ���������� ���������).\n\n";
    menu::rulesDefense =
        "�������� ����� ��������� �������:\n"
        "1. �������� - ����������� ������ (���� ���� ������� ������ �� 10%);\n"
        "2. ������ ����� - �������� ������ �� ������� � ������� ������� (���� �������� �������� ������ � ��� - ���� -20%),\n"
        "�� ����������� �������� ������� ��� ������� ������� � ���������� (���� �������� �������� ������ � ���������� + 10 %);\n"
        "3. ������ ������ - �������� ������ �� ������� ������� � ���������� (���� �������� �������� ������ � ���������� -20%),\n"
        "�� ����������� �������� ������� ��� ��� - ����� � ������� ������� (���� �������� ��� - ���� � ������� ������� + 10%);\n"
        "4. ��� ������ - ������� �������� � ������ (���������� ���� ������� ���������� ���� ������� +10%);\n"
        "��������� ����� ������ ���� ������ � ����������� �� �������, ������� �� �������!\n";
        "����� �������� ������, ������ ������� 0 � �������� ���������� ������.\n\n";
}

void gameRules()
{
    // ��������� ���� � ����������
    std::cout << menu::rules;
    recording(menu::rules);
    std::cout << menu::rulesShot;
    recording(menu::rulesShot);
    std::cout << menu::rulesDefense;
    recording(menu::rulesDefense);
    system("pause");
    system("cls");
}

void situationOne(int& teamSpirit)
{
    Situation situation{};

    situation.scene =
        "�� � ���� ������� �� ������� � ���������� �������� ����� ���������� ������������ � ���������� ���������,\n"
        "������ �������� ����������� ������ ����.\n"
        "����� ������ �������� �����, �� ���������� � ������� ���� ��������.\n"
        "��� ���� ������� ����� �����������, �� ����� ������ �� ��� ����������, �� �� �� ��� ����� ������ �������,\n"
        "��� ��� ��� ���� ����� ������� ������������ ��� �������� ����������� ������.\n"
        "� ��������,� ���������� � ���� ����, ������, �������, ����� ����� �������� �������,\n"
        "� � ��� �� ������ ����, �����? � ��,� ��������� ��. � �������!,� ������������ �������.\n"
        "� �� ���� ������ �� ������, ���� �� ��� ���������?\n"
        "� ��������� � ��� �������! �� ��� ��� ��?\n"
        "� ��� ��� ���!� ���� ��������� �����. � � � ��� ����� �������. �� ��� ���, �� ��������?\n"
        "��� ���� �� ����� ����.\n"
        "���� �������� ���������� ����������� � ������� ����� - ������ �������� ��������� ���� �� ����� ���� ������,\n"
        "��� ��� �� �������� ����������� ���������������� � ������������, �, ���� �������, ���������� �������� ����������.\n"
        "�������� ���� ������ � �����, ������������� �������������� �� �������������.\n"
        "� ���� � � ������� ���������� ���� ���������� ����������� ���, ���������� ���� ������ ������� �������� � ���������,\n"
        "���� ������������� �������, � ���������� ������� ��������� ���������� �� ������ ���� �����������,\n"
        "�� � ������� �������, � ���� ��� ����������� ���� �������.\n"
        "����� ���������, �� ����� ��������,  ����������� ������� ���� �����������, � �� �������� �������� ����� ������,\n"
        "��� ���, ���� �� �����������, ��� ����� �� ������ ������������.\n"
        "����� ���������, ��� ��� �������, ������� ���� ������, �������� �����������, �� ������ ����.\n\n";
    std::cout << situation.scene;
    recording(situation.scene);
    system("pause");
    system("cls");

    situation.choice = "��� �� ��� ���������?\n1. ������� ����������� ����.\n2. ���������� �� ����������� ����.\n�����: ";
    std::cout << situation.choice;
    recording(situation.choice);
    getline(std::cin, engine::userText);
    userComment(engine::userText, situation.choice, situation.playerChoice);
    recording(situation.playerChoice);
    while (situation.playerChoice > situation.UNACTION || situation.playerChoice < situation.ACTION)
    {
        std::cout << menu::REPEAT;
        recording(menu::REPEAT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::REPEAT, situation.playerChoice);
        recording(situation.playerChoice);
    }
    
    situation.probalityVictory = rand() % 100 + 1;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\n�����!\n\n"
            "���� � � ������� ������ �������� ��������� �� ������ �����, � ���� �� ���� ������ �������,\n"
            "������ ����� ������ �����.\n"
            "������� �������� ������ ������ � �����������, �� ������� ��� ���� �� ������ ������������,\n"
            "�� � ����������� �����.\n"
            "������ �� ������ �� ������ ����� ����������.\n\n";
        std::cout << situation.riscVictory;
        recording(situation.riscVictory);
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (teamSpirit > MAX_SPIRIT)
        {
            teamSpirit = MAX_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }
    else if (situation.playerChoice == situation.ACTION && situation.probalityVictory < history::PROBALITY_WIN)
    {
        situation.riscFail =
            "\n�������!\n\n"
            "���� � � ������� ���������� � ������ ��������� �� ������ �����,\n"
            "� � ������ ����� �� ����� �����������.\n"
            "���� �� ������� ���������� ����, � �������� �� ����������� �����������,\n"
            "� �������, �������� ��� ��������� �����,\n"
            "��  ���������� ����������� �������� ���������.\n"
            "��������� ��� ���������, ����� ����� �������, �������� ����������, �������� ����,\n"
            "��� ��� ���� ������� �����������, ����� ����������� ��.\n\n";
        std::cout << situation.riscFail;
        recording(situation.riscFail);
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }
    else
    {
        situation.riscNone =
            "������� �����, ���� ������� �����������, �������� ����� � ���������� ���� � ������� ����� ��������� �����.\n"
            "����� �������� �, �� ������� �� ����������.\n"
            "���� ��� �������� �� ����, ���������� ���������� �� ���� � �������.\n"
            "� �� ������ ��� ���� �� ����!, ������ ����, ��� �� ��� �����?!\n"
            "� �� ��� ����? � �� �� ���� ���������� �� ������.\n"
            "� ��!� ������� ������. � �� � ���, �������, ����, � �������� �������� ��, ������� ��� ����������� ��������.\n"
            "� � �� ���!, �� �� �� ������ ��������� ����, � ���� ��� �� ���������, � ��������� ����� ���,\n"
            "� ��������� �� ��������� ���� �������.\n"
            "����, �� ������ �������, ���� ������� ������ �������. \n"
            "���� ���� �������� ������ ������, �� � ������� ��� ��������� ����� ��������,\n"
            "�������� ���� � ���������� ���������� � ��������� �� �����.\n"
            "� �� �� � �������, � ����� ����������� �����. ������ �� ��� �����.\n\n";
        std::cout << situation.riscNone;
        recording(situation.riscNone);
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }

}

void situationTwo(int& teamSpirit)
{
    Situation situation;

    situation.scene = 
        "� ������� �� ������� ���������. �� ������ ������ �������� � ��������� �� ������ ������,\n"
        "���� ���������, ��� ������ �����.\n"
        "� ������� ������������ ��������, ����� ����, �� ���� ��� �� ������� ���������.\n"
        "�� ��������� ������ ������� � ����, ������� ��������� ���� ����� �� ����, �������� �� ������� ��� ��� ��� ������.\n"
        "������, ������������� ��������� ��������, ��������� �������������� �� ������������ ����� �������, ������,\n"
        "���� ������� �� �������� �� ����� ����������, ������ � ������ �� ����� �����,\n"
        "��� ��� ������� ����-�� ������������, ��� �� �������� � �� ������.\n"
        "���� �����, ��� ��������� � ���� �����, � ����� ����������, �������, ������ �� ��������?\n"
        "�� ����� � ��������� �����, � ���������: � ����� ��� �������, ��� ����������, � ����� ��� �� ����� �� ���?\n";
    std::cout << situation.scene;
    recording(situation.scene);
    system("pause");
    system("cls");

    situation.choice = "��� �� ��� ���������?\n1. ��������� ������.\n2. �� �������, ����� ������ �� ���������.\n�����: ";
    std::cout << situation.choice;
    recording(situation.choice);
    getline(std::cin, engine::userText);
    userComment(engine::userText, situation.choice, situation.playerChoice);
    recording(situation.playerChoice);
    while (situation.playerChoice > situation.UNACTION || situation.playerChoice < situation.ACTION)
    {
        std::cout << menu::REPEAT;
        recording(menu::REPEAT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::REPEAT, situation.playerChoice);
        recording(situation.playerChoice);
    }

    situation.probalityVictory = rand() % 100 + 1;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\n�����!\n\n"
            "������ ����� �������� ������!\n"
            "��������, � ������� �� ��������� �������, �������, �� ��������,\n"
            "�� ������ ��������� ������ ���������, �� � � ������� �� ������.\n"
            "� ��� �������� ����� ����� ��� ��� ���������, �� ��������� � �� ���������� ����, ��� ������� ������,\n"
            "� ����� �� ���������, ���� ��������� ���� ����������.\n"
            "��� ��� ����� �� �����, ��� �� �������, �����, ��� ������ �� ������ �������� �� ���������� ������ ������ �����!\n";
        std::cout << situation.riscVictory;
        recording(situation.riscVictory);
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (teamSpirit > MAX_SPIRIT)
        {
            teamSpirit = MAX_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }
    else if (situation.playerChoice == situation.ACTION && situation.probalityVictory < history::PROBALITY_WIN)
    {
        situation.riscFail =
            "\n�������!\n\n"
            "��� � ���� ������ ����� ������!\n"
            "�� � ������ ������� ������� �� �������.\n"
            "������ ����������� �����������, �� �� ����� �������, ��� � ��� ���-��-�� ���.\n"
            "������ ����� � ������, ������� ��� ���� ���������.\n"
            "����� �� ���� ������� ����������� �������, ����������, ��� � ���� �������� ��� ������� ������,\n"
            "��-�� ���� �� ������� ��������� ����-�� � ������, ��� ���� �� ��, ��� � ����������,\n"
            "��� ���� ������������� � ���� ���� �� ������.\n";
            "������ �������,���, ��������, �� ������� �������� �� ������� ���, �� ���� ����������,\n"
            "��� ��� � ���� �� ������� ����� � ���.\n"
            "���� �����, ���� ������ ���������� � ����� �������� ������, ����, ��� �� ��� ��������?\n"
            "�� ��������� ������� �� ���������� ����, �� ��� ��������, ��� � �� ����� ��� ��-�� ��������.\n"
            "����� ���� �������������, ��������� ������� ����, �� ���������� �� ����, ��� ��� �� ����� ���� �����.\n";
        std::cout << situation.riscFail;
        recording(situation.riscFail);
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }
    else
    {
        situation.riscNone =
            "�������� ������� ���� ������, ��  �� �� ������� �������.\n"
            "�� ��������� ������������� �� ����������� ������ ����,\n"
            "�� ����� ����� � ����� ������������ � ������.\n"
            "�� ��������� � �������� �����, ��� ��� ������� ������� ���� ��� ����.\n";
        std::cout << situation.riscNone;
        recording(situation.riscNone);
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }

}

void situationThree(int& teamSpirit)
{
    Situation situation;

    situation.scene =
        "������� �� ����� �������� ����� �������� �����.\n"
        "�� ����� ��������������� ������� ������� ������� �, ������� �������, �������� �� �����.\n"
        "� ���, �� ���? ��� ��� ���������, � ������� ���������.\n"
        "�� ������� ���� �� ���.\n"
        "������������ ����, ��� ���������� ������� ������ �� ��� ���� ������, ��� ��� � ����,\n"
        "��� �� � �������� ������������, ������ ���� ��������� �����-�� �����������.\n"
        "��� ����������� ���� ������ �� �����, ��� ��� ������� �� ������ ���� �� �����,\n"
        "��� ���� ����������� ��������, �� ������� ��� ������������ � ��������, �� ������� ����, ��� ����.\n"
        "����  � ���, ��� �� ����� �������� ������� �� ����� ��������� �������, ������� ����� �����, ��� �������, ��� ������.\n"
        "������ ���� ������� ��������, ����� �� ����������, � ����� ���������,\n"
        "��� ���-������ �� ����� ���� �������, ���� �� �������� ���� � ������������ �������������.\n"
        "�� � ���� ������ ������ ����������� ��������, ��� �������� �� ������ � �������.\n";
    std::cout << situation.scene;
    recording(situation.scene);
    system("pause");
    system("cls");

    situation.choice = "��� �� ��� ���������?\n1. ������� �� ����������.\n2. �������� ���� � ������������.\n�����: ";
    std::cout << situation.choice;
    recording(situation.choice);
    getline(std::cin, engine::userText);
    userComment(engine::userText, situation.choice, situation.playerChoice);
    recording(situation.playerChoice);
    while (situation.playerChoice > situation.UNACTION || situation.playerChoice < situation.ACTION)
    {
        std::cout << menu::REPEAT;
        recording(menu::REPEAT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::REPEAT, situation.playerChoice);
        recording(situation.playerChoice);
    }

    situation.probalityVictory = rand() % 100 + 1;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\n�����!\n\n"
            "��-���� �� �������!\n"
            "������ ���� � ������������� ��� ����� �������������, �� ���������� ������ �� ���,\n"
            "��� ��� ������� ������� ��������, ��� ������, ���� ���� ������ ��������� ������� ����.\n"
            "� ������ ���� �� ����������� ��������� �������.\n"
            "���� �������� ������� �� ������ ��������� ����������,\n"
            "�� � ����������� ������� ���������� ��������, ��� ��� ������� ���� �� ������.\n";
        std::cout << situation.riscVictory;
        recording(situation.riscVictory);
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (teamSpirit > MAX_SPIRIT)
        {
            teamSpirit = MAX_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }
    else if (situation.playerChoice == situation.ACTION && situation.probalityVictory < history::PROBALITY_WIN)
    {
        situation.riscFail =
            "\n�������!\n\n"
            "�� ���� ��� �� ����!\n"
            "����� �� �� ����������� �� ����������, �� ����� � ������.\n"
            "����� ������� �������� ���������, � � �������,\n"
            "����� ����� ���� ����������� ���, �� �� ����������� � �������� ����������������.\n"
            "����� ����, �� ��������� � ���������, ������, ������� ��� �� ������ ���� � �������,\n"
            "��� ��� ������ ������� ������������� ������.\n";
        std::cout << situation.riscFail;
        recording(situation.riscFail);
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }
    else
    {
        situation.riscNone =
            "�� �� �� ����� �������� ���� � ��� �������  �������������.\n"
            "������ ������������� ������� � ����� ����, �� � ����� ��������� � ��������  � ����������.\n"
            "�� ������� �������, ��� ������ �� ����� ���������� � ��������� ����,\n"
            "�������, ������ ���� �� �����, �� �� ������, ������ ����������.\n";
        std::cout << situation.riscNone;
        recording(situation.riscNone);
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }

}

void choiceDefense(int& defense)
{
    if (menu::hint == EXPERT)
    {
        getline(std::cin, engine::userText);
        userComment(engine::userText, defend::QUESTION_DEFENSE, defense);
    }
    else if (menu::hint == AMATEUR)
    {
        std::cout << defend::SHOW_HINT;
        recording(defend::SHOW_HINT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, defend::QUESTION_DEFENSE, defense);
        recording(defense);
        while (defense == RULES_DEFENSE)
        {
            std::cout << menu::rulesDefense;
            recording(menu::rulesDefense);
            std::cout << defend::QUESTION_DEFENSE;
            recording(defend::QUESTION_DEFENSE);
            getline(std::cin, engine::userText);
            userComment(engine::userText, defend::QUESTION_DEFENSE, defense);
            recording(defense);
        }
    }
    else if (menu::hint == NOOB)
    {
        std::cout << "\n" << menu::rulesDefense;
        recording(menu::rulesDefense);
        getline(std::cin, engine::userText);
        userComment(engine::userText, menu::rulesDefense, defense);
        recording(defense);
    }
    while (defense < PRESSING || defense > NONE_DEFENSE)
    {
        std::cout << defend::UNKNOW_TACTICS;
        recording(defend::UNKNOW_TACTICS);
        std::cout << defend::QUESTION_DEFENSE;
        recording(defend::QUESTION_DEFENSE);
        getline(std::cin, engine::userText);
        userComment(engine::userText, defend::QUESTION_DEFENSE, defense);
        recording(defense);
    }
}

void jumpBall(int& jump)
{
    engine::probalityJump = rand() % 100 + 1;
    if (engine::probalityJump > PROCENT_BALL_PLAYER)
    {
        jump = PLAYER_BALL;
    }
    else
    {
        jump = OPPONENT_BALL;
    }
}

void probabilityHitPlayer(int& hit, int teamSpirit)
{
    hit = (rand() % 100 + 1) + teamSpirit;
}

void probabilityHitOpponent(int& hit, int teamSpiritOpponent)
{
    hit = (rand() % 100) + 1 + teamSpiritOpponent;
}

void probalityStealOpponentOnPlayer(bool& steal)
{
    int probalitySteal = (rand() % 100) + 1;
    if (probalitySteal > engine::GOOD_STEAL_OPPONENT_ON_PLAYER)
    {
        steal = true;
    }
}

void probalityBlockOpponentOnPlayer(bool& block)
{
    int probalityBlock = (rand() % 100) + 1;
    if (probalityBlock > engine::GOOD_BLOCK_OPPONENT_ON_PLAYER)
    {
        block = true;
    }
}

void attackShot(int& shot, int teamSpirit)
{
    switch (menu::hint)
    {
    case EXPERT:
        std::cout << attack::SHOT_CHOICE;
        recording(attack::SHOT_CHOICE);
        break;
    case AMATEUR:
        std::cout << attack::SHOT_CHOICE_AND_HINT;
        recording(attack::SHOT_CHOICE_AND_HINT);
        break;
    case NOOB:
        std::cout << menu::rulesShot;
        recording(menu::rulesShot);
        std::cout << attack::SHOT_CHOICE;
        recording(attack::SHOT_CHOICE);
    }
    getline(std::cin, engine::userText);
    userComment(engine::userText, attack::SHOT_CHOICE, shot);
    recording(shot);

    while (shot == RULES_SHOT)
    {
        std::cout << menu::rulesShot;
        std::cout << attack::SUPERPOWER_HINT;
        recording(attack::SUPERPOWER_HINT);
        std::cout << attack::SHOT_CHOICE;
        recording(attack::SHOT_CHOICE);
        getline(std::cin, engine::userText);
        userComment(engine::userText, attack::SHOT_CHOICE, shot);
        recording(shot);
    }
    
    if (shot == DIRTY_SHOT && teamSpirit <= DIRTY_SPIRIT)
    {
        return;
    }
    else if (shot == HAND_GOD_SHOT && teamSpirit >= GOD_SPIRIT)
    {
        return;
    }
    while (shot < CHOICE_DEFENSE || shot > COMBINATIONT_SHOT)
    {
        if (shot == DIRTY_SHOT && teamSpirit <= DIRTY_SPIRIT)
        {
            return;
        }
        else if (shot == HAND_GOD_SHOT && teamSpirit >= GOD_SPIRIT)
        {
            return;
        }
        std::cout << attack::UNKNOW_TACTICS;
        recording(attack::UNKNOW_TACTICS);
        std::cout << attack::SHOT_CHOICE;
        recording(attack::SHOT_CHOICE);
        getline(std::cin, engine::userText);
        userComment(engine::userText, attack::SHOT_CHOICE, shot);
        recording(shot);
    }
}

bool playerAttack(Player& player, Opponent& opponent)
{
    if (player.teamSpirit >= MAX_SPIRIT)
    {
        player.teamSpirit = MAX_SPIRIT;
    }
    else if (player.teamSpirit <= MIN_SPIRIT)
    {
        player.teamSpirit = MIN_SPIRIT;
    }

    std::cout << history::YOUR_TEAM_SPIRIT;
    recording(history::YOUR_TEAM_SPIRIT);
    std::cout << player.teamSpirit << std::endl;
    recording(player.teamSpirit);
    if (player.teamSpirit <= DIRTY_SPIRIT && (menu::hint == AMATEUR || menu::hint == NOOB))
    {
        std::cout << attack::OPEN_DIRTY;
        recording(attack::OPEN_DIRTY);
    }
    else if (player.teamSpirit >= GOD_SPIRIT && (menu::hint == AMATEUR || menu::hint == NOOB))
    {
        std::cout << attack::OPEN_HAND;
        recording(attack::OPEN_HAND);
    }
    attackShot(player.shot, player.teamSpirit);

    switch (player.shot)
    {
    case THREE_POINT_SHOT:
    case COMBINATIONT_SHOT:
        if (engine::countZoneDefense == engine::SWITCH_DEFENSE)
        {
            opponent.defense = ZONE_DEFENSE;
            engine::countZoneDefense = engine::ZERO;
            break;
        }
        engine::countZoneDefense += engine::ONE_UP;
        engine::countPersonalDefense = engine::ZERO;
        break;

    case MEDIUM_SHOT:
    case LAY_UP_SHOT:
        if (engine::countPersonalDefense == engine::SWITCH_DEFENSE)
        {
            opponent.defense = PERSONAL_DEFENSE;
            engine::countPersonalDefense = engine::ZERO;
            break;
        }
        engine::countPersonalDefense += engine::ONE_UP;
        engine::countZoneDefense = engine::ZERO;
        break;
    }
    if (player.score - opponent.score >= opponent.DIRTY_DEEP)
    {
        opponent.defense = PRESSING;
    }
    else if (opponent.score - player.score >= opponent.DIRTY_DEEP)
    {
        opponent.defense = NONE_DEFENSE;
    }

    std::cout << "\n";
    while (player.shot == CHOICE_DEFENSE)
    {
        if (player.shot == CHOICE_DEFENSE)
        {
            std::cout << defend::QUESTION_DEFENSE;
            recording(defend::QUESTION_DEFENSE);
            choiceDefense(player.defense);
            attackShot(player.shot, player.teamSpirit);
        }
    }
    if (player.shot == THREE_POINT_SHOT)
    {
        //���� ������������ 40% - �������
        std::cout << attack::THREE_POINT;
        recording(attack::THREE_POINT);
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (opponent.defense)
        {
        case PRESSING:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_THREE_PRESSING;
                recording(test::TEST_THREE_PRESSING);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::THREE_POINT_AND_PRESSING)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_THREE_PERSONAL_DEFENSE;
                recording(test::TEST_THREE_PERSONAL_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::THREE_POINT_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_THREE_ZONE_DEFENSE;
                recording(test::TEST_THREE_ZONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);

            }
            if (player.hit > engine::THREE_POINT_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_THREE_NONE_DEFENSE;
                recording(test::TEST_THREE_NONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::THREE_POINT_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }

    }
    if (player.shot == MEDIUM_SHOT)
    {
        //���� ������������ 50% - �������
        std::cout << attack::MEDIUM_SHOT;
        recording(attack::MEDIUM_SHOT);
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (opponent.defense)
        {
        case PRESSING:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_MEDIUM_PRESSING;
                recording(test::TEST_MEDIUM_PRESSING);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_MEDIUM_PERSONAL_DEFENSE;
                recording(test::TEST_MEDIUM_PERSONAL_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_MEDIUM_ZONE_DEFENSE;
                recording(test::TEST_MEDIUM_ZONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_MEDIUM_NONE_DEFENSE;
                recording(test::TEST_MEDIUM_NONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }
    }
    if (player.shot == LAY_UP_SHOT)
    {
        //���� ��� - ���� 60% - �������
        std::cout << attack::LAY_UP;
        recording(attack::LAY_UP);
        probabilityHitPlayer(player.hit, player.teamSpirit);
        probalityStealOpponentOnPlayer(attack::steal);
        probalityBlockOpponentOnPlayer(attack::block);
        if (attack::steal && attack::block)
        {
            attack::steal = false;
        }
        switch (opponent.defense)
        {
        case PRESSING:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_LAY_UP_PRESSING;
                recording(test::TEST_LAY_UP_PRESSING);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::LAY_UP_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_LAY_UP_PERSONAL_DEFENSE;
                recording(test::TEST_LAY_UP_PERSONAL_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_LAY_UP_ZONE_DEFENSE;
                recording(test::TEST_LAY_UP_ZONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::LAY_UP_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_LAY_UP_NONE_DEFENSE;
                recording(test::TEST_LAY_UP_NONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::LAY_UP_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }
    }
    if (player.shot == COMBINATIONT_SHOT)
    {
        //���� ���������� 55% - �������
        std::cout << attack::COMBINATION;
        recording(attack::COMBINATION);
        probabilityHitPlayer(player.hit, player.teamSpirit);
        probalityStealOpponentOnPlayer(attack::steal);
        probalityBlockOpponentOnPlayer(attack::block);
        if (attack::steal && attack::block)
        {
            attack::steal = false;
        }
        switch (opponent.defense)
        {
        case PRESSING:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_COMBINATION_PRESSING;
                recording(test::TEST_COMBINATION_PRESSING);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::COMBINATION_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_COMBINATION_PERSONAL_DEFENSE;
                recording(test::TEST_COMBINATION_PERSONAL_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::COMBINATION_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_COMBINATION_ZONE_DEFENSE;
                recording(test::TEST_COMBINATION_ZONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::COMBINATION_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (test::testingEnabled)
            {
                std::cout << test::TEST_COMBINATION_NONE_DEFENSE;
                recording(test::TEST_COMBINATION_NONE_DEFENSE);
                std::cout << player.teamSpirit << "\n";
                recording(player.teamSpirit);
            }
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << opponent.name << "\n\n";
                recording(opponent.name);
                return false;
            }
            if (player.hit > engine::COMBINATION_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit += MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }
    }
    if (player.shot == DIRTY_SHOT && player.teamSpirit <= DIRTY_SPIRIT)
    {
        if (test::testingEnabled)
        {
            std::cout << test::TEST_DIRTY;
            recording(test::TEST_DIRTY);
        }
        player.probalityDirtyGame = rand() % 100 + 1;
        if (player.probalityDirtyGame >= player.PROCENT_DIRTY_GAME)
        {
            std::cout << attack::ADD_DIRTY;
            recording(attack::ADD_DIRTY);
            player.score += engine::THREE_POINT;
            score(player.score, opponent.score);
            player.teamSpirit += history::ADD_SPIRIT_VICTORY;
        }
        else
        {
            std::cout << attack::FAIL_DIRTY;
            recording(attack::FAIL_DIRTY);
            std::cout << player.name << '\n';
            recording(player.name);
            std::cout << opponent.name;
            recording(opponent.name);
            std::cout << attack::REALESE_DIRTY_PENALTY;
            recording(attack::REALESE_DIRTY_PENALTY);
            opponent.score += engine::FREE_THROW_POINT;
            score(player.score, opponent.score); 
        }
        return true;
    }
    if (player.shot == HAND_GOD_SHOT && player.teamSpirit >= GOD_SPIRIT)
    {
        if (test::testingEnabled)
        {
            std::cout << test::TEST_HAND_GOD;
            recording(test::TEST_HAND_GOD);
        }
        std::cout << attack::ADD_HAND;
        recording(attack::ADD_HAND);
        player.score += engine::THREE_POINT;
        std::cout << attack::RESET_HAND;
        recording(attack::RESET_HAND);
        score(player.score, opponent.score);
        player.teamSpirit += history::REM_SPIRIT_FAIL;
        return true;
    }
    std::cout << "\n\n";

    return false;
}

bool opponentAttack(Player& player, Opponent& opponent)
{
    switch (opponent.defense)
    {
    case PRESSING:
        std::cout << "������ ������� " << opponent.name << " - ��������\n";
        break;
    case PERSONAL_DEFENSE:
        std::cout << "������ ������� " << opponent.name << " - ������ �����\n";
        break;
    case ZONE_DEFENSE:
        std::cout << "������� " << opponent.name << " ������ ������ ������\n";
        break;
    case NONE_DEFENSE:
        std::cout << "������ ������� " << opponent.name << " ������ - � ��� ��� ������\n";
        break;
    }
    opponent.shot = (rand() % 4) + 1;
    std::cout << opponent.name;
    recording(opponent.name);
    std::cout << attack::IN_ATTACK;
    recording(attack::IN_ATTACK);
    opponent.probalityDirtyGame = rand() % 100 + 1;
    if ((player.score - opponent.score >= opponent.DIRTY_DEEP) && opponent.probalityDirtyGame > opponent.PROCENT_DIRTY_GAME)
    {
        if (opponent.probalityDirtyGame >= opponent.PROCENT_DIRTY_GAME)
        {
            std::cout << attack::ADD_DIRTY;
            recording(attack::ADD_DIRTY);
            opponent.score += engine::THREE_POINT;
            score(player.score, opponent.score);
            player.teamSpirit -= MORE_POINT;
        }
        else
        {
            std::cout << attack::FAIL_DIRTY;
            recording(attack::FAIL_DIRTY);
            std::cout << opponent.name << '\n';
            recording(opponent.name);
            std::cout << player.name;
            recording(player.name);
            std::cout << attack::REALESE_DIRTY_PENALTY;
            recording(attack::REALESE_DIRTY_PENALTY);
            player.score += engine::FREE_THROW_POINT;
            score(player.score, opponent.score);
        }
        return true;
    }
    if (opponent.shot == THREE_POINT_SHOT)
    {
        //���� ������������ 40% - �������
        std::cout << attack::THREE_POINT;
        recording(attack::THREE_POINT);
        probabilityHitOpponent(opponent.hit, opponent.teamSpiritOpponent);
        switch (player.defense)
        {
        case PRESSING:
            if (opponent.hit > engine::THREE_POINT_AND_PRESSING)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (opponent.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (opponent.hit > engine::THREE_POINT_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (opponent.hit > engine::THREE_POINT_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }

    }
    if (opponent.shot == MEDIUM_SHOT)
    {
        //���� ������������ 50% - �������
        std::cout << attack::MEDIUM_SHOT;
        recording(attack::MEDIUM_SHOT);
        probabilityHitOpponent(opponent.hit, opponent.teamSpiritOpponent);
        switch (player.defense)
        {
        case PRESSING:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }
    }
    if (opponent.shot == LAY_UP_SHOT)
    {
        //���� ��� - ���� 60% - �������
        std::cout << attack::LAY_UP;
        recording(attack::LAY_UP);
        probabilityHitOpponent(opponent.hit, opponent.teamSpiritOpponent);
        probalityStealOpponentOnPlayer(attack::steal);
        probalityBlockOpponentOnPlayer(attack::block);
        if (attack::steal && attack::block)
        {
            attack::steal = false;
        }
        switch (player.defense)
        {
        case PRESSING:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::LAY_UP_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::LAY_UP_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::LAY_UP_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }
    }
    if (opponent.shot == COMBINATIONT_SHOT)
    {
        //���� ���������� 55% - �������
        std::cout << attack::COMBINATION;
        recording(attack::COMBINATION);
        probabilityHitOpponent(opponent.hit, opponent.teamSpiritOpponent);
        probalityStealOpponentOnPlayer(attack::steal);
        probalityBlockOpponentOnPlayer(attack::block);
        if (attack::steal && attack::block)
        {
            attack::steal = false;
        }
        switch (player.defense)
        {
        case PRESSING:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::COMBINATION_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case PERSONAL_DEFENSE:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::COMBINATION_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case ZONE_DEFENSE:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::COMBINATION_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case NONE_DEFENSE:
            if (attack::steal)
            {
                std::cout << attack::STEAL_GOOD;
                recording(attack::STEAL_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            else if (attack::block)
            {
                std::cout << attack::BLOCK_GOOD;
                recording(attack::BLOCK_GOOD);
                std::cout << player.name << "\n\n";
                recording(player.name);
                return false;
            }
            if (opponent.hit > engine::COMBINATION_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= MORE_POINT;
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        }
    }
    std::cout << "\n\n";
    return false;
}

bool rebound()
{
    engine::probalityRebound = rand() % 100 + 1;
    if (engine::probalityRebound > engine::PROCENT_REBOUND)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void game(Player& player, Opponent& opponent)
{
    while (engine::period < engine::PERIOD_FINISH)
    {
        if (menu::jump == PLAYER_BALL)
        {
            if (!playerAttack(player, opponent))
            {
                if (attack::steal)
                {
                    attack::steal = false;
                    opponentAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                if (attack::block)
                {
                    attack::block = false;
                    opponentAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                if (rebound())
                {
                    std::cout << attack::REBOUND_IN_ATTACK;
                    recording(attack::REBOUND_IN_ATTACK);
                    std::cout << player.name << "\n\n";
                    recording(player.name);
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                else
                {
                    std::cout << defend::REBOUND_IN_DEFENSE;
                    recording(defend::REBOUND_IN_DEFENSE);
                    std::cout << opponent.name << "\n\n";
                    recording(opponent.name);
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
            if (!opponentAttack(player, opponent))
            {
                if (attack::steal)
                {
                    attack::steal = false;
                    continue;
                }
                if (attack::block)
                {
                    attack::block = false;
                    continue;
                }
                if (rebound())
                {
                    std::cout << attack::REBOUND_IN_ATTACK;
                    recording(attack::REBOUND_IN_ATTACK);
                    std::cout << opponent.name << "\n\n";
                    recording(opponent.name);
                    opponentAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                }
                else
                {
                    std::cout << defend::REBOUND_IN_DEFENSE;
                    recording(defend::REBOUND_IN_DEFENSE);
                    std::cout << player.name << "\n\n";
                    recording(player.name);
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
        }
        else if (menu::jump == OPPONENT_BALL)
        {
            if (!opponentAttack(player, opponent))
            {
                if (attack::steal)
                {
                    attack::steal = false;
                    playerAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                if (attack::block)
                {
                    attack::block = false;
                    playerAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                if (rebound())
                {
                    std::cout << attack::REBOUND_IN_ATTACK;
                    recording(attack::REBOUND_IN_ATTACK);
                    std::cout << opponent.name << "\n\n";
                    recording(opponent.name);
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                else
                {
                    std::cout << defend::REBOUND_IN_DEFENSE;
                    recording(defend::REBOUND_IN_DEFENSE);
                    std::cout << player.name << "\n\n";
                    recording(player.name);
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
            if (!playerAttack(player, opponent))
            {
                if (attack::steal)
                {
                    attack::steal = false;
                    continue;
                }
                if (attack::block)
                {
                    attack::block = false;
                    continue;
                }
                if (rebound())
                {
                    std::cout << attack::REBOUND_IN_ATTACK;
                    recording(attack::REBOUND_IN_ATTACK);
                    std::cout << player.name << "\n\n";
                    recording(player.name);
                    playerAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                }
                else
                {
                    std::cout << defend::REBOUND_IN_DEFENSE;
                    recording(defend::REBOUND_IN_DEFENSE);
                    std::cout << opponent.name << "\n\n";
                    recording(opponent.name);
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
        }
    }
}

void score(int scorePlayer, int scoreOpponent)
{
    std::cout << menu::TABLO;
    recording(menu::TABLO);
    std::cout << scorePlayer;
    recording(scorePlayer);
    std::cout << ' ';
    std::cout << scoreOpponent;
    recording(scoreOpponent);
    std::cout << "\n\n";
}

void deleteName(std::vector<std::string>& namesTeamOpponent, int choiceTeamName)
{
    std::vector<std::string>::iterator team = namesTeamOpponent.begin();
    namesTeamOpponent.erase(team + choiceTeamName);
    engine::allTeamTournament--;
}