#include "manager_ui.h"

QString manager_ui::QueryStudentButton(){
    std::vector<student> students=sqlite_connect::QueryStudent();
    QString studentInfo;
    for(const auto& student : students){
        studentInfo+=QString("学号:%1\t姓名:%2\t年龄:%3\t性别:%4\n")
                           .arg(student.age).arg(student.name).arg(student.age).arg(student.sex);
    }
    return studentInfo;
}
