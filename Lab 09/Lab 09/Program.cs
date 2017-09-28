// Author: Jameson Aranda
// Assignment: Lab 8
// Instructor: Timothy Stanley
// Class: CS 1400-004
// Date Written: 1/31/16
// Description: Farmer John Solution

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_09
{
    class Program
    {
        static void Main(string[] args)
        {
            // prompt user for radius
            Console.WriteLine("Please enter a decimal number (00.00)\nrepresenting the length of your sprinkler arm:");

            // set double radius equal to user input
            double radius = Double.Parse(Console.ReadLine());

            // area of square is equal to (2 * r) * (2 * r) squared
            double areaOfSquare = (2 * radius) * (2 * radius);

            // area of circle is equal to (pi * r * r)
            double areaOfCircle = (Math.PI * radius * radius);

            // unwatered area is equal to squareArea - circleArea
            string unwatered = Convert.ToString(Math.Round(areaOfSquare - areaOfCircle, 2));

            // write solution to console
            Console.WriteLine("Your unwatered area would be " + unwatered + " square units.");
            Console.WriteLine("\n\nPress any key to exit.");

            Console.ReadKey(true);

            // end main
        }
    }
}
