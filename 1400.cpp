#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
struct DATA{
	int dis;
	int x;
	int y;
};
const int INF = 0x1f1f1f1f;
const int MAX_N = 200;
const int dx[] = {0,0,0,1,-1};
const int dy[] = {0,1,-1,0,0};
int Dis[MAX_N][MAX_N];
int n,m;
int map[MAX_N][MAX_N];
string s;
queue<DATA> q;
int ans = INF;

void deal(){
	DATA d;
	
	if(map[1][1]>=1){
		int vx,vy;
		bool bo = false;
		for(int i=1;i<=n;i++){
			if(bo)
			break;
			for(int j=1;j<=m;j++)
			if(i!=1 && j!=1 && map[i][j] == map[1][1]){
				vx = i;
				vy = j;
				bo = true;
				break;
			}
		}
		
		d.dis = 0;
		d.x = vx;
		d.y = vy;
		Dis[vx][vy] = 0;
		q.push(d);
	}
	else
	{
		Dis[1][1] = 0;
		d.dis = 0;
		d.x = 1;
		d.y = 1;
		q.push(d);
	}

	int x,y,dis;
	while(!q.empty()){
		d = q.front();
		q.pop();
		x = d.x;
		y = d.y;
		dis = d.dis;
		
		if(x == n && y == m){
			ans = min(ans,dis);
			continue;
		}
		
		
		if(map[x][y] == -1)
		continue;

		for(int i=1;i<=4;i++)
		if(x+dx[i]>=1 && x+dx[i]<=n && y+dy[i]>=1 && y+dy[i]<=m){
			int vx = x+dx[i];
			int vy = y+dy[i];

			if(map[vx][vy] == -1)
			continue;
			
			if(map[vx][vy] != 0){
				bool bo = false;
				for(int i=1;i<=n;i++){
					if(bo)
					break;
					for(int j=1;j<=m;j++)
						if((i!=vx || j!=vy )&& map[i][j] == map[vx][vy]){
						
						vx = i;
						vy = j;
						bo = true;
						break;
					}
					
				}
			
			}
			
				if(dis+1<Dis[vx][vy]){
					
					Dis[vx][vy] = dis+1;
					d.x = vx;
					d.y = vy;
					d.dis = dis+1;
					q.push(d);
				}
		}
		
	}
	

	if(Dis[n][m] == INF)
	cout<<"No Solution"<<endl;
	else
	cout<<ans<<endl;
}

int main(){
	freopen("1400.in","r",stdin);
freopen("1400.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	
	memset(Dis,0x1f,sizeof(Dis));
	
	for(int i=1;i<=n;i++){
		cin>>s;
		int len = s.length();
		for(int j=0;j<len;j++)
		if(s[j] == '1')
		map[i][j+1] = -1;
		else
		if(s[j] >= 'A' && s[j] <= 'Z')
		map[i][j+1] = s[j]-'A'+1;
	}
	deal();
	return 0;
}
