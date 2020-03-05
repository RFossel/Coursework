/*************************************************************
 Name: Raul Fosselman
 Username: cssc1900
 Class: CS530 Spring 2020
 Project: CS-530 Assignment 1
 File: dbx.cpp
 Notes: Opens and reads every byte in a file (specified by the user when
 launching the program) and writes both the ASCII hex value for that
 byte as well as it’s printable (human-readable) character. The user may also choose to have the program print in binary instead of hex.
 *************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <bitset>

using namespace std;

const int HEX_LENGTH = 16;
const int BIN_LENGTH = 6;
const int ADDRESS_LENGTH = 7;

/*************************************************************
 FUNCTION: printInstructions()
 DESCRIPTION: Prints instructions describing how to properly input arguments
 *************************************************************/
void printInstructions() {
    cout << "Make sure you have proper input as such: dbx <filename> or dbx -b <filename>";
}

/*************************************************************
 FUNCTION: hexDump()
 DESCRIPTION: Prints an address, 16 bytes in hexidecimal format, and the ASCII representation of those bytes
 
 ex:    0003540: 0504 0675 6e73 6967 6e65 6420 6368 6172 ...unsigned char
 *************************************************************/
void hexDump(const char* hexBuffer, unsigned int address, int charCount) {
    //Print the address
    cout << hex << setw(ADDRESS_LENGTH) << setfill('0') << address << ":";
    
    //Loop to print hex
    for (int i = 0; i < HEX_LENGTH; i++) {
        //Spaces
        if (i % 2 == 0){
            cout << " ";
        }
    
        //Format the last line
        if (i >= charCount){
            cout << "  ";
        }
        else {
            //Print the hex value for the char
            printf("%02x", hexBuffer[i]);
        }
    }
    //Print the ASCII printable chars in the current line
    cout << "  ";
    for (int i = 0; i < charCount; i++) {
        //Printable ASCII chars are 32<X<128 (decimal)
        //Check if it's a printable ASCII char
        if (hexBuffer[i] < 32 || hexBuffer[i] > 127){
            cout << '.';//Default if not printable
        }
        else{
            //Print the human-readable character
            cout << hexBuffer[i];
        }
    }
    cout << endl;
}

/*************************************************************
 FUNCTION: binDump()
 DESCRIPTION: Prints an address, 6 bytes in hexidecimal format, and the ASCII representation of those bytes
 
 ex:    "000010e: 01100011 01101111 01110110 01100101 01110010 00100000  cover"
 *************************************************************/
void binDump(const char* binBuffer, unsigned int address, int charCount) {
    //Print address
    cout << hex << setw(ADDRESS_LENGTH) << setfill('0') << address<< ":";
    
    //Loop to print binary
    for(int i=0; i<BIN_LENGTH; i++) {
        //Format last line
        if(i >= charCount){
            cout << "        ";
        }
        else {
            //Make the char val into a bitset to print its bin representation
            cout << " " << bitset<8>(binBuffer[i]);
        }
    }
    //Print the ASCII printable chars in the current line
    cout << "  ";
    for(int i=0; i<charCount; i++) {
        //Printable ASCII chars are 32<X<128 (decimal)
        //Check if it's a printable ASCII char
        if(binBuffer[i] < 32 || binBuffer[i] > 127)
            cout << '.';//Default if not printable
        else
            cout << binBuffer[i];
    }
    cout << endl;
}

/*************************************************************
 FUNCTION: checkArgs()
 DESCRIPTION: Checks to see that the user has put in valid arguments and determines whether the user wishes to print binary or hex output. Returns boolean to set binFlag
 *************************************************************/
bool checkArgs(int argc, char* argv[]){
    int binOption;
    bool binFlag = false;
    //Check for correct number of args
    if (argc <= 1 || argc > 3) {
        printInstructions();
        exit(1);
    }
    //Check if user selected binary option
    while ((binOption = getopt(argc, argv, "b")) != -1) {
        switch (binOption) {
            case 'b':
                binFlag = true;
                break;
            default:
                printInstructions();
                exit(1);
        }
    }
    //Check for proper num of args given the user hasn't selected binary mode
    if (argc >= 3 && !binFlag) {
        printInstructions();
        exit(1);
    }
    return binFlag;
}

/*************************************************************
MAIN
 *************************************************************/
int main(int argc, char* argv[]) {
    unsigned int address = 0;
    bool binFlag;//0 = print hex; 1 = print bin
    binFlag = checkArgs(argc, argv);
    
    //Note: optind is an external variable to keep track of the next element in argv
    ifstream myFile(argv[optind], ios::binary | ios::in);
    
    //Check the file the user provided
    if (!myFile) {
        cout << "FILE NOT FOUND";
        exit(1);
    }
    
    if (!binFlag) {
        while (myFile) {
            //Create a buffer, fill it w/ 16 chars(or less for the last charaters), and hexDump its vals
            char hexBuffer[HEX_LENGTH] = {};
            myFile.read(hexBuffer, HEX_LENGTH);
            int charCount = myFile.gcount();//num of chars put in the buffer
            hexDump(hexBuffer, address, charCount);
            address += HEX_LENGTH;
        }
    }
    else {
        while (myFile) {
            //Create a buffer, fill it w/ 6 chars(or less for the last charaters), and binDump its vals
            char binBuffer[BIN_LENGTH] = {};
            myFile.read(binBuffer, BIN_LENGTH);
            int charCount = myFile.gcount();//num of chars put in the buffer
            binDump(binBuffer, address, charCount);
            address += BIN_LENGTH;
        }
    }
    
    myFile.close();
    return 0;
}

 /****************************** EOF: dbx.cpp  *******************************/
