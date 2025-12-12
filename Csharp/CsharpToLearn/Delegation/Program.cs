using System;
using System.Reflection.Metadata;
//委托是一种类型安全的函数指针,它允许将*方法*作为参数传给其他方法
namespace Delegation
{
    //定义一个委托,注意委托的定义位置
    public delegate void Handler(string message);
    internal class Program
    {
        static void Main(string[] args)
        {
            Handler handler = new Handler(Function);
            //将Function方法委托给handler
            handler("已经收到委托!");

            ClassExample example = new ClassExample() { Price = 8000 };
            //订阅一个事件
            example.PriceChange += ExamplePriceChange;
            //价格变动
            example.Price = 1000;
        }
        //注意这里,委托方法的参数和被委托方法的参数需一致
        static void Function(string message)
        {
            Console.WriteLine("Here is a message: {0}",message);
        }
        static void ExamplePriceChange(double rawPrice,double newPrice)
        {
            Console.WriteLine("价格变动!原价: {0},现价: {1}!!!",rawPrice,newPrice);
        }
    }
}