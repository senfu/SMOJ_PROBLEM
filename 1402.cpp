#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 2e7;
const int Root = 1;
struct node{
	int son[5];
	int last;
	int len;
	void init(){
		memset(son,-1,sizeof(son));
		last = 1;
		len = 0;
		return;
	}
};
int n,m;
node mem[MAX_N];
char s[MAX_N/2];
int mp = 1;

void add(int num){
	int len = strlen(s);
	int idx = Root;
	for(int i=0;i<len;i++){
		if(mem[idx].son[s[i]-'a'] == -1){
			mp++;
			mem[mp].init();
			mem[idx].son[s[i]-'a'] = mp;
		}
		
		idx = mem[idx].son[s[i]-'a'];
		
		//cout<<idx<<endl;
		
		mem[idx].len = max(mem[idx].len, num-mem[idx].last);
		mem[idx].last = num+1;
	}
}

void deal(){

	for(int i=2;i<=mp;i++)
	mem[i].len = max(mem[i].len,n-mem[i].last+1);
	
	//for(int i=2;i<=mp;i++)
	//cout<<mem[i].len<<endl;
	return;
}

void query(){
	int len = strlen(s);
	int idx = Root;
	for(int i=0;i<len;i++){
		idx = mem[idx].son[s[i]-'a'];
		if(idx == -1){
			printf("%d\n",n);
			return;
		}
	}
	
	
	//cout<<mem[1].son[1]<<endl;
	
	printf("%d\n",mem[idx].len);
	return;
}

int main(){
	freopen("1402.in","r",stdin);
	freopen("1402.out","w",stdout);
	
	mem[Root].init();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",&s);
		add(i);
	}
	
	deal();
	
	for(int i=1;i<=m;i++){
		scanf("%s",&s);
		query();
	}
	
	return 0;
}
