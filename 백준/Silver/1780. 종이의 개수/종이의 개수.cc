#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[2200][2200], n;
int answer[3];

void count(int num, int x, int y){
	int paper=arr[x][y];
	for(int i=x; i<x+num; i++){
		for(int j=y; j<y+num; j++){
			if(paper!=arr[i][j]){
				for(int ii=x; ii<x+num; ii+=num/3){
					for(int jj=y; jj<y+num; jj+=num/3){
						count(num/3, ii, jj);
					}
				}
				return;
			}
		}
	}
	answer[paper+1]++;
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   cin>>n;
   
   for(int i=0; i<n; i++){
   		for(int j=0; j<n; j++){
   			cin>>arr[i][j];
	   	}
   }
   
   count(n, 0, 0);
   for(int i=0; i<3; i++) cout<<answer[i]<<"\n";
   
   return 0;
}