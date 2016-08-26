// Author: Jameson Aranda
// Assignment: Project 05
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 045
// Date Written: 2/28/16
// Description: Sales Invoice application

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

namespace Project_05
{
    public partial class Form1 : Form
    {
        const string ABOUT = "Invoice Calcualtor\nJameson Aranda 2016";
        const double STATE_TAX = 0.0745, LOCAL_TAX = 0.025;

        private SalesInvoice transaction;

        public Form1()
        {
            InitializeComponent();

            transaction = new SalesInvoice();
        }

        // get value from  "Count" box
        private double readCount()
        {
            double count = 0;
            double.TryParse(textBox1.Text, out count);
            return count;
        }

        // get value from "Price" box
        private double readPrice()
        {
            double price = 0;
            double.TryParse(textBox2.Text, out price);
            return price;
        }

        // handle click on "Purchase"
        private void button1_Click(object sender, EventArgs e)
        {
            double price = readPrice();
            double count = readCount();

            transaction.setPrice(price);
            transaction.setCount(count);
            transaction.setStateTax(STATE_TAX);
            transaction.setLocalTax(LOCAL_TAX);

            label3.Text = transaction.getInvoice();
        }

        // handle click on "Clear"
        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = null;
            textBox2.Text = null;
            label3.Text = null;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ABOUT);
        }
    }
}
