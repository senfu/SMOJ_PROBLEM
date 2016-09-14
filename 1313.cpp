#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 110;
int a[MAX_N];
int n;
bool f[MAX_N][MAX_N][MAX_N][2];

void deal(){

	f[2][a[1]][a[2]][0]=true;
	
	for(int i=2;i<=100;i++)
	for(int j=a[i-1];j>=0;j--)
	for(int k=a[i];k>=0;k--){
		
		f[i][j][k][1]|=f[i][j][k+2][0];
		f[i][j][k][1]|=f[i][j+2][k][0];
		f[i][j][k][0]|=f[i][j][k+4][0];
		f[i][j][k][0]|=f[i][j+4][k][0];
		f[i][j][k][0]|=f[i][j+3][k][0];
		f[i][j][k][0]|=f[i][j][k+3][0];
		f[i][j][k][1]|=f[i][j][k+4][1];
		f[i][j][k][1]|=f[i][j+4][k][1];
		f[i][j][k][1]|=f[i][j+3][k][1];
		f[i][j][k][1]|=f[i][j][k+3][1];
		
		/*
		if(f[i][j][k+2][0]) f[i][j][k][1]=true;
		if(f[i][j+2][k][0]) f[i][j][k][1]=true;
		if(f[i][j][k+4][0]) f[i][j][k][0]=true;
		if(f[i][j][k+3][0]) f[i][j][k][0]=true;
		if(f[i][j+4][k][0]) f[i][j][k][0]=true;
		if(f[i][j+3][k][0]) f[i][j][k][0]=true;
		if(f[i][j][k+4][1]) f[i][j][k][1]=true;
		if(f[i][j][k+3][1]) f[i][j][k][1]=true;
		if(f[i][j+4][k][1]) f[i][j][k][1]=true;
		if(f[i][j+3][k][1]) f[i][j][k][1]=true;
		*/
		int tmp = a[i] - k;
		if( tmp > a[i-2] || j+tmp > a[i-1] )
		continue;
		
		f[i][j][k][0]|=f[i-1][tmp][j+tmp][0];
		f[i][j][k][1]|=f[i-1][tmp][j+tmp][1];
		/*
		if(f[i-1][tmp][j+tmp][0]) f[i][j][k][0] = true;
		if(f[i-1][tmp][j+tmp][1]) f[i][j][k][1] = true;
		*/
	}
	
	if(f[100][0][0][1])
	printf("Yes\n");
	else
	printf("No\n");
	
	return;
}

int main(){
	freopen("1313.in","r",stdin);
	freopen("1313.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		memset(f,false,sizeof(f));
		for(int i=1;i<=100;i++) scanf("%d",&a[i]);
		deal();
	}
	return 0;
}
