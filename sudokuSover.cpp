#include<iostream>
using namespace std;

bool canPlace(int mat[][100],int i,int j,int val){

	//Check Row .
	for(int col=0;col<9;col++){
		if(mat[i][col]==val)
			return false;
	}
	//Check for Col
	for(int row = 0;row<9;row++){
		if(mat[row][j]==val)
			return false;
	}

	int startX = (i/3)*3;
	int startY = (j/3)*3;

	for(int x=startX;x<startX+3;x++){
		for(int y=startY;y<startY+3;y++){
			if(mat[x][y]==val){
				return false;
			}
		}
	}
	return true;
}


bool SudokoSolver(int mat[][100],bool marked[][100],int i,int j){
	
	if(i==9){
		return true;
	}
	if(j==9){
		return SudokoSolver(mat,marked,i+1,0);
	}
	if(marked[i][j]==true){
		return SudokoSolver(mat,marked,i,j+1);
	}
	//Fill the current position with some number.
	for(int number=1;number<=9;number++){
		if(canPlace(mat,i,j,number)){

			mat[i][j] = number;
			bool canIFillRestOfTheMatrix = SudokoSolver(mat,marked,i,j+1);
			
			if(canIFillRestOfTheMatrix==false)
				mat[i][j]=0;
			else
				return true;
		}
	}
	return false;

}
void print(int mat[100][100]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<mat[i][j]<<" ";
		}
	 	cout<<endl;
	}
	cout<<endl<<endl;
}



int main(){

int mat[100][100] = 
		{{8,0,0,7,5,0,0,4,0},
        {0,0,0,1,0,0,0,0,0},
        {5,1,0,4,0,6,0,0,7},
        {0,0,4,0,0,0,0,5,0},
        {1,0,5,0,0,0,7,0,8},
        {0,2,0,0,0,0,4,0,0},
        {0,0,0,9,0,2,0,6,1},
        {0,0,0,0,0,3,0,0,0},
        {0,0,0,0,6,1,0,0,5}};

bool marked[100][100];
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(mat[i][j]>0){
				marked[i][j]=true;
			}
			else{
				marked[i][j] = false;
			}
		}
	}

	
	print(mat);

	SudokoSolver(mat,marked,0,0);
	
	cout<<"Solution : " <<endl;
	print(mat);

return 0;
}