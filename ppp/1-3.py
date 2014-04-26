#!/usr/bin/env python
import random
import time

print("启动")


# 取值范围：[0, max]
max = int(1E7)

class MyCollection:
	def __init__(self, max):
		self.vector = bytearray(max // 8 + 1)

	def put(self, n):
		'''给定任意数，将其对应的向量位标记为1'''
		byte_index, bit_index = divmod(n, 8)	# byte_index：n在字节向量的第几个字节
		# n在这个字节中的第7 - bit_index位
		# 1 << 7 - bit_index构造一个在指定位为1的字节
		# |= 将向量此位置为1
		self.vector[byte_index] |= 1 << 7 - bit_index

	def get_number_with_1_bits(self, byte):
		'''返回参数值二进制表示法中，值为1对应的数字，数字从左向右计数，如0111 0000表示1、2、3，1000 1000表示0和4'''
		test_bit = 0b100000000
		for number in range(8):
			test_bit = test_bit >> 1
			if byte & test_bit == test_bit:
				yield number

	def sort(self, numbers):
		for n in numbers:
			self.put(n)

		for i in range(len(self.vector)):
			# i表示第几个字节，这个字节的最高位对应的数值为i * 8
			if (self.vector[i] == 0):
				continue
			for bit in self.get_number_with_1_bits(self.vector[i]):
				yield i * 8 + bit

class AnswerCollection:
	def __init__(self, max):
		self.vector = bytearray(max // 8 + 1)

	def put(self, n):
		self.vector[n >> 3] |= 1 << (n & 7)

	def sort(self, numbers):
		for n in numbers:
			self.put(n)

		for i in range(max):
			if self.vector[i >> 3] & (1 << (i & 7)) != 0:
				yield i
		


# 随机填入test_number_count个数
test_number_count = int(1E6)
test_numbers = list({random.randint(0, max) for n in range(test_number_count)})
print('{0}个数排序{1}...{2}'.format(len(test_numbers), test_numbers[:10], test_numbers[-10:]))

t = time.time()
sorted_numbers = list(MyCollection(max).sort(test_numbers))	# 2.88s
print('我的算法排序：', '{:.3}s'.format(time.time() - t), sorted_numbers[:10], '...', sorted_numbers[-10:])

t = time.time()
sorted_numbers_3 = list(AnswerCollection(max).sort(test_numbers))	# 2.88s
print('答案算法排序：', '{:.3}s'.format(time.time() - t), sorted_numbers_3[:10], '...', sorted_numbers_3[-10:])

t = time.time()
sorted_numbers_2 = sorted(test_numbers)	# 0.509s
print('系统排序：', '{:.3}s'.format(time.time() - t), sorted_numbers_2[:10], '...', sorted_numbers_2[-10:])