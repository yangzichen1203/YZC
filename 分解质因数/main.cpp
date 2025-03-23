#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
#define MAXN 100000000
int a[MAXN+5];
int main(){
	freopen("100000000.txt","w",stdout);
	for(int i=2;i*i<=MAXN;i++){
		if(a[i]!=0) continue;
		for(int j=2;i*j<=MAXN;j++){
			if(a[i*j]) continue;
			a[i*j]=i;
		}
	}
	long long cnt=0;
	For(i,2,MAXN){
		int k=i;
		cout<<k<<'=';
		while(a[k]){
			cout<<a[k]<<'*';
			k/=a[k];
			cnt++;
		} 
		cout<<k<<endl;
		cnt++;
	}
	cout<<cnt<<endl;
    return 0;
}
/*
1e1:15
1e2:239
1e3:2877
1e4:31985
1e5:343614
1e6:3626619
1e7:37861249
1e8:392351272
1e9:
*/
