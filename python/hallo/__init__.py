n = int(input())
a = []
su = 0
max1,max2 = [None,None]
for i in range(n):
    x,y = [ int(t) for t in input().split()]
    a.append([x,y])
    su += x
    if max1==None or y>a[max1][1]:
        max1,max2 = [i,max1]
    elif max2==None or y>a[max2][1]:
        max2 = i
print(' '.join([str((su-a[i][0])*a[max2 if i==max1 else max1][1]) for i in range(n)])) 