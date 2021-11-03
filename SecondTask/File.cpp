#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <string>
#include "Input.h"
#include "CreateArray.h"
#include "File.h"
#include "Structure.h"
#include <math.h>
#include <cmath>
#include "Circle.h"
#include <filesystem>
using namespace std::experimental::filesystem::v1;
using namespace std;

void ReadFile(int** arrayofdots, int** arrayofdotsincircle, int radius, int x, int y, int z, int n, int counting)
{
				ofstream fout;
				int answering;
				bool checkfile;
				string pathinput;
				cout << "Write data to file?" << endl;
				cout << "1. Write only raw data. " << endl;
				cout << "2. Write only the result." << endl;
				cout << "3. Write raw data and result." << endl;
				cout << "4. Do not write anything down." << endl;
				while (true)
				{
				cin >> answering;
				if (cin.fail() || (cin.peek() != '\n') || (answering != SaveInput && answering != SaveResalt && answering != SaveBoth && answering != Nothing))
				{
								cout << "Please enter a valid value!" << endl;
								cin.clear(); 
								cin.ignore(INT_MAX, '\n'); 
				}
				else
				break;
				}
								switch (answering)
								{
								case SaveInput:
								{
												while (!fout.is_open())
												{
																checkfile = true;
																cout << "Enter the name of the .txt format file" << endl;
																cout << "Example.txt" << endl;
																cin >> pathinput;
																if(!IsInputOk(pathinput))
																{
																				cout << "This name is reserved by Windows. Enter another" << endl;
																				cin.clear(); 
																				cin.ignore(INT_MAX, '\n'); 
																}
																else if (!IsTxt(pathinput)) {
																				cout << "Dont fotget to put .txt at the end" << endl;
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else
																{
																				if (exists(pathinput))
																				{
																								cout << "A file with this name exists. Do you want to overwrite the file? " << endl;
																								cout << "1. Yes." << endl;
																								cout << "2. No." << endl;
																								while (true) 
																								{
																												cin >> answering;
																												if (cin.fail())
																												{
																																cout << "Enter the correct value!";
																																cin.clear(); 
																																cin.ignore(INT_MAX, '\n'); 
																												}
																												else
																																break;
																								}
																												switch (answering)
																												{
																												case Yes:
																												{
																																				break;
																												}
																												case No:
																												{
																																checkfile = false;
																																break;
																												}
																												}
																				}
																				if (checkfile != false)
																				{
																								fout.open(pathinput);
																				}
																				if (fout.is_open() && checkfile != false)
																				{
																								fout << n << endl;
																								for (int i = 0; i < n; i++)
																								{
																												for (int j = 0; j < NUMBEROFCOORDINATES; j++)
																												{
																																fout << arrayofdots[i][j] << " ";
																												}
																												fout << "\n";
																								}
																								fout << radius << "\n" << x << " " << y << " " << z << " " << endl;

																								cout << "Data saved successfully" << endl;
																								fout.close();
																								break;
																				}
																				else if (checkfile != false)
																				{
																								cout << "The file has the wrong extension, please try again" << endl;
																								cout << "The file must have the .txt extension" << endl;
																								fout.close();
																				}
																}
												}
												break;
								}
								case SaveResalt:
								{
												while (!fout.is_open())
												{
																checkfile = true;
																cout << "Enter the name of the .txt format file" << endl;
																cout << "Example.txt" << endl;
																cin >> pathinput;

																if (!IsInputOk(pathinput)) {
																				cout << "This name is reserved by Windows. Enter another" << endl;
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else if (!IsTxt(pathinput)) {
																				cout << "Dont fotget to put .txt at the end" << endl;
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																else
																{
																				if (exists(pathinput))
																				{
																								cout << "A file with this name exists. Do you want to overwrite the file? " << endl;
																								cout << "1. Yes." << endl;
																								cout << "2. No." << endl;
																								while (true) 
																								{
																								cin >> answering;
																								if (cin.fail())
																								{
																								cout << "Please enter a valid value!";
																								cin.clear();
																								cin.ignore(INT_MAX, '\n'); 
																								}
																								else
																								break;
																								}
																												switch (answering)
																												{
																												case Yes:
																												{
																																break;
																												}
																												case No:
																												{
																																checkfile = false;
																																break;
																												}
																												}
																				}
																				if (checkfile != false)
																				{
																								fout.open(pathinput);
																				}
																				if (fout.is_open() && checkfile != false)
																				{
																								fout << "Dots in sphere:" << endl;
																								if (counting >= 1) {
																												for (int i = 0; i < counting; i++)
																												{
																																fout << "Dot number " << i + 1 << endl;
																																fout << arrayofdotsincircle[i][0] << " " << arrayofdotsincircle[i][1] << " " << arrayofdotsincircle[i][2] << endl;

																												}
																								}
																								else
																												cout << "There is No dots in sphere!" << endl;
																								cout << "Data saved successfully" << endl;
																								fout.close();
																								break;
																				}
																				else if (checkfile != false)
																				{
																								cout << "The file has the wrong extension, please try again" << endl;
																								cout << "The file must have the .txt extension" << endl;
																								fout.close();
																				}
																}
												}
												break;
								}
								case SaveBoth:
								{
												while (true) {
																cout << "How do you want save raw data and result?" << endl;
																cout << "1. In one file." << endl;
																cout << "2. In different files" << endl;
																cin >> answering;
																switch (answering)
																{
																case First:
																{
																				while (!fout.is_open())
																				{
																								checkfile = true;
																								cout << "Enter the name of the .txt format file" << endl;
																								cout << "Example.txt" << endl;
																								cin >> pathinput;

																								if (!IsInputOk(pathinput))
																								{
																												cout << "This name is reserved by Windows. Enter another" << endl;
																												cin.clear();
																												cin.ignore(INT_MAX, '\n');
																								}
																								else if (!IsTxt(pathinput)) {
																												cout << "Dont fotget to put .txt at the end" << endl;
																												cin.clear();
																												cin.ignore(INT_MAX, '\n');
																								}
																								else
																								{
																												if (exists(pathinput))
																												{
																																cout << "A file with this name exists. Do you want to overwrite the file? " << endl;
																																cout << "1. Yes." << endl;
																																cout << "2. No." << endl;
																																while (true)
																																{
																																				cin >> answering;
																																				if (cin.fail())
																																				{
																																								cout << "Please enter a valid value!";
																																								cin.clear();
																																								cin.ignore(INT_MAX, '\n');
																																				}
																																				else
																																								break;
																																}
																																switch (answering)
																																{
																																case Yes:
																																{
																																				break;
																																}
																																case No:
																																{
																																				checkfile = false;
																																				break;
																																}
																																}
																												}
																												if (checkfile != false)
																												{
																																fout.open(pathinput);
																												}
																												if (fout.is_open() && checkfile != false)
																												{
																																fout << "Radius and coordinates of circle:" << endl;
																																fout << radius << "\n" << x << " " << y << " " << z << " " << endl;
																																fout << "Coordintes of entered dots:" << endl;
																																for (int i = 0; i < n; i++)
																																{
																																				fout << "Dot number " << i + 1 << endl;
																																				for (int j = 0; j < NUMBEROFCOORDINATES; j++)
																																				{
																																								fout << arrayofdots[i][j] << " " << endl;
																																				}
																																}
																																fout << "Dots in sphere:" << endl;
																																for (int i = 0; i < counting; i++)
																																{
																																				fout << "Dot number " << i + 1 << endl;
																																				fout << arrayofdotsincircle[i][0] << " " << arrayofdotsincircle[i][1] << " " << arrayofdotsincircle[i][2] << endl;

																																}
																																cout << "Data saved successfully" << endl;
																																fout.close();
																																break;
																												}
																												else if (checkfile != false)
																												{
																																cout << "The file has the wrong extension, please try again" << endl;
																																cout << "The file must have the .txt extension" << endl;
																																fout.close();
																												}
																								}
																				}
																				break;
																}
																case Second: 
																{
																				while (!fout.is_open())
																				{
																								checkfile = true;
																								cout << "Enter the name of the .txt format file to save raw data." << endl;
																								cout << "Example.txt" << endl;
																								cin >> pathinput;
																								if (!IsInputOk(pathinput))
																								{
																												cout << "This name is reserved by Windows. Enter another" << endl;
																												cin.clear();
																												cin.ignore(INT_MAX, '\n');
																								}
																								else if (!IsTxt(pathinput)) {
																												cout << "Dont fotget to put .txt at the end" << endl;
																												cin.clear();
																												cin.ignore(INT_MAX, '\n');
																								}
																								else
																								{
																												if (exists(pathinput))
																												{
																																cout << "A file with this name exists. Do you want to overwrite the file? " << endl;
																																cout << "1. Yes." << endl;
																																cout << "2. No." << endl;
																																while (true)
																																{
																																				cin >> answering;
																																				if (cin.fail())
																																				{
																																								cout << "Enter the correct value!";
																																								cin.clear();
																																								cin.ignore(INT_MAX, '\n');
																																				}
																																				else
																																								break;
																																}
																																switch (answering)
																																{
																																case Yes:
																																{
																																				break;
																																}
																																case No:
																																{
																																				checkfile = false;
																																				break;
																																}
																																}
																												}
																												if (checkfile != false)
																												{
																																fout.open(pathinput);
																												}
																												if (fout.is_open() && checkfile != false)
																												{
																																fout << n << endl;
																																for (int i = 0; i < n; i++)
																																{
																																				for (int j = 0; j < NUMBEROFCOORDINATES; j++)
																																				{
																																								fout << arrayofdots[i][j] << " ";
																																				}
																																				cout << "\n";
																																}
																																fout << radius << "\n" << x << " " << y << " " << z << " " << endl;

																																cout << "Data saved successfully" << endl;
																																fout.close();
																																break;
																												}
																												else if (checkfile != false)
																												{
																																cout << "The file has the wrong extension, please try again" << endl;
																																cout << "The file must have the .txt extension" << endl;
																																fout.close();
																												}
																								}
																				}
																				while (!fout.is_open())
																				{
																								checkfile = true;
																								cout << "Enter the name of the .txt format file to save the result" << endl;
																								cout << "Example.txt" << endl;
																								cin >> pathinput;

																								if (!IsInputOk(pathinput)) {
																												cout << "This name is reserved by Windows. Enter another" << endl;
																												cin.clear();
																												cin.ignore(INT_MAX, '\n');
																								}
																								else if (!IsTxt(pathinput)) {
																												cout << "Dont fotget to put .txt at the end" << endl;
																												cin.clear();
																												cin.ignore(INT_MAX, '\n');
																								}
																								else
																								{
																												if (exists(pathinput))
																												{
																																cout << "A file with this name exists. Do you want to overwrite the file? " << endl;
																																cout << "1. Yes." << endl;
																																cout << "2. No." << endl;
																																while (true)
																																{
																																				cin >> answering;
																																				if (cin.fail())
																																				{
																																								cout << "Please enter a valid value!";
																																								cin.clear();
																																								cin.ignore(INT_MAX, '\n');
																																				}
																																				else
																																								break;
																																}
																																switch (answering)
																																{
																																case Yes:
																																{
																																				break;
																																}
																																case No:
																																{
																																				checkfile = false;
																																				break;
																																}
																																}
																												}
																												if (checkfile != false)
																												{
																																fout.open(pathinput);
																												}
																												if (fout.is_open() && checkfile != false)
																												{
																																fout << "Dots in sphere:" << endl;
																																if (counting >= 1) {
																																				for (int i = 0; i < counting; i++)
																																				{
																																								fout << "Dot number " << i + 1 << endl;
																																								fout << arrayofdotsincircle[i][0] << " " << arrayofdotsincircle[i][1] << " " << arrayofdotsincircle[i][2] << endl;

																																				}
																																}
																																else
																																				cout << "There is No dots in sphere!" << endl;
																																cout << "Data saved successfully" << endl;
																																fout.close();
																																break;
																												}
																												else if (checkfile != false)
																												{
																																cout << "The file has the wrong extension, please try again" << endl;
																																cout << "The file must have the .txt extension" << endl;
																																fout.close();
																												}
																								}
																				}
																}
																default:
																{
																				cout << "Invalid enter." << endl;
																				cin.clear();
																				cin.ignore(INT_MAX, '\n');
																}
																}
																break;
												}
								}
								case Nothing:
								{
												break;
								}
								default:
								{
												cout << "Invalid enter." << endl;
												ReadFile(arrayofdots, arrayofdotsincircle, radius, x, y, z, n, counting);
												break;
								}
								}
}