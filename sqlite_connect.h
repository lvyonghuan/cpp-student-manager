#ifndef SQLITE_CONNECT_H
#define SQLITE_CONNECT_H

#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

#include <vector>

#include "model.h"

class sqlite_connect
{
public:
    sqlite_connect();

    //插入
    QString InsertStudentTable(int id,QString name,int age,QString sex);
    QString InsertCourseTable(int id,QString name,int credits);
    QString InsertSelectionTable(int student_id,int crouse_name);

    //查询
    std::vector<student> QueryStudent();
    std::vector<course> QueryCourse();
    std::vector<selection> QuerySelection();
    student QueryStudentByID(int id);
    course QueryCourseByID(int id);

private:
    QSqlDatabase db;

// public:
//     //表名
//     const QString student="student";
//     const QString selection="selection";
//     const QString course="course";
};

#endif // SQLITE_CONNECT_H
