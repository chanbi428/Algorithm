#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return a%b?gcd(b,a%b):b;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, first, i, ring, m;
	cin>>n;
	cin>>first;
	for(i=1;i<n;i++){
		cin>>ring;
		m=gcd(first, ring);
		cout<<first/m<<"/"<<ring/m<<"\n";
	}
	return 0;
}
