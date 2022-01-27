#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath> 
#include <iomanip>
#include <algorithm>
using namespace std;

char horz = 196, vert = 179; 
char uLeft = 218, uRight = 191, dhorz = 194; 
char bLeft = 192, bRight = 217, uhorz = 193; 
char mRight = 180, mLeft = 195, mhorz = 197; 

int main(){
	char again;
	do{
		system("CLS");
		stringstream ss;
		ifstream fin;
		ofstream fout;
		int maxCS;
		int headStart;
		int total = 0;
		double avg = 0;
		string strOutput = "";
		cout<<"Programmed by: Cara L Rono \n"
			<<"MP09 - C-LOOK DISK SCHEDULING ALGORITHM\n\n";
			
		cout<<"Inputs:\n";
		fin.open("MP08 Checker.txt");
		
		fin >> maxCS;
		
		cout<<"Max Cylinder Size: "<<maxCS<<endl;
				
		int cylinderQ[100];		
		int n = 0;
		
	    fin >> headStart;
	    for(int i = 0;  ; ++i){
	   		fin >> cylinderQ[i];	   		
	   		if(cylinderQ[i] == -1)
	        	break;
	        else
	        	n++;//array size
	    }
	    
	    int graphing[n+1];//compensates for the head start	
	    
	    for(int y = 0; y <n; y++){
			graphing[y] = cylinderQ[y];
		}
		    
		cout<<"Head Pointer Position: "<<headStart<<"\n";
	    cout<<"Queue: ";
	    for(int i=0;i<=n;i++)
	   		cout<<cylinderQ[i]<< "  ";
	    cout<<endl<<endl;
	    
	    graphing[n] =  headStart;//inserts at the end
	    n++;
	    
	    int i, j;
        sort(graphing,graphing+n);//sorts in ascending order

	    int headStart_index;
		for(int y = 0; y <n; y++)
			if(headStart == graphing[y])
				headStart_index = y;//finds the index of the head start within the array

		int idx=headStart_index;
	    headStart_index++;//bumps the index to accomodate the edge
		int tn=n+1;
	    int traverse[n];//holds the traversing sequence
	    int DStable[n];//holds the computations
        int temp,edge=maxCS-1;
		int k,l;
		//===============C-SCAN TRAVERSAL================(this hasn't included 0 in the graphing yet)[FUCK IT IT"S C LOOK NOW]
	    for(int i=idx,k=0; i < n; i++){
	    	traverse[k] = graphing[i];//assigns the first values
			k++;//firstpass counter
			if(i==n-1){
				// traverse[k] = edge;//get the edge for plotting
				l=k;//pick up where /k left off
				// traverse[l+1]=0;
				for(j=0;j<idx;j++){
					traverse[l]=graphing[j];
					l++;//second pass counter
				}
			}				
		}
		//===============END OF CSCAN TRAVERSAL=============
		// Assigns the C-SCAN Traverse[] to the DSTable[] for Computation
		//Change the "edge" to 0 if you're inverting it for SCAN		
		for(i=0,j=0;i<=n;i++){
			if(traverse[i]!=edge){//ignores the edge
				DStable[j]=traverse[i];
				j++;//separate counter
			}
		}
	    
	    int diskHole[n + 2];//diskHole[] holds the number labels in the graph 
	    //build the label array
	    for(int i =0, q=0; i< n+2; i++){
	    	if(i == 0){
		    	diskHole[i] = 0;//0 label
			}
			else if(i == n + 1){
				diskHole[i] =  edge;//max cylinder size label
			}
			else{
				diskHole[i] = graphing[q];//values label
				q++;//counter for the graphing[]
			}
		}
		
		fout.open("MP08 Checker.txt", ios_base::app);
		
		
		fout<<"\n\nProgrammed by: Cara L Rono \n"
			<<"MP09 - C-LOOK DISK SCHEDULING ALGORITHM\n\n";
		fout <<"\n\nOutput:";
		cout<<"\nOutput:\n\n";
		fout << "\n\n";
        //Graph==============================
		cout<<"Graph\n\n";
		fout << "Graph\n\n";
        int gW = (10*n)-1;//Graph Width

        //Number Labels

		for(int i=0; i<n+2; i++){
			cout<<diskHole[i]<<"\t";
			fout << diskHole[i]<< "\t";
		}
		cout<<endl<<endl;
		fout<<endl<<endl;
        //Plotting points
	    for(int y=0; y<n+1; y++){
	    	for(int x=0, q=0; x<n + 2;x++){	    		
				if(traverse[y] == diskHole[x]){
					cout<<"X";
					fout << "X";
				}
				else{
					cout<<" \t";
					fout << "\t";
				}					
			}
			cout<<endl;
			fout << "\n";
		}
 
		cout<<"\n\n"; 
		fout << "\n\n";

		cout<<"Table\n";
		fout << "Table\n";
		
		int nD = 9;
		cout<<uLeft;
		fout <<" ";
		for(int x=0; x<(nD*6) +1; x++){
			if (x == 23)
				cout<< dhorz;
			else
				cout<<horz;
			fout << "_";
		}
		cout<<uRight;
		cout<<endl;
		fout << "\n";
		cout<<vert<<" Next Track Accesed\t"<<vert<<" Next Track Traversed\t\t"<<vert<<"\n";
		fout << "| Next Track Accesed\t| Next Track Traversed\t\t|\n";
		for(int x=0; x<(nD*6)+3; x++){
			if(x==0 || x == ((nD*6) /2 ) - 3 || x == (nD*6) +2){
				if (x == 0)
					cout<<mLeft;
				else if (x == ((nD*6) /2 ) - 3)
					cout<<mhorz;
				else if (x == (nD*6) +2)
					cout << mRight;
				fout << "|";
			}
			else{
				cout<<horz;
				fout << "_";
			}		
		}
		cout<<endl;
		fout << "\n";
		
		for(int y = 0; y <n; y++){
			if(y != 0){
				total += abs(DStable[y] - DStable[y-1]);
				avg = total / ((n-1)*1.00);
			}
		}
		
		for(int y = 0; y <n; y++){
			cout<< vert<<" "<<DStable[y]<<"\t\t\t"<<vert;
			fout << "| "<< DStable[y]<< "\t\t\t| ";
			if(y != 0){
				cout<<" "<<abs(DStable[y] - DStable[y-1])<<" "<<"\t\t\t\t"<<vert;
				fout << abs(DStable[y] - DStable[y-1])<<" "<<"\t\t\t\t|";
			}
			else{
				cout<<" "<<"\t\t\t\t"<<vert;
				fout << " "<< "\t\t\t\t|";
			}
			cout<<endl;
			fout << "\n";
			for(int x=0; x<(nD*6)+3; x++){
				if(x==0 || x == ((nD*6) /2 ) - 3 || x == (nD*6) +2){
					if (x == 0)
						cout<<mLeft;
					else if (x == ((nD*6) /2 ) - 3)
						cout<<mhorz;
					else if (x == (nD*6) +2)
						cout << mRight;
					fout << "|";
				}
				else{
					cout<<horz;
					fout << "_";
				}
					
			}
			cout<<endl;
			fout << "\n";
		}
        //Total==================================================
		cout<< vert<<" Total"<<"\t\t\t"<<vert;
		fout << "| Total\t\t\t|";
	
		cout<<" "<<total<<" Cylinders"<<"\t\t\t"<<vert;
		fout<<" "<<total<< " Cylinders\t\t\t|";
		
		cout<<endl;
		fout << "\n";
		for(int x=0; x<(nD*6)+3; x++){
			if(x==0 || x == ((nD*6) /2 ) - 3 || x == (nD*6) +2){
				if (x == 0)
					cout<<mLeft;
				else if (x == ((nD*6) /2 ) - 3)
					cout<<mhorz;
				else if (x == (nD*6) +2)
					cout << mRight;
				fout << "|";
			}
			else{
				cout<<horz;
				fout << "_";
			}
				
		}
		cout<<endl;
		//Average==================================================
		fout << "\n";
		cout<< vert<<setprecision(2)<<fixed<<" Average\t"<<"\t"<<vert;
		fout << "|"<<" Average\t\t| ";
	
		cout<<" "<<avg<<"\t\t\t\t"<<vert;
		fout << setprecision(2)<< fixed<<avg<< " \t\t\t|";
		
		cout<<endl;
		fout << "\n";
		for(int x=0; x<(nD*6)+3; x++){
			if(x==0 || x == ((nD*6) /2 ) - 3 || x == (nD*6) +2){
				if (x == 0)
					cout<<bLeft;
				else if (x == ((nD*6) /2 ) - 3)
					cout<<uhorz;
				else if (x == (nD*6) +2)
					cout << bRight;
				fout << "|";
			}
			else{
				cout<<horz;
				fout << "_";
			}
				
		}
		cout<<endl;
	    fin.close();
		fout.close();
	
		cout << "\n\nDo you want to run again [y/n]: ";
		cin >> again;
	}while(again == 'Y' || again == 'y');
    
	return 0;
}
