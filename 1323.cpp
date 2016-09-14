#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 65540;
const int MAX_M = 300000;
const int M = 65536;
int R,seed,n,k;
long long sum = 0;
long long mul = 0;
long long Add = 0;
int mid = 0;
long long v[MAX_M]={0};
int p = 0;
long long tree[MAX_N * 4]={0};

void add(int num,int val){
	int idx = M-1+num;
	tree[idx]+=val;
	
	while(true){
		if(idx == 1)
		break;
		idx/=2;
		tree[idx]+=val;
	}

	return;
}

long long ask(int x){
	int num = tree[1];
	int idx = 1;
	while(idx<M){
		if(tree[idx*2]>=x)
		idx = idx*2;
		else{
			x-=tree[idx*2];
			idx = idx*2+1;
		}
	}
	
	return idx-M+1;
}

void query(int x){
	long long ans = ask(x);
	ans--;
	sum += ans;
	return;
}

int main(){
	freopen("1323.in","r",stdin);
	freopen("1323.out","w",stdout);
	
	scanf("%d",&R);
	while(R--){
		memset(tree,0,sizeof(tree));
		p=0;
		mid = 0;
		sum = 0;

		scanf("%d %I64d %I64d %d %d",&seed,&mul,&Add,&n,&k);
		
		if(k&1)
		mid = (k+1)/2;
		else
		mid = k/2;
		
		v[1] = seed;
		add(v[1]+1,1);
		
		for(int i=2;i<=k;i++){
			v[i]=(v[i-1]*mul+Add)%65536;
			add(v[i]+1,1);
		}
		
		query(mid);
		
		for(int i=k+1;i<=n;i++){
			p++;
			add(v[p]+1,-1);
			
			v[i]=(v[i-1]*mul+Add)%65536;
			add(v[i]+1,1);

			query(mid);
		}
		cout<<sum<<endl;
	}
	return 0;
}
