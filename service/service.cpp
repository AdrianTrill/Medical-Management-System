#include "service.h"

void Service::addDoctor(Doctor *doctor) {
    repository->addDoctor(doctor);
}

void Service::addPatient(Patient *patient) {
    repository->addPatient(patient);
}

vector<Doctor *> Service::getDoctors() {
    return repository->getDoctors();
}

vector<Patient *> Service::getPatients() {
    return repository->getPatients();
}

void Service::removeDoctor(string name) {
    repository->removeDoctor(name);
}

void Service::removePatient(string name) {
    repository->removePatient(name);
}


vector<Patient *> Service::getPatientsBySpecialisation(string specialisation) {
    vector<Patient *> patients = repository->getPatients();

    patients.erase(remove_if(patients.begin(), patients.end(), [specialisation](Patient *patient) {
        return !(patient->getSpecialisation() == specialisation || patient->getDiagnosis() == "undiagnosed");
    }), patients.end());

    sort(patients.begin(), patients.end(), [](Patient *a, Patient *b) {
        return a->getAdmissionDate() < b->getAdmissionDate();
    });

    return patients;
}

