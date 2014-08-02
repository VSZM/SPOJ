using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

    public class FCTRL2
    {

		public static void Main()
        {
            int case_count = int.Parse(Console.ReadLine());
            BigInteger[] fact = new BigInteger[101];

			fact[0] = 1;

            for (int i = 1; i < 101; i++)
            {
                fact[i] = i * fact[i - 1];
            }

            while (case_count-- > 0)
            {
                Console.WriteLine(fact[int.Parse(Console.ReadLine())]);
            }
        }

    }
