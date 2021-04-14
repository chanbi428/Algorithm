#include <stdio.h>
using namespace std;

int digit_sum(int x){
	int sum=0;
	while(x>0){
		sum+=x%10;
		x=x/10;
	}
	return sum;
}

int main(int argc, char** argv) {
//	freopen("input.txt", "rt", stdin);
	
	int arr[100];
	int num, n, i, max=-247000000, res, sum;
	
	scanf("%d",&n);

	for(i=0;i<n;i++){
	 scanf("%d",&num);
	 sum=digit_sum(num);
	 if(sum>max){
	 	max=sum;
	 	res=num;
	 } 
	 else if(sum==max){
	 	if(res<num) res=num;	 	
	 }
	}
	printf("%d",res);
	
	return 0;
}

