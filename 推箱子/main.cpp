#include<bits/stdc++.h>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;a++)
#define dFor(a,b,c) for(int a=b;a>=c;a--)
#define MAXN 35
int x,y,cnt=0;
char f[MAXN][MAXN];
const int fx[4]={-1,0,0,1};
const int fy[4]={0,-1,1,0};
struct Node{
	int x[MAXN],y[MAXN];
	Node(){}
	operator < (Node a) const{
		For(i,0,cnt){
			if(x[i]!=a.x[i]) return x[i]<a.x[i];
			if(y[i]!=a.y[i]) return y[i]<a.y[i];
		}
	}
}a;
set<Node> s;
vector<int> bfs(){
	queue<Node> q;
	queue<vector<int> > q2;
	q.push(a);
	vector<int> temp;
	q2.push(temp);
	while(!q.empty()){
		Node k=q.front();
		vector<int> k2=q2.front();
		q.pop();q2.pop();
	  	For(i,0,int(k2.size()-1)){
			cout<<k2[i];
		}
		cout<<endl;
		bool flag=1;
		For(i,1,cnt){
			if(f[k.x[i]][k.y[i]]!='O'){
				flag=0;
				break;
			}
		}
		if(flag){
			return k2;
		}
		For(i,0,3){
			int xx=k.x[0]+fx[i],yy=k.y[0]+fy[i];
			if(xx<0||xx>=x||yy<0||yy>=y||f[xx][yy]=='#') continue;
			bool flag1=1;
			int p=0;
			For(j,1,cnt){
				if(xx==k.x[j]&&yy==k.y[j]&&(f[k.x[j]+fx[i]][k.y[j]+fy[i]]!='#')){
					bool flag2=1;
					For(l,1,cnt){
						if(l==j) continue;
						if(k.x[j]+fx[i]==k.x[l]&&k.y[j]+fy[i]==k.y[l]){
							flag2=0;
							continue;
						}
					}
					if(!flag2){
						flag1=0;
					}
					p=j;
					break;
				}
			}
			if(flag1==0){
				continue;
			}
			if(p==0){
				Node kk=k;
				kk.x[0]=xx;kk.y[0]=yy;
				if(s.find(kk)==s.end()){
					q.push(kk);
					vector<int> t=k2;
					t.push_back(i);
					q2.push(t);
				}
			}else{
				Node kk=k;
				kk.x[0]=xx;kk.y[0]=yy;
				kk.x[p]+=fx[i];kk.y[p]+=fy[i];
				if(s.find(kk)==s.end()){
					q.push(kk);
					vector<int> t=k2;
					t.push_back(i);
					q2.push(t);
				}
			}
		}
	}
}
void init(){
	freopen("lever1.txt","r",stdin);
	cin>>x>>y;
	string s;
	getline(cin,s);
	For(i,0,x-1){
		getline(cin,s);
		For(j,0,s.size()-1){
			f[i][j]=s[j];
			if(f[i][j]=='X'){
				a.x[0]=i;a.y[0]=j;
			}
			if(f[i][j]=='A'){
				cnt++;
				a.x[cnt]=i;a.y[cnt]=j;
			}
		}
	}
	For(i,0,x-1){
		For(j,0,y-1){
			cout<<f[i][j];
		}
		cout<<endl;
	}
	cout<<cnt<<endl;
}
int main(){
	init();
	vector<int> ans=bfs();
	For(i,0,ans.size()-1){
		if(ans[i]==0){
			cout<<'A';
		}
		if(ans[i]==1){
			cout<<'W';
		}
		if(ans[i]==2){
			cout<<'S';
		}
		if(ans[i]==3){
			cout<<'D';
		}
	}
    return 0;
}
