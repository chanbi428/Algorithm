#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int n, k, i, cnt=0;
	stack<int> res;
	
	scanf("%d %d",&n,&k);
	
	while(1){
		res.push(n%k);
		cnt++;
		if(n/k==0) break;
		n=n/k;
	}
	
	for(i=0;i<cnt;i++){
		if(res.top()>9) printf("%c",res.top()+55);
		else printf("%d",res.top());
		res.pop();
	}
	
	return 0;
}

