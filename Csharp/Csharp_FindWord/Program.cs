using System;

namespace FindTheWordMainCode;
class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("输入一段需要查找单词的英文文本:");
        string inputText = Console.ReadLine();
        Console.WriteLine("输入需要查找的单词:");
        string wordToFind = Console.ReadLine();
        int count = CountWordOccurrences(inputText, wordToFind);
        Console.WriteLine($"单词 '{wordToFind}' 在文本中出现了 {count} 次。");
    }
    static int CountWordOccurrences(string text, string word)
    {
        if (string.IsNullOrEmpty(text) || string.IsNullOrEmpty(word))
        {
            return 0;
        }
        string[] words = text.Split(new char[] { ' ', '\n', '\r', '\t', '.', ',', '!', '?'}, StringSplitOptions.RemoveEmptyEntries);
        int count = 0;
        foreach (string w in words)
        {
            if (string.Equals(w, word, StringComparison.OrdinalIgnoreCase))
            {
                count++;
            }
        }
        return count;
    }
}