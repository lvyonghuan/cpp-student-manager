#include "manager_ui.h"

QString manager_ui::QueryStudentButton(){
    std::vector<student> students=sqlite_connect::QueryStudent();
    QString studentInfo;
    for(const auto& student : students){
        studentInfo+=QString("学号:%1\t姓名:%2\t年龄:%3\t性别:%4\n")
                           .arg(student.id).arg(student.name).arg(student.age).arg(student.sex);
    }
    return studentInfo;
}

QString manager_ui::QueryCourseButton(){
    std::vector<course> courses=sqlite_connect::QueryCourse();
    QString courseInfo;
    for(const auto& course : courses){
        courseInfo+=QString("ID:%1\t名称:%2\t学分:%3\n")
                          .arg(course.id).arg(course.name).arg(course.credits);
    }

    return courseInfo;
}

QString manager_ui::QuerySelectionButton(){
    std::vector<selection> selections=sqlite_connect::QuerySelection();
    QString selectionInfo;

    for(const auto& selection :selections){
        selectionInfo += QString("学号:%1\t姓名:%2\t课程名:%3\n")
                             .arg(selection.student::id)
                             .arg(selection.student::name)
                             .arg(selection.course::name);

    }

    return selectionInfo;
}

QString manager_ui::QueryStudentByStudentID(int id){
    student temp=sqlite_connect::QueryStudentByID(id);

    QString studentInfo;
    studentInfo+=QString("学号:%1\t姓名:%2\t年龄:%3\t性别:%4\n")
                       .arg(temp.id).arg(temp.name).arg(temp.age).arg(temp.sex);

    return studentInfo;
}

QString manager_ui::QueryCourseByCourseName(QString name){
    course temp=sqlite_connect::QueryCourseByName(name);

    QString courseInfo;
    courseInfo+=QString("ID:%1\t名称:%2\t学分:%3\n")
                      .arg(temp.id).arg(temp.name).arg(temp.credits);

    return courseInfo;
}

QString manager_ui::QuerySelectionScoreByStudentID(int id){
    std::vector<selection> selections=sqlite_connect::QuerySelection();
    QString selectionInfo;

    for(const auto& selection :selections){
        selectionInfo += QString("课程名:%1\t成绩:%2\n")
                             .arg(selection.course::name)
                             .arg(selection.score);
    }

    return selectionInfo;
}

QString manager_ui::InsertStuent(int id,QString name,int age,QString sex){
    QString info=sqlite_connect::InsertStudentTable(id,name,age,sex);
    return info;
}

QString manager_ui::InsertCourse(int id,QString name,int credits){
    QString info=sqlite_connect::InsertCourseTable(id,name,credits);
    return info;
}

QString manager_ui::InsertSelection(int student_id,int course_id){
    QString info=sqlite_connect::InsertSelectionTable(student_id,course_id);
    return info;
}

QString manager_ui::UpdateStudentScore(int student_id,int course_id,int score){
    QString info=sqlite_connect::UploadStudentScore(student_id,course_id,score);
    return info;
}

