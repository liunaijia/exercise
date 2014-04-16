#!/usr/bin/env python
# 此题没有答案
import unittest

class NumberCollection:
	def __init__(self, max_number, numbers):
		if (len(numbers) == 0):
			return

		self.max_number = max_number
		vector_size = max_number // 8 + 1
		self.vector = bytearray(vector_size)

		self.put_numbers(numbers)

	def put_numbers(self, numbers):
		for n in numbers:
			if type(n) != int:
				raise ValueError('%s不是整数' % n)
			if n < 0:
				raise ValueError('%d不能小于0' % n)
			if n > self.max_number:
				raise ValueError('{0}超过允许的最大值{1}'.format(n, self.max_number))

			byte_index, bit_index = divmod(n, 8)
			mask = 1 << 7 - bit_index
			byte = self.vector[byte_index]
			
			if byte & mask == mask:
				raise ValueError('%d已经存在' % n)
			
			self.vector[byte_index] |= mask

	def get_bit_position_with_1(self, byte):
		mask = 0b100000000
		for number in range(8):
			mask = mask >> 1
			if byte & mask == mask:
				yield number

	def sort(self):
		if hasattr(self, 'vector'):
			for i in range(len(self.vector)):
				# i表示第几个字节，这个字节的最高位对应的数值为i * 8
				if (self.vector[i] == 0):
					continue
				for pos in self.get_bit_position_with_1(self.vector[i]):
					yield i * 8 + pos


class NumberCollectionTests(unittest.TestCase):
	def test_empty_sequence(self):
		numbers = []
		sorted_numbers = list(NumberCollection(None, numbers).sort())
		self.assertEqual(0, len(sorted_numbers))

	def test_normal_sequence(self):
		numbers = [1, 3, 2, 0]
		sorted_numbers = list(NumberCollection(3, numbers).sort())
		
		self.assertListEqual([0, 1, 2, 3], sorted_numbers)

	def test_repeat_sequence(self):
		numbers = [1, 2, 1]
		with self.assertRaises(ValueError):
			NumberCollection(2, numbers).sort()

	def test_contains_nagative_number_sequence(self):
		numbers = [1, 2, -3]
		with self.assertRaises(ValueError):
			NumberCollection(2, numbers).sort()

	def test_contains_greater_number_sequence(self):
		numbers = [1, 2, 3]
		with self.assertRaises(ValueError):
			NumberCollection(2, numbers).sort()

	def test_contains_char_sequence(self):
		numbers = [1, 2, 'a']
		with self.assertRaises(ValueError):
			NumberCollection(2, numbers).sort()

	def test_contains_none_sequence(self):
		numbers = [1, None]
		with self.assertRaises(ValueError):
			NumberCollection(2, numbers).sort()


unittest.main()