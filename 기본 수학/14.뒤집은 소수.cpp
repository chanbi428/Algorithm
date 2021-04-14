#include <stdio.h>
using namespace std;

int reverse(int x){
	int rev=0;
	while(x>0){
		rev=rev*10+(x%10);
		x=x/10;
	}
	return rev;
}

bool isPrime(int x){
	int i;
	for(i=2;i<x;i++){
		if(x%i==0) return false;
	}
	if(x==1) return false;
	return true;
}

int main(int argc, char** argv) {
	//freopen("input.txt", "rt", stdin);

	int n, i, num, rev;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d", &num);
		rev=reverse(num);
		if(isPrime(rev)==true) printf("%d ",rev);
	}
	
	return 0;
}

