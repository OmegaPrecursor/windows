#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

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

int MAPHEIGHT = 10;

int MAPWIDTH = 10;

bool gameon = 1;

char map [11] [11] = {0}; // map 10x10 the extra 1 is to avoid random numbers being put on the edge of the screen

map [5] [5] = 219;

map [y] [x] = '@';

while(gameon = 1)
{

map [y] [x] = '@';
for (int i = 0; i != MAPHEIGHT; ++i)
{
    for (int j = 0; j != MAPWIDTH; ++j)
    {
        cout << map[i][j];
    }
    cout << '\n';   // After row is done create a new line.
}

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

ClearScreen(); // Successfully clear the sreen without using system dependencies.

map [prevy] [prevx] = 0;
}

}

