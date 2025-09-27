#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <cstdio>
#include <cstring>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;


string DecimalToBinary(long int number)
{
    if (number <= 0){
        return "0";
    }
    else{
        string result = "";
        int i = 0;
        while (number > 0){
            long long int num = number % 2;
            stringstream ss;
            ss<<num;
            result.insert(0, ss.str());
            number = number / 2;
            i++;
        }
        return result;
    }
}


// The main function that multiplies two bit strings X and Y and returns
// result as long integer



string addBitStrings( string a, string b )
{
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Traverse both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--; j--;
    }
    return result;
}

string findTwoscomplement(string str)
{
    int n = str.length();

    // Traverse the string to get first '1' from
    // the last of string
    int i;
    for (i = n-1 ; i >= 0 ; i--)
        if (str[i] == '1')
            break;

    // If there exists no '1' concatenate 1 at the
    // starting of string
    if (i == -1)
        return '1' + str;

    // Continue traversal after the position of
    // first '1'
    for (int k = i-1 ; k >= 0; k--)
    {
        //Just flip the values
        if (str[k] == '1')
            str[k] = '0';
        else
            str[k] = '1';
    }

    // return the modified string
    return str;;
}

string addC2( string a, string b )
{
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Traverse both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--; j--;
    }
    return result;
}

string Subtraction(string lhs, string rhs)
{

    string result = addC2(lhs, findTwoscomplement(rhs));
    return result;
}

string multiply(string lhs, string rhs){
    int length = max(lhs.size(), rhs.size());

    while (lhs.size() < length)
        lhs.insert(0,"0");

    while (rhs.size() < length)
        rhs.insert(0,"0");

    if (length == 1)
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));

    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);

    string p0 = multiply(lhs0,rhs0);
    string p1 = multiply(lhs1,rhs1);
    string p2 = multiply(addBitStrings(lhs0,lhs1),addBitStrings(rhs0,rhs1));
    string p3 = Subtraction(p2,addBitStrings(p0,p1));

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");

    string result = addBitStrings(addBitStrings(p0,p1),p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

int main() {
    clock_t start = clock();
    ifstream file("input.txt");
    string str;
    while (getline(file, str)) { //lee las lineas del archivo input
        istringstream buf(str);
        istream_iterator<string> beg(buf), end;
        vector<string> txtvec(beg, end); //para cada linea, se hace un "split" en sus espacios formando un vector de 3 casillas
        //stringstream num(txtvec[0]);
        //num >> N; //se hace un stream para pasar el numero de bits de string a int
        cout << multiply(txtvec[1], txtvec[2])  << "\n";

    }
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}