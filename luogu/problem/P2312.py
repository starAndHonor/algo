#!/usr/bin/python
# -*- coding: UTF-8 -*-
n,m = map(int,input().split())
xi = []
ans = []
for i in range(1,n+2):
	xi.append(int(input()))
xi.append(0)
cnt =0
for i in range(1,m+1):
	res = 0
	for j in reversed(xi):
		res=res*i+j
	if res==0:
		cnt+=1
		ans.append(i)
print(cnt)
for i in ans:
	print(i)
