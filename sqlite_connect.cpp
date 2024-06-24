#include "sqlite_connect.h"

void initTables(QSqlDatabase &db);
bool isTableExist(const QString &tableName,QSqlDatabase &db);
void CreateStudentTable(QSqlDatabase &db);
void CreateCourseTable(QSqlDatabase &db);
void CreateSelectionTable(QSqlDatabase &db);

//初始化数据库
sqlite_connect::sqlite_connect() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("student.sqlite");
    db.open();

    initTables(db);
}

//初始化表
void initTables(QSqlDatabase &db){
    bool isStudentExist=isTableExist("student",db);
    if(!isStudentExist){
        CreateStudentTable(db);
    }

    bool isCourseTableExist=isTableExist("course",db);
    if(!isCourseTableExist){
        CreateCourseTable(db);
    }

    bool isSelectionTableExist=isTableExist("selection",db);
    if(!isSelectionTableExist){
        CreateSelectionTable(db);
    }
}

//查询是否已经存在表
bool isTableExist(const QString &tableName,QSqlDatabase &db){
    QSqlQuery query(db);

    query.prepare("SELECT count(*) FROM sqlite_master WHERE type='table' AND name=:tableName");
    query.bindValue(":tableName", tableName);

    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return (count > 0);
    }

    return false;
}

//创建学生表
void CreateStudentTable(QSqlDatabase &db){
    QSqlQuery query(db);
    query.exec("CREATE TABLE student"
               "(id INTEGER PRIMARY KEY,"
               "name VARCHAR(32),"
               "age INTEGER,"
               "sex VARCHAR(1))");
}

//创建课程表
void CreateCourseTable(QSqlDatabase &db) {
    QSqlQuery query(db);
    query.exec("CREATE TABLE course"
               "(id INTEGER PRIMARY KEY,"
               "name VARCHAR(64) NOT NULL,"
               "credits INTEGER NOT NULL CHECK (credits > 0))");
}

//创建选课表
void CreateSelectionTable(QSqlDatabase &db) {
    QSqlQuery query(db);
    query.exec("CREATE TABLE selection"
               "(student_id INTEGER,"
               "course_id INTEGER,"
               "score INTEGER,"
               "PRIMARY KEY(student_id, course_id),"
               "FOREIGN KEY(student_id) REFERENCES student(id),"
               "FOREIGN KEY(course_id) REFERENCES course(id))");
}
