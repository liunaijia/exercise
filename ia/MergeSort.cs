using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    internal class MergeSort {
        [Test]
        public void TestSortEvenLengthNumbers() {
            var numbers = new[] {3, 4, 1, 10};
            Sort(numbers);

            Assert.AreEqual(new[] {1, 3, 4, 10}, numbers);
        }

        [Test]
        public void TestSortOddLengthNumbers() {
            var numbers = new[] {3, 4, 1};
            Sort(numbers);

            Assert.AreEqual(new[] {1, 3, 4}, numbers);
        }

        [Test]
        public void TestSortSortedNumbers() {
            var numbers = new[] {11, 22, 33};
            Sort(numbers);

            Assert.AreEqual(new[] {11, 22, 33}, numbers);
        }

        [Test]
        public void TestSortReversedNumbers() {
            var numbers = new[] {10, 9, 8, 7, 6, 5, 4};
            Sort(numbers);

            Assert.AreEqual(new[] {4, 5, 6, 7, 8, 9, 10}, numbers);
        }

        private void Sort<T>(IList<T> numbers) {
            Sort(numbers, 0, numbers.Count);
        }

        /// <summary>
        /// sort the numbers
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="numbers">numbers to be sorted</param>
        /// <param name="start">sort from start index to end index elements in numbers</param>
        /// <param name="end"></param>
        public void Sort<T>(IList<T> numbers, int start, int end) {
            if (end - start > 1) {
                var middle = (start + end) / 2; // find the middle index
                Sort(numbers, start, middle); // sort the left part
                Sort(numbers, middle, end); // sort the right part
                Merge(numbers, start, end, middle); // merge two parts
            }
        }

        /// <summary>
        /// merge two sorted slices
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="numbers"></param>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <param name="middle"></param>
        private void Merge<T>(IList<T> numbers, int start, int end, int middle) {
            // split numbers into two slices, each slice is sorted
            var left = numbers.Skip(start).Take(middle - start).ToList();
            var right = numbers.Skip(middle).Take(end - middle).ToList();
            // merge two sorted slices into numbers
            var leftIndex = 0;
            var rightIndex = 0;
            for (var i = start; i < end; i++) {
                if (leftIndex >= left.Count)
                    numbers[i] = right[rightIndex++];
                else if (rightIndex >= right.Count)
                    numbers[i] = left[leftIndex++];
                else if (Comparer.Default.Compare(left[leftIndex], right[rightIndex]) < 0)
                    numbers[i] = left[leftIndex++];
                else
                    numbers[i] = right[rightIndex++];
            }
        }
    }
}