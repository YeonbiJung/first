#include <iostream>
#include <ctime>
using namespace std;

int setSize();
int setTarget(int bingo);
int playGame(int board[][]);
int main()
{
	int a[9][9];
	int playGame(a);
	int n=setSize();
	int b=setTarget(n);
}

int setSize(){//빙고판 사이즈 설정
	int size;
	do{
		cout<<"빙고판 사이즈(3x3~9x9) : ";
		cin>>size;
		if(size>9||size<3) cout<<"잘못된 범위입니다. 제시한 범위안에서 설정해주세요."<<endl;
	}while(size>9||size<3);
	return size;
}
int setTarget(int bingo){//목표 빙고수 설정
	int targ;
	int bound=bingo*2+2;
	do{
		cout<<"목표 빙고 수(1x1~"<<bound<<"x"<<bound<<") : ";
		cin>>targ;
		if(targ>bound||targ<1) cout<<"잘못된 범위입니다. 제시한 범위안에서 설정해주세요."<<endl;
	}while(targ>bound||targ<1);
	
	return targ;
}
int playGame(int board[][]){//실제 게임 플레이 -
	int how;
	do{
	cout<<"How to generate bingo?"<<endl;
	cout<<"1 : random"<<endl;
	cout<<"2 : read from file"<<endl;
	cout<<"Your option : "; cin>>how;
	}while(how>2||how<0);
	if(how==1) playRandom();
	else if(how==2) playFile();
}
/* https://blog.naver.com/lsy_pupu/120835487 */
int playRandom(int board[][], int size){
	int num=size*size;
	srand((unsigned int)time(0));
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			board[i][j]=rand()%num;
		}
	}
	for(int i=0; i<size; i++){
		if(i%2==0){
			for(int j=0; j<size; j++){
				cout<<"+---";
			}
			cout<<"+"<<endl;
		}else{
			for(int j=0; j<size; j++){
				cout<<"|"<<setw(3)<<board[i][j];
			}
			cout<<"|"<<endl;
		}
		
	}
	
}

//2dwdqrq12rdfsd











