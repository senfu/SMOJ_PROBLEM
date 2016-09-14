#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
const int MAX_N = 33000;
const int MAX_NUM = 32001;
int a[MAX_N];
int n,x,y;

int query(int x){
	int sum = 0;
	while(x>0){
		sum+=a[x];
		x-=lowbit(x);
	}
	return sum;
}

void add(int x,int val){
	while(x<MAX_NUM){
		a[x]+=val;
		x+=lowbit(x);
	}
	return;
}

int main(){
	freopen("1320.in","r",stdin);
	freopen("1320.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		x++;
		printf("%d\n",query(x));
		add(x,1);
	}
	return 0;
}
