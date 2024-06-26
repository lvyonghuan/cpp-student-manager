import QtQuick
import QtQuick.Controls

import manager_ui 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("控制界面")

    ManagerUI{
    id:managerUI
    }

    Rectangle {
        id: topArea
                width: parent.width
                height: 100
                color: "lightgray"
                border.color: "black"
                border.width: 1

        Flow {

            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

        Button{
        id: queryStudent
        text:"查询学生信息"
        onClicked:textArea.text=managerUI.QueryStudentButton()
        }

        Button{
            id:queryCourse
            text:"查询课程信息"
            onClicked:textArea.text=managerUI.QueryCourseButton()
        }

        Button{
            id:querySelection
            text:"查询选课信息"
            onClicked: textArea.text=managerUI.QuerySelectionButton()
        }

        Button{
            id:queryStudentByID
            text:"学号查询学生"
            onClicked:queryStudentByIDDialog.open()
        }

        Button{
            id:queryCourseByCourseName
            text:"课程名查询课程"
            onClicked: queryCourseByNameDialog.open()
        }

        Button{
            id:insertStudentInfo
            text:"插入学生信息"
            onClicked: insertStudentInfoDialog.open()
        }

        Button{
            id:insertCourseInfo
            text:"插入课程信息"
            onClicked: insertCourseInfoDialog.open()
        }

        Button{
            id:insertSelectionInfo
            text:"插入选课信息"
            onClicked: insertSelectionInfoDialog.open()
        }

        Button{
            id:queryStudentScore
            text:"查询学生成绩"
            onClicked: queryStudentScoreDialog.open()
        }

        Button{
            id:uploadStudentScore
            text:"上传学生成绩"
            onClicked:uploadStudentScoreDialog.open()
        }

        Button{
            id:deleteStudent
            text:"删除学生"
            onClicked: deleteStudentDialog.open()
        }

        Button{
            id:deleteCourse
            text:"删除课程"
            onClicked: deleteCourseDialog.open()
        }

        Button{
            id:deleteSelection
            text:"删除选课"
            onClicked: deleteSelectionDialog.open()
        }
    }
    }

    Dialog{
        id:queryStudentByIDDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:queryStudentByIDInputFile
                placeholderText: "请输入学号"
                inputMethodHints: Qt.ImhDigitsOnly // 限定输入为数字
            }
        }

        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.QueryStudentByStudentID(queryStudentByIDInputFile.text)
                queryStudentByIDDialog.close()
            }

        }
    }

    Dialog{
        id:queryCourseByNameDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:queryCourseByNameInputFile
                placeholderText: "请输入课程名"
            }
        }

        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.QueryCourseByCourseName(queryCourseByNameInputFile.text)
                queryCourseByNameDialog.close()
            }

        }
    }

    Dialog{
        id:insertStudentInfoDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:insertStudentInfoStudentIDInputFile
                placeholderText: "请输入学号"
            }
            TextField{
                id:insertStudentInfoStudentNameInputFile
                placeholderText: "请输入姓名"
            }
            TextField{
                id:insertStudentInfoStudentAgeInputFile
                placeholderText: "请输入年龄(18~60)"
            }
            TextField{
                id:insertStudentInfoStudentSexInputFile
                placeholderText: "请输入性别(男/女)"
            }
        }

        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.InsertStuent(insertStudentInfoStudentIDInputFile.text,insertStudentInfoStudentNameInputFile.text,insertStudentInfoStudentAgeInputFile.text,insertStudentInfoStudentSexInputFile.text)
                insertStudentInfoDialog.close()
            }

        }
    }

    Dialog{
        id:insertCourseInfoDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:insertCourseInfoCourseIDInputFile
                placeholderText: "请输入课程号"
            }
            TextField{
                id:insertCourseInfoCourseNameInputFile
                placeholderText: "请输入课程名"
            }
            TextField{
                id:insertCourseInfoCourseCreditsInputFile
                placeholderText: "请输入学分(>0)"
            }
        }

        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.InsertCourse(insertCourseInfoCourseIDInputFile.text,insertCourseInfoCourseNameInputFile.text,insertCourseInfoCourseCreditsInputFile.text)
                insertCourseInfoDialog.close()
            }

        }
    }


    Dialog{
        id:insertSelectionInfoDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:insertSelectionStudentIDInputFile
                placeholderText: "请输入学号"
            }
            TextField{
                id:insertSelectionCourseIDInputFile
                placeholderText: "请输入课程号"
            }
            }


        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.InsertSelection(insertSelectionStudentIDInputFile.text,insertSelectionCourseIDInputFile.text)
                insertSelectionInfoDialog.close()
            }
        }
    }

    Dialog{
        id:queryStudentScoreDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:queryStudentScoreInputFile
                placeholderText: "请输入学号"
            }
            }


        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.QuerySelectionScoreByStudentID(queryStudentScoreInputFile.text)
                queryStudentScoreDialog.close()
            }
        }
    }

    Dialog{
        id:uploadStudentScoreDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:uploadStudentScoreStudentIDInputFile
                placeholderText: "请输入学号"
            }
            TextField{
                id:iuploadStudentScoreCourseIDInputFile
                placeholderText: "请输入课程号"
            }
            TextField{
                id:uploadStudentScoreScoreInputFile
                placeholderText:"请输入学生成绩(0~100)"
            }
            }


        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.UpdateStudentScore(uploadStudentScoreStudentIDInputFile.text,iuploadStudentScoreCourseIDInputFile.text,uploadStudentScoreScoreInputFile.text)
                uploadStudentScoreDialog.close()
            }
        }
    }

    Dialog{
        id:deleteStudentDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:deleteStudentStudentIDInputFile
                placeholderText: "请输入学号"
            }
            }


        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.DeleteStudent(deleteStudentStudentIDInputFile.text)
                deleteStudentDialog.close()
            }
        }
    }

    Dialog{
        id:deleteCourseDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:deleteCourseCourseIDInputFile
                placeholderText: "请输入课程号"
            }
            }


        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.DeleteCourse(deleteCourseCourseIDInputFile.text)
                deleteCourseDialog.close()
            }
        }
    }

    Dialog{
        id:deleteSelectionDialog
        modal:true
        title:"请输入内容"

        contentItem:Column{
            spacing:10
            width:parent.width
            padding:10

            TextField{
                id:deleteSelectionStudentIDInputFile
                placeholderText: "请输入学号"
            }
            TextField{
                id:deleteSelectionCourseIDInputFile
                placeholderText: "请输入课程号"
            }
            }


        Button{
            text:"提交"
            onClicked:{
                textArea.text=managerUI.DeleteSelection(deleteSelectionStudentIDInputFile.text,deleteSelectionCourseIDInputFile.text)
                deleteSelectionDialog.close()
            }
        }
    }

    TextArea {
            id: textArea
            anchors.top: topArea.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            readOnly: true
        }
}
