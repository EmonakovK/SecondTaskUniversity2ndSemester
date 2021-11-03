#include <iostream>
#include <fstream>
#include <string>
#include "Structure.h"
#include "File.h"
#include "Input.h"
#include "CreateArray.h"
#include "Circle.h"
using namespace std;


void Iam()
{
				cout << "Laboratory work 2" << endl;
				cout << "An array of points is given in 3D space and sphere(center and radius). Write a program that prints out dots(their coordinates) that fall within a user - defined sphere." << endl;
				cout << "Student group 405, Emonakov Konstantin." << endl;
}

bool Menu()
{
				int variant;
				int n, counter = 0;
				cout << "MENU" << endl;
				cout << "How do you want to enter number of dots?" << endl;
				cout << "1. Enter data from the keyboard." << endl;
				cout << "2. Use data from file." << endl;
				cout << "3. Display information about the program and the author." << endl;
				cout << "4. Exit the program." << endl;
				while (true)
				{
				cin >> variant;
				if (cin.fail() || (cin.peek() != '\n') || (variant != Start && variant != UseFile && variant != Information && variant != Finish)) 
				{
				cout << "Please enter a valid value!" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n'); 
				}
				else
								break;
				}
								switch ((int) variant)
								{
								case Start:
								{
												variant = 0;
												return true;
								}
								case UseFile:
								{
												while (true)
												{
																ifstream ifout;
																string line;
																cout << "Enter the path to retrieve data" << endl;
																cin >> line;
																ifout.open(line, ios::in);
																if (!IsTxt(line)) {
																cout << "Dont fotget to put .txt at the end" << endl;
																cin.clear();
																cin.ignore(INT_MAX, '\n');
																}
																else if (ifout.is_open() && IsInputOk(line))
																{
																				int ch;
																				while (ifout >> ch)
																				{
																								counter++;
																				}
																				ifout.close();
																				ifout.open(line);
																				ifout >> n;
																				if (counter == 0)
																				{
																								cout << "Incorrect data in the file! Upload new file." << endl;
																				}
																				else
																				{
																								int radius = 0, x = 0, y = 0, z = 0;
																								counter = 0;
																								cout << "Number of dots - " << n << endl;
																								ifout.close();
																								int** arrayofdots = new int*[n];
																								int previouschoice = 2;
																								CreateArray(arrayofdots, n);
																								FillArray(arrayofdots, n, previouschoice);
																								CircleData(radius, x, y, z, n);
																								int counting = HowMany(arrayofdots, n, radius, x, y, z);
																								int **arrayofdotsincircle = new int *[counting];
																								CreateArray(arrayofdotsincircle, counting);
																								IsInCircle(arrayofdots, arrayofdotsincircle, n, counting, radius, x, y, z);
																								ShowSecondArray(arrayofdotsincircle, counting);
																								ReadFile(arrayofdots, arrayofdotsincircle, radius, x, y, z, n, counting);

																								for (int i = 0; i < n; i++)
																								{
																												delete[] arrayofdots[i];
																								}
																								delete[] arrayofdots;
																								for (int i = 0; i < counting; i++)
																								{
																												delete[]	arrayofdotsincircle[i];
																								}
																								delete[] arrayofdotsincircle;
																								bool checkMenuFile = Menu();
																								if (checkMenuFile == false)
																												return false;
																								else
																												return true;
																				}
																}
																if (!IsInputOk(line)) 
																{
																				cout << "This file reserved by windows!" << endl;
																}
																else if (!ifout.is_open())
																				{
																								cout << "The file cannot be opened!" << endl;
																								bool checkMenuFile = Menu();
																								if (checkMenuFile == false)
																												return false;
																								else
																												return true;
																				}

												}
												return false;
								}
								case Information:
												{
																Iam();
																Menu();
																return true;
												}
								case Finish:
								{
												cout << "The program has ended. Goodbye." << endl;
												return false;
								}
								default:
								{
												cout << "Invalid value entered." << endl;
												return false;
								}
								}
}

int input()
{

				int n;
				while (true) 
				{
								cout << "Enter the number of dots" << endl;
								cin >> n;
								if (cin.fail() || n < 1 || (cin.peek() != '\n'))
								{

												cout << "Invalid value entered!" << endl;
												cout << "Please enter a number in betwen of 1 and 2147483647" << endl;
												cin.clear();
												cin.ignore(INT_MAX, '\n');
								}
								else
												break;
				}
				return n;
}