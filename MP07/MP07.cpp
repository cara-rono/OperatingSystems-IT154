// C++ program for implementation of
// SSTF disk scheduling
#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cctype>
#include<list>
#include<string>

using namespace std;

int csize, head, queue[10]={}, tableSize, temp, cntr, Hcntr; 
char horz = 196, uLeft = 218,  uRight = 191, dot=254, vert = 179;
char bLeft = 192;
char bRight = 217;
char dhorz = 194;
char uhorz = 193; 
char mRight = 180; 
char mLeft = 195; 
char mhorz = 197; 
int proc[10]={};
int n;


// Calculates difference of each
// track number with the head position
void calculatedifference(int request[], int head,
						int diff[][2], int n)
{
	for(int i = 0; i < n; i++)
	{
		diff[i][0] = abs(head - request[i]);
	}
}

// Find unaccessed track which is
// at minimum distance from head
int findMIN(int diff[][2], int n)
{
	int index = -1;
	int minimum = 1e9;

	for(int i = 0; i < n; i++)
	{
		if (!diff[i][1] && minimum > diff[i][0])
		{
			minimum = diff[i][0];
			index = i;
		}
	}
	return index;
}

void shortestSeekTimeFirst(int request[],
						int head, int n)
{
	if (n == 0)
	{
		return;
	}
	ifstream checker;
	ofstream output;
	output.open("MP07 Checker.txt", std::ios_base::app);
	// Create array of objects of class node
	int diff[n][2] = { { 0, 0 } };
	
	// Count total number of seek operation
	int seekcount = 0;
	
	// Stores sequence in which disk access is done
	int seeksequence[n + 1] = {0};
	
	for(int i = 0; i < n; i++)
	{
		seeksequence[i] = head;
		calculatedifference(request, head, diff, n);
		int index = findMIN(diff, n);
		diff[index][1] = 1;
		
		// Increase the total count
		seekcount += diff[index][0];
		
		// Accessed track is now new head
		head = request[index];
	}
	seeksequence[n] = head;
	
	
	//sort by ascending
	for(int i=0;i<tableSize+1;i++)
	{		
		for(int j=i+1;j<tableSize+1;j++)
		{
			if(proc[i]>proc[j])
			{
				temp  =proc[i];
				proc[i]=proc[j];
				proc[j]=temp;
			}
		}
	}
	cout<<endl<<"output:"<<endl<<"graph "<<endl<<endl;
	output<<endl<<"output:"<<endl<<"graph "<<endl<<endl;
	
	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0; j<4; j++){
			cout<<" ";
			output<<" ";
			cntr++;
		}
		cout<<proc[i];
		output<<proc[i];
	}		
	cout<<endl;
	output<<endl;
	
	//upper row
	cout<<uLeft<<horz;
	output<<"--";
	int row =cntr+(tableSize*2);
	for (int i = 0; i < row +2; ++i)
	{
		cout<<horz;
		output<<"-";
	}
	
	cout<<horz<<uRight;
	output<<"-"<<endl;
	cout<<endl;
	int spaces=0;
	for(int i = 0; i <tableSize+1 ; ++i){
		cout<<vert;
		for(int j = 0; j <tableSize+1 ; ++j){
			if(seeksequence[i]==proc[j]){
				spaces=j;
			}
		}
		
		for(int j = 0; j <spaces*3+2 ; ++j){
			cout<<"  ";
			output<<"  ";
		}
		cout<<"x";
		output<<"x"<<endl;
		
		int jj = spaces*3+2 ;
		for(int j = 0; j < row-(spaces*6)-1 ; ++j){
			cout<<" ";
		}
		cout<<vert<<endl;
		
	}
	
	cout<<bLeft<<horz;
	output<<"--";
	for (int i = 0; i < row +2; ++i)
	{
		cout<<horz;
		output<<"-";
	}
	
	cout<<horz<<bRight;
	cout<<endl;
	output<<"-"<<endl;
	
	cout<<endl<<"Table"<<endl;
	output<<endl<<"Table"<<endl<<"-";
	cout<<uLeft;
	
	//table labels and top border
	for (int i = 0; i < 15; ++i)
	{
		cout<<horz;
		
	}
		
	cout<<dhorz;
	
	
	for (int i = 0; i < 15; ++i)
	{
		cout<<horz;
		output<<"--";
	}
	cout<<uRight<<endl;
	output<<"-"<<endl;
	cout<<vert<<"  Next track   "<<vert<<"   Next track  "<<vert<<endl;
	cout<<vert<<"   accessed    "<<vert<<"    traversed  "<<vert<<endl;
	
	output<<"|"<<"  Next track   "<<"|"<<"   Next track  "<<"|"<<endl;
	output<<"|"<<"   accessed    "<<"|"<<"    traversed  "<<"|"<<endl;
	
	cout<<mLeft;
	for (int i = 0; i < 15; ++i)
	{
		cout<<horz;
		output<<"-";
	}
		
	cout<<mhorz;
	output<<"-";
	for (int i = 0; i < 15; ++i)
	{
		cout<<horz;
		output<<"-";
	}
	cout<<mRight<<endl;
	output<<"-"<<endl;
	//table fillings
	int totalDiff=0;
	
	for (int i = 0; i < tableSize+1; ++i)
	{
		
		int diff;
		int count=0, num, num2;
		cout<<vert;
		output<<"|";
		cout<<"       "<<seeksequence[i];
		output<<"       "<<seeksequence[i];
		
		num =seeksequence[i];
		while(num != 0) { //for counting digits
	      num = num / 10;
	      count++;
	    }
		if(count==1){
			cout<<"       "<<vert;
			output<<"       |";
		}else if(count==2){
			cout<<"      "<<vert;
			output<<"      |";
		}else if(count==3){
			cout<<"     "<<vert;
			output<<"     |";
		}
		
		if(i==0){
			diff=0;
		}else{
			diff=seeksequence[i]-seeksequence[i-1];
		}
		
		num2=diff;
		totalDiff+=diff;
		cout<<"       "<<abs(diff);
		output<<"       "<<abs(diff);
		
	

		if(num2>9 || num2<0){
			cout<<"      "<<vert;
			output<<"      |";
		}
	
		if(num2<=9 && num2>=0)
		{
			cout<<"       "<<vert;
			output<<"       |";
		}
		
		
		cout<<endl;
		output<<endl;
		
	}
	cout<<mLeft;
	output<<"-";
	for(int i=0; i<15; ++i){
		cout<<horz;
		output<<"-";
	}
	cout<<mhorz;
	output<<"-";
	for(int i=0; i<15; ++i){
		cout<<horz;
		output<<"-";
	}
	cout<<mRight<<endl;
	output<<"-"<<endl;
	double avg = (double)seekcount/n;
	cout<<vert<<"   Total       "<<vert<<" "<<seekcount<<" cylinders "<<vert<<endl;
	output<<"|   Total       | "<<seekcount<<" cylinders |"<<endl;
	cout<<vert<<"   Average     "<<vert<<" "<<avg<<"          "<<vert;
	output<<"|   Average     | "<<avg<<"          |";
	
	//total and average
	
	
	//bottom lines
	cout<<endl<<bLeft;
	output<<endl<<"-";
	for (int i = 0; i < 15; ++i)
	{
		cout<<horz;
		output<<"-";
	}
		
	cout<<uhorz;
	
	for (int i = 0; i < 15; ++i)
	{
		cout<<horz;
		output<<"-";
	}
	cout<<bRight<<endl;
	output<<"-"<<endl;
}


// Driver code
int main()
{
	char again;
	do{
	
	ifstream checker;
	ofstream output;
	
	output.open("MP07 Checker.txt", std::ios_base::app);
	cout << "Programmed by: Cara L Rono" << endl
		 << "MP07 - SSTF DISK SCHEDULING ALGORITHM" << endl;
	output << endl
		   << "Programmed by: Cara L Rono" << endl
		   << "MP07 - SSTF DISK SCHEDULING ALGORITHM" << endl;

	checker.open("MP07 Checker.txt");
	cout<<"Inputs: "<<endl;
	checker>>csize;
	cout<<"Max Cylinder Size: "<<csize<<endl;	
	checker>>head; 
	cout<<"Head Pointer Position: "<<head<<endl; 
	
	cout<<"Queue: ";
	output<<"Queue: ";
	for (int i = 0; i < 10; ++i)
	{	
		checker>>proc[i];
		cout << proc[i] << " ";
		output<<proc[i] << " ";
		if( proc[i] ==-1){
			proc[i]=head;
			break;
		}
		tableSize++;
	}
	cout<<endl;
	output<<endl;
	n = tableSize;
	
	//proc[n] = { 98, 183 ,37, 122, 14, 124, 65, 67};
	
	shortestSeekTimeFirst(proc, head, n);
		cout<<endl;
		
	    checker.close();
		output.close();
	
		cout << "\n\nDo you want to run again [y/n]: ";
		cin >> again;
	}while(again == 'Y' || again == 'y');
	return 0;
}



