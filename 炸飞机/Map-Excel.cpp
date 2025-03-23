#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=j;i<=k;i++)
#define dFor(i,j,k) for(auto i=j;i>=k;i--)
#define MAXN 9
using namespace std;
class AI{
	public:
		double w[MAXN*MAXN][MAXN*MAXN],b[MAXN*MAXN];
		void print(){
			For(i,0,MAXN*MAXN-1){
				For(j,0,MAXN-1){
					For(k,0,MAXN-1){
						printf("%lf ",w[i][j*MAXN+k]);
					}
					printf("\n");
				}
				printf("\n");
			}
			For(i,0,MAXN-1){
				For(j,0,MAXN-1){
					printf("%lf ",b[i*MAXN+j]);
				}
				printf("\n");
			}
			printf("\n");
		}
}ai;
void init(){
	freopen("AI1.2.txt","r",stdin);
	For(i,0,MAXN*MAXN-1){
		For(j,0,MAXN*MAXN-1){
			scanf("%lf",&ai.w[i][j]);
			if(i==j) ai.w[i][j]=0;
		}
	}
	For(i,0,MAXN*MAXN-1){
		scanf("%lf",&ai.b[i]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	freopen("toExcel.txt","w",stdout);
	ai.print();
	return 0;
}
