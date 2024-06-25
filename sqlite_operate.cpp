#include "sqlite_connect.h"

//插入学生信息
QString sqlite_connect::InsertStudentTable(int id,QString name,int age,QString sex){
    QSqlQuery sqlQuery;
    QString sql=QString("insert into student(id,name,age,sex) values('%1','%2','%3','%4');").arg(id).arg(name).arg(age).arg(sex);
    if(sqlQuery.exec(sql)){
        return "插入成功";
    }else{
        return "插入失败";
    }
}

//插入课程信息
QString sqlite_connect::InsertCourseTable(int id,QString name,int credits){
    QSqlQuery sqlQuery;
    QString sql=QString("insert into course(id,name,credits) values('%1','%2','%3');").arg(id).arg(name).arg(credits);
    if(sqlQuery.exec(sql)){
        return "插入成功";
    }else{
        return "插入失败";
    }
}

QString sqlite_connect::InsertSelectionTable(int student_id,int course_id){
    QSqlQuery sqlQuery;
    QString sql=QString("insert into selection(student_id,course_id) values('%1','%2');").arg(student_id).arg(course_id);
    if(sqlQuery.exec(sql)){
        return "插入成功";
    }else{
        return "插入失败";
    }
}

std::vector<student> sqlite_connect::QueryStudent(){
    std::vector<student> response;

    QSqlQuery sqlQuery;
    QString sql=("select * from student order by id desc");
    if(sqlQuery.exec(sql)){
        while(sqlQuery.next()){
            int id,age;
            QString name,sex;

            id=sqlQuery.value("id").toInt();
            name=sqlQuery.value("name").toString();
            age=sqlQuery.value("age").toInt();
            sex=sqlQuery.value("sex").toString();

            student temp =student(id,name,age,sex);

            response.push_back(temp);
        }
    }else{
        qDebug()<<"查询失败";
    }

    return response;
}

std::vector<course> sqlite_connect::QueryCourse(){
    std::vector<course> response;

    QSqlQuery sqlQuery;
    QString sql=("select * from course order by id desc");
    if(sqlQuery.exec(sql)){
        while(sqlQuery.next()){
            int id,credits;
            QString name;

            id=sqlQuery.value("id").toInt();
            name=sqlQuery.value("name").toString();
            credits=sqlQuery.value("credits").toInt();

            course temp =course(id,name,credits);

            response.push_back(temp);
        }
    }else{
        qDebug()<<"查询失败";
    }

    return response;
}

student sqlite_connect::QueryStudentByID(int id){
    QSqlQuery sqlQuery;
    QString sql=("select * from student where id=?");
    sqlQuery.prepare(sql);
    sqlQuery.addBindValue(id);


    if(!sqlQuery.exec()){
        qDebug() << "查询失败";
        return student();
    }

    if(sqlQuery.next()){
        int id = sqlQuery.value("id").toInt();
        QString name = sqlQuery.value("name").toString();
        int age = sqlQuery.value("age").toInt();
        QString sex = sqlQuery.value("sex").toString();

        return student(id, name, age, sex);
    } else {
        qDebug() << "没有找到学生:"<<id;
        return student();
    }
}

course sqlite_connect::QueryCourseByID(int id){
    QSqlQuery sqlQuery;
    QString sql = "select * from course where id = ?";
    sqlQuery.prepare(sql);
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec()){
        qDebug() << "查询失败";
        return course();
    }

    if(sqlQuery.next()){
        int id = sqlQuery.value("id").toInt();
        QString name = sqlQuery.value("name").toString();
        int credits = sqlQuery.value("credits").toInt();

        return course(id, name, credits); // 返回查询到的course对象
    } else {
        qDebug() << "没有找到课程:"<<id;
        return course();
    }
}

std::vector<selection> sqlite_connect::QuerySelection(){
    std::vector<selection> response;

    QSqlQuery sqlQuery;
    QString sql=("select * from selection order by student_id desc");
    if(sqlQuery.exec(sql)){
        while(sqlQuery.next()){
            int student_id,course_id,score;

            student_id=sqlQuery.value("student_id").toInt();
            course_id=sqlQuery.value("course_id").toInt();
            score=sqlQuery.value("score").toInt();

            student tempS=QueryStudentByID(student_id);
            course tempC=QueryCourseByID(course_id);

            selection temp=selection(tempS,tempC,score);

            response.push_back(temp);
        }
    }else{
        qDebug()<<"查询失败";
    }

    return response;
}

QString sqlite_connect::DeleteStudentByID(int id){
    QSqlQuery sqlQuery;
    QString sql=("delete from student where id = ?");
    sqlQuery.prepare(sql);
    sqlQuery.addBindValue(id);

    if(sqlQuery.exec()){
        return "删除成功";
    }else{
        return "删除失败";
    }
}

QString sqlite_connect::DeleteCourseByID(int id){
    QSqlQuery sqlQuery;
    QString sql=("delete from course where id = ?");
    sqlQuery.prepare(sql);
    sqlQuery.addBindValue(id);

    if(sqlQuery.exec()){
        return "删除成功";
    }else{
        return "删除失败";
    }
}

QString sqlite_connect::DeleteSelection(int student_id, int course_id){
    QSqlQuery sqlQuery;
    QString sql = "delete from selection where student_id = ? and course_id = ?";
    sqlQuery.prepare(sql);
    sqlQuery.addBindValue(student_id);
    sqlQuery.addBindValue(course_id);

    if(sqlQuery.exec()){
        return "删除成功";
    }else{
        return "删除失败";
    }
}

QString sqlite_connect::UploadStudentScore(int student_id, int course_id, int score){
    QSqlQuery sqlQuery;
    QString sql = "update selection set score = ? where student_id = ? and course_id = ?";
    sqlQuery.prepare(sql);
    sqlQuery.addBindValue(score);
    sqlQuery.addBindValue(student_id);
    sqlQuery.addBindValue(course_id);

    if(sqlQuery.exec()){
        return "上传成功";
    }else{
        return "上传失败";
    }
}
