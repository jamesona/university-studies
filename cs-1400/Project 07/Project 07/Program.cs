// Author: Jameson Aranda
// Assignment: Project 07
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: 3/12/16
// Description: rabbit simulator

// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_07
{
    class Program
    {
        static void Main(string[] args)
        {
            // print student info
            Console.WriteLine("Jameson Aranda, Project 07: Rabbits, Rabbits, Rabbits");

            // set a const for the number of available cages
            const int CAGES = 500;

            // set a dictionary to hold information
            Dictionary<string, int> data = new Dictionary<string, int>
            {
                { "Month", 0 },
                { "Adults", 0 },
                { "Babies", 0 },
                { "Total", 0 }
            };

            // initialize a list object to count our rabbits
            List<Rabbit> rabbits = new List<Rabbit>();

            // add the first rabbit
            rabbits.Add(new Rabbit(true));

            // print table headers
            Console.WriteLine(string.Join(" ", data.Keys));

            // begin loop
            do
            {
                // it's a new month, increment the counter
                data["Month"]++;

                // reset counters for rabbits
                data["Adults"] = 0;
                data["Babies"] = 0;

                // iterate over all rabbits
                foreach (Rabbit thisRabbit in rabbits.ToList<Rabbit>())
                {
                    // if this rabbit is an adult
                    if (thisRabbit.canBreed)
                    {
                        // increment counter
                        data["Adults"]++;

                        // it makes a new baby
                        rabbits.Add(new Rabbit());

                        // increment counter
                        data["Babies"]++;

                    }
                    else
                    {
                        // it grows into an adult this month
                        thisRabbit.canBreed = true;

                        // increment counter
                        data["Adults"]++;
                    }
                }
                data["Total"] = data["Adults"] + data["Babies"];

                // For each colum in the data
                foreach (var column in data.Keys)
                {
                    // print the value, nicely padded
                    Console.Write(
                        $"{data[column]}".PadRight(column.Count<char>() + 1)
                        );
                }
                // end the line
                Console.Write('\n');

            }
            // stop the loop when we have as many rabbits as cages
            while (rabbits.Count < CAGES);

            // wait for user before exiting
            Console.WriteLine($"Simulation complete. You will run out of cages in month {data["Month"]}.");
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }

    class Rabbit
    {
        public bool canBreed;
        public Rabbit(bool adult = false)
        {
            if (adult) canBreed = true;
        }
    }
}
