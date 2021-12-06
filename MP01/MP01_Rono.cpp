
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std; 

int proc,fg,bg,  tmp, totalBurst, a, fgCntr, bgCntr;
fstream checker;
int d; 
double ATAT=0.00, AWT=0.00, TTAT=0, TWT=0;
int process[8][8]={{0},{0},{0}};

char ULCorner=218, LLCorner=192, URCorner=191, LRCorner=217, UDivider=194, LDivider=193, ULine=196, SLine=179, LSDivider=195, RSDivider=180, MDivider=197;

void sort(int process[8][8]);
void compute();
void printGantt();
void printTable();
void middleD();
int  cntD(int a);

ofstream output;

int main(){
	bool tryAgain = true;
	do{
	ifstream checker("MP01 Checker.txt");
	
	output.open("MP01 Checker.txt", std::ios_base::app);
	cout<<"\nProgrammed by: Cara L Rono \nMP01 - FCFS"<<endl; 
	cout<<"Number of processes: ";
	output<<"\nProgrammed by: Cara L Rono \nMP01 - FCFS"<<endl; 
	output<<"Number of processes: ";
	checker>>proc;
	output<<proc;
	cout<<proc;
	
	//arrival, burst, 
	for(int i=0; i<proc; i++){
		checker>>tmp;
		process[1][i]=tmp;
	}
	for(int i=0; i<proc; i++){
		checker>>tmp;
		process[2][i]=tmp;	
	}
	for(int i=0; i<proc; i++){
		checker>>tmp;
		process[3][i]=tmp;
	}


		
	//ID
	for(int i=0; i<proc; i++){
		process[0][i]= i+1;
	}
	
	//Display
	
	cout<<"\nArrival Time: \n";
	output<<"\nArrival Time: \n";
	for(int i=0; i<proc; i++){
		cout<<"P"<<(i+1)<<" "<< process[1][i] <<"\n";
		output<<"P"<<(i+1)<<" "<< process[1][i] <<"\n";
	}
	cout<<"\nBurst Time: \n";
	output<<"\nBurst Time: \n";
	for(int i=0; i<proc; i++){
		cout<<"P"<<(i+1)<<" "<< process[2][i] <<"\n";
		output<<"P"<<(i+1)<<" "<< process[2][i] <<"\n";
	}
	
	cout<<"\nGantt Chart: \n";
	output<<"\nGantt Chart: \n";
	sort(process);
	printGantt();
	cout<<"\n\nTable\n";
	output<<"\n\nTable\n";
	printTable();
	
	char answer;
	do {
			cout << "\nDo you want to run again? [y/n]?: ";
			
			cin >> answer;
			
			if(answer == 'N' || answer == 'n')
				tryAgain = false;
				
			system("CLS");
		} while(answer != 'N' && answer != 'n' && answer != 'y' && answer != 'Y');
	
	}while(tryAgain);
		return 0; 
}

void sort(int process[8][8]){
	 // total burst time
	for(int i=0; i<proc; i++){
		totalBurst += process[2][i];
	}
	
	
	//sort by Arrival
	for (int i=1; i < proc-1; i++) {
    	if (process[1][i] > process[1][i+1]) {
            swap(process[0][i+1], process[0][i]);
            swap(process[1][i+1], process[1][i]);
            swap(process[2][i+1], process[2][i]);
            swap(process[3][i+1], process[3][i]);
			swap(process[4][i+1], process[4][i]);
        }
    }
    
    
	
}

void printGantt(){
	
	int cnt=proc; 
	int priority=5, tmp, totalArriv, nxtArriv=0, Gtmp, Gtmp2, Gtmp3;
	
	//fisrt line
	cout<<ULCorner; 
	
 	for(int i=0; i<proc; i++){
 		//cout<<process[2][i];
 		Gtmp=process[2][i]*2;
 		for(int i=0;i<Gtmp ;i++){
 			cout<<ULine;
 			
		}
		for(int i=0;i<Gtmp+1 ;i++){
 			output<<"_";
		}
		if(i<proc-1){
			cout<<UDivider;
			
		}else{
			cout<<URCorner;
		
		}	
	}
	
	cout<<endl;
	output<<endl;
	cout<<SLine; 
	
	output<<"|";
	//second line
	for(int i=0; i<proc; i++){
 	Gtmp=process[2][i]*2;
 	cout<<"P"<<process[0][i];
 	output<<"P"<<process[0][i];
 	for(int i=0;i<Gtmp-2;i++){
 		cout<<" ";
 		output<<" ";
	}

		cout<<SLine;
		output<<"|";
	}
	
	//third line
	cout<<endl;
	cout<<LLCorner;
	
	output<<endl; 
	output<<"|";
 	for(int i=0; i<proc; i++){
 		
 		Gtmp=process[2][i]*2;
 		for(int i=0;i<Gtmp ;i++){
 			cout<<ULine;
		}
		for(int i=0;i<Gtmp ;i++){
 			output<<"_";
		}
		if(i<proc-1){
			cout<<LDivider;
			output<<"|";
			
		}else{
			cout<<LRCorner;
			output<<"|";
		}	
	}
	
	cout<<endl;
	output<<endl;	
	//lower label
	int burst=0;
	
	for(int i=0; i<proc+1; i++){
		cout<<burst;
		output<<burst;
		Gtmp=process[2][i]*2;
		for(int j=0; j<process[2][i]*2; j++){
		cout<<" "; 
	
		}for(int j=0; j<Gtmp; j++){
		output<<" ";	
		}
		burst=burst+process[2][i];
	}
	


}

void printTable(){

	compute();

	cout<<endl<<endl;
	output<<endl;
	cout<<ULCorner; 
	
	for(int i=0; i<20; i++){
		cout<<ULine;
		output<<"_";
	}
	
	cout<<UDivider;
	
	for(int i=0; i<20; i++){
		cout<<ULine;
		}
	for(int i=0; i<23; i++){
		output<<"_";}
	cout<<UDivider;
	//output<<"_"; 
	for(int i=0; i<20; i++){
		cout<<ULine;
		output<<"_";}
	cout<<URCorner<<endl;
	output<<endl; 
	cout<<"|"<<" PROCESS";
	output<<"|"<<" PROCESS";
	for(int i=0; i<12; i++){
		cout<<" ";
		output<<" ";}
	cout<<SLine<<" WAITING TIME";
	output<<"|"<<" WAITING TIME";
	for(int i=0; i<7; i++){cout<<" ";output<<" ";}
	cout<<SLine<<" TURNAROUND TIME";
	output<<"|"<<" TURNAROUND TIME";
	for(int i=0; i<4; i++){cout<<" ";output<<" ";}
	cout<<SLine<<endl;
	output<<"|"<<endl;
	
	middleD();
	
	//process rows
	int rows=proc;
	int	totalBurst2=0;
	int cntr;
	
	//re-sorting
	for(int i=0; i<2; i++){
	 for (int i=1; i < proc-1; i++) {
    	if (process[0][i] > process[0][i+1]) {
    		swap(process[0][i+1], process[0][i]);
    		swap(process[1][i+1], process[1][i]);
    		swap(process[2][i+1], process[2][i]);
    		swap(process[3][i+1], process[3][i]);
    		swap(process[4][i+1], process[4][i]);
            swap(process[5][i+1], process[5][i]);
            swap(process[6][i+1], process[6][i]);
            
        }
    	}
	}
    
	for(int i=0; i<proc; i++){
		cout<<SLine;
		output<<"|";
		cout<<"   P"<<i+1; //Process number
		output<<"   P"<<i+1;
		for(int b=0; b<15; b++){cout<<" "; output<<" ";}
		cout<<SLine;
		output<<"|";
		
		cout<<"  "<<process[6][i];//turnaround time
		output<<"  "<<process[6][i];
		cntD(process[5][i]);
		
			if(d==1){
				for(int i=0; i<17; i++){cout<<" ";output<<" ";}
				cout<<SLine;
				output<<"|";
			}else if(d!=1){
				for(int i=0; i<17; i++){cout<<" ";output<<" ";}
				cout<<SLine;
				output<<"|";
			}
		
		cout<<"  "<<process[5][i];//waiting time
		output<<"  "<<process[5][i];
		cntD(process[5][i]);
		if(d==1){
			for(int i=0; i<17; i++){cout<<" ";output<<" ";}
			cout<<SLine;
			output<<"|";
		}else if(d!=1){
			for(int i=0; i<16; i++){cout<<" ";output<<" ";}
			cout<<SLine;
			output<<"|";
		}
		cout<<endl;
		output<<endl;
	}
	middleD();
	cout<<SLine;
	output<<"|";
	cout<<"Total"; //total
	output<<"Total";
	for(int i=0; i<15; i++){cout<<" ";output<<" ";}
	cout<<SLine;
	output<<"|";
	cout<<"  "<<TWT;
	output<<"  "<<TWT;
	for(int i=0; i<16; i++){cout<<" ";output<<" ";}
	cout<<SLine;
	output<<"|";
	cout<<"  "<<TTAT;
	output<<"  "<<TTAT;
	for(int i=0; i<16; i++){cout<<" ";output<<" ";}
	cout<<SLine;
	output<<"|";
	cout<<endl;
	output<<endl;
	middleD();
	cout<<SLine;
	output<<"|";
	cout<<"Average"; //total
	output<<"Average"; //total
	for(int i=0; i<13; i++){cout<<" ";output<<" ";}
	cout<<SLine;
	output<<"|";
	cout<<"  "<<ATAT;
	output<<"  "<<ATAT;
	for(int i=0; i<14; i++){cout<<" ";output<<" ";}
	cout<<SLine;
	output<<"|";
	cout<<"  "<<AWT;
	output<<"  "<<AWT;
	for(int i=0; i<14; i++){cout<<" ";output<<" ";}
	cout<<SLine;
	output<<"|";
	cout<<endl;
	output<<endl;
	
	cout<<LLCorner; 
	output<<"|"; 
	for(int i=0; i<20; i++){cout<<ULine;output<<"_";}
	
	cout<<LDivider;
	output<<"|"; 
	for(int i=0; i<20; i++){cout<<ULine;output<<"_";}
	
	cout<<LDivider;
	output<<"|"; 
	for(int i=0; i<20; i++){cout<<ULine;output<<"_"; }

	cout<<LRCorner<<endl;
	output<<"|"<<endl;
	
}

void compute(){
	int totalBurst2=0;
	for(int i=0; i<proc; i++){
		
		totalBurst2= totalBurst2 +process[2][i];
		int x=totalBurst2-process[1][i]; //TAT
		
		process[5][i]=x;
		process[6][i]=x-process[2][i]; // WT
		
	}
	//total TAT. TTAT=0, TWT=0
	for(int i=0; i<proc; i++){
		TTAT +=	process[5][i];
		TWT += process[6][i];
	}
	
	//Average. ATAT=0.00, AWT=0.00
	for(int i=0; i<proc; i++){
		ATAT=TTAT/proc;
		AWT=TWT/proc;
	}
	
}

void middleD(){
	
	cout<<LSDivider; 
	for(int i=0; i<20; i++){cout<<ULine;}
	//for(int i=0; i<20; i++){output<<"_";}
	cout<<MDivider; 
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<MDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<RSDivider<<endl;
	//output<<"|"<<ednl;

}

int cntD(int a){
	
	if(a/10==0){
		 d=1;	
	}else if(a/10!=0){
		 d=0;	
	}

}


