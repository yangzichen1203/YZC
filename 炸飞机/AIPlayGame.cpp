#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<windows.h>
#define For(i,j,k) for(auto i=j;i<=k;i++)
#define dFor(i,j,k) for(auto i=j;i>=k;i--)
#define MAXN 9
#define MAXP 3
#define MAXMP 100
#define MAXAI 1000
using namespace std;
struct Node{
	int x,y,d;
};
const int plane[4][5]={
{0,0,2,0,0},
{1,1,1,1,1},
{0,0,1,0,0},
{0,1,1,1,0}};
int mp[MAXN][MAXN];
vector<Node> head;
mt19937 Rand(time(0));
Node Randnode(){
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
void getmap(){
	do{
		head.clear();
		For(i,1,MAXP){
			head.push_back(Randnode());
		}
	}while(!check());
}
void printans(){
	cout<<' ';
	For(i,0,MAXN-1) cout<<i+1;
	cout<<endl;
	For(i,0,MAXN-1){
		cout<<char(i+'A');
		For(j,0,MAXN-1){
			cout<<mp[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
double sigmoid(double x){
	return 1.0/(1+exp(-x)); 
}
class AI{
	public:
		double w[MAXN*MAXN][MAXN*MAXN],b[MAXN*MAXN];
		AI(){}
		void print(){
			For(i,0,MAXN*MAXN-1){
				For(j,0,MAXN*MAXN-1){
					printf("%lf ",w[i][j]);
				}
				printf("\n");
			}
			For(i,0,MAXN*MAXN-1){
				printf("%lf ",b[i]);
			}
			printf("\n");
		}
}ai;
double test(){
	double map[MAXN][MAXN],now[MAXN*MAXN],next[MAXN*MAXN];
	For(i,0,MAXN-1){
		For(j,0,MAXN-1){
			map[i][j]=0;
		}
	}
	int headsum=MAXP;
	double ans=0;
	map[MAXN/2][MAXN/2]=(mp[MAXN/2][MAXN/2]+1)/3.0;
	if(mp[MAXN/2][MAXN/2]==2) headsum--;
	cout<<"E5"<<endl;
	while(headsum>0){
		For(i,0,MAXN-1){
			For(j,0,MAXN-1){
				now[i*MAXN+j]=map[i][j];
			}
		}
		memset(next,0,sizeof(next));
		For(i,0,MAXN*MAXN-1){
			For(j,0,MAXN*MAXN-1){
				next[j]+=now[i]*ai.w[i][j];
			}
		}
		For(i,0,MAXN*MAXN-1){
			now[i]=sigmoid(next[i]+ai.b[i]);
		}
		int fire;
		double Max=-1;
		For(i,0,MAXN*MAXN-1){
			int x=i/MAXN,y=i%MAXN;
			if(now[i]>Max){
				if(map[x][y]==0){
					Max=now[i];
					fire=i;
				}
			}
		}
		int x=fire/MAXN,y=fire%MAXN;
		cout<<char(x+'A')<<y+1<<endl;
		map[x][y]=(mp[x][y]+1)/4.0;
		if(mp[x][y]==2){
			headsum--;
		}
		ans++;
	}
	cout<<"Step:"<<ans<<endl;
	return ans;
}
void init(){
	freopen("AI1.2.txt","r",stdin);
	For(i,0,MAXN*MAXN-1){
		For(j,0,MAXN*MAXN-1){
			scanf("%lf",&ai.w[i][j]);
			if(i==j) ai.w[i][j]=-10000;
		}
	}
	For(i,0,MAXN*MAXN-1){
		scanf("%lf",&ai.b[i]);
	}
	freopen("CON","r",stdin);
}
int main(){
	init();
	getmap();
	printans();
	test();
	return 0;
}
