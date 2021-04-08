#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, tmp, cnt=0;
	cin>>a;
	tmp=a;
	while(true){
		tmp=(tmp%10*10)+((tmp/10+tmp%10)%10);
		cnt++;
		if(tmp==a) break;
	}
	cout<<cnt;
	 
	return 0;
}
