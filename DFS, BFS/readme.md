## 조합(DFS)
```java
static int total = 0, n=0;  //전역변수들 static으로 선언
	static boolean flag = false;
	static String answer = "NO";
	
	void solution(int L, int sum, int arr[]) { 
		if(flag || sum>total/2) return;  //이미 답이 정해진 경우 flag로 더이상 확인하지 않음
		if(sum==total/2) {  //조건에 맞았을때
			answer = "YES";
			flag = true;
			return;
		}
		if(L==n) return;  //끝까지 탐색했을 때
		solution(L+1, sum+arr[L], arr);  //현재 index를 더해서 넘기기
		solution(L+1, sum, arr);  //현재 index를 더하지 않고 넘기기
```
