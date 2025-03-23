#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=j;i<=k;i++)
#define dFor(i,j,k) for(auto i=j;i>=k;i--)
using namespace std;
#define MAXN 9
#define MAXP 3
#define MAXMP 52464
#define PLANE 1
struct Node{
	int x,y,d;
};
const int plane[4][5]={
{0,0,2,0,0},
{1,1,1,1,1},
{0,0,1,0,0},
{0,1,1,1,0}};
int mp[MAXMP][MAXN][MAXN];
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
bool check(int id){
	memset(mp[id],0,sizeof(mp[id]));
	for(Node i:head){
		int x=i.x,y=i.y,d=i.d;
		if(d==0){
			For(i,0,3){
				For(j,0,4){
					if(!checkpos(x+i,y+j-2)) return 0;
					mp[id][x+i][y+j-2]+=plane[i][j];
				}
			}
		}else if(d==1){
			For(i,0,3){
				For(j,0,4){
					if(!checkpos(x-i,y+j-2)) return 0;
					mp[id][x-i][y+j-2]+=plane[i][j];
				}
			}
		}else if(d==2){
			For(i,0,4){
				For(j,0,3){
					if(!checkpos(x+i-2,y+j)) return 0;
					mp[id][x+i-2][y+j]+=plane[j][i];
				}
			}
		}else{
			For(i,0,4){
				For(j,0,3){
					if(!checkpos(x+i-2,y-j)) return 0;
					mp[id][x+i-2][y-j]+=plane[j][i];
				}
			}
		}
	}
	int sum1=0,sum2=0;
	For(i,0,MAXN-1){
		For(j,0,MAXN-1){
			if(mp[id][i][j]<0||mp[id][i][j]>2) return 0;
			if(mp[id][i][j]==1) sum1++;
			if(mp[id][i][j]==2) sum2++;
		}
	}
	if(sum1==MAXP*9&&sum2==MAXP) return 1;
	else return 0;
}
int cnt=0;
void getmap(){
	For(a,0,MAXN-1){
		For(b,0,MAXN-1){
			For(c,0,3){
				For(d,0,MAXN-1){
					For(e,0,MAXN-1){
						For(f,0,3){
							For(g,0,MAXN-1){
								For(h,0,MAXN-1){
									For(i,0,3){
										head.clear();
										head.push_back(Node{a,b,c});
										head.push_back(Node{d,e,f});
										head.push_back(Node{g,h,i});
										if(check(cnt)){
											cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void printmap(){
	freopen("map.txt","w",stdout);
	printf("%d\n",cnt);
	For(i,0,cnt-1){
		For(j,0,MAXN-1){
			For(k,0,MAXN-1){
				printf("%d ",mp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
class AI{
	public:
		double w[MAXN*MAXN][MAXN*MAXN],b[MAXN*MAXN];
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
double sigmoid(double x){
	return 1.0/(1+exp(-x));
}
double test(int m){
	double map[MAXN][MAXN],now[MAXN*MAXN],next[MAXN*MAXN];
	For(i,0,MAXN-1){
		For(j,0,MAXN-1){
			map[i][j]=0;
		}
	}
	int headsum=MAXP;
	double ans=1,p=1;
	map[MAXN/2][MAXN/2]=(mp[m][MAXN/2][MAXN/2]+1)/3.0;
	if(mp[m][MAXN/2][MAXN/2]==2) headsum--;
	while(headsum>3-PLANE){
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
		map[x][y]=(mp[m][x][y]+1)/3.0;
		if(mp[m][x][y]==2){
			headsum--;//p*=ans;ans=0;
		}
		ans++;
	}
	return ans;
}
double point(){
	double sum=0;
	//int Max=0;
	For(i,0,MAXMP-1){
		//printf("%d\n",i);
		int p=test(i);
		sum+=p;
		//Max=max(Max,p);
	}
	sum/=MAXMP;
	return sum;
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
}
int main(){
	getmap();
	//printmap();
	init();
	printf("Point=%lf\n",point());
	return 0;
}
