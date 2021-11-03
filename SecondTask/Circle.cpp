#include <fstream>
#include <iostream>
#include <ctime>
#include "Input.h"
#include "Circle.h"
#include <cmath>
#include "CreateArray.h"
#include "Structure.h"


void CircleData(int& radius, int& x, int& y, int& z, int n)
{
				ifstream ifoutcircle;
				int answer;
				cout << "Which way do you want to enter radius and coordinates of the center of the sphere?" << endl;
				cout << "1.From the keyboard." << endl;
				cout << "2.From file." << endl;
				cout << "3.Fill with random numbers" << endl;
				while (true) 
				{
								cin >> answer;
								if (cin.fail() || (cin.peek() != '\n'))
								{
												cout << "Please enter a valid value!" << endl;
												cin.clear();
												cin.ignore(INT_MAX, '\n');
								}
								else
												break;
				}
				switch (answer)
				{
								case First:
								{
												while (true)
												{
																cout << "Enter radius of a circle" << endl;
																cin >> radius;
																if (cin.fail() || radius <= 0 || (cin.peek() != '\n'))
																{
																				cout << "Please enter a valid value! \n";
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else
																				break;
												}
												cout << "Enter the coordinates of the center of the sphere" << endl;
												while (true)
												{
																cout << "Enter coordinate X: " << endl;
																cin >> x;
																if (cin.fail() || (cin.peek() != '\n'))
																{
																				cout << "Please enter a valid value! \n";
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else
																				break;
												}
												while (true)
												{
																cout << "Enter coordinate Y: " << endl;
																cin >> y;
																if (cin.fail() || (cin.peek() != '\n'))
																{
																				cout << "Please enter a valid value! \n";
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else
																				break;
												}
												while (true)
												{
																cout << "Enter coordinate Z: " << endl;
																cin >> z;
																if (cin.fail() || (cin.peek() != '\n'))
																{
																				cout << "Please enter a valid value! \n";
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else
																				break;
												}
												break;
								}
								case Second:
								{
												while (true)
												{
																string linetocircle;
																cout << "Enter the path to retrieve data" << endl;
																cin >> linetocircle;
																ifoutcircle.open(linetocircle, ios::in);
																if (!IsTxt(linetocircle)) {
																				cout << "Dont fotget to put .txt at the end" << endl;
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else if (ifoutcircle.is_open())
																{
																				int howmanysimbols = 0;
																				int ch;
																				while (ifoutcircle >> ch)
																				{
																								howmanysimbols++;
																				}
																				ifoutcircle.close();
																				ifoutcircle.open(linetocircle);
																				if ((howmanysimbols != numberofcirclecoords) && (howmanysimbols != 1 + n*NUMBEROFCOORDINATES + numberofcirclecoords))
																				{
																								cout << "Incorrect data in the file! Upload new file." << endl;
																								cout << "Array contains invalid amount of numbers" << endl;
																								ifoutcircle.close();
																				}
																				else if (howmanysimbols == numberofcirclecoords)
																				{
																								ifoutcircle >> radius;
																								ifoutcircle >> x;
																								ifoutcircle >> y;
																								ifoutcircle >> z;
																								ifoutcircle.close();
																								howmanysimbols = 0;
																								break;
																				}
																				else if (howmanysimbols == 1 + (n * NUMBEROFCOORDINATES) + numberofcirclecoords)
																				{
																								int time;
																								ifoutcircle >> time;
																								for (int i = 0; i < n; i++)
																								{
																												for (int j = 0; j < NUMBEROFCOORDINATES; j++)
																												{
																																ifoutcircle >> time;
																												}
																								}
																								ifoutcircle >> radius;
																								ifoutcircle >> x;
																								ifoutcircle >> y;
																								ifoutcircle >> z;
																								ifoutcircle.close();
																								howmanysimbols = 0;
																								break;
																				}
																}

																else if (!ifoutcircle.is_open())
																{
																				cout << "The file cannot be opened!" << endl;
																}
												}
												break;
								}
								case Third:
								{
												srand((unsigned int)time(NULL)); 
												radius = rand() % random;
												x = rand() % random;
												y = rand() % random;
												z = rand() % random;
												break;
								}
								default:
								{
												cout << "Invalid enter." << endl;
												CircleData(radius, x, y, z, n);
												break;
								}

				}
}

int HowMany(int** arrayofdots, int n, int radius, int x, int y, int z) {
				int count = 0;
				for (int i = 0; i < n; i++)
				{
								if ((pow((arrayofdots[i][0] - x), 2) + pow((arrayofdots[i][1] - y), 2) + pow((arrayofdots[i][2] - z), 2)) <= (pow(radius, 2))) {
												count++;
								}
				}
				return count;
}

void IsInCircle(int** arrayofdots, int** arrayofdotsincircle, int n, int counting, int radius, int x, int y, int z) {

				int j = 0;
				for (int i = 0; i < n; i++)
				{
								if ((pow((arrayofdots[i][0] - x), 2) + pow((arrayofdots[i][1] - y), 2) + pow((arrayofdots[i][2] - z), 2)) <= (pow(radius, 2)))
								{
												while (j < counting) 
												{
																arrayofdotsincircle[j][0] = arrayofdots[i][0];
																arrayofdotsincircle[j][1] = arrayofdots[i][1];
																arrayofdotsincircle[j][2] = arrayofdots[i][2];
																j+=1;
																break;
												}
								}
				}
}