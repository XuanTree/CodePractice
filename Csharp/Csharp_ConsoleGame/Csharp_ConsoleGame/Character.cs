using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Csharp_ConsoleGame
{
    public class Character
    {
        public int health;
        public int defence;
        public int damage;
        public string name;
        public string skill;
        Random random = new Random();
        public Character(string name, int health, int defence, string skill)
        {
            this.health = health;
            this.name = name;
            this.skill = "";
            this.defence = defence;
            damage = random.Next(80, 200);
        }
        public void Attack(Character character)
        {
            if (this.health <= 0)
            {
                Console.WriteLine(this.name + "已经死亡，无法攻击！");
                return;
            }
            else
            {
                if (damage < 0)
                {
                    damage = 0;
                }
                character.health -= damage;
                Console.WriteLine(this.name + "对" + character.name + "造成了" + damage + "点伤害！");
                if (character.health <= 0)
                {
                    character.health = 0;
                    Console.WriteLine(character.name + "已经死亡！");
                }
                else
                {
                    Console.WriteLine(character.name + "还剩下" + character.health + "点生命值！");
                }
            }
        }

    }
}