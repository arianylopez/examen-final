#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

Date date;
map<string, set<string>> events; 

void add_event(map<string, set<string>>& events, const string& date_str, const string& event);

int main(){
    string operation;
    string date_str;
    string event;
    string error_msg;

    return 0;
}

void add_event(map<string, set<string>>& events, const string& date_str, const string& event){
    events[date_str].insert(event);
}