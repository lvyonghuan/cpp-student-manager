#ifndef MANAGER_UI_H
#define MANAGER_UI_H

#include <QObject>

#include "sqlite_connect.h"

class manager_ui:public QObject,public sqlite_connect
{
    Q_OBJECT
public:
    manager_ui(QObject *parent=nullptr):QObject(parent),sqlite_connect(){};

public slots:
    Q_INVOKABLE QString QueryStudentButton();
    Q_INVOKABLE QString QueryCourseButton();
    Q_INVOKABLE QString QuerySelectionButton();
    Q_INVOKABLE QString QueryStudentByStudentID(int id);
    Q_INVOKABLE QString QueryCourseByCourseName(QString name);
    Q_INVOKABLE QString QuerySelectionScoreByStudentID(int id);

    Q_INVOKABLE QString InsertStuent(int id,QString name,int age,QString sex);
    Q_INVOKABLE QString InsertCourse(int id,QString name,int credits);
    Q_INVOKABLE QString InsertSelection(int studnet_id,int course_id);

    Q_INVOKABLE QString UpdateStudentScore(int student_id,int course_id,int score);
};

#endif // MANAGER_UI_H
