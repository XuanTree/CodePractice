using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Security.Cryptography.X509Certificates;
using System.Threading;
using System.Threading.Tasks;
namespace Csharp_StudentManagement
{
    class Program
    {
        static async Task Main(string[] args)
        {
            Console.Clear();
            Console.Title = "Student Management System";
            List<Student> studentList = new List<Student>();
            Console.ForegroundColor = ConsoleColor.Green;
            await TypeWriter("Welcome to Student Management System!");
            Thread.Sleep(1000);
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.White;
            await ShowMainUI();
            string line;
            while ((line = Console.ReadLine()) != null)
            {
                if (string.IsNullOrWhiteSpace(line))
                {
                    continue;
                }
                int choice = int.Parse(line);
                switch (choice)
                {
                    case 1:
                        await TypeWriter("Add Student...");
                        Console.Clear();
                        Console.WriteLine("How many students do you want to add?");
                        int count = int.Parse(Console.ReadLine());
                        Console.WriteLine("OK!");
                        Console.Clear();
                        string name, gender, address, phoneNumber;
                        for (int i = 0; i < count; i++)
                        {
                            await TypeWriter($"Enter student {i + 1} name,gender,age,address,phonenumber: ");
                            string[] input = Console.ReadLine().Split(' ');
                            name = input[0];
                            gender = input[1];
                            int age = int.Parse(input[2]);
                            address = input[3];
                            phoneNumber = input[4];
                            AddStudent(studentList, name, gender, age, address, phoneNumber);
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.WriteLine("Student added successfully!");
                            Console.ResetColor();
                            Thread.Sleep(2500);
                            Console.Clear();
                        }
                        break;
                    case 2:
                        await TypeWriter("View Students...");
                        Console.Clear();
                        ViewStudents(studentList);
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    case 3:
                        await TypeWriter("Search Student...");
                        Console.Clear();
                        Console.WriteLine("Enter student name to search:");
                        string nameToSearch = Console.ReadLine();
                        Console.Clear();
                        SearchStudent(studentList, nameToSearch);
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    case 4:
                        await TypeWriter("Update Students...");
                        Console.Clear();
                        Console.WriteLine("Enter student name to update:");
                        string nameToUpdate = Console.ReadLine();
                        Console.Clear();
                        UpdateStudent(studentList, nameToUpdate);
                        Thread.Sleep(2500);
                        Console.Clear();
                        break;
                    case 5:
                        await TypeWriter("Delete Student...");
                        Console.Clear();
                        Console.WriteLine("Enter student name to delete:");
                        string nameToDelete = Console.ReadLine();
                        Console.Clear();
                        DeleteStudent(studentList, nameToDelete);
                        Thread.Sleep(2500);
                        Console.Clear();
                        break;
                    case 6:
                        await TypeWriter("Exit...........");
                        Console.Clear();
                        Console.WriteLine("Bye!");
                        Thread.Sleep(1000);
                        Environment.Exit(0);
                        break;
                    default:
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("Invalid choice!");
                        Console.ResetColor();
                        Thread.Sleep(2000);
                        Console.Clear();
                        break;
                }
                await ShowMainUI();
            }
            static async Task TypeWriter(string text)
            {
                foreach (char c in text)
                {
                    Console.Write(c);
                    await Task.Delay(100);
                }
                Console.WriteLine();
            }
            static async Task ShowMainUI()
            {
                Console.WriteLine("---------------------------");
                Console.WriteLine("|Student Management System|");
                Console.WriteLine("---------------------------");
                await TypeWriter("Please select an option:");
                Console.WriteLine("---------------------------");
                Console.Write("|1. Add Student");
                Console.Write("           |\n");
                Console.Write("---------------------------\n");
                Console.Write("|2. View Students");
                Console.Write("         |\n");
                Console.Write("---------------------------\n");
                Console.Write("|3. Search Student");
                Console.Write("        |\n");
                Console.Write("---------------------------\n");
                Console.Write("|4. Update Students");
                Console.Write("       |\n");
                Console.Write("---------------------------\n");
                Console.Write("|5. Delete Student");
                Console.Write("        |\n");
                Console.Write("---------------------------\n");
                Console.Write("|6. Exit");
                Console.Write("                  |\n");
                Console.Write("---------------------------\n");
                Console.Write("Enter your choice: ");
            }
            static List<Student> AddStudent(List<Student> studentList, string name, string gender, int age, string address, string phoneNumber)
            {
                Student student = new Student();
                student.Name = name;
                student.Gender = gender;
                student.Age = age;
                student.Address = address;
                student.PhoneNumber = phoneNumber;
                studentList.Add(student);
                return studentList;
            }
            static void ViewStudents(List<Student> studentList)
            {
                Console.WriteLine("Students List:");
                Console.WriteLine("Name | Gender | Age | Address | PhoneNumber");
                Console.WriteLine("-------------------------------------------------------------------------------------------------");
                foreach (Student student in studentList)
                {
                    Console.Write(student.Name);
                    Console.Write(" | ");
                    Console.Write(student.Gender);
                    Console.Write(" | ");
                    Console.Write(student.Age);
                    Console.Write(" | ");
                    Console.Write(student.Address);
                    Console.Write(" | ");
                    Console.Write(student.PhoneNumber + "\n");
                    Console.WriteLine("-------------------------------------------------------------------------------------------------");
                }
            }
            static void SearchStudent(List<Student> studentList, string name)
            {
                bool found = false;
                int len = studentList.Count;
                for (int i = 0; i < len; i++)
                {
                    if (studentList[i].Name == name)
                    {
                        found = true;
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        Console.WriteLine("Student found!");
                        Console.ResetColor();
                        Console.Write(studentList[i].Name + " ");
                        Console.Write(studentList[i].Gender + " ");
                        Console.Write(studentList[i].Age + " ");
                        Console.Write(studentList[i].Address + " ");
                        Console.Write(studentList[i].PhoneNumber + " ");
                        break;
                    }
                }
                if (!found)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("Student not found!");
                    Console.ResetColor();
                }
            }
            static List<Student> UpdateStudent(List<Student> studentList, string name)
            {
                int len = studentList.Count;
                Console.WriteLine("Please select the values to update:");
                Console.WriteLine("1. Name");
                Console.WriteLine("2. Gender");
                Console.WriteLine("3. Age");
                Console.WriteLine("4. Address");
                Console.WriteLine("5. PhoneNumber");
                Console.Write("Enter your choice: ");
                int choice = int.Parse(Console.ReadLine());
                Console.Write("Enter the new value: ");
                string newValue = Console.ReadLine();
                for (int i = 0; i < len; i++)
                {
                    if (studentList[i].Name == name)
                    {
                        switch (choice)
                        {
                            case 1:
                                studentList[i].Name = newValue;
                                Console.ForegroundColor = ConsoleColor.Yellow;
                                Console.WriteLine("Student updated successfully!");
                                Console.ResetColor();
                                break;
                            case 2:
                                studentList[i].Gender = newValue;
                                Console.ForegroundColor = ConsoleColor.Yellow;
                                Console.WriteLine("Student updated successfully!");
                                Console.ResetColor();
                                break;
                            case 3:
                                studentList[i].Age = int.Parse(newValue);
                                Console.ForegroundColor = ConsoleColor.Yellow;
                                Console.WriteLine("Student updated successfully!");
                                Console.ResetColor();
                                break;
                            case 4:
                                studentList[i].Address = newValue;
                                Console.ForegroundColor = ConsoleColor.Yellow;
                                Console.WriteLine("Student updated successfully!");
                                Console.ResetColor();
                                break;
                            case 5:
                                studentList[i].PhoneNumber = newValue;
                                Console.ForegroundColor = ConsoleColor.Yellow;
                                Console.WriteLine("Student updated successfully!");
                                Console.ResetColor();
                                break;
                            default:
                                Console.ForegroundColor = ConsoleColor.Red;
                                Console.WriteLine("Invalid choice!");
                                Console.ResetColor();
                                break;
                        }
                        break;
                    }
                }
                return studentList;
            }
            static List<Student> DeleteStudent(List<Student> studentList, string name)
            {
                bool found = false;
                int len = studentList.Count;
                for (int i = 0; i < len; i++)
                {
                    if (studentList[i].Name == name)
                    {
                        found = true;
                        studentList.RemoveAt(i);
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        Console.WriteLine("Student deleted successfully!");
                        Console.ResetColor();
                        break;
                    }
                }
                if (!found)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("Student not found!");
                    Console.ResetColor();
                }
                return studentList;
            }
        }
    }
}
