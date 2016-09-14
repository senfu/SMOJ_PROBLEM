#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int MAX_N = 7003;
const long long INF = 1e15;
struct Car{
	long long s;
	long long v;
	int idx;
}car[MAX_N];
struct Data{
	long long s;
	int idx;
}ad[MAX_N];
int n,m;
int tp;

long long GetMinK(int n,int k)  
{
    int s=0,i=1,j=n;  
    Data temp;
    int beg=i;
    int end=j;
    while(s!=k)  
    {  
        beg=i;  
        end=j;  
        temp=ad[i];  
        while(i<j)  
        {  
            while(i<j && ad[j].s>=temp.s) j--;
			ad[i]=ad[j];  
            while(i<j && ad[i].s<=temp.s) i++;
			ad[j]=ad[i];  
        }  
        ad[i]=temp;  
        s=i; 

        if(s==k)  
            return ad[k].s;  
        if(s>k){i=beg;j--;} //在左侧寻找   
        if(s<k){j=end;i++;} //在右侧寻找   
    }
}  


void find(int k){
	long long num = GetMinK(n,k);
	int idx = 100000;
	bool stop = false;
	for(int i=1;i<=n;i++){
		if(ad[i].s == num && ad[i].idx < idx){
			idx = ad[i].idx;
			stop = true;
			continue;
		}
		
		if(ad[i].s != num && stop)
		break;
	}

	printf("%d\n",idx);
	return;
}

int main(){
	freopen("1316.in","r",stdin);
	freopen("1316.out","w",stdout);

	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%I64d %I64d",&car[i].v,&car[i].s);
		car[i].idx = i;
	}
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int t,k;
		scanf("%d %d",&t,&k);
		long long MAX = -1;
		int idx = 100000;
		for(int i=1;i<=n;i++){
			ad[i].s = car[i].s + car[i].v*t;
			ad[i].idx = i;
			if(ad[i].s > MAX){
				MAX = ad[i].s;
				idx = i;
			}

		}
		if(k == 1)
		printf("%d\n",idx);
		else
		find(n-k+1);
	}

	return 0;
}

