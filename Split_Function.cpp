#include <iostream>

using namespace std;

bool isDelimeter(string del, char c){
    for(int i=0;i<del.length();i++){
        if(del[i] == c) return true;
    }

    return false;
}

int wordCount(string del, string toChange){

    int i=0;
    int wordCount = 0;
    bool cancelWordCountInc = false;

    while(i!=toChange.length()){

        if(isDelimeter(del,toChange[i])){
           cancelWordCountInc = false;
        }else if(!isDelimeter(del,toChange[i]) && cancelWordCountInc == false){
            wordCount++;
            cancelWordCountInc = true;
        }

        i++;
    }

    return wordCount;
}

string* split(string del, string toChange){

    int numberOfWords = wordCount(del,toChange);
    string* stringArray = new string[numberOfWords];
    string addingString = "";
    int counter = 0,i=0;

    while(i!=toChange.length()){

        if(isDelimeter(del,toChange[i]) && addingString!=""){
           stringArray[counter] = addingString;
           addingString = "";
           counter++;
        }else if(!isDelimeter(del,toChange[i])){
           addingString = addingString + toChange[i];
        }

        i++;

        if(addingString!="" && i == toChange.length()){
             stringArray[counter] = addingString;
             break;
        }
    }

    return stringArray;
}

int main()
{
    string str = "  DDThis..is    test.exampleDDD.,for.deleting . usingDDD delimeters..,Finish,..Of.The..Example,,";
    string del = " .D,";

    string* arrayOfWords = split(del,str);

    for(int i=0;i<wordCount(del,str);i++){
        cout << arrayOfWords[i] << endl;
    }

    return 0;
}
