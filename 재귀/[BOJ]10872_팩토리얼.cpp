#include <bits/stdc++.h>
using namespace std;

int n, res=1;

void fac(int num){
	if(num<1){
		cout<<res;
		return;
	}
	res*=num;
	fac(num-1);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	cin>>n;
	fac(n);
		
	return 0;
}
