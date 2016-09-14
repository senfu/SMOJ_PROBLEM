#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define lowbit(x) (x&(-(x)))
const int MAX_N = 100100;
long long sum[MAX_N];
long long d1[MAX_N];
long long d2[MAX_N];
int n,q;
char op[5];
int a,b,c;

void update(long long* A,int x,int val){
	while(x<=n){
		A[x]+=val;
		x+=lowbit(x);
	}
	return;
}

long long query(long long* A,int x){
	long long sum = 0;
	while(x>0){
		sum+=A[x];
		x-=lowbit(x);
	}
	return sum;
}

void ask(int x,int y){
	x--;
	long long sumx = sum[x]+(long long)((long long)(x+1)*query(d1,x))-query(d2,x);
	long long sumy = sum[y]+(long long)((long long)(y+1)*query(d1,y))-query(d2,y);
	printf("%lld\n",sumy-sumx);
	return;
}

int main(){
	freopen("1321.in","r",stdin);
	freopen("1321.out","w",stdout);
	
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	
	for(int i=1;i<=q;i++){
		scanf("%s%d%d",&op,&a,&b);
		if(op[0] == 'Q')
		ask(a,b);
		else{
			scanf("%d",&c);
			update(d1,a,c);
			update(d1,b+1,-c);
			update(d2,a,a*c);
			update(d2,b+1,-c*(b+1));
		}
	}
	
	return 0;
}
