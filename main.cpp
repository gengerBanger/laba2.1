#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
struct student{
    string FullName;
    char Sex;
    short int GroupNum;
    short int numInGroup;
    short int Session[8];
};
bool numCheck(int x){
    return (x > 0) && (x <= 30);
}
bool gradeCheck(int x){
    return (x >= 3) && (x <= 5);
}
bool sexCheck(char x){
    return (x == 'M') || (x == 'W');
}
bool groupCheck(int x){
    return (x >= 0) && (x < 10000);
}
void dottedLine(){
    cout <<'\n'<<"---------------------------------------------------------------------------------------------------------------------"<<'\n';
}
int countStd(){
    ifstream database;
    database.open(R"(C:\\Users\\aleks\\CLionProjects\\laba2.1\\students.txt)");
    if (database.is_open())
    {
        int temp = 0;
        string data;
        while (!database.eof())
        {
            getline(database, data,'\n');
            temp++;
        }
        database.close();
        int n;
        n = temp / 13 + 1;
        return n;
    }
    else return 0;
}
void stdOutFile(student *p, int n,int len){
    student *begin = p;
    ifstream database;
    database.open(R"(C:\\Users\\aleks\\CLionProjects\\laba2.1\\students.txt)");
    for(;p < begin + n; p++){
        getline(database,p->FullName, '\n');
        /*while(p->FullName == ""){
            getline(database,p->FullName, '\n');
        }*/
        if(p->FullName == ""){
            getline(database,p->FullName, '\n');
        }
        if(p->FullName == ""){
            getline(database,p->FullName, '\n');
        }
        database >> p->Sex >> p->GroupNum >> p->numInGroup;
        for(int i = 0; i < len; i++){
            database >> p->Session[i];
        }
    }
    database.close();
}
void stdInFile(string *p,int len){
    string *pSub = p;
    bool key;
    student newStud{};
    student *p_1 = &newStud;
    while(cin.get() != '\n');
    cout << "enter full name ";
    getline(cin,newStud.FullName);
    cout << "\nenter sex ";
    cin >> newStud.Sex;
    while(!sexCheck(newStud.Sex)){
        cout <<'\t'<<'\t'<< "Invalid data, try again" <<'\n' <<'\n';
        cout << "\nenter sex ";
        cin >> newStud.Sex;
    }
    cout << "\nenter group number " ;
    cin >> newStud.GroupNum;
    while(!groupCheck(newStud.GroupNum)){
        cout <<'\t'<<'\t'<< "Invalid data, try again" <<'\n' <<'\n';
        cout << "\nenter group number " ;
        cin >> newStud.GroupNum;
    }
    cout << "\nenter number in group ";
    cin >> newStud.numInGroup;
    while(!numCheck(newStud.numInGroup)){
        cout <<'\t'<<'\t'<< "Invalid data, try again" <<'\n' <<'\n';
        cout << "\nenter number in group ";
        cin >> newStud.numInGroup;
    }
    for (int i = 0; i < len; i++, pSub++){
        cout << "enter "<< *pSub <<' ';
        cin >> newStud.Session[i];
        while(!gradeCheck(newStud.Session[i])){
            cout <<'\t'<<'\t'<< "Invalid data, try again" <<'\n' <<'\n';
            cout << "enter "<< *pSub <<' ';
            cin >> newStud.Session[i];
        }
    }
    ofstream database;
    database.open(R"(C:\\Users\\aleks\\CLionProjects\\laba2.1\\students.txt)", ios::app);
    database << newStud.FullName << '\n'<< newStud.Sex << '\n'<< newStud.GroupNum << '\n'
                << newStud.numInGroup << '\n';
    for(int i = 0; i < len; i++) {
        database << newStud.Session[i] << '\n';
    }
    database << '\n';
    database.close();
    cout << "\t\tDo you want to enter data for a new student?\n1)Yes\n0)No\n";
    cin >> key;
    if (key) stdInFile(p,len);
 }
void StdOutCon(student *p, int n, string *k, int len){
    student *beginStd = p;
    string *beginSes = k;
    for(; p < beginStd + n; p++){
        cout << "Full name : " << p->FullName << '\n';
        cout << "Sex : " << p->Sex << '\n';
        cout << "Group number : " << p->GroupNum<< '\n';
        cout << "Number in group : " << p->numInGroup<< '\n';
        for(int i = 0; i < len; i++, k++){
            cout << *k <<" : "<< p->Session[i] << " ";
        }
        cout << '\n' <<'\n'<<'\n';
        k = beginSes;
    }
}
void StdInfChange(student *p, int n, string *k,int len){
    student *beginStd = p, *CheckResult;
    string Name;
    bool check = false, key_1;
    int key;
    while(cin.get() != '\n');
    cout << "Enter the name of student whose information you want to change"<<'\n';
    getline(cin,Name,'\n');
    for (; p < beginStd + n; p++){
        if(p->FullName == Name)
        {
            CheckResult = p;
            check = true;
            break;
        }
    }
    if(check){
        cout <<'\n'<<'\n';
        StdOutCon(CheckResult, 1,k, len);
        cout << "Enter number of information which you want to change"<<'\n';
        cout <<"1) Full name" << '\n'<<"2) Sex" << '\n'<<"3) Group number" << '\n'<<"4) Number in group" << '\n';
        cout <<"5) fizika" << '\n'<<"6) filosofiya" << '\n'<<"7) fizkultura" << '\n'<<"8) informatica" << '\n'
                <<"9) programmirovanie" << '\n'<<"10) angliyskiy" << '\n'<<"11) albebra" << '\n'<<"12) matbanan" << '\n';
        cin >> key;
        while(cin.get() != '\n');
        if (key >= 1 && key <= 4){
            switch (key) {
                case 1:
                    cout << "Enter new name"<<'\n';
                    getline(cin, CheckResult ->FullName,'\n');
                    break;
                case 2:
                    cout << "Enter new sex" <<'\n';
                    CheckResult ->Sex = getchar();
                    break;
                case 3:
                    cout << "Enter new group number" <<'\n';
                    cin >> CheckResult->GroupNum;
                    break;
                case 4:
                    cout << "Enter new number in group" <<'\n';
                    cin >> CheckResult->numInGroup;
                    break;
            }
        }
        else{
            cout <<"Enter new grade of "<< *(k + (key - 5))<<'\n';
            cin >> CheckResult->Session[key - 5];
        }
        cout << '\n';
        StdOutCon(CheckResult, 1, k, len);
    }
    else cout <<"\tStudent not found\n";
    cout << "\t\tDo you want to change information of student?\n1)Yes\n0)No\n";
    cin >> key_1;
    if (key_1) StdInfChange(beginStd, countStd(), k, len);
}
void GroupSearch(student *p, int n, string *k, int len){
    student *beginStd = p;
    vector<student *> UserGroup;
    int Group;
    cout << "Enter the number of group"<<'\n';
    cin >> Group;
    for (;p < beginStd + n; p++){
        if (p->GroupNum == Group){
            UserGroup.push_back(p);
        }
    }
    if(!UserGroup.empty()){
        for( student * j : UserGroup){
            StdOutCon(j,1,k,len);
        }
    }
    else cout <<"Group not found";
}
float AverageValue(student *p, int len){
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += p->Session[i];
    }
    return float(sum) / len;
}
void TopValue(student *p, int n, int len){
    student *beginStd = p;
    multimap <float, string> Top;
    for(; p < beginStd + n; p++){
        Top.emplace(AverageValue(p,len),p->FullName);
    }
    cout <<"Rating :"<<'\n';
    multimap <float, string> :: reverse_iterator iter = Top.rbegin();
    for(int i = 1; iter != Top.rend(); iter++, i++){
        cout <<'\t' << i <<')'<<' '<< iter->second<<"   "<<iter->first <<'\n';
    }
}
void SortingByGender(student *p, int n, string *k,int len){
    vector <student *> mGender;
    vector <student *> wGender;
    for(student *begin = p; p < begin + n; p++){
        if (p->Sex == 'M') mGender.push_back(p);
        else wGender.push_back(p);
    }
    cout <<'\t'<< "Number of male students = "<< mGender.size() <<'\n'<<'\n';
    cout <<'\t'<< "Number of female students = "<< wGender.size() <<'\n'<<'\n';
}
void SortingByPerfomance(student *p, int n, string *k,int len){
    vector <student *> Grade_3;
    vector <student *> Grade_4;
    vector <student *> Grade_5;
    for(student *begin = p; p < begin + n; p++){
        bool flag_3 = false, flag_4 = false;
        for(int i = 0; i < len; i++){
            if (p->Session[i] == 3) {
                flag_3 = true;
                break;
            }
            if (p->Session[i] == 4){
                flag_4 = true;
            }
        }
        if((!flag_3) && (!flag_4)) Grade_5.push_back(p);
        else{
            if((!flag_3) && flag_4) Grade_4.push_back(p);
            else
                Grade_3.push_back(p);
        }
    }
    cout <<'\t'<<'\t' << "Students which got only 5s" <<'\n'<<'\n';
    for(student * j : Grade_5){
        StdOutCon(j,1,k,len);
    }
    cout <<'\t'<<'\t' << "Students which got 4s and 5s" <<'\n'<<'\n';
    for(student * j : Grade_4){
        StdOutCon(j,1,k,len);
    }
    cout <<'\t'<<'\t' << "Students which did not get scholarship" <<'\n'<<'\n';
    for(student * j : Grade_3){
        StdOutCon(j,1,k,len);
    }
}
void InfByNumber(student *p, int n, string *k,int len){
    short int Number;
    vector <student *> NumList;
    cout <<'\t'<<'\t'<< "Enter the number in group"<<'\n'<<'\n';
    cin >> Number;
    while(!numCheck(Number)){
        cout <<'\t'<<'\t'<< "This number cannot be, enter again"<<'\n'<<'\n';
        cin >> Number;
    }
    for(student * begin = p; p < begin + n; p++){
        if (p->numInGroup == Number) NumList.push_back(p);
    }
    if(!NumList.empty()){
        cout << "Students with number " << Number <<" :"<<'\n'<<'\n';
        for(student * j : NumList){
            StdOutCon(j,1,k,len);
        }
    }
    else cout <<'\t'<<'\t'<< "No students with this number were found"<<'\n'<<'\n';

}
int main(){
    const int x = 100, y = 8;
    bool key;
    student StArr[x];
    string subjects[y] = {"fizika", "filosofiya", "fizkultura","informatica","programmirovanie","angliyskiy","albebra","matbanan"};
    stdOutFile(StArr,countStd(),y);
    cout << "\t\tDo you want to enter data for a new student?\n1)Yes\n0)No\n";
    cin >> key;
    if (key) stdInFile(subjects, y);
    dottedLine();

    stdOutFile(StArr,countStd(),y);
    StdOutCon(StArr,countStd(),subjects,y);
    dottedLine();

    while(cin.get() != '\n');
    cout << "\t\tDo you want to change information of student?\n1)Yes\n0)No\n";
    cin >> key;
    if (key )StdInfChange(StArr, countStd(), subjects, y);
    dottedLine();

    while(cin.get() != '\n');
    GroupSearch(StArr,countStd(),subjects, y);
    dottedLine();
    cin.get();

    while(cin.get() != '\n');
    TopValue(StArr,countStd(),y);
    dottedLine();
    cin.get();

    SortingByGender(StArr,countStd(),subjects, y);
    dottedLine();
    cin.get();

    SortingByPerfomance(StArr,countStd(),subjects, y);
    dottedLine();

    while(cin.get() != '\n');
    InfByNumber(StArr,countStd(),subjects, y);
    dottedLine();

    system("pause");
    return 0;
}
