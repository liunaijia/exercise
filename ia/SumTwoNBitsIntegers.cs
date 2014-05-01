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
            for (var bitAt = length - 1; bitAt >= 0; bitAt--) {
                BitAdd(carry, a[bitAt], b[bitAt], out result[bitAt + 1], out carry);
            }
            result[0] = carry;
            return result;
        }

        private void BitAdd(bool x, bool y, bool z, out bool result, out bool carry) {
            var sum = Convert.ToInt32(x) + Convert.ToInt32(y) + Convert.ToInt32(z);
            result = (sum & 1) == 1;
            carry = (sum & 2) == 2;
        }

        private bool[] ToBoolArray(string number) {
            return number.ToCharArray().Select(_ => _ == '1').ToArray();
        }

        [Test]
        public void TestSumTwoIntegers() {
            var x = ToBoolArray("101101");
            var y = ToBoolArray("101101");
            
            var result = Sum(x, y);

            Assert.AreEqual(ToBoolArray("1011010"), result);
        }
    }
}
