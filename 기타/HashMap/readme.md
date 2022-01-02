# JAVA HashMap 사용법

[https://coding-factory.tistory.com/556](https://coding-factory.tistory.com/556)

HashMap<String,String> map1 = new HashMap<String,String>();//HashMap생성

HashMap<String,String> map2 = new HashMap<>();//new에서 타입 파라미터 생략가능

HashMap<String,String> map3 = new HashMap<>(map1);//map1의 모든 값을 가진 HashMap생성

HashMap<String,String> map4 = new HashMap<>(10);//초기 용량(capacity)지정

HashMap<String,String> map5 = new HashMap<>(10, 0.7f);//초기 capacity,load factor지정

HashMap<String,String> map6 = new HashMap<String,String>(){{//초기값 지정
put("a","b");
}};

map.getOrDefault(x,0) → value를 가져오는데 만약에 key가 없으면 0을 리턴

map.containsKey(’A’) → A라는 key가 있는지 리턴

map.size() → key의 갯수

map.remove(’A’) → A를 삭제하고 A의 value값 리턴

map.keySet() → key의 모음, map을 탐색할때 사용
