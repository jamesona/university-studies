// Author: Jameson Aranda
// Assignment: Project #6
// Instructor: Dr. Stanley
// Class: CNS 1400 Section: 045
// Date Written: Mar 5, 2016
// Description: Shipping calculator form, implementing
// a custom shipping calculator class.

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

namespace Project_06
{
    public partial class Form1 : Form
    {
        // set the about message
        const string ABOUT = "Jameson Aranda\nShipping Calculator";

        // reserve the calculator class
        private ShippingCalculator calc;

        public Form1()
        {
            InitializeComponent();

            // initialize calculator class
            calc = new ShippingCalculator();

            // load shipping methods from class, and initialize form
            var shippingMethods = calc.getMethods();
            // iterate over shipping matrix
            foreach (var shippingMethod in shippingMethods)
            {
                // for each shipping method, add a new item to
                // the shipping combobox dropdown
                shippingSelect.Items.Add(shippingMethod);
            }
        }

        // handle exit menu click
        private void exitMenuItem_Click(object sender, EventArgs e)
        {
            // close application
            Application.Exit();
        }

        // handle about menu click
        private void aboutMenuItem_Click(object sender, EventArgs e)
        {
            // show about message
            MessageBox.Show(ABOUT);
        }

        // handle calculate button click
        private void calculateButton_Click(object sender, EventArgs e)
        {
            // use class method to get shipping total
            double total = calc.getShippingPrice(
                // get seleced shipping mode
                shippingSelect.Text,
                // get selected category
                categorySelect.Text,
                // get multiplier
                Convert.ToDouble(countBox.Text),
                // check for surcharge
                surchargeBox.Checked
                );
            // output shipping price
            shippingPrice.Text = $"{total:C}";
        }

        // handle clear button click
        private void clearButton_Click(object sender, EventArgs e)
        {   
            // empty shipping combobox
            shippingSelect.Text = null;
            // empty category combobox
            categorySelect.Text = null;
            // empty count textbox
            countBox.Text = null;
            // reset surcharge
            surchargeBox.Checked = false;
            // reset shipping price text
            shippingPrice.Text = $"{0:C}";
        }
    }
}
