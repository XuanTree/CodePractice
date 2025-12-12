using System;
using System.Threading.Tasks;

namespace TypeWriter;

class Program
{
    static async Task Main(string[] args)
    {
        string text = "这是一个打字机效果的演示！";
        await TypeWriterEffect(text, 150); // 每个字符间隔100毫秒
        Console.ReadKey();
    }
    static async Task TypeWriterEffect(string text, int delay)
    {
        foreach (char c in text)
        {
            Console.Write(c);
            await Task.Delay(delay); // 延迟一段时间
        }
        Console.WriteLine(); // 完成后换行
        Console.ReadKey();
    }
}
