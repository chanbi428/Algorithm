#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[21];

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, num;
	string str;
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>str;
		if(str=="add"){
			cin>>num;
			arr[num]=1;
		}
		else if(str=="remove"){
			cin>>num;
			arr[num]=0;
		}
		else if(str=="check"){
			cin>>num;
			cout<<arr[num]<<"\n";
		}
		else if(str=="toggle"){
			cin>>num;
			if(arr[num]==1) arr[num]=0;
			else arr[num]=1;
		}
		else if(str=="all"){
			for(int j=1; j<=20; j++) arr[j]=1;
		}
		else{
			for(int j=1; j<=20; j++) arr[j]=0;
		}
	}
	
	return 0;
}