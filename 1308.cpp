#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N = 60;
const long long INF = 1e18;
int n,s,t;
struct MAT{
	long long a[MAX_N][MAX_N];
	long long * const operator[](const int idx){
		return a[idx];
	}
	
	MAT operator*(MAT m1){
		MAT res;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		res[i][j]=-INF;
		
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(a[i][k]!=-INF && m1[k][j]!=-INF)
		if(a[i][k]+m1[k][j]>res[i][j])
		res[i][j]=a[i][k]+m1[k][j];

		return res;
	}
	
	
	
	void print(){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		j==n ? printf("%I64d\n",a[i][j]) : printf("%I64d ",a[i][j]);
	}

};

MAT m,m2;

MAT dfs(int k){
		if(k == 1)
		return m;
		
		MAT res = dfs(k/2);
		//res.print();
		res = res*res;

		if(k&1)
		res=res*m;

		return res;
}
	
MAT operator^(MAT tmp,int K){
	MAT res;
	res = dfs(K);
	return res;
}

MAT dfs2(int x){
	if(x == 1)
	return m2;
	
	MAT res = dfs2(x/2);
	MAT tmp = res;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(tmp[i][k]!=-INF && tmp[k][j]!=-INF)
	res[i][j]=max(res[i][j],tmp[i][k]+tmp[k][j]);
	
	if(x&1){
		tmp = res;
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(m2[i][k]!=-INF && tmp[k][j]!=-INF)
		res[i][j]=max(res[i][j],m2[i][k]+tmp[k][j]);
	}
	
	return res;
}

void deal(int k){
	MAT res = dfs2(k);
	long long ans = res[1][2];
	if(ans<-1e16)
	printf("IMPOSSIBLE\n");
	else
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("1308.in","r",stdin);
	freopen("1308.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&s,&t);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			m[i][j]=m2[i][j]=0;
			cin>>m[i][j];
			if(m[i][j] == 1000)
			m[i][j] = -INF;
		}
		m2=m^s;

		deal(t);
	}
	
	return 0;
}
