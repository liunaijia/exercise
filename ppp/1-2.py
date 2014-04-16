#!/usr/bin/env python
# 答案中的方法：
# N = 1E7	N 是最大值
# int a[1 + N / 32];	向量
# void set(int i) { a[i >> 5] |= (1 << (i & 0x1f)); }
# void clr(int i) { a[i >> 5] &= ~(1 << (i & 0x1f)); } 
# void test(int i) { return a[i >> 5] & (1 << (i & 0x1f)); } 
# i >> 5就是 i / 32，一个整数字节占32位，所以i / 32得出所在字节
# 0x1f = 31，i & 0x1f表示 i / 32的余数，向量元素中的低位表示0，高位表示31，1 << 余数，就可以将数字i对应的bit位置1


import random

# 取值范围：[0, max]
max = 50

# 计算需要的总字节数max // 8 + 1，//表示地板除
# bytearray为可变的字节数组，用来表示题目中的向量
vector = bytearray(max // 8 + 1)

def put(n):
	'''给定任意数，将其对应的向量位标记为1'''

	byte_index, bit_index = divmod(n, 8)	# byte_index：n在字节向量的第几个字节
	
	# n在这个字节中的第7 - bit_index位
	# 1 << 7 - bit_index构造一个在指定位为1的字节
	# |= 将向量此位置为1
	vector[byte_index] |= 1 << 7 - bit_index
	
	#按照答案中的做法，可以改写为
	# vector[n >> 3] |= 1 << (n & 7)

def vector_to_string():
	for n in vector:
		yield '{:08b}'.format(n)
		# :后面指定了输出格式：
		#	0表示不够的位置填0；
		#	8宽度；
		#	b二进制格式输出

# 随机填入test_number_count个数
test_number_count = 20
test_numbers = {random.randint(0, max) for n in range(test_number_count)}
for test_number in sorted(test_numbers):
	put(test_number)
	print('{0:>3} {1}'.format(test_number, ' '.join(vector_to_string())))