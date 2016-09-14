#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
const int MAX_N = 1100;
int g[MAX_N][MAX_N];
int n,T,X;
int op[5],x1,y1,x2,y2;

void update(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i))
	for(int j=y;j<=n;j+=lowbit(j))
	g[i][j]++;
	return;
}

void query(int x,int y){
	int sum = 0;
	for(int i=x;i>0;i-=lowbit(i))
	for(int j=y;j>0;j-=lowbit(j))
	sum+=g[i][j];
	
	if(sum & 1)
	printf("1\n");
	else
	printf("0\n");
	
	return;
}

int main(){
	freopen("1322.in","r",stdin);
	freopen("1322.out","w",stdout);
	
	scanf("%d",&X);
	while(X--){
		memset(g,0,sizeof(g));
		scanf("%d %d",&n,&T);
		while(T--){
			scanf("%s%d%d",&op,&x1,&y1);
			if(op[0] == 'C'){
				scanf("%d %d",&x2,&y2);
				x1++;
				y1++;
				x2++;
				y2++;
				update(x2,y2);
				update(x1-1,y1-1);
				update(x2,y1-1);
				update(x1-1,y2);
			}
			else
			query(x1,y1);
		}
		printf("\n");
	}
	return 0;
}
