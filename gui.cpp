//
// Created by Adrian Trill on 21.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <QMessageBox>
#include <QDate>


gui::gui(QWidget *parent, Service *service, Doctor *doctor) : QWidget(parent), ui(new Ui::gui), service(service), doctor(doctor){
    ui->setupUi(this);

    this->setWindowTitle(QString::fromStdString(doctor->getName()));

    this->updateList();

    QObject::connect(this->ui->myPatientsCheckbox, &QCheckBox::stateChanged, this, &gui::updatePatients);
    QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &gui::addPatient);
}

gui::~gui() {
    delete ui;
}


void gui::updateList() {
    this->ui->listWidgetPatient->clear();
    for(Patient *patient: service->getPatientsBySpecialisation(doctor->getSpecialisation())) {
        auto item = new QListWidgetItem(QString::fromStdString(patient->toString()));
        if(patient->getCurrentDoctor() == doctor->getName()) {
            item->setBackground(Qt::green);
        }
        this->ui->listWidgetPatient->addItem(item);
    }
}


void gui::updatePatients() {
    this->ui->listWidgetPatient->clear();

    if(this->ui->myPatientsCheckbox->isChecked()) {
        for(Patient *patient: service->getPatientsBySpecialisation(doctor->getSpecialisation())) {
            if(patient->getCurrentDoctor() == doctor->getName()) {
                auto item = new QListWidgetItem(QString::fromStdString(patient->toString()));
                item->setBackground(Qt::green);
                this->ui->listWidgetPatient->addItem(item);
            }
        }
    } else {
        this->updateList();
    }
}


// Doctors can add new patients by inputting all required information(specialisation, diagnosis, and doctor can be empty)
// Display an error if the patient name is empty or the date is in the past
void gui::addPatient() {
string name = this->ui->nameLineEdit->text().toStdString();
    string diagnosis = this->ui->diagnosisLineEdit->text().toStdString();
    string specialisation = this->ui->specialisationLineEdit->text().toStdString();
    string doctorName = this->ui->doctorLineEdit->text().toStdString();
    QDate date = this->ui->dateEdit->date();

    if(name.empty()) {
        QMessageBox::critical(this, "Error", "Name cannot be empty!");
        return;
    }

    if(date < QDate::currentDate()) {
        QMessageBox::critical(this, "Error", "Date cannot be in the past!");
        return;
    }

    Patient *patient = new Patient(name, diagnosis, specialisation, doctor, date);
    service->addPatient(patient);
    this->updateList();
}

