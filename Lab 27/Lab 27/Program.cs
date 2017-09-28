// Author: Jameson Aranda
// Assignment: Lab 27
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004 
// Date Written: 4/19/16
// Description: Box loader -- read class instance specifications from a file

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_27
{
    class Program
    {
        static void Main(string[] args)
        {
            const ARR_SIZE = 10;
            string line = "";
            int height, width, depth;
            Box[] boxes = new Box[ARR_SIZE];


        }
    }

    class Box
    {
        private int height;
        private int width;
        private int depth;
        public Box(int p1, int p2, int p3)
        {
            height = p1;
            width = p2;
            depth = p3;
        }
        public int GetVolume()
        {
            return (height * width * depth);
        }
    }
}
