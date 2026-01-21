# [Platinum IV] 잘못 작성한 요세푸스 코드 - 1215 

[문제 링크](https://www.acmicpc.net/problem/1215) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2026년 1월 21일 14:40:58

### 문제 설명

<p>요세푸스 문제는 아래와 같이 풀 수 있다.</p>

<div><div id="highlighter_539695" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c plain">r := 0;</code></div><div class="line number2 index1 alt1"><code class="c keyword bold">for</code> <code class="c plain">i from 1 to n </code><code class="c keyword bold">do</code></div><div class="line number3 index2 alt2"><code class="c spaces">    </code><code class="c plain">r := (r + k) mod i;</code></div><div class="line number4 index3 alt1"><code class="c keyword bold">return</code> <code class="c plain">r;</code></div></div></td></tr></tbody></table></div></div>

<p>하지만 상근이는 코드를 잘못 읽고 아래와 같이 작성했다.</p>

<div><div id="highlighter_446668" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c plain">r := 0;</code></div><div class="line number2 index1 alt1"><code class="c keyword bold">for</code> <code class="c plain">i from 1 to n </code><code class="c keyword bold">do</code></div><div class="line number3 index2 alt2"><code class="c spaces">    </code><code class="c plain">r := r + (k mod i);</code></div><div class="line number4 index3 alt1"><code class="c keyword bold">return</code> <code class="c plain">r;</code></div></div></td></tr></tbody></table></div></div>

<p>n과 k가 주어졌을 때, 상근이의 잘못 작성한 소스를 실행시킨 결과를 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫 줄에 n과 k가 주어진다. (1 ≤ n, k ≤ 10<sup>9</sup>)<br>
 </p>

### 출력 

 <p>첫째 줄에 주어진 n과 k로 상근이의 잘못 작성한 소스의 결과를 출력한다.</p>

# 풀이
### 정수 문제
이 문제는 이름만 요세푸스 문제일 뿐 실은 수학 **정수 문제**입니다. 

$$\sum_{i=1}^{n}({k}\mod{i})$$

핵심은 결국 위 수식을 처리하는 문제로 귀결됩니다. 그러나 위 수식을 그대로 코드로 옮겨서 실행하면 $k$값이 커서 시간초과가 발생합니다.

### 위 수식 연산을 줄일 수 없을까?
**$i>k$ 경우**: 나머지 연산의 특성을 생각해보면 $i>k$이면 ${k}\mod{i}=k$이므로 $k\times(n-k)$를 하면 됩니다.

**$i<k$ 경우**: $i<k$일 때는 또 두 가지 경우로 나눠서 생각해 볼 수 있습니다.

### 중복 연산 제거
${k}\mod{i}=k$ 에서 $i$가 일정하게 크다면 동일한 결과가 나온다는 것을 알 수 있습니다. 예를 들어 $k=100$라 하고 $i$를 20부터 30까지 증가시키면 몫이 4라는 값이 여러번 나온다는 것을 알 수 있습니다. 덕분에 특정 구간을 **묶어서** 계산할 수 있게 됩니다.

반대로 $i$이 작다면, 클 때보다 상대적으로 자주 나눠져서 몫이 매번 바뀌게 됩니다.

여기서 한 가지 규칙을 찾아낼 수 있습니다.

### $\sqrt{k}$ 경계

${k}\mod{i}$ 를 고쳐 쓰면 $\lfloor \frac{k}{i} \rfloor$라 할 수 있고, $q\leq\frac{k}{i}<q+1$ 범위를 가진다고 볼 수 있습니다.

$$\frac{k}{q+1}\leq i <\frac{k}{q}$$

아래와 같이 고쳐쓸 수 있고,

$$\frac{k}{q}-\frac{k}{q+1}=\frac{k}{q(q+1)}$$

$$\frac{k}{q(q+1)}\approx\frac{k}{q^2}$$

여기서 $q>\sqrt{k}$ 이면 같은 몫을 가지는 $i$가 1개이하가 됩니다.

반대로, $q<\sqrt{k}$ 이면 동일한 몫을 가지는 구간이 늘어나 묶어서 계산할 수 있게 됩니다.

그러므로 총 3 구간으로 나누고 중복 연산 구간을 제거한다면, $\mathcal{O}(\sqrt{k})$ 내에 계산이 가능하게 됩니다.

### 3구간
$q>\sqrt{k}$ 경우 몫이 여러개가 나오므로 그대로 ${k}\mod{i}$ 연산을 해줍니다.

$q<\sqrt{k}$ 경우 동일한 몫이 여러 개 나오므로 그 구간을 한 번에 계산해 줍시다.

### 동일 몫 구간 구하기
$$\frac{k}{q+1}\leq i <\frac{k}{q}$$

에서

$$l=\frac{k}{q+1},\ r=\frac{k}{q}$$

라 하면 구간은 $r-l+1$이 됩니다.

${k}\mod{i}$ 는 다시 ${k}\mod{i}=k-i\lfloor \frac{k}{i} \rfloor$($k=iq+r$, $q=\lfloor \frac{k}{i} \rfloor$ 이므로)로 고쳐쓸 수 있고 이는 나머지 연산을 몫 연산으로 바꿔줍니다. 동일한 몫에 대해서 연산을 건너띄는 게 목적이므로 이러한 변형을 하는 것입니다.

$$\sum_{i=1}^{n}({k}\mod{i}) = \sum_{i=1}^{n}(k-i\lfloor \frac{k}{i} \rfloor)$$

첫번째 항:

$$\sum_{i=l}^{r}k=k(r-l+1)$$

두번째 항:

$$\sum_{i=l}^{r}\lfloor \frac{k}{i} \rfloor=q\cdot\frac{(l+r)(r-l+1)}{2}$$

최종적으로 아래 식이 나오게 됩니다.

$$k(r-l+1)-q\cdot\frac{(l+r)(r-l+1)}{2}$$

위 식을 그대로 계산해주면 동일 몫에 대해서 한번에 계산할 수 있습니다.

**마지막 구간은 $i>k$이므로 $k\times(n-k)$를 계산해주면 끝납니다.**

## 구현
<details>
<summary>코드</summary>


### Python
```python
import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

from math import sqrt

def main():
    n, k = map(int, input().split())
    sq = int(sqrt(k)); ans = 0
    for i in range(1, min(k//sq, n)+1): ans += k%i
    for i in range(1, sq):
        l = k//(i+1)+1; r = min(k//i, n)
        if l > r: continue
        ans += k*(r-l+1)-(l+r)*(r-l+1)*i//2
    ans += k*max(0, n-k)
    print(ans)
    return 0
if __name__ == '__main__':
    sys.exit(main())
```
### C++
```c++
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	ll n, k; cin >> n >> k; ll sq = sqrt(k); ll ans = 0;
	for(ll i = 1; i <= min(k/sq, n); i++) ans += k%i;
	for(ll i = 1; i < sq; i++){
		ll l = k/(i+1)+1, r = min(k/i, n);
		if(l > r) continue;
		ans += k*(r-l+1)-(l+r)*(r-l+1)*i/2;
	}
	ans += k*max(0LL, n-k);
	cout << ans;
}
```
</details>

## 시간 및 공간 복잡도
* 시간복잡도: $\mathcal{O}(\sqrt{k})$
* 공간복잡도: $\mathcal{O}(1)$

