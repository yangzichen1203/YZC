#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=j;i<=k;i++)
#define dFor(i,j,k) for(auto i=j;i>=k;i--)
using namespace std;
double G=6.67e-11;// N*m^2/kg^2
double M=5.965e24;// kg
double F(double x,double y){//Gravity
	return G*M/(x*x+y*y);
}
double dis(double x,double y){
	return sqrt(x*x+y*y);
}
double x,y,vx,vy,ax,ay;
void print(){
	cout<<dis(x,y)<<' ';
	cout<<dis(vx,vy)<<' ';
	cout<<dis(ax,ay)<<' ';
	cout<<endl;
}
int main(){
	freopen("output.txt","w",stdout);
	double h=500,v0=9;
	//cin>>h>>v0;// km,km/s
	x=-(h+6371)*1e3,y=0;// m
	vx=0,vy=v0*1e3;// m/s
	ax=-x/dis(x,y)*F(x,y);
	ay=-y/dis(x,y)*F(x,y);
	For(i,1,100000){
		print();
		ax=-x/dis(x,y)*F(x,y);
		ay=-y/dis(x,y)*F(x,y);
		vx+=ax;vy+=ay;
		x+=vx;y+=vy;
	}
	return 0;
}
