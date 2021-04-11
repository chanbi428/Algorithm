#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, num, sum=0;
	stack<int> money;
	cin>>n;
	while(n--){
		cin>>num;
		if(num==0){
			sum-=money.top();
			money.pop();
		}
		else{
			sum+=num;
			money.push(num);
		}
	}
	cout<<sum;
	
	return 0;
}
