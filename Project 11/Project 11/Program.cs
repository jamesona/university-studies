// Author: Jameson Aranda
// Assignment: project 11
// Instructor: Dr. Debry
// Class: CNS 1400 Section: 004
// Date Written: 4/16/16
// Description: A program to calculate pass/fail status of resistor quality control data

// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_11
{
    class Program
    {
        static void Main(string[] args)
        {
            const int MAX_BATCH_SIZE = 50, COLUMN_WIDTH = 12;

            // figure out where the data file is at, and reserve space for the filename
            string path = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), file;

            // initialize counter
            int index = 0;

            // reserve names for resistance and power rating
            int resistance = 0;
            double rating = 0;

            // initialize an array to hold voltages
            int[] voltages = new int[MAX_BATCH_SIZE];

            // prompt for the file name
            Console.WriteLine("--Resistor Batch Test Report--\nTest Data must be in your Documents folder.");
            Console.Write("Please enter your file name: ");
            file = Console.ReadLine();

            foreach ( string line in File.ReadLines(@path + "\\" + file) )
            {
                if (index == 0)
                {
                    string[] values = line.Split(' ');
                    int.TryParse(values[0], out resistance);
                    double.TryParse(values[1], out rating);
                }
                else
                {
                    // read the value into the array, using the current line index
                    // minus 1 to adjust for the initial configuration line
                    int.TryParse(line, out voltages[index - 1]);
                }
                index++;
            }

            Console.Write("\n\n#".PadRight(COLUMN_WIDTH));
            Console.Write("Dissipation".PadRight(COLUMN_WIDTH));
            Console.WriteLine("Test".PadRight(COLUMN_WIDTH));

            for (int i = 0; i < index - 1; i++)
            {
                Resistor resistor = new Resistor(resistance, rating, voltages[i]);
                string test = resistor.Dissipation < rating ? "FAIL" : "PASS";
                Console.Write($"{i+1}".PadRight(COLUMN_WIDTH));
                Console.Write($"{resistor.Dissipation:0.00}".PadRight(COLUMN_WIDTH));
                Console.WriteLine(test.PadRight(COLUMN_WIDTH));
            }

            Console.WriteLine("\nPress any key to exit.");
            Console.ReadKey();
        }
    }
}
