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

    Button{
        id: queryButton
        text:"查询学生"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked:textArea.text=managerUI.QueryStudentButton()
    }

    TextArea {
            id: textArea
            anchors.top: queryButton.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            readOnly: true
        }
}
