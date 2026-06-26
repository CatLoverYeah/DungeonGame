#include <iostream>
#include <windows.h>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

bool hasLockpick = false;
bool hasRustyKey = false;
bool hasDiamondKey = false;
bool hasScrapMetal = false;
bool hasSearchedCell = false;
bool hasWoodenSword = false;
bool hasOpenedRustyRoom = false;
bool hasBeatenSkeleton = false;
int skeletonHP = 100;
int playerHP = 150;
int bowDamage = 25;
int woodenSwordDamage = 35;
int punchDamage = 15;
int howManyScraps = 0;
int howManyLockpicks = 0;

void Rooms();
void Corridor();
void RustyRoom();
void SkeletonFight();
void SkeletonFightCycle();
void DisplaySkeletonHP();
void DisplayPlayerHP();
void Room13();

int main() {
  int tt = 0;
  cout << "Loading";
  int hh = 0;
  while(hh != 3){
    while(tt != 3){
    Sleep(700);
    cout << ".";
    tt++;
    }
    Sleep(700);
    cout << "\b\b\b   \b\b\b";
    tt = 0;
    hh++;
  }
  cout << "\n\n";
  srand(time(NULL));
  cout << "Welcome! Your target is to collect items to help you beat the monster at the end of the game!\n\n";
  Sleep(3000);
  cout << "Where do you want to go? (Type in the number)\n\n";
  Rooms();
}

void Rooms() {
  cout << "1. Locked Rusty Room\n2. Long Corridor\n3. Room 13\n4. Treasure Room\n5. Search your cell\n\n";
  int ans1;
  cin >> ans1;
  switch (ans1){
    case 1:
      if(hasRustyKey == true || hasOpenedRustyRoom == true){
        hasOpenedRustyRoom = true;
        cout << "You have unlocked the Rusty Room!\n\n";
        Sleep(1200);
        RustyRoom();
      }
      else{
        cout << "You need a rusty key to unlock this door! Do you want to use lockpicks?\n\n";
        string ans2;
        cin >> ans2;
        if(ans2 == "Yes" || ans2 == "yes"){
          if(hasLockpick == true){
            cout << "Pick a number from 1-5\n\n";
            int rand1 = 1 + rand() % 5;
            int c;
            cin >> c;
            while(c != rand1){
              cout << "Wrong, try again\n\n";
              howManyLockpicks--;
              if(howManyLockpicks == 0){
                cout << "You ran out of lockpicks, where now?\n\n";
                hasLockpick = false;
                Sleep(700);
                Rooms();
              }
            }
            if(c == rand1){
              hasOpenedRustyRoom = true;
              howManyLockpicks--;
              cout << "You opened the Rusty Room!\n\n";
              RustyRoom();
          }
          }
          else{
            cout << "You do not have any lockpicks yet, where do you want to go?\n\n";
            Sleep(700);
            Rooms();
          }
        }
      }
      break;

      case 2:
      cout << "You are in the Long Corridor\n\n";
      Sleep(1800);
      cout << "Where do you want to go?\n\n";
      Corridor();
      break;

      case 3:
      if(hasBeatenSkeleton == false){
        SkeletonFight();
      }
      else{
        Room13();
      }
        break;

      case 4:
        cout << "You are in the Treasure Room! What now?\n\n";
        cout << "1. Investigate\n2. Go back\n\n";
        int i;
        cin >> i;
        if(i == 1){ // to check if the treasure room will be investigated
          cout << "You have investigated the Treasure Room and found an anvil and a hammer. What could it be used for?\n\n";
          Sleep(2600);
          if(hasScrapMetal == true){ // checks if player has scrap 
            cout << "What now?\n\n1. Make lockpicks\n2. Go back\n\n";
            int w;
            cin >> w;
            if(w == 1){
              if(hasScrapMetal == true){
                cout << "You have " << howManyScraps << " pieces of scrap metal, do you want to make them into lockpicks? (Yes or No)\n\n";
                string e;
                cin >> e;
                if(e == "Yes" || e == "yes"){
                  howManyLockpicks = howManyLockpicks+howManyScraps;
                  howManyScraps = howManyScraps-howManyScraps;
                  cout << "\nPerfect! You now have " << howManyLockpicks << " lockpicks. What now?\n\n1. Go back\n\n";
                  hasLockpick = true;
                  hasScrapMetal = false;
                  int r;
                  cin >> r;
                  if(r == 1){
                    cout << "You are back at your cell! Where now?\n\n";
                    Rooms();
                  }
                }
                else if(e == "No" || e == "no"){
                  cout << "\nSure, no lockpicks, where then?\n\n1. Go back\n\n";
                  int t;
                  cin >> t;
                  if(t == 1){
                    cout << "You are back at your cell! Where now?\n\n";
                    Rooms();
                  }
                }
              }
            }
          }

          else if(hasScrapMetal == false){
            cout << "What now?\n\n1. Go back\n\n";
            int o;
            cin >> o;
            if(o == 1){
              cout << "You are back at your cell! Where now?\n\n";
              Rooms();
            }
          }
        }
        else if(i == 2){
          cout << "You exited the Treasure Room\n\n";
          Rooms();
        }
        break;
      
      case 5:
      if(hasSearchedCell == false){
        int random = 1 + rand() % 3;
        cout << "You have searched your cell, and found " << random << " pieces of scrap metal! What could you use it for?\n\n";
        hasSearchedCell = true;
        hasScrapMetal = true;
        howManyScraps = random;
        Sleep(2700);
        cout << "Where now?\n\n";
        Rooms();
        break;
      }
      else if(hasSearchedCell == true){
        cout << "You have already searched your cell! Where now?\n\n";
        Rooms();
      }
  }
}

void Corridor(){
  cout << "1. Room\n2. Diamond Locked Room\n3. Stairs leading down\n4. Go back\n\n";
  int y;
  cin >> y;
  if(y == 1){
        cout << "Boss fight!";
      }
      else if(y == 2){
        if(hasDiamondKey == true){
          cout << "You have entered the Diamond Room!\n\n";
        }
        else if(hasDiamondKey == false){
          cout << "You do not have the diamond key yet! Where now?\n\n";
          Corridor();
        }
      }
      else if(y == 3){
          cout << "You just went down the stairs...but where will they lead you?\n\n";
          Sleep(2000);
          cout << "You emerged in a dusty room with nothing in it except a table with a drawer...will you look inside?\n\n";
          string m;
          cin >> m;
          if(m == "Yes" || m == "yes"){
            hasRustyKey = true;
            cout << "You opened the drawer and found a rusty key! What will you do?\n\n1. Exit\n\n";
            int f;
            cin >> f;
            if(f == 1){
              cout << "You went back up the stairs, where now?\n\n";
              Corridor();
            }
          }
          else if(m == "No" || m == "no"){
            cout << "You didn't look inside the drawer and went back up the stairs\n\n";
            Corridor();
          }
      }
      else if(y == 4){
        cout << "You exited the Corridor\n\n";
        Sleep(1000);
        Rooms();
      }
}

void RustyRoom() {
  cout << "What do you want to do?\n\n1. Look around\n2. Exit\n\n";
  int u;
  cin >> u;
  if(u == 1){
    cout << "Where do you want to look?\n\n1. On top of the wardrobe\n2. Under the chair\n3. Behind the wardrobe\n\n";
    int d;
    cin >> d;
    if(d == 1){
      cout << "Nothing here, just a flower pot\n\n";
      Sleep(1000);
      RustyRoom();
    }
    else if(d == 2){
      cout << "Nothing there, just some paper\n\n";
      Sleep(1000);
      RustyRoom();
    }
    else if(d == 3){
      hasWoodenSword = true;
      cout << "Congratulations! You found a wooden sword, your first melee weapon!\n\n";
      Sleep(1400);
      RustyRoom();
    }
  }
  else if(u == 2){
    cout << "You are back at your cell!\n\n";
    Rooms();
  }
}

void SkeletonFight() {
  cout << "You have entered Room 13...and met a skeleton with a bow and arrow!\n\n";
  Sleep(1800);
  cout << "FIGHT!\n\n";
  while(playerHP > 0 && skeletonHP > 0){
        Sleep(900);
        DisplayPlayerHP();
        DisplaySkeletonHP();
        Sleep(1800);
        cout << "What will you do?\n\n";
        SkeletonFightCycle();
      }
  if(skeletonHP <= 0){
    hasBeatenSkeleton = true;
    Sleep(1800);
    cout << "You deliver the final blow\n";
    Sleep(1100);
    cout << "and...\n";
    Sleep(1100);
    cout << "And...\n";
    Sleep(1100);
    cout << "AND...\n\n";
    Sleep(1800);
    cout << "Congratulations! You just beat the skeleton, your first enemy! And now also have now gotten his bow and arrow which does " << bowDamage << " damage!\n";
    Sleep(2600);
    cout << "However there will be many more along your way...\n\n";
    Sleep(1800);
    Room13();
  }
  else if(playerHP <= 0){
    Sleep(1800);
    cout << "The skeleton delivers the final blow\n";
    Sleep(1100);
    cout << "and...\n";
    Sleep(1100);
    cout << "And...\n";
    Sleep(1100);
    cout << "AND";
    Sleep(700);
    cout << ".";
    Sleep(700);
    cout << ".";
    Sleep(700);
    cout << ".";
    Sleep(1800);
    cout << "\n\n";
    cout << "You died :)\n\n";
    Sleep(900);
    cout << "Press 1 to restart, press 2 to exit\n\n";
    int hh;
    cin >> hh;
    if(hh == 1){
      bool hasLockpick = false;
      bool hasRustyKey = false;
      bool hasDiamondKey = false;
      bool hasScrapMetal = false;
      bool hasSearchedCell = false;
      bool hasWoodenSword = false;
      bool hasOpenedRustyRoom = false;
      bool hasBeatenSkeleton = false;
      int skeletonHP = 100;
      int playerHP = 150;
      int bowDamage = 25;
      int woodenSwordDamage = 35;
      int punchDamage = 15;
      int howManyScraps = 0;
      int howManyLockpicks = 0;
      main();
    }
  }
}

void DisplayPlayerHP() {
  cout << "Your HP is " << playerHP << "\n";
}

void DisplaySkeletonHP() {
  cout << "Skeleton HP is " << skeletonHP << "\n\n";
}

void SkeletonFightCycle() {
  if(hasWoodenSword == true){
          cout << "You can attack with:\n\n1. Punch\n2. Wooden sword\n\n";
          int h;
          cin >>h;
          if(h == 1){
            cout << "You attacked with a punch and dealt " << punchDamage << " damage!\n\n";
            skeletonHP-=punchDamage;
            Sleep(1300);
            cout << "The skeleton attacks with his bow and arrow and deals " << bowDamage << " damage!\n\n";
            playerHP -= bowDamage;
            Sleep(1300);
          }
          else if(h == 2){
            cout << "You attacked with the Wooden Sword and dealt " << woodenSwordDamage << " damage!\n\n";
            skeletonHP-=woodenSwordDamage;
            Sleep(1300);
            cout << "The skeleton attacks with his bow and arrow and deals " << bowDamage << " damage!\n\n";
            playerHP-= bowDamage;
            Sleep(1300);
          }
        }
        else{
          cout << "You can attack with:\n\n1. Punch\n\n";
          int k;
          cin >> k;
          if(k == 1){
            cout << "You attacked with a punch and dealt " << punchDamage << " damage!\n\n";
            skeletonHP-=punchDamage;
            Sleep(1300);
            cout << "The skeleton attacks with his bow and arrow and deals " << bowDamage << " damage!\n\n";
            playerHP-=bowDamage;
            Sleep(1300);
          }
        }
}

void Room13() {
  cout << "You are now in Room 13, what do you want to do?\n\n";
  Sleep(2000);
  cout << "1. Look around\n2. Go back\n\n";
  int qq;
  cin >> qq;
  if(qq == 1){
    cout << "You decided to take a look around and you see a bed, a table, a chair, a drawer and a wardrobe. Where do you look?\n\n";
    Sleep(3600);
    cout << "1. The bed\n2. The table\n3. The chair\n4. The drawer\n5. The wardrobe\n6. Go back\n\n";
    int yy;
    cin >> yy;
    if(yy == 1){
      cout << "You have decided to go to the bed. But where to look?";
      Sleep(900);
      cout << "1. On top of the bed\n2."
      int gg;
      cin >> gg;
      if(gg == )
    }
  }
  else if(qq == 2){
    cout << "You have exited Room 13\n\n";
    Rooms();
  }
}