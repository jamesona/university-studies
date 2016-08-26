// Author: Jameson Aranda
// Assignment: Project 3
// Instructor: Timothy Stanley
// Class: CS 1400-004
// Date Written: 2/6/16
// Description: Good Guys Delivery Service
// Delivery time calculator

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

namespace Project_3
{
    public partial class Form1 : Form
    {
        const string ABOUT = "CS 1400 Project 3\nJameson Aranda";

        // used to separate hours from minutes in military time
        const int DECIMAL_SHIFT = 100;
        
        // used to add 25% to the estimated time
        const double DELAY_FACTOR = 1.25;

        const int MINUTES_PER_HOUR = 60;

        public Form1()
        {
            InitializeComponent();
        }

        // Purpose: Get hours from military time
        // Parameters: integer for whole time
        // Returns: integer for hours
        // Pre-conditions: none
        // Post-conditions: none
        private int getHours(int time)
        { 
            double shiftResult;
            int hours;

            /* Separate hours by shifing the decimal
               two spaces to the left, and truncating   */
            shiftResult = time / DECIMAL_SHIFT;
            hours = Convert.ToInt32(Math.Truncate(shiftResult));
            return hours;
        }

        // Purpose: Get minutes from military time
        // Parameters: integer for whole time
        // Returns: integer for minutes
        // Pre-conditions: none
        // Post-conditions: none
        private int getMinutes(int time)
        {
            double shiftResult;
            int hours, minutes;

            /* Separate minutes by shifing the decimal
               two spaces to the left, subtracting the
               integral portion, then unshifting the
               difference                               */
            shiftResult = time / DECIMAL_SHIFT;
            hours = Convert.ToInt32(Math.Truncate(shiftResult));
            minutes = time - hours * DECIMAL_SHIFT;            
            return minutes;
        }

        // Purpose: Convert hours to minutes
        // Parameters: integer for number of hours
        // Returns: integer for minutes
        // Pre-conditions: none
        // Post-conditions: none
        private int hoursToMinutes(int hours)
        {
            int minutes = hours * MINUTES_PER_HOUR;
            return minutes;
        }

        // Purpose: Convert minutes to hours
        // Parameters: integer for number of minutes
        // Returns: integer for hours
        // Pre-conditions: none
        // Post-conditions: none
        private int minutesToHours(int minutes)
        {
            int hours = minutes / MINUTES_PER_HOUR;
            return hours;
        }

        // Purpose: Get end time from start time and elapsed minutes
        // Parameters: integer for military time, integer for number of minutes
        // Returns: integer for end time
        // Pre-conditions: none
        // Post-conditions: none
        private int getEndTime(int time, int elapsed)
        {
            int endTime, 
                hours = getHours(time), 
                minutes = getMinutes(time);

            // increment values
            hours += minutesToHours(elapsed);
            minutes += elapsed % MINUTES_PER_HOUR;

            // resolve minutes values greater than 59
            hours += minutesToHours(minutes);
            minutes -= minutesToHours(minutes) * MINUTES_PER_HOUR;


            // shift decimal on hours
            hours = hours * DECIMAL_SHIFT;

            // sum time
            endTime = hours + minutes;

            return endTime;
        }


        // Handle click on "Exit" menu option
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            // Close program
            Application.Exit();
        }

        // Handle click on "About" menu option
        private void menuToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Show "About" dialogue
            MessageBox.Show(ABOUT);
        }

        // Handle click on main button
        private void button1_Click(object sender, EventArgs e)
        {
            // Declare variables
            int startTime, startHour, startMin, startTotal,
                endTime, endHour, endMin, endTotal,
                timeTaken, estimatedTimeOfArrival;

            // Parse inputs
            int.TryParse(textBox1.Text, out startTime);
            int.TryParse(textBox2.Text, out endTime);

            // Parse start time
            startHour = getHours(startTime);
            startMin = getMinutes(startTime);
            startTotal = hoursToMinutes(startHour) + startMin;

            // Parse end time
            endHour = getHours(endTime);
            endMin = getMinutes(endTime);
            endTotal = hoursToMinutes(endHour) + endMin;

            // Used to verify correct parsing of time
            //MessageBox.Show($"START: {startHour} hours, {startMin} minutes.");
            //MessageBox.Show($"END: {endHour} hours, {endMin} minutes.");
            //MessageBox.Show($"START: {startTotal}; END: {endTotal}");

            // Calculate time taken in minutes
            timeTaken = endTotal - startTotal;

            // verify difference
            //MessageBox.Show($"original time taken: {timeTaken}");

            // Apply delay factor
            timeTaken = Convert.ToInt32(timeTaken * DELAY_FACTOR);

            // verify delay
            //MessageBox.Show($"adjusted time taken: {timeTaken}");

            // Calculate new end time
            estimatedTimeOfArrival = getEndTime(startTime, timeTaken);

            // Write result to form
            textBox3.Text = estimatedTimeOfArrival.ToString("D4");
        }
    }
}
