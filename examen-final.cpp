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
bool delete_event(map<string, set<string>>& events, const string& date_str, const string& event);

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

bool delete_event(map<string, set<string>>& events, const string& date_str, const string& event){
    if(events.count(date_str) && events[date_str].count(event)){
        events[date_str].erase(event);
        if(events[date_str].empty()){
            events.erase(date_str);
        }
        return true;
    }
    return false;
}