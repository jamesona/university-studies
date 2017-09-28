// Author: Jameson Aranda
// Assignment: Project 04
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: 2/13/16
// Description: Cosine triangle calculator

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

namespace Project_04
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        const double RADIANS_FACTOR = Math.PI / 180;
        const string ABOUT = "Triangle Calculator\nJameson Aranda";
        const int TWO = 2;

        // Purpose: Convert degrees to radians
        // Parameters: double degrees
        // Returns: double radians
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double toRadians(double degrees)
        {
            double radians = degrees * RADIANS_FACTOR;
            return radians;
        }

        // Purpose: Convert radians to degrees
        // Parameters: double radians
        // Returns: double degrees
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double toDegrees(double radians)
        {
            double degrees = radians / RADIANS_FACTOR;
            return degrees;
        }

        // Purpose: Calculate hypotenuse of a triangle given
        // the length of two sides and the opposite angle
        // Parameters: double side_a, double side_b, [optional] double angle_C
        // Returns: double side_c
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double calculateHypt(double a, double b, double C = 90.0)
        {
            // convert angle to radians
            C = toRadians(C);
            // use law of cosines to solve for side c
            double c = Math.Sqrt(a * a +b * b - TWO * a * b * Math.Cos(C));
            return c;
        }

        // Purpose: Calculate an angle opposite two sides of a triangle
        // given the length of the third side
        // Parameters: double side_a, double side_b, double side_c
        // Returns: double side_c
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double calculateAngle(double a, double b, double c)
        {
            // use law of cosines to solve for angle C
            double C = Math.Acos((c * c - (a * a + b * b)) / (TWO * a * b * -1));
            // convert radians to degrees
            C = toDegrees(C);
            return C;
        }

        // Handle Calcluate button click
        private void button1_Click(object sender, EventArgs e)
        {   // Setup names
            double side_a, side_b, side_c, angle_A, angle_B, angle_C;

            // read values
            double.TryParse(textBox1.Text, out side_a);
            double.TryParse(textBox2.Text, out side_b);
            double.TryParse(textBox3.Text, out angle_C);

            // call calculateHypt method to get side_c
            side_c = calculateHypt(side_a, side_b, angle_C);

            // call calculateAngle method to get angles A and B
            angle_A = calculateAngle(side_b, side_c, side_a);
            angle_B = calculateAngle(side_a, side_c, side_b);

            textBox4.Text = Convert.ToString(Math.Round(side_c, 2));
            textBox5.Text = Convert.ToString(Math.Round(angle_A, 2));
            textBox6.Text = Convert.ToString(Math.Round(angle_B, 2));
        }

        // Handle Clear button click
        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        // Handle exit menu click
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {   // Close application
            Application.Exit();
        }

        // Handle about menu click
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {   // Create modal showing ABOUT text
            MessageBox.Show(ABOUT);
        }
    }
}
