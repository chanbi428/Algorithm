#include <bits/stdc++.h>
using namespace std;

int ch[50], ch2[50], zero[50], one[50];

int fzero(int n){
	if(ch[n]==1) return zero[n];
	if(n==0) return 1;
	if(n==1) return 0;
	else{
		ch[n]=1;
		return zero[n]=fzero(n-1)+fzero(n-2);
	}
}
int fone(int n){
	if(ch2[n]==1) return one[n];
	if(n==0) return 0;
	if(n==1) return 1;
	else{
		ch2[n]=1;
		return one[n]=fone(n-1)+fone(n-2);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int t, n;
	
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<fzero(n)<<" "<<fone(n)<<"\n";
	}
		
	return 0;
}
