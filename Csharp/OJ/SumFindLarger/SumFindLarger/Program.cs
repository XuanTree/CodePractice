using System;
namespace SumFindLarger;
class Program
{
    static void Main(string[] args)
    {
        double sum = 0;
        int n = 1;
        int k = Convert.ToInt32(Console.ReadLine());
        for (; ; n++)
        {
            sum += 1.0 / n;
            if (sum > k)
            {
                break;
            }
        }
        Console.WriteLine(n);
    }
}