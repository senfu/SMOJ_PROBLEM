#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_N = 100100;
int f[MAX_N+2];
int num;

int find(int x){
	if(f[x] == x)
	return x;
	
	return f[x]=find(f[x]);
}

bool add(int x,int y){
	int rx = find(x);
	int ry = find(y);
	if(rx == ry)
	return false;
	
	f[rx]=ry;
	return true;
}
int main(){
	
	freopen("1310.in","r",stdin);
	freopen("1310.out","w",stdout);
	
	for(int i=0;i<=MAX_N;i++)
	f[i]=i;
	
	while(true){
		int x,y;
		scanf("%d",&x);
		if(x == -1)
		break;
		
		scanf("%d",&y);
		if(!add(x,y))
		num++;
	}
	
	cout<<num<<endl;
	
	return 0;
}
