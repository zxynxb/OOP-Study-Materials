#include <iostream>
#include <string>
using namespace std;

class HeartRates {
private:
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    HeartRates(string first_name, string last_name, int birth_month, int birth_day, int birth_year) {
        firstName = first_name;
        lastName = last_name;
        birthMonth = birth_month;
        birthDay = birth_day;
        birthYear = birth_year;
    }

    void setFirstName(string first_name) {
        firstName = first_name;
    }

    void setLastName(string last_name) {
        lastName = last_name;
    }

    void setBirthMonth(int birth_month) {
        birthMonth = birth_month;
    }

    void setBirthDay(int birth_day) {
        birthDay = birth_day;
    }

    void setBirthYear(int birth_year) {
        birthYear = birth_year;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    int getBirthMonth() {
        return birthMonth;
    }

    int getBirthDay() {
        return birthDay;
    }

    int getBirthYear() {
        return birthYear;
    }

    int calculateAge() {
        int currentYear = 2024;
        int age = currentYear - birthYear;
        return age;
    }

    int calculateMaxHeartRate() {
        return 220 - calculateAge();
    }

    pair<int, int> calculateTargetHeartRate() {
        int max_heart_rate = calculateMaxHeartRate();
        int min_target_rate = max_heart_rate * 0.5;
        int max_target_rate = max_heart_rate * 0.85;
        return make_pair(min_target_rate, max_target_rate);
    }
};

int main() {
    string firstName, lastName;
    int birthMonth, birthDay, birthYear;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter birth month (1-12): ";
    cin >> birthMonth;
    cout << "Enter birth day: ";
    cin >> birthDay;
    cout << "Enter birth year: ";
    cin >> birthYear;

    HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);

    cout << "\nFirst Name: " << person.getFirstName() << endl;
    cout << "Last Name: " << person.getLastName() << endl;
    cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << endl;

    int age = person.calculateAge();
    cout << "Age: " << age << " years" << endl;

    int max_heart_rate = person.calculateMaxHeartRate();
    cout << "Maximum Heart Rate: " << max_heart_rate << " bpm" << endl;

    pair<int, int> target_heart_rate = person.calculateTargetHeartRate();
    cout << "Target Heart Rate Range: " << target_heart_rate.first << " - " << target_heart_rate.second << " bpm" << endl;

    return 0;
}
