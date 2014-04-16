#!/usr/bin/env python
# 这道题和答案基本一致

import random
import time
# 想法：10dec = 1010bin，可以用4bits来记录出现的次数，1byte只能表示2个数字，
# 所以不重复的N个数，需要用N/2个bytes来存储，并且每个数字最多允许出现15次（0b1111）

class RepeatableCollection:
	def __init__(self, max_number):
		vector_size = max_number // 2 + 1
		self.vector = bytearray(int(vector_size))

	def put_numbers(self, numbers):
		for n in numbers:
			# byte_index：n在字节向量的第几个字节
			# high_or_low_bits：0高4位、1低4位
			byte_index, high_or_low_bits = divmod(n, 2)

			byte_value = self.vector[byte_index]
			if high_or_low_bits == 0:
				show_times = ((byte_value & 0b11110000) >> 4) + 1
				self.vector[byte_index] = (show_times << 4) | (byte_value & 0b00001111)
			else:
				show_times = (byte_value & 0b00001111) + 1
				self.vector[byte_index] = byte_value & 0b11110000 | show_times


	def sort(self, numbers):
		self.put_numbers(numbers)
		
		for i in range(len(self.vector)):
			byte_value = self.vector[i]

			high_bits_number_show_times = (byte_value & 0b11110000) >> 4
			for n in range(high_bits_number_show_times):
				yield i * 2

			low_bits_number_show_times = byte_value & 0b00001111
			for n in range(low_bits_number_show_times):
				yield i * 2 + 1


max_number = 1E7	# 约用内存4.7MB max_number / 2 / 1024 / 1024

def gen_test_numbers():
	# 生成10万个[0, 1E7)之间的随机数
	unique_number_count = 100000
	unique_numbers = {random.randint(0, max_number - 1) for n in range(unique_number_count)}

	# 每个随机数最多出现10次，或者一次都不出现
	for unique_number in unique_numbers:
		for n in range(random.randint(0, 10)):
			yield unique_number

def show_result(t, sorted_numbers):
	if len(sorted_numbers) < 100:
		print('{:.3}s'.format(time.time() - t), sorted_numbers)
	else:
		print('{:.3}s'.format(time.time() - t), sorted_numbers[:10], '...', sorted_numbers[-10:])	


test_numbers = list(gen_test_numbers())
if len(test_numbers) < 100:
	print('{0}个数排序{1}'.format(len(test_numbers), test_numbers))
else:
	print('{0}个数排序{1}...{2}'.format(len(test_numbers), test_numbers[:10], test_numbers[-10:]))


print('算法排序...')
show_result(time.time(), list(RepeatableCollection(max_number).sort(test_numbers)))

print('系统排序...')
show_result(time.time(), list(sorted(test_numbers)))