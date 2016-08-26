// Author: Jameson Aranda
// Assignment: Lab 21
// Instructor: Dr. deBry
// Class: CS-1400 Section: 004
// Date Written: Mar 9, 2016
// Description: Change calculator

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_21
{
    class Program
    {
        // some  class level constants
        const int HALVES = 50;
        const int QUARTERS = 25;
        const int DIMES = 10;
        const int NICKELS = 5;
        const int PENNIES = 1;

        static void Main()
        {
            int money;  // the value we want to count change for

            Console.WriteLine("I will make change for you.");
            Console.Write("Enter in an amount between 1 and 99: ");
            money = int.Parse(Console.ReadLine());

            Console.WriteLine("For {0} you get:", money);

            Console.WriteLine("{0} halves", ComputeChange(ref money, HALVES));
            Console.WriteLine("{0} quarters", ComputeChange(ref money, QUARTERS));
            Console.WriteLine("{0} dimes", ComputeChange(ref money, DIMES));
            Console.WriteLine("{0} nickels", ComputeChange(ref money, NICKELS));
            Console.WriteLine("{0} pennies\n", ComputeChange(ref money, PENNIES));
            Console.ReadLine();
        }

        // I declare that the following source code was written solely by me.
        // I understand that copying any source code, in whole or in part, 
        // constitutes cheating, and that I will receive a zero on this project
        // if I am found in violation of this policy.


        // Purpose: determines the most whole coins a denomination can be 
        // broken into
        // Parameters: int for total to split, int for size of denomniation
        // Returns: int for the number of coins that can be produced
        // Pre-conditions: a reference variable must exist for current change
        // Post-conditions: the reference variable will be decremented by the
        // total value of the coins produced
        // -----------------------------------------------------------------
        static int ComputeChange(ref int changeValue, int coinValue)
        {
            int newCoins = changeValue / coinValue;
            changeValue -= newCoins * coinValue;
            return newCoins;
        }
    }
}
