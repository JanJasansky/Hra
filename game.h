#pragma once

#include <string>

extern int discipline;
extern int reputation;
extern int performance;

void introduction();
void line();
void showStats();
void pauseMenu();
int ctiVolbu(int minimum, int maximum);

extern int currentQuestion;
extern const int totalQuestions;
void showProgress();

void scena1();
void scena2();
void scena3();
void scena4();
void scena5();
