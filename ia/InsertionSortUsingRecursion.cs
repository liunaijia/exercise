using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    class InsertionSortUsingRecursion {
        private void Sort<T>(IList<T> numbers, int insertNumberIndex = 1) {
            if (insertNumberIndex < numbers.Count - 1)
                Sort(numbers, insertNumberIndex + 1);
            // insert numbers[insertNumberIndex] into sorted numbers[0..insertNumberIndex - 1]
            var key = numbers[insertNumberIndex];
            var i = insertNumberIndex - 1;
            while (i >= 0 && Comparer.Default.Compare(numbers[i], key) > 0) {
                numbers[i + 1] = numbers[i];
                i--;
            }
            numbers[i + 1] = key;
        }

        [Test]
        public void TestSortNumbers() {
            var numbers = new[] { 3, 4, 1, 10 };
            Sort(numbers);

            Assert.AreEqual(new[] { 1, 3, 4, 10 }, numbers);
        }

    }
}
