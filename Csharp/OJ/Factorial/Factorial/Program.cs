using System;//题源:https://www.luogu.com.cn/problem/P1009
namespace Factorial;
class Program
{
    static void Main(string[] args)
    {
        if (int.TryParse(Console.ReadLine(), out int number) && number >= 0)
        {
            long result = Factorial(number);
            Console.WriteLine($"{result}");
        }
    }

    public static long Factorial(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        return n * Factorial(n - 1);
    }
}