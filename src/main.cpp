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
    const std::string TESTING_ENABLED = "РЕЖИМ ТЕСТИРОВЩИКА ВКЛЮЧЕН!\n";
    const std::string CHOICE_TEAM_SPIRIT = "\nТЕСТОВОЕ МЕНЮ:\nВыберите уровень командного духа от -10 до 10: ";
    const std::string CHOICE_SCENE = "Выебирте одну одну кат сцену цифрами от 1 до 3.\nКат сцена номер: ";
    const std::string NONE_SCENE = "Переход к игре без кат сцен!\n";
    const std::string TEST_THREE_PRESSING = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 40%.\n2.Защита \"Прессинг\" - (-10%)\n3.Командный дух ";
    const std::string TEST_THREE_PERSONAL_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 40%.\n2.Защита \"Личная опека\" - (+15%)\n3.Командный дух ";
    const std::string TEST_THREE_ZONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 40%.\n2.Защита \"Зонная защита\" - (-10%)\n3.Командный дух ";
    const std::string TEST_THREE_NONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 40%.\n2.Защита \"Нет защиты\" - (+20%)\n3.Командный дух ";
    const std::string TEST_MEDIUM_PRESSING = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 50%.\n2.Защита \"Прессинг\" - (-10%)\n3.Командный дух ";
    const std::string TEST_MEDIUM_PERSONAL_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 50%.\n2.Защита \"Личная опека\" - (-10%)\n3.Командный дух ";
    const std::string TEST_MEDIUM_ZONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 50%.\n2.Защита \"Зонная защита\" - (+15%)\n3.Командный дух ";
    const std::string TEST_MEDIUM_NONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 50%.\n2.Защита \"Нет защиты\" - (+20%)\n3.Командный дух ";
    const std::string TEST_LAY_UP_PRESSING = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 60%.\n2.Защита \"Прессинг\" - (-10%)\n3.Командный дух ";
    const std::string TEST_LAY_UP_PERSONAL_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 60%.\n2.Защита \"Личная опека\" - (-10%)\n3.Командный дух ";
    const std::string TEST_LAY_UP_ZONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 60%.\n2.Защита \"Зонная защита\" - (+15%)\n3.Командный дух ";
    const std::string TEST_LAY_UP_NONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 60%.\n2.Защита \"Нет защиты\" - (+20%)\n3.Командный дух ";
    const std::string TEST_COMBINATION_PRESSING = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 55%.\n2.Защита \"Прессинг\" - (-10%)\n3.Командный дух ";
    const std::string TEST_COMBINATION_PERSONAL_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ : \n1.Базовый шанс - 55 % .\n2.Защита \"Личная опека\" - (+15%)\n3.Командный дух ";
    const std::string TEST_COMBINATION_ZONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 55%.\n2.Защита \"Зонная защита\" - (-10%)\n3.Командный дух ";
    const std::string TEST_COMBINATION_NONE_DEFENSE = "ТЕСТОВОЕ СООБЩЕНИЕ:\n1.Базовый шанс - 55%.\n2.Защита \"ЛНет защиты\" - (+20%)\n3.Командный дух ";
    const std::string TEST_DIRTY = "ТЕСТОВОЕ СООБЩЕНИЕ:\nВероятность попадания 70%\n";
    const std::string TEST_HAND_GOD = "ТЕСТОВОЕ СООБЩЕНИЕ:\nВероятность попадания 100%\n";
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
    const std::string CHOICE_MENU = "Выберите варинат запуска игры:\n1.Тестовый режим.\n2.Режим пользователя.\nВаш выбор: ";
    const std::string REPEAT = "Не понимаю!\nВаш выбор: ";
    const std::string OPPONENT_NAME_CHOICE = "Нажмите клавишу Enter, для стандартного названия противника или\nВведите название команды противника: ";
    const std::string START_DEFENSE = "Вашей стартовой защитой будет...";
    const std::string WIN_BALL_JUMP = "Судья подкидывает мяч вверх в центральном круге и...\nВбрасывание выигрывает команда: ";
    const std::string TIMEOUT = "\nЗвучит свисток, сейчас команды уйдут на перерыв!\nУслышимся после небольшой паузы!\n\n";
    const std::string SECOND_TIME = "Начинается второй тайм! ПОЕХАЛИ!!!\n\n";
    const std::string FINAL = "Последние секунды матча истекли! Судья дает свисток!\nФинальный счет на табло:\n";
    const std::string HOORAY = "Поздравляем с победой команду ";
    const std::string DRAW = "Сегодня победитель не выявлен, но в следующий раз победит сильнейший!\n\n";
    const std::string WELCOME = "Добро пожаловать в игру \"Баскетбол\"\n";
    const std::string START_MENU = "1. Правила игры.\n2. Начать игру.\n3. Режим турнира.\n4. Об авторе.\n5. Выйти из игры.\n\nДля продолжения выберете действие: ";
    const std::string CHOICE_HINT = "Выберите режим подсказок:\n1.Опытный(без подсказок).\n2.Любитель(подсказки появляются по нажатию клавиши)\n3.Новичок(подсказки выводятся всегда)\n\nВаш выбор: ";
    const std::string AUTHOR = "Студия разработки игр Dialas представляет.\nАвтор: Медведенко Егор(ник: mee1b).\nВерсия: 1.0.8.\n\n";
    const std::string TABLO = "Счет: ";
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
    const int PROBALITY_WIN{ 50 }; // 50% шанс победы в событии
    const int ADD_SPIRIT_VICTORY{ 10 };
    const int REM_SPIRIT_FAIL{ -10 };
    const int NONE_RISC_SPIRIT{ -5 };
    const std::string YOUR_TEAM_SPIRIT = "\nВаш командный дух равен ";
    const std::string STANDART_OPPONENT_NAME = "Колледж Оклахомы";
    const std::string PLAYER_TEAM_NAME = "Колледж Алабамы";
}

namespace attack
{
    const std::string SHOT_CHOICE = "Капитан! Какой бросок делаем в этой атаке? ";
    const std::string SHOT_CHOICE_AND_HINT = "Капитан! Какой бросок делаем в этой атаке?(чтобы посмотреть виды бросков нажмите 5): ";
    const std::string SUPERPOWER_HINT = "Если командных дух равен -10 или меньше:\n6.Грязная игра(три очка, плюс 10 к командному духу).\nЕсли командный дух равен 10 или больше:\n7.Рука бога(три очка, плюс 10 к командному духу).\n\n";
    const std::string UNKNOW_TACTICS = "На тренировках мы не разбирали такие броски, капитан!\nДавай сыграем то, что мы уже знаем!\n";
    const std::string OPEN_DIRTY = "6. Ваш командный дух падает, открыт прием \"Грязная игра\".\n";
    const std::string OPEN_HAND = "7. Ваш командный дух на подъёме, открыт прием \"Рука бога\".\n";
    const std::string THREE_POINT = "Трехочковый бросок!!!\n";
    const std::string ADD_THREE = "Три очка в корзине!!!\n";
    const std::string LOSE_SHOT = "Промах! Мяч в воздухе, кто же им завладеет?\n";
    const std::string MEDIUM_SHOT = "Средний бросок!!!\n";
    const std::string ADD_TWO = "Два очка в корзине!!!\n";
    const std::string LAY_UP = "Это же лэй - апп!!!\n";
    const std::string COMBINATION = "Смотрите, игроки разыгрывают комбинацию!!!\n";
    const std::string ADD_HAND = "КАКАЯ ТРАЕКТОРИЯ ПОЛЕТА!!!\nНе бросок, а заглядение.\nТри очка в корзине!\n\n";
    const std::string RESET_HAND = "Это был великолепный бросок!\nНо видимо он отнял много сил у игроков, перед следующим броском команде нужно собраться!\n\n";
    const std::string ADD_DIRTY = "ЭТО ЖЕ ФОЛ!!!\nНо судья ничего не видит.\nТри очка в корзине!\n\n";
    const std::string FAIL_DIRTY = "ЭТО ЖЕ ФОЛ!!!\nСудья назначает штрафной бросок в кольцо команды ";
    const std::string REALESE_DIRTY_PENALTY = " реализует штрафной бросок!\n\n";
    const std::string IN_ATTACK = " в атаке:\n";
    const std::string REBOUND_IN_ATTACK = "\nПодбор в атаке за командой: ";
    const std::string STEAL_GOOD = "Мяч перехвачен!\n\nМяч достается команде ";
    const std::string BLOCK_GOOD = "Вот это БЛОК-ШОТ!\n\nМяч достается команде ";
    bool steal{ false };
    bool block{ false };
    
}

namespace defend
{
    const std::string SHOW_HINT = "(Чтобы посмотреть схемы защиты нажмите 5.)";
    const std::string QUESTION_DEFENSE = "Какой будет наша защита? ";
    const std::string UNKNOW_TACTICS = "На тренировках мы не разбирали эти схемы, капитан!\nДавай сыграем то, что мы уже знаем!\n";
    const std::string REBOUND_IN_DEFENSE = "\nПодбор в защите за командой: ";
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
            std::cout << "К сожалению, ты проиграл турнир.\nНо не вешай нос! Этот турнир не последний!\nУдачи в следующий раз!";
            system("pause");
            return 0;
        case DRAW:
            system("cls");
            std::cout << "К сожалению, ты проиграл турнир. Из-за большого количества ничьюх не хватило очков.\nНо не вешай нос! Этот турнир не последний!\nУдачи в следующий раз!";
            system("pause");
            return 0;
        case PLAYER_WIN:
            std::cout << "Вот он ЧЕМПИОН!!!\nСегодня все поют песни только в твою честь!\nЛюбят только тебя и твоих товарищей!\nМедали на шее, но помни расслабляться рано! Впереди ждут новые победы!!!";
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
    std::vector<std::string> namesTeamOpponent{ "Колледж Чикаго", "Колледж Вашингтона", "Колледж Аляски", "Колледж Огайо", "Далласский колледж", "Колледж Техаса", "Колледж Минесоты", "Колледж Финикса"};

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
            std::cout << "Первая игра турнира против команды " << opponent.name << std::endl;
            break;
        case 2:
            system("cls");
            situationTwo(player.teamSpirit);
            std::cout << "Полуфинал турнира против команды " << opponent.name << std::endl;
            opponent.teamSpiritOpponent += MORE_POINT;
            break;
        case 3:
            system("cls");
            situationThree(player.teamSpirit);
            std::cout << "Финальная игра турнира против команды " << opponent.name << std::endl;
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
    // Объясняет ввод с клавиатуры
    menu::rules =
        "Это баскетбольный клуб колледжа Алабама. "
        "Ты будешь капитаном и плеймейкером нашей команды.\n"
        "Игра длится 2 тайма по 4 минуты. Одна атака длится 24 секунды.\n\n";
    menu::rulesShot =
        "Делайте броски следующим образом:\n"
        "1. Дальний (трехочковый) бросок в прыжке;\n2. Средний (двухочковый) бросок в прыжке;\n3. Лэй - апп (два очка);\n4. Комбинация и бросок (два очка);\n\n"
        "На попадание влияет:\n1. Базовый процент попадания.\n2. Защита.\n3. Командный дух.\n\n"
        "Командный дух можно, как поднять(отличной игрой и успешным решением жизненных вопросов команды).\nТак и потерять(плохой игрой или неудачними решениями).\n\n";
    menu::rulesDefense =
        "Выберите схему следующим образом:\n"
        "1. Прессинг - эффективная защита (шанс всех бросков снижен на 10%);\n"
        "2. Личная опека - отличная защита от средних и ближних бросков (шанс удачного среднего броска и лэй - аппа -20%),\n"
        "но открывается огромный простор для дальних бросков и комбинаций (шанс удачного дальнего броска и комбинаций + 10 %);\n"
        "3. Зонная защита - отличная защита от дальних бросков и комбинаций (шанс удачного дальнего броска и комбинации -20%),\n"
        "но открывается огромный простор для лэй - аппов и средних бросков (шанс удачного лэй - аппа и средних бросков + 10%);\n"
        "4. Нет защиты - команда отдыхает в защите (повышается шанс удачной реализации всех бросков +10%);\n"
        "Противник будет менять свою защиту в зависимости от бросков, которые ты делаешь!\n";
        "Чтобы изменить защиту, просто введите 0 в качестве следующего броска.\n\n";
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
    
    situation.probalityVictory = rand() % 100 + 1;

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

    situation.probalityVictory = rand() % 100 + 1;

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
            "\nНЕУДАЧА!\n\n"
            "Вот и верь знакам после такого!\n"
            "Ты с досады швырнул телефон на кровать.\n"
            "Алисон согласилась прогуляться, но ты сразу заметил, что с ней что-то-не так.\n"
            "Обычно живая и весёлая, сегодня она была молчалива.\n"
            "Когда же тебе удалось разговорить девушку, выяснилось, что её отец вынужден был сменить работу,\n"
            "из-за чего им придётся переехать куда-то в Африку, где беда не то, что с интернетом,\n"
            "там даже электричество и вода есть не всегда.\n";
            "Алисон сказала,что, возможно, ей удастся приехать на будущий год, но тебе показалось,\n"
            "что она и сама не слишком верит в это.\n"
            "Быть может, тебе стоило признаться в своих чувствах раньше, хотя, что бы это изменило?\n"
            "Ты пригласил девушку на завтрашний матч, но она ответила, что у неё много дел из-за переезда.\n"
            "Нужно было подготовиться, продумать тактику игры, но настроения не было, так что ты решил лечь спать.\n";
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
            "Мысленно обозвав себя трусом, ты  всё же отложил телефон.\n"
            "Ты попытался переключиться на предстоящую завтра игру,\n"
            "но мысли снова и снова возвращались к Алисон.\n"
            "Ты проснулся с головной болью, так как заснуть удалось лишь под утро.\n";
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

    situation.probalityVictory = rand() % 100 + 1;

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
            "Ты всё же решил остаться дома и как следует  подготовиться.\n"
            "Ребята повозмущались немного в общем чате, но в целом отнеслись к ситуации  с пониманием.\n"
            "Ты накидал текстом, что именно им нужно отработать к следующей игре,\n"
            "конечно, вживую было бы лучше, ну да ничего, должны справиться.\n";
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
        //Шанс трехочкового 40% - базовый
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
        //Шанс двухочкового 50% - базовый
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
        std::cout << "Защита команды " << opponent.name << " - прессинг\n";
        break;
    case PERSONAL_DEFENSE:
        std::cout << "Защита команды " << opponent.name << " - личная опека\n";
        break;
    case ZONE_DEFENSE:
        std::cout << "Команда " << opponent.name << " играет зонную защиту\n";
        break;
    case NONE_DEFENSE:
        std::cout << "Видимо команда " << opponent.name << " устала - у них нет защиты\n";
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
        //Шанс трехочкового 40% - базовый
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
        //Шанс двухочкового 50% - базовый
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