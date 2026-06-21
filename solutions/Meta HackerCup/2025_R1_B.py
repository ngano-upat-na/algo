for i in range(int(input())):
    n, a, b = map(int,input().split())
    ans = [1 for j in range(2*n-1)] + [b]
    print(f"Case #{i+1}:",*ans)
