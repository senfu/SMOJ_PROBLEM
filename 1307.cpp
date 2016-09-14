#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N = 500100;
const int INF = 1001000000;
struct POINT{
	int x;
	int idx;
	bool left;
}point[MAX_N * 2];
struct LINE{
	int x;
	int y;
	int len;
}line[MAX_N];

int cnt[MAX_N * 8];
int add[MAX_N * 8];
int n,m,pn,ln;
int head,tail;
int ans = INF;
int num = 0;

bool cmp1(POINT p1,POINT p2){
	if(p1.x == p2.x && p1.idx != p2.idx)
	return p1.idx<p2.idx;
	
	return p1.x<p2.x;
}

bool cmp2(LINE l1,LINE l2){
	return l1.len<l2.len;
}

void down(int rt){
	int lson = rt*2;
	int rson = rt*2+1;
	cnt[lson]+=add[rt];
	cnt[rson]+=add[rt];
	add[lson]+=add[rt];
	add[rson]+=add[rt];
	add[rt]=0;
	return;
}

void insert(int rt,int l,int r,int a,int b,int val){
	if( b<l || a>r )
	return;
	
	if(a<=l && b>=r){
		add[rt]+=val;
		cnt[rt]+=val;
		return;
	}
	
	down(rt);
	
	int lson = rt*2;
	int rson = rt*2+1;
	int mid = (l+r)/2;
	
	insert(lson,l,mid,a,b,val);
	insert(rson,mid+1,r,a,b,val);
	cnt[rt] = max(cnt[rt*2],cnt[rt*2+1]);
	return;
}

void solve(){
	head=tail=1;
	insert(1,1,num,line[head].x,line[head].y,1);
	if(cnt[1]>=m)
	ans = min(ans,line[head].len - line[tail].len);
	
	while(head < n){
		head++;
		insert(1,1,num,line[head].x,line[head].y,1);
		while(cnt[1]>=m){
			ans = min(ans,line[head].len - line[tail].len);
			insert(1,1,num,line[tail].x,line[tail].y,-1);
			tail++;
		}
	}
	
	if(ans == INF)
	printf("-1\n");
	else
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("1307.in","r",stdin);
	freopen("1307.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		pn++;
		point[pn].x = x;
		point[pn].idx = i;
		point[pn].left = true;
		pn++;
		point[pn].x = y;
		point[pn].idx = i;
		point[pn].left = false;
		line[i].len = y-x;
	}
	
	sort(point+1,point+1+pn,cmp1);
	
	point[0].x = -1;
	for(int i=1;i<=pn;i++){
		if(point[i].x!=point[i-1].x)
		num++;
		if(point[i].left)
		line[point[i].idx].x = num;
		else
		line[point[i].idx].y = num;
	}
	
	sort(line+1,line+1+n,cmp2);
	
	solve();
	
	return 0;
}

