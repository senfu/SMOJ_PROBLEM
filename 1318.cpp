#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
typedef short int BYTE;
typedef long long LL;
const int MAX_N = 8005;
BYTE a[MAX_N][MAX_N];
BYTE ax[MAX_N][MAX_N];
BYTE ay[MAX_N][MAX_N];
BYTE axy[MAX_N][MAX_N];
int lastans;
int n,m,q,op,x1i,x2i,y1i,y2i,N;

void add(BYTE A[MAX_N][MAX_N],int x,int y,int val){
	int tmp = 0;
	for(int i=x;i<=N;i+=lowbit(i))
	for(int j=y;j<=N;j+=lowbit(j)){
		tmp = (int)A[i][j]+val;
		tmp%=q;
		A[i][j] = tmp;
	}
	
	return;
}

LL get(BYTE A[MAX_N][MAX_N],int x,int y){
	LL sum = 0;
	for(int i=x;i>0;i-=lowbit(i))
	for(int j=y;j>0;j-=lowbit(j)){
		sum+=(int)A[i][j];
		sum%=q;
	}
	return sum;
}

LL getSum(int x,int y){
	LL t1 = ((x+1)*(y+1)*get(a,x,y))%q;
	LL t2 = ((y+1)*get(ax,x,y))%q;
	LL t3 = ((x+1)*get(ay,x,y))%q;
	LL t4 = get(axy,x,y)%q;
	LL res = t1-t2-t3+t4;

	return res;
}

void update(int x1,int y1,int x2,int y2){

	add(a,x1,y1,1);
	add(a,x2+1,y2+1,1);
	add(a,x2+1,y1,-1);
	add(a,x1,y2+1,-1);
	
	add(ax,x1,y1,x1);
	add(ax,x2+1,y2+1,x2+1);
	add(ax,x2+1,y1,-(x2+1));
	add(ax,x1,y2+1,-x1);
	
	add(ay,x1,y1,y1);
	add(ay,x2+1,y2+1,y2+1);
	add(ay,x2+1,y1,-y1);
	add(ay,x1,y2+1,-(y2+1));
	
	add(axy,x1,y1,x1*y1);
	add(axy,x2+1,y2+1,(x2+1)*(y2+1));
	add(axy,x2+1,y1,-(x2+1)*y1);
	add(axy,x1,y2+1,-x1*(y2+1));
	
	/*
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	if(j == N)
	printf("%d\n",(int)a[i][j]);
	else
	printf("%d ",(int)a[i][j]);
	
	printf("\n");
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	if(j == N)
	printf("%d\n",(int)ax[i][j]);
	else
	printf("%d ",(int)ax[i][j]);

	printf("\n");
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	if(j == N)
	printf("%d\n",(int)ay[i][j]);
	else
	printf("%d ",(int)ay[i][j]);

	printf("\n");
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	if(j == N)
	printf("%d\n",(int)axy[i][j]);
	else
	printf("%d ",(int)axy[i][j]);

	printf("\n");	
	*/
	return;
}

void ask(long long x1,long long y1,long long x2,long long y2){
	LL sum1 = getSum(x2,y2);
	LL sum2 = getSum(x1-1,y1-1);
	LL sum3 = getSum(x2,y1-1);
	LL sum4 = getSum(x1-1,y2);
	LL ans = sum1+sum2-sum3-sum4;
	while(ans<0)
	ans+=q;
	ans%=q;
	lastans+=ans;
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("1318.in","r",stdin);
	freopen("1318.out","w",stdout);

	int x1,x2,y1,y2;

	scanf("%d %d %d",&n,&m,&q);
	N = n+1;

	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d %d",&op,&x1i,&x2i,&y1i,&y2i);
		x1=(x1i+lastans)%n;
		x2=(x2i+lastans)%n;
		y1=(y1i+lastans)%n;
		y2=(y2i+lastans)%n;
		if(x2<x1) swap(x2,x1);
		if(y2<y1) swap(y2,y1);
		x1++;
		x2++;
		y1++;
		y2++;
		if(op == 1)
		update(x1,y1,x2,y2);
		else
		ask(x1,y1,x2,y2);
	}
	return 0;
}
