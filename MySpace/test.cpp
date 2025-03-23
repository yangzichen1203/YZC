#include "MySpace.cpp"
using namespace MySpace;
int main(){
	__int128 a;
	read(a);
	srand(time(0));
	for(int i=0;i<100;i++) write(random(a));
    return 0;
}
