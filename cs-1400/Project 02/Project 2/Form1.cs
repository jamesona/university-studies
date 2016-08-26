// Author: Jameson Aranda
// Assignment: Project 2
// Instructor: Timothy Stanley
// Class: CS 1400-004
// Date Written: 1/31/16
// Description: Pirate gold calculator project

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

namespace Project_2
{
    public partial class Form1 : Form
    {
        const int CELEBRATION_GOLD = 3;
        const double JACK_CUT = 0.12,
                     MATE_CUT = 0.08;
        const string ABOUT = "CS 1400 Project 2\nJameson Aranda";
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ABOUT);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int piratesCount = int.Parse(textBox1.Text),
                goldCount = int.Parse(textBox2.Text),
                jackCut, mateCut, share, pbf;

            // Subtract celebration gold from pot for each regular crew
            goldCount -= CELEBRATION_GOLD * (piratesCount - 2);

            // Cut for Jack and 1st mate
            jackCut = Convert.ToInt32(Math.Floor(goldCount * JACK_CUT));
            goldCount -= jackCut;
            mateCut = Convert.ToInt32(Math.Floor(goldCount * MATE_CUT));
            goldCount -= mateCut;

            // Divide the remainder evenly
            share = Convert.ToInt32(goldCount / piratesCount);

            // Send remainder to Pirate's Benevolent Fund
            pbf = goldCount % piratesCount;

            // Write ouput
            label7.Text = Convert.ToString(jackCut);
            label8.Text = Convert.ToString(mateCut);
            label9.Text = Convert.ToString(share);
            label10.Text = Convert.ToString(pbf);

        }
    }
}
