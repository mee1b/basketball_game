#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include "namespace.h"
#include "enums.h"
#include "structs.h"
#include "games.h"
#include "history.h"
#include "engine_func.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(NULL)));
    record.open(engine::USER_HISTORY_FILE);
    record.close();

    Opponent opponent{};
    Player player{};

    startMenu(player, opponent);
    while (menu::startGame != menu::EXIT_GAME)
    {

        if (menu::startGame == menu::TOURNAMENT)
        {
            engine::resoultTournament = tournament(player, opponent);
            switch (engine::resoultTournament)
            {
            case static_cast<int>(winOrLose::PLAYER_LOSE):
                system("cls");
                std::cout << history::LOSE_TOURNAMENT;
                recording(history::LOSE_TOURNAMENT);
                system("pause");
                startMenu(player, opponent);
                break;
            case static_cast<int>(winOrLose::DRAW):
                system("cls");
                std::cout << history::DRAW_TOURNAMENT;
                recording(history::DRAW_TOURNAMENT);
                system("pause");
                startMenu(player, opponent);
                break;
            case static_cast<int>(winOrLose::PLAYER_WIN):
                std::cout << history::WIN_TOURNAMENT;
                recording(history::WIN_TOURNAMENT);
                system("pause");
                startMenu(player, opponent);
                break;
            }
        }
        else if (menu::startGame == menu::ONE_GAME)
        {
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
                while (player.teamSpirit > static_cast<int>(spirit::MAX_SPIRIT) || player.teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
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
                case static_cast<int>(situationShow::FIRST_STORY):
                    situationOne(player.teamSpirit);
                    break;
                case static_cast<int>(situationShow::SECOND_STORY):
                    situationTwo(player.teamSpirit);
                    break;
                case static_cast<int>(situationShow::THIRD_STORY):
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
            choiceDefenseOpponent(opponent.defense);
            std::cout << "\n";

            system("cls");

            jumpBall(menu::jump);
            if (menu::jump == static_cast<int>(posessionBall::PLAYER_BALL))
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
            if (menu::jump == static_cast<int>(posessionBall::PLAYER_BALL))
            {
                menu::jump = static_cast<int>(posessionBall::OPPONENT_BALL);
            }
            else
            {
                menu::jump = static_cast<int>(posessionBall::PLAYER_BALL);
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
            startMenu(player, opponent);
        }  
    }
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
    while (userText[engine::ZERO] == engine::COMMENT_CHAR || userText == engine::EMPTY_STRING)
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
    while (userChoice[engine::ZERO] == engine::COMMENT_CHAR)
    {
        record.open(engine::USER_HISTORY_FILE, std::ios::app);
        record << userChoice << std::endl;
        record.close();
        std::cout << gameText;
        getline(std::cin, userChoice);
    }
}

void hints()
{
    std::cout << menu::CHOICE_HINT;
    recording(menu::CHOICE_HINT);
    getline(std::cin, engine::userText);
    userComment(engine::userText, menu::CHOICE_HINT, menu::hint);
    recording(menu::hint);
    while ((menu::hint < static_cast<int>(playerHints::EXPERT)) || (menu::hint > static_cast<int>(playerHints::AMATEUR)))
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

void gameRules()
{
    // Объясняет ввод с клавиатуры
    std::cout << menu::rules;
    recording(menu::rules);
    std::cout << menu::rulesShot;
    recording(menu::rulesShot);
    std::cout << menu::rulesDefense;
    recording(menu::rulesDefense);
    system("pause");
    system("cls");
}

void deleteName(std::vector<std::string>& namesTeamOpponent, int choiceTeamName)
{
    std::vector<std::string>::iterator team = namesTeamOpponent.begin();
    namesTeamOpponent.erase(team + choiceTeamName);
    engine::allTeamTournament--;
}

int tournament(Player& player, Opponent& opponent)
{
    int gamesDraw = engine::ZERO;
    std::vector<std::string> namesTeamOpponent{ "Колледж Иллинойс", "Колледж Вашингтона", "Колледж Аляски", "Колледж Огайо", "Далласский колледж", "Колледж Техаса", "Колледж Минесоты", "Колледж Аризоны" };

    int choiceTeamName{};
    hints();
    player.name = history::PLAYER_TEAM_NAME;
    recording(player.name);
    while (engine::howGame <= engine::ALL_TOURNAMENT_GAME)
    {
        player.score = 0;
        opponent.score = 0;
        engine::period = engine::PERIOD_START;
        defend::fatigue = engine::ZERO;
        choiceTeamName = rand() % engine::allTeamTournament;

        opponent.name = namesTeamOpponent[choiceTeamName];
        deleteName(namesTeamOpponent, choiceTeamName);



        switch (engine::howGame)
        {
        case 1:
            system("cls");
            situationOne(player.teamSpirit);
            std::cout << history::FIRST_GAME;
            recording(history::FIRST_GAME);
            std::cout << opponent.name << std::endl;
            recording(opponent.name);
            break;
        case 2:
            system("cls");
            situationTwo(player.teamSpirit);
            std::cout << history::SECOND_GAME;
            recording(history::SECOND_GAME);
            std::cout << opponent.name << std::endl;
            recording(opponent.name);
            opponent.teamSpiritOpponent += static_cast<int>(spirit::MORE_POINT);
            break;
        case 3:
            system("cls");
            situationThree(player.teamSpirit);
            std::cout << history::LAST_GAME;
            recording(history::LAST_GAME);
            std::cout << opponent.name << std::endl;
            recording(opponent.name);
            opponent.teamSpiritOpponent += static_cast<int>(spirit::MORE_POINT);
            break;
        }

        std::cout << menu::START_DEFENSE;
        recording(menu::START_DEFENSE);
        choiceDefense(player.defense);
        recording(player.defense);
        choiceDefenseOpponent(opponent.defense);
        std::cout << "\n";

        system("cls");

        jumpBall(menu::jump);
        if (menu::jump == static_cast<int>(posessionBall::PLAYER_BALL))
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
        if (menu::jump == static_cast<int>(posessionBall::PLAYER_BALL))
        {
            menu::jump = static_cast<int>(posessionBall::OPPONENT_BALL);
        }
        else
        {
            menu::jump = static_cast<int>(posessionBall::PLAYER_BALL);
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
            return static_cast<int>(winOrLose::PLAYER_LOSE);
        }
        else
        {
            if (gamesDraw == engine::MAX_DRAW) { system("pause");  return static_cast<int>(winOrLose::DRAW); }
            std::cout << menu::DRAW;
            recording(menu::DRAW);
            gamesDraw++;
        }
        std::cout << std::endl;
        system("pause");
        system("cls");

        engine::howGame++;
    }
    return static_cast<int>(winOrLose::PLAYER_WIN);
}

void startMenu(Player& player, Opponent& opponent)
{
    engine::allTeamTournament = engine::ALL_TOURNAMENT_TEAM;
    engine::howGame = engine::ONE_UP;
    engine::period = engine::PERIOD_START;
    player.score = engine::ZERO;
    opponent.score = engine::ZERO;
    player.teamSpirit = engine::ZERO;
    opponent.teamSpiritOpponent = engine::ZERO;
    defend::fatigue = engine::ZERO;
    system("cls");
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

void choiceDefense(int& defense)
{
    if ((defend::fatigue > engine::ZERO && defense == static_cast<int>(defense::NONE_DEFENSE)) || (defense == static_cast<int>(defense::PRESSING) && defend::fatigue == defend::SEVERE_FATIGUE))
    {
        std::cout << defend::RELAX;
        recording(defend::RELAX);
        return;
    }
    if (menu::hint == static_cast<int>(playerHints::EXPERT))
    {
        getline(std::cin, engine::userText);
        userComment(engine::userText, defend::QUESTION_DEFENSE, defense);
    }
    else if (menu::hint == static_cast<int>(playerHints::AMATEUR))
    {
        std::cout << defend::SHOW_HINT;
        recording(defend::SHOW_HINT);
        getline(std::cin, engine::userText);
        userComment(engine::userText, defend::QUESTION_DEFENSE, defense);
        recording(defense);
        while (defense == static_cast<int>(defense::RULES_DEFENSE))
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
    while (defense < static_cast<int>(defense::PRESSING) || defense > static_cast<int>(defense::NONE_DEFENSE))
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

void choiceDefenseOpponent(int& defense)
{
    int choiceDefense = rand() % engine::HIGH_RAND;
    if (choiceDefense >= history::PROBALITY_WIN)
    {
        defense = static_cast<int>(defense::PERSONAL_DEFENSE);
    }
    else
    {
        defense = static_cast<int>(defense::ZONE_DEFENSE);
    }
}

void jumpBall(int& jump)
{
    engine::probalityJump = rand() % engine::HIGH_RAND + engine::ONE_UP;
    if (engine::probalityJump > static_cast<int>(posessionBall::PROCENT_BALL_PLAYER))
    {
        jump = static_cast<int>(posessionBall::PLAYER_BALL);
    }
    else
    {
        jump = static_cast<int>(posessionBall::OPPONENT_BALL);
    }
}

void probabilityHitPlayer(int& hit, int teamSpirit)
{
    hit = (rand() % engine::HIGH_RAND + engine::ONE_UP) + teamSpirit;
}

void probabilityHitOpponent(int& hit, int teamSpiritOpponent)
{
    hit = rand() % engine::HIGH_RAND + engine::ONE_UP + teamSpiritOpponent;
}

void probalityStealOpponentOnPlayer(bool& steal)
{
    int probalitySteal = rand() % engine::HIGH_RAND + engine::ONE_UP;
    if (probalitySteal > engine::GOOD_STEAL_OPPONENT_ON_PLAYER)
    {
        steal = true;
    }
}

void probalityBlockOpponentOnPlayer(bool& block)
{
    int probalityBlock = rand() % engine::HIGH_RAND + engine::ONE_UP;
    if (probalityBlock > engine::GOOD_BLOCK_OPPONENT_ON_PLAYER)
    {
        block = true;
    }
}

void attackShot(int& shot, int teamSpirit)
{
    switch (menu::hint)
    {
    case static_cast<int>(playerHints::EXPERT):
        std::cout << attack::SHOT_CHOICE;
        recording(attack::SHOT_CHOICE);
        break;
    case static_cast<int>(playerHints::AMATEUR):
        std::cout << attack::SHOT_CHOICE_AND_HINT;
        recording(attack::SHOT_CHOICE_AND_HINT);
        break;
    }
    getline(std::cin, engine::userText);
    userComment(engine::userText, attack::SHOT_CHOICE, shot);
    recording(shot);

    while (shot == static_cast<int>(shots::RULES_SHOT))
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

    if (shot == static_cast<int>(shots::DIRTY_SHOT) && teamSpirit <= static_cast<int>(spirit::DIRTY_SPIRIT))
    {
        return;
    }
    else if (shot == static_cast<int>(shots::HAND_GOD_SHOT) && teamSpirit >= static_cast<int>(spirit::GOD_SPIRIT))
    {
        return;
    }
    while (shot < static_cast<int>(defense::CHOICE_DEFENSE) || shot > static_cast<int>(shots::COMBINATIONT_SHOT))
    {
        if (shot == static_cast<int>(shots::DIRTY_SHOT) && teamSpirit <= static_cast<int>(spirit::DIRTY_SPIRIT))
        {
            return;
        }
        else if (shot == static_cast<int>(shots::HAND_GOD_SHOT) && teamSpirit >= static_cast<int>(spirit::GOD_SPIRIT))
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
    showDefense(opponent.defense, opponent.name);

    if (player.teamSpirit >= static_cast<int>(spirit::MAX_SPIRIT))
    {
        player.teamSpirit = static_cast<int>(spirit::MAX_SPIRIT);
    }
    else if (player.teamSpirit <= static_cast<int>(spirit::MIN_SPIRIT))
    {
        player.teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
    }

    std::cout << history::YOUR_TEAM_SPIRIT;
    recording(history::YOUR_TEAM_SPIRIT);
    std::cout << player.teamSpirit << std::endl;
    recording(player.teamSpirit);
    if (player.teamSpirit <= static_cast<int>(spirit::DIRTY_SPIRIT) && (menu::hint == static_cast<int>(playerHints::AMATEUR)))
    {
        std::cout << attack::OPEN_DIRTY;
        recording(attack::OPEN_DIRTY);
    }
    else if (player.teamSpirit >= static_cast<int>(spirit::GOD_SPIRIT) && (menu::hint == static_cast<int>(playerHints::AMATEUR)))
    {
        std::cout << attack::OPEN_HAND;
        recording(attack::OPEN_HAND);
    }
    attackShot(player.shot, player.teamSpirit);




    std::cout << "\n";
    while (player.shot == static_cast<int>(defense::CHOICE_DEFENSE))
    {
        if (player.shot == static_cast<int>(defense::CHOICE_DEFENSE))
        {
            std::cout << defend::QUESTION_DEFENSE;
            recording(defend::QUESTION_DEFENSE);
            choiceDefense(player.defense);
            attackShot(player.shot, player.teamSpirit);
        }
    }


    if (player.shot == static_cast<int>(shots::THREE_POINT_SHOT))
    {
        //Шанс трехочкового 40% - базовый
        std::cout << attack::THREE_POINT;
        recording(attack::THREE_POINT);
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (opponent.defense)
        {
        case static_cast<int>(defense::PRESSING):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
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
    if (player.shot == static_cast<int>(shots::MEDIUM_SHOT))
    {
        //Шанс двухочкового 50% - базовый
        std::cout << attack::MEDIUM_SHOT;
        recording(attack::MEDIUM_SHOT);
        probabilityHitPlayer(player.hit, player.teamSpirit);
        switch (opponent.defense)
        {
        case static_cast<int>(defense::PRESSING):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
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
    if (player.shot == static_cast<int>(shots::LAY_UP_SHOT))
    {
        //Шанс лэй - аппа 60% - базовый
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
        case static_cast<int>(defense::PRESSING):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
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
    if (player.shot == static_cast<int>(shots::COMBINATIONT_SHOT))
    {
        //Шанс комбинации 55% - базовый
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
        case static_cast<int>(defense::PRESSING):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
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
                player.teamSpirit += static_cast<int>(spirit::MORE_POINT);
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
    if (player.shot == static_cast<int>(shots::DIRTY_SHOT) && player.teamSpirit <= static_cast<int>(spirit::DIRTY_SPIRIT))
    {
        if (test::testingEnabled)
        {
            std::cout << test::TEST_DIRTY;
            recording(test::TEST_DIRTY);
        }
        player.probalityDirtyGame = rand() % engine::HIGH_RAND + engine::ONE_UP;
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
    if (player.shot == static_cast<int>(shots::HAND_GOD_SHOT) && player.teamSpirit >= static_cast<int>(spirit::GOD_SPIRIT))
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
    if (player.defense == static_cast<int>(defense::NONE_DEFENSE))
    {
        defend::fatigue--;
        if (defend::fatigue < engine::ZERO)
        {
            defend::fatigue = engine::ZERO;
        }
    }
    if (defend::fatigue == defend::SEVERE_FATIGUE)
    {
        player.defense = static_cast<int>(defense::NONE_DEFENSE);
        std::cout << defend::RELAX;
    }
    if (player.defense == static_cast<int>(defense::PRESSING))
    {
        defend::fatigue++;
    }
    showDefense(player.defense, player.name);


    opponent.shot = rand() % engine::FOUR + engine::ONE_UP;
    std::cout << opponent.name;
    recording(opponent.name);
    std::cout << attack::IN_ATTACK;
    recording(attack::IN_ATTACK);
    opponent.probalityDirtyGame = rand() % engine::HIGH_RAND + engine::ONE_UP;
    if ((player.score - opponent.score >= opponent.DIRTY_DEEP) && opponent.probalityDirtyGame > opponent.PROCENT_DIRTY_GAME)
    {
        if (opponent.probalityDirtyGame >= opponent.PROCENT_DIRTY_GAME)
        {
            std::cout << attack::ADD_DIRTY;
            recording(attack::ADD_DIRTY);
            opponent.score += engine::THREE_POINT;
            score(player.score, opponent.score);
            player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
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
    if (opponent.shot == static_cast<int>(shots::THREE_POINT_SHOT))
    {
        //Шанс трехочкового 40% - базовый
        std::cout << attack::THREE_POINT;
        recording(attack::THREE_POINT);
        probabilityHitOpponent(opponent.hit, opponent.teamSpiritOpponent);
        switch (player.defense)
        {
        case static_cast<int>(defense::PRESSING):
            if (opponent.hit > engine::THREE_POINT_AND_PRESSING)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
            if (opponent.hit > engine::LAY_UP_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
            if (opponent.hit > engine::THREE_POINT_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
            if (opponent.hit > engine::THREE_POINT_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_THREE;
                recording(attack::ADD_THREE);
                opponent.score += engine::THREE_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
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
    if (opponent.shot == static_cast<int>(shots::MEDIUM_SHOT))
    {
        //Шанс двухочкового 50% - базовый
        std::cout << attack::MEDIUM_SHOT;
        recording(attack::MEDIUM_SHOT);
        probabilityHitOpponent(opponent.hit, opponent.teamSpiritOpponent);
        switch (player.defense)
        {
        case static_cast<int>(defense::PRESSING):
            if (opponent.hit > engine::MEDIUM_SHOT_AND_PRESSING)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
            if (opponent.hit > engine::MEDIUM_SHOT_AND_PERSONAL_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
            if (opponent.hit > engine::MEDIUM_SHOT_AND_ZONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
            if (opponent.hit > engine::MEDIUM_SHOT_AND_NONE_DEFENSE)
            {
                std::cout << attack::ADD_TWO;
                recording(attack::ADD_TWO);
                opponent.score += engine::TWO_POINT;
                score(player.score, opponent.score);
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
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
    if (opponent.shot == static_cast<int>(shots::LAY_UP_SHOT))
    {
        //Шанс лэй - аппа 60% - базовый
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
        case static_cast<int>(defense::PRESSING):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
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
    if (opponent.shot == static_cast<int>(shots::COMBINATIONT_SHOT))
    {
        //Шанс комбинации 55% - базовый
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
        case static_cast<int>(defense::PRESSING):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::PERSONAL_DEFENSE):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::ZONE_DEFENSE):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
                return true;
            }
            else
            {
                std::cout << attack::LOSE_SHOT;
                recording(attack::LOSE_SHOT);
                return false;
            }
        case static_cast<int>(defense::NONE_DEFENSE):
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
                player.teamSpirit -= static_cast<int>(spirit::MORE_POINT);
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
    engine::probalityRebound = rand() % engine::HIGH_RAND + engine::ONE_UP;
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
        if (menu::jump == static_cast<int>(posessionBall::PLAYER_BALL))
        {
            if (!playerAttack(player, opponent))
            {
                switchDefenseOpponent(player, opponent);
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
                switchDefenseOpponent(player, opponent);
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
        else if (menu::jump == static_cast<int>(posessionBall::OPPONENT_BALL))
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
                switchDefenseOpponent(player, opponent);
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
                switchDefenseOpponent(player, opponent);
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

void switchDefenseOpponent(const Player& player, Opponent& opponent)
{
    if ((opponent.defense == static_cast<int>(defense::PRESSING)) && (player.score - opponent.score < opponent.DIRTY_DEEP))
    {
        choiceDefenseOpponent(opponent.defense);
    }
    if (player.score - opponent.score >= opponent.DIRTY_DEEP)
    {
        opponent.defense = static_cast<int>(defense::PRESSING);
    }
    else if (opponent.score - player.score >= opponent.DIRTY_DEEP)
    {
        opponent.defense = static_cast<int>(defense::NONE_DEFENSE);
    }
    switch (player.shot)
    {
    case static_cast<int>(shots::THREE_POINT_SHOT):
    case static_cast<int>(shots::COMBINATIONT_SHOT):
        if (engine::countZoneDefense == engine::SWITCH_DEFENSE)
        {
            opponent.defense = static_cast<int>(defense::ZONE_DEFENSE);
            engine::countZoneDefense = engine::ZERO;
            break;
        }
        engine::countZoneDefense += engine::ONE_UP;
        engine::countPersonalDefense = engine::ZERO;
        break;

    case static_cast<int>(shots::MEDIUM_SHOT):
    case static_cast<int>(shots::LAY_UP_SHOT):
        if (engine::countPersonalDefense == engine::SWITCH_DEFENSE)
        {
            opponent.defense = static_cast<int>(defense::PERSONAL_DEFENSE);
            engine::countPersonalDefense = engine::ZERO;
            break;
        }
        engine::countPersonalDefense += engine::ONE_UP;
        engine::countZoneDefense = engine::ZERO;
        break;
    }
}

void showDefense(int defense, std::string name)
{
    switch (defense)
    {
    case static_cast<int>(defense::PRESSING):
        std::cout << defend::DEFENSE_TACTICS;
        recording(defend::DEFENSE_TACTICS);
        std::cout << name;
        recording(name);
        std::cout << defend::PRESSING_OPPONENT;
        recording(defend::PRESSING_OPPONENT);
        break;
    case static_cast<int>(defense::PERSONAL_DEFENSE):
        std::cout << defend::DEFENSE_TACTICS;
        recording(defend::DEFENSE_TACTICS);
        std::cout << name;
        recording(name);
        std::cout << defend::PERSONAL_OPPONENT;
        recording(defend::PERSONAL_OPPONENT);
        break;
    case static_cast<int>(defense::ZONE_DEFENSE):
        std::cout << defend::TEAM_OPPONENT;
        recording(defend::TEAM_OPPONENT);
        std::cout << name;
        recording(name);
        std::cout << defend::ZONE_OPPONENT;
        recording(defend::ZONE_OPPONENT);
        break;
    case static_cast<int>(defense::NONE_DEFENSE):
        if (name == history::PLAYER_TEAM_NAME && defend::fatigue > engine::ZERO)
        {
            std::cout << defend::TEAM_OPPONENT;
            recording(defend::TEAM_OPPONENT);
            std::cout << name;
            recording(name);
            std::cout << defend::PLAYER_FATIGUE;
            recording(defend::PLAYER_FATIGUE);
            break;
        }
        else if (name == history::PLAYER_TEAM_NAME)
        {
            std::cout << defend::TEAM_OPPONENT;
            recording(defend::TEAM_OPPONENT);
            std::cout << name;
            recording(name);
            std::cout << defend::PLAYER_RELAX;
            recording(defend::PLAYER_RELAX);
            break;
        }
        else
        {
            std::cout << defend::TEAM_OPPONENT;
            recording(defend::TEAM_OPPONENT);
            std::cout << name;
            recording(name);
            std::cout << defend::NONE_DEFENSE_OPPONENT;
            recording(defend::NONE_DEFENSE_OPPONENT);
            break;
        }
    }
}

void situationOne(int& teamSpirit)
{
    Situation situation{};

    situation.scene =
        "Ты и твой товарищ по команде и закадычный приятель Билли Уортингтон направлялись к автобусной остановке,\n"
        "горячо обсуждая предстоящую завтра игру.\n"
        "Вдруг сздади раздался оклик, вы обернулись и увидели Кэти Гринхаус.\n"
        "При виде девушки Билли разулыбался, он давно мечтал за ней приударить, но всё не мог найти повода подойти,\n"
        "так как при всей своей внешней напористости был довольно застенчивым парнем.\n"
        "— Послушай,— обратилась к тебе Кэти, одарив, впрочем, Билли лёгкой ответной улыбкой,\n"
        "— У вас же завтра игра, верно? — Да,— отозвался ты. — Отлично!,— обрадовалась девушка.\n"
        "— Вы ведь будете не против, если мы вас поддержим?\n"
        "— Поддержка — это здорово! Но кто это мы?\n"
        "— Как это— кто!— Кэти взметнула брови. — Я и моя новая команда. Ну так что, ты согласен?\n"
        "Тут тебе всё стало ясно.\n"
        "Кэти страстно увлекалась черлидингом и мечтала когда - нибудь выиграть чемпионат мира по этому виду спорта,\n"
        "так что не упускала возможности попрактиковаться в выступлениях, и, надо сказать, показывала неплохие результаты.\n"
        "Проблема была только в одном, феноменальной нестабильности их представлений.\n"
        "У Кэти и её девочек получались либо совершенно феерические шоу, заряжающие всех вокруг бешеной энергией и позитивом,\n"
        "либо оглушительные провалы, в результате которых частенько калечились не только сами спортсменки,\n"
        "но и обычные зрители, а пару раз доставалось даже игрокам.\n"
        "После недавнего, не очень удачного,  выступления команда Кэти разбежалась, и ей пришлось собирать новый состав,\n"
        "так что, если ты согласишься, это будет их первым выступлением.\n"
        "Билли незаметно, как ему кажется, толкает тебя локтем, призывая согласиться, но решать тебе.\n\n";
    std::cout << situation.scene;
    recording(situation.scene);
    system("pause");
    system("cls");

    situation.choice = "Как же мне поступить?\n1. Принять предложение Кэти.\n2. Отказаться от предложения Кэти.\nРешай: ";
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

    situation.probalityVictory = rand() % engine::HIGH_RAND + engine::ONE_UP;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\nУСПЕХ!\n\n"
            "Кэти и её команда начали работать незадолго до начала матча, и судя по этим первым минутам,\n"
            "дальше будет только круче.\n"
            "Девушки показали чудеса грации и слаженности, не забывая при этом не только подбадривать,\n"
            "но и подначивать ребят.\n"
            "Теперь вы просто не имеете права облажаться.\n\n";
        std::cout << situation.riscVictory;
        recording(situation.riscVictory);
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (teamSpirit > static_cast<int>(spirit::MAX_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MAX_SPIRIT);
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
            "\nНЕУДАЧА!\n\n"
            "Кэти и её команда приступили к работе незадолго до начала матча,\n"
            "и с первых минут всё пошло наперекосяк.\n"
            "Одна из девушек подвернула ногу, и пирамида из спортсменок рассыпалась,\n"
            "к счастью, обошлось без серьёзных травм,\n"
            "но  продолжать выступление подругам запретили.\n"
            "Оставшись без поддержки, члены вашей команды, особенно Уортингтон, повесили носы,\n"
            "так что тебе придётся постараться, чтобы расшевелить их.\n\n";
        std::cout << situation.riscFail;
        recording(situation.riscFail);
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
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
            "Услышав отказ, Кэти холодно попрощалась, пожелала удачи в завтрашней игре и быстрым шагом двинулась прочь.\n"
            "Билли окликнул её, но девушка не оглянулась.\n"
            "Едва она скрылась из виду, Уортингтон набросился на тебя с упрёками.\n"
            "— Ты должен был дать ей шанс!, видишь ведь, для неё это важно?!\n"
            "— Ей или тебе? — ты не смог удержаться от улыбки.\n"
            "— Ей!— взвился парень. — Ну и мне, конечно, тоже, — смущённо закончил он, понимая всю очевидность ситуации.\n"
            "— Я бы рад!, но ты же знаешь везучесть Кэти, а если они не справятся, в проигрыше будут все,\n"
            "— попытался ты обьяснить свою позицию.\n"
            "Хотя, по правде сказать, тебя здорово мучила совесть. \n"
            "Кэти ведь искренне хотела помочь, да и ребятам без поддержки будет несладко,\n"
            "особенно если у противника недостатка в мотивации не будет.\n"
            "— Да всё я понимаю, — хмуро пробормотал Билли. Дальше вы шли молча.\n\n";
        std::cout << situation.riscNone;
        recording(situation.riscNone);
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
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
        "С уроками на сегодня покончено. ты закрыл крышку ноутбука и откинулся на спинку кресла,\n"
        "надо придумать, чем занять вечер.\n"
        "В кармане завибрировал смартфон, снова спам, на этот раз от сервиса знакомств.\n"
        "Ты задумчиво крутил телефон в руке, реклама направила твои мысли на путь, которого ты избегал вот уже три месяца.\n"
        "Алисон, светловолосая смешливая девчонка, частенько присутствовала на выступлениях вашей команды, однако,\n"
        "ваше общение не выходило за рамки дружеского, иногда с намёком на лёгкий флирт,\n"
        "так что девушка вряд-ли догадывалась, что ты пламенно в неё влюблён.\n"
        "Быть может, эта сообщение — знак свыше, и стоит пригласить, наконец, Алисон на свидание?\n"
        "Ты нашёл в контактах номер, и задумался: а вдруг она откажет, или согласится, а потом что то пойдёт не так?\n";
    std::cout << situation.scene;
    recording(situation.scene);
    system("pause");
    system("cls");

    situation.choice = "Как же мне поступить?\n1. Позвонить Алисон.\n2. Не звонить, вдруг ничего не получится.\nРешай: ";
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

    situation.probalityVictory = rand() % engine::HIGH_RAND + engine::ONE_UP;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\nУСПЕХ!\n\n"
            "Иногда стоит доверять знакам!\n"
            "Пиццерия, в которую ты пригласил девушку, конечно, не ресторан,\n"
            "но Алисон выглядела вполне довольной, да и с букетом ты угадал.\n"
            "У вас оказалос сотня общих тем для разговора, ты пригласил её на завтрашнюю игру, она обещала прийти,\n"
            "а когда вы прощались, даже разрешила себя поцеловать.\n"
            "Так что домой ты летел, как на крыльях, думая, что завтра вы должны оставить от соперников только мокрое место!\n";
        std::cout << situation.riscVictory;
        recording(situation.riscVictory);
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (teamSpirit > static_cast<int>(spirit::MAX_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MAX_SPIRIT);
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
            "\nНЕУДАЧА!\n\n"
            "Вот и верь знакам после такого!\n"
            "Ты с досады швырнул телефон на кровать.\n"
            "Алисон согласилась прогуляться, но ты сразу заметил, что с ней что-то-не так.\n"
            "Обычно живая и весёлая, сегодня она была молчалива.\n"
            "Когда же тебе удалось разговорить девушку, выяснилось, что её отец вынужден был сменить работу,\n"
            "из-за чего им придётся переехать куда-то в Африку, где беда не то, что с интернетом,\n"
            "там даже электричество и вода есть не всегда.\n"
            "Алисон сказала,что, возможно, ей удастся приехать на будущий год, но тебе показалось,\n"
            "что она и сама не слишком верит в это.\n"
            "Быть может, тебе стоило признаться в своих чувствах раньше, хотя, что бы это изменило?\n"
            "Ты пригласил девушку на завтрашний матч, но она ответила, что у неё много дел из-за переезда.\n"
            "Нужно было подготовиться, продумать тактику игры, но настроения не было, так что ты решил лечь спать.\n";
        std::cout << situation.riscFail;
        recording(situation.riscFail);
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
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
            "Мысленно обозвав себя трусом, ты всё же отложил телефон.\n"
            "Ты попытался переключиться на предстоящую завтра игру,\n"
            "но мысли снова и снова возвращались к Алисон.\n"
            "Ты проснулся с головной болью, так как заснуть удалось лишь под утро.\n";
        std::cout << situation.riscNone;
        recording(situation.riscNone);
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
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
        "Лежащий на столе смартфон издал короткую трель.\n"
        "Ты решил воспользоваться поводом сделать перерыв и, отложив учебник, взглянул на экран.\n"
        "— Кэп, ты где? Все уже собрались, — гласило сообщение.\n"
        "Ты хлопнул себя по лбу.\n"
        "Договорились ведь, что тренировка сегодня пройдёт на два часа раньше, так как в зале,\n"
        "где вы с командой тренируетесь, должны были проводить какое-то мероприятие.\n"
        "Зал принадлежал отцу одного из ребят, так что платить за аренду было не нужно,\n"
        "что всех чрезвычайно радовало, но сегодня это превратилось в проблему, по крайней мере, для тебя.\n"
        "Дело  в том, что ты самым дурацким образом не успел выполнить задание, которое сдать нужно, вот сюрприз, уже завтра.\n"
        "Теперь тебе придётся выбирать, пойти на тренировку, а потом надеяться,\n"
        "что кто-нибудь из ребят даст списать, либо же остаться дома и основательно подготовиться.\n"
        "Но в этом случае ребята обоснованно обидятся, что повлияет на климат в команде.\n";
    std::cout << situation.scene;
    recording(situation.scene);
    system("pause");
    system("cls");

    situation.choice = "Как же мне поступить?\n1. Поехать на тренировку.\n2. Остаться дома и подготовится.\nРешай: ";
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

    situation.probalityVictory = rand() % engine::HIGH_RAND + engine::ONE_UP;

    if (situation.playerChoice == situation.ACTION && situation.probalityVictory >= history::PROBALITY_WIN)
    {
        situation.riscVictory =
            "\nУСПЕХ!\n\n"
            "Всё-таки ты везучий!\n"
            "Ребята хоть и прикалывались над твоей забывчивостью, но тренировка прошла на ура,\n"
            "так что команда сыграет слаженно, как машина, даже если парней разбудить посреди ночи.\n"
            "С учёбой тоже всё разрешилось наилучшим образом.\n"
            "Твой приятель Джейкоб не только поделился материалом,\n"
            "но и растолковал парочку непонятных моментов, так что проблем быть не должно.\n";
        std::cout << situation.riscVictory;
        recording(situation.riscVictory);
        teamSpirit += history::ADD_SPIRIT_VICTORY;
        if (teamSpirit > static_cast<int>(spirit::MAX_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MAX_SPIRIT);
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
            "\nНЕУДАЧА!\n\n"
            "Не везёт так не везёт!\n"
            "Решив всё же отправиться на тренировку, ты попал в пробку.\n"
            "Время занятий пришлось сократить, и к моменту,\n"
            "когда нужно было освобождать зал, вы не проработали и половины запланированного.\n"
            "Кроме того, ты повздорил с Джейкобом, парнем, который мог бы помочь тебе с уроками,\n"
            "так что теперь придётся выкручиваться самому.\n";
        std::cout << situation.riscFail;
        recording(situation.riscFail);
        teamSpirit += history::REM_SPIRIT_FAIL;
        if (teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
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
            "Ты всё же решил остаться дома и как следует  подготовиться.\n"
            "Ребята повозмущались немного в общем чате, но в целом отнеслись к ситуации  с пониманием.\n"
            "Ты накидал текстом, что именно им нужно отработать к следующей игре,\n"
            "конечно, вживую было бы лучше, ну да ничего, должны справиться.\n";
        std::cout << situation.riscNone;
        recording(situation.riscNone);
        teamSpirit += history::NONE_RISC_SPIRIT;
        if (teamSpirit < static_cast<int>(spirit::MIN_SPIRIT))
        {
            teamSpirit = static_cast<int>(spirit::MIN_SPIRIT);
        }
        std::cout << history::YOUR_TEAM_SPIRIT;
        recording(history::YOUR_TEAM_SPIRIT);
        std::cout << teamSpirit << std::endl;
        recording(teamSpirit);
        system("pause");
        system("cls");
    }

}