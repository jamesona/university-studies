// File Prologue
// Name: Jameson Aranda
// CS 1400
// Project: Lab 16
// Date: 3/1/16
//
// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

using System;

class Program
{
    static void Main()
    {
        // declare some constants for saturday and sunday
        const string SAT = "Saturday";
        const string SUN = "Sunday";
        const int FREEZING = 32;

        // declare a variable to hold user's input
        string today;
        int temp;

        // prompt the user to enter a day and get the input
        Console.Write("Please enter a day of the week, e.g. Tuesday: ");
        today = Console.ReadLine();

        // see if it is a work day
        if (today != SUN && today != SAT)
        {
            // prompt user for temperature outside
            Console.Write("What temperature will it be today? ");
            Int32.TryParse(Console.ReadLine(), out temp);

            if (temp >= FREEZING)
            {
                Console.WriteLine("Go to work.");
            }
            else
            {
                Console.WriteLine("Go to work, and dress warmly");
            }
            
        }
        else
        {
            // its not a workday, display the weekend message
            Console.WriteLine("Ahh... the weekend. No work!");
        }

        Console.ReadLine();
    }//End Main()
}//End class Program