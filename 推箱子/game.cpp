#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;a++)
#define dFor(a,b,c) for(int a=b;a>=c;a--)
#define MAXN 35
#define MANM
int x,y,xx,yy,cnt=0;
char f[MAXN][MAXN];
void init(){
	ifstream fin("lever/16.txt");
	fin>>x>>y;
	string s;
	getline(fin,s);
	For(i,0,x-1){
		getline(fin,s);
		For(j,0,s.size()-1){
			f[i][j]=s[j];
			if(f[i][j]=='X'){
				xx=i;yy=j;
			}
			if(f[i][j]=='A'||f[i][j]=='R'){
				cnt++;
			}
		}
	}
	For(i,0,x-1){
		For(j,0,y-1){
			cout<<f[i][j];
		}
		cout<<endl;
	}
	fin.close();
}
void move(int fx,int fy){
	if(xx+fx<0||xx+fx>=x||yy+fy<0||yy+fy>=y||f[xx+fx][yy+fy]=='#') return;
	if(f[xx+fx][yy+fy]=='A'||f[xx+fx][yy+fy]=='R'){
		if(f[xx+fx*2][yy+fy*2]=='#'||f[xx+fx*2][yy+fy*2]=='A') return ;
		if(f[xx+fx*2][yy+fy*2]==' '){
			f[xx+fx*2][yy+fy*2]='A';
		}else if(f[xx+fx*2][yy+fy*2]=='O'){
			f[xx+fx*2][yy+fy*2]='R';
		}
		if(f[xx+fx][yy+fy]=='A') f[xx+fx][yy+fy]='X';
		else f[xx+fx][yy+fy]='C';
	}else if(f[xx+fx][yy+fy]==' '){
		f[xx+fx][yy+fy]='X';
	}else if(f[xx+fx][yy+fy]=='O'){
		f[xx+fx][yy+fy]='C';
	}
	if(f[xx][yy]=='C') f[xx][yy]='O';
	else f[xx][yy]=' ';
	xx+=fx;
	yy+=fy;
}
bool check_win(){
	int sum=0;
	For(i,1,x){
		For(j,1,y){
			if(f[i][j]=='R'){
				sum++;
			}
		}
	}
	return sum==cnt;
}
void game(){
	while(1){
		char op=getch();
		switch(op){
			case 'w':move(-1,0);break;
			case 'a':move(0,-1);break;
			case 's':move(1,0);break;
			case 'd':move(0,1);break;
		}
		system("cls");
		if(check_win()){
			cout<<"You Win!!!!!"<<endl;
			break;
		}
		For(i,0,x-1){
			For(j,0,y-1){
				cout<<f[i][j];
			}
			cout<<endl;
		}
	}
}
int main(){
	init();
	game();
	return 0;
}
