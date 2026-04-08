# [Platinum III] Increasing Sequence Card Game - 23018 

[문제 링크](https://www.acmicpc.net/problem/23018) 

### 성능 요약

메모리: 74096 KB, 시간: 156 ms

### 분류

수학, 조합론, 미적분학

### 제출 일자

2026년 4월 8일 15:20:27

### 문제 설명

<p>You're playing a card game as a single player.</p>

<p>There are N cards. The i-th card has integer i written on it.</p>

<p>You first shuffle N cards randomly and put them in a pile. Take the card at the top of the pile to your hand. Then repeat the following process until the pile becomes empty:</p>

<ol>
	<li>Check the card on the top of the pile.</li>
	<li>If the number on the card is larger than the number on the last card you took, take the card.</li>
	<li>Otherwise, discard the card.</li>
</ol>

<p>The score of the game is the number of cards in your hand at the end. With the given number of cards N, what is the expected score of the game?</p>

### 입력 

 <p>The first line of the input contains the number of test cases, T. T lines follow. Each line contains a single integer N, the number of cards in the pile.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is the expected score at the end of the game.</p>

<p><code>y</code> will be considered correct if it is within an absolute or relative error of 10<sup>-6</sup> of the correct answer.</p>

