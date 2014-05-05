using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    class NumbersFind {
        [Test]
        public void TestExistsNumbers() {
            var list = new[] {1, 5, 2, 4, 3, 8};

            int a, b;
            var found = FindNumbersThatSumEquals(list, 11, out a, out b);

            Assert.True(found);
            Assert.AreEqual(11, a + b);
        }

        [Test]
        public void TestNotExistsNumbers() {
            var list = new[] { 1, 5, 2, 4, 3, 8 };

            int a, b;
            var found = FindNumbersThatSumEquals(list, 20, out a, out b);

            Assert.False(found);
        }

        private bool FindNumbersThatSumEquals(IList<int> list, int sum, out int a, out int b) {
            // sort list using merge sort algorithm
            new MergeSort().Sort(list, 0, list.Count);  // Θ(nlgn)

            for (var i = 0; i < list.Count - 1; i++) {
                a = list[i];
                b = sum - a;
                // binary search b in list[i + 1] to list[END]
                var indexOfB = new BinarySearch().IndexOf(list, i + 1, list.Count - 1, b);   // Θ(lgn)

                if (indexOfB != -1)
                    return true;
            }

            a = 0;
            b = 0;
            return false;
        }
    }
}
