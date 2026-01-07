# [Diamond IV] Circle of digits - 10351 

[문제 링크](https://www.acmicpc.net/problem/10351) 

### 성능 요약

메모리: 71300 KB, 시간: 7512 ms

### 분류

그리디 알고리즘, 문자열, 이분 탐색, 매개 변수 탐색, 접미사 배열과 LCP 배열

### 제출 일자

2026년 1월 7일 10:58:50

### 문제 설명

<p>You are given a circular string of length N that consists of digits '1'..'9'. You want to split it into K continuous non-empty parts. Each of those parts represents a decimal notation of some integer number. Your goal is to find a partition that minimizes the maximum integer from the partition at hand.</p>

<p>For example, if the string is 7654321 and K=3 then the optimal partition is: {176, 54, 32} which has 176 as the maximum number. Note that the string is cyclic, that is the first character goes right after the last one (as in the 176 part of the above example).</p>

### 입력 

 <p>The first line of the input contains two integers N and K (3 ≤ N ≤ 100000, 2 ≤ K ≤ N). The second line contains a string of length N which consists only of characters ‘1’..’9’.</p>

### 출력 

 <p>Output the value of the maximal number in the optimal partition.</p>

<p> </p>

