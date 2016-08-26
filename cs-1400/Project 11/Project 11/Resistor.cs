using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_11
{
    // this class models a resistor
    // it contains information about the expected resistance, the actual 
    // voltage drop, and calculated power dissipation
    class Resistor
    {
        int resistance;
        double voltage, rating;

        public Resistor(int res = 0, double power = 0, double volts = 0)
        {
            resistance = res;
            rating = power;
            voltage = volts;
        }

        public int Resistance {
            get { return resistance; }
            private set { }
        }

        public double Voltage
        {
            get { return voltage;  }
            set { voltage = value; }
        }

        public double Rating
        {
            get { return rating; }
            set { rating = value; }
        }

        public double Dissipation
        {
            get { return voltage * voltage / resistance; }
            private set { }
        }
    }
}
