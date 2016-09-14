#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
#define lowbit(x) (x&(-(x)))
const int MAX_S = 1030;
int a[MAX_S][MAX_S];
int S,op,x1,y1,x2,y2,val;

void add(int x,int y,int val){
	for(int i=x;i<=S;i+=lowbit(i))
	for(int j=y;j<=S;j+=lowbit(j))
	a[i][j]+=val;
	
	return;
}

int gs(int x,int y){
	int sum = 0;
	for(int i=x;i;i-=lowbit(i))
	for(int j=y;j;j-=lowbit(j))
	sum+=a[i][j];
	return sum;
}

int ask(int x1,int y1,int x2,int y2){
	return gs(x2,y2)+gs(x1-1,y1-1)-gs(x1-1,y2)-gs(x2,y1-1);
}

int main(){
	freopen("1324.in","r",stdin);
	freopen("1324.out","w",stdout);
	
	while(scanf("%d",&op),op!=3){
		if(op == 0)
			scanf("%d",&S);
		else
		if(op == 1){
			scanf("%d %d %d",&x1,&y1,&val);
			x1++;
			y1++;
			add(x1,y1,val);
		}
		else{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++;
			y1++;
			x2++;
			y2++;
			printf("%d\n",ask(x1,y1,x2,y2));
		}
	}
	return 0;
}

