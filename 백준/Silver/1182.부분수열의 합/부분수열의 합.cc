#include <iostream>
#include <vector>

using namespace std;

int answer=0, n, s;

void check(vector<int>&num, int sum, int index, int end_n, int cnt){
    if(cnt==end_n){
        if(sum==s){
            answer++;
            //cout<<answer<<"\n";
        }
        return;
    }
    for(int i=index; i<n; i++){
        //cout<<"i:"<<i<<" num[i]:"<<num[i]<<" sum:"<<sum<<" sum+num[i]"<<sum+num[i]<<" end_n:"<<end_n<<" cnt:"<<cnt<<"\n";
        check(num, sum+num[i], i+1, end_n, cnt+1);
    }
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>s;
	vector<int> num(n);
	
	for(int i=0; i<n; i++) cin>>num[i];
    
    for(int i=1; i<=n; i++) check(num, 0, 0, i, 0);
    
    cout<<answer;
	
	return 0;
}