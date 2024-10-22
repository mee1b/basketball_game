#pragma once
std::ofstream record;
extern void recording(std::string comment);
extern void recording(int comment);
extern void userComment(std::string userText, std::string gameText, int& userChoice);
extern void userComment(std::string gameText, std::string& userChoice);
extern void hints();
extern void author();
extern void gameRules();
extern void deleteName(std::vector<std::string>& namesTeamOpponent, int choiceTeamName);
