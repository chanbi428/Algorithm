#include <string>
#include <vector>
#include <iostream>

using namespace std;

int block[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for(int i=0; i<puddles.size(); i++){
        block[puddles[i][1]][puddles[i][0]]=-1;
    }

    block[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(block[i][j]==-1) continue;
            if(i>1 && block[i-1][j]!=-1) block[i][j]+=block[i-1][j] %1000000007;
            if(j>1 && block[i][j-1]!=-1) block[i][j]+=block[i][j-1] %1000000007;
        }
    }

    answer = block[n][m] %1000000007;
    return answer;
}