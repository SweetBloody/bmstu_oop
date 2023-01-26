#include <iostream>
#include <vector>

#include "Matrix.h"
#include "matrix_realize.h"

int main()
{
    try
    {
        std::cout << "--------------CONSTRUCTORS--------------\n";

        std::cout << "Null matrix:\n";
        Matrix<float> mtrx1(3, 3);
        mtrx1.fill_zero();
        std::cout << mtrx1;

        std::cout << "Mtrx2(mtrx1):\n";
        Matrix<float> mtrx2(mtrx1);
        std::cout << mtrx2;

        std::cout << "Matrix from array:\n";
        Matrix<float> mtrx3({ { 5.2f, 2.5f, 3.8f }, { 1.2f, 2.3f, 3.2f } });
        std::cout << mtrx3;

        std::cout << "--------------ADDITION--------------\n";
        std::cout << "Matrix 1:\n";
        mtrx1.identity_matrix();
        std::cout << mtrx1;

        std::cout << "Matrix 2:\n";
        mtrx2.identity_matrix();
        std::cout << mtrx2;

        std::cout << "mtrx1 += mtrx2:\n";
        mtrx1 += mtrx2;
        std::cout << mtrx1;

        std::cout << "mtrx1 = mtrx1 + mtrx2:\n";
        mtrx1 = mtrx1 + mtrx2;
        std::cout << mtrx1;

        std::cout << "mtrx1.add(mtrx2):\n";
        mtrx1.add(mtrx2);
        std::cout << mtrx1;

        std::cout << "mtrx1.add(2):\n";
        mtrx1.add(2);
        std::cout << mtrx1;

        std::cout << "--------------SUBSTRACTION--------------\n";
        std::cout << "Matrix 1:\n";
        mtrx1.identity_matrix();
        std::cout << mtrx1;

        std::cout << "Matrix 2:\n";
        mtrx2.identity_matrix();
        std::cout << mtrx2;

        std::cout << "mtrx1 -= mtrx2:\n";
        mtrx1 -= mtrx2;
        std::cout << mtrx1;

        std::cout << "mtrx1 = mtrx1 - mtrx2:\n";
        mtrx1 = mtrx1 - mtrx2;
        std::cout << mtrx1;

        std::cout << "mtrx1.sub(mtrx2):\n";
        mtrx1.sub(mtrx2);
        std::cout << mtrx1;

        std::cout << "mtrx1.sub(2):\n";
        mtrx1.sub(2);
        std::cout << mtrx1;


        std::cout << "--------------MULTIPLICATION--------------\n";
        std::cout << "Matrix 1:\n";
        mtrx1.identity_matrix();
        std::cout << mtrx1;

        std::cout << "Matrix 2:\n";
        mtrx2.identity_matrix();
        std::cout << mtrx2;

        std::cout << "mtrx1.mult(3):\n";
        mtrx1.mult(3);
        std::cout << mtrx1;

        std::cout << "mtrx2.mult(4):\n";
        mtrx2.mult(4);
        std::cout << mtrx2;

        std::cout << "mtrx1.mult(mtrx2):\n";
        mtrx1 = mtrx1.mult(mtrx2);
        std::cout << mtrx1;

        std::cout << "mtrx1 = mtrx1 * 2:\n";
        mtrx1 = mtrx1 * 2;
        std::cout << mtrx1;


        std::cout << "--------------INVERTED--------------\n";
        std::cout << "Matrix 1:\n";
        Matrix<float> mtrx5({{1, 2, -3}, {4, -5, -6}, {7, -8, 9}});
        std::cout << mtrx5;
        mtrx5 = mtrx5.inverted();
        std::cout << mtrx5;


        std::cout << "--------------DIVISION--------------\n";
        std::cout << "Matrix 1:\n";
        mtrx1.identity_matrix();
        mtrx1.mult(3);
        std::cout << mtrx1;

        std::cout << "Matrix 2:\n";
        mtrx2.identity_matrix();
        mtrx2.mult(4);
        std::cout << mtrx2;

        std::cout << "mtrx1.divide(3):\n";
        mtrx1.divide(3);
        std::cout << mtrx1;

        std::cout << "mtrx2.divide(4):\n";
        mtrx2.divide(4);
        std::cout << mtrx2;

        std::cout << "mtrx1.divide(mtrx2):\n";
        mtrx1 = mtrx1.divide(mtrx2);
        std::cout << mtrx1;

        std::cout << "mtrx1 = mtrx1 / 2:\n";
        mtrx1 = mtrx1 / 2;
        std::cout << mtrx1;

        std::cout << "Matrix 6:\n";
        Matrix<float> mtrx6({{1, 2, 3}, {6, 4, 2}, {0, -5, -10}});
        std::cout << mtrx6;

        std::cout << "Matrix 7:\n";
        Matrix<float> mtrx7({{2, 3, 3}, {5, -11, 7}, {5, 1, 8}});
        std::cout << mtrx7;

        std::cout << "mtrx6.divide(mtrx7):\n";
        mtrx6 = mtrx6.divide(mtrx7);
        std::cout << mtrx6;

        std::cout << "--------------DETERMINANT--------------\n";
        std::cout << "Matrix 4:\n";
        Matrix<int> mtrx4({ {2, 8, -2}, {6, 0, 2}, {-1, 3, -5} });
        std::cout << mtrx4;
        auto det = mtrx4.determinant();
        std::cout << "det = " << det << std::endl;

        std::cout << "\n--------------TRANSPOSE--------------\n";
        std::cout << "Matrix 4:\n";
        std::cout << mtrx4;
        std::cout << "Matrix 4 (transpose):\n";
        mtrx4 = mtrx4.transpose();
        std::cout << mtrx4;

        std::cout << "--------------GET VALUE--------------\n";
        std::cout << "Matrix 3:\n";
        std::cout << mtrx3;
        std::cout << "value(1, 0) = ";
        std::cout << mtrx3.get_value(1, 0) << "\n" << std::endl;


        std::cout << "--------------SET VALUE--------------\n";
        std::cout << "Matrix 1:\n";
        std::cout << mtrx1;
        std::cout << "value(1, 0, 3)\n";
        mtrx1.set_value(1, 0, 3);
        std::cout << "Matrix 1:\n";
        std::cout << mtrx1;

        std::cout << "--------------ITERATORS--------------\n";
        std::cout << "Matrix 3:\n";
        auto iter = mtrx3.begin();

        for (size_t i = 0; iter != mtrx3.end(); i++, iter++)
        {
            if (i % mtrx3.get_m() == 0)
            {
                std::cout << std::endl;
            }

            std::cout << *iter << ' ';
        }
    }

    catch (MatrixBaseException& exception)
    {
        std::cout << exception.what();
    }

    return 0;
}
