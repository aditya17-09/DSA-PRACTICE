//Write a C++ program to convert a given non-negative integer into English words.
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static string belowTwenty[] ={"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                 "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                 "Seventeen", "Eighteen", "Nineteen"};
                 
static string belowHundred[]={"","", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };


static string overThousand[]={"Hundred", "Thousand", "Million", "Billion" };


string number_to_words_below_hundred(long long int num) {
    string result;

    if (num == 0) {
        return result;
    }else if (num < 20) {
        return belowTwenty[num];
    } else if (num < 100) {
        result = belowHundred [num/10];
        if (num%10 > 0) { 
            result += " " + belowTwenty[num%10];
        }
    }else {
        result = belowTwenty[num/100] + " " + overThousand[0];
        if ( num % 100 > 0 ) {
            result += " " + number_to_words_below_hundred( num % 100 );
        }
    }
    return result;
}

string number_to_words(int num) {
    if (num ==0 ) return belowTwenty[num];

    vector<string> ret;
    for( ;num > 0; num/=1000 ) {
        ret.push_back( number_to_words_below_hundred(num % 1000) );
    }

    string result=ret[0];
    for (int i=1; i<ret.size(); i++){
        if (ret[i].size() > 0 ){
            if ( result.size() > 0 ) {
                result = ret[i] + " " + overThousand[i] + " " + result; 
            } else {
                result = ret[i] + " " + overThousand[i]; 
            }
        }

    }
    return result;
}

int main() 
{
      
	  long long int num = 0;
      cout << num << " ->  " << number_to_words(num) <<  endl;
      num = 9;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 12;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 29;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 234;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 777;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 1023;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 45321;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;
      num = 876543;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;	  	  	  	  	  	        
      num = 8734210;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;	  	  	  	  	  	        
      num = 329876120;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;	  	 
      num = 18348797629876120;
      cout << "\n" << num << " ->  " << number_to_words(num) <<  endl;	   	  	  	  	        	        
    return 0;
}
