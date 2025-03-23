#include<bits/stdc++.h>
using namespace std;
#define MAXN 256
#define MAXM 0
double a[MAXN][MAXN],b[MAXN][MAXN];
const int fx[5]={0,-1,0,0,1};
const int fy[5]={0,0,-1,1,0};
const double fk[2][5]={{0.6,0.1,0.1,0.1,0.1},
						{1.2,-0.05,-0.05,-0.05,-0.05}};
void init(){
	srand(time(0));
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			a[i][j]=rand()%2;
		}
	}
}
void work(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			double sum=0;
			for(int k=0;k<=4;k++){
				sum+=a[(i+fx[k]+MAXN)%MAXN][(j+fy[k]+MAXN)%MAXN]*fk[0][k];
			}
			b[i][j]=sum;
		}
	}
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			a[i][j]=b[i][j];
		}
	}
}
void print(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			int high=a[i][j]*256;
			printf("%d ",high);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	freopen("map.out","w",stdout);
	init();
	for(int i=1;i<=MAXM;i++){
		work();
	}
	print();
    return 0;
}
