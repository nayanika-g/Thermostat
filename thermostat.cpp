//
//  thermostat.cpp
//  Created by Grace Gupta on 7/12/18.
//  Copyright © 2018 Grace Gupta. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isDigitChar(char c);
int indexOfNextNonDigitChar(string commands, int i);
void updateIndexToNextNonDigitChar(string commands, string from_section, int& i);

bool isWellFormedThermostatString(string commands);
int temperature(string commands);
int setting(string commands);
bool isHeating(string commands);
bool isCooling(string commands);

void testone(int n)
{
    switch (n)
    {
        case  1:
            assert( !isWellFormedThermostatString( "" ) );
            break;
        case  2:
            assert( !isWellFormedThermostatString( " " ) );
            break;
        case  3:
            assert( !isWellFormedThermostatString( "12" ) );
            break;
        case  4:
            assert( !isWellFormedThermostatString( "ua12" ) );
            break;
        case  5:
            assert( !isWellFormedThermostatString( "T" ) );
            break;
        case  6:
            assert( !isWellFormedThermostatString( "t70z" ) );
            break;
        case  7:
            assert( !isWellFormedThermostatString( "t+70" ) );
            break;
        case  8:
            assert( !isWellFormedThermostatString( "t-70" ) );
            break;
        case  9:
            assert( !isWellFormedThermostatString( "T70H" ) );
            break;
        case 10:
            assert( !isWellFormedThermostatString( "T70Hc" ) );
            break;
        case 11:
            assert( !isWellFormedThermostatString( "t70h69x" ) );
            break;
        case 12:
            assert( !isWellFormedThermostatString( "t70h69+" ) );
            break;
        case 13:
            assert( !isWellFormedThermostatString( "t70h69-" ) );
            break;
        case 14:
            assert( !isWellFormedThermostatString( "t70h69    " ) );
            break;
        case 15:
            assert( !isWellFormedThermostatString( "t70h69+1_" ) );
            break;
        case 16:
            assert( !isWellFormedThermostatString( "t70c69+1-" ) );
            break;
        case 17:
            assert( !isWellFormedThermostatString( "t70c69x"));
            break;
        case 18:
            assert( !isWellFormedThermostatString( "t70c69+"));
            break;
        case 19:
            assert( !isWellFormedThermostatString( "t70c69-"));
            break;
        case 20:
            assert( !isWellFormedThermostatString( "t70c69    " ) );
            break;
        case 21:
            assert( !isWellFormedThermostatString( "t70c69+1_" ) );
            break;
        case 22:
            assert( !isWellFormedThermostatString( "t70c69+1-" ) );
            break;
        case 23:
            assert( !isWellFormedThermostatString( "t70c+69+1_" ) );
            break;
        case 24:
            assert( !isWellFormedThermostatString( "t70c+69+1-" ) );
            break;
        case 25:
            assert( !isWellFormedThermostatString( "t70c-69-1_" ) );
            break;
        case 26:
            assert( !isWellFormedThermostatString( "t70c-69-1-" ) );
            break;
        case 27:
            assert( !isWellFormedThermostatString( "t+70c-69-1-" ) );
            break;
        case 28:
            assert( !isWellFormedThermostatString( "t-70c-69-1-" ) );
            break;
        case 29:
            assert( !isWellFormedThermostatString( "t70c69-0" ) );
            break;
        case 30:
            assert( !isWellFormedThermostatString( "t70c69+0" ) );
            break;
        case 31:
            assert( !isWellFormedThermostatString( "t70c+69+1_45    " ) );
            break;
        case 32:
            assert( !isWellFormedThermostatString( "t70c+69+1-45    " ) );
            break;
        case 33:
            assert( !isWellFormedThermostatString( "t70c-69-1_45" ) );
            break;
        case 34:
            assert( !isWellFormedThermostatString( "t70c-69-1   " ) );
            break;
        case 35:
            assert( isWellFormedThermostatString( "T70" ) );
            break;
        case 36:
            assert( isWellFormedThermostatString( "t70" ) );
            break;
        case 37:
            assert( isWellFormedThermostatString( "t70h69" ) );
            break;
        case 38:
            assert( isWellFormedThermostatString( "t70h69+1" ) );
            break;
        case 39:
            assert( isWellFormedThermostatString( "t70h69-1" ) );
            break;
        case 40:
            assert( isWellFormedThermostatString( "t70h69-1+1" ) );
            break;
        case 41:
            assert( isWellFormedThermostatString( "t70c69" ) );
            break;
        case 42:
            assert( isWellFormedThermostatString( "t70c69+1" ) );
            break;
        case 43:
            assert( isWellFormedThermostatString( "t70c69-1" ) );
            break;
            
        case 44:
            assert( isWellFormedThermostatString( "t70c69-1+1" ) );
            break;
        case 45:
            assert( setting( "t70c+69+1-" ) == -1 );
            break;
        case 46:
            assert( setting( "t70c-69-1_" ) == -1 );
            break;
        case 47:
            assert( setting( "t70c-69-1-" ) == -1 );
            break;
        case 48:
            assert( setting( "T70" ) == 0 );
            break;
        case 49:
            assert( setting( "t70" ) == 0 );
            break;
        case 50:
            assert( setting( "t70h69" ) == 69 );
            break;
        case 51:
            assert( setting( "t70h69+1" ) == 70 );
            break;
        case 52:
            assert( setting( "t70h69-1" ) == 68 );
            break;
        case 53:
            assert( setting( "t70h69-1+1" ) == 69 );
            break;
        case 54:
            assert( setting( "t70c69" ) == 69 );
            break;
        case 55:
            assert( setting( "t70c69+1" ) == 70 );
            break;
        case 56:
            assert( setting( "t70c69-1" ) == 68 );
            break;
        case 57:
            assert( setting( "t70c69-1+1" ) == 69 );
            break;
        case 58:
            assert( temperature( "t70c+69+1-" ) == -1 );
            break;
        case 59:
            assert( temperature( "t70c-69-1_" ) == -1 );
            break;
        case 60:
            assert( temperature( "T70" ) == 70 );
            break;
        case 61:
            assert( temperature( "t70" ) == 70 );
            break;
        case 62:
            assert( temperature( "t70h69" ) == 70 );
            break;
        case 63:
            assert( temperature( "t70h69+1" ) == 70 );
            break;
        case 64:
            assert( temperature( "t70h69-1" ) == 70 );
            break;
        case 65:
            assert( temperature( "t70c69" ) == 70 );
            break;
        case 66:
            assert( temperature( "t70c69+1" ) == 70 );
            break;
        case 67:
            assert( temperature( "t70c69-1+1" ) == 70 );
            break;
        case 68:
            assert( !isCooling( "t70c+69+1-" ) );
            break;
        case 69:
            assert( !isCooling( "T70" ) );
            break;
        case 70:
            assert( !isCooling( "t70h69" ) );
            break;
        case 71:
            assert( !isCooling( "t70h69+1" ) );
            break;
        case 72:
            assert( !isCooling( "t70h69-1" ) );
            break;
        case 73:
            assert( !isCooling( "t70h69-1+1" ) );
            break;
        case 74:
            assert( isCooling( "t70c69" ) );
            break;
        case 75:
            assert( !isCooling( "t70c69+1" ) );
            break;
        case 76:
            assert( isCooling( "t70c69-1" ) );
            break;
        case 77:
            assert( isCooling( "t70c69-1+1" ) );
            break;
        case 78:
            assert( !isHeating( "t70c+69+1-" ) );
            break;
        case 79:
            assert( !isHeating( "T70" ) );
            break;
        case 80:
            assert( !isHeating( "t70h69" ) );
            break;
        case 81:
            assert( isHeating( "t68h69+1" ) );
            break;
        case 82:
            assert( isHeating( "t67h69-1" ) );
            break;
        case 83:
            assert( isHeating( "t68h69-1+1" ) );
            break;
        case 84:
            assert( !isHeating( "t70c69" ) );
            break;
        case 85:
            assert( !isHeating( "t70c69+1" ) );
            break;
        case 86:
            assert( !isHeating( "t70c69-1" ) );
            break;
        case 87:
            assert( !isHeating( "t70c69-1+1" ) );
            break;
            
        default:
            cout << "Bad argument" << endl;
            break;
    }
}


int main() {
    
    for(int n = 1; n < 88; n++) {
        
        testone(n);
            
    }
    
    cout << "Passed tests!" << endl;

}

//  returns true if thermostat string is well formed
bool isWellFormedThermostatString(string commands) {
    
    //  if string length < 2, return false
    if(commands.length() < 2) {
        return false;
    }
    
    //  if first character is not 'T' or 't', return false
    if(commands[0] != 'T' && commands[0] != 't') {
        return false;
    }
    
    //  if last character is not '0'-'9', return false
    if(!isDigitChar(commands[commands.length()-1])) {
        return false;
    }
    
    for(int i = 0; i < commands.length(); i++) {
        
        char c = commands[i];
        
        //  if not a valid letter, symbol, or digit character, return false
        if((c != 't' && c != 'T' && c != 'c' && c != 'C' && c != 'h'
            && c != 'H' && c != '+' && c != '-') && !(isDigitChar(c))) {
            
            return false;
        }
        
        //if a letter or symbol character is not immediately followed by a digit, return false
        if((c == 't' || c == 'T' || c == 'c' || c == 'C' || c == 'h'
            || c == 'H' || c == '+' || c == '-')) {
            
            char next = commands[i+1];
            
            //if +/- is followed by a '0', return false
            if(((c == '+') || (c == '-')) && (!isDigitChar(next) || next == '0')) {
                return false;
            }
            
            if( !(isDigitChar(next))) {
                return false;
            }
            
        }
        
        //  the next non-digit character after the current temp command must be 'c'/'C'/'h'/'H'
        if(c == 't' || c == 'T') {
            
            updateIndexToNextNonDigitChar(commands, "current", i);
        }
        
        //  the next non-digit character after the setting temp command must be '+'/'-'
        else if(c == 'c' || c == 'C' || c == 'h' || c == 'H') {
            
            updateIndexToNextNonDigitChar(commands, "setting", i);
        }
        
        // the next non-digit character after the adjusted temp command must be '+'/'-'
        else if(c == '+' || c == '-') {
            
            updateIndexToNextNonDigitChar(commands, "adjust", i);
        }
        
        //  if any of the above checks is false, break out of the loop and return false
        if(i == -1) {  return false;  }
        
        //  checks if it is the end of the string
        if(i == -2) {   break;  }
        
    }
    
    return true;
    
}

// returns true if character is a digit character
bool isDigitChar(char c) {
    
    if(c >= '0' && c <= '9') {  return true;  }
    
    return false;
    
}

/**
 *  returns index of next non digit character, -1 if end of string
 */
int indexOfNextNonDigitChar(string commands, int i) {
    
    //skips over digit characters between the original and the next non-digit character
    int j = i+1;
    
    while((j < commands.length()) && (isDigitChar(commands[j]))) {
        j++;
    }
    
    if(j == commands.length()) {    return -1;  }
    
    else {  return j;   }
    
}
/**
 *  updates the index tracking the position within the string (i) to the next
 *  non-digit character if the next non-digit character is valid
 *  i = -1 if invalid, i = -2 if end of string
 */
void updateIndexToNextNonDigitChar(string commands, string from_section, int& i) {
    
    int j = indexOfNextNonDigitChar(commands, i);
    
    if(j == -1) {  i = -2; return; }
    
    if(from_section == "current") {
        
        if((commands[j] != 'C') && (commands[j] != 'c') && (commands[j] != 'h')
           && (commands[j] != 'H')) {   i = -1; return;   }
        
    }
    else if(from_section == "setting") {
        
        if((commands[j] != '+') && (commands[j] != '-')) {  i = -1; return; }
        
    }
    
    else if(from_section == "adjust") {
        
        if((commands[j] != '+') && (commands[j] != '-')) {  i = -1; return; }
    }
    
    i = j-1;
    
    return;
}

//  returns the current temperature if the string is well-formed, -1 if not
int temperature(string commands) {
    
    int t = 0;
    
    if(isWellFormedThermostatString(commands)) {
        
        int i = 1;
        
        //extract current temperature
        
        while((i < commands.length()) && ((commands[i] != 'c') && (commands[i] != 'C') &&
            (commands[i] != 'h') && (commands[i] != 'H')))
        {
            
            int d = commands[i] - '0';
            
            t = (t * 10) + d;
            
            i++;
            
        }
        
        return t;
        
    }
    
    else {  return -1;  }
    
}

//  returns the setting temperature if the string is well-formed, -1 if not
int setting(string commands) {
    
    int t = 0;
    
    if(isWellFormedThermostatString(commands)) {
        
        //extract setting temperature before adjustments
        
        int i = indexOfNextNonDigitChar(commands, 0);
        
        if(i == -1) { return 0; }
        
        i++;
        
        while((i < commands.length()) && ((commands[i] != '+') && (commands[i] != '-'))) {
            
            int d = commands[i] - '0';
            
            t = (t * 10) + d;
            
            i++;
            
        }
        
        //  include adjustments to the setting temperature
        
        while(i < commands.length()) {
            
            //determine whether the adjust command is to add or subtract
            
            bool add(false);
            
            if(commands[i] == '+') {  add = true; }
            
            //extract adjust number
            i++;
            
            int j = 0;
            
            while((i < commands.length()) && (isDigitChar(commands[i]))) {
                
                int d = (commands[i] - '0');
                
                j = (j * 10) + d;
                
                i++;
                
            }
            
            if(add == true) {   t += j; }   //add adjust number to setting temp
            
            else {  t -= j; }               //subtract adjust number from setting temp
            
        }
        
        return t;
        
    }
    
    else {  return -1;  }
    
}

//returns true if heating
bool isHeating(string commands) {
    
    bool isHeatingDesired(false);       // true if 'h' or 'H' found in well formed thermostat string
    
    if(isWellFormedThermostatString(commands)) {
        
        for (int i = 0; i < commands.length(); i++) {
            
            if(commands[i] == 'h' || commands[i] == 'H')    {  isHeatingDesired = true;}
            
        }
        
        //if heating desired, if current temperature < setting temperature, it is heating
        
        if(isHeatingDesired == true) {
            
            if(temperature(commands) < setting(commands)) {  return true; }
            
        }
        else {  return false;  }
        
    }
    
    return false;
    
}

//returns true if cooling
bool isCooling(string commands) {
    
    bool isCoolingDesired(false);      // true if 'c' or 'C' found in well formed thermostat string
    
    if(isWellFormedThermostatString(commands)) {
        
        for (int i = 0; i < commands.length(); i++) {
            
            if(commands[i] == 'c' || commands[i] == 'C') {  isCoolingDesired = true; }
            
        }
        
        //if cooling desired, if current temperature > setting temperature, it is cooling
        if(isCoolingDesired == true) {
            
            if(temperature(commands) > setting(commands)) { return true; }
            
        }
        else {  return false; }
        
    }
    
    return false;
    
}

