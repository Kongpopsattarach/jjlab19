#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> names,vector<int> scores,vector<char> grades){
    char name[100];
    char grade[5];
    int score;
    int a = 0;
    int b = 0;
    int c = 0;

    ifstream source;
    source.open("name_score.txt");
    string textline;
    while (getline(source,textline))
    {
        cout << textline << "\n";
        sscanf(textline.c_str(),"%[^:]:%d %d %d",name,&a,&b,&c);
        names.push_back(name);
        score = a+b+c;
        scores.push_back(score);
        grades.push_back(score2grade(score));
    }

    }
    

void getCommand(string command,string key){
    cout << "Please input your command: ";
    string text;
    char com[100];
    char keyword[100];
    getline(cin,text);
    sscanf(text.c_str(),"%s %[^:]",com,keyword);
    command = com;
    key = keyword;
    
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------\n";
    bool check = false;
    for(unsigned int i = 0;i < names.size();i++){
        if(key == toUpperStr(names[i])){
            cout << names[i] << "'s score = " << scores[i] << "\n";
            cout << names[i] << "'s grade = " << grades[i] << "\n";
            check = true;
        }
    }
    if(check == false){
    cout << "Cannot found."<< "\n";
    }
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------\n";
    for(unsigned int i = 0;i < names.size();i++){
        string y;
        y+= grades[i];
        if(key == y){
            cout << names[i] << " (" << scores[i] << ")" << "\n";
            
            
            }
    }
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
