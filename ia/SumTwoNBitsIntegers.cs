using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    class SumTwoNBitsIntegers {
        public bool[] Sum(bool[] a, bool[] b) {
            var length = Math.Max(a.Length, b.Length);
            var result = new bool[length + 1];
            bool carry = false;
            for (var bitAt = 0; bitAt < length; bitAt++) {
                BitAdd(carry, a[bitAt], b[bitAt], out result[bitAt], out carry);
            }
            result[length] = carry;
            return result;
        }

        private void BitAdd(bool x, bool y, bool z, out bool result, out bool carry) {
            var sum = Convert.ToInt32(x) + Convert.ToInt32(y) + Convert.ToInt32(z);
            result = (sum & 1) == 1;
            carry = (sum & 2) == 1;
        }

        [Test]
        public void TestSumTwoIntegers() {
            //new BitArray
            //var x = new[] {};
            //var y = new[] { };

            //var result = Sum(x, y);

            //Assert.AreEqual(ToBitArray(83123), result);
        }
    }
}
