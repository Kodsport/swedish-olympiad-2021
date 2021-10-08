#!env /bin/python3
k, n = map(int , input().split())
people_per_day = list(map(int , input().split()))
day = []
for current_day, people_today in enumerate(people_per_day):
    for _ in range(people_today):
        day.append(current_day)
for friend in list(map(int , input().split())):
    if friend < len(day):
        print(day[friend]+1)
    else:
        print(-1)