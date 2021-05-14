

#ifndef BANKER_H
#define BANKER_H

#include <iostream>
#include <string>

using namespace std;


class Banker {
private :
    string position;
    string banker_name;
    int banker_age;
    string personal_num;
    string gender;
    string affiliation; // headquater, branch
    string join_date;
    pair<string, string> banker_account;


public :
    Banker(){
        this->position = "staff";
        this->banker_name = "john do";
        this->banker_age  = 0;
        this->personal_num = "920101-1111111";
        this->gender = "male";
        this->affiliation = "branch";
        this->join_date = "2000.01.01";
        this->banker_account = make_pair("staff_000101", "staff_920101");
    }
};


#endif