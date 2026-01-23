#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Student{
    string name;
    int kor, eng, math;
};

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<Student> students(n);
    for(int i = 0; i < n; i++) cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
    sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        if(a.kor != b.kor) return a.kor > b.kor;
        if(a.eng != b.eng) return a.eng < b.eng;
        if(a.math != b.math) return a.math > b.math;
        return a.name < b.name;
    });
    for(const auto& s: students) cout << s.name << '\n';
	return 0;
}