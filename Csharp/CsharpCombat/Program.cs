using System;
using characters;

namespace mainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "C# CombatTest";
            Console.WriteLine("双人对决测试");
            bool gameRunning_Property = true;
            Character Player = new Character();
            Character Enemy = new Character();

            Starter(Player, Enemy);

            while (gameRunning_Property == true)
            {
                if (Player.HP <= 0 || Enemy.HP <= 0)
                {
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("测试结束！");
                    Console.ReadKey();
                    break;
                }
                else
                {
                    Player.Attack(Enemy);

                    Divider();

                    Enemy.Attack(Player);

                    Divider();
                }
            }
        }
        static void Starter(Character character1, Character character2)
        {


            Console.ForegroundColor = ConsoleColor.Green;
            try
            {
                Console.WriteLine("玩家1的名字是:");
#pragma warning disable CS8601 // 引用类型赋值可能为 null。
                character1.name = Console.ReadLine();
#pragma warning restore CS8601 // 引用类型赋值可能为 null。
                Console.WriteLine("玩家2的名字是:");
#pragma warning disable CS8601 // 引用类型赋值可能为 null。
                character2.name = Console.ReadLine();
#pragma warning restore CS8601 // 引用类型赋值可能为 null。
                Console.ForegroundColor = ConsoleColor.White;
                Divider();
                Console.WriteLine("设置参数");

                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("玩家1的伤害:");
                character1.damage = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("玩家1的生命值:");
                character1.HP = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("玩家2的伤害:");
                character2.damage = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("玩家2的生命值:");
                character2.HP = Convert.ToInt32(Console.ReadLine());

                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine("参数设置完毕！测试准备开始！");
                Divider();
            }
            catch
            {
                Console.WriteLine("程序异常，你是不是输入错什么东西了？");
                Divider();
            }
        }
        static void Divider()
        {
            Console.WriteLine(" ");
            Console.WriteLine("--------------------------------------");
            Console.WriteLine(" ");
            System.Threading.Thread.Sleep(1000);
        }
    }
}
namespace characters
{
    public class Character()
    {
        public string name;
        public int HP;
        public int damage;

        public void Attack(Character character)
        {
            character.HP -= damage;
            damage.ToString();
            Console.WriteLine(character.name + "受到" + damage + "伤害！");
            Convert.ToInt32(damage);
            Console.WriteLine(character.name + "还剩下" + character.HP + "生命值！");
        }
    }
}