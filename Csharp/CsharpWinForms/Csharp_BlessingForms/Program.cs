using System.Reflection.Metadata;
using System.Windows.Forms;
using System.Collections.Generic;

namespace Csharp_BlessingForms;

static class Program
{
    /// <summary>
    ///  The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
        // To customize application configuration such as set high DPI settings or default font,
        // see https://aka.ms/applicationconfiguration.
        Application.EnableVisualStyles();
        Application.SetCompatibleTextRenderingDefault(false);
        Random random = new Random();
        List<string> blessings = GetBlessings();
        for(int i = 0; i < 10; i++)
        {
            int index = random.Next(blessings.Count);
            string blessing = blessings[index];
            BlessingForms.ShowBlessing(blessing);
        }
    }
    static List<string> GetBlessings()
    {
        List<string> blessings = new List<string>();
        string[] blessingsArray = {"新年快乐!","心想事成~","万事如意~","事事如意~","一切顺利~","祝你新年快乐！",
        "元旦快乐！", "愿你在新的一年,事事如意！", "吃的很好~", "睡的很好~", "玩的开心~", "学习的开心~", "工作的开心~", "生活的开心~", "美好的一年！"};
        int len = blessingsArray.Length;
        for (int i = 0; i < len; i++)
        {
            blessings.Add(blessingsArray[i]);
        }
        return blessings;
    }
}