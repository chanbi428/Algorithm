#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int a, b, res=0;
	cin>>a>>b;
	a=(a%10*100)+(a/100)+(a%100/10*10);
	b=(b%10*100)+(b/100)+(b%100/10*10);
	res=max(a, b);
	cout<<res;
		
	return 0;
}
