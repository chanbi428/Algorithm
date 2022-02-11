#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char bombomi[50][50];
int answer=0, n;

void rowcheck(int x){
	char color=bombomi[x][0];
	int cnt=1;
	for(int i=1; i<n; i++){
		if(color==bombomi[x][i]) cnt++;
		else{
			color=bombomi[x][i];
			answer=max(answer, cnt);
			cnt=1;
		}
	}
	answer=max(answer, cnt);
}
void columncheck(int y){
	char color=bombomi[0][y];
	int cnt=1;
	for(int i=1; i<n; i++){
		if(color==bombomi[i][y]) cnt++;
		else{
			color=bombomi[i][y];
			answer=max(answer, cnt);
			cnt=1;
		}
	}
	answer=max(answer, cnt);
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   cin>>n;
   
   for(int i=0; i<n; i++){
   	for(int j=0; j<n; j++){
   		cin>>bombomi[i][j];
	   }
   }
   for(int i=0; i<n; i++){
   	for(int j=0; j<n-1; j++){
   		swap(bombomi[i][j], bombomi[i][j+1]);
   		rowcheck(i);
   		columncheck(j);
   		columncheck(j+1);
   		swap(bombomi[i][j], bombomi[i][j+1]);
   		
   		swap(bombomi[j][i], bombomi[j+1][i]);
   		rowcheck(j);
   		rowcheck(j+1);
   		columncheck(i);
   		swap(bombomi[j][i], bombomi[j+1][i]);
	   }
   }
   cout<<answer;
   
   return 0;
}