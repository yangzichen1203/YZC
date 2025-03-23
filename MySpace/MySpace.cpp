#pragma GCC optimize(1)
#pragma GCC optimize(2)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
namespace MySpace{
	template<typename T> inline T max(T a,T b);
	template<typename T> inline T min(T a,T b);
	template<typename T> inline T gcd(T a,T b);
	template<typename T> inline T lcm(T a,T b);
	template<typename T> inline T abs(T x);
	template<typename T> inline T lowbit(T x);
	template<typename T> inline T pow(T a,T b,T mod);
	inline int random(int x);
	template<typename T> inline void read(T &ff);
	template<typename T> inline void write(T x);
};
template<typename T> inline T MySpace::max(T a,T b){return a>b?a:b;}
template<typename T> inline T MySpace::min(T a,T b){return a<b?a:b;}
template<typename T> inline T MySpace::gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T> inline T MySpace::lcm(T a,T b){return a*b/gcd(a,b);}
template<typename T> inline T MySpace::abs(T x){return x>0?x:-x;}
template<typename T> inline T MySpace::lowbit(T x){return x&-x;}
template<typename T> inline T MySpace::pow(T a,T b,T mod){
	T ans=1,t=a;
	while(b){if(b&1){ans=ans*t%mod;}t=t*t%mod;b>>=1;}
	return ans;
}
inline int MySpace::random(int x){
	return (rand()<<15|rand())%x;
}
template<typename T> inline void MySpace::read(T &ff){
   	T rr=1;ff=0;char ch=getchar();
   	while(ch<'0'||ch>'9'){if(ch=='-')rr=-1;ch=getchar();}
   	while(ch>='0'&&ch<='9'){ff=(ff<<1)+(ff<<3)+(ch^48);ch=getchar();}
   	ff*=rr;
}
template<typename T> inline void MySpace::write(T x){
	int a[40],cnt=0;
	while(x){a[cnt++]=x%10;x/=10;}
	for(int i=cnt-1;i>=0;i--) putchar(a[i]+'0');
	putchar(' ');
}
