#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<windows.h>
#define For(i,j,k) for(auto i=j;i<=k;i++)
#define dFor(i,j,k) for(auto i=j;i>=k;i--)
#define MAXN 9
#define MAXP 3
#define MAXMP 52464
#define MAP 1000
#define PLANE 3
#define STUDY 5.0
#define MAXBLOCK 1000
double STEP=0.02;
using namespace std;
struct Node{
	int x,y,d;
	Node(){}
	Node(int xx,int yy){
		x=xx;y=yy;
	}
	Node(int xx,int yy,int dd){
		x=xx;y=yy;d=dd;
	}
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
void getmap(){
	int cnt=0;
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
										head.push_back(Node(a,b,c));
										head.push_back(Node(d,e,f));
										head.push_back(Node(g,h,i));
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
int generation;
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
double f(double x){
	return x*STUDY;
}
double test(int m){
	double map[MAXN*MAXN],next[MAXN*MAXN];
	memset(map,0,sizeof(map));
	int headsum=MAXP;
	double ans=1,p=1;
	map[(MAXN/2)*MAXN+MAXN/2]=(mp[m][MAXN/2][MAXN/2]+1)/3.0;
	if(mp[m][MAXN/2][MAXN/2]==2) headsum--;
	while(headsum>MAXP-PLANE){
		memset(next,0,sizeof(next));
		For(i,0,MAXN*MAXN-1){
			For(j,0,MAXN*MAXN-1){
				next[j]+=map[i]*ai.w[i][j];
			}
		}
		For(i,0,MAXN*MAXN-1){
			next[i]+=ai.b[i];
		}
		int fire;
		double Max=-1;
		For(i,0,MAXN*MAXN-1){
			if(next[i]>Max&&map[i]==0){
				Max=next[i];
				fire=i;
			}
		}
		int x=fire/MAXN,y=fire%MAXN;
		map[fire]=(mp[m][x][y]+1)/3.0;
		if(mp[m][x][y]==2){
			headsum--;//p*=ans;ans=0;
		}
		ans++;
	}
	return ans;
}
double point1(){
	double sum=0;
	For(i,0,MAXMP-1){
		int p=test(i);
		sum+=p;
	}
	sum/=MAXMP;
	return sum;
}
vector<int> t;
double point2(){
	double sum=0;
	For(i,0,MAP-1){
		double p=test(t[i]);
		sum+=p;
	}
	sum/=MAP;
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
	freopen("CON","r",stdin);
}
double s1,s2;
double cw[MAXN*MAXN][MAXN*MAXN],cb[MAXN*MAXN];
void walk1(){
	For(i,0,MAXN/2){
		For(j,0,MAXN/2){
			For(k,0,MAXN-1){
				For(l,0,MAXN-1){
					ai.w[i*MAXN+j][k*MAXN+l]+=STEP;
					ai.w[(MAXN-i-1)*MAXN+j][(MAXN-k-1)*MAXN+l]+=STEP;
					ai.w[i*MAXN+(MAXN-j-1)][k*MAXN+(MAXN-l-1)]+=STEP;
					ai.w[(MAXN-i-1)*MAXN+(MAXN-j-1)][(MAXN-k-1)*MAXN+(MAXN-l-1)]+=STEP;
					double p1=point2()-s2;
					ai.w[i*MAXN+j][k*MAXN+l]-=STEP*2;
					ai.w[(MAXN-i-1)*MAXN+j][(MAXN-k-1)*MAXN+l]-=STEP*2;
					ai.w[i*MAXN+(MAXN-j-1)][k*MAXN+(MAXN-l-1)]-=STEP*2;
					ai.w[(MAXN-i-1)*MAXN+(MAXN-j-1)][(MAXN-k-1)*MAXN+(MAXN-l-1)]-=STEP*2;
					double p2=point2()-s2;
					//printf("%.2lf %.2lf\n",p1,p2);
					cw[i*MAXN+j][k*MAXN+l]=STEP*f(p2-p1);
					cw[(MAXN-i-1)*MAXN+j][(MAXN-k-1)*MAXN+l]=STEP*f(p2-p1);
					cw[i*MAXN+(MAXN-j-1)][k*MAXN+(MAXN-l-1)]=STEP*f(p2-p1);
					cw[(MAXN-i-1)*MAXN+(MAXN-j-1)][(MAXN-k-1)*MAXN+(MAXN-l-1)]=STEP*f(p2-p1);
					ai.w[i*MAXN+j][k*MAXN+l]+=STEP;
					ai.w[(MAXN-i-1)*MAXN+j][(MAXN-k-1)*MAXN+l]+=STEP;
					ai.w[i*MAXN+(MAXN-j-1)][k*MAXN+(MAXN-l-1)]+=STEP;
					ai.w[(MAXN-i-1)*MAXN+(MAXN-j-1)][(MAXN-k-1)*MAXN+(MAXN-l-1)]+=STEP;
				}
			}
		}
	}
	For(i,0,MAXN/2){
		For(j,0,MAXN/2){
			ai.b[i*MAXN+j]+=STEP;
			ai.b[(MAXN-i-1)*MAXN+j]+=STEP;
			ai.b[i*MAXN+(MAXN-j-1)]+=STEP;
			ai.b[(MAXN-i-1)*MAXN+(MAXN-j-1)]+=STEP;
			double p1=point2()-s2;
			ai.b[i*MAXN+j]-=STEP*2;
			ai.b[(MAXN-i-1)*MAXN+j]-=STEP*2;
			ai.b[i*MAXN+(MAXN-j-1)]-=STEP*2;
			ai.b[(MAXN-i-1)*MAXN+(MAXN-j-1)]-=STEP*2;
			double p2=point2()-s2;
			//printf("%.2lf %.2lf\n",p1,p2);
			cb[i*MAXN+j]=STEP*f(p2-p1);
			cb[(MAXN-i-1)*MAXN+j]=STEP*f(p2-p1);
			cb[i*MAXN+(MAXN-j-1)]=STEP*f(p2-p1);
			cb[(MAXN-i-1)*MAXN+(MAXN-j-1)]=STEP*f(p2-p1);
			ai.b[i*MAXN+j]+=STEP;
			ai.b[(MAXN-i-1)*MAXN+j]+=STEP;
			ai.b[i*MAXN+(MAXN-j-1)]+=STEP;
			ai.b[(MAXN-i-1)*MAXN+(MAXN-j-1)]+=STEP;
		}
	}
}
void walk2(){
	vector<Node> block[MAXBLOCK];
	For(i,0,MAXN/2){
		For(j,0,MAXN/2){
			For(k,0,MAXN-1){
				For(l,0,MAXN-1){
					int r=Rand()%MAXBLOCK;
					block[r].push_back(Node(i*MAXN+j,k*MAXN+l));
					block[r].push_back(Node((MAXN-i-1)*MAXN+j,(MAXN-k-1)*MAXN+l));
					block[r].push_back(Node(i*MAXN+(MAXN-j-1),k*MAXN+(MAXN-l-1)));
					block[r].push_back(Node((MAXN-i-1)*MAXN+(MAXN-j-1),(MAXN-k-1)*MAXN+(MAXN-l-1)));
				}
			}
		}
	}
	For(i,0,MAXBLOCK-1){
		if(block[i].empty()) continue;
		for(Node j:block[i]){
			ai.w[j.x][j.y]+=STEP;
		}
		double p=point2();
		//printf("%.2lf\n",s2-p);
		for(Node j:block[i]){
			cw[j.x][j.y]=STEP*f(s2-p);
			ai.w[j.x][j.y]-=STEP;
		}
	}
	For(i,0,MAXN/2){
		For(j,0,MAXN/2){
			ai.b[i*MAXN+j]+=STEP;
			ai.b[(MAXN-i-1)*MAXN+j]+=STEP;
			ai.b[i*MAXN+(MAXN-j-1)]+=STEP;
			ai.b[(MAXN-i-1)*MAXN+(MAXN-j-1)]+=STEP;
			double p=point2();
			cb[i*MAXN+j]=STEP*f(s2-p);
			cb[(MAXN-i-1)*MAXN+j]=STEP*f(s2-p);
			cb[i*MAXN+(MAXN-j-1)]=STEP*f(s2-p);
			cb[(MAXN-i-1)*MAXN+(MAXN-j-1)]=STEP*f(s2-p);
			ai.b[i*MAXN+j]-=STEP;
			ai.b[(MAXN-i-1)*MAXN+j]-=STEP;
			ai.b[i*MAXN+(MAXN-j-1)]-=STEP;
			ai.b[(MAXN-i-1)*MAXN+(MAXN-j-1)]-=STEP;
		}
	}
}
void change(){
	For(i,0,MAXN*MAXN-1){
		For(j,0,MAXN*MAXN-1){
			ai.w[i][j]+=cw[i][j];
		}
	}
	For(i,0,MAXN*MAXN-1){
		ai.b[i]+=cb[i];
	}
}
vector<double> Log1,Log2;
void save(){
	freopen("AI1.2.txt","w",stdout);
	ai.print();
	freopen("CON","w",stdout);
	freopen("log1.2.txt","w",stdout);
	for(double x:Log1){
		printf("%lf\n",x);
	}
	for(double x:Log2){
		printf("%.3lf\n",x);
	}
	freopen("CON","w",stdout);
}
int main(){
	init();
	generation=1;
	getmap();
	For(i,0,MAP-1){
		t.push_back(Rand()%MAXMP);
	}
	s1=point1();
	printf("Point=%lf\n",s1);
	Log1.push_back(s1);
	while(1){
		printf("Generation=%d\n",generation);
		if(generation%10==0){
			s1=point1();
			printf("Point=%lf\n",s1);
			Log1.push_back(s1);
			save();
			t.clear();
			For(i,0,MAP-1){
				t.push_back(Rand()%MAXMP);
			}
		}
		clock_t begin=clock();
		s2=point2();
		printf("Point=%.3lf\n",s2);
		Log2.push_back(s2);
		walk1();
		change();
		clock_t end=clock();
		printf("Time=%.3lf\n",1.0*(end-begin)/CLOCKS_PER_SEC);
		generation++;
	}
	return 0;
}
