#!/usr/bin/env python
import unittest

class MyVector:
	def __init__(self, size):
		self.vector = bytearray(size)
		self.used_bytes = set()

	def read_byte(self, index):
		if (index in self.used_bytes):
			return self.vector[index]
		raise ValueError(index, '越界')

	def write_byte(self, index, value):
		if (index not in self.used_bytes):
			self.used_bytes.add(index)
		self.vector[index] = value


class MyVectorTests(unittest.TestCase):
	def test_out_of_range(self):
		with self.assertRaises(ValueError):
			MyVector(10).read_byte(1)

	def test_write_read(self):
		vector = MyVector(10)
		vector.write_byte(2, 19)
		value = vector.read_byte(2)

		self.assertEqual(19, value)

unittest.main()
		