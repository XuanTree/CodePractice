using System;
using System.Collections;

namespace HashTable
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //创建一个拥有100个容量的哈希表对象(该参数可不填)
            Hashtable ht = new Hashtable(100);
            //键值对内容,需要添加两个参数(类比Python的字典)
            ht.Add(1,"张三");
            ht.Add(2,"李四");
            /*
             * 值得注意的是,哈希表中的数据是无序存放的,其搜索全靠"键"
             * 这也说明了,哈希表中的键是不允许重复存在的,下面就是一个
             * 打印哈希表中值的示例
            */
            Console.WriteLine(ht[1]);
            //移除哈希表中的某个值(同样用键定位)
            ht.Remove(2);
            //为了演示遍历效果,这里添加两个元素
            ht.Add(2,"李四");
            ht.Add(3,"王五");
            //遍历哈希表
            foreach (var hashItem in ht) 
            {
                Console.WriteLine(hashItem);
            }
            //用var是一种相当偷懒的方法,其实哈希表元素的类型是DictionaryEntry
            Console.WriteLine();
            foreach(DictionaryEntry dictionaryEntry in ht)
            {
                Console.WriteLine("{0} : {1}",dictionaryEntry.Key,dictionaryEntry.Value);
            }
            Console.WriteLine();
            //Contains方法查找哈希表中是否存在该元素,返回布尔
            Console.WriteLine(ht.ContainsKey(1));
            Console.WriteLine(ht.ContainsValue("张三"));
        }
    }
}