using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    internal class BinarySearch {
        public int IndexOf<T>(IList<T> collection, T target) {
            // notice end is collection.Count - 1
            return IndexOf(collection, 0, collection.Count - 1, target);
        }

        public int IndexOf<T>(IList<T> collection, int start, int end, T target) {
            if (start > end)
                return -1;
            var middle = (start + end) / 2;

            var compareResult = Comparer.Default.Compare(target, collection[middle]);
            if (compareResult < 0)
                return IndexOf<T>(collection, start, middle - 1, target);

            if (compareResult > 0)
                return IndexOf<T>(collection, middle + 1, end, target);

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
        public void TestNotExistsNumber1() {
            var numbers = new[] {1, 3};

            var index = IndexOf(numbers, 2);

            Assert.AreEqual(-1, index);
        }

        [Test]
        public void TestNotExistsNumber2() {
            var numbers = new[] { 1, 3 };

            var index = IndexOf(numbers, 10);

            Assert.AreEqual(-1, index);
        }

        [Test]
        public void TestNotExistsNumber3() {
            var numbers = new[] { 1, 3 };

            var index = IndexOf(numbers, 0);

            Assert.AreEqual(-1, index);
        }
    }
}