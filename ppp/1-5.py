#!/usr/bin/env python
# 这道题和答案基本一致

import random
import time

print("启动")

class MyLimitRamSorter:
	'''最多使用1MB内存的排序算法，采用多趟读取数据的方式'''

	def __init__(self):
		# 向量最大1MB
		self.vector = self.build_vector()

	def build_vector(self):
		vector_size = 1024 ** 2
		return bytearray(vector_size)

	def put_numbers(self, numbers, base_number):
		'''将numbers中，值在[base_number, base_number + len(self.vector) * 8)范围内的数字记录，并返回是否有记录上的数字'''
		has_putted_numbers = False
		for n in numbers:
			if base_number <= n < base_number + len(self.vector) * 8:
				# 给定任意数，将其对应的向量位标记为1
				byte_index, bit_index = divmod(n - base_number, 8)	# byte_index：n在字节向量的第几个字节

				# n在这个字节中的第7 - bit_index位
				# 1 << 7 - bit_index构造一个在指定位为1的字节
				# |= 将向量此位置为1
				self.vector[byte_index] |= 1 << 7 - bit_index
				has_putted_numbers = True

		return has_putted_numbers

	def get_bit_position_with_1(self, byte):
		'''返回参数值二进制表示法中，值为1对应的数字，数字从左向右计数，如0111 0000表示1、2、3，1000 1000表示0和4'''

		mask = 0b100000000
		for number in range(8):
			mask = mask >> 1
			if byte & mask == mask:
				yield number

	def _sort(self, numbers, base_number):
		has_putted = self.put_numbers(numbers, base_number)
		if has_putted:
			for i in range(len(self.vector)):
				# i表示第几个字节，这个字节的最高位对应的数值为i * 8
				if self.vector[i] == 0:
					continue
				for pos in self.get_bit_position_with_1(self.vector[i]):
					yield base_number + i * 8 + pos

	def sort(self, numbers):
		base_number = 0
		
		while True:
			# 每次处理numbers中值在base_number + [0, len(self.vector) * 8)范围内的数据
			has_result = False
			for n in self._sort(numbers, base_number):
				has_result = True
				yield n
			
			if not has_result:
				break

			base_number += len(self.vector) * 8
			self.vector = self.build_vector()


# 取值范围：[0, max]
max = int(1E7)

# 随机填入test_number_count个数
test_number_count = int(1E6)
test_numbers = list({random.randint(0, max) for n in range(test_number_count)})

print('{0}个数排序{1}...{2}'.format(len(test_numbers), test_numbers[:10], test_numbers[-10:]))

t = time.time()
sorted_numbers = list(MyLimitRamSorter().sort(test_numbers))
print('算法排序：', '{:.3}s'.format(time.time() - t), sorted_numbers[:10], '...', sorted_numbers[-10:])