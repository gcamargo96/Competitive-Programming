lv = 1
curr = 2
nxt = 2

to = input()

while lv <= to:
    print nxt*nxt - curr
    curr = nxt + 1
    nxt = nxt + 1
    lv = lv + 1
