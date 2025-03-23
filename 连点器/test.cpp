#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	while(1){
		if(GetAsyncKeyState(VK_UP)){
			while(1){
				mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
				Sleep(50);
				if(GetAsyncKeyState(VK_DOWN)){
					break;
				}
			}
		}
	}
	return 0;
}
