#include <bits/stdc++.h>
using namespace std;

bool hansoo(int num){
	int d;
	if(num<100) return true;
	if(num==10000) return false;
	if((num%10)-(num/10%10)==(num/10%10)-(num/100)) return true;
	else return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int n, i, cnt=0;
	cin>>n;
	for(i=1;i<=n;i++){
		if(hansoo(i)) cnt++;
	}
	cout<<cnt;
		
	return 0;
}
