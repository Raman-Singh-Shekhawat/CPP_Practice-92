/*

OOPS 2

107. Code : Polynomial Class: Implement a polynomial class, with the following properties and functions.
Properties :

An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
An integer holding total size of array A.
Functions :
Default constructor
Copy constructor
setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : "x"
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases

*/

class Polynomial
{

public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;

    Polynomial()
    {

        capacity = 5;
        int *degCoeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {

            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial const &da)
    {

        this->degCoeff = new int[da.capacity];

        for (int i = 0; i < da.capacity; i++)
        {

            degCoeff[i] = da.degCoeff[i];
        }

        capacity = da.capacity;
    }

    void operator=(Polynomial const &da)
    {

        this->degCoeff = new int[da.capacity];

        for (int i = 0; i < da.capacity; i++)
        {

            degCoeff[i] = da.degCoeff[i];
        }

        capacity = da.capacity;
    }

    void print()
    {

        for (int i = 0; i < capacity; i++)
        {

            if (degCoeff[i] != 0)
            {

                cout << degCoeff[i] << " "
                     << "x" << i;
            }
        }

        cout << endl;
    }

    void setCoefficient(int degree, int coefficient)
    {

        if (degree < capacity)
        {

            degCoeff[degree] = coefficient;
        }
        else
        {

            int *newData = new int[2 * capacity];

            for (int i = 0; i < capacity; i++)
            {

                newData[i] = degCoeff[i];
            }

            for (int i = capacity; i < 2 * capacity; i++)
            {

                newData[i] = 0;
            }
            delete[] degCoeff;
            degCoeff = newData;
            capacity *= 2;
            degCoeff[degree] = coefficient;
        }
    }

    Polynomial operator+(Polynomial &da)
    {

        int Max = max(capacity, da.capacity);

        if (Max == capacity)
        {

            for (int i = da.capacity; i < capacity; i++)
            {

                da.setCoefficient(i, 0);
            }
        }

        else
        {

            for (int i = capacity; i < da.capacity; i++)
            {

                setCoefficient(i, 0);
            }
        }

        Polynomial P3;

        for (int i = 0; i < Max; i++)
        {

            P3.setCoefficient(i, degCoeff[i] + da.degCoeff[i]);
        }
    }

    Polynomial operator-(Polynomial &da)
    {

        int Max = max(capacity, da.capacity);
        Polynomial P3;

        if (Max == capacity)
        {

            for (int i = da.capacity; i < capacity; i++)
            {

                da.setCoefficient(i, 0);
            }

            for (int i = 0; i < Max; i++)
            {

                P3.setCoefficient(i, degCoeff[i] - da.degCoeff[i]);
            }
        }

        else
        {

            for (int i = capacity; i < da.capacity; i++)
            {

                setCoefficient(i, 0);
            }

            for (int i = 0; i < Max; i++)
            {

                P3.setCoefficient(i, da.degCoeff[i] - degCoeff[i]);
            }
        }

        return P3;
    }

    Polynomial operator*(Polynomial const &p2)
    {
        Polynomial p3;
        for (int i = 0; i < capacity; i++)
        {
            //  Polynomial p;
            for (int j = 0; j < p2.capacity; j++)
            {
                p3.setCoefficient(i + j, degCoeff[i] * p2.degCoeff[j]);
            }
            // p3=p3+p;
        }
        return p3;
    }
};

// Complete the class
