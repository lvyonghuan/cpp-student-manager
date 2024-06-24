#ifndef MODEL_H
#define MODEL_H

#include <QString>

class student{
public:
    student(int id,QString name,int age,QString sex):id(id),name(name),age(age),sex(sex){};
    student(){};
    int id;
    QString name;
    int age;
    QString sex;
};

class course{
public:
    course(int id,QString name,int credits):id(id),name(name),credits(credits){};
    course(){};
    int id;
    QString name;
    int credits;
};

class selection:public student,public course{
public:
    selection(student s,course c,int score):student(s),course(c),score(score){};
    selection(int student_id,QString student_name,int age,QString sex,int course_id,QString course_name,int credits,int score):student(student_id,student_name,age,sex),course(course_id,course_name,credits),score(score){};
    selection(){};
    int score;
};

#endif // MODEL_H
