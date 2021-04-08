#include <bits/stdc++.h>
using namespace std;

int ch[42];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, cnt=0;
	for(int i=0;i<10;i++){
		cin>>a;
		if(ch[a%42]==0){
			cnt++;
			ch[a%42]=1;
		}
	}
	cout<<cnt;
	return 0;
}
