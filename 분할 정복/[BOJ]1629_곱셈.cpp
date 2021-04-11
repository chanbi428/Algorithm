#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long c){
    a=a%c;
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2==0){
		long long tmp=power(a, b/2, c);
		return tmp*tmp%c;
	}
	else{
		return a*power(a, b-1, c)%c;
	}	
}


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long a, b, c;
	cin>>a>>b>>c;
	cout<<power(a, b, c);
	
	return 0;
}
