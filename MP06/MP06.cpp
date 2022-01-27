#include <stdio.h>
#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

void show()
{
	ifstream checker;
	ofstream output;

	char horz = 196;
	char vert = 179;
	char uLeft = 218;
	char uRight = 191;
	char bLeft = 192;
	char bRight = 217;
	char dhorz = 194;
	char uhorz = 193;
	char mRight = 180;
	char mLeft = 195;
	char mhorz = 197;

	int frameSize, stringSize, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

	output.open("MP06 Checker.txt", std::ios_base::app);
	cout << "Programmed by: Cara L Rono" << endl
		 << "MP06 - Least Frequently used" << endl << endl;
	output << endl << endl
		   << "Programmed by: Cara L Rono" << endl
		   << "MP06 - Least Frequently used" << endl << endl;

	checker.open("MP06 Checker.txt");
	checker >> stringSize;
	cout << "Enter reference string size: " << stringSize << endl;
	int fstat[stringSize];
	string tb[stringSize];

	printf("Enter reference string: "); //getting reference strin save in pages array
	for (i = 0; i < stringSize; ++i)
	{
		fstat[i]=1;
		checker >> pages[i];
		cout << pages[i] << " ";
	}
	cout << endl;
	checker >> frameSize;
	int hit[frameSize];
	cout << "Frame size: " << frameSize << endl
		 << endl;
	cout << "Page Replacement Table" << endl
		 << endl;
	output << "Page Replacement Table" << endl
		   << endl;

    int** container = new int*[frameSize];
    
    for(int i = 0; i < frameSize; i++)
    	container[i] = new int[stringSize];

	for (i = 0; i < stringSize; ++i)
	{ //printing reference string
		cout << "  " << pages[i] << "  " << " ";
		output << "  " << pages[i] << "  " << " ";
	}
	cout << endl;
	output << endl;


	for (i = 0; i < frameSize; ++i)
	{ //initiallizes frames
		frames[i] = -1;
	}
	
	//Traverse through pages
	//
	for (i = 0; i < stringSize; ++i)
	{
		flag1 = flag2 = 0;
		
		//checks if pages[i] value has similar value with frames values
		for (j = 0; j < frameSize; ++j)
		{
			if (frames[j] == pages[i])
			{
				flag1 = flag2 = 1; 
				fstat[i] = 0;	//Fault Status Flag 1 = hit : 0 = none
				break;
			}
		}
		
		//no hit
		if (flag1 == 0) 
		{
			for (j = 0; j < frameSize; ++j)
			{
				//checks if frame is empty
				if (frames[j] == -1)
				{
					//fills the frame
					faults++;
					frames[j] = pages[i];
					flag2 = 1; 
					break;
				}
			}
		}

		if (flag2 == 0)
		{
			flag3 = 0;
			if (flag3 == 0)//find victim
			{
				for (j = 0; j < frameSize; ++j)
				{
					if (frames[j] == pages[i-3])
					{
						pos = j;
					}
				}
				
			
			}
			
			frames[pos] = pages[i];
			faults++;
		}

		for (j = 0; j < frameSize; ++j)
		{
			if (frames[j] == -1)
			{
				tb[i] += " ";
			}
			else
			{
				int a = frames[j];
				stringstream ss;
				ss << a;
				string str = ss.str();
				tb[i] += ss.str();
			}
		}
		// prepare flag
	}

	//==================Page Fault================

	////////////////////////////////////////////////////////////////////
	 
	string ftb[frameSize];
	string ftb2[frameSize];
	//for exe
	
	for (int zz = 0; zz < frameSize; zz++)
	{
		//top layer
		if (zz == 0)
		{
			for (int i = 0; i < stringSize; i++)
			{
				if(fstat[i] == 1)
				{
					cout << uLeft << horz << horz << horz << uRight << " ";
					output << "_____ ";
				}
				else{
					cout << "      ";
					output << "      ";					
				}
			}
		}
		cout << endl;
		output << endl;

		// page number
		for (int z = 0; z < sizeof(tb) / sizeof(tb[0]); z++)
		{
			if(fstat[z] == 1)
			{
				ftb[zz] += vert;
				ftb[zz] += " ";
				ftb[zz] += tb[z].substr(zz, 1);
				ftb[zz] += " ";
				ftb[zz] += vert;
				ftb[zz] += " ";

				ftb2[zz] += "|";
				ftb2[zz] += " ";
				ftb2[zz] += tb[z].substr(zz, 1);
				ftb2[zz] += " ";
				ftb2[zz] += "|";
				ftb2[zz] += " ";				
			}
			else{
				ftb[zz] += "      ";
				ftb2[zz] += "      ";
			}
		}
		cout << ftb[zz] << endl;
		output << ftb2[zz] << endl;

		//lower layer
		if (zz == frameSize - 1)
		{
			for (int i = 0; i < stringSize; i++)
			{
				if(fstat[i] == 1)
				{
					cout << bLeft << horz << horz << horz << bRight << " ";
					output << "|___| ";
				}
				else{
					cout << "      ";
					output << "      ";					
				}
			}
		}
		else
		{
			for (int i = 0; i < stringSize; i++)
			{
				if(fstat[i] == 1)
				{
					cout << mLeft << horz << horz << horz << mRight << " ";
					output << "|___| ";
				}
				else{
					cout << "      ";
					output << "      ";					
				}
			}
		}
	}
	cout << endl;
	cout << endl;
	output << endl
		   << endl;
	printf("\nDisplay Page Fault: %d\n", faults);
	output << "\nDisplay Page Fault: " << faults;
}
int main()
{
	bool ex = true;
	show();
	while (ex == true)
	{
		cout << endl
			 << "Do you want to run again[y/n]:";
		char a = 'n';
		cin >> a;
		if (a == 'y' || a == 'Y')
		{
			system("CLS");
			show();
		}
		else
		{
			return 0;
		}
	}
}
