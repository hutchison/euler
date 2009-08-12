#include <cstdlib>
#include <iostream>
#include "math.h"
#include <sstream>
#include <fstream>
#include <vector>
#include "bignum.h"
#include <gmp.h>
#include "functions.hpp"

using namespace std;

void Problem10() {
     double sum=0,  number=1;
     while (number<2000000) {
           number++;
           if (isprime(number))
              sum += number;
     }

     cout << fixed << sum << endl;
}

void Problem11() {
     int sum,  max=0;

int numbers[400] = { 8,2 , 22,97,38,15,40,75,4,5,7,78,52,12,50,77,91,8
                    ,49 , 49 , 99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62
                    ,81 , 49 , 31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65
                    ,52 , 70 , 95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91
                    ,22 , 31 , 16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80
                    ,24 , 47 , 32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50
                    ,32 , 98 , 81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70
                    ,67 , 26 , 20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21
                    ,24 , 55 , 58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72
                    ,21 , 36 , 23,9,75,76,44,20,45,35,14,61,33,97,34,31,33,95
                    ,78 , 17 , 53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92
                    ,16 , 39 , 5,42,96,35,31,47,55,58,88,24,17,54,24,36,29,85,57
                    ,86 , 56 , 0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58
                    ,19 , 80 , 81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40
                    ,4, 52 , 8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66
                    ,88 , 36 , 68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69
                    ,4, 42 , 16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36
                    ,20 , 69 , 36 , 41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16
                    ,20 , 73 , 35 , 29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54
                    ,1, 70 , 54 , 71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48 };

     for (int i=0; i<395;i++) {
         if (i%20 <= 16) {
             //right
             sum = numbers[i] * numbers[i+1] * numbers[i+2] * numbers[i+3];
             if (sum > max)     max = sum;
             if (i < 339) {
                 //diagonal right down
                 sum = numbers[i] * numbers[i+21] * numbers[i+42] * numbers[i+63];
                 if (sum > max)     max = sum;
             }
         }
         if (i<=339) {
             // down
             sum = numbers[i] * numbers[i+20] * numbers[i+40] * numbers[i+60];
             if (sum > max)     max = sum;
         }
         if (i%20 >= 3 && i < 339) {
             // diagonal left down
             sum = numbers[i] * numbers[i+19] * numbers[i+38] * numbers[i+57];
             if (sum > max)     max = sum;
         }
     }
     cout << fixed << max << endl;
}



void Problem12() {
     int i=1,  number=0,  divisors = 0;

     while (divisors < 500) {
           number += i;
           i++;
           divisors = num_divisors(number);
//           if (divisors > 100)
//                      cout << number << " " << divisors << endl;
     }

     cout << fixed << number << endl;
}

void Problem13() {
    double hilf,  sum=0;
    char numbers[5000];

    fstream file_op("numbers 13.txt", ios::in);

    while(file_op >> numbers) {
        std::stringstream val;
        val << numbers;
        val >> hilf;
        sum+=hilf;
    }

    file_op.close();

    cout.precision(10);
    cout << sum << endl;
}

void Problem14() {
    double max_number=0,  steps,  akt,  max_steps=0;

    for (double i=1; i<1000000; i++) {
        akt=i;
        steps=0;

        while (akt!=1) {

              if (fmod(akt, 2)==0)
                 akt = akt/2;
              else
                  akt = 3*akt+1;

              steps++;
        }

        if (steps > max_steps) {
                  max_steps = steps;
                  max_number = i;
        }
    }

    cout << max_number << endl;
}

int pascaltriangle(double column, double row) {
    if (row==1 and (column==1 or column == 2))
       return 1;
    else if (row==1)
       return 0;

    if (row > 22)
        cout << row << endl;

    return pascaltriangle(column-1, row-1) + pascaltriangle(column, row-1);
}


void Problem15() {
    int dimension=20;

    double triangle[dimension*2+1][dimension*2+1];

    for (int i=0;i<dimension*2+1;i++)
        for (int j=0;j<dimension*2+1;j++)
            triangle[i][j]=0.;

    triangle[0][1]=1.;
    triangle[0][2]=1.;

    for (int i=1;i<41;i++)
    {
        triangle[i][0]=1;

        for (int j=1; j<i+1; j++)
            triangle[i][j]=triangle[i-1][j-1] + triangle[i-1][j];
    }


    cout << fixed << triangle[dimension*2][dimension] << endl;
}

/*
void Problem16() {
	BIGNAT rest,  number;
	int grenze = 1000;

	//number = 2^grenze
	string2bignat(&rest,  "2");
	string2bignat(&number,  "2");

	for (int i=1;i<grenze;i++)
	    number = mul_bignat(number,  rest);

    int sum = sum_of_digits(number);

    cout << sum << endl;
}
*/

int digit_count_letters(int i) {
    switch(i%10) {
        case 1: case 2: case 6: return 3;
        case 4: case 5: case 9: return 4;
        case 3: case 7: case 8: return 5;
        default: return 0;
    }
}

int digit_count_letters_ten(int i) {
    switch(i%10) {
        case 1: return 4;
        case 4: case 5: case 6: return 5;
        case 2: case 3: case 8: case 9: return 6;
        case 7: return 7;
        default: return 0;
    }
}

void Problem17() {
	//one thousand
    long long int sum=11;

	for (int i=1;i<=999;i++) {
	        if (i%100 == 10) sum += 3;
            else if (i%100 == 11) sum +=6;
            else if (i%100 == 12) sum +=6;
            else if (i%100 == 13) sum +=8;
            else if (i%100 == 14) sum +=8;
            else if (i%100 == 15) sum +=7;
            else if (i%100 == 18) sum +=8;
            else {
                sum+=digit_count_letters(i%10);
                sum+=digit_count_letters_ten((i%100-i%10)/10);
            }

            //hundred and
            if (i>99) {
               sum += 10;
               sum += digit_count_letters((i-i%100)/100);
            }

            //Bei runden hundertern gibts kein and
            if (i%100 == 0)
               sum -= 3;
    }
    cout << sum << endl;
}

void Problem18() {
     int dim=16;
     int dreieck[dim][dim];

     for (int i=0;i<dim;i++)
         for (int j=0;j<dim;j++)
             dreieck[i][j]=0;

     dreieck[0][0] =75;   dreieck[8][4] =83;    dreieck[12][2 ]=52;
     dreieck[1][0] =95;   dreieck[8][5] =40;    dreieck[12][3 ]=38;
     dreieck[1][1] =64;   dreieck[8][6] =80;    dreieck[12][4 ]=17;
     dreieck[2][0] =17;   dreieck[8][7] =70;    dreieck[12][5 ]=14;
     dreieck[2][1] =47;   dreieck[8][8] =33;    dreieck[12][6 ]=91;
     dreieck[2][2] =82;   dreieck[9][0] =41;    dreieck[12][7 ]=43;
     dreieck[3][0] =18;   dreieck[9][1] =48;    dreieck[12][8 ]=58;
     dreieck[3][1] =35;   dreieck[9][2] =72;    dreieck[12][9 ]=50;
     dreieck[3][2] =87;   dreieck[9][3] =33;    dreieck[12][10]=27;
     dreieck[3][3] =10;   dreieck[9][4] =47;    dreieck[12][11]=29;
     dreieck[4][0] =20;   dreieck[9][5] =32;    dreieck[12][12]=48;
     dreieck[4][1] =4 ;   dreieck[9][6] =37;    dreieck[13][0]=63;
     dreieck[4][2] =82;   dreieck[9][7] =16;    dreieck[13][1 ]=66;
     dreieck[4][3] =47;   dreieck[9][8] =94;    dreieck[13][2 ]=4 ;
     dreieck[4][4] =65;   dreieck[9][9] =29;    dreieck[13][3 ]=68;
     dreieck[5][0] =19;   dreieck[10][0]=53;    dreieck[13][4 ]=89;
     dreieck[5][1] =1 ;   dreieck[10][1]=71;    dreieck[13][5 ]=53;
     dreieck[5][2] =23;   dreieck[10][2]=44;    dreieck[13][6 ]=67;
     dreieck[5][3] =75;   dreieck[10][3]=65;    dreieck[13][7 ]=30;
     dreieck[5][4] =3 ;   dreieck[10][4]=25;    dreieck[13][8 ]=73;
     dreieck[5][5] =34;   dreieck[10][5]=43;    dreieck[13][9 ]=16;
     dreieck[6][0] =88;   dreieck[10][6]=91;    dreieck[13][10]=69;
     dreieck[6][1] =2 ;   dreieck[10][7]=52;    dreieck[13][11]=87;
     dreieck[6][2] =77;   dreieck[10][8]=97;    dreieck[13][12]=40;
     dreieck[6][3] =73;   dreieck[10][9]=51;    dreieck[13][13]=31;
     dreieck[6][4] =7 ;   dreieck[10][10]=14;   dreieck[14][0]=04;
     dreieck[6][5] =63;   dreieck[11][0]=70;    dreieck[14][1 ]=62;
     dreieck[6][5] =67;   dreieck[11][1 ]=11;   dreieck[14][2 ]=98;
     dreieck[7][0] =99;   dreieck[11][2 ]=33;   dreieck[14][3 ]=27;
     dreieck[7][1] =65;   dreieck[11][3 ]=28;   dreieck[14][4 ]=23;
     dreieck[7][2] =4 ;   dreieck[11][4 ]=77;   dreieck[14][5 ]=9 ;
     dreieck[7][3] =28;   dreieck[11][5 ]=73;   dreieck[14][6 ]=70;
     dreieck[7][4] =6 ;   dreieck[11][6 ]=17;   dreieck[14][7 ]=98;
     dreieck[7][5] =16;   dreieck[11][7 ]=78;   dreieck[14][8 ]=73;
     dreieck[7][6] =70;   dreieck[11][8 ]=39;   dreieck[14][9 ]=93;
     dreieck[7][7] =92;   dreieck[11][9 ]=68;   dreieck[14][10]=38;
     dreieck[8][0] =41;   dreieck[11][10]=17;   dreieck[14][11]=53;
     dreieck[8][1] =41;   dreieck[11][11]=57;   dreieck[14][12]=60;
     dreieck[8][2] =26;   dreieck[12][0]=91;    dreieck[14][13]=4 ;
     dreieck[8][3] =56;   dreieck[12][1 ]=71;   dreieck[14][14]=23;

     int b[dim][dim];

     for (int i=0;i<dim;i++)
         for (int j=0;j<dim;j++)
             b[i][j]=0;

     b[0][0]=dreieck[0][0];

     for (int zeile=1;zeile<dim;zeile++)
     {
         b[zeile][0]=b[zeile-1][0] + dreieck[zeile][0];
         b[zeile][zeile]=b[zeile-1][zeile-1] + dreieck[zeile][zeile];
         for (int spalte=1;spalte<zeile;spalte++)
         {
             if (b[zeile-1][spalte]>b[zeile-1][spalte-1])
                b[zeile][spalte]=b[zeile-1][spalte]+dreieck[zeile][spalte];
             else
                b[zeile][spalte]=b[zeile-1][spalte-1]+dreieck[zeile][spalte];
         }
     }

     int max =0;
     for (int j=0;j<dim;j++)
         if (b[dim-1][j]>max)
            max = b[dim-1][j];

     cout << max << endl;
}

int anzahltage(int month,  int year) {
    switch (month)
    {
           case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
           case 4: case 6: case 9: case 11:
                return 30;
    }

    //Schaltjahr
    if (year%4==0 and year%100!=0 and year%400 == 0)
           return 29;

    //kein Schaltjahr
    return 28;
}

void Problem19() {
     int tag = 2,  sonntage=0;

     for (int year=1901;year<2001;year++)
         for (int month=1;month<=12;month++)
         {
             tag += anzahltage(month, year);
             if (tag%7 == 0)
                sonntage ++;
         }

     cout << sonntage << endl;
}
