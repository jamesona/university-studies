// Author: Jameson Aranda
// Assignment: Project 10
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: 4/10/16
// Description: sorted bowling scores

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_10
{
    class Program
    {
        const int ARRAY_SIZE = 10;
        static void Main(string[] args)
        {
            String[] names = new String[ARRAY_SIZE];
            int[] scores = new int[ARRAY_SIZE];
            string input = "initial";
            int player = 0, players, highScore, lowScore;
            double averageScore = 0;

            while (input != "")
            {
                int score;
                string name;
                Console.WriteLine("Enter player name and score:");
                input = Console.ReadLine();
                string[] values = input.Split(' ');

                if (values.Length == 2 && int.TryParse(values[1], out score))
                {
                    name = values[0];
                    score = int.Parse(values[1]);
                }
                else if (values.Length == 3 && int.TryParse(values[2], out score))
                {
                    name = values[0] + ' ' + values[1];
                    score = int.Parse(values[2]);
                }
                else if (input == "")
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Invalid input.");
                    continue;
                }
                names[player] = name;
                scores[player] = score;
                player++;
            }
            players = player;

            Sort(scores, names);

            for (var i = 0; i < players; i++)
            {
                averageScore += scores[i];
                Console.WriteLine(names[i].PadRight(10) + scores[i].ToString().PadLeft(3));
            }
            
            averageScore = averageScore / players;
            highScore = scores[0];
            lowScore = scores[players - 1];
            Console.WriteLine($"\n   High score: {highScore}");
            Console.WriteLine($"    Low score: {lowScore}");
            Console.WriteLine($"Average score: {averageScore}");
            Console.WriteLine("\nPress any key to exit.\n");
            Console.ReadKey();
        }
        static void Sort(int[] scores, string[] players)
        {
            for (int j = 0; j < scores.Length - 1; j++)  // index for outer loop is j
            {
                for (int i = 0; i < scores.Length - 1; i++)  // index for inner loop is i
                {
                    if (scores[i] < scores[i + 1])
                    {
                        SwapI(ref scores[i], ref scores[i + 1]);
                        SwapS(ref players[i], ref players[i + 1]);
                    }
                }
            }
        }
        static void SwapI(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        static void SwapS(ref string a, ref string b)
        {
            string temp = a;
            a = b;
            b = temp;
        }
    }
}
