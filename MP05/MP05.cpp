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

	int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

	output.open("MP05 Checker.txt", std::ios_base::app);
	cout << "Programmed by: Cara L Rono" << endl
		 << "MP05 - OPTIMAL PAGE REPLACEMENT" << endl;
	output << endl
		   << "Programmed by: Cara L Rono" << endl
		   << "MP05 - OPTIMAL PAGE REPLACEMENT" << endl;

	checker.open("MP05 Checker.txt");
	printf("Enter reference string size: ");
	checker >> no_of_pages;
	int faultFlag[no_of_pages];
	int fstat[no_of_pages];
	cout << no_of_pages << endl;
	string tb[no_of_pages];

	printf("Enter page reference string: "); //getting reference strin save in pages array
	for (i = 0; i < no_of_pages; ++i)
	{
		faultFlag[i]=0; 
		fstat[i]=1;
		checker >> pages[i];
		cout << pages[i] << " ";
	}
	cout << endl;
	checker >> no_of_frames;
	cout << "Frame size: " << no_of_frames << endl
		 << endl;

	cout << "Page Replacement Table" << endl
		 << endl;
	output << "Page Replacement Table" << endl
		   << endl;

	for (i = 0; i < no_of_pages; ++i)
	{ //printing reference string
		cout << "  " << pages[i] << "  "
			 << " ";
		output << "  " << pages[i] << "  "
			   << "  ";
	}
	cout << endl;
	output << endl;


	for (i = 0; i < no_of_frames; ++i)
	{ // frame size or "boxes"
		frames[i] = -1;
	}
	//Traverse through pages
	for (i = 0; i < no_of_pages; ++i)
	{
		flag1 = flag2 = 0;
		for (j = 0; j < no_of_frames; ++j)
		{
			if (frames[j] == pages[i])
			{
				flag1 = flag2 = 1;
				break;
			}
		}

		if (flag1 == 0)
		{
			for (j = 0; j < no_of_frames; ++j)
			{
				if (frames[j] == -1)
				{
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

			for (j = 0; j < no_of_frames; ++j)
			{
				temp[j] = -1;

				for (k = i + 1; k < no_of_pages; ++k)
				{
					if (frames[j] == pages[k])
					{
						temp[j] = k;
						break;
					}
				}
			}

			for (j = 0; j < no_of_frames; ++j)
			{
				if (temp[j] == -1)
				{
					pos = j;
					flag3 = 1;
					break;
				}
			}

			if (flag3 == 0)
			{
				max = temp[0];
				pos = 0;

				for (j = 1; j < no_of_frames; ++j)
				{
					if (temp[j] > max)
					{
						max = temp[j];
						pos = j;
					}
				}
			}

			frames[pos] = pages[i];
			faults++;
		}
		
	
		for (j = 0; j < no_of_frames; ++j)
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
		
		
	}

	////////////////////////////////////////////////////////////////////

	string ftb[no_of_frames];
	string ftb2[no_of_frames];
	//for exe
	for (int zz = 0; zz < no_of_frames; zz++)
	{
		//top layer
		if (zz == 0)
		{
			for (int i = 0; i < no_of_pages; i++)
			{
				cout << uLeft << horz << horz << horz << uRight << " ";
				output << "____   ";
			}
		}
		cout << endl;
		output << endl;

		for (int z = 0; z < sizeof(tb) / sizeof(tb[0]); z++)
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
			ftb2[zz] += "  ";
		}
		cout << ftb[zz] << endl;
		output << ftb2[zz] << endl;
		
		//bottom layer
		if (zz == no_of_frames - 1)
		{
			for (int i = 0; i < no_of_pages; i++)
			{
				cout << bLeft << horz << horz << horz << bRight << " ";
				output << "____   ";
			}
		}
		else //middle
		{
			for (int i = 0; i < no_of_pages; i++)
			{
				cout << mLeft << horz << horz << horz << mRight << " ";
				output << "____   ";
			}
		}
	}

	cout << endl;
	cout << endl;
	output << endl
		   << endl;
	printf("\nDisplay Page Faults = %d\n", faults);
	output << "\nDisplay Page Faults = " << faults;
	
	
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
