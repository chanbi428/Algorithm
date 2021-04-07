#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int a, b, v, res;
	cin>>a>>b>>v;
	if((v-a)%(a-b)==0) res=(v-a)/(a-b)+1;
	else res=(v-a)/(a-b)+2;
	cout<<res;
		
	return 0;
}
