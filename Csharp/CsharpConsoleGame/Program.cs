using System;
using System.Formats.Tar;
using System.Threading;
using System.Xml;
using Characters;

namespace mainCode
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "C# Console Game";
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("C# Console Game");
            Console.ResetColor();
            Random random = new Random();
            bool game_Property = false;
            string[] skills = ["X斩击","双重治疗","碎甲"];
            
            Console.WriteLine("输入 1 开始游戏！");
            try
            {
                int test = Convert.ToInt32(Console.ReadLine());
                if (test == 1)
                {
                    game_Property = true;
                    Console.WriteLine("游戏准备开始！");
                    Thread.Sleep(3000);
                    
                    //生成玩家
                    Console.WriteLine("你有以下技能可以选择：");
                    foreach (var VARIABLE in skills)
                    {
                        Console.Write(VARIABLE+" ");
                    }
                    Console.WriteLine("");
                    Console.WriteLine("请选择你的技能:");
                    Character Player = new Character("你",400,10,"");
                    Player.skill = Console.ReadLine();
                    
                    //设置我方技能
                    if (Player.skill == "")
                    {
                        Console.WriteLine();
                    }
                    else if (Player.skill == "X斩击")
                    {
                        Console.WriteLine("你的技能是"+Player.skill);
                    }
                    else if (Player.skill == "双重治疗")
                    {
                        Console.WriteLine("你的技能是"+Player.skill);
                    }
                    else if (Player.skill == "碎甲")
                    {
                        Console.WriteLine("你的技能是"+Player.skill);
                    }
                    else
                    {
                        Console.WriteLine("你输入了什么技能？");
                    }
                    
                    //生成敌人
                    Character Enemy = new Character("小怪",2500,5,"");
                    int result = random.Next(3);
                    
                    //设置敌人的技能
                    if (result == 1)
                    {
                        Enemy.skill = "X斩击";
                    }
                    else if (result == 2)
                    {
                        Enemy.skill = "双重治疗";
                    }
                    else if (result == 3)
                    {
                        Enemy.skill = "碎甲";
                    }

                    while (game_Property = true)
                    {
                        Start(Player,Enemy);
                    }
                }
                else
                {
                    Console.WriteLine("叫你输入1你瞎吗");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                Space();
                throw;
            }
        }

        static void Start(Character Player,Character Enemy)
        {
            
        }

        static void Space()
        {
            Console.WriteLine("---------按任意键继续下一步----------");
            Console.ReadKey();
            Thread.Sleep(1000);
        }
    }
}

namespace Characters
{
    public class Character
    {
        public int health;
        public int defence;
        public string name;
        public string skill;
        public Character(string name, int health, int defence,string skill)
            {
            this.health = health;
            this.name = name;
            this.skill = "";
            }
        
    }
}