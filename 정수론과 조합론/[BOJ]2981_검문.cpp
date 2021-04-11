#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return a%b?gcd(b,a%b):b;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, res, flag;
	cin>>n;
	vector<int>num(n);
	vector<int>m;
	
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	res=num[1]-num[0];
	for(i=2;i<n;i++){
		res=gcd(res,num[i]-num[i-1]);
	}
	for(i=1;i*i<=res;i++){
		
		if(i==1) m.push_back(res);
		else if(i*i==res) cout<<i<<" ";
		else{
			if(res%i==0){
				cout<<i<<" ";
				m.push_back(res/i);
			}
		}
	}
	for(i=m.size()-1;i>=0;i--) cout<<m[i]<<" ";
	return 0;
}
