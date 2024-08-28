#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <windows.h>


bool testingEnabled{};

enum Shots
{
    THREE_POINT_SHOT = 1,
    MEDIUM_SHOT = 2,
    LAY_UP_SHOT = 3,
    COMBINATIONT_SHOT = 4,
    RULES_SHOT = 5,
    DIRTY_SHOT = 6,
    HAND_GOD_SHOT = 7
};

enum defense
{
    CHOICE_DEFENSE = 0,
    PRESSING = 1,
    PERSONAL_DEFENSE = 2,
    ZONE_DEFENSE = 3,
    NONE_DEFENSE = 4,
    RULES_DEFENSE = 5
};

enum playerHints
{
    EXPERT = 1,
    AMATEUR = 2,
    NOOB = 3
};

enum spirit
{
    MAX_SPIRIT = 20,
    MIN_SPIRIT = -20,
    DIRTY_SPIRIT = -10,
    GOD_SPIRIT = 10,
    MORE_POINT = 5,
    MORE_PLAYER = 1,
    MORE_OPPONENT = -1
};

enum posessionBall
{
    PLAYER_BALL = 0,
    OPPONENT_BALL = 1,
    PROCENT_BALL_PLAYER = 40

};

enum situationShow
{
    FIRST_STORY = 1,
    SECOND_STORY = 2,
    THIRD_STORY = 3
};

enum testing
{
    TEST = 1,
    UNTEST = 2
};

namespace menu
{
    int startGame{};
    int jump{};
    int hint{};
    const int RULES_GAME{ 1 };
    const int AUTHOR_GAME{ 3 };
    const int EXIT_GAME{ 4 };
    std::string rules{};
    std::string rulesShot{};
    std::string rulesDefense{};
}

namespace engine
{
    const int ATTACK_TIME{ 24 };
    const int THREE_POINT{ 3 };
    const int TWO_POINT{ 2 };
    const int FREE_THROW_POINT{ 1 };
    const int THREE_POINT_AND_PRESSING{ 70 };
    const int THREE_POINT_AND_PERSONAL_DEFENSE{ 45 };
    const int THREE_POINT_AND_ZONE_DEFENSE{ 70 };
    const int THREE_POINT_AND_NONE_DEFENSE{ 40 };
    const int MEDIUM_SHOT_AND_PRESSING{ 60 };
    const int MEDIUM_SHOT_AND_PERSONAL_DEFENSE{ 60 };
    const int MEDIUM_SHOT_AND_ZONE_DEFENSE{ 35 };
    const int MEDIUM_SHOT_AND_NONE_DEFENSE{ 30 };
    const int LAY_UP_AND_PRESSING{ 50 };
    const int LAY_UP_AND_PERSONAL_DEFENSE{ 50 };
    const int LAY_UP_AND_ZONE_DEFENSE{ 25 };
    const int LAY_UP_AND_NONE_DEFENSE{ 20 };
    const int COMBINATION_AND_PRESSING{ 65 };
    const int COMBINATION_AND_PERSONAL_DEFENSE{ 40 };
    const int COMBINATION_AND_ZONE_DEFENSE{ 65 };
    const int COMBINATION_AND_NONE_DEFENSE{ 35 };
    const int PROCENT_REBOUND{ 80 };
    const int PERIOD_FINISH{ 120 };
    const int PERIOD_START{ 0 };
    int probalityJump{};
    int probalityRebound{};
    int period{};
    int testingChoice{};
}

namespace history
{
    const int PROBALITY_WIN{ 50 }; // 50% ���� ������ � �������
    const int ADD_SPIRIT_VICTORY{ 10 };
    const int REM_SPIRIT_FAIL{ -10 };
    const int NONE_RISC_SPIRIT{ -5 };
}

struct Situation
{
    int probalityVictory{};
    int playerChoice{};
    const int ACTION{ 1 };
    const int UNACTION{ 2 };
    std::string scene{};
    std::string riscNone{};
    std::string riscVictory{};
    std::string riscFail{};
};

struct Opponent
{
    int score{};
    int hit{};
    int shot{};
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
void probabilityHitOpponent(int& hit);
void attackShot(int& shot, int teamSpirit);
bool playerAttack(Player& player, Opponent& opponent);
bool opponentAttack(Player& player, Opponent& opponent);
bool rebound();
void game(int jump, Player& player, Opponent& opponent);
void score(int scorePlayer, int scoreOpponent);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(0)));


    Opponent opponent{};
    Player player{};

    std::cout << "�������� ������� ������� ����:\n1.�������� �����.\n2.����� ������������.\n";
    std::cout << "��� �����: ";
    std::cin >> engine::testingChoice;
    while (engine::testingChoice < TEST || engine::testingChoice > UNTEST)
    {
        std::cout << "�� �������!\n���� �����: ";
        std::cin >> engine::testingChoice;
    }
    switch (engine::testingChoice)
    {
    case TEST:
        testingEnabled = true;
        break;
    case UNTEST:
        testingEnabled = false;
        break;
    }
    system("cls");

    if (testingEnabled)
    {
        std::cout << "����� ������������ �������!\n";
        Sleep(1500);
        system("cls");
    }

    gameRulesRecord();
    startMenu();
    if (menu::startGame == menu::EXIT_GAME)
    {
        return 0;
    }

    hints();

    std::cout << "������� ������� Enter, ��� ������������ �������� ���������� ���\n������� �������� ������� ����������: ";
    std::cin.ignore();
    std::getline(std::cin, opponent.name);
    if (opponent.name == "")
    {
        opponent.name = "������� ��������";
    }

    if (testingEnabled)
    {
        std::cout << "\n�������� ����:\n�������� ������� ���������� ���� �� -20 �� 20: ";
        std::cin >> player.teamSpirit;
        system("cls");
        std::cout << "�������� ���� ���� ��� ����� ������� �� 1 �� 3.\n";
        std::cout << "��� ����� �����: ";
        int show;
        std::cin >> show;
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
            std::cout << "������� � ���� ��� ��� ����!\n";
            system("cls");
            break;
        }

    }
    
    std::cout << "����� ��������� ������� �����...";
    choiceDefense(player.defense);
    player.name = "����������� �������";
    std::cout << "\n";

    system("cls");

    jumpBall(menu::jump);
    if (menu::jump == PLAYER_BALL)
    {
        std::cout << "����� ����������� ��� ����� � ����������� ����� �...\n";
        std::cout << "����������� ���������� �������: " << player.name << ".\n\n";
    }
    else
    {
        std::cout << "����� ����������� ��� ����� � ����������� ����� �...\n";
        std::cout << "����������� ���������� �������: " << opponent.name << ".\n\n";
    }

    game(menu::jump, player, opponent);
    std::cout << "\n������ �������, ������ ������� ����� �� �������!\n��������� ����� ��������� �����!\n\n";
    system("pause");
    system("cls");
    std::cout << "���������� ������ ����! �������!!!\n\n";
    if (menu::jump == PLAYER_BALL)
    {
        menu::jump = OPPONENT_BALL;
    }
    else
    {
        menu::jump = PLAYER_BALL;
    }
    engine::period = engine::PERIOD_START;
    game(menu::jump, player, opponent);
    std::cout << "��������� ������� ����� �������! ����� ���� �������!\n��������� ���� �� �����:\n" << player.name << ' ' << player.score << ' ' << opponent.name << ": " << opponent.score << ".\n";
    if (player.score > opponent.score)
    {
        std::cout << "����������� ������� " << player.name << " � �������!";
    }
    else if (player.score < opponent.score)
    {
        std::cout << "����������� ������� " << opponent.name << " � �������!";
    }
    else
    {
        std::cout << "������� ���������� �� �������, �� � ��������� ��� ������� ����������!\n\n";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}

void startMenu()
{
    std::cout << "����� ���������� � ���� \"���������\"\n";
    std::cout << "1. ������� ����.\n";
    std::cout << "2. ������ ����.\n";
    std::cout << "3. �� ������.\n";
    std::cout << "4. ����� �� ����.\n\n";
    std::cout << "��� ����������� �������� ��������: ";
    std::cin >> menu::startGame;
    std::cout << "\n";
    while (menu::startGame < menu::RULES_GAME || menu::startGame > menu::EXIT_GAME)
    {
        std::cout << "�� �������!\n�������� ��������: ";
        std::cin >> menu::startGame;
    }
    if (menu::startGame == menu::RULES_GAME || menu::startGame == menu::AUTHOR_GAME)

    {
        while (menu::startGame == menu::RULES_GAME || menu::startGame == menu::AUTHOR_GAME)
        {
            if (menu::startGame == menu::RULES_GAME)
            {
                system("cls");
                gameRules();
                std::cout << "1. ������� ����.\n";
                std::cout << "2. ������ ����.\n";
                std::cout << "3. �� ������.\n";
                std::cout << "4. ����� �� ����.\n\n";
                std::cout << "��� ����������� �������� ��������: ";
                std::cin >> menu::startGame;
                std::cout << "\n";
            }
            else if (menu::startGame == menu::AUTHOR_GAME)
            {
                system("cls");
                author();
                std::cout << "1. ������� ����.\n";
                std::cout << "2. ������ ����.\n";
                std::cout << "3. �� ������.\n";
                std::cout << "4. ����� �� ����.\n\n";
                std::cout << "��� ����������� �������� ��������: ";
                std::cin >> menu::startGame;
                std::cout << "\n";
            }
        }
    }
}

void hints()
{
    std::cout << "�������� ����� ���������:\n1.�������(��� ���������).\n2.��������(��������� ���������� �� ������� �������)\n3.�������(��������� ��������� ������)\n\n";
    std::cout << "��� �����: ";
    std::cin >> menu::hint;
    while (menu::hint > NOOB || menu::hint < EXPERT)
    {
        std::cout << "�� ������� ����!\n�������� ����� ���������: ";
        std::cin >> menu::hint;
    }
}

void author()
{
    std::cout << "������ ���������� ��� Dialas ������������.\n�����: ���������� ����(���: mee1b).\n������: 1.0.3.\n\n";
    system("pause");
    system("cls");
}

void gameRulesRecord()
{
    // ��������� ���� � ����������
    menu::rules =
        "��� ������������� ���� ������������ ��������. "
        "�� ������ ��������� � ������������ ����� �������.\n"
        "���� ������ 2 ����� �� 4 ������. ���� ����� ������ 24 �������.\n\n";
    menu::rulesShot =
        "������� ������ ��������� �������:\n"
        "1. ������� (�����������) ������ � ������;\n2. ������� (�����������) ������ � ������;\n3. ��� - ��� (��� ����);\n4. ���������� � ������ (��� ����);\n\n"
        "�� ��������� ������:\n1. ������� ������� ���������.\n2. ������.\n3. ��������� ���.\n\n"
        "��������� ��� �����, ��� �������(�������� ����� � �������� �������� ��������� �������� �������).\n��� � ��������(������ ����� ��� ���������� ���������).\n\n";
    menu::rulesDefense =
        "��� ������� ����� ������������ ���� � �� �� ������.\n�������� ����� ��������� �������:\n"
        "1. �������� - ����������� ������ (���� ���� ������� ������ �� 10%);\n"
        "2. ������ ����� - �������� ������ �� ������� � ������� ������� (���� �������� �������� ������ � ��� - ���� -10%),\n"
        "�� ����������� �������� ������� ��� ������� ������� � ���������� (���� �������� �������� ������ � ���������� + 15 %);\n"
        "3. ������ ������ - �������� ������ �� ������� ������� � ���������� (���� �������� �������� ������ � ���������� -10%),\n"
        "�� ����������� �������� ������� ��� ��� - ����� � ������� ������� (���� �������� ��� - ���� � ������� ������� + 15%);\n"
        "4. ��� ������ - ������� �������� � ������ (���������� ���� ������� ���������� ���� ������� +20%);\n"
        "����� �������� ������, ������ ������� 0 � �������� ���������� ������.\n\n";
}

void gameRules()
{
    // ��������� ���� � ����������
    menu::rules =
        "��� ������������� ���� ������������ ��������. "
        "�� ������ ��������� � ������������ ����� �������.\n"
        "���� ������ 2 ����� �� 4 ������. ���� ����� ������ 24 �������.\n\n";
    std::cout << menu::rules;
    menu::rulesShot =
        "������� ������ ��������� �������:\n"
        "1. ������� (�����������) ������ � ������;\n2. ������� (�����������) ������ � ������;\n3. ��� - ��� (��� ����);\n4. ���������� � ������ (��� ����);\n\n"
        "�� ��������� ������:\n1. ������� ������� ���������.\n2. ������.\n3. ��������� ���.\n\n"
        "��������� ��� �����, ��� �������(�������� �����(����� � ���� ������ �����, ��� � ���������) � �������� �������� ��������� �������� �������).\n"
        "��� � ��������(������ �����(����� � ���� ������ �����, ��� � ��������� ��� ���������� ���������).\n\n";
    std::cout << menu::rulesShot;
    menu::rulesDefense =
        "��� ������� ����� ������������ ���� � �� �� ������.\n�������� ����� ��������� �������:\n"
        "1. �������� - ����������� ������ (���� ���� ������� ������ �� 10%);\n"
        "2. ������ ����� - �������� ������ �� ������� � ������� ������� (���� �������� �������� ������ � ��� - ���� -10%),\n"
        "�� ����������� �������� ������� ��� ������� ������� � ���������� (���� �������� �������� ������ � ���������� + 15 %);\n"
        "3. ������ ������ - �������� ������ �� ������� ������� � ���������� (���� �������� �������� ������ � ���������� -10%),\n"
        "�� ����������� �������� ������� ��� ��� - ����� � ������� ������� (���� �������� ��� - ���� � ������� ������� + 15%);\n"
        "4. ��� ������ - ������� �������� � ������ (���������� ���� ������� ���������� ���� ������� +20%);\n"
        "����� �������� ������, ������ ������� 0 � �������� ���������� ������.\n\n";
    std::cout << menu::rulesDefense;
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
    system("pause");
    system("cls");

    std::cout << "��� �� ��� ���������?\n1. ������� ����������� ����.\n2. ���������� �� ����������� ����.\n";

    std::cout << "�����: ";
    std::cin >> situation.playerChoice;
    while (situation.playerChoice > situation.UNACTION || situation.playerChoice < situation.ACTION)
    {
        std::cout << "�� ������ ����!\n�����: ";
        std::cin >> situation.playerChoice;
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
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (testingEnabled && teamSpirit > MAX_SPIRIT)
        {
            teamSpirit = MAX_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (testingEnabled && teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (testingEnabled && teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
        "� ������� ������������ ���������, ����� ����, �� ���� ���� �� ������� ���������.\n"
        "�� ��������� ������ ������� � ����, ������� ��������� ���� ����� �� ����, �������� �� ������� ��� ��� ��� ������.\n"
        "������, ������������� ��������� ��������, ��������� �������������� �� ������������ ����� �������, ������, \n"
        "���� ������� �� �������� �� ����� ����������, ������ � ������ �� ����� �����,\n"
        "��� ��� ������� ����-�� ������������, ��� �� �������� � �� ������.\n"
        "���� �����, ��� ��������� � ���� �����, � ����� ����������, �������, ������ �� ��������?\n"
        "�� ����� � ���������  �����, � ���������: � ����� ��� �������, ��� ����������, � ����� ��� �� ����� �� ���?\n";
    std::cout << situation.scene;
    system("pause");
    system("cls");

    std::cout << "��� �� ��� ���������?\n1. ��������� ������.\n2. �� �������, ����� ������ �� ���������.\n";

    std::cout << "�����: ";
    std::cin >> situation.playerChoice;
    while (situation.playerChoice > situation.UNACTION || situation.playerChoice < situation.ACTION)
    {
        std::cout << "�� ������ ����!\n�����: ";
        std::cin >> situation.playerChoice;
    }

    situation.probalityVictory = rand() % 100 + 1;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\n�����!\n\n"
            "B����� ����� �������� ������!\n"
            "��������, � ������� �� ��������� �������, �������, �� ��������,\n"
            "�� ������ ��������� ������ ���������, �� � � ������� �� ������.\n"
            "� ��� �������� ����� ����� ��� ��� ���������, �� ��������� � �� ���������� ����, ��� ������� ������,\n"
            "� ����� �� ���������, ���� ��������� ���� ����������.\n"
            "��� ��� ����� �� �����, ��� �� �������, �����, ��� ������ �� ������ �������� �� ���������� ������ ������ �����!\n";
        std::cout << situation.riscVictory;
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (testingEnabled && teamSpirit > MAX_SPIRIT)
        {
            teamSpirit = MAX_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
            "������ �������,���, ��������, �� ������� �������� �� ������� ���, �� ���� ����������,\n"
            "��� ��� � ���� �� ������� ����� � ���.\n"
            "���� �����, ���� ������ ���������� � ����� �������� ������, ����, ��� �� ��� ��������?\n"
            "�� ��������� ������� �� ���������� ����, �� ��� ��������, ��� � �� ����� ��� ��-�� ��������.\n"
            "����� ���� �������������, ��������� ������� ����, �� ���������� �� ����, ��� ��� �� ����� ���� �����.\n";
        std::cout << situation.riscFail;
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (testingEnabled && teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (testingEnabled && teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
    system("pause");
    system("cls");

    std::cout << "��� �� ��� ���������?\n1. ������� �� ����������.\n2. �������� ���� � ������������.\n";

    std::cout << "�����: ";
    std::cin >> situation.playerChoice;
    while (situation.playerChoice > situation.UNACTION || situation.playerChoice < situation.ACTION)
    {
        std::cout << "�� ������ ����!\n�����: ";
        std::cin >> situation.playerChoice;
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
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (testingEnabled && teamSpirit > MAX_SPIRIT)
        {
            teamSpirit = MAX_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (testingEnabled && teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
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
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (testingEnabled && teamSpirit < MIN_SPIRIT)
        {
            teamSpirit = MIN_SPIRIT;
        }
        std::cout << "\n��� ��������� ��� ����� " << teamSpirit << std::endl;
        system("pause");
        system("cls");
    }

}

void choiceDefense(int& defense)
{
    if (menu::hint == EXPERT)
    {
        std::cin >> defense;
    }
    else if (menu::hint == AMATEUR)
    {
        std::cout << "(����� ���������� ����� ������ ������� 5.)";
        std::cin >> defense;
        while (defense == RULES_DEFENSE)
        {
            std::cout << menu::rulesDefense;
            std::cout << "����� ����� ���� ������? ";
            std::cin >> defense;
        }
    }
    else if (menu::hint == NOOB)
    {
        std::cout << "\n" << menu::rulesDefense;
        std::cin >> defense;
    }
    while (defense < PRESSING || defense > NONE_DEFENSE)
    {
        std::cout << "�� ����������� �� �� ��������� ��� �����, �������!\n����� ������� ��, ��� �� ��� �����!\n";
        std::cout << "����� ����� ���� ������? ";
        std::cin >> defense;
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

void probabilityHitOpponent(int& hit)
{
    hit = (rand() % 100) + 1;
}

void attackShot(int& shot, int teamSpirit)
{
    switch (menu::hint)
    {
    case EXPERT:
        std::cout << "�������! ����� ������ ������ � ���� �����? ";
        break;
    case AMATEUR:
        std::cout << "�������! ����� ������ ������ � ���� �����?(����� ���������� ���� ������� ������� 5): ";
        break;
    case NOOB:
        std::cout << menu::rulesShot;
        std::cout << "�������! ����� ������ ������ � ���� �����? ";
    }
    std::cin >> shot;

    while (shot == RULES_SHOT)
    {
        std::cout << menu::rulesShot;
        std::cout << "���� ��������� ��� ����� -10 ��� ������:\n6.������� ����(��� ����, ���� 10 � ���������� ����).\n���� ��������� ��� ����� 10 ��� ������:\n7.���� ����(��� ����, ���� 10 � ���������� ����).\n\n";
        std::cout << "�������! ����� ������ ������ � ���� �����? ";
        std::cin >> shot;
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
        std::cout << "�� ����������� �� �� ��������� ����� ������, �������!\n����� ������� ��, ��� �� ��� �����!\n";
        std::cout << "����� ������ ������ � ���� �����? ";
        std::cin >> shot;
    }
}

bool playerAttack(Player& player, Opponent& opponent)
{
    if (player.score - opponent.score >= MORE_PLAYER)
    {
        player.teamSpirit += MORE_POINT;
    }
    else if (player.score - opponent.score <= MORE_OPPONENT)
    {
        player.teamSpirit -= MORE_POINT;
    }

    if (player.teamSpirit >= MAX_SPIRIT)
    {
        player.teamSpirit = MAX_SPIRIT;
    }
    else if (player.teamSpirit <= MIN_SPIRIT)
    {
        player.teamSpirit = MIN_SPIRIT;
    }

    std::cout << "��� ��������� ��� ����� " << player.teamSpirit << std::endl;
    if (player.teamSpirit <= DIRTY_SPIRIT && (menu::hint == AMATEUR || menu::hint == NOOB))
    {
        std::cout << "6. ��� ��������� ��� ������, ������ ����� \"������� ����\".\n";
    }
    else if (player.teamSpirit >= GOD_SPIRIT && (menu::hint == AMATEUR || menu::hint == NOOB))
    {
        std::cout << "7. ��� ��������� ��� �� �������, ������ ����� \"���� ����\".\n";
    }
    attackShot(player.shot, player.teamSpirit);
    std::cout << "\n";
    while (player.shot == CHOICE_DEFENSE)
    {
        if (player.shot == CHOICE_DEFENSE)
        {
            std::cout << "\n�������, ����� ����� ������ ������? ";
            choiceDefense(player.defense);
            attackShot(player.shot, player.teamSpirit);
        }
    }
    if (player.shot == THREE_POINT_SHOT)
    {
        //���� ������������ 40% - �������
        std::cout << "����������� ������!!!\n";
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (player.defense)
        {
        case PRESSING:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::THREE_POINT_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"������ �����\" - (+15%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::THREE_POINT_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"������ ������\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::THREE_POINT_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 40%.\n2.������ \"��� ������\" - (+20%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::THREE_POINT_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }

    }
    if (player.shot == MEDIUM_SHOT)
    {
        //���� ������������ 50% - �������
        std::cout << "������� ������!!!\n";
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (player.defense)
        {
        case PRESSING:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"������ �����\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"������ ������\" - (+15%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 50%.\n2.������ \"��� ������\" - (+20%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::MEDIUM_SHOT_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }
    }
    if (player.shot == LAY_UP_SHOT)
    {
        //���� ��� - ���� 60% - �������
        std::cout << "��� �� ��� - ���!!!\n";
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (player.defense)
        {
        case PRESSING:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::LAY_UP_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"������ �����\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"������ ������\" - (+15%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::LAY_UP_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 60%.\n2.������ \"��� ������\" - (+20%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::LAY_UP_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }
    }
    if (player.shot == COMBINATIONT_SHOT)
    {
        //���� ���������� 55% - �������
        std::cout << "��������, ������ ����������� ����������!!!\n";
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (player.defense)
        {
        case PRESSING:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"��������\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::COMBINATION_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"������ �����\" - (+15%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::COMBINATION_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"������ ������\" - (-10%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::COMBINATION_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (testingEnabled)
            {
                std::cout << "�������� ���������:\n1.������� ���� - 55%.\n2.������ \"���� ������\" - (+20%)\n3.��������� ��� " << player.teamSpirit << "%\n";
            }
            if (player.hit > engine::COMBINATION_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                player.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }
    }
    if (player.shot == DIRTY_SHOT && player.teamSpirit <= DIRTY_SPIRIT)
    {
        if (testingEnabled)
        {
            std::cout << "�������� ���������:\n����������� ��������� 70%\n";
        }
        player.probalityDirtyGame = rand() % 100 + 1;
        if (player.probalityDirtyGame >= player.PROCENT_DIRTY_GAME)
        {
            std::cout << "��� �� ���!!!\n�� ����� ������ �� �����.\n��� ���� � �������!\n\n";
            player.score += engine::THREE_POINT;
            score(player.score, opponent.score);
            player.teamSpirit += history::ADD_SPIRIT_VICTORY;
        }
        else
        {
            std::cout << "��� �� ���!!!\n����� ��������� �������� ������ � ������ ������� " << player.name << '\n';
            std::cout << "������� " << opponent.name << " ��������� �������� ������!\n\n";
            opponent.score += engine::FREE_THROW_POINT;
            score(player.score, opponent.score); 
        }
        return true;
    }
    if (player.shot == HAND_GOD_SHOT && player.teamSpirit >= GOD_SPIRIT)
    {
        if (testingEnabled)
        {
            std::cout << "�������� ���������:\n����������� ��������� 100%\n";
        }
        std::cout << "����� ���������� ������!!!\n�� ������, � ����������.\n��� ���� � �������!\n\n";
        player.score += engine::THREE_POINT;
        std::cout << "��� ��� ������������ ������!\n�� ������ �� ����� ����� ��� � �������, ����� ��������� ������� ������� ����� ���������!\n\n";
        score(player.score, opponent.score);
        player.teamSpirit += history::REM_SPIRIT_FAIL;
        return true;
    }
    std::cout << "\n\n";
    return false;
}

bool opponentAttack(Player& player, Opponent& opponent)
{
    opponent.shot = (rand() % 4) + 1;
    std::cout << opponent.name << " � �����:\n";
    if (opponent.shot == THREE_POINT_SHOT)
    {
        //���� ������������ 40% - �������
        std::cout << "����������� ������!!!\n";
        probabilityHitOpponent(opponent.hit);
        switch (player.defense)
        {
        case PRESSING:
            if (opponent.hit > engine::THREE_POINT_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (opponent.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (opponent.hit > engine::THREE_POINT_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (opponent.hit > engine::THREE_POINT_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }

    }
    if (opponent.shot == MEDIUM_SHOT)
    {
        //���� ������������ 50% - �������
        std::cout << "������� ������!!!\n";
        probabilityHitOpponent(opponent.hit);
        switch (player.defense)
        {
        case PRESSING:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (opponent.hit > engine::MEDIUM_SHOT_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }
    }
    if (opponent.shot == LAY_UP_SHOT)
    {
        //���� ��� - ���� 60% - �������
        std::cout << "��� �� ��� - ���!!!\n";
        probabilityHitOpponent(opponent.hit);
        switch (player.defense)
        {
        case PRESSING:
            if (opponent.hit > engine::LAY_UP_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (opponent.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (opponent.hit > engine::LAY_UP_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (opponent.hit > engine::LAY_UP_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        }
    }
    if (opponent.shot == COMBINATIONT_SHOT)
    {
        //���� ���������� 55% - �������
        std::cout << "��������, ������ ����������� ����������!!!\n";
        probabilityHitOpponent(opponent.hit);
        switch (player.defense)
        {
        case PRESSING:
            if (opponent.hit > engine::COMBINATION_AND_PRESSING)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case PERSONAL_DEFENSE:
            if (opponent.hit > engine::COMBINATION_AND_PERSONAL_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case ZONE_DEFENSE:
            if (opponent.hit > engine::COMBINATION_AND_ZONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
                return false;
            }
        case NONE_DEFENSE:
            if (opponent.hit > engine::COMBINATION_AND_NONE_DEFENSE)
            {
                std::cout << "��� ���� � �������!!!\n";
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                return true;
            }
            else
            {
                std::cout << "������! ��� � �������, ��� �� �� ���������?\n";
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

void game(int jump, Player& player, Opponent& opponent)
{
    while (engine::period < engine::PERIOD_FINISH)
    {
        if (jump == PLAYER_BALL)
        {
            if (!playerAttack(player, opponent))
            {
                if (rebound())
                {
                    std::cout << "\n������ � ����� �� ��������: " << player.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                else
                {
                    std::cout << "\n������ � ������ �� ��������: " << opponent.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
            if (!opponentAttack(player, opponent))
            {
                if (rebound())
                {
                    std::cout << "\n������ � ����� �� ��������: " << opponent.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                    opponentAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                }
                else
                {
                    std::cout << "\n������ � ������ �� ��������: " << player.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
        }
        else if (jump == OPPONENT_BALL)
        {
            if (!opponentAttack(player, opponent))
            {
                if (rebound())
                {
                    std::cout << "\n������ � ������ �� ��������: " << opponent.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                    continue;
                }
                else
                {
                    std::cout << "\n������ � ������ �� ��������: " << player.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                }
            }
            else
            {
                engine::period += engine::ATTACK_TIME;
            }
            if (!playerAttack(player, opponent))
            {
                if (rebound())
                {
                    std::cout << "\n������ � ������ �� ��������: " << player.name << "\n\n";
                    engine::period += engine::ATTACK_TIME;
                    playerAttack(player, opponent);
                    engine::period += engine::ATTACK_TIME;
                }
                else
                {
                    std::cout << "\n������ � ������ �� ��������: " << opponent.name << "\n\n";
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
    std::cout << "����: " << scorePlayer << ' ' << scoreOpponent << "\n\n";
}