#include <iostream>
#include <cstring>
using namespace std;

// Эх класс — өөрчлөхгүй
class Animal {
protected:
    char name[20];
    int age;
public:
    Animal(const char* n, int a) {
        strcpy(name, n);
        age = a;
    }
    void showInfo() {
        cout << "name: " << name << ", age: " << age << endl;
    }
};

// Удамшсан шинэ класс — нэмэлт гишүүн өгөгдөлтэй
class Dog : public Animal {
private:
    char breed[30]; // Шинээр нэмсэн гишүүн өгөгдөл
// public горимоор удамшиж байгаа учраас эх классын public гишүүд мөн public аар удамшина. 
public:
    Dog(const char* n, int a, const char* b) : Animal(n, a) { // Эх классын constructor дуудаж байна
        strcpy(breed, b);
    }
// Эх классын функц ашиглаж байна, амьтны нэр насыг хэвлэх ба түүн дээр амьтны үүлдэр гэсэн гишүүн өгөгдлийг нэмж  оруулж байна
    void showDogInfo() {
        showInfo();  
        cout << "breed: " << breed << endl;
    }
};

int main() {
    Dog d1("kitty", 3, "German Shepherd");
    d1.showDogInfo();
    return 0;
}
