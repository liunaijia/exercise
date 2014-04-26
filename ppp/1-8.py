#!/usr/bin/env python
# 此题没有答案
import random
import itertools
import time
import glob
import os
import struct

class MyLimitRamSorter:
	'''最多使用vector_sizebytes内存的排序算法，采用多趟读取数据的方式'''

	def __init__(self, vector_size):
		self.vector = bytearray(vector_size)

	def put_number(self, n):
		# 给定任意数，将其对应的向量位标记为1
		byte_index, bit_index = divmod(n, 8)	# byte_index：n在字节向量的第几个字节

		# n在这个字节中的第7 - bit_index位
		# 1 << 7 - bit_index构造一个在指定位为1的字节
		# |= 将向量此位置为1
		self.vector[byte_index] |= 1 << 7 - bit_index


	def get_bit_position_with_1(self, byte):
		'''返回参数值二进制表示法中，值为1对应的数字，数字从左向右计数，如0111 0000表示1、2、3，1000 1000表示0和4'''

		mask = 0b100000000
		for number in range(8):
			mask = mask >> 1
			if byte & mask == mask:
				yield number

	def sort(self):
		for i in range(len(self.vector)):
			# i表示第几个字节，这个字节的最高位对应的数值为i * 8
			if self.vector[i] == 0:
				continue
			for pos in self.get_bit_position_with_1(self.vector[i]):
				yield i * 8 + pos

def create_test_numbers(count):
	'''800、877、888开头，后面是7位数字的电话号码，构造一些测试号码'''
	return list({random.choice((800, 877, 888)) * int(1E7) + random.randint(0, 1E7 - 1) for _ in range(count)})	

def sort_and_save_numbers(test_numbers):
	# 删除sorted_numbers_{0}.txt
	for f in glob.glob("sorted_numbers_*"):
	    os.remove(f)

	# 三组免费号码，公用1MB存储空间，每组免费号码最大存储空间 1MB / 3
	vector_size = 1024 ** 2 // 3

	# 可容纳的数字1MB / 3 * 8个
	vector_number_count = vector_size * 8
	# 第一遍：只处理三个号码段中[0, vector_size * 8)的号码，这样一共需要遍历1E7 // vector_number_count + 1次，才能将所有可能的号码处理完毕
	for base_number in range(0, int(1E7), vector_number_count):

		sorters = {888: MyLimitRamSorter(vector_size),
			877: MyLimitRamSorter(vector_size),
			800: MyLimitRamSorter(vector_size)}

		for test_number in test_numbers:
			seg = test_number // int(1E7)	# seg表示号段：888、800、887
			number_part = test_number % int(1E7)		# n表示后7位号码
			if base_number <= number_part < base_number + vector_number_count:
				sorters[seg].put_number(number_part - base_number)

		# 排序[0, vector_size * 8)的号码
		for (k, v) in sorters.items():
			with open('sorted_numbers_{0}'.format(k), 'ab') as file:
				for sorted_number in v.sort():
					#print(k, sorted_number + base_number)
					file.write(struct.pack('i', sorted_number + base_number))
					# file.write(str(sorted_number + base_number) + '\n')

def find_number(lookup_number):
	seg = lookup_number // int(1E7)	# seg表示号段：888、800、887
	number_part = lookup_number % int(1E7)		# n表示后7位号码
	
	filename = 'sorted_numbers_{0}'.format(seg)
	
	# 从文件中一半的位置开始查找
	start_offset = 0
	end_offset = os.path.getsize(filename) // 4 - 1	# int值占用4字节
	with open(filename, 'rb') as file:
		while True:
			direction = seek_number(file, number_part, start_offset, end_offset)
			if direction == 0:
				print(lookup_number, '已用')
				break
			elif start_offset == end_offset:
				print(lookup_number, '可用')
				break
			elif direction > 0:
				start_offset = (start_offset + end_offset) // 2 + 1
			else:
				end_offset = (start_offset + end_offset) // 2 - 1
		

def seek_number(file, target_number, start_offset, end_offset):
	'''target_number更大，返回正数，相等返回0，否则返回负数'''
	offset = (end_offset + start_offset) // 2
	file.seek(offset * 4)
	number = struct.unpack('i', file.read(4))[0]
	number2 = struct.unpack('i', file.read(4))[0]

	#print(start_offset, end_offset, target_number, number, number2)

	return target_number - number


test_numbers = create_test_numbers(int(1E6))
print('{0}个数排序{1}...{2}'.format(len(test_numbers), test_numbers[:10], test_numbers[-10:]))

# 将这些号码排序，并写到文件中
t = time.time()
sort_and_save_numbers(test_numbers)
print('排序完毕{:.3}s'.format(time.time() - t))

# 查找几个随机数
for lookup_number in create_test_numbers(10):
 	find_number(lookup_number)
# 和几个肯定存在的数
find_number(test_numbers[0])
find_number(test_numbers[1])
find_number(test_numbers[2])
find_number(test_numbers[3])
find_number(test_numbers[4])
find_number(test_numbers[5])
find_number(test_numbers[6])