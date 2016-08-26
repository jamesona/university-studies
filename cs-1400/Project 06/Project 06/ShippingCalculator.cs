using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_06
{
    class ShippingCalculator
    {
        // define constants
        const double 
            STANDARD_PER_ITEM = 3.00, 
            STANDARD_PER_POUND = 1.45,         
            STANDARD_SURCHARGE = 2.50,
            EXPRESS_PER_ITEM = 4.00,
            EXPRESS_PER_POUND = 2.50,
            EXPRESS_SURCHARGE = 5.00,
            ONE_DAY_PER_ITEM = 5.50,
            ONE_DAY_PER_POUND = 3.00,
            ONE_DAY_SURCHARGE = 8.00;

        // initialize dictionary of shipping rate data
        private Dictionary<string, Dictionary<string, double>> shipping = new Dictionary<string, Dictionary<string, double>>
        {
            { "Standard", new Dictionary<string, double>
                {
                    { "Per Item",  STANDARD_PER_ITEM},
                    { "Per Pound",  STANDARD_PER_POUND},
                    { "surcharge",  STANDARD_SURCHARGE}
                }
            },
            { "Express", new Dictionary<string, double>
                {
                    { "Per Item", EXPRESS_PER_ITEM },
                    { "Per Pound", EXPRESS_PER_POUND },
                    { "surcharge", EXPRESS_SURCHARGE }
                }
            },
            { "Same Day", new Dictionary<string, double>
                {
                    { "Per Item", ONE_DAY_PER_ITEM },
                    { "Per Pound", ONE_DAY_PER_POUND },
                    { "surcharge", ONE_DAY_SURCHARGE }
                }
            }
        };

        // shipping type getter
        public List<string> getMethods()
        {
            // create a list object for shipping methods
            var methods = new List<string>();
            // iterate over shipping matrix
            foreach (KeyValuePair<string, Dictionary<string, double>> entry in shipping)
            {
                // for each item, add the shipping method text
                // to the shipping method list
                methods.Add(entry.Key);
            }
            // return the list
            return methods;
        }

        // total getter
        public double getShippingPrice(
            string method, string category, double count, bool useSurcharge = false
            )
        {
            // set values
            double surcharge = 0, price = 0;
            try
            {
                price = shipping[method][category];
            }
            catch
            {

            }
            if (useSurcharge)
            {
                surcharge = shipping[method]["surcharge"];
            }
            // calculate and return
            return surcharge + count * price;
        }
    }
}
