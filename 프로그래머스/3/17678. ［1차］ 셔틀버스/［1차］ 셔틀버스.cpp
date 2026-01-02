#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crew;
    for (const string& time : timetable){
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        crew.push_back(hour * 60 + min);
    }

    sort(crew.begin(),crew.end());
    int crew_idx = 0;
    int last_crew_time = 0;
    int ridden;
    int last_bus_time;

    for (int i = 0; i < n; i++){
        last_bus_time = 9 * 60 + t * i;
        ridden = 0;

        while (crew_idx < crew.size() && crew[crew_idx] <= last_bus_time && ridden < m){
            last_crew_time = crew[crew_idx];
            crew_idx++;
            ridden++;
        }
    }

    int answer = 0;
    if (ridden < m) answer = last_bus_time;
    else answer = last_crew_time - 1;
    
    int H = answer / 60;
    int M = answer % 60;

    ostringstream oss;
    oss << setw(2) << setfill('0') << H
        << ":" 
        << setw(2) << setfill('0') << M;

    return oss.str(); 
}