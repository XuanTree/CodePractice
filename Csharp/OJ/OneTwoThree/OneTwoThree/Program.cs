using System;//题源:https://www.luogu.com.cn/problem/P1008
using System.Collections.Generic;
namespace OneTwoThree;
class Program
{
    static void Main()
    {
        List<string> results = new List<string>();
        for (int i = 123; i <= 329; i++)
        {
            int num1 = i;
            int num2 = i * 2;
            int num3 = i * 3;
            if (IsValidCombination(num1, num2, num3))
            {
                results.Add($"{num1} {num2} {num3}");
            }
        }
        foreach (string result in results)
        {
            Console.WriteLine(result);
        }
    }
    static bool IsValidCombination(int a, int b, int c)
    {
        if (a < 100 || a > 999 || b < 100 || b > 999 || c < 100 || c > 999)
        {
            return false;
        }
        if (b != 2 * a || c != 3 * a)
        {
            return false;
        }
        bool[] digits = new bool[10]; 
        digits[a / 100] = true;
        digits[(a / 10) % 10] = true;
        digits[a % 10] = true;

        digits[b / 100] = true;
        digits[(b / 10) % 10] = true;
        digits[b % 10] = true;

        digits[c / 100] = true;
        digits[(c / 10) % 10] = true;
        digits[c % 10] = true;
        for (int i = 1; i <= 9; i++)
        {
            if (!digits[i])
            {
                return false;
            }
        }
        return true;
    }
}