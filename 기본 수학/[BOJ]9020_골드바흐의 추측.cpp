#include <bits/stdc++.h>
using namespace std;

int num[10001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, t, a, b;
	num[1]=-1;
	for(i=2;i<=10000;i++){
		if(num[i]==0){
			for(j=2;j*i<=10000;j++){
				num[j*i]=-1;
			}
		}
	}
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		a=b=n/2;
		while(true){
			if(num[a]==0&&num[b]==0){
				cout<<a<<" "<<b<<"\n";
				break;
			}
			a--;
			b++;
		}
	}
		
	return 0;
}
