using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace IA {
    class SortTests {
        private static readonly Random _Random = new Random();
        
        private IList<int> CreateRandomNumberSequence(int maxNumber = 100, int maxLength = 100) {
            var numbers = new int[_Random.Next(maxLength)];
         
            for (var i = 0; i < numbers.Length; i++)
                numbers[i] = _Random.Next(maxNumber);
            
            return numbers.Distinct().OrderBy(_ => _).ToList();
        }

        public void RandomTest(Action<IList<int>> sortAction) {
            const int TEST_TIMES = 10;
            foreach (var numbers in Enumerable.Range(0, TEST_TIMES).Select(n => CreateRandomNumberSequence())) {
                sortAction.Invoke(numbers);
                var sortedNumbers = numbers.OrderBy(_ => _).ToList();

                Assert.AreEqual(sortedNumbers, numbers);
            }
        }
    }
}
