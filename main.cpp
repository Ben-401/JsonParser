/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Zhi (Tom) Lin
 *
 * Created on 21 March 2018, 7:09 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include <string>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string n;
    string line;
    
    struct sensorData {
        string n;
        int u;
        int t; // (T NEEDS TO STORE NULLS AND INTS)
        string d;
        string z;
        int s;
        int e;
        string b;
        int p;
        int m;
        int x;
        string g;
        bool w;

    };

    struct sensorIdentifier {
        int name;
        sensorData data;
    };

    sensorIdentifier structureArray[1000];

    //    fstream is used to allow INPUT AND OUTPUT TO FILES
    
    //    fstream jsonFile("sensors [modified].json"); USED FOR TESTING A SMALLER SAMPLE
    fstream jsonFile("sensors.json"); // USED FOR TESTING A SMALLER SAMPLE

    //    sensorIdentifier[0].name = 101;
    //    sensorIdentifier[0].data.d = "Testing";
    //    sensorIdentifier[0].data.t = 3;
    //    
    //    sensorIdentifier[1].name = 99;
    //    sensorIdentifier[1].data.d = "Testing2";
    //    sensorIdentifier[1].data.t = 5;


    if (jsonFile.is_open()) { // DETECTS IF THE FILE IS OPEN
        while (getline(jsonFile, line)) {
            if ((line.length() != 1)&&(line.find_last_of('{') != -1)) {
                /* 
                 * Detects if the line's length is greater than one and contains a "{" AKA OPENING CURLY BRACE.
                 * This allows it to find all the names to be placed into the identifier.
                 * SUCCESSFULLY TESTED
                 */
                //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION

            }
            switch (line[9]) {
                case 'n': // Detects if the 9th Element is n (i.e. Attribute is n)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'u': // Detects if the 9th Element is u (i.e. Attribute is U)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 't': // Detects if the 9th Element is t (i.e. Attribute is T)
                    cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'd': // Detects if the 9th Element is d (i.e. Attribute is d)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'z': // Detects if the 9th Element is z (i.e. Attribute is Z)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 's': // Detects if the 9th Element is s (i.e. Attribute is S)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'e': // Detects if the 9th Element is e (i.e. Attribute is E)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'b': // Detects if the 9th Element is B (i.e. Attribute is B)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'p': // Detects if the 9th Element is P (i.e. Attribute is P)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'm': // Detects if the 9th Element is M (i.e. Attribute is M)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'x': // Detects if the 9th Element is X (i.e. Attribute is X)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'g': // Detects if the 9th Element is G (i.e. Attribute is G)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'w': // Detects if the 9th Element is W (i.e. Attribute is W)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'v': // Detects if the 9th Element is V (i.e. Attribute is V)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    // THIS LINE OF CODE HAS CURLY BRACES. DO I REMOVE THEM??
                    break;
                default:
                {
                }//DO NOTHING
            }

            if (line[9] == 'c') { // WILL NOT RUN SINCE C DOESN'T EXIST
                structureArray[0].data.u = 5;
            }
            //            cout << line[9] << endl; // PRINTS OUT THE 9TH ELEMENT OF LINE e.g. n,u,t,d
            //            cout << line << endl; // Prints out EVERYTHING
            //            cout << structureArray[0].data.d << endl;
        }
        jsonFile.close();
    } else {
        cout << "Unable to open file";
    }

    // LEARN TO ITERATE OVER OBJECTS BY PRINTING OUT THE IDENTIFIER E.G. 100, 101
    // USE DATA STRUCTURES http://www.cplusplus.com/doc/tutorial/structures/
    // https://www.programiz.com/cpp-programming/structure
    // LEARN TO OPEN JSON FILES & PARSE THEIR CONTENTS
    // SSCANF FUNCTION C++?

    return 0;
}

