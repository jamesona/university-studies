// Author: Jameson Aranda
// Assignment: Lab 19
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: Mar 8, 2016
// Description: A command line dice simulation program

// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19
{
    class Program
    {
        const int NUMBER_OF_SIDES = 6;
        static void Main(string[] args)
        {
            PromptUser();
        }
        
        // ask if the user would like to roll the dice
        static void PromptUser()
        {
            Console.WriteLine("Would you like to roll the dice? (y/n)");
            char ans = Console.ReadKey().KeyChar;
            switch (ans) {
                case 'y':
                case 'Y':
                    Console.WriteLine("You said yes");
                    RollDice();
                    break;
                case 'n':
                case 'N':
                    Console.WriteLine("\nPress any key to exit. Goodbye.");
                    Console.ReadKey();
                    break;
                default:
                    Console.WriteLine("\nInvalid response. Prease respond with y/n.");
                    PromptUser();
                    break;
            }
            
        }

        // get two random dice values and output them
        static void RollDice()
        {
            Random random = new Random();
            int die1 = random.Next(1, NUMBER_OF_SIDES + 1), die2 = random.Next(1, NUMBER_OF_SIDES + 1);
            if (die1 == die2 && die1 == 1)
            {
                Console.WriteLine($"You rolled snake eyes!"); 
            }
            else if (die1 == die2 && die1 == NUMBER_OF_SIDES)
            {
                Console.WriteLine($"You rolled boxcars!");
            }
            else
            {
                Console.WriteLine($"You rolled {die1} and {die2}.");
            }
            PromptUser();
        }

    }

}
