#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int passwd = 123;

struct Patient {
    int patientId;         // Patient ID
    string name;           // Patient name
    int age;
    string gender;
    string contact;
    double balance;
};
struct Doctor {
    int doc_id;           // Doctor ID
    string name;          // Doctor name
    string specialty;     // e.g., Cardiologist, ENT
    int experience;       // Years of experience
};
struct Appointment {
    int patientId;
    int doctorId;
    char date[11];        // e.g., "2026-03-30"
    char time [10];        // e.g., "10:00 AM"
};
struct Treatment {
    int patientId;
    string description; // Treatment details
    double cost;        // Cost of treatment
    bool paid;          // True if bill is paid
};

void addTreatment(Treatment t1);
void viewTreatment(ifstream &treatmentFile);
void updatePayment(ifstream &in, ofstream &out);
void generateBill(ifstream &in);



int main() {
    char option = 'y';
    int id, password;

    Treatment t1;
    ofstream treatmentOut("treatments.txt", ios::app);
    ifstream treatmentIn("treatments.txt");
    ofstream billOut("bills.txt", ios::app);
    ifstream billIn("bills.txt");
    
    cout<<"Enter User ID: "<<endl;
    cin>>id;
    cout<<"Welcome User: "<<id<<".\nEnter Password: ";
    cin>>password;

    if (password != passwd) {
        cout<<"!!!Invalid Password!!!. EXITING"<<endl;
        return 1;
    }

    while (option == 'y') {
        int select;
        cout<<"==========Welcome to hospital management system=========="<<endl;
        cout<<"1. Patient Management"<<endl;
        cout<<"2. Doctor Managent"<<endl;
        cout<<"3. Appointment Management"<<endl;
        cout<<"4. Treatments and Billings"<<endl;
        cout<<"5. Search / Reports"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl<<"Enter your option: "<<endl;
        cin>>select;

        switch(select) {
            case 4:
                int opt;
                cout<<endl<<"==========Treatment And Billing Management=========="<<endl;
                cout<<"1. Add Treatment Record for patient"<<endl;
                cout<<"2. View Treatments"<<endl;
                cout<<"3. Update Payment Status"<<endl;
                cout<<"4. Generate Bill"<<endl;
                cout<<endl<<"Enter Option: "<<endl;
                cin>>opt;
                switch(opt) {
                    case 1:
                        addTreatment(t1);
                        break;
                    case 2:
                        cout<<endl<<"==========View Treatments=========="<<endl;
                        viewTreatment(treatmentIn);
                        break;
                    case 3:
                        cout<<endl<<"==========Update Payment Status=========="<<endl;
                        updatePayment(billIn, billOut);
                        break;
                    case 4:
                        cout<<endl<<"==========Generate Bill=========="<<endl;
                        generateBill(billIn);
                        break;
                    default:
                        cout<<endl<<"Invalid option"<<endl;
                }
            break;

            case 6:
                cout<<endl<<"Exiting. The system"<<endl;
                return 2;
            default:
                cout<<endl<<"Invalid Option."<<endl;
        
        }
        cout<<"Do you want to Continue(y/n)? ";
        cin>>option;
    }

    return 0;
}

void addTreatment(Treatment t1) {
    cout<<endl<<"==========Add Treatment Records for Patient=========="<<endl;
    cout<<"Enter Patient Id to enter record: ";
    cin>>t1.patientId;
    cout<<"Enter Treatment details: ";
    getline(cin, t1.description);
    cout<<"Enter treatment Cost: ";
    cin>>t1.cost;
    cout<<"Is the bill paid(1 for yes, 0 for no)? ";
    cin>>t1.paid;
}

void viewTreatment(ifstream &treatmentFile) {

}

void updatePayment(ifstream &in, ofstream &out) {

}

void generateBill(ifstream &in) {

}
