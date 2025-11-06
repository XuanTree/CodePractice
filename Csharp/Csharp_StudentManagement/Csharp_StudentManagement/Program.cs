using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
namespace Csharp_StudentManagement
{
    class Program
    {
        static async Task Main(string[] args)
        {
            Console.Title = "Student Management System";
            Console.ForegroundColor = ConsoleColor.Green;
            await TypeWriter("Welcome to Student Management System!");
            Thread.Sleep(2000);
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.White;
            await TypeWriter("Please select an option:");
            Console.WriteLine("1. Add Student");
            Console.WriteLine("2. View Students");
            Console.WriteLine("3. Search Student");
            Console.WriteLine("4. Add Scores");
            Console.WriteLine("5. Delete Student");
            Console.WriteLine("6. Exit");
            Console.Write("Enter your choice: ");
            int choice = int.Parse(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    await TypeWriter("Add Student");
                    Console.Clear();
                    break;
                case 2:
                    await TypeWriter("View Students");
                    break;
                case 3:
                    await TypeWriter("Search Student");
                    break;
                case 4:
                    await TypeWriter("Add Scores");
                    break;
                case 5:
                    await TypeWriter("Delete Student");
                    break;
                case 6:
                    await TypeWriter("Exit...........");
                    Console.Clear();
                    Console.WriteLine("Bye!");
                    Thread.Sleep(2000);
                    Environment.Exit(0);
                    break;
                default:
                    break;
            }
            static async Task TypeWriter(string text)
            {
                foreach (char c in text)
                {
                    Console.Write(c);
                    await Task.Delay(120); // 延迟一段时间
                }
                Console.WriteLine(); // 完成后换行
            }
            static List<Student> AddStudent(string name)
            {
                Student student = new Student();
                List<Student> studentList = new List<Student>();
                studentList.Add(student);
                return studentList;
            }
        }
    }
}
