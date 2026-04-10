# [Platinum III] Java2016 - 13482 

[문제 링크](https://www.acmicpc.net/problem/13482) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 애드 혹, 해 구성하기, 비트마스킹, 확률론

### 제출 일자

2026년 4월 10일 11:36:32

### 문제 설명

<p>John likes to learn esoteric programming languages. Recently he discovered the probabilistic programming language Java2K. Built-in functions of Java2K have only a certain probability to do whatever you intend them to do.</p>

<p>The Java2K programming is very hard, so John designed a much simpler language for training: Java2016. Built-in operators of Java2016 are deterministic, while their operands are random. Each value in Java2016 is a positive integer in the range 0..255, inclusive.</p>

<p>Java2016 supports six operators of three precedencies:</p>

<p style="text-align: center;">⟨expression⟩ ::= ⟨expression⟩‘<code>min</code>’⟨sum⟩ | ⟨expression⟩‘<code>max</code>’⟨sum⟩ | ⟨sum⟩<br>
⟨sum⟩ ::= ⟨sum⟩‘<code>+</code>’⟨term⟩ | ⟨sum⟩‘<code>-</code>’⟨term⟩ | ⟨term⟩<br>
⟨term⟩ ::= ⟨term⟩‘<code>*</code>’⟨factor⟩ | ⟨term⟩‘<code>/</code>’⟨factor⟩ | ⟨factor⟩<br>
⟨factor⟩ ::= ‘<code>(</code>’⟨expression⟩‘<code>)</code>’ | ‘<code>?</code>’ | ⟨macro⟩</p>

<p>Minimum (‘<code>min</code>’) and maximum (‘<code>max</code>’) operators are defined as usual. Addition (‘<code>+</code>’), subtraction (‘<code>-</code>’) and multiplication (‘<code>*</code>’) are defined modulo 256. The result of the division (‘<code>/</code>’) is rounded towards zero. If the divider is zero, the program crashes. The argument of the operator is a result of another operator, evenly distributed random value (‘<code>?</code>’), or macro substitution.</p>

<p>For instance, the probability that “<code>?/?/?</code>” is evaluated to zero is 98.2%, while the probability of the crash is 0.8%.</p>

<p>The Java2016 program consists of zero or more macro definitions, followed by the resulting expression. Each macro definition has a form of</p>

<p style="text-align: center;">⟨macrodef⟩ ::= ⟨macro⟩‘=’⟨expression⟩<br>
⟨macro⟩ ::= ‘<code>a</code>’ . . . ‘<code>z</code>’</p>

<p>The macro should be defined before the first use. It may not be redefined. The macro is expanded to its definition on each use. For instance,<br>
<code>a = ? max ?<br>
(a max a) / a</code><br>
is expanded to “<code>((? max ?) max (? max ?)) / (? max ?)</code>”.</p>

<p>John is going to add probabilistic constants to Java2016, so for each possible constant value he needs a program that successfully evaluates to this value with at least one-half probability. Crashes are counted toward failures.</p>

### 입력 

 <p>The input contains a single integer c — the target constant (0 ≤ c ≤ 255).</p>

### 출력 

 <p>Output a Java2016 program that successfully evaluates to constant c with probability no less than 1/2. The total length of the program should not exceed 256 characters (excluding spaces).</p>

