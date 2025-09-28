//g++ "Music.cpp" -o "Music.exe" -std=c++11 -lwinmm
#include "music.h"

using namespace std;

int main()
 {
    MusicPlayer music;
    music.play("1 2 3 4 5 6 7 1^");
    return 0;
} 