#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, num;
	priority_queue<int>max_heap;
	priority_queue<int>min_heap;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		if(i%2==0) max_heap.push(num);
		else min_heap.push(-num);
		if(max_heap.size()!=0 && min_heap.size()!=0 && max_heap.top()>-min_heap.top()){
			min_heap.push(-max_heap.top());
			max_heap.pop();
			max_heap.push(-min_heap.top());
			min_heap.pop();
		}
		cout<<max_heap.top()<<"\n";
	}

	
	return 0;
}
