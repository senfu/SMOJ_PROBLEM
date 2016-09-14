#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N = 100100;
long long a[MAX_N];
long long c[MAX_N];
int n,m;
long long num;

inline int lowbit(int x){
	return x&(-x);
}

void add(int x,long long num){
	a[x]+=num;
	while(x<n){
		x+=lowbit(x);
		a[x]+=num;
	}
	return;
}

long long ask(int x){
	long long sum = 0;
	while(x>0){
		sum+=a[x];
		x-=lowbit(x);
	}
	return sum;
}

void query(int x,int y){
	long long sum1 = ask(x-1);
	long long sum2 = ask(y);
	printf("%I64d\n",sum2-sum1);
	return;
}

int main(){
	freopen("1319.in","r",stdin);
	freopen("1319.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&num);
		c[i]=num;
		add(i,num);
	}
	
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++){
		char op[5];
		int x;
		long long y;
		scanf("%s%d%I64d",&op,&x,&y);
		if(op[0] == 'C'){
			add(x,y-c[x]);
			c[x] = y;
		}
		else
		query(x,y);
	}
	
	return 0;
}
