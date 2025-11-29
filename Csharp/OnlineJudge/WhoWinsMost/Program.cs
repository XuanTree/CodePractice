using System;//题源:https://www.luogu.com.cn/problem/P1051
using System.Collections.Generic;
namespace WhoWinsMost
{
    class Program
    {
        static void Main(string[] args)
        {
            int count = int.Parse(Console.ReadLine());
            List<Student> students = new List<Student>();
            string name;
            int score1, score2, paper;
            string isMonitor, isWestern;
            for (int i = 0; i < count; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                name = input[0];
                score1 = int.Parse(input[1]);
                score2 = int.Parse(input[2]);
                isMonitor = input[3];
                isWestern = input[4];
                paper = int.Parse(input[5]);
                students.Add(new Student
                {
                    Name = name,
                    Score1 = score1,
                    Score2 = score2,
                    isMonitor = isMonitor,
                    isWestern = isWestern,
                    Paper = paper,
                    TotalScholarship = 0
                });
            }
            foreach (var student in students)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (student.Score1 > 80 && student.Paper > 0 && !student.isGet1)
                    {
                        student.TotalScholarship += 8000;
                        student.isGet1 = true;
                    }
                    if (student.Score1 > 85 && student.Score2 > 80 && !student.isGet2)
                    {
                        student.TotalScholarship += 4000;
                        student.isGet2 = true;
                    }
                    if (student.Score1 > 90 && !student.isGet3)
                    {
                        student.TotalScholarship += 2000;
                        student.isGet3 = true;
                    }
                    if (student.Score1 > 85 && student.isWestern == "Y" && !student.isGet4)
                    {
                        student.TotalScholarship += 1000;
                        student.isGet4 = true;
                    }
                    if (student.Score2 > 80 && student.isMonitor == "Y" && !student.isGet5)
                    {
                        student.TotalScholarship += 850;
                        student.isGet5 = true;
                    }
                }
            }
            FindWinner(students);
        }
        static void FindWinner(List<Student> students)
        {
            int i = 0;
            int max = 0;
            foreach (var student in students)
            {
                if (student.TotalScholarship > max)
                {
                    max = student.TotalScholarship;
                    i = students.IndexOf(student);
                }
            }
            int total = 0;
            for (int j = 0; j < students.Count; j++)
            {
                total += students[j].TotalScholarship;
            }
            Console.WriteLine(students[i].Name);
            Console.WriteLine(students[i].TotalScholarship);
            Console.WriteLine(total);
        }
    }
    class Student
    {
        public string Name { get; set; }
        public int Score1 { get; set; }
        public int Score2 { get; set; }
        public string isMonitor { get; set; }
        public string isWestern { get; set; }
        public int Paper { get; set; }
        public int TotalScholarship { get; set; }
        public bool isGet1 = false;
        public bool isGet2 = false;
        public bool isGet3 = false;
        public bool isGet4 = false;
        public bool isGet5 = false;
    }
}