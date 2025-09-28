using System;
using System.Threading;//如果想慢一点看的话就取消注释Thread.Sleep(1000);


namespace mainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Fibonacci sequence";
            float a = 1, b = 1;
            float temp;
            while (true)
            {
                Console.WriteLine(b);
                Console.ForegroundColor = ConsoleColor.DarkGreen;
                float result = a / b;
                Console.WriteLine(result);
                temp = a;
                a = b;
                b += temp;
                Console.ForegroundColor = ConsoleColor.White;
                //Thread.Sleep(1000);
                if (b >= 100000)
                {
                    Console.WriteLine("就演示到这里吧");
                    break;
                }
            }
            Console.ReadKey();
        }
    }
}