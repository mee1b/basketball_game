#pragma once
namespace test
{
    bool testingEnabled{};
    const std::string TESTING_ENABLED = "����� ������������ �������!\n";
    const std::string CHOICE_TEAM_SPIRIT = "\n�������� ����:\n�������� ������� ���������� ���� �� -10 �� 10: ";
    const std::string CHOICE_SCENE = "�������� ���� ���-����� ������� �� 1 �� 3.\n���-����� �����: ";
    const std::string NONE_SCENE = "������� � ���� ��� ���-����!\n";
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
    const int ONE_GAME{ 2 };
    const int TOURNAMENT{ 3 };
    const int AUTHOR_GAME{ 4 };
    const int EXIT_GAME{ 5 };
    std::string rules =
        "��� ������������� ���� �������� �������."
        "�� ������ ��������� � ������������ ����� �������.\n"
        "���� ������ 2 ����� �� 8 �����. ���� ����� ������ 24 �������.\n\n";
    std::string rulesShot =
        "����� ������ ��������� �������:\n"
        "1. ������� (�����������) ������ � ������;\n2. ������� (�����������) ������ � ������;\n3. ��� - ��� (��� ����);\n4. ���������� � ������ (��� ����);\n\n"
        "�� ��������� ������:\n1. ������.\n2. ��������� ���.\n\n"
        "����������� ��������� ��� ��� - ���� ��� ���������� ����, ��� ��� ������� � ������� ������,\n�� �� ����� �� ���������� ������������� ������� ����� ������� �������� ��� ����-���."
        "��� ����� ����������� ��������� ������� �������������,\n� �������� ��� ��� ������ ��� � ��� ����������!\n\n"
        "��������� ��� ����� ��� �������(�������� ����� � �������� �������� ��������� �������� �������),\n��� � ��������(������ ����� ��� ���������� ���������).\n"
        "��� ������������ ������� ���������� ����(+10) ����������� ��������� \"���� ����\",\n������� ����������� 100% ��������� � ����������� �����,\n"
        "�� ��, ��� ��, ������ ��� ������ ���������� ����.\n"
        "��� ����������� ��������� ���� (-10) ����������� ��������� \"������� ����\",\n������� � ��������� ������������ ����� �������� ��� ����,\n"
        "�� ���� ���������, ���� ���� ����������� ����, ��� ����� ������� ��� � �������� ��������� ��������,\n��� ���� ��� ���� ����.\n"
        "\"������� ����\" ����� �������� � ����������, ���� �� �������� ����������� ���� �� ������������ ��������,\n�� ���� ��������� �� �� �����������.\n\n";
    std::string rulesDefense =
        "������������ ������ ���� - ������. ������� �� � ����, ����� ����������� ��� ���� ������� � �������.\n����������� ����� �� ���, ����� ������ ���������� ���������!\n\n"
        "����� �������� ������ �� ����� �����, ������ ������� 0 � �������� ���������� ������.\n\n"
        "������� ����� ��������� �������:\n"
        "1. �������� - ����������� ������ (���� ���� ������� ������ �� 10%), �� ���� ��������, ���� ����� ���� ����� � ��������� ������� ������\n"
        "� ��������� ��� ����� ���������, ������� ����� � ��������� \"��� ������\", ����� ������������ ����!\n"
        "2. ������ ����� - �������� ������ �� ������� � ������� ������� (���� �������� �������� ������ � ��� - ���� -20%),\n"
        "�� ����������� �������� ������� ��� ������� ������� � ���������� (���� �������� �������� ������ � ���������� + 10 %);\n"
        "3. ������ ������ - �������� ������ �� ������� ������� � ���������� (���� �������� �������� ������ � ���������� -20%),\n"
        "�� ����������� �������� ������� ��� ��� - ����� � ������� ������� (���� �������� ��� - ���� � ������� ������� + 10%);\n"
        "4. ��� ������ - ������� �������� � ������ (���������� ���� ������� ���������� ���� ������� +10%);\n"
        "��������� ����� ������ ���� ������ � ����������� �� �������, ������� �� �������!\n"
        "�� ����� ����� ������������ ������ ����������, � ��� ����� ���������� ������������ ������ ������.\n\n";
    const std::string REPEAT = "�� �������!\n���� �����: ";
    const std::string OPPONENT_NAME_CHOICE = "������� ������� Enter ��� ������������ �������� ����������, ���\n������� �������� ������� ����������: ";
    const std::string START_DEFENSE = "����� ��������� ������� �����...";
    const std::string WIN_BALL_JUMP = "����� ����������� ��� ����� � ����������� ����� �...\n����������� ���������� �������: ";
    const std::string TIMEOUT = "\n������ �������, ������ ������� ����� �� �������!\n��������� ����� ��������� �����!\n\n";
    const std::string SECOND_TIME = "���������� ������ ����! �������!!!\n\n";
    const std::string FINAL = "��������� ������� ����� �������! ����� ��� �������!\n��������� ���� �� �����:\n";
    const std::string HOORAY = "����������� � ������� ������� ";
    const std::string DRAW = "������� ���������� �� �������, �� � ��������� ��� ������� ����������!\n\n";
    const std::string WELCOME = "����� ���������� � ���� \"���������\"\n";
    const std::string START_MENU = "1. ������� ����.\n2. ������ ����.\n3. ����� �������.\n4. �� ������.\n5. ����� �� ����.\n\n��� ����������� �������� ��������: ";
    const std::string CHOICE_HINT = "�������� ����� ���������:\n1.�������(��� ���������).\n2.��������(��������� ���������� �� ������� �������)\n\n���� �����: ";
    const std::string AUTHOR = "������ ���������� ��� Dialas ������������.\n�����: ���������� ���� (���: mee1b).\n������: 2.1.0\n\n";
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
    const int ALL_TOURNAMENT_TEAM{ 8 };
    const int HIGH_RAND{ 100 };
    const int FOUR{ 4 };
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
    const std::string YOUR_TEAM_SPIRIT = "\n��������� ��� ����� ";
    const std::string STANDART_OPPONENT_NAME = "������� ��������";
    const std::string PLAYER_TEAM_NAME = "������� �������";
    const std::string LOSE_TOURNAMENT = "� ���������, �� �������� ������.\n�� �� ����� ���! ���� ������ �� ���������!\n����� � ��������� ���!";
    const std::string DRAW_TOURNAMENT = "� ���������, �� �������� ������. ��-�� �������� ���������� ������ �� ������� �����.\n�� �� ����� ���! ���� ������ �� ���������!\n����� � ��������� ���!";
    const std::string WIN_TOURNAMENT = "��� �� �������!!!\n������� ��� ���� ����� ������ � ���� �����!\n����� ������ ���� � ����� ���������!\n������ �� ���, �� ����� ������������� ����! ������� ���� ����� ������!!!";
    const std::string FIRST_GAME = "������ ���� ������� ������ ������� ";
    const std::string SECOND_GAME = "��������� ������� ������ ������� ";
    const std::string LAST_GAME = "��������� ���� ������� ������ ������� ";
}

namespace attack
{
    const std::string SHOT_CHOICE = "�������! ����� ������ ������ � ���� �����? ";
    const std::string SHOT_CHOICE_AND_HINT = "�������! ����� ������ ������ � ���� �����? (����� ���������� ���� �������, ����� 5): ";
    const std::string SUPERPOWER_HINT = "���� ��������� ��� ����� -10 ��� ������:\n6.������� ���� (��� ����, ���� 10 � ���������� ����).\n���� ��������� ��� ����� 10 ��� ������:\n7.���� ���� (��� ����, ���� 10 � ���������� ����).\n\n";
    const std::string UNKNOW_TACTICS = "�� ����������� �� �� ��������� ����� ������, �������!\n����� ������� ��, ��� �� ��� �����!\n";
    const std::string OPEN_DIRTY = "6.��������� ��� ������, ������ ���� \"������� ����\".\n";
    const std::string OPEN_HAND = "7.��������� ��� �� �������, ������ ���� \"���� ����\".\n";
    const std::string THREE_POINT = "����������� ������!!!\n";
    const std::string ADD_THREE = "��� ���� � �������!!!\n";
    const std::string LOSE_SHOT = "������! ��� � �������, ��� �� �� ���������?\n";
    const std::string MEDIUM_SHOT = "������� ������!!!\n";
    const std::string ADD_TWO = "��� ���� � �������!!!\n";
    const std::string LAY_UP = "��� �� ���-��!!!\n";
    const std::string COMBINATION = "��������, ������ ����������� ����������!!!\n";
    const std::string ADD_HAND = "����� ���������� ������!!!\n�� ������, � ����������.\n��� ���� � �������!\n\n";
    const std::string RESET_HAND = "��� ��� ������������ ������!\n�� ������ �� ����� ����� ��� � �������, ����� ��������� ������� ������� ����� ���������!\n\n";
    const std::string ADD_DIRTY = "��� �� ���!!!\n�� ����� ������ �� �����.\n��� ���� � �������!\n\n";
    const std::string FAIL_DIRTY = "��� �� ���!!!\n����� ��������� �������� ������ � ������ ������� ";
    const std::string REALESE_DIRTY_PENALTY = " ��������� �������� ������!\n\n";
    const std::string IN_ATTACK = " � �����:\n";
    const std::string REBOUND_IN_ATTACK = "\n������ � ����� �� ��������: ";
    const std::string STEAL_GOOD = "��� ����������!\n\n��� �������� ������� ";
    const std::string BLOCK_GOOD = "��� ��� ����-���!\n\n��� �������� ������� ";
    bool steal{ false };
    bool block{ false };

}

namespace defend
{
    const std::string SHOW_HINT = "(����� ���������� ����� ������ ����� 5.)";
    const std::string QUESTION_DEFENSE = "����� ����� ���� ������? ";
    const std::string UNKNOW_TACTICS = "�� ����������� �� �� ��������� ��� �����, �������!\n����� ������� ��, ��� �� ��� �����!\n";
    const std::string REBOUND_IN_DEFENSE = "\n������ � ������ �� ��������: ";
    const std::string DEFENSE_TACTICS = "������ ������� ";
    const std::string PRESSING_OPPONENT = " - ��������\n";
    const std::string PERSONAL_OPPONENT = " - ������ �����\n";
    const std::string TEAM_OPPONENT = "������� ";
    const std::string ZONE_OPPONENT = " ������ ������ ������\n";
    const std::string NONE_DEFENSE_OPPONENT = " ������������ - � ��� ��� ������\n";
    const std::string PLAYER_FATIGUE = " ������ �� ���������, ������ � ��� ��� ������!\n";
    const std::string PLAYER_RELAX = " �� ���� ���, ����� ����� ���������� � ���� � ������?!\n";
    const std::string RELAX = "\n�������, ������� ������ ������ � ���������!\n����� �����!\n\n";
    int fatigue = 0;
    const int SEVERE_FATIGUE = 2;
}