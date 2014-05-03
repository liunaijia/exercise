using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    class SelectionSort {
        public void Sort<T>(IList<T> array) {
            for (var i = 0; i < array.Count - 1; i++) {
                var smallestIndex = i;
                for(var j = i + 1; j < array.Count; j++)
                    if (Comparer.Default.Compare(array[j], array[smallestIndex]) < 0)
                        smallestIndex = j;
                
                // swap smallest and array[j]
                var t = array[i];
                array[i] = array[smallestIndex];
                array[smallestIndex] = t;
            }
        }

        [Test]
        public void TestSortNumbers() {
            var numbers = new[] { 3, 4, 1, 10 };
            Sort(numbers);

            Assert.AreEqual(new[] { 1, 3, 4, 10 }, numbers);
        }
    }
}
