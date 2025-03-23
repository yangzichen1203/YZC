#include<bits/stdc++.h>
using namespace std;
int main(){
	double ans=1;
	for(int i=0;i<20;i++){
		ans=ans-(ans*ans-2)/(ans*2);
	}
	printf("%.6lf\n",ans);
    return 0;
}
