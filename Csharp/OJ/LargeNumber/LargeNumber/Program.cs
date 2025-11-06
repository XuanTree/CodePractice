using System;
using System.Numerics;
namespace LargeNumber;
class Program
{
    static void Main()
    {
        BigInteger sum = 0;
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = n; i > 0; i--)
        {
            sum += CalculateFactorial(i);
        }
        Console.WriteLine($"{sum}");
    }
    static BigInteger CalculateFactorial(int n)
    {
        BigInteger result = 1;
        for (int i = n; i > 0; i--)
        {
            result *= i;
        }
        return result;
    }
}