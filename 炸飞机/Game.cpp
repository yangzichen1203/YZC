#include<bits/stdc++.h>
#include<windows.h>
#define For(i,j,k) for(auto i=j;i<=k;i++)
#define dFor(i,j,k) for(auto i=j;i>=k;i--)
#define MAXN 9
#define MAXP 3
using namespace std;
struct Node{
	int x,y,d;
};
const int plane[4][5]={
{0,0,2,0,0},
{1,1,1,1,1},
{0,0,1,0,0},
{0,1,1,1,0}};
char Map[MAXN][MAXN];
int mp[MAXN][MAXN],headsum,step;
vector<Node> head;
mt19937 Rand(time(0));
Node rd(){
	Node ans;
	ans.x=Rand()%MAXN;ans.y=Rand()%MAXN;
	ans.d=Rand()%4;
	return ans;
}
bool checkpos(int x,int y){
	return x>=0&&x<MAXN&&y>=0&&y<MAXN;
}
bool check(){
	memset(mp,0,sizeof(mp));
	for(Node i:head){
		int x=i.x,y=i.y,d=i.d;
		if(d==0){
			For(i,0,3){
				For(j,0,4){
					if(!checkpos(x+i,y+j-2)) return 0;
					mp[x+i][y+j-2]+=plane[i][j];
				}
			}
		}else if(d==1){
			For(i,0,3){
				For(j,0,4){
					if(!checkpos(x-i,y+j-2)) return 0;
					mp[x-i][y+j-2]+=plane[i][j];
				}
			}
		}else if(d==2){
			For(i,0,4){
				For(j,0,3){
					if(!checkpos(x+i-2,y+j)) return 0;
					mp[x+i-2][y+j]+=plane[j][i];
				}
			}
		}else{
			For(i,0,4){
				For(j,0,3){
					if(!checkpos(x+i-2,y-j)) return 0;
					mp[x+i-2][y-j]+=plane[j][i];
				}
			}
		}
	}
	int sum1=0,sum2=0;
	For(i,0,MAXN-1){
		For(j,0,MAXN-1){
			if(mp[i][j]<0||mp[i][j]>2) return 0;
			if(mp[i][j]==1) sum1++;
			if(mp[i][j]==2) sum2++;
		}
	}
	if(sum1==MAXP*9&&sum2==MAXP) return 1;
	else return 0;
}
char change(int x){
	if(x==0) return 'X';
	if(x==1) return 'O';
	if(x==2) return 'C';
	return '?';
}
void printmap(){
	cout<<' ';
	For(i,0,MAXN-1) cout<<i+1;
	cout<<endl;
	For(i,0,MAXN-1){
		cout<<char(i+'A');
		For(j,0,MAXN-1){
			cout<<Map[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void printans(){
	cout<<' ';
	For(i,0,MAXN-1) cout<<i+1;
	cout<<endl;
	For(i,0,MAXN-1){
		cout<<char(i+'A');
		For(j,0,MAXN-1){
			cout<<change(mp[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
}
void init(){
	do{
		head.clear();
		For(i,1,MAXP){
			head.push_back(rd());
		}
	}while(!check());
	For(i,0,MAXN-1){
		For(j,0,MAXN-1){
			Map[i][j]='.';
		}
	}
}
bool checkput(string op){
	return op.size()==2&&op[0]>='A'&&op[0]<'A'+MAXN&&op[1]>='1'&&op[1]<'1'+MAXN;
}
void question(){
	string op;
	while(cin>>op){
		if(checkput(op)) break;
	}
	int x=op[0]-'A',y=op[1]-'1';
	cout<<x<<' '<<y<<endl;
	Map[x][y]=change(mp[x][y]);
	if(mp[x][y]==2) headsum--;
	step++;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	headsum=MAXP;step=0;
	while(headsum>0){
		printmap();
		question();
		system("cls");
	}
	cout<<"Step:"<<step<<endl;
	printans();
	return 0;
}
