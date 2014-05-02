using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    class SequenceFind {
        public int IndexOf<T>(IList<T> array, T value) {
            for (var i = 0; i < array.Count; i++) {
                if (Comparer.Default.Compare(array[i], value) == 0)
                    return i;
            }
            return -1;
        }

        [Test]
        public void FindExistNumberShouldReturnIndex() {
            var numbers = new[] {31, 59, 34};
            var idx = IndexOf(numbers, 59);
            Assert.AreEqual(1, idx);
        }

        [Test]
        public void FindNotExistNumberShouldReturnNegative() {
            var numbers = new[] { 31, 59, 34 };
            var idx = IndexOf(numbers, 32);
            Assert.AreEqual(-1, idx);
        }
    }
}
