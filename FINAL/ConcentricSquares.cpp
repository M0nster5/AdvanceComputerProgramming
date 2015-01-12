#include <iostream>
using namespace std;
int squareDim(int num){
	return num*2-3;
}
int main(){
	int numLines = 0;
	cin>>numLines;
	for (int i = 0; i <numLines; i++){
			int numMaze = 0;
			cin>>numMaze;
			int original = numMaze;
			int row = 1;
		while(numMaze>0){
			for (int i = 0; i<row; i++){
				if (i%2 == 0){
					cout<<"* ";
				}
				else{
					cout<<"  ";
				}
			}
			if (row%2 == 1){
				for (int r = 0; r<squareDim(numMaze); r++){
					cout<<"* ";
				}
			}
			else{
				for (int r1 = 0; r1<squareDim(numMaze); r1++){
					cout<<"  ";
				}
			}
			for (int i = row; i>0; i--){
				if (i%2 == 1){
					if (i==original)
						cout<<"";
					else
						cout<<"* ";
				}
				else{
					if (i==original)
						cout<<"";
					else
						cout<<"  ";
					
				}
			}
			cout<<endl;
			numMaze--;
			row++;
		}
		numMaze = 2;
		row-=2;
		while(numMaze<=original){
			for (int i = 0; i<row; i++){
				if (i%2 == 0){
					cout<<"* ";
				}
				else{
					cout<<"  ";
				}
			}
			if (row%2 == 1){
				for (int r = 0; r<squareDim(numMaze); r++){
					cout<<"* ";
				}
			}
			else{
				for (int r1 = 0; r1<squareDim(numMaze); r1++){
					cout<<"  ";
				}
			}
			for (int i = row; i>0; i--){

				if (i%2 == 1){
					if (i==original)
						cout<<"";
					else
						cout<<"* ";
					
				}
				else{
					if (i==original)
						cout<<"";
					else
						cout<<"  ";
					
				}
			}
			row--;
			cout<<endl;
			numMaze++;
		}
		cout<<endl;
	}
}