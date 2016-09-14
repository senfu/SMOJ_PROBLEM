#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 100100;
const int INF = 1e9;
struct Node{
	int MAX;
	int l;
	int r;
}tree[MAX_N * 16];

int point[MAX_N * 4];

struct LINE{
	int x;
	int y;
	int c;
	int ty;
}line[MAX_N * 4];

int n,m,pn,pl;
int ans[MAX_N * 4];

bool cmp1(int p1,int p2){
	return p1<p2;
}

bool cmp2(LINE c1,LINE c2){
	if(c1.y == c2.y)
	return c1.ty<c2.ty;
	
	return c1.y<c2.y;
}

void build(int rt,int l,int r){
	
	if(l == r){
		tree[rt].l = point[l];
		tree[rt].r = point[r];
		tree[rt].MAX = -INF;
		return;
	}
	
	int mid = (l+r)/2;
	int lson = rt*2;
	int rson = rt*2+1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	tree[rt].l = tree[lson].l;
	tree[rt].r = tree[rson].r;
	tree[rt].MAX = -INF;
	return;
}

void insert(int rt,int x,int val){
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(x<l || x>r)
	return;
	
	if(l == r){
		tree[rt].MAX = max(tree[rt].MAX,val);
		return;
	}
	
	int lson = rt*2;
	int rson = rt*2+1;
	insert(lson,x,val);
	insert(rson,x,val);
	tree[rt].MAX = max(tree[lson].MAX,tree[rson].MAX);
	return;
}

int query(int rt,int a,int b){
	int l = tree[rt].l;
	int r = tree[rt].r;
	
	if(l>b || r<a)
	return -INF;
	
	if(a<=l && b>=r)
	return tree[rt].MAX;
	
	int lson = rt*2;
	int rson = rt*2+1;
	return max(query(lson,a,b),query(rson,a,b));
}

int main(){
	
	freopen("1312.in","r",stdin);
	freopen("1312.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		pl++;
		line[pl].x = x;
		line[pl].y = y;
		line[pl].c = c;
		line[pl].ty = 0;
		
		pn++;
		point[pn] = x;
		pn++;
		point[pn] = y;
	}
	
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		pl++;
		line[pl].x = x;
		line[pl].y = y;
		line[pl].c = i;
		line[pl].ty = 1;
		pn++;
		point[pn] = x;
		pn++;
		point[pn] = y;
	}
	
	sort(point+1,point+1+pn,cmp1);
	int num = 0;
	point[0]=-INF;
	for(int i=1;i<=pn;i++)
	if(point[i]!=point[i-1]){
		num++;
		point[num] = point[i];
	}
	
	sort(line+1,line+1+pl,cmp2);
	
	build(1,1,num);
	
	for(int i=1;i<=pl;i++){
		if(line[i].ty)
		ans[line[i].c] = query(1,line[i].x,line[i].y);
		else
		insert(1,line[i].x,line[i].c);
	}
	
	for(int i=1;i<=m;i++)
	if(ans[i] == -INF)
	printf("0\n");
	else
	printf("%d\n",ans[i]);

	return 0;
}
