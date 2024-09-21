#pragma once
#include <algorithm>
#include <vector>
#include <string>

#include "../repository/repository.h"

class Service {
private:
    Repository *repository;
public:
    Service(Repository *repository): repository(repository) {
        repository->loadDoctorsFromFile("../data/doctors.txt");
        repository->loadPatientsFromFile("../data/patients.txt");
    }
    void addDoctor(Doctor *doctor);
    void addPatient(Patient *patient);
    vector<Doctor *> getDoctors();
    vector<Patient *> getPatients();
    void removeDoctor(string name);
    void removePatient(string name);
    vector<Patient *> getPatientsBySpecialisation(string specialisation);
};
