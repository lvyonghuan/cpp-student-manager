#include "manager_ui.h"
#include "detection.h"

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
    if(!IsLegalAge(age)){
        return "非法年龄参数，年龄应位于18~60之间";
    }
    if(!IsLegalSex(sex)){
        return "非法性别参数，性别只能是“男”或“女”";
    }

    QString info=sqlite_connect::InsertStudentTable(id,name,age,sex);
    return info;
}

QString manager_ui::InsertCourse(int id,QString name,int credits){
    if(!IsLegalCredits(credits)){
        return "非法学分参数，学分应当大于0";
    }

    QString info=sqlite_connect::InsertCourseTable(id,name,credits);
    return info;
}

QString manager_ui::InsertSelection(int student_id,int course_id){
    QString info=sqlite_connect::InsertSelectionTable(student_id,course_id);
    return info;
}

QString manager_ui::UpdateStudentScore(int student_id,int course_id,int score){
    if(!IsLegalScore(score)){
        return "非法分数参数，分数应当位于0~100之间";
    }

    QString info=sqlite_connect::UploadStudentScore(student_id,course_id,score);
    return info;
}

QString manager_ui::DeleteStudent(int id){
    QString info=sqlite_connect::DeleteStudentByID(id);
    return info;
}

QString manager_ui::DeleteCourse(int id){
    QString info=sqlite_connect::DeleteCourseByID(id);
    return info;
}

QString manager_ui::DeleteSelection(int student_Id,int course_id){
    QString info=sqlite_connect::DeleteSelection(student_Id,course_id);
    return info;
}
