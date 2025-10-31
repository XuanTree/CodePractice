using System;
using System.IO;

namespace CsharpFileOperation;

class Program
{

    static void Main(string[] args)
    {
        Console.Title = "FileOperation";
        Console.WriteLine("文件操作程序");
        Space();
        while (true)
        {
            try
            {
                Console.WriteLine("请输入文件路径：");
                try
                {
#pragma warning disable CS8600 // 将 null 字面量或可能为 null 的值转换为非 null 类型。
                    string path = Console.ReadLine();
#pragma warning restore CS8600 // 将 null 字面量或可能为 null 的值转换为非 null 类型。
#pragma warning disable CS8604 // 引用类型参数可能为 null。
                    FolderGet(path);
#pragma warning restore CS8604 // 引用类型参数可能为 null。
                }
                catch
                {
                    Console.WriteLine(" ");
                }
            }
            catch
            {
                Console.WriteLine("程序异常,请重新操作");
            }
        }
    }

    private static void Space()
    {
        Console.WriteLine(" ");
        Console.ForegroundColor = ConsoleColor.Green;
        Console.WriteLine("************");
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine(" ");
    }
    public static void FolderGet(string path)
    {
        try
        {
            string[] files = Directory.GetFiles(path, "*", SearchOption.AllDirectories);
            foreach (string file in files)
            {
                for (int i = 0; i < files.Length; i++)
                {
                    Console.WriteLine("文件:" + files[i]);
                    Space();
                }
            }
            Console.WriteLine("获取完毕");
            Space();
        }
        catch
        {
            Console.WriteLine("程序异常,请重新操作");
        }
    }
}
