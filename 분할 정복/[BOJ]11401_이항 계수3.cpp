#include <bits/stdc++.h>
using namespace std;

long long p = 1000000007;

long long power(long long a, long long b){
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2==0){
		long long tmp=power(a, b/2);
		return tmp*tmp%p;
	}
	else{
		return a*power(a, b-1)%p;
	}	
}

long long persoma(long long n, long long k){
	long long a=1, b=1, i;
	for(i=n;i>=1;i--){
		a*=i;
		a%=p;
	}
	for(i=k;i>=1;i--){
		b*=i;
		b%=p;
	}
	for(i=n-k;i>=1;i--){
		b*=i;
		b%=p;
	}
	return a*power(b,p-2)%p;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long n, k;
	cin>>n>>k;
	cout<<persoma(n,k);
	
	return 0;
}
