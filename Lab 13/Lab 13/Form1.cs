// Author: Jameson Aranda
// Assignment: Lab 13
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 004
// Date Written: 2/18/16
// Description: A class that defines a token machine

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

namespace Lab_13
{
    public partial class Form : System.Windows.Forms.Form
    {
        // constant for about message text
        private const string ABOUT = "Lab 13\nJameson Aranda";

        // class reference to a token machine
        private TokenMachine tm;

        public Form()
        {
            InitializeComponent();

            // create new token machine
            tm = new TokenMachine();
            tm.Reset();
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

        // handle click on "Get Token" button
        private void getButton_Click(object sender, EventArgs e)
        {
            tm.GetToken();
            tokens.Text = Convert.ToString(tm.CountTokens());
            quarters.Text = Convert.ToString(tm.CountQuarters());
        }

        // handle click on "Reset" button
        private void resetButton_Click(object sender, EventArgs e)
        {
            tm.Reset();
            tokens.Text = Convert.ToString(tm.CountTokens());
            quarters.Text = Convert.ToString(tm.CountQuarters());
        }
    }
}
