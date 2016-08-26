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
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_13
{
    // This class models a token machine.
    // It contains fields and methods for storing quarters
    // and tokens, reporting it's contents, and performing
    // transactions.
    class TokenMachine
    {
        // constant for the maximum amount of tokens this machine can hold
        private const int MAX_TOKENS = 100;

        // class fields for token and quarter storage
        private int numTokens = 0,
                    numQuarters = 0;

        // Purpose: This method resets the machine.
        // Parameters: none
        // Returns: none
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        public void Reset()
        {
            numTokens = MAX_TOKENS;
            numQuarters = 0;
        }

        // Purpose: This method performs a transaction
        // Parameters: none
        // Returns: none
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        public void GetToken()
        {
            if (numTokens > 0)
            {
                numTokens--;
                numQuarters++;
            }
        }

        // Purpose: This method returns the number of tokens remaining.
        // Parameters: none
        // Returns: none
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        public int CountTokens()
        {
            return numTokens;
        }

        // Purpose: This method returns the number of quarters held.
        // Parameters: none
        // Returns: none
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        public int CountQuarters()
        {
            return numQuarters;
        }
    }
}
