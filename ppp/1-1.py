#!/usr/bin/env python
import random
import time

print("启动")
t = time.time()

# 生成一个小于100万长度（因为生成的随机数可能重复，set中元素必须唯一，所以实际set会小于100万），元素取值范围[0, 1000万)的随机数set，然后对这个set进行排序
numbers = {random.randint(0, 1E7 - 1) for n in range(int(1E6))}	# 这句代码用时40秒

print("构造数据（%d个元素）... %.3f" % (len(numbers), (time.time() - t)))

t = time.time()

sorted_numbers_1 = sorted(numbers)
print(sorted_numbers_1[:10], '...', sorted_numbers_1[-10:])

print("系统排序... %.3f" % (time.time() - t))	# 0.7秒左右