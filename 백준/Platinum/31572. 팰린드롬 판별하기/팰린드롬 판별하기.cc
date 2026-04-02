#include <vector>

extern int count_pair(int x, int y, int z);
extern int find_character(int x, std::vector<int> Y);

int guess_palindromicity(int N) {
    std::vector<int> refs;

    // 첫 번째 원소와 마지막 원소 비교
    if (find_character(0, {N - 1}) == 0) {
        return 0;
    }
    refs.push_back(0);

    for (int i = 1; i < N / 2; ++i) {
        int valid = -1;
        
        for (int r : refs) {
            int c = count_pair(r, i, N - 1 - i);
            
            if (c == 0) {
                return 0; // 팰린드롬 조건 위배
            } 
            if (c == 3) {
                valid = 1; // 팰린드롬 조건 만족 확인 완료
                break;
            }
            // c == 1인 경우 다음 기준값(r)으로 계속 검증
        }

        // 모든 refs에 대해 count_pair 결과가 1인 경우
        if (valid == -1) {
            if (refs.size() < 3) {
                // 기준값이 3개 미만이면 find_character를 통해 직접 확인
                if (find_character(i, {N - 1 - i}) == 0) {
                    return 0;
                }
                // 새로운 독립적인 값의 쌍을 발견했으므로 기준점에 추가
                refs.push_back(i);
            }
            // refs.size() == 3 이라면 비둘기집 원리에 의해 무조건 팰린드롬 쌍임이 보장됨
        }
    }

    return 1;
}