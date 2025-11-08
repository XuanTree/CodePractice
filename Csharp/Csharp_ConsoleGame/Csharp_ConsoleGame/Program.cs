using System;
using System.Threading;
namespace Csharp_ConsoleGame
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
            string[] skills = ["X斩击", "双重治疗", "防御增加"];
            Console.WriteLine("\a输入 1 开始游戏！\a");
            try
            {
                int test = Convert.ToInt32(Console.ReadLine());
                if (test == 1)
                {
                    game_Property = true;
                    Console.WriteLine("游戏准备开始！\a");
                    Thread.Sleep(3000);
                    //生成玩家
                    Console.WriteLine("你有以下技能可以选择：");
                    foreach (var VARIABLE in skills)
                    {
                        Console.Write(VARIABLE + " ");
                    }
                    Console.WriteLine("");
                    Console.WriteLine("请选择你的技能:\a");
                    Character Player = new Character("你", 400, 10, "");
                    Player.skill = Console.ReadLine();
                    //设置我方技能
                    if (Player.skill == "")
                    {
                        Console.WriteLine();
                    }
                    else if (Player.skill == "X斩击")
                    {
                        Console.WriteLine("\a你的技能是" + Player.skill);
                    }
                    else if (Player.skill == "双重治疗")
                    {
                        Console.WriteLine("\a你的技能是" + Player.skill);
                    }
                    else if (Player.skill == "防御增加")
                    {
                        Console.WriteLine("\a你的技能是" + Player.skill);
                    }
                    else
                    {
                        Console.WriteLine("\a你输入了什么技能？");
                    }
                    //生成敌人
                    int enemyHealth = random.Next(2000, 3000);
                    int enemyDefence = random.Next(1, 10);
                    Character Enemy = new Character("小怪", enemyHealth, enemyDefence, "");
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
                        Enemy.skill = "防御增加";
                    }
                    int turn = 1;
                    Console.WriteLine("玩家血量:" + Player.health + "  敌人血量:" + Enemy.health);
                    Console.WriteLine("玩家防御:" + Player.defence + "  敌人防御:" + Enemy.defence);
                    Console.WriteLine("玩家伤害:" + Player.damage + "  敌人伤害:" + Enemy.damage);
                    Console.WriteLine("玩家技能:" + Player.skill + "  敌人技能:" + Enemy.skill);
                    Space();
                    Console.Clear();
                    //游戏开始
                    while (game_Property == true)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("第" + turn + "回合");
                        Console.ResetColor();
                        game_Property = Start(Player, Enemy, game_Property);
                        turn++;
                    }
                }
                else        //错误捕捉
                {
                    Console.WriteLine("\a叫你输入1你瞎吗\a");
                    Space();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                Space();
                throw;
            }
        }
        static bool Start(Character Player, Character Enemy, bool boolean)
        {
            Console.WriteLine("按下空格释放技能!");

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("**************************************");
            Console.ResetColor();
            if (Player.health > 0 && Enemy.health > 0)
            {
                Skill(Player, Player.skill);
                Player.Attack(Enemy);
                Space();
                if (Enemy.health > 0)
                {
                    Skill(Enemy, Enemy.skill);
                    Enemy.Attack(Player);
                    Space();
                }
                else
                {
                    Console.WriteLine("你赢了！");
                    return false;
                }
                if (Player.health <= 0)
                {
                    Console.WriteLine("你输了！");
                    return false;
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        static void Space()
        {
            Console.WriteLine(" ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("---------按Enter键继续下一步----------");
            Console.ResetColor();
            Console.WriteLine(" ");
            Console.ReadKey();
        }
        static void Skill(Character character, string skill)
        {
            ConsoleKeyInfo key = Console.ReadKey(true);
            if (key.Key == ConsoleKey.Spacebar)
            {
                Console.WriteLine(character.name + "使用了" + character.skill + "!");
                if (skill == "X斩击")
                {
                    character.damage *= 2;
                }
                else if (skill == "双重治疗")
                {
                    character.health *= 2;
                }
                else
                {
                    character.defence += 10;
                }
                return;
            }
            else
            {
                return;
            }
        }
    }
}