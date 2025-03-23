#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
#define MAXN 64
char a[MAXN][MAXN];
void init(){
	ifstream fin;
	fin.open("map2.out",ios::in);
	for(int i=0;i<MAXN;i++){
		string str;
		getline(fin,str);
		for(int j=0;j<MAXN;j++){
			a[i][j]=str[j];
		}
	}
	fin.close();
}
void print(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}
void output(){
	ofstream fout;
	fout.open("game_map.out",ios::out);
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			fout<<a[i][j];
		}
		fout<<endl;
	}
	fout.close();
}
int main(){
	init();
	int x=32,y=32;
	a[x][y]='K';
	char op;
	while(1){
		system("cls");
		print();
		a[x][y]=' ';
		op=getch();
		if(op=='w'&&a[x-1][y]==' ') x--;
		if(op=='s'&&a[x+1][y]==' ') x++;
		if(op=='a'&&a[x][y-1]==' ') y--;
		if(op=='d'&&a[x][y+1]==' ') y++;
		if(op=='m') output();
		a[x][y]='K';
	}
    return 0;
}
