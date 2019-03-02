#include <iostream>
#include <math.h>
using namespace std;

#define MAX_DEG 100

void mult_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R)
{
    for (int i = 0; i <= P_deg; i++)
        for (int j = 0; j <= Q_deg; j++)
            R[i + j] += P[i] * Q[j];
}

void copy_p(double * to, const double * from)
{
    for(int i = 0; i < MAX_DEG; i++)
        to[i] = from[i];
}

void zero_p(double * P)
{
    for(int i = 0; i < MAX_DEG; i++)
        P[i] = 0;
}


int main()
{
    double P[MAX_DEG] = {0},
           Q[MAX_DEG] = {0},
           temp[MAX_DEG] = {0},
           temp2[MAX_DEG] = {0},
           R[MAX_DEG] = {0};
    int P_deg, Q_deg, R_deg, temp_deg, temp2_deg;


    do {
        cout << "Insert P polynom degree\n\nFor example:\nIf P(x) = 1*x^5 + 6*x^3 - 2*x^2 + 5*x - 13\nthen degree = 5\n";
        cin >> P_deg;
    } while( P_deg <= 0 || P_deg >= MAX_DEG );

    cout << "Insert P polynom coefficients\n\nFor example:\nIf P(x) = 1*x^5 + 6*x^3 - 2*x^2 + 5*x - 13\nthen coefficients is = -13 5 -2 6 0 1 \n";
    for (int i = 0; i <= P_deg; i++)
        cin >> P[i];

    do {
        cout << "Insert Q polynom degree\n";
        cin >> Q_deg;
    } while( Q_deg < 0 || Q_deg >= MAX_DEG );


    cout << "Insert Q polynom coefficients\n";
    for (int i = 0; i <= Q_deg; i++)
        cin >> Q[i];

    R_deg = P_deg * Q_deg;

    // свободный член сохраняется
    R[0] = P[0];

    for (int i = 1; i <= P_deg; i++) {

        // записываем Q(x) в temp
        copy_p( temp, Q );
        // степень temp равна степени Q(x)
        temp_deg = Q_deg;

        for (int j = 0; j < i-1 ; j++) {
            // перемножить многочлен Q(x) i-1 раз
            // берем temp2[ ]
            // на первом шаге в temp2 запишется Q*Q
            temp_deg += Q_deg;
            mult_p( temp, temp_deg, Q, Q_deg, temp2 );

            // temp хранит многочлен-результат предыдущего шага
            // так что скопируем temp2 в temp
            copy_p(temp, temp2);
            // а temp2 обнулим
            zero_p(temp2);
        }

        // когда temp уже хранит коеффициенты многочлена Q(x)^(i-1) ,
        // умножим коэффициенты temp на коэффициент перед P[i]
        // и сразу же добавим их к имеющемуся многочлену R
        for (int j = 0; j <= temp_deg; j++)
            R[j] += P[i] * temp[j];

        // уничтожим мусор
        zero_p(temp);
    }

    R_deg = P_deg * Q_deg;


    // вывести результат в виде многочлена

    cout << "\n=== RESULT: ===\n";
    for(int i = R_deg; i >= 0; i-- ) {

        if ( R[i] < 0 )
            cout << "- ";
        else if ( R[i] > 0 && i != R_deg ) // для первого слагаемого "+" выводить как-то некрасиво
            cout << "+ ";
        else if ( i != R_deg ) // тут коэф. равен 0, нифига не выводим
            continue;

        if (i != 0) // для свободного члена x^0 писать не надо
            cout << R[i] << "x^" << i << " ";
        else
            cout << R[i];
    }

    cout << endl;

 }
