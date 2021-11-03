#pragma once
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
void ReadFile(int** arrayofdots, int** arrayofdotsincircle, int radius, int x, int y, int z, int n, int counting);
enum question { SaveInput = 1, SaveResalt, SaveBoth, Nothing };
enum file { Yes = 1, No };