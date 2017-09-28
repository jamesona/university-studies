// Author: Jameson Aranda
// Assignment: Lab 15
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: Feb 21, 2016
// Description: A triangle calculator utilizing a separate triangle class

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_15
{
    public partial class Form1 : Form
    {
        const string ABOUT = "Triangle Calculator\nJameson Aranda";
        // class level reference to RightTriangle class
        private RightTriangle tri;

        public Form1()
        {
            InitializeComponent();

            // create a new right triangle
            tri = new RightTriangle();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void tryCalculate()
        {
            double hypt, valAngleOne, valAngleTwo;
            if (tri.getSide(0) > 0 && tri.getSide(1) > 0)
            {
                hypt = tri.getHypt();
                valAngleOne = tri.getAngle(0);
                valAngleTwo = tri.getAngle(1);
                
                if (hypt > 0 && valAngleOne > 0 && valAngleTwo > 0)
                {
                    hypotenuse.Text = Convert.ToString(Math.Round(hypt, 2));
                    angleOne.Text = Convert.ToString(Math.Round(valAngleOne, 2));
                    angleTwo.Text = Convert.ToString(Math.Round(valAngleTwo, 2));
                }
            }
        }

        // Handle Exit menu click
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        // Handle About menu click
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ABOUT);
        }

        // Handle value change of sideOne
        private void sideOne_TextChanged(object sender, EventArgs e)
        {
            double length;
            double.TryParse(sideOne.Text, out length);
            if (length > 0)
            {
                tri.setSide(length, 0);
                tryCalculate();
            }
        }

        // Handle value change of sideTwo
        private void sideTwo_TextChanged(object sender, EventArgs e)
        {
            double length;
            double.TryParse(sideTwo.Text, out length);
            if (length > 0)
            {
                tri.setSide(length, 1);
                tryCalculate();
            }
        }
    }
}
