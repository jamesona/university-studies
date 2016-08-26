// Author: Jameson Aranda
// Assignment: lab 17
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 045
// Date Written: 3/3/16
// Description: Lab 17 (shipping selector)
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

namespace Lab_17
{
    public partial class Form1 : Form
    {
        const string MESSAGE = "You selected ",
                     ABOUT = "Jameson Aranda\nLab 17";
        public Form1()
        {
            InitializeComponent();
        }

        // handle shipping selection
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            MessageBox.Show(MESSAGE + comboBox1.Text);
        }

        // handle exit menu click
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        // handle about menu click
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ABOUT);
        }
    }
}
