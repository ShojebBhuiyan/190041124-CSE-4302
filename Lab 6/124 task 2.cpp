#include <iostream>
using namespace std;

class Matrix3D
{
    private:
    double m[3][3];

    public:
    Matrix3D(double a11, double a12, double a13,
                double a21, double a22, double a23,
                double a31, double a32, int a33)
            {
                m[0][0] = a11; m[0][1] = a12; m[0][2] = a13;
                m[1][0] = a21; m[1][1] = a22; m[1][2] = a23;
                m[2][1] = a31; m[2][1] = a32; m[2][2] = a33;
            }

    double det() const
    {
        return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
                + m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
                + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    void view()
    {
        for(int i = 0; i < 3; i++)	
        {
            for(int j = 0; j < 3; j++) 
            {
                cout << m[i][j] << "  ";
            }
            cout << endl;		
        }
    }

    Matrix3D inverse() const;
    ~Matrix3D()
    { }

    Matrix3D operator + (Matrix3D) const;
    Matrix3D operator - (Matrix3D) const;
    Matrix3D operator * (Matrix3D) const;
};

Matrix3D Matrix3D::inverse() const
{
    Matrix3D temp(0, 0, 0, 0, 0, 0, 0, 0, 0);
    double det = this->det();
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.m[i][j] = (m[(j + 1) % 3][(i + 1) % 3]
                        * m[(j + 2) % 3][(i + 2) % 3]
                        - m[(j + 1) % 3][(i + 2) % 3]
                        * m[(j + 2) % 3][(i + 1) % 3])
                        / det;
    return temp;
}

Matrix3D Matrix3D::operator + (Matrix3D m2) const
{
    Matrix3D temp(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.m[i][j] = m[i][j] + m2.m[i][j];

    return temp;
}

Matrix3D Matrix3D::operator - (Matrix3D m2) const
{
    Matrix3D temp(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.m[i][j] = m[i][j] - m2.m[i][j];

    return temp;
}

Matrix3D Matrix3D::operator * (Matrix3D m2) const
{
    Matrix3D temp(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            temp.m[i][j] += m[i][k] * m2.m[k][j];

    return temp;
}

int main()
{
    
    Matrix3D m1(3,3,-1,-2,-2,1,-4,-5,2);

    m1.view();

    cout << m1.det() << endl;

    cout << endl << endl;

    Matrix3D m2 = m1.inverse();
    m2.view();

    m1 = m1 * m2;


    cout << endl << endl;
    m1.view();

    return 0;
}