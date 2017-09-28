// Author: Jameson Aranda
// Assignment: Lab 22
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: 3/29/16
// Description: a console application to sum an array of user inputs

// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_22
{
    class Program
    {
        const int ARRAY_SIZE = 10;
        static void Main(string[] args)
        {
            // initialize empty array for user input
            int[] userInputs = new int[ARRAY_SIZE];
            // prompt user to fill each empty index
            for (int i = 0; i < ARRAY_SIZE; i++)
            {
                int input;
                Console.WriteLine($"Enter a value for index {i}:");
                int.TryParse(Console.ReadLine(), out input);
                userInputs[i] = input;   
            }
            // send completed array to the SumArray method
            int total = SumArray(userInputs);
            // output the total
            Console.WriteLine($"The total is {total}. \nPress any key to exit.");
            // wait for user input to close
            Console.ReadKey();
        }

        // Purpose: returns an integer sum of an integer array
        // Parameters: int[] numbers
        // Returns: int number
        // Pre-conditions: none
        // Post-conditions: none1
        // -----------------------------------------------------------------
        static int SumArray(int[] numbers)
        {
            int sum = 0;
            foreach(int number in numbers)
            {
                sum += number;
            }
            return sum;
        }
    }
}
