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
        double x;
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
                    line.erase((line.find("        \"n\": \"")), 14); // Deletes: ["n": ] (8 White Spaces)
                    line.erase(line.find_last_of('\"'),2); //Erases [",]
                    //cout << line << endl;
                    structureArray[arrayNumber - 1].data.n = line; //ArrayNumber-1 is to correct a bug in code
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
                    if (line.find("null,") != -1) { //IF T IS NULL
                        structureArray[arrayNumber - 1].data.t = 0;
                    } else {
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
                    line.erase((line.find("        \"d\": \"")), 14); // Deletes: ["d": ] (8 White Spaces)
                    line.erase(line.find_last_of('\"'),2); //Erases [",]
                    //cout << line << endl;
                    structureArray[arrayNumber - 1].data.d = line; //ArrayNumber-1 is to correct a bug in code
                    break;
                case 'z': // Detects if the 9th Element is z (i.e. Attribute is Z)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    line.erase((line.find("        \"z\": \"")), 14); // Deletes: ["z": ] (8 White Spaces)
                    line.erase(line.find_last_of('\"'),2); //Erases [",]
                    //cout << line << endl;
                    structureArray[arrayNumber - 1].data.z = line; //ArrayNumber-1 is to correct a bug in code
                    break;
                case 's': // Detects if the 9th Element is s (i.e. Attribute is S)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    for (int i = 0; i < 5; i++) {
                        int markedCharPosition = line.find_first_of(":s\","); // Position of Character to be deleted
                        line.erase(markedCharPosition, 1); // Deletes the Character
                        // cout << line << endl;
                    }
                    structureArray[arrayNumber - 1].data.s = stoi(line); //ArrayNumber-1 is to correct a bug in code
                    break;
                case 'e': // Detects if the 9th Element is e (i.e. Attribute is E)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    for (int i = 0; i < 5; i++) {
                        int markedCharPosition = line.find_first_of(":e\","); // Position of Character to be deleted
                        line.erase(markedCharPosition, 1); // Deletes the Character
                        // cout << line << endl;
                    }
                    structureArray[arrayNumber - 1].data.e = stoi(line); //ArrayNumber-1 is to correct a bug in code
                    break;
                case 'b': // Detects if the 9th Element is B (i.e. Attribute is B)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    line.erase((line.find("        \"b\": \"")), 14); // Deletes: ["b": ] (8 White Spaces)
                    line.erase(line.find_last_of('\"'),2); //Erases [",]
                    //cout << line << endl;
                    structureArray[arrayNumber - 1].data.b = line; //ArrayNumber-1 is to correct a bug in code
                    break;
                case 'p': // Detects if the 9th Element is P (i.e. Attribute is P)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    for (int i = 0; i < 5; i++) {
                        int markedCharPosition = line.find_first_of(":p\","); // Position of Character to be deleted
                        line.erase(markedCharPosition, 1); // Deletes the Character
                        //cout << line << endl;
                    }
                    structureArray[arrayNumber - 1].data.p = stoi(line); //ArrayNumber-1 is to correct a bug in code
                    break;
                case 'm': // Detects if the 9th Element is M (i.e. Attribute is M)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    if (line.find_first_of("0123456789") == -1) { // IF A NUMBER CAN'T BE FOUND
                        structureArray[arrayNumber - 1].data.m = 0;
                    } 
                    else {
                        for (int i = 0; i < 7; i++) {
                            int markedCharPosition = line.find_first_of(":m\","); // Position of Character to be deleted
                            line.erase(markedCharPosition, 1); // Deletes the Character
                            //cout << line << endl;
                        }
                        structureArray[arrayNumber - 1].data.m = stoi(line); //ArrayNumber-1 is to correct a bug in code
                    }
                    break;
                case 'x': // Detects if the 9th Element is X (i.e. Attribute is X)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    if (line.find_first_of("0123456789") == -1) { // IF A NUMBER CAN'T BE FOUND
                        structureArray[arrayNumber - 1].data.m = 0;
                    } 
                    else {
                        for (int i = 0; i < 7; i++) {
                            int markedCharPosition = line.find_first_of(":x\","); // Position of Character to be deleted
                            line.erase(markedCharPosition, 1); // Deletes the Character
                            //cout << line << endl;
                        }
                        //NOTE THAT STOD converts string to double
                        structureArray[arrayNumber - 1].data.x = stod(line); //ArrayNumber-1 is to correct a bug in code
                    }
                    break;
                case 'g': // Detects if the 9th Element is G (i.e. Attribute is G)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    line.erase((line.find("        \"g\": \"")), 14); // Deletes: ["g": ] (8 White Spaces)
                    line.erase(line.find_last_of('\"'),2); //Erases [",]
                    //cout << line << endl;
                    structureArray[arrayNumber - 1].data.g = line; //ArrayNumber-1 is to correct a bug in code
                    break;
                case 'w': // Detects if the 9th Element is W (i.e. Attribute is W)
                    //cout << line << endl; // THIS LINE IS TO BE USED FOR TESTING PURPOSES AND HAS NO REAL FUNCTION
                    if (line.find("false")!=-1){ //Detects if true has been found in the string
                        structureArray[arrayNumber - 1].data.w = false;
                    }
                    else if (line.find("true")!=-1){ //Detects if true has been found in the string
                        structureArray[arrayNumber - 1].data.w = true;
                    }
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
        cout << structureArray[i].name << endl;
        cout << structureArray[i].name << ":" <<" N: " << structureArray[i].data.n << endl;
        cout << structureArray[i].name << ":" <<" U: " << structureArray[i].data.u << endl;
        cout << structureArray[i].name << ":" << " T: " << structureArray[i].data.t << endl;
        cout << structureArray[i].name << ":" << " D: " << structureArray[i].data.d << endl;
        cout << structureArray[i].name << ":" << " Z: " << structureArray[i].data.z << endl; //SOME STRINGS ARE EMPTY
        cout << structureArray[i].name << ":" <<" S: " << structureArray[i].data.s << endl;
        cout << structureArray[i].name << ":" <<" E: " << structureArray[i].data.e << endl;
        cout << structureArray[i].name << ":" <<" B: " << structureArray[i].data.b << endl;
        cout << structureArray[i].name << ":" << " P: " << structureArray[i].data.p << endl;
        cout << structureArray[i].name << ":" << " M: " << structureArray[i].data.m << endl;
        cout << structureArray[i].name << ":" << " X: " << structureArray[i].data.x << endl;
        cout << structureArray[i].name << ":" << " G: " << structureArray[i].data.g << endl; //SOME STRINGS ARE EMPTY
        cout << structureArray[i].name << ":" << " W: " << structureArray[i].data.w << endl;
    }

    return 0;
}

