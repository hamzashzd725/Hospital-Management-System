#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

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

void scheduleAppointment();
void cancelAppointment();
void addPatient();
void addDoctor();
void updatePatient(ifstream &inFile);
void updateDoctor(ifstream &inFile);
void deletePatient();
void deleteDoctor();
void viewPatients(ifstream &inFile);
void viewDoctors(ifstream &inFile);
void addTreatment(Treatment t1);
void viewTreatment(ifstream &treatmentFile);
void updatePayment(ifstream &in, ofstream &out);
void generateBill(ifstream &in);
void searchDoctorBySpecialty();
void searchPatientBydoc_ID();
void viewTreatmentsByDoctor();
void sortDoctorsByExperience();
void viewAppointments();
void cleanFile();
void removeDuplicatePatients();
void cleanDoctor(ifstream &inFile);
void cleanPatient(ifstream &inFile);
void cleanAppoitment(ifstream &inFile);
void cleanTreatment(ifstream &inFile);
bool isValidRecord(int count, string line);

int main() {
    char option = 'y';
    int id, password;

    Treatment t1;
    Patient p1;
    Doctor d1;
    cleanFile();
    ofstream treatmentOut("treatments.txt", ios::app);
    ifstream treatmentIn("treatments.txt");
    
    ofstream billOut("bills.txt", ios::app);
    ifstream billIn("bills.txt");

    ifstream patientIn("patients.txt");
    ofstream patientOut("patients.txt", ios::app);
    
    ifstream doctorIn("doctors.txt");
    ofstream doctorOut("doctors.txt", ios::app);

    cout<<"Enter User ID: ";
    cin>>id;
    cout<<"==========Welcome User "<<id<<"==========\nEnter Password: ";
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
        cout<<endl<<"Enter your option: ";
        cin>>select;

        switch(select) {
            case 1:
                cout<<endl<< "==========Patient Management=========="<<endl;
                cout<<"1. Add Patient"<<endl;
                cout<<"2. Update Patient"<<endl;
                cout << "3. Delete Patient"<<endl;
                cout << "4. View Patients"<<endl;
                cout<<"Enter option: ";
                int choicep;
                cin >> choicep;
                if (choicep==1) {
                    addPatient();
                }
            
                else if (choicep==2) {
                    updatePatient(patientIn); 
                }
            
                else if (choicep==3) {
                    deletePatient();
                }
                
                else if (choicep==4) {
                    viewPatients(patientIn);
                }
                else {
                    cout << "Invalid choice";
                }
                break;
                
            case 2:
                cout<<endl<< "==========Doctor Management=========="<<endl;
                cout << "1. Add Doctor"<<endl;
                cout << "2. Update Doctor"<<endl;
                cout << "3. Delete Doctor"<<endl;
                cout << "4. View All Doctors"<<endl;
                int choiced;
                cout<<"Enter Option: ";
                cin>>choiced;
                if(choiced== 1) {
                    addDoctor();
                }
                
                else if(choiced== 2) {
                    updateDoctor(doctorIn);
                }
                
                else if(choiced== 3) {
                    deleteDoctor();
                }
                
                else if(choiced== 4) {
                    viewDoctors(doctorIn);
                }
                
                else {
                    cout<<"Invalid choice"<<endl;
                }
                break;
                
            case 3:
                cout<<endl<< "==========Appointments=========="<<endl;
                cout<< "1. View Appointments"<<endl;
                cout<< "2. Schedule Appointments"<<endl;
                cout<< "3. Cancel Appointments"<<endl;
                cout<<"Enter Option: ";
                int choicea;
                cin>>choicea;
                
                if(choicea== 1)
                {
                    viewAppointments();
                }
            
                else if(choicea== 2)
                {
                    scheduleAppointment(); 
                }
            
                else if(choicea== 3)
                {
                    cancelAppointment();
                }
                else
                {
                    cout<<"Invalid choice"<<endl;
                    return 0;
                }
                
                break;
            case 4:
                int opt;
                cout<<endl<<"==========Treatment And Billing Management=========="<<endl;
                cout<<"1. Add Treatment Record for patient"<<endl;
                cout<<"2. View Treatments"<<endl;
                cout<<"3. Update Payment Status"<<endl;
                cout<<"4. Generate Bill"<<endl;
                cout<<endl<<"Enter Option: ";
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
            case 5:
                cout<<endl<<"==========Search And Reports=========="<<endl;
                cout<<endl<<"1. Search Patient"<<endl;
                cout<<endl<<"2. Search Doctor"<<endl;
                cout<<endl<<"3. Search Treatments provided by a doctor"<<endl;
                cout<<endl<<"4. Generate Bills/Report"<<endl;
                cout<<endl<<"5. Sort all doctors by years of experience"<<endl;
                cout<<endl<<"Enter Option: ";
                cin>>opt;
                switch(opt) {
                    case 1:
                        int o;
                        cout<<endl<<"==========Search Patient=========="<<endl;
                        cout<<endl<<"1. Search by Patient ID "<<endl;
                        cout<<endl<<"2. Search by Patient Name"<<endl;
                        cout<<endl<<"Enter Your Choice: ";
                        cin>>o;

                        if (o ==  1) {
                                cout<<endl<<"==========Enter Patient ID=========="<<endl;
                                int id;
                                bool found = false;
                                cout<<endl<<"Enter Patient ID: ";
                                cin>>id;
                                while(patientIn>>p1.patientId>>p1.name>>p1.age>>p1.gender>>p1.contact) {
                                    if (p1.patientId == id) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found == true) {
                                    cout<<endl<<"Patient Found!!"<<endl;
                                    cout<<"Patient Details: "<<endl;
                                    cout<<"Patient ID: "<<p1.patientId<<endl;
                                    cout<<"Patient Name: "<<p1.name<<endl;
                                    cout<<"Patient Age: "<<p1.age<<endl;
                                    cout<<"Patient Gender: "<<p1.gender<<endl;
                                    cout<<"Patient Contact: "<<p1.contact<<endl;
                                }
                                else if (found == false) {
                                    cout<<endl<<"Patient Not Found"<<endl;
                                }
                        }
                        else if(o == 2) { 
                                cout<<endl<<"==========Enter Patient Name=========="<<endl;
                                string name;
                                bool found = false;
                                cout<<endl<<"Enter Patient ID: ";
                                getline(cin, name);
                                while(patientIn>>p1.patientId>>p1.name>>p1.age>>p1.gender>>p1.contact) {
                                    if (p1.name == name) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found == true) {
                                    cout<<endl<<"Patient Found!!"<<endl;
                                    cout<<"Patient Details: "<<endl;
                                    cout<<"Patient ID: "<<p1.patientId<<endl;
                                    cout<<"Patient Name: "<<p1.name<<endl;
                                    cout<<"Patient Age: "<<p1.age<<endl;
                                    cout<<"Patient Gender: "<<p1.gender<<endl;
                                    cout<<"Patient Contact: "<<p1.contact<<endl;
                                }
                                else if (found == false) {
                                    cout<<endl<<"Patient Not Found"<<endl;
                                }
                        }
                        else {
                                cout<<endl<<"Invalid Option"<<endl;
                        } 
                        break;
                    case 2:
                        int sel;
                        cout<<endl<<"==========Search Doctors=========="<<endl;
                        cout<<endl<<"1. Search Doctor By Doc ID"<<endl;
                        cout<<endl<<"2. Search Doctor By Speciality"<<endl;
                        cout<<endl<<"Enter Option: ";
                        cin>>sel;
                        if (0 ==  1) {
                                cout<<endl<<"==========Enter Doctor ID=========="<<endl;
                                int id;
                                bool found = false;
                                cout<<endl<<"Enter Doctor ID: ";
                                cin>>id;
                                while(doctorIn>>d1.doc_id>>d1.name>>d1.specialty>>d1.experience) {
                                    if (d1.doc_id == id) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found == true) {
                                    cout<<endl<<"Doctor Found!!"<<endl;
                                    cout<<"Doctor Details: "<<endl;
                                    cout<<"Doctor ID: "<<d1.doc_id<<endl;
                                    cout<<"Doctor Name: "<<d1.name<<endl;
                                    cout<<"Doctor Speciality: "<<d1.specialty<<endl;
                                    cout<<"Doctor Experience: "<<d1.experience<<endl;
                                }
                                else if (found == false) {
                                    cout<<endl<<"Doctor Not Found"<<endl;
                                }
                        }
                        else if (o == 2) {
                            searchDoctorBySpecialty();
                        }
                        else {
                            cout<<endl<<"Invalid Option"<<endl;
                        }
                        break;
                    case 3:
                        cout<<endl<<"==========Search Treatment By Doc ID=========="<<endl;
                        void viewTreatmentsByDoctor();
                        break;
                    case 4:
                        cout<<endl<<"==========Generate Bill=========="<<endl;
                        generateBill(billIn);
                        break;
                    case 5:
                        cout<<endl<<"==========Sort Doctors By Experience=========="<<endl;
                        sortDoctorsByExperience();
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
    cout<<endl<<"==========View Treatment=========="<<endl;
}

void updatePayment(ifstream &in, ofstream &out) {

}

void generateBill(ifstream &in) {

}

void searchPatientBydoc_ID() {

}

void searchDoctorBySpecialty() {

}

void viewTreatmentsByDoctor() {

}
void sortDoctorsByExperience() {

}
void scheduleAppointment() {

}
void cancelAppointment() {

}
void addPatient() {

}
void addDoctor() {

}
void updatePatient(ifstream &inFile) {
    Patient *p1 = new Patient;
    int idCheck;
    ofstream tempFile("tempFile.txt");
    bool isfound = false; 
    double balanceTemp;
    cout<<"Enter Patients ID whose data you want to update: ";
    cin>>idCheck;
    while(inFile>>p1->patientId) {
        inFile.ignore();
        getline(inFile ,p1->name, '#');
        inFile>>p1->age;
        inFile.ignore();
        getline(inFile, p1->gender, '#');
        getline(inFile, p1->contact, '#');
        inFile>>p1->balance;
        inFile.ignore();
        if (idCheck == p1->patientId) {
            cout<<endl<<"ID Found"<<endl;
            
            isfound = true;
            cout<<endl<<"==========Update Patient=========="<<endl;
            cout<<"1. Update Name"<<endl;
            cout<<"2. Update Age"<<endl;
            cout<<"3. Update Contact"<<endl;
            cout<<"4. Update Balance"<<endl;
            cout<<"5. Update Gender"<<endl;
            cout<<"Enter a Valid Option: ";
            int option;
            cin>>option;
            cin.ignore();
            switch(option) {
                case 1:
                    cout<<"Enter Name of Patient: ";
                    getline(cin, p1->name);
                    cout<<"Name Updated to "<<p1->name<<endl;
                    break;
                case 2:
                    cout<<"Enter age: ";
                    cin>>p1->age;
                    cin.ignore();
                    cout<<"New age is "<<p1->age<<endl;
                    break;
                case 3:
                    cout<<"Enter Contact(11 digits): ";
                    getline(cin, p1->contact);
                    cout<<"New Contact is "<<p1->contact<<endl;
                    break;
                case 4:
                    cout<<"Enter Balance: ";
                    cin>>p1->balance;
                    cin.ignore();
                    cout<<"New balance is "<<p1->balance<<endl;
                    break;
                case 5:
                    cout<<"Enter gender: ";
                    getline(cin, p1->gender);
                    cout<<"New gender is "<<p1->gender<<endl;
                    break;
                default:
                    cout<<"Invalid Option"<<endl;
                    break;
            }
        }
        tempFile<<p1->patientId<<"#"<<p1->name<<"#"<<p1->age<<"#"<<p1->gender<<"#"<<p1->contact<<"#"<<p1->balance<<endl;
    }
    if (isfound == false) {
        cout<<endl<<"Patient Not Found, Cannot update patient!!"<<endl;
        return;
    }
    remove("patients.txt");
    rename("tempFile.txt", "patients.txt");
    removeDuplicatePatients();
    tempFile.close();
    cout<<"File Updated"<<endl;
    delete p1;
}
void updateDoctor(ifstream &inFile) {
    Doctor *d1 = new Doctor;
    int idCheck;
    ofstream tempFile("temp.txt");
    bool isfound = false; 
    cout<<"Enter Doctors ID whose data you want to update: ";
    cin>>idCheck;
    while(inFile>>d1->doc_id) {
        inFile.ignore();
        getline(inFile ,d1->name, '#');
        getline(inFile, d1->specialty, '#');
        inFile>>d1->experience;
        inFile.ignore();
        if (idCheck == d1->doc_id) {
            cout<<endl<<"ID Found"<<endl;
            isfound = true;

            cout<<endl<<"==========Update Patient=========="<<endl;
            cout<<"1. Update Name"<<endl;
            cout<<"2. Update Speciality"<<endl;
            cout<<"3. Update Experience"<<endl;
            cout<<"Enter a Valid Option: ";
            int option;
            cin>>option;
            cin.ignore();
            switch(option) {
                case 1:
                    cout<<"Enter Name of Doctor: ";
                    getline(cin,d1->name);
                    cout<<"Name Updated to "<<d1->name<<endl;
                    break;
                case 2:
                    cout<<"Enter Speciality: ";
                    getline(cin, d1->specialty);
                    cout<<"New Speciality is "<<d1->specialty<<endl;
                    break;
                case 3:
                    cout<<"Enter experience: ";
                    cin>>d1->experience;
                    cin.ignore();
                    cout<<"New Experience is "<<d1->experience<<endl;
                    break;
                default:
                    cout<<"Invalid Option"<<endl;
                    break;
            }
        }
        tempFile<<d1->doc_id<<"#"<<d1->name<<"#"<<d1->specialty<<"#"<<d1->experience<<endl;
    }
    if (isfound == false) {
        cout<<endl<<"Patient Not Found, Cannot update patient!!"<<endl;
        return;
    }
    remove("doctors.txt");
    rename("temp.txt", "doctors.txt");
    tempFile.close();
    cout<<"File Updated"<<endl;
    delete d1;
}
void deletePatient() {

}
void deleteDoctor() {

}
void viewPatients(ifstream &inFile) {
    Patient *p1 = new Patient;
    cout<<endl<<"==========View Patients=========="<<endl;
    cout<<left<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Age"<<setw(20)<<"Gender"<<setw(20)<<"Contact"<<setw(20)<<"Ballance"<<endl;
    while(inFile>>p1->patientId) {
        inFile.ignore();
        getline(inFile ,p1->name, '#');
        inFile>>p1->age;
        inFile.ignore();
        getline(inFile, p1->gender, '#');
        getline(inFile, p1->contact, '#');
        inFile>>p1->balance;
        inFile.ignore();
        cout<<left<<setw(20)<<p1->patientId<<setw(20)<<p1->name<<setw(20)<<p1->age<<setw(20)<<p1->gender<<setw(20)<<p1->contact<<setw(20)<<p1->balance<<endl;    
    }
    delete p1;
}
void viewDoctors(ifstream &inFile) {
    Doctor *d1 = new Doctor;
    cout<<endl<<"==========View Doctors=========="<<endl;
    cout<<left<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Speciality"<<setw(20)<<"Experience"<<endl;
    while(inFile>>d1->doc_id) {
        inFile.ignore();
        getline(inFile ,d1->name, '#');
        getline(inFile, d1->specialty, '#');
        inFile>>d1->experience;
        inFile.ignore();
        cout<<left<<setw(20)<<d1->doc_id<<setw(20)<<d1->name<<setw(20)<<d1->specialty<<setw(20)<<d1->experience<<endl;
    }
    delete d1;
}
void viewAppointments() {

}
void cleanFile() {
    ifstream patientFile("patients.txt"); 
    cleanPatient(patientFile);
    patientFile.close();
}
void removeDuplicatePatients() {

}

void cleanDoctor(ifstream &inFile) {

}
void cleanPatient(ifstream &inFile) {
    Patient *p1 = new Patient;
    ofstream outFile("temp.txt");
    string line;
    while(true) {
        long pos = inFile.tellg();
        if(!getline(inFile, line)) { 
            break;
        }
        bool valid = isValidRecord(5, line);
        if (valid == true) {
            inFile.seekg(pos);
            inFile>>p1->patientId;
            inFile.ignore();
            getline(inFile, p1->name, '#');
            inFile>>p1->age;
            bool ageFlag = true;
            if(p1->age < 10) {
                ageFlag = false;
            }
            inFile.ignore();
            getline(inFile, p1->gender, '#');
            if (p1->gender == "M") {
                p1->gender = "Male";
            }
            else if (p1->gender == "F") {
                p1->gender = "Female";
            }
            getline(inFile, p1->contact, '#');
            inFile>>p1->balance;
            inFile.ignore();
            int length = (p1->contact).length();
            bool flag = true; 
            if (length != 11) {
                continue;
            }
            for(int i = 0; i < length; i++) {
                if(p1->contact[i] < '0' || p1->contact[i] > '9') {
                    flag = false;
                }
            }
            if (flag == false) {
                continue;
            }
            if(ageFlag == false) {
                continue;
            }
            outFile<<p1->patientId<<"#"<<p1->name<<"#"<<p1->age<<"#"<<p1->gender<<"#"<<p1->contact<<"#"<<p1->balance<<endl;
        }
    }
    remove("patients.txt");
    rename("temp.txt", "patients.txt");
    outFile.close();
    delete p1;
}
void cleanAppoitment(ifstream &inFile) {

}
void cleanTreatment(ifstream &inFile) {

}
bool isValidRecord(int count, string line) {
    int hash = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '#')
            hash++;
    }
    if (hash == count) {
        return true;
    }
    else {
        return false;
    }
}