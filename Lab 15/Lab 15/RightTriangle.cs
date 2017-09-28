using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_15
{
    class RightTriangle
    {
        private const int RIGHT_ANGLE = 90, TWO = 2;
        private const double RADIANS_FACTOR = Math.PI / 180;
        private double sideOne = 0.0, sideTwo = 0.0;

        // Purpose: Convert degrees to radians
        // Parameters: double degrees
        // Returns: double radians
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double toRadians(double degrees)
        {
            double radians = degrees * RADIANS_FACTOR;
            return radians;
        }

        // Purpose: Convert radians to degrees
        // Parameters: double radians
        // Returns: double degrees
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double toDegrees(double radians)
        {
            double degrees = radians / RADIANS_FACTOR;
            return degrees;
        }

        // Purpose: Calculate hypotenuse of a triangle given
        // the length of two sides and the opposite angle
        // Parameters: double side_a, double side_b, [optional] double angle_C
        // Returns: double side_c
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double calculateHypt(double a, double b, double C = 90.0)
        {
            // convert angle to radians
            C = toRadians(C);
            // use law of cosines to solve for side c
            double c = Math.Sqrt(a * a + b * b - TWO * a * b * Math.Cos(C));
            return c;
        }

        // Purpose: Calculate an angle opposite two sides of a triangle
        // given the length of the third side
        // Parameters: double side_a, double side_b, double side_c
        // Returns: double side_c
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        private double calculateAngle(double a, double b, double c)
        {
            // use law of cosines to solve for angle C
            double C = Math.Acos((c * c - (a * a + b * b)) / (TWO * a * b * -1));
            // convert radians to degrees
            C = toDegrees(C);
            return C;
        }

        // Purpose: set internal value of a side length
        // Parameters: double length, int side
        // Returns: none
        // Pre-conditions: none
        // Post-conditions: internal value set for sideOne or sideTwo
        // -----------------------------------------------------------------
        public void setSide(double length, int side)
        {
           if (side == 0)
            {
                sideOne = length;
            }
           else if (side == 1)
            {
                sideTwo = length;
            }
        }

        // Purpose: get internal value of a side length
        // Parameters: int side
        // Returns: double length
        // Pre-conditions: none
        // Post-conditions: none
        // -----------------------------------------------------------------
        public double getSide(int side)
        {
            if (side == 0)
            {
                return sideOne;
            }
            else if (side == 1)
            {
                return sideTwo;
            }
            else
            {
                return 0;
            }
        }

        // Purpose: get the hypotenuse of the triangle
        // Parameters: none
        // Returns: double hypt
        // Pre-conditions: internal values set for sideOne AND sideTwo
        // Post-conditions: none
        // -----------------------------------------------------------------
        public double getHypt()
        {
            if (sideOne > 0 && sideTwo > 0)
            {
                double hypt = calculateHypt(sideOne, sideTwo);
                return hypt;
            }
            else
            {
                return 0.0;
            }
        }

        // Purpose: get one of the angles of the triangle
        // Parameters: int angle
        // Returns: double degrees
        // Pre-conditions: internal values set for sideOne AND sideTwo
        // Post-conditions: none
        // -----------------------------------------------------------------
        public double getAngle(int angle)
        {
            // get the hypotenuse first
            double angleOut, hypt = calculateHypt(sideOne, sideTwo);

            if (angle == 0)
            {
                angleOut = calculateAngle(sideOne, hypt, sideTwo);
            } else if (angle == 1)
            {
                angleOut = calculateAngle(sideTwo, hypt, sideTwo);
            }
            else
            {
                return 0;
            }
            return angleOut;
        }
    }
}
