// Author : Velan
// Description : made a Game("Stone-Paper-Scizzor")
// Date : Dec-25-25
// Time : 1.15pm in delhi standard time

// Algorithm
/*
  1.Get input from user as Player
  2.Generate random num as Computer
  3.Propability to check who Win
  4.Greetings
  5.Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char Handle_Input(int Randc);
int Game(char player, char computer);
void Greetings(int point);

int main() {
  int randc;  // Store random num
  char input; // Store user input

  char player, comp; // Both are particiapate

  printf("\n\n\n\t\t\tEnter s for Stone, p for Paper, z for Scizzor\n\n");
  printf("\t\t\t\tHand-shake : ");
  scanf("%c", &input); // Get input from user(Player)

  srand(time(NULL));
  randc = rand() % 100; // Generate Random number less than 100

  comp = Handle_Input(randc);
  player = input;
  printf("\nYou : %c\nComputer : %c", player, comp);
  Greetings(Game(player, comp));

  return 0;
}

// (Game Engine) which is Decide who win
int Game(char player, char computer) {
  if (player == computer) {
    return -1; // Draw
  }
  if (player == 's' && computer == 'z') {
    return 1; // Player Win
  } else if (player == 's' && computer == 'p') {
    return 0; // Player Loose
  }
  if (player == 'p' && computer == 's') {
    return 1; // Player Win
  } else if (player == 'p' && computer == 'z') {
    return 0; // Player Loose
  }
  if (player == 'z' && computer == 'p') {
    return 1; // Player Win
  } else if (player == 'z' && computer == 's') {
    return 0; // Player Loose
  } else {
    return 3;
  }
}

// Handle computer random number to as character input
char Handle_Input(int Randc) {
  if (Randc < 33) {
    return 's';
  } else if (Randc < 66) {
    return 'p';
  } else {
    return 'z';
  }
}

// Greeting System for Player
void Greetings(int point) {
  if (point == 1) {
    printf("\n\n\n\t\t Hurry! You won the Game!");
  } else if (point == 0) {
    printf("\n\n\n\t\t HaHaHa! You Fool lost the Game!");
  } else if (point == -1) {
    printf("\n\n\n\t\t Game Draw! ");
  } else {
    printf("\n\n\n\t\t Something is wrong!!");
  }
}
