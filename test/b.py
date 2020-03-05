from math import gcd
x1 , y1 , x2 , y2 = map(int,input().split())
if gcd(x1 , y1) == gcd(x2 , y2):
    print("YES")
else:
    print("NO")