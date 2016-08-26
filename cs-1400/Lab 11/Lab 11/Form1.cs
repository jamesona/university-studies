// Author: Jameson Aranda
// Assignment: Lab 11
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: 2/11/16
// Description: Hypotenuse calculator

// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
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

namespace Lab_11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // Purpose: Use the Pythagorean theorem to calculate a hypotenuse
        // Parameters: double side 1, double side 2
        // Returns: a double for hypt
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double calculateHypotenuse(double side1, double side2)
        {
            // Pythagorean theorem: a^2+b^2=c^
            double hypotenuse = Math.Sqrt((side1 * side1) + (side2 * side2));
            return hypotenuse;
        }

        // Purpose: handle calculate button click
        // Parameters: none
        // Returns: none
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private void button1_Click(object sender, EventArgs e)
        {
            double side1 = double.Parse(textBox1.Text),
                   side2 = double.Parse(textBox2.Text),
                   hypotenuse = calculateHypotenuse(side1, side2);

            textBox3.Text = Convert.ToString(hypotenuse);
        }
    }
}
