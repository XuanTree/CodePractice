using System;

namespace maincode
{
    class Program
    {
        static void Main(String[] args)
        {
            Console.Title = "C# Point_Count";

            Console.WriteLine("作品评分系统 欢迎使用!");

            while (true)
            {
                Console.Write("输入个人评分:");
                double personalPoint = Convert.ToDouble(Console.ReadLine());

                Divide();

                Console.Write("输入豆瓣评分:");
                double douBanPoint = Convert.ToDouble(Console.ReadLine());

                Divide();

                Console.Write("请输入Bangumi评分:");
                double bangumiPonit = Convert.ToDouble(Console.ReadLine());

                Divide();

                double outPut = personalPoint * 0.2 + douBanPoint * 0.4 + bangumiPonit * 0.4;
                
                Convert.ToString(outPut);
                Convert.ToDouble(outPut);
                
                Console.WriteLine("最终评分:" + outPut);
                Divide();
                Console.ReadKey();
            }

        }
        static void Divide()
        {
            Console.WriteLine("----------------------");
        }
    }
}