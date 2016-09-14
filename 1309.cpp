#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 30;
const int MAX_NUM = 95;
const int INF = 1e9;
int v[MAX_N];
int f[MAX_N][MAX_NUM][MAX_NUM];
int t,n;
int sum;

bool check(int num){

	memset(f,0x7f,sizeof(f));
	memset(f[0],0,sizeof(f[0]));
	
	for(int i=1;i<=n;i++)
	for(int x=0;x<=num;x++)
	for(int y=0;y<=num;y++)
	for(int a=0;a<=7&&a<=x;a++)
	for(int b=0;b<=20&&b<=y;b++)
	if(f[i-1][x-a][y-b]<=num){
		int one = v[i]-9*a-3*b;
		if(one<0)
		one=0;
		if(a+b+one <= num)
		f[i][x][y] = min(f[i][x][y], one+f[i-1][x-a][y-b]);
	}
	
	if(f[n][num][num]<=num)
	return true;
	
	return false;
}

void solve(){
	int l = sum/13-1;
	int r = 93;
	while(l+1<r){
		int mid = (l+r)>>1;
		if(check(mid))
		r=mid;
		else
		l=mid;
	}
	
	cout<<r<<endl;
	return;
}

int main(){
	freopen("1309.in","r",stdin);
	freopen("1309.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof(v));
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&v[i]);
			sum+=v[i];
		}
		solve();
	}

	return 0;
}
