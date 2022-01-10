# JAVA 정렬

## 객체 정렬 방법

class 객체 implements Comparable<객체>{

// 변수

// 생성자

@Override

public int compareTo(객체 p){

// 오름차순 정렬시 음수가 반환되어야 함

// 내림차순 정렬시 양수가 반환

}

}

// main

Collections.sort(arr); → compareTo에서 지정한대로 정렬됨
