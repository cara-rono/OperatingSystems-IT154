#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std; 

int proc, tmp, totalBurst, a;
fstream checker;
int d; 
double ATAT=0.00, AWT=0.00, TTAT=0, TWT=0;
int process[4][4]={{0},{0},{0}};
char ULCorner=218, LLCorner=192, URCorner=191, LRCorner=217, UDivider=194, LDivider=193, ULine=196, SLine=179, LSDivider=195, RSDivider=180, MDivider=197;

void sort(int process[4][4]);
void compute();
void printGantt();
void printTable();
void middleD();
int  cntD(int a);
void printToFile();


int main(){
	bool tryAgain = true;
	do{
	ifstream checker("MP03 Checker.txt");
	cout<<"\nProgrammed by: Cara L Rono \nMP03 - SJF non-preemptive"<<endl; 
	cout<<"Number of processes: ";
	checker>>proc;
	cout<<proc;
	
	//arrival, burst, and priority
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
	for(int i=0; i<proc; i++){
		cout<<"P"<<(i+1)<<" "<< process[1][i] <<"\n";
	}
	cout<<"\nBurst Time: \n";
	for(int i=0; i<proc; i++){
		cout<<"P"<<(i+1)<<" "<< process[2][i] <<"\n";
	}
	cout<<"\nPriority number: \n";
	for(int i=0; i<proc; i++){
		cout<<"P"<<(i+1)<<" "<< process[3][i] <<"\n";
	}
	
	cout<<"\nGantt Chart: \n";
	sort(process);
	printGantt();
	cout<<"\n\n Table\n";
	printTable();
	
	char answer;
	do {
			cout << "\nDo you want to run again? [y/n]?: ";
			cin >> answer;
			
			if(answer == 'N' || answer == 'n')
				tryAgain = false;
				printToFile();
			system("CLS");
		} while(answer != 'N' && answer != 'n' && answer != 'y' && answer != 'Y');
	
	}while(tryAgain);
		return 0; 
}

void sort(int process[4][4]){
	//sort by Arrival
	 for (int i=1; i < proc-1; i++) {
    	if (process[1][i] > process[1][i+1]) {
            swap(process[0][i+1], process[0][i]);
            swap(process[1][i+1], process[1][i]);
            swap(process[2][i+1], process[2][i]);
            swap(process[3][i+1], process[3][i]);
        }
    }
    
    //sort by burst time
    for(int i=0; i<2; i++){
		for (int i=1; i < proc-1; i++) {
    	if (process[2][i] > process[2][i+1]) {
            swap(process[0][i+1], process[0][i]);
            swap(process[1][i+1], process[1][i]);
            swap(process[2][i+1], process[2][i]);
            swap(process[3][i+1], process[3][i]);
        }
    	}
	}
     
    
  // total burst time
	for(int i=0; i<proc; i++){
		totalBurst += process[2][i];
	}
}

void printGantt(){
	int ganttSize=totalBurst; 
	//first line
	cout<<ULCorner; 
	for(int i=0; i<proc; i++){
		for(int j=0; j<process[2][i]; j++){
		cout<<ULine; 
		}
		if(i<proc-1){
			cout<<UDivider;
		}else{
			break; 
		}
		
	}
	cout<<URCorner<<endl;
	//second line
	cout<<SLine; 
	for(int i=0; i<proc; i++){
		cout<<"P"<<process[0][i];
		for(int j=0; j<process[2][i]-2; j++){
		cout<<" "; 
		}
		cout<<SLine;
	}
	cout<<endl;
	//third line
	cout<<LLCorner; 
	for(int i=0; i<proc; i++){
		for(int j=0; j<process[2][i]; j++){
		cout<<ULine; 
		}
		if(i<proc-1){
			cout<<LDivider;
		}else{
			break; 
		}
		
	}
	cout<<LRCorner<<endl;
	//lower label
	int burst=0;
	
	for(int i=0; i<proc+1; i++){
		cout<<burst;
		for(int j=0; j<process[2][i]-1; j++){
		cout<<" "; 
		}
		burst=burst+process[2][i];
	}
	
}

void printTable(){
	cout<<ULCorner; 
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<UDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<UDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<URCorner<<endl;
	cout<<SLine<<" PROCESS";
	for(int i=0; i<12; i++){cout<<" ";}
	cout<<SLine<<" WAITING TIME";
	for(int i=0; i<7; i++){cout<<" ";}
	cout<<SLine<<" TURNAROUND TIME";
	for(int i=0; i<4; i++){cout<<" ";}
	cout<<SLine<<endl;
		
	middleD();
	compute();
	//process rows
	int rows=proc;
	int	totalBurst2=0;
	int cntr;
	//re-sorting
	for(int i=0; i<2; i++){
	 for (int i=1; i < proc-1; i++) {
    	if (process[0][i] > process[0][i+1]) {
    		swap(process[0][i+1], process[0][i]);
            swap(process[4][i+1], process[4][i]);
            swap(process[5][i+1], process[5][i]);
            
        }
    	}
	}
    
	for(int i=0; i<proc; i++){
		cout<<SLine;
		cout<<"   P"<<i+1; //Process number
		for(int b=0; b<15; b++){cout<<" ";}
		cout<<SLine;
		cout<<"  "<<process[4][i];//turnaround time
		cntD(process[4][i]);
		
			if(d==1){
				for(int i=0; i<17; i++){cout<<" ";}
				cout<<SLine;
			}else{
				for(int i=0; i<16; i++){cout<<" ";}
				cout<<SLine;
			}
		
		cout<<"  "<<process[5][i];//waiting time
		cntD(process[5][i]);
		if(d==1){
			for(int i=0; i<17; i++){cout<<" ";}
			cout<<SLine;
		}else{
			for(int i=0; i<16; i++){cout<<" ";}
			cout<<SLine;
		}
		cout<<endl;
	}
	middleD();
	cout<<SLine;
	cout<<"Total"; //total
	for(int i=0; i<15; i++){cout<<" ";}
	cout<<SLine;
	cout<<"  "<<TTAT;
	for(int i=0; i<15; i++){cout<<" ";}
	cout<<SLine;
	cout<<"  "<<TWT;
	for(int i=0; i<15; i++){cout<<" ";}
	cout<<SLine;
	cout<<endl;
	middleD();
	cout<<SLine;
	cout<<"Average"; //total
	for(int i=0; i<13; i++){cout<<" ";}
	cout<<SLine;
	cout<<"  "<<ATAT;
	for(int i=0; i<13; i++){cout<<" ";}
	cout<<SLine;
	cout<<"  "<<AWT;
	for(int i=0; i<13; i++){cout<<" ";}
	cout<<SLine;
	cout<<endl;
	
	cout<<LLCorner; 
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<LDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<LDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<LRCorner<<endl;
	
}

void compute(){
	int totalBurst2=0;
	for(int i=0; i<proc; i++){
		totalBurst2 += process[2][i];
		process[4][i]=totalBurst2-process[1][i];
		process[5][i]=process[4][i]-process[2][i];
	}
	
	//total TAT. TTAT=0, TWT=0
	for(int i=0; i<proc; i++){
		TTAT +=	process[4][i];
		TWT += process[5][i];
	}
	
	//Average. ATAT=0.00, AWT=0.00
	for(int i=0; i<proc; i++){
		ATAT=TTAT/proc;
		AWT=TWT/proc;
	}
	

}

void middleD(){
	cout<<LSDivider; for(int i=0; i<20; i++){cout<<ULine;}
	cout<<MDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<MDivider;
	for(int i=0; i<20; i++){cout<<ULine;}
	cout<<RSDivider<<endl;
}

int cntD(int a){
	
	if(a/10==0){
		 d=1;	
	}else if(a/10!=0){
		 d=0;	
	}

}

void printToFile(){
	ofstream checker;
	checker.open("MP03 Checker.txt", std::ios_base::app); 
	checker<<"\n\nProgrammed by: Cara L Rono \nMP03 - SJF non-preemptive"<<endl; 
	checker<<"Number of processes: "<<proc;
	checker<<endl<<endl;

	checker<<"\nArrival Time: \n";
	for(int i=0; i<proc; i++){
		checker<<"P"<<(i+1)<<" "<< process[1][i] <<"\n";
	}
	checker<<"\nBurst Time: \n";
	for(int i=0; i<proc; i++){
		checker<<"P"<<(i+1)<<" "<< process[2][i] <<"\n";
	}
	checker<<"\nPriority number: \n";
	for(int i=0; i<proc; i++){
		checker<<"P"<<(i+1)<<" "<< process[3][i] <<"\n";
	}
	
	checker<<"\nGantt Chart: \n";
	checker<<"_"; 
	for(int i=0; i<proc; i++){
		for(int j=0; j<process[2][i]; j++){
		checker<<"_"; 
		}
		if(i<proc-1){
			checker<<"_";
		}else{
			break; 
		}
		
	}
	checker<<"_"<<endl;
	//second line
	checker<<"|"; 
	for(int i=0; i<proc; i++){
		checker<<"P"<<process[0][i];
		for(int j=0; j<process[2][i]-2; j++){
		checker<<" "; 
		}
		checker<<"|";
	}
	checker<<endl;
	//third line
	checker<<"_"; 
	for(int i=0; i<proc; i++){
		for(int j=0; j<process[2][i]; j++){
		checker<<"_"; 
		}
		if(i<proc-1){
			checker<<"_";
		}else{
			break; 
		}
		
	}
	checker<<"_"<<endl;
	//lower label
	int burst=0;
	
	for(int i=0; i<proc+1; i++){
		checker<<burst;
		for(int j=0; j<process[2][i]-1; j++){
		checker<<" "; 
		}
		burst=burst+process[2][i];
	}
	
	checker<<"\n\n Table\n";
	
	//process rows
	int rows=proc;
	int	totalBurst2=0;
	int cntr;
	checker<<"_"; 
	for(int i=0; i<20; i++){checker<<"_";}
	checker<<"_";
	for(int i=0; i<20; i++){checker<<"_";}
	checker<<"_";
	for(int i=0; i<20; i++){checker<<"_";}
	checker<<"_"<<endl;
	checker<<"|"<<" PROCESS";
	for(int i=0; i<12; i++){checker<<" ";}
	checker<<"|"<<" WAITING TIME";
	for(int i=0; i<7; i++){checker<<" ";}
	checker<<"|"<<" TURNAROUND TIME";
	for(int i=0; i<4; i++){checker<<" ";}
	checker<<"|"<<endl;
	for(int i=0; i<64; i++){checker<<"-";}
	checker<<endl;
	
	for(int i=0; i<proc; i++){
		checker<<"|";
		checker<<"   P"<<i+1; //Process number
		for(int g=0; g<15; g++){checker<<" ";}
		checker<<"|";
		checker<<"  "<<process[4][i];//turnaround time
		cntD(process[4][i]);
		
		if(d==1){
			for(int i=0; i<17; i++){checker<<" ";}
			checker<<"|";
		}else{
			for(int i=0; i<16; i++){checker<<" ";}
			checker<<"|";
		}
		
		checker<<"  "<<process[5][i];//waiting time
		cntD(process[5][i]);
		if(d==1){
			for(int i=0; i<17; i++){checker<<" ";}
			checker<<"|";
		}else{
			for(int i=0; i<16; i++){checker<<" ";}
			checker<<"|";
		}
		checker<<endl;
	}
	
	for(int i=0; i<64; i++){checker<<"-";}
	checker<<endl;
	
	
	checker<<"|";
	checker<<"Total"; //total
	for(int i=0; i<15; i++){checker<<" ";}
	checker<<"|";
	checker<<"  "<<TTAT;
	for(int i=0; i<15; i++){checker<<" ";}
	checker<<"|";
	checker<<"  "<<TWT;
	for(int i=0; i<15; i++){checker<<" ";}
	checker<<"|";
	checker<<endl;
	for(int i=0; i<64; i++){checker<<"-";}
	checker<<endl;
	checker<<"|";
	checker<<"Average"; //total
	for(int i=0; i<13; i++){checker<<" ";}
	checker<<"|";
	checker<<"  "<<ATAT;
	for(int i=0; i<13; i++){checker<<" ";}
	checker<<"|";
	checker<<"  "<<AWT;
	for(int i=0; i<13; i++){checker<<" ";}
	checker<<"|";
	checker<<endl;
	
	checker<<" "; 
	for(int i=0; i<20; i++){checker<<"_";}
	checker<<"_";
	for(int i=0; i<20; i++){checker<<"_";}
	checker<<"_";
	for(int i=0; i<20; i++){checker<<"_";}
	checker<<"_"<<endl;
}


