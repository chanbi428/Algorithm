#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, num, cnt=1;
	stack<int>seq;
	vector<char>res;
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		while(num>=cnt){
			seq.push(cnt++);
			res.push_back('+');
		}
		if(num==seq.top()){
			seq.pop();
			res.push_back('-');
		}
		else{
			cout<<"NO";
			return 0;
		}
	}
	for(i=0;i<res.size();i++){
		cout<<res[i]<<"\n";
	}
	
	return 0;
}
