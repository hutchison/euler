#include <iostream>
#include "math.h"
#include <sstream>
#include <fstream>
#include <vector>
#include "bignum.h"
#include <gmp.h>
#include "functions.hpp"

using namespace std;

void Problem1() {
     int i,  sum=0;
     for (i=1;i<1000;i++) {
         if (i%3==0 or i%5==0)
            sum +=i;
     }
     cout << sum << endl;
}

void Problem2() {
     int i=0,  j=1,  hilf,  sum=0;
     while (j < 4000000) {
           hilf = i+j;
           i=j;
           j=hilf;
           if (j%2==0)
                sum += j;
     }
     cout << sum << endl;
}

void Problem3() {
     double i,  zahl,  max=1;
     zahl=600851475143.;
     for(i=1;i<sqrt(zahl);i++)
           if (fmod(zahl, i)==0)
               if (isprime(i))
                   max = i;

     cout << max << endl;
}

void Problem4() {
     int max=0;
     for (int i=999;i>1;i--)
          for(int j=999;j>1;j--)
                  if (ispalindrom(i*j) and i*j > max)
                                       max = i*j;

     cout << max << endl;
}

bool isdivisible(int number) {
     for (int j=20;j>1;j--)
         if (number%j != 0)
            return false;

     return true;
}

void Problem5() {
     int min=10;
     while (isdivisible(min) == false)
           min +=2;

     cout << min << endl;
}

void Problem6() {
     int sq=0,  su=0;
     for (int i=0;i<=100;i++) {
         sq += i*i;
         su += i;
     }
     su = su*su;

     cout << su-sq << endl;
}

void Problem7() {
     int i=0,  number=1;
     while (i<10001) {
           number++;
           if (isprime(number))       i++;
     }

     cout << number << endl;
}

void Problem8() {
     int hilf,  sum,  max = 0;
     char number[1001];

     sprintf(number, "73167176531330624919225119674426574742355349194934"
                "96983520312774506326239578318016984801869478851843"
                "85861560789112949495459501737958331952853208805511"
                "12540698747158523863050715693290963295227443043557"
                "66896648950445244523161731856403098711121722383113"
                "62229893423380308135336276614282806444486645238749"
                "30358907296290491560440772390713810515859307960866"
                "70172427121883998797908792274921901699720888093776"
                "65727333001053367881220235421809751254540594752243"
                "52584907711670556013604839586446706324415722155397"
                "53697817977846174064955149290862569321978468622482"
                "83972241375657056057490261407972968652414535100474"
                "82166370484403199890008895243450658541227588666881"
                "16427171479924442928230863465674813919123162824586"
                "17866458359124566529476545682848912883142607690042"
                "24219022671055626321111109370544217506941658960408"
                "07198403850962455444362981230987879927244284909188"
                "84580156166097919133875499200524063689912560717606"
                "05886116467109405077541002256983155200055935729725"
                "71636269561882670428252483600823257530420752963450");

     for (int i=0;i<1000;i++) {
         sum = 1;

         for (int j=0;j<5;j++) {
             std::stringstream val;
             val << number[i+j];
             val >> hilf;
             sum*=hilf;
         }

         if (sum > max)
                  max = sum;
     }

     cout << max << endl;
}

void Problem9() {
     int number;
     for (int i=1;i<1000;i++)
         for (int j=1;j<1000;j++) {
             number = i*i+j*j;
             if (fmod(number,  sqrt(number)) == 0)
                if (i+j+sqrt(number)==1000)
                                cout << i << " " << j << " "<< sqrt(number) << " " << i*j*sqrt(number) << endl;
         }
}
