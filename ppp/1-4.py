#!/usr/bin/env python
# 这道题目理解错了，问题是如何保证生成的随机数不重复，而不是如何生成随机数。
# 保证不重复有两种办法：1）把生成过的数记录下来；2）预先生成一些不重复的数字，然后从中选择，
# 我的办法是1，答案中的方法是2，只是非常巧妙：
import random

n = int(1E7)
x = list(range(n))	# 预先生成[0, 1E7)的序列，要生成的随机数将从中选取
for i in range(100):	# 假设生成100个随机数
	available_index = random.randint(i, n - 1)	# 可用的序列索引，可用的表示没有使用过的索引值，是当前索引值和序列最大索引值之间的任意一个索引
	x[available_index], x[i] = x[i], x[available_index]	# 交换当前元素和一个可用元素，交换后，保证当前元素随机，且当前索引后的元素都是可用的
	print(x[i])

# 下面是我的算法

import time

class MyRandom:
	def __init__(self, max):
		# 随机数的种子，用它来生成随机数
		self.seed = time.time() % 1
		
		# 使用一个位向量记录哪些随机数已经生成过了
		bits_map_len = max // 8
		if max % 8 != 0:
			bits_map_len += 1
		self.bits_map = bytearray(bits_map_len)
		
		# 随机数的最大值，这个值不会取道
		self.max = max

		# 还可以生成的随机数
		self.available_numbers = max

	
	def _rand_int(self):
		'''生成一个[0, max)的随机整数'''

		# 每次都在上个种子的基础上进行一些变换，防止生成一样的随机数
		self.seed = self.seed * 13 % 1
		return int(self.seed * self.max)

	
	def is_exists(self, n):
		'''随机数n是否已经生成过？'''

		(index_bits_map, index_byte) = divmod(n, 8)
		bit_mask = 1 << 7 - index_byte
		return self.bits_map[index_bits_map] & bit_mask == bit_mask

	def is_full(self):
		'''没有可用的随机数？'''

		return self.available_numbers == 0

	def mark(self, n):
		'''记录已经生成的随机数n'''
		(index_bits_map, index_byte) = divmod(n, 8)
		self.bits_map[index_bits_map] |= 1 << 7 - index_byte
		self.available_numbers -= 1

	def rand_int(self):
		'''生成一个随机数，保证这个随机数不重复'''
		if self.is_full():
			raise Exception('没有可用的数值了')

		n = self._rand_int()
		if (self.is_exists(n)):
			return self.rand_int()

		self.mark(n)
		return n


mr = MyRandom(20)
a_list = list(mr.rand_int() for n in range(10))
print(sorted(a_list))

