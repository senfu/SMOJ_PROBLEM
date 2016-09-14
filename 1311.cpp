#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int MAX_N = 62;
const int dx[]={0,-1,0,0,1};
const int dy[]={0,0,-1,1,0};
struct POINT{
	int x;
	int y;
	int high;
}p[MAX_N * MAX_N];

int f[MAX_N * MAX_N][MAX_N * MAX_N];
int rank[MAX_N][MAX_N];
int pos[MAX_N][MAX_N];
int n,m,pn;
int ix,iy,jx,jy,ih,jh,posj,posi,k,nh,nx,ny,cx,cy,ans;

bool cmp(POINT p1,POINT p2){
	return p1.high<p2.high;
}

int main(){
	freopen("1311.in","r",stdin);
	freopen("1311.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		int x;
		scanf("%d",&x);
		pn++;
		p[pn].x = i;
		p[pn].y = j;
		p[pn].high = x;
	}
	
	sort(p+1,p+1+pn,cmp);
	int num = 0;
	p[0].high = -1;
	for(int i=1;i<=pn;i++){
		if(p[i].high != p[i-1].high)
		num++;
		rank[p[i].x][p[i].y] = num;
		 pos[p[i].x][p[i].y] = i;
	}
	
	if(num == 1){
		printf("1\n");
		return 0;
	}
	
	
	for(int i=1;i<=pn;i++)
	for(int j=1;j<i;j++){

		ix = p[i].x;
		iy = p[i].y;
		jx = p[j].x;
		jy = p[j].y;
		ih = rank[ix][iy];
		jh = rank[jx][jy];
		posi = pos[ix][iy];
		posj = pos[jx][jy];
		
		
		for(int w=1;w<=4;w++){
			nx = ix+dx[w];
			ny = iy+dy[w];
			
			if(nx<1 || nx>n || ny<1 || ny>m)
			continue;
			
			if(rank[nx][ny]>=ih)
			continue;
			
			nh = rank[nx][ny];
			k = pos[nx][ny];
			if( (nh < ih && nh < jh)  || (nh <ih && nh == jh && k!=posi && k!=posj))
				f[i][j] = max(f[i][j], f[j][k]+1);
		}
		
		for(int w=1;w<=4;w++){
			nx = jx+dx[w];
			ny = jy+dy[w];
			
			if(nx<1 || nx>n || ny<1 || ny>m)
			continue;
			
			if(rank[nx][ny]>=jh)
			continue;
			
			nh = rank[nx][ny];
			k = pos[nx][ny];
			if( (nh < ih && nh < jh) || (nh == ih && nh < jh && k!=posj && k!=posi) )
				f[i][j] = max(f[i][j], f[i][k]+1);
		}
	}
	/*
	for(int i=1;i<=pn;i++)
	for(int j=1;j<=pn;j++)
	if(j == pn)
	printf("%d\n",f[i][j]);
	else
	printf("%d ",f[i][j]);
	*/
	
	ans = -1;

	for(int i=1;i<=pn;i++)
	for(int j=1;j<=i;j++){
		if(i == j)
		continue;
		
		ix = p[i].x;
		iy = p[i].y;
		jx = p[j].x;
		jy = p[j].y;
		ih = rank[ix][iy];
		jh = rank[jx][jy];
		
		cx = abs(ix-jx);
		cy = abs(iy-jy);
		
		if( (cx==0 && cy==2) || (cy==0 && cx==2)){
			nx = (ix+jx)/2;
			ny = (iy+jy)/2;
			nh = rank[nx][ny];
			if( nh>ih && nh>jh )
			ans = max(ans,f[i][j]+3);
		}
		
		if( (cx==0 && cy==1) || (cy==0 && cx==1) )
		if( ih<jh || jh<ih )
		ans = max(ans,f[i][j]+2);
	}
	
	if(ans == -1)
	printf("0\n");
	else
	printf("%d\n",ans);
	
	return 0;
}
