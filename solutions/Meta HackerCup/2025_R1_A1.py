for i in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = 0
    for j in range(1,n):
        ans = max(ans,abs(a[j]-a[j-1]))
    print(f"Case #{i+1}: {ans}")
