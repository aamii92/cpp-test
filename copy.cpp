#include<iostream>
#include<cstring>
using namespace std;

class employee {
private:
    int n;
    char *name;
    char *position;
    float work_hour;

public:
    employee() {
        n = 0;
        name = new char[1]; name[0] = '\0';
        position = new char[1]; position[0] = '\0';
        work_hour = 0;
    }

    employee(int a, const char *x, const char *y, float b) {
        n = a;
        name = new char[strlen(x)+1];
        strcpy(name, x);
        position = new char[strlen(y)+1];
        strcpy(position, y);
        work_hour = b;
    }

    void copy(const employee &s) {
        if(this != &s) {
            delete[] name;
            delete[] position;
            n = s.n;
            name = new char[strlen(s.name)+1];
            strcpy(name, s.name);
            position = new char[strlen(s.position)+1];
            strcpy(position, s.position);
            work_hour = s.work_hour;
        }
    }

    ~employee() {
        delete[] name;
        delete[] position;
        cout << "\nobject emp" << n << " is destroyed";
        
    }

    void showdata() {
        cout << " dugaar:" << n;
        cout << "\n ajilltnii ner: " << name;
        cout << "\n alban tushaal: " << position;
        cout << "\n ajilsan tsag: " << work_hour << endl;
    }

    char* get_name() { return name; }
    
};



int main() {
    employee empl1(1, "dorjnamaahai", "zahiral", 8);
    employee empl2(2, "bat", "ajiltan", 6);
    employee empl3(3, "gereltuy", "ajiltan", 7);
    employee empl4(4, "saraan", "menejer", 9);

    // нэрээр эрэмбэлэх
    employee *emp[4];
    emp[0]=&empl1;
    emp[1]=&empl2;
    emp[2]=&empl3;
    emp[3]=&empl4;
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<4; j++) {
            if(strcmp(emp[i]->get_name(), emp[j]->get_name())>0) {
                employee *temp;
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
    }

    cout << "\n haygaar eremblsen \n" << endl;
    for(int i=0; i<4; i++) {
        emp[i]->showdata();
    }
}
