using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    public class AlgorithmEfficiencyCompare {
        private int GetMinNumberThatFunc1FasterThanFunc2(Func<int, double> func1, Func<int, double> func2) {
            var n = 1;
            while (func1.Invoke(n) >= func2.Invoke(n)) {
                n++;
            }

            return n;
        }

        [Test]
        public void Func1FasterThanFunc2When44() {
            Func<int, double> func1 = n => 100 * n * n;
            Func<int, double> func2 = n => Math.Pow(2, n);
            var min = GetMinNumberThatFunc1FasterThanFunc2(func1, func2);

            Assert.AreEqual(15, min);
        }
    }
}