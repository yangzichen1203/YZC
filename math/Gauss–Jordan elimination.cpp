#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
int n;
double a[MAXN][MAXN+1],ans[MAXN];
void print(){
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];

		}
	}
	for(int t=0;t<n-1;t++){
	  	for(int i=t+1;i<n;i++){
			double k=a[t][t]/a[i][t];
			a[i][t]=0;
			for(int j=t+1;j<=n;j++){
				a[i][j]=a[i][j]*k-a[t][j];
			}
		}
	}
	print();
	for(int i=n-1;i>=0;i--){
		ans[i]=a[i][n];
		for(int j=i+1;j<n;j++){
			ans[i]-=ans[j]*a[i][j];
		}
		ans[i]/=a[i][i];
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
/*
3
1 2 3 14
3 6 1 18
4 8 2 26
*/
