//
// Created by Adrian Trill on 21.06.2024.
//

#ifndef OOP_E_911_915_ADRIANTRILL_GUI_H
#define OOP_E_911_915_ADRIANTRILL_GUI_H

#include <QWidget>
#include "domain/doctor.h"
#include "service/service.h"
#include "domain/patient.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
Q_OBJECT

public:
    explicit gui(QWidget *parent = nullptr, Service *service = nullptr, Doctor *doctor = nullptr);
    ~gui() override;

private:
    Ui::gui *ui;

    Service *service;
    Doctor *doctor;

    void updateList();
    void updatePatients();
    void addPatient();
};


#endif //OOP_E_911_915_ADRIANTRILL_GUI_H
