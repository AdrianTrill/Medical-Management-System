#include <QApplication>
#include <QPushButton>
#include "gui.h"
#include "service/service.h"
#include "repository/repository.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repo;
    Service service(&repo);
    for(Doctor *doctor: service.getDoctors()) {
        auto g = new gui(nullptr, &service, doctor);
        g->show();
    }
    return QApplication::exec();
}
