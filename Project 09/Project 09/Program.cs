using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_09
{
    class Program
    {
        const int ARRAY_SIZE = 500;
        static void Main(string[] args)
        {
            String[] names = new String[ARRAY_SIZE];
            int[] scores = new int[ARRAY_SIZE];
            string input = "initial";
            int player = 0, players, highScore, lowScore, averageScore = 0;

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
            player = ARRAY_SIZE - player;
            Array.Sort(scores, names);
            scores.Reverse();
            names.Reverse();
            lowScore = scores[player];

            for (int i=0;player < ARRAY_SIZE;player++)
            {
                averageScore += scores[player];
                Console.WriteLine(names[player].PadLeft(15)+" scored "+scores[player].ToString().PadLeft(3));
            }

            highScore = scores[ARRAY_SIZE - 1];
            averageScore = averageScore / players;

            Console.WriteLine($"\n   High score: {highScore}");
            Console.WriteLine($"    Low score: {lowScore}");
            Console.WriteLine($"Average score: {averageScore}");
            Console.WriteLine("\nPress any key to exit.\n");
            Console.ReadKey();
        }
    }
}
