#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void jinsoo(int x){
	if(x==0) return;
	else{
		jinsoo(x/2);
		printf("%d", x%2);
	}
}

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d",&n);
	jinsoo(n);
	
	return 0;
}

