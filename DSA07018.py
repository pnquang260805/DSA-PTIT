# DSA07018 - TỔNG ĐA THỨC

from collections import defaultdict


def solve():
    a = input().strip().split(" + ")
    b = input().strip().split(" + ")
    d = defaultdict(int)
    for s in a:
        idx = s.find("*")
        idx2 = s.find("^")
        key = int(s[idx2 + 1 :])
        value = int(s[:idx])
        d[key] += value

    for s in b:
        idx = s.find("*")
        idx2 = s.find("^")
        key = int(s[idx2 + 1 :])
        value = int(s[:idx])
        d[key] += value
    d = sorted(d.items(), key=lambda x: x[0], reverse=True)
    ans = ""
    for x in d:
        ans += str(x[1]) + "*x^" + str(x[0]) + " + "
    print(ans[:-3])


if __name__ == "__main__":
    t = int(input().strip())
    while t > 0:
        solve()
        t -= 1
