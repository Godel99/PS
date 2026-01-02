def solution(n, t, m, timetable):
    crew = []
    for time in timetable:
        hour, min = map(int, time.split(':'))
        crew.append(hour*60+min)
    crew.sort()
    crew_idx = 0
    last_ridden = 0
    last_time = 0
    
    for i in range(n):
        last_bus_time= 9 * 60 + (t * i)
        ridden = 0

        while crew_idx < len(crew) and crew[crew_idx] <= last_bus_time and ridden < m:
            last_time = crew[crew_idx]
            crew_idx += 1
            ridden += 1
        
    if ridden < m:
        result_time = last_bus_time 
    else:
        result_time = max(0, last_time - 1)

    H, M = divmod(result_time, 60)
    return f'{H:02d}:{M:02d}'