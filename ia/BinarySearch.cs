using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    internal class BinarySearch {
        private int IndexOf<T>(IList<T> collection, T target) {
            return IndexOf(collection, target, 0, collection.Count);
        }

        private int IndexOf<T>(IList<T> collection, T target, int start, int end) {
            if (start > end)
                return -1;
            var middle = (start + end) / 2;
            
            if (Comparer.Default.Compare(target, collection[middle]) < 0)
                return IndexOf<T>(collection, target, start, middle - 1);

            if (Comparer.Default.Compare(target, collection[middle]) > 0)
                return IndexOf<T>(collection, target, middle + 1, end);

            return middle;
        }

        [Test]
        public void TestExistsNumber() {
            const int TEST_TIMES = 10;
            foreach (var n in Enumerable.Range(0, TEST_TIMES)) {
                var random = new Random();
                var numbers = new int[random.Next(100)];
                for (var i = 0; i < numbers.Length; i++)
                    numbers[i] = random.Next(100);
                numbers = numbers.Distinct().OrderBy(_ => _).ToArray();

                for (var i = 0; i < numbers.Length; i++) {
                    var index = IndexOf(numbers, numbers[i]);

                    Assert.AreEqual(i, index);
                }
            }
        }

        [Test]
        public void TestNotExistsNumber() {
            var numbers = new[] {1, 3};

            var index = IndexOf(numbers, 2);

            Assert.AreEqual(-1, index);
        }
    }
}