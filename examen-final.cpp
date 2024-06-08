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
bool validate_date(const string& date_str, string& error_msg);
int delete_date(map<string, set<string>>& events, const string& date_str);
set<string> find(map<string, set<string>>& events, const string& date_str);
void print_events();

int main(){
    string operation;
    string date_str;
    string event;
    string error_msg;

    while(cin>>operation){
        if(operation=="Add"){
            cin>>date_str>>event;
            if(validate_date(date_str, error_msg)){
                add_event(events, date_str, event);
            } else{
                cout<<error_msg<<endl;
            }
        } else if(operation=="Del"){
            cin>>date_str>>event;
            if(validate_date(date_str, error_msg)){
                if(event.empty()){
                    cout<<"Deleted "<<delete_date(events, date_str)<<" events"<<endl;
                } else{
                    if(delete_event(events, date_str, event)){
                        cout<<"Deleted successfully"<<endl;
                    } else{
                        cout<<"Event not found"<<endl;
                    }
                }
            } else{
                cout<<error_msg<<endl;
            }
        } else if(operation=="Find"){
            cin>>date_str;
            if(validate_date(date_str, error_msg)){
                set<string> events_found=find(events, date_str);
                for(const auto& event:events_found){
                    cout<<event<<endl;
                }
            } else{
                cout<<error_msg<<endl;
            }
        }
    }
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

bool validate_date(const string& date_str, string& error_msg){
    vector<int> date_parts;
    string part;

    for(char c : date_str){
        if(c=='-'){
            date_parts.push_back(stoi(part));
            part.clear();
        } else{
            part += c;
        }
    }
    date_parts.push_back(stoi(part));

    if(date_parts.size() != 3){
        error_msg="Wrong date format: " + date_str;
        return false;
    }

    date.year=date_parts[0];
    date.month=date_parts[1];
    date.day=date_parts[2];

    if(date.month<1 || date.month>12){
        error_msg="Month value is invalid" + to_string(date.month);
        return false;
    }

    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(date.day<1 || date.day>days_in_month[date.month - 1]){
        error_msg = "Day value is invalid: " + to_string(date.day);
        return false;
    }
    return true;
}

int delete_date(map<string, set<string>>& events, const string& date_str){
    if(events.count(date_str)){
        int count=events[date_str].size();
        events.erase(date_str);
        return count;
    }
    return 0;
}

set<string> find(map<string, set<string>>& events, const string& date_str){
    if(events.count(date_str)){
        return events[date_str];
    } else{
        return {};
    }
}

void print_events(){
    for(const auto& item:events){
        for(const auto& event:item.second){
            string date=item.first;
            vector<int> date_parts;
            string part;

            for(char c:date){
                if(c=='-'){
                    date_parts.push_back(stoi(part));
                    part.clear();
                } else{
                    part+=c;
                }
            }
            date_parts.push_back(stoi(part));

            int year=date_parts[0];
            int month=date_parts[1];
            int day=date_parts[2];

            cout<<(year<1000 ? "0":"")<<(year<100 ? "0" : "")
            <<(year<10 ? "0" : "")<<year<<'-'
            <<(month<10 ? "0" : "")<<month<<'-'
            <<(day<10 ? "0" : "")<<day<<' '
            <<event<<endl;
        }
    }
}