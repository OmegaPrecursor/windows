#include <iostream>
#include <string>


using namespace std;


int main()
{
//is stands for in sight (os is opposite), line of sight is 25 characters of text starting with one and adding two with each character further forward


//in sight NPC stats
int hpis [25];
int defenseis [25];
int staminais [25];
int attackis [25];
int strengthis [25];
int inventoryis [25] [10];


//out of sight NPC stats (can run fifty NPCs at one time)
int hpos [50];
int defenseos [50];
int staminaos [50];
int attackos [50];
int strengthos [50];
int inventoryos [50] [10];


int npcx [50];
int npcy [50];


//player stats
string playername;
int hpplayer;
int defenseplayer;
int staminaplayer;
int attackplayer;
int strengthplayer;
int inventoryplayer [10];
string command;

//READ THIS x and y are reversed in the graphics sorry :(

int x = 1;
int y = 1;
//prev = previous
int prevx;
int prevy;

bool gameon = 1;

char map [11] [11] = {0}; // map 10x10 the extra 1 is to avoid random numbers being put on the edge of the screen

map [5] [5] = 219;

map [y] [x] = '@';

while(gameon = 1)
{

map [y] [x] = '@';
cout << map [1] [1] << map [1] [2] << map [1] [3] << map [1] [4] <<  map [1] [5] << map [1] [6] << map [1] [7] << map [1] [8] <<  map [1] [9] << map [1] [10] << endl;
cout << map [2] [1] << map [2] [2] << map [2] [3] << map [2] [4] <<  map [2] [5] << map [2] [6] << map [2] [7] << map [2] [8] <<  map [2] [9] << map [2] [10] << endl;
cout << map [3] [1] << map [3] [2] << map [3] [3] << map [3] [4] <<  map [3] [5] << map [3] [6] << map [3] [7] << map [3] [8] <<  map [3] [9] << map [3] [10] << endl;
cout << map [4] [1] << map [4] [2] << map [4] [3] << map [4] [4] <<  map [4] [5] << map [4] [6] << map [4] [7] << map [4] [8] <<  map [4] [9] << map [4] [10] << endl;
cout << map [5] [1] << map [5] [2] << map [5] [3] << map [5] [4] <<  map [5] [5] << map [5] [6] << map [5] [7] << map [5] [8] <<  map [5] [9] << map [5] [10] << endl;
cout << map [6] [1] << map [6] [2] << map [6] [3] << map [6] [4] <<  map [6] [5] << map [6] [6] << map [6] [7] << map [6] [8] <<  map [6] [9] << map [6] [10] << endl;
cout << map [7] [1] << map [7] [2] << map [7] [3] << map [7] [4] <<  map [7] [5] << map [7] [6] << map [7] [7] << map [7] [8] <<  map [7] [9] << map [7] [10] << endl;
cout << map [8] [1] << map [8] [2] << map [8] [3] << map [8] [4] <<  map [8] [5] << map [8] [6] << map [8] [7] << map [8] [8] <<  map [8] [9] << map [8] [10] << endl;
cout << map [9] [1] << map [9] [2] << map [9] [3] << map [9] [4] <<  map [9] [5] << map [9] [6] << map [9] [7] << map [9] [8] <<  map [9] [9] << map [9] [10] << endl;
cout << map [10] [1] << map [10] [2] << map [10] [3] << map [10] [4] <<  map [10] [5] << map [10] [6] << map [10] [7] << map [10] [8] <<  map [10] [9] << map [10] [10] << endl;

prevx = x;
prevy = y;

cin >> command;

if(command == "w")y--;
if(command == "a")x--;
if(command == "s")y++;
if(command == "d")x++;
if(command == "exit")gameon = 0;

if(map[y] [x] != 0){
x = prevx;
y = prevy;
}

system ("CLS");

map [prevy] [prevx] = 0;

}

}

