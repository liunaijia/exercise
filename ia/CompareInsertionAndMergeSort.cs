using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    public class CompareInsertionAndMergeSort {
        private int GetTheNumberOfMergeIsFasterThanInsertionSort() {
            // insertion cost 8 * n ^ 2
            // merge cost 64 * n * log2(n)
            var n = 2;
            while (true) {
                var insertionCost = 8 * n * n;
                var mergeCost = 64 * n * Math.Log(n, 2);
                if (insertionCost > mergeCost)
                    break;
                n++;
            }

            return n;
        }

        [Test]
        public void MergeIsFasterThanInsertionWhenSorting44Numbers() {
            var n = GetTheNumberOfMergeIsFasterThanInsertionSort();
            Assert.AreEqual(44, n);
        }
    }
}