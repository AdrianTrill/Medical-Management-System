#include "repository.h"

void Repository::addDoctor(Doctor *doctor) {
    this->doctors.push_back(doctor);
}

void Repository::addPatient(Patient *patient) {
    this->patients.push_back(patient);
}

vector<Doctor *> Repository::getDoctors() {
    return this->doctors;
}

vector<Patient *> Repository::getPatients() {
    return this->patients;
}

void Repository::removeDoctor(string name) {
    for (int i = 0; i < doctors.size(); i++) {
        if (doctors[i]->getName() == name) {
            doctors.erase(doctors.begin() + i);
            return;
        }
    }
}

void Repository::removePatient(string name) {
    for (int i = 0; i < patients.size(); i++) {
        if (patients[i]->getName() == name) {
            patients.erase(patients.begin() + i);
            return;
        }
    }
}

void Repository::saveDoctorsToFile(const string &filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& doctor : doctors) {
            outFile << *doctor << endl;
        }
        outFile.close();
    }
}

void Repository::savePatientsToFile(const string &filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& patient : patients) {
            outFile << *patient << endl;
        }
        outFile.close();
    }
}

void Repository::loadDoctorsFromFile(const string &filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream stream(line);
            Doctor *doctor = new Doctor();
            stream >> *doctor;
            this->doctors.push_back(doctor);
        }
        inFile.close();
    }
}

void Repository::loadPatientsFromFile(const string &filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream stream(line);
            Patient *patient = new Patient();
            stream >> *patient;
            this->patients.push_back(patient);
        }
        inFile.close();
    }
}


