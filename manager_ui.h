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
    //查询
    Q_INVOKABLE QString QueryStudentButton();
    Q_INVOKABLE QString QueryCourseButton();
    Q_INVOKABLE QString QuerySelectionButton();
    Q_INVOKABLE QString QueryStudentByStudentID(int id);
    Q_INVOKABLE QString QueryCourseByCourseName(QString name);
    Q_INVOKABLE QString QuerySelectionScoreByStudentID(int id);

    //插入
    Q_INVOKABLE QString InsertStuent(int id,QString name,int age,QString sex);
    Q_INVOKABLE QString InsertCourse(int id,QString name,int credits);
    Q_INVOKABLE QString InsertSelection(int studnet_id,int course_id);

    //修改
    Q_INVOKABLE QString UpdateStudentScore(int student_id,int course_id,int score);

    //删除
    Q_INVOKABLE QString DeleteStudent(int id);
    Q_INVOKABLE QString DeleteCourse(int id);
    Q_INVOKABLE QString DeleteSelection(int studnet_id,int course_id);
};

#endif // MANAGER_UI_H
