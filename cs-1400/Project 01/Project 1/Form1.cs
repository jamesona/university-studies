// Author: Jameson Aranda
// Assignment: Project 1
// Instructor: Timothy D Stanley, PhD
// Class: CNS 1400 Section: 004 
// Date Written: 1/23/16
// Description: Source code for a console application demonstrating types int, double, and string

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

namespace Project_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        const double POOR_PERCENT = 0.10, GOOD_PERCENT = 0.15, EXCELLENT_PERCENT = 0.20;
        const string ABOUT = "Tip Calculator\nVersion 1.1\nJameson Aranda";
        double cost = 0, poor = 0, good = 0, excellent = 0;

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            Double.TryParse(textBox1.Text, out cost);
            poor = cost * POOR_PERCENT;
            good = cost * GOOD_PERCENT;
            excellent = cost * EXCELLENT_PERCENT;

            textBox2.Text = Convert.ToString(string.Format("{0:C}", poor));
            textBox3.Text = Convert.ToString(string.Format("{0:C}", good));
            textBox4.Text = Convert.ToString(string.Format("{0:C}", excellent));
            
        }

        public void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        public void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ABOUT);
        }


    }
}
