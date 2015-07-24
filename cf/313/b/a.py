x1,y1=(int(x) for x in input().split())
x2,y2=(int(x) for x in input().split())
x3,y3=(int(x) for x in input().split())
if(((x2+x3<=x1)|(y2+y3<=y1))|((x2+y3<=x1)|(y2+x3<=y1))|((y2+y3<=x1)|(x2+x3<=y1))|((y2+x3<=x1)|(x2+y3<=y1))):
    print("YES")
else:
    print("NO")
