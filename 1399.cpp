#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int MAX_LEN = 102;
const int M = 23;
unsigned int X;
int b[MAX_LEN];
void srand1(unsigned int S){
	X = S;
}
unsigned int nextInteger1(void){
	X = X*1103515245 + 12345;
	return (X/65536)%32768;
}
bool generator1(int N,unsigned int S){
	srand1(S);
	int num = 0;
	for(int i=1;i<=N;i++){
        num = nextInteger1()%2;
        if(num != b[i])
            return false;
	}

    return true;
}

int T;
char s[MAX_LEN*2000];
int main(){
	freopen("1399.in","r",stdin);
	freopen("1399.out","w",stdout);

	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%s",&s);

		bool bo = false;
		int len = strlen(s);
		len = min(M,len);
		for(int i=0;i<len;i++)
            b[i+1] = s[i]-'0';

		for(unsigned int k=1;k<=232323;k++)
            if(generator1(len,k)){
				cout<<"LCG"<<endl;
				bo = true;
				break;
			}

		if(!bo)
		cout<<"Xorshift"<<endl;
	}

	return 0;

}
