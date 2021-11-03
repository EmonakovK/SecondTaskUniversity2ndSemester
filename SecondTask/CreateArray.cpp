#include "CreateArray.h"
#include "Input.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include "Structure.h"
using namespace std;


void CreateArray(int** array, int n)//Создаем массив
{
				for (int i = 0; i < n; i++)
				{
								array[i] = new int[NUMBEROFCOORDINATES];
				}
}

void FillArray(int** arrayofdots, int n, int previouschoice)//Заполняем 
{
				ifstream ifoutcreatearray;
				int answered = NULL;
				cout << "Which way do you want to enter coordinates of dots?" << endl; 
				cout << "1.From the keyboard." << endl;
				cout << "2.Fill with random numbers" << endl;
				int element = NULL;
				if (previouschoice == 1) {
								while (true)
								{
												cin >> answered;
												if (cin.fail() || (cin.peek() != '\n') || answered != First && answered != Second)
												{
																cout << "Please enter a valid value!" << endl;
																cin.clear();
																cin.ignore(INT_MAX, '\n');
												}
												else
																break;
								}
				}
				else  
				{
								cout << "3.From file." << endl;
								while (true)
								{
												cin >> answered;
												if (cin.fail() || (cin.peek() != '\n') || answered != First && answered != Second && answered != Third)
												{
																cout << "Please enter a valid value!" << endl;
																cin.clear();
																cin.ignore(INT_MAX, '\n');
												}
												else
																break;
												}
				}
			
				switch (answered)
				{
								case First:
								{
								for (int i = 0; i < n; i++)
								{
												for (int j = 0; j < NUMBEROFCOORDINATES; j++)
												{
																cout << "Enter "<< j+1 << " coordinate of " << i+1 << " dot." << endl;
																while (true) 
																{
																				cin >> element;
																				if (cin.fail() || (cin.peek() != '\n'))
																				{
																								cout << "Invalid value entered!" << endl;
																								cout << "Please enter a number in betwen of -2147483648 and 2147483647" << endl;
																								cin.clear(); 
																								cin.ignore(INT_MAX, '\n');
																				}
																				else
																				{
																								arrayofdots[i][j] = (int) element;
																								break;
																				}
																}
												}
								}
								break;
				}
								case Second:
								{
								srand((unsigned int)time(NULL));
								for (int i = 0; i < n; i++)
								{
												for (int j = 0; j < NUMBEROFCOORDINATES; j++)
												{
																arrayofdots[i][j] = rand() % random;
												}
								}
								break;
				}
								case Third:
								{
								while (true)
								{
												string line;
												cout << "Enter the path to retrieve data" << endl;
												cin >> line;
												ifoutcreatearray.open(line, ios::in);
												if (!IsTxt(line)) {
																cout << "Dont fotget to put .txt at the end" << endl;
																cin.clear();
																cin.ignore(INT_MAX, '\n');
												}
												else if(!IsInputOk(line)){
																cout << "This file reserved by windows!" << endl;
																cin.clear();
																cin.ignore(INT_MAX, '\n');
												}
												else if (ifoutcreatearray.is_open() && IsInputOk(line))
												{
																int counercreate = 0;
																int ch;
																while (ifoutcreatearray >> ch)
																{
																				counercreate++;
																}
																ifoutcreatearray.close();
																ifoutcreatearray.open(line);
																if (counercreate != n * NUMBEROFCOORDINATES && counercreate != n * NUMBEROFCOORDINATES + 1 && counercreate != n * NUMBEROFCOORDINATES + 5)
																{
																				cout << "Incorrect data in the file! Upload new file." << endl;
																				cout << "Array contains invalid amount of numbers" << endl;
																				ifoutcreatearray.close();
																}
																else if (counercreate == n * NUMBEROFCOORDINATES)
																{
																				for (int i = 0; i < n; i++)
																				{
																								for (int j = 0; j < NUMBEROFCOORDINATES; j++)
																								{
																												ifoutcreatearray >> arrayofdots[i][j];
																								}
																				}
																				ifoutcreatearray.close();
																				counercreate = 0;
																				break;
																}
																else if (counercreate == (n * NUMBEROFCOORDINATES) + 1 || counercreate == (n * NUMBEROFCOORDINATES) + 5)
																{
																				int time;
																				ifoutcreatearray >> time;
																				for (int i = 0; i < n; i++)
																				{
																								for (int j = 0; j < NUMBEROFCOORDINATES; j++)
																								{
																												ifoutcreatearray >> arrayofdots[i][j];
																								}
																				}
																				ifoutcreatearray.close();
																				counercreate = 0;
																				break;
																}
												}
												else if (!ifoutcreatearray.is_open())
												{
																cout << "The file cannot be opened!" << endl;
												}
								}
				}
				}
}
