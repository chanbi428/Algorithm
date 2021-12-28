# JAVA 문자열 사용

대문자 변환 → str.toUpperCase();

소문자 변환 → str.toLowerCase();

문자 변환시에는 → Charater.toUppserCase(c);

인덱스 접근시에 str[0] X , str.charAt(0) O

foreach문 쓸때 String은 사용 불가해서 문자 배열로 만들어야함 → str.toCharArray()

해당 문자가 대소문자인지 확인 → Character.isUpperCase(), Charater.isLowerCase()

str.indexOf(문자나 문자열) → 못찾으면 -1, 처음으로 발견된 인덱스 넘버

str.lastindexOf(문자나 문자열) → 못찾으면 -1, 뒤에서 처음으로 발견된 인덱스 넘버

str.indexOf(문자나 문자열, 찾기 시작할 위치)

str.substring(시작위치(0),마지막위치)

String tmp = new StringBuilder(str) ⇒ string은 불변, 연산이 많아질수록 성능 저하 StringBuilder는 하나의 메모리에서 계속 연산하므로 효율적

문자열 문자배열로 만들기 → char c[] = str.toCharArray();

문자배열 문자열로 만들기 → String str = String.valueOf(c);

문자가 알파벳인지 확인 → Character.isAlphabetic(c);

특정 문자 변환 → str.replace(’aa’,’b’) aa를 b로 변환, replaceAll(정규표현식, 문자)

문자를 숫자로 변환 → Integer.parseInt(str);

문자가 숫자인지 확인 → Character.isDigit(c);

이진수 문자열을 숫자로 변경 → Integer.parseInt(str, 2);
