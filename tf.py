
def solve():
    n = int(input())
    line = list(map(int, input().split()))
    if n == 1: 
        return 2 if line[0] == 0 else 0
    count = 0
    for _ in range(2):
        ans = [-1] * n
    
        ans[0] = _
        if line[0] == 0: ans[1] = 0
        if line[0] == 1: ans[1] = 1
        
        if line[-1] == 0: ans[-2] = 0
        if line[-1] == 1: ans[-2] = 0

        ok = True
        for i in range(n):
            if line[i] == 2:
                if i == 0 or i == n-1:
                    ok = False
                if ans[i+1] == -1 or ans[i+1] == 1:
                    ans[i+1] = 1
                else:
                    ok = False
                if ans[i-1] == -1 or ans[i-1] == 1:
                    ans[i-1] = 1
                else:
                    ok = False
            
            if line[i] == 0:
                if i != n-1:
                    if ans[i+1] == -1 or ans[i+1] == 0:
                        ans[i+1] = 0
                    else:
                        ok = False
                if i != 0:
                    if ans[i-1] == -1 or ans[i-1] == 0:
                        ans[i-1] = 0
                    else:
                        ok = False
    
        
        for i in range(1, n-1):
          
          if line[i] == 1:
            if ans[i+1] != -1:
              if ans[i-1] == ans[i+1]:
                ok = False
              ans[i-1] = 0 if ans[i+1] else 1
    
            if ans[i-1] != -1:
              if ans[i-1] == ans[i+1]:
                ok = False
              ans[i+1] = 0 if ans[i-1] else 1
        
        for i in range(n-2, 0, -1):
          
          if line[i] == 1:
              
            if ans[i+1] != -1:
              if ans[i-1] == ans[i+1]:
                ok = False
              ans[i-1] = 0 if ans[i+1] == 1 else 1
    
            if ans[i-1] != -1:
              if ans[i-1] == ans[i+1]:
                ok = False
              ans[i+1] = 0 if ans[i-1] == 1 else 1
        #print(ans)
        if ok: count += 1
        
    
    return count
    
    
                
        
      

print(solve())

