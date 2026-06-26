#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int hasLockpick = 0;
int hasRustyKey = 0;

int main() {
  srand(time(NULL));
  cout << "Your target is to beat the monster at the end of the game. Start to gather items now!\n\n";
  Sleep(3500);
  cout << "Where do you want to go? (Type in the number)\n\n";
  cout << "1. Locked Room\n2. Long Corridor\n3. Room 13\n4. Treasure Room\n5. Search your cell\n\n";
  int ans1;
  cin >> ans1;

  switch (ans1){
    case 1:
      if(hasRustyKey == 1){
        cout << "You have unlocked the Rusty Room!";
      }
      else{
        cout << "You need a rusty key to unlock this door!";
      }
      break;

      case 2:
      cout << "You are in the Long Corridor";
      break;

      case 3:
        cout << "You have entered Room 13...";
        break;

      case 4:
        cout << "You are in the Treasure Room!";
        break;
      
      case 5:
      int random = 1 + rand() % 3;
        cout << "You have searched your cell, and found " << random << " pieces of scrap metal! What could you use it for?";
        break;
  }
}