#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int n=10,m=20;
bool k[n+5][n+5];
int main(){
	srand(time(0));
	cout<<n<<endl;
	For(i,1,n){
		cout<<i<<endl;
	}
	For(i,1,m){
		int x=rand()%n+1,y=rand()%n+1;
		if(x>y) swap(x,y);
		while(k[x][y]){
			x=rand()%n+1;y=rand()%n+1;
			if(x>y) swap(x,y);
		}
		cout<<x<<' '<<y<<endl;
		k[x][y]=1;
	}
	return 0;
}
