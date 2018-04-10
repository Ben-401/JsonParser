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
#include <string>
#include <vector>

using namespace std;

void lineProcessor(string line) {


}

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
    fstream jsonFile("sensors.json"); // USED FOR TESTING A SAMPLE

    //    sensorIdentifier[0].name = 101;
    //    sensorIdentifier[0].data.d = "Testing";
    //    sensorIdentifier[0].data.t = 3;
    //    
    //    sensorIdentifier[1].name = 99;
    //    sensorIdentifier[1].data.d = "Testing2";
    //    sensorIdentifier[1].data.t = 5;


    if (jsonFile.is_open()) { // DETECTS IF THE FILE IS OPEN
        int arrayNumber = 0;
        while (getline(jsonFile, line)) {
            if ((line.length() != 1)&&(line.find_last_of('{') != -1)) { //USED FOR UNIQUELY IDENTIFYING OBJECT IDENTIFIER LINE
                // cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                // In summary, the code below deletes everything that isn't a number and then converts it to an integer
                for (int i = 0; i < 4; i++) {
                    int markedCharPosition = line.find_first_of(":{\""); // Position of Character to be deleted
                    line.erase(markedCharPosition, 1); // Deletes the Character
                    // cout << line << endl;
                }
                // NOTE THAT STOI CONVERTS FROM STRING TO INTEGER
                // cout << stoi(line) << endl;
                structureArray[arrayNumber].name = stoi(line);
                arrayNumber++; //Switches to the next object
                // cout << "NUMBER OF OBJECTS: " << arrayNumber << endl;
            }
            switch (line[9]) {
                case 'n': // Detects if the 9th Element is n (i.e. Attribute is n)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    break;
                case 'u': // Detects if the 9th Element is u (i.e. Attribute is U)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    for (int i = 0; i < 5; i++) {
                        int markedCharPosition = line.find_first_of(":u\","); // Position of Character to be deleted
                        line.erase(markedCharPosition, 1); // Deletes the Character
                        // cout << line << endl;
                    }
                    structureArray[arrayNumber - 1].data.u = stoi(line); //ArrayNumber-1 is to correct a bug in code
                    break;
                case 't': // Detects if the 9th Element is t (i.e. Attribute is T)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    if (line.find("null,") != -1) {
                        structureArray[arrayNumber - 1].data.t = 0;
                    }
                    else {
                        for (int i = 0; i < 5; i++) {
                            int markedCharPosition = line.find_first_of(":t\","); // Position of Character to be deleted
                            line.erase(markedCharPosition, 1); // Deletes the Character
                            //cout << line << endl;
                        }
                        structureArray[arrayNumber - 1].data.t = stoi(line); //ArrayNumber-1 is to correct a bug in code
                    }

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

            // cout << line[9] << endl; // PRINTS OUT THE 9TH ELEMENT OF LINE e.g. n,u,t,d
            // cout << line << endl; // Prints out EVERYTHING
            // cout << structureArray[0].data.d << endl;
        }
        jsonFile.close();
    } else {
        cout << "Unable to open file";
    }

    for (int i = 0; i < 109; i++) { //TESTERS
        //cout << structureArray[i].name << endl;
        //cout << structureArray[i].name << " U: " << structureArray[i].data.u << endl;
        //cout << structureArray[i].name << " T: " << structureArray[i].data.t << endl;
    }
    // LEARN TO ITERATE OVER OBJECTS BY PRINTING OUT THE IDENTIFIER E.G. 100, 101
    // USE DATA STRUCTURES http://www.cplusplus.com/doc/tutorial/structures/
    // https://www.programiz.com/cpp-programming/structure
    // LEARN TO OPEN JSON FILES & PARSE THEIR CONTENTS
    // SSCANF FUNCTION C++?

    return 0;
}

