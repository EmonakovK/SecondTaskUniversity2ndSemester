#include <fstream>
#include <iostream>
#include "Structure.h"
#include "Input.h"
#include "CreateArray.h"
#include "File.h"
#include "Circle.h"

using namespace std;
int main()
{
				bool check;
				int radius = 0, x = 0, y = 0, z = 0;
				do
				{
							 IsTestOk();
								check = Menu();
								if (check == true)
								{
												int n = input();
												int previouschoice = 1;
												int** arrayofdots = new int*[n];
												CreateArray(arrayofdots, n);
												FillArray(arrayofdots, n, previouschoice);
												CircleData(radius, x, y, z, n);
												int counting = HowMany(arrayofdots, n, radius, x, y, z);
												int** arrayofdotsincircle = new int*[counting];
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
								}
				} while (check == true);

}