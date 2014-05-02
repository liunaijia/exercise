using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    internal class InsertionSort {
        public void Sort<T>(IList<T> array) {
            Sort(array, (x, y) => Comparer.Default.Compare(x, y));
        }

        public void SortDesc<T>(IList<T> array) {
            Sort(array, (x, y) => Comparer.Default.Compare(y, x));
        }

        private void Sort<T>(IList<T> array, Func<T, T, int> comparer) {
            for (var i = 1; i < array.Count; i++) {
                var key = array[i];
                var j = i - 1;
                while (j >= 0 && comparer.Invoke(array[j], key) > 0) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = key;
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
    }
}
