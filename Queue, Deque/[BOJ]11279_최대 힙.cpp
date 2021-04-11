#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, num;
	priority_queue<int>max_heap;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		if(num==0){
			if(max_heap.empty()) cout<<"0\n";
			else{
				cout<<max_heap.top()<<"\n";
				max_heap.pop();
			}
		}
		else max_heap.push(num);
	}

	
	return 0;
}
