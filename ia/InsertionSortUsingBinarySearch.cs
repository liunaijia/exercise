using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    internal class InsertionSortUsingBinarySearch {
        public void Sort<T>(IList<T> list) {
            Sort(list, (x, y) => Comparer.Default.Compare(x, y));
        }

        public void SortDesc<T>(IList<T> list) {
            Sort(list, (x, y) => Comparer.Default.Compare(y, x));
        }

        private int FindInsertPosition<T>(IList<T> list, T target, int start, int end, Func<T, T, int> comparer) {
            if (start > end)
                return Math.Max(start, end);
            var middle = (start + end) / 2;

            if (comparer.Invoke(target, list[middle]) < 0)
                return FindInsertPosition<T>(list, target, start, middle - 1, comparer);

            if (comparer.Invoke(target, list[middle]) > 0)
                return FindInsertPosition<T>(list, target, middle + 1, end, comparer);

            return middle;
        }

        private void Sort<T>(IList<T> list, Func<T, T, int> comparer) {
            for (var i = 1; i < list.Count; i++) {
                var key = list[i];

                var insertPosition = FindInsertPosition(list, key, 0, i - 1, comparer);

                for (var j = i - 1; j >= insertPosition; j--)
                    list[j + 1] = list[j];
                
                list[insertPosition] = key;
            }
        }

        [Test]
        public void TestSortNumbers() {
            var numbers = new[] {3, 4, 1, 10};
            Sort(numbers);

            Assert.AreEqual(new[] {1, 3, 4, 10}, numbers);
        }

        [Test]
        public void TestSortDescNumbers() {
            var numbers = new[] {3, 4, 1, 10};
            SortDesc(numbers);

            Assert.AreEqual(new[] {10, 4, 3, 1}, numbers);
        }

        [Test]
        public void RandomTest() {
            new SortTests().RandomTest(Sort);
        }
    }
}
