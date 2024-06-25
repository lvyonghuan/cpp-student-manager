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

    TextArea {
            id: textArea
            anchors.top: topArea.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            readOnly: true
        }
}
