using System;
using System.Security.Principal;
namespace WordCount
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int count = 0;
            string wordToFind = Console.ReadLine();
            char firstLetter = char.ToLower(wordToFind[0]);
            string article = Console.ReadLine();
            wordToFind = wordToFind.ToLower();
            article = article.ToLower();
            string[] words = article.Split(new char[] { ' ', '.', ',', '!', '?' },StringSplitOptions.RemoveEmptyEntries);
            int position = -1;
            foreach (string word in words)
            {
                if(wordToFind == word)
                {
                    count++;
                }
            }
            for (int i = 0; i < article.Length; i++)
            {
                if (char.IsWhiteSpace(article[i]) || char.IsPunctuation(article[i]))
                {
                    continue;
                }
                if (article[i] == firstLetter)
                {
                    if (i == 0 || char.IsWhiteSpace(article[i - 1]) || char.IsPunctuation(article[i - 1]))
                    {
                        position = i;
                        break;
                    }
                }
            }
            if (count > 0)
            {
                Console.Write(count + " ");
                Console.Write(position);
            }
            else
            {
                Console.WriteLine(-1);
            }
            Console.ReadKey();
        }
    }
}
