#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
#define test_time 10
random_device __RD;
mt19937 Rand(__RD());
int rd(){
	int ans=Rand();
	return abs(ans);
}
int qpow(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=(long long)ans*a%mod;
		}
		a=(long long)a*a%mod;
		b>>=1;
	}
	return ans;
}
bool MillerRabin(int n){
    if(n<3||n%2==0) return n==2;
    int t=n-1,k=0;
    while(!(t&1)){
		k++;
		t>>=1;
	}
    For(i,1,test_time){
        int p=rd();
        int a=qpow(p,t,n),nxt=a;
        For(j,1,k){
            nxt=(long long)(a*a)%n;
            if(nxt==1&&a!=1&&a!=n-1) return 0;
            a=nxt;
        }
        if(a!=1) return 0;
    }
    return 1;
}
bool prime(int n){
	if(n<2) return 0;
	For(i,2,sqrt(n)){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	while(1){
		int n=rd();
		cout<<MillerRabin(n)<<prime(n)<<endl;
	}
    return 0;
}
