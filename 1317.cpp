#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int MAX_N = 40;
const int INF = 1e8;
const int MAX_DAY = 200;
struct EDGE{
	int x;
	int next;
	int dis;
}e[MAX_N * MAX_N * 2];
int h[MAX_N];
int n,m,K,E,ep;
int g[MAX_N][MAX_N];
bool ok[MAX_N][MAX_DAY];
bool vis[MAX_N];
int dis[MAX_N];
int cost[MAX_DAY][MAX_DAY];
int dp[MAX_DAY];
queue<int> q;

void addedge(int x,int y,int d){
	ep++;
	e[ep].x = y;
	e[ep].next = h[x];
	e[ep].dis = d;
	h[x] = ep;
	return;
}

void SPFA(int be,int en){
	memset(vis,false,sizeof(vis));
	fill(dis+1,dis+m+1,INF);
	
	q.push(1);
	vis[1] = true;
	dis[1]=0;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=h[x];i!=-1;i=e[i].next){
			int v = e[i].x;

			int j;
			for(j=be;j<=en;j++)
			if(!ok[v][j])
			break;
			if(j!=en+1)
			continue;

			if(dis[v] > dis[x]+e[i].dis){
				vis[v] = true;
				dis[v] = dis[x]+e[i].dis;
				q.push(v);
			}
		}
		vis[x] = false;
	}
	
	if(dis[m] == INF)
	cost[be][en]=-1;
	else
	cost[be][en] = dis[m];
	
	return;
}

int main(){
	freopen("1317.in","r",stdin);
	freopen("1317.out","w",stdout);
	
	memset(h,-1,sizeof(h));
	memset(ok,true,sizeof(ok));
	
	scanf("%d %d %d %d",&n,&m,&K,&E);
	for(int i=1;i<=E;i++){
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		addedge(x,y,d);
		addedge(y,x,d);
	}
	
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++){
		int P,a,b;
		scanf("%d %d %d",&P,&a,&b);

		for(int i=a;i<=b;i++)
		ok[P][i] = false;
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	SPFA(j,i);
	
	fill(dp+1,dp+1+n,INF);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++){
		if(cost[j+1][i] == -1)
		continue;
		dp[i] = min(dp[i],(dp[j]+cost[j+1][i]*(i-j)+K));
	}
	
	
	cout<<dp[n]-K<<endl;
	return 0;
}
