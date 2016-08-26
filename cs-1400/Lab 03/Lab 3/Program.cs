// Author: Jameson Aranda
// Assignment: Lab 3
// Instructor: Timothy D Stanley, PhD
// Class: CNS 1400 Section: 004 
// Date Written: 1/13/16
// Description: Source code for a console application demonstrating types int, double, and string

// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

// Question 1: 
// I used an int, because the user will be supplying whole year.

// Question 2:
// using the 'c' formatter for currency, adds a dollar sign to the interpreted value.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_3
{
    class Program
    {
        static void Main(string[] args)
        {
            string userName = "";
            int userAge = 0,
                nextAge = 0;
            double userMoney = 0;

            Console.WriteLine("Hello, my name is HAL");
            Console.WriteLine("What is your name?");
            userName = Console.ReadLine();
            Console.WriteLine($"Nice to meet you {userName}. How old are you?");
            userAge = int.Parse(Console.ReadLine());
            nextAge = userAge + 1;
            Console.WriteLine("How much money do you have?");
            userMoney = double.Parse(Console.ReadLine());
            Console.WriteLine($"Thank you {userName}. On your next birthday you will be {nextAge} years old.");
            Console.WriteLine($"You have {userMoney:c}.");
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();

        }
    }
}
