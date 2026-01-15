# [Platinum I] 마지막 요세푸스 문제 - 1179 

[문제 링크](https://www.acmicpc.net/problem/1179) 

### 성능 요약

메모리: 32412 KB, 시간: 32 ms

### 분류

수학, 다이나믹 프로그래밍, 재귀

### 제출 일자

2026년 1월 14일 22:05:31

### 문제 설명

<p>요세푸스 문제는 다음과 같다.</p>

<p>1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.</p>

<p>N과 K가 주어지면, 마지막으로 남는 사람의 번호를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ N ≤ 10<sup>15</sup>, 1 ≤ K ≤ 90)</p>

### 출력 

 <p>첫째 줄에 마지막으로 남는 사람의 번호를 출력한다.</p>

# 풀이
간단하게 큐를 이용해 요세푸스 문제를 해결할 수 있지만, 이 문제의 경우 입력값의 범위가 매우 크기 때문에 큐로 접근했다간 시간초과(TLE)가 납니다.(1 ≤ N ≤ 10<sup>15</sup>, 1 ≤ K ≤ 90, $\mathcal{O}(n)$ 경우 TLE)

수학적으로 $n$의 크기를 줄일 수 있습니다. 그 과정은 재귀를 이용해서 풀어봅시다.
### 수학적 접근
요세푸스 문제를 수학적 접근을 해본다면, 한 바퀴를 돌았을 경우 그 다음은 좀 더 작은 요세푸스 문제가 된다는 점을 알 수 있습니다. 이를 점화식으로 표현하면 아래와 같습니다.

$$f(n,k)=(f(n−1,k)+k)\ mod \ n$$
### $n$ 줄이기
$n<k$ 경우 위 점화식을 이용해 간단히 해결하면 됩니다.


문제는 $n>k$이 클 경우 이를 어떻게 줄일 수 있느냐입니다. 다행히도 한 바퀴를 돌 경우 $n/k$명이 죽는다는 사실을 착안하여 $n-n/k$로 $n$을 줄여갈 수 있습니다.( $\mathcal{O}(k log n)$ )

그런데 우리가 구하고자 하는 것은 **마지막으로 살아남는 사람의 번호**입니다. 

중요한 것은 **매번 $n/k$이 죽을 때마다 시작 위치와 사람들의 번호가 바뀐다는 사실**입니다. $n/k$이 죽을 때마다 원위치 복원작업을 해줘야 합니다.
### 시작점 복원
원위치를 복원하기 앞서 회전 복원, 즉 시작점부터 찾아줍시다. 왜 시작점부터 찾아주냐면 시작점을 알아야 다시 원래 번호를 찾아줄 수 있기 때문입니다.

시작점은 **마지막 죽은 사람의 위치 다음이 시작점**이 됩니다. 그렇다면 $k$명의 사람이 죽고 그 뒤에 $n\mod\ k$명이 남게 됩니다. 따라서 그 부분을 빼줘서 시작점을 원위치 시킵니다. 
### 원위치 복원
시작점 찾기 위해 회전 복원을 시켰다면, 다음은 원래 번호를 찾아줘야 합니다. $x$를 살아남은 사람의 위치라고 한다면 $x+x/(k-1)$만큼 이동을 시켜줍니다.


$x$의 원 위치는 생존자 $x$명 + $(k-1)$의 제거자 수이기 때문에 $x+x/(k-1)$이 성립합니다.
## 시간 및 공간 복잡도
* 시간복잡도: $\mathcal{O}(k log n)$
* 공간복잡도: $\mathcal{O}(k log n)$
## 코드
### Python
```python
import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**7)

def josephus(n, k):
    if n == 1: return 0
    if n < k: return (josephus(n-1, k)+k)%n
    l = josephus(n-n//k, k) - n%k
    if l < 0: return l+n
    return l+l//(k-1)

def main():
    n, k = map(int, input().split())
    print(n) if k == 1 else print(josephus(n,k)+1)
if __name__ == '__main__':
    main()
```
```python
import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**7)

def josephus(n, k):
    if n == 1: return 0
    if n < k: return dp[n]
    l = josephus(n-n//k, k) - n%k
    if l < 0: return l+n
    return l+l//(k-1)

def main():
    n, k = map(int, input().split())
    global dp
    dp = [0] * k
    for i in range(1, k): dp[i] = (dp[i-1]+k)%i
    print(n) if k == 1 else print(josephus(n,k)+1)
if __name__ == '__main__':
    main()
```
### C++
```c++
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll josephus(ll n, ll k){
    if(n == 1) return 0;
    if(n < k) return (josephus(n-1, k)+k)%n;
    ll l = josephus(n-n/k, k) - n%k;
    if(l < 0) return l+n;
    return l+l/(k-1);
}

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k; if(k == 1) cout << n; else cout << josephus(n, k)+1;
}
```
