using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_05
{
    class SalesInvoice
    {
        // define private fields
        private double price, count, stateTax, localTax;

        public void setPrice(double priceIn = 0)
        {
            price = priceIn;
        }

        public void setCount(double countIn = 0)
        {
            count = countIn;
        }

        public void setStateTax(double taxIn = 0.0)
        {
            stateTax = taxIn;
        }

        public void setLocalTax(double taxIn = 0.0)
        {
            localTax = taxIn;
        }

        public string getInvoice()
        {
            string invoice = "===== Sales Invoice =====";
            string quantity = "Quantity:", unitPrice = "Unit Price:",
                   divider = new String('-', invoice.Length),
                   stateTaxString = "", localTaxString = "", totalString;
            
            // create count line, or error
            if (count <= 0)
            {
                return "ERR: Invalid Count";
            }
            else
            {
                string countString = Convert.ToString(count);
                quantity += countString.PadLeft(invoice.Length - quantity.Length) + "\n";
            }
            // create price line, or error
            if (price <= 0)
            {
                return "ERR: Invalid Price"; 
            }
            else
            {
                string priceString = $"{price:C}";
                unitPrice += priceString.PadLeft(invoice.Length - unitPrice.Length) + "\n";
            }

            // calculate net price
            double net = count * price;
            string netPrice = $"{net:C}";
            string netString = "Net Total:";
            netString += netPrice.PadLeft(invoice.Length - netString.Length) + "\n";

            // if state tax exists, calculate it
            if (stateTax > 0)
            {
                stateTaxString = "State Tax:";
                string stateTaxValue = $"{stateTax * net:C}";
                stateTaxString += stateTaxValue.PadLeft(invoice.Length - stateTaxString.Length) + "\n";
            }

            // if local tax exists, calculte it
            if (localTax > 0)
            {
                localTaxString = "State Tax:";
                string localTaxValue = $"{localTax * net:C}";
                localTaxString += localTaxValue.PadLeft(invoice.Length - localTaxString.Length) + "\n";
            }

            // calculate total
            string total = $"{net + net * stateTax + net * localTax:C}";
            totalString = "Total:";
            totalString += total.PadLeft(invoice.Length - totalString.Length);

            // compile invoice
            invoice += "\n\n" + quantity + unitPrice + divider + "\n";
            invoice += netString + stateTaxString + localTaxString + totalString;
            return invoice;
        }
    }
}
