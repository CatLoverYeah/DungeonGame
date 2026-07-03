#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

bool hasLockpick = false;
bool hasRustyKey = false;
bool hasGoldenKey = false;
bool hasDiamondKey = false;
bool hasScrapMetal = false;
bool hasSearchedCell = false;
bool hasWoodenSword = false;
bool hasOpenedRustyRoom = false;
bool hasBeatenSkeleton = false;
bool hasHardDrive = false;
bool hasBeatenGoldenDoorMiniboss = false;
bool hasBow = false;
bool hasElectricSpell = false;
bool hasSuperDuperFancyCoolSword = false;
int skeletonHP = 100;
int playerHP = 150;
int stamina = 200;
int bowDamage = 25;
int woodenSwordDamage = 35;
int punchDamage = 15;
int howManyScraps = 0;
int howManyLockpicks = 0;
int goldenDoorMinibossHP = 250;

void Rooms();
void Corridor();
void RustyRoom();
void SkeletonFight();
void SkeletonFightCycle();
void DisplaySkeletonHP();
void DisplayPlayerHP();
void Room13();
void Room13Search();
void GoldenDoorMiniboss();
void GoldenDoorMinibossFight();
void GoldenRoom();
void ScrapMetalLoop();
void DownStairsLoop();
void RustyDoorLockpickLoop();
void DiamondDoorLockpickLoop();
void RustyRoomLoop();

int main() {
  srand(time(NULL));
  cout << "Your target is to collect items to help you beat the monster at the end of the game!\n\n";
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
        RustyDoorLockpickLoop();
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
        TreasureRoom2Loop();
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
        Sleep(700);
        Rooms();
        break;
      }
      else if(hasSearchedCell == true){
        cout << "You have already searched your cell! Where now?\n\n";
        Rooms();
      }
      default:
      cout << "Sorry, this is not an option, try again\n\n";
      Sleep(1400);
      Rooms();
  }
}

void Corridor(){
  cout << "1. Room\n2. Diamond Locked Room\n3. Stairs leading down\n4. Go back\n\n";
  int y;
  cin >> y;
  if(y == 1){
        cout << "Well, you have entered the mysterious room";
      }
      else if(y == 2){
        if(hasDiamondKey == true){
          cout << "You have entered the Diamond Room!\n\n";
        }
        else if(hasDiamondKey == false){
          cout << "You do not have the diamond key yet! Do you want to use lockpicks?\n\n";
          DiamondDoorLockpickLoop();
        }
      }
      else if(y == 3){
          cout << "You just went down the stairs...but where will they lead you?\n\n";
          Sleep(2000);
          cout << "You emerged in a dusty room with nothing in it except a table with a drawer...will you look inside?\n\n";
          DownStairsLoop();
      }
      else if(y == 4){
        cout << "You exited the Corridor\n\n";
        Sleep(1000);
        Rooms();
      }
      else {
        cout << "Sorry, that's not an option, TRY AGAIN\n\n";
        Sleep(1300);
        Corridor();
      }
}

void RustyRoom() {
  cout << "What do you want to do?\n\n1. Look around\n2. Exit\n\n";
  RustyRoomLoop();
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
    hasBow == true;
    Sleep(2600);
    cout << "However there will be many more along your way...\n\n";
    Sleep(1800);
    Room13();
  }
  else {
    Sleep(1800);
    cout << "The skeleton delivers the final blow\n";
    Sleep(1100);
    cout << "and...\n";
    Sleep(1100);
    cout << "And...\n";
    Sleep(1100);
    cout << "AND...\n\n";
    Sleep(1800);
    cout << "You died :( - More like :) -\n\n";
    Sleep(1600);
    cout << "Press any number to restart\n\n";
    int hk;
    cin >> hk;
    if(hk == 1 || hk == 2 || hk == 3 || hk == 4 || hk == 5 || hk == 6 || hk == 7 || hk == 8 || hk == 9 || hk == 0) {
      bool hasLockpick = false;
      bool hasRustyKey = false;
      bool hasGoldenKey = false;
      bool hasDiamondKey = false;
      bool hasScrapMetal = false;
      bool hasSearchedCell = false;
      bool hasWoodenSword = false;
      bool hasOpenedRustyRoom = false;
      bool hasBeatenSkeleton = false;
      bool hasHardDrive = false;
      bool hasBeatenGoldenDoorMiniboss = false;
      bool hasBow = false;
      bool hasElectricSpell = false;
      bool hasSuperDuperFancyCoolSword = false;
      int skeletonHP = 100;
      int playerHP = 150;
      int stamina = 200;
      int bowDamage = 25;
      int woodenSwordDamage = 35;
      int punchDamage = 15;
      int howManyScraps = 0;
      int howManyLockpicks = 0;
      main();
    }
    else {
      cout << "Nope, not a number, try again\n\n";
      Sleep()
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
  Room13Search();
}

void Room13Search() {
  int qq;
  cin >> qq;
  if(qq == 1){
    cout << "You decided to take a look around and you see lots of different things!. Where do you look?\n\n";
    Sleep(3600);
    cout << "1. The bed\n2. The table\n3. The chair\n4. The drawer\n5. The wardrobe\n6. Go back\n\n";
    int yy;
    cin >> yy;
    if(yy == 1){
      cout << "You have decided to go to the bed. But where to look?\n\n";
      Sleep(1100);
      cout << "1. Under\n2. On top\n\n";
      int kk;
      cin >> kk;
      if(kk == 1){
        cout << "You looked under the bed and saw... A golden key?\n\n";
        hasGoldenKey = true;
        Sleep(1600);
        cout << "What could that be used for?\n\n";
        Sleep(1000);
        cout << "Anyway, where now?\n\n";
        Room13Search();
      }
      else if(kk == 2) {
        cout << "Sadly there was nothing on the bed.\n\n";
        Room13Search();
      }
    }
    else if(yy == 2) {
      cout << "You ate an apple on the table, nice!\n\n";
      Sleep(1400);
      cout << "It did nothing...\n\n";
      Sleep(1000);
      Room13Search();
    }
    else if(yy == 3){
      cout << "I mean, you can sit on the chair, what else do you expect?\n\n";
      Sleep(1700);
      Room13Search();
    }
    else if(yy == 4) {
      cout << "You look into the drawer, and you see a hard drive?\n\n";
      hasHardDrive = true;
      Sleep(1700);
      cout << "Where in the world would this be necesary in a cave, man...\n\n";
      Sleep(1500);
      cout << "Who designed this game?!\n\n";
      Sleep(2000);
      cout << "Oh wait.\n\n";
      Sleep(1500);
      cout << "It was me...\n\n";
      Sleep(1200);
      cout << "Whatever. Where now?\n\n";
      Room13Search();
    }
    else if(yy == 5) {
      if(hasGoldenKey == true) {
        cout << "You found a golden door, which you just unlocked! Do you wanna go in?\n\n";
        string uu;
        cin >> uu;
        if(uu == "yes" || uu == "Yes") {
          cout << "Nice! What will you find...\n\n";
          Sleep(3000);
          if(hasBeatenGoldenDoorMiniboss == false) {
            GoldenDoorMiniboss();
          }
          else {
            GoldenRoom();
          }
        }
        else if(uu == "no" || uu == "No") {
          cout << "Alright, not now then, then where?\n\n";
          Room13Search();
        }
      }
      else {
        cout << "You have found a golden door! But sadly no way to open it.\n\n";
        Sleep(1600);
        Room13Search();
      }
    }
    else if(yy == 6) {
      cout << "Alright. Where then?\n\n";
      Sleep(1000);
      Rooms();
    }
    else {
      cout << "Sorry, that's not an option\n\n";
      Room13Search();
    }
  }
  else if(qq == 2){
    cout << "You have exited Room 13\n\n";
    Sleep(1200);
    Rooms();
  }
}

void GoldenDoorMiniboss() {
  cout << "And OH MY DOG\n\n";
  Sleep(1300);
  cout << "Ah, sorry, meant to say 'GOD', but yeah, whatever\n\n";
  Sleep(1800);
  cout << "Anyways, THERE'S A BIG GUY (your first miniboss btw)\n\n";
  Sleep(1900);
  cout << "Well...\n\n";
  Sleep(700);
  cout << "FIGHT!\n\n";
  Sleep(1300);
  GoldenDoorMinibossFight();
}

void GoldenDoorMinibossFight() {
  if(hasWoodenSword == true) {
    if(hasBow == true) {
      if(hasElectricSpell == true) {
        if(hasSuperDuperFancyCoolSword == true) {
          cout << "How do you attack:\n\n1. Punch\n2. Wooden Sword\n3. Bow and Arrow\n4. Electric Spell\n5. Super Duper Fancy Sword :)\n\n";
          int hhh;
          cin >> hhh;
          switch(hhh) {
            case 1:
              goldenDoorMinibossHP -= punchDamage;
              cout << "You hit him with a punch and dealt " << punchDamage << " damage\n\n";
              Sleep()
          }
        }
        else {
          cout << "How do you attack:\n\n1. Punch\n2. Wooden Sword\n3. Bow and Arrow\n4. Electric Spell\n\n";
          int ggg;
          cin >> ggg;
        }
      }
      else {
        if(hasSuperDuperFancyCoolSword == true) {
          cout << "How do you attack:\n\n1. Punch\n2. Wooden Sword\n3. Bow and Arrow\n4. Super Duper Fancy Sword :)\n\n";
          int fff;
          cin >> fff;
        }
        else {
          cout << "How do you attack:\n\n1. Punch\n2. Wooden Sword\n3. Bow and Arrow\n\n";
          int fl;
          cin >> fl;
        }
      }
    }
  }
}

void GoldenRoom() {

}

void ScrapMetalLoop() {
  cout << "What now?\n\n1. Go back\n\n";
  int o;
  cin >> o;
    if(o == 1){
    cout << "You are back at your cell! Where now?\n\n";
    Rooms();
  }
  else {
    cout << "Sorry, this is not an option, try again\n\n";
  Sleep(1400);
  ScrapMetalLoop();
  }
}

void RustyDoorLockpickLoop() {
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
  else if (ans2 == "no" || ans2 == "No") {
    cout << "Okay then, your choice!\n\n";
    Sleep(900);
    cout << "Where then?\n\n";
    Rooms();
  }
  else {
    cout << "Sorry, that is not an option\n\n";
    Sleep(1400);
    RustyDoorLockpickLoop();
  }
}

void DiamondDoorLockpickLoop() {
  string hs;
  cin >> hs;
  if(hasLockpick == true) {
    if(hs == "yes" || hs == "Yes") {
    cout << "Great! You have " << howManyLockpicks << " lockpicks, so now guess a number from 1-5!\n\n";
    }
    else if(hs == "no" || hs == "No") {
      cout << "Okay then! Not today. Where then?\n\n";
      Sleep(1000);
      Corridor();
    }
    else {
      cout << "Sorry, that is not an option, please try again\n\n";
      Sleep(1400);
    }
  }
}

void DownStairsLoop() {
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
  else {
    cout << "That is not an option, try again\n\n";
    Sleep(1000);
  }
}
void TreasureRoomLoop() {
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
  else {
    cout << "Sorry, that is not an option, please try again\n\n";
    Sleep(1200);
    TreasureRoomLoop();
  }
}

void TreasureRoom1Loop() {
  int w;
  cin >> w;
  if(w == 1){
    if(hasScrapMetal == true){
      cout << "You have " << howManyScraps << " pieces of scrap metal, do you want to make them into lockpicks? (Yes or No)\n\n";
      TreasureRoomLoop();
    }
  }
  else if(w == 2) {
    cout << "Okay then, back we go!\n\n";
    Sleep(1000);
    Rooms();
  }
  else {
    cout << "Sorry, that is not an option\n\n";
    Sleep(1000);
    TreasureRoom1Loop();
  }
}

void TreasureRoom2Loop() {
  int i;
  cin >> i;
  if(i == 1){
    cout << "You have investigated the Treasure Room and found an anvil and a hammer. What could it be used for?\n\n";
    Sleep(2600);
    if(hasScrapMetal == true){
      cout << "What now?\n\n1. Make lockpicks\n2. Go back\n\n";
      TreasureRoom1Loop();
    }
    else if(hasScrapMetal == false){
      ScrapMetalLoop();
    }
  }
  else if(i == 2){
    cout << "You exited the Treasure Room\n\n";
    Rooms();
  }
  else {
    cout << "That is not an option, try again\n\n";
    Sleep(1000);
    TreasureRoom2Loop();
  }
}

void RustyRoomLoop() {
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
    else {
      cout << "Okay, you know that's not an option...\n\n";
      Sleep(1500);
      cout << "TRY\n";
      Sleep(800);
      cout << "AGAIN\n\n";
      Sleep(900);
      RustyRoomLoop();
    }
  }
  else if(u == 2){
    cout << "You are back at your cell!\n\n";
    Rooms();
  }
  else {
    cout << "That's not an option, just try again\n\n";
    Sleep(1200);
    RustyRoomLoop();
  }
}
