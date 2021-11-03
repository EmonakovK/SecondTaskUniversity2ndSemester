#include <Windows.h>
#include <cstring>
#include "Structure.h"
#include <algorithm>
#include "Input.h"
#include <iostream>
#include "Circle.h"
#include "CreateArray.h"
using namespace std;


string ToLower(string line)
{
				transform(line.begin(), line.end(), line.begin(), [](char c) {return static_cast<char>(tolower(c)); });
				return line;
}

void ShowFirstArray(int** arrayofdots, int n)//Выводим на консоль первый массив
{
				for (int i = 0; i < n; i++)
				{
								for (int j = 0; j < NUMBEROFCOORDINATES; j++)
								{
												cout << arrayofdots[i][j] << "\t";
								}
								cout << endl;
				}
				cout << endl;
}

void ShowSecondArray(int** arrayofdotsincircle, int counting)//Выводим на консоль второй массив
{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
				if (counting >= 1) {
								cout << "Dots in sphere:" << endl;
								cout << "X Y Z" << endl;
								for (int i = 0; i < counting; i++)
								{
												cout << arrayofdotsincircle[i][0] << " ";
												cout << arrayofdotsincircle[i][1] << " ";
												cout << arrayofdotsincircle[i][2] << " " << endl;


								}
				}
				else
								cout << "There is no dots in sphere!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

bool IsTxt(string pathinput) 
{
				size_t lenght = pathinput.size();
				if ( lenght < 5) {
								return false;
				}
				else 
				{
								if (pathinput[lenght-1] != 't' || pathinput[lenght -2] != 'x' || pathinput[lenght -3] != 't' || pathinput[lenght -4] != '.') 
								{
												return false;
								}
								else 
								{
												return true;
								}
				}
}

bool IsInputOk(string pathinput) {
				pathinput = ToLower(pathinput);

				if (pathinput == "con.txt" || pathinput == "dos.txt" || pathinput == "prn.txt" || pathinput == "aux.txt" ||
								pathinput == "nul.txt" || pathinput == "com1.txt" || pathinput == "com2.txt" ||
								pathinput == "com3.txt" || pathinput == "com4.txt" || pathinput == "com5.txt" ||
								pathinput == "com6.txt" || pathinput == "com7.txt" || pathinput == "com8.txt" ||
								pathinput == "com9.txt" || pathinput == "lpt1.txt" || pathinput == "lpt2.txt" ||
								pathinput == "lpt3.txt" || pathinput == "lpt4.txt" || pathinput == "lpt5.txt" ||
								pathinput == "lpt6.txt" || pathinput == "lpt7.txt" || pathinput == "lpt8.txt" ||
								pathinput == "lpt9.txt")
				{
								return false;
				}
				return true;

}

void IsTestOk() {
				int testcount;
				int n = 1;
				int counting = 3;
				int** testarrayofdots = new int*[n];
				CreateArray(testarrayofdots, n);
				testarrayofdots[0][0] = 0;
				testarrayofdots[0][1] = 0;
				testarrayofdots[0][2] = 0;
				int radius = 1;
				int circleX = 0;
				int circleY = 0;
				int circleZ = 0;
				int** testarrayofdotsincircle = new int*[counting];
				CreateArray(testarrayofdotsincircle, counting);
				IsInCircle(testarrayofdots, testarrayofdotsincircle, n, counting, radius, circleX, circleY, circleZ);
				testcount = 0;
				for (int i = 0; i < NUMBEROFCOORDINATES; i++) {
								if (testarrayofdots[0][i] == testarrayofdotsincircle[0][i]) {
												testcount++;
								}
				}
				for (int i = 0; i < n; i++)
				{
								delete[] testarrayofdots[i];
				}
				delete[] testarrayofdots;

				for (int i = 0; i < counting; i++)
				{
								delete[] testarrayofdotsincircle[i];
				}
				delete[] testarrayofdotsincircle;
				if (testcount == 3) 
				{ //1
								n = 1;
								counting = 3;
								testarrayofdots = new int*[n];
								CreateArray(testarrayofdots, n);
								testarrayofdots[0][0] = 2;
								testarrayofdots[0][1] = 2;
								testarrayofdots[0][2] = 2;
								radius = 1;
								circleX = 0;
								circleY = 0;
								circleZ = 0;
								testarrayofdotsincircle = new int*[counting];
								CreateArray(testarrayofdotsincircle, counting);
								IsInCircle(testarrayofdots, testarrayofdotsincircle, n, counting, radius, circleX, circleY, circleZ);
								testcount = 0;
								for (int i = 0; i < NUMBEROFCOORDINATES; i++) {
												if (testarrayofdots[0][i] != testarrayofdotsincircle[0][i]) {
																testcount++;
												}
								}
								for (int i = 0; i < n; i++)
								{
												delete[] testarrayofdots[i];
								}
								delete[] testarrayofdots;

								for (int i = 0; i < counting; i++)
								{
												delete[] testarrayofdotsincircle[i];
								}
								delete[] testarrayofdotsincircle;
								if (testcount == 3) { //2
												n = 1;
												counting = 3;
												testarrayofdots = new int*[n];
												CreateArray(testarrayofdots, n);
												testarrayofdots[0][0] = -2;
												testarrayofdots[0][1] = -2;
												testarrayofdots[0][2] = -2;
												radius = 2;
												circleX =-1;
												circleY = -1;
												circleZ = -1;
												testarrayofdotsincircle = new int*[counting];
												CreateArray(testarrayofdotsincircle, counting);
												IsInCircle(testarrayofdots, testarrayofdotsincircle, n, counting, radius, circleX, circleY, circleZ);
												testcount = 0;
												for (int i = 0; i < NUMBEROFCOORDINATES; i++) {
																if (testarrayofdots[0][i] == testarrayofdotsincircle[0][i]) {
																				testcount++;
																}
												}
												for (int i = 0; i < n; i++)
												{
																delete[] testarrayofdots[i];
												}
												delete[] testarrayofdots;

												for (int i = 0; i < counting; i++)
												{
																delete[] testarrayofdotsincircle[i];
												}
												delete[] testarrayofdotsincircle;
												if (testcount == 3) { //3
																n = 3;
																counting = 2;
																testarrayofdots = new int*[n];
																CreateArray(testarrayofdots, n);
																testarrayofdots[0][0] = -2;
																testarrayofdots[0][1] = -1;
																testarrayofdots[0][2] = -3;
																testarrayofdots[1][0] = 2000;
																testarrayofdots[1][1] = 2002;
																testarrayofdots[1][2] = 2001;
																testarrayofdots[2][0] = 3;
																testarrayofdots[2][1] = 2;
																testarrayofdots[2][2] = 1;
																radius = 10;
																circleX = 0;
																circleY = 0;
																circleZ = 0;
																testarrayofdotsincircle = new int*[counting];
																CreateArray(testarrayofdotsincircle, counting);
																IsInCircle(testarrayofdots, testarrayofdotsincircle, n, counting, radius, circleX, circleY, circleZ);
																testcount = 0;
																if (testarrayofdotsincircle[0][0] == -2 && testarrayofdotsincircle[0][1] == -1 && testarrayofdotsincircle[0][2] == -3) {
																				testcount++;
																				if (testarrayofdotsincircle[1][0] == 3 && testarrayofdotsincircle[1][1] == 2 && testarrayofdotsincircle[1][2] == 1){
																								testcount++;
																				}
																}
																for (int i = 0; i < n; i++)
																{
																				delete[] testarrayofdots[i];
																}
																delete[] testarrayofdots;

																for (int i = 0; i < counting; i++)
																{
																				delete[] testarrayofdotsincircle[i];
																}
																delete[] testarrayofdotsincircle;
																if (testcount == 2) {  //4
																				n = 3;
																				counting = 1;
																				testarrayofdots = new int*[n];
																				CreateArray(testarrayofdots, n);
																				testarrayofdots[0][0] = 126;
																				testarrayofdots[0][1] = 123;
																				testarrayofdots[0][2] = 111;
																				testarrayofdots[1][0] = -1;
																				testarrayofdots[1][1] = 0;
																				testarrayofdots[1][2] = 0;
																				testarrayofdots[2][0] = -12;
																				testarrayofdots[2][1] = 33;
																				testarrayofdots[2][2] = 11;
																				radius = 1;
																				circleX = 0;
																				circleY = 0;
																				circleZ = 0;
																				testarrayofdotsincircle = new int*[counting];
																				CreateArray(testarrayofdotsincircle, counting);
																				IsInCircle(testarrayofdots, testarrayofdotsincircle, n, counting, radius, circleX, circleY, circleZ);
																				testcount = 0;
																				if (testarrayofdotsincircle[0][0] == -1 && testarrayofdotsincircle[0][1] == 0 && testarrayofdotsincircle[0][2] == 0) {
																								testcount++;
																				}
																				for (int i = 0; i < n; i++)
																				{
																								delete[] testarrayofdots[i];
																				}
																				delete[] testarrayofdots;

																				for (int i = 0; i < counting; i++)
																				{
																								delete[] testarrayofdotsincircle[i];
																				}
																				delete[] testarrayofdotsincircle;
																				if (testcount == 1) {  //5
																								cout << "All tests passed" << endl;
																				}
																				else
																				{
																								cout << "Something went wrong. Tests not passed!" << endl;
																				}
																}
																else
																{
																				cout << "Something went wrong. Tests not passed!" << endl;
																}
												}
												else
												{
																cout << "Something went wrong. Tests not passed!" << endl;
												}
								}
								else
								{
												cout << "Something went wrong. Tests not passed!" << endl;
								}
				}
				else
				{
								cout << "Something went wrong. Tests not passed!" << endl;
				}
}