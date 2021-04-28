import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.VirtualKeyboard 2.4
import Working 1.0
import QtQuick.Controls 2.5

Window {
    id: window
    visible: true
    width: 640
    height: 600
    title: qsTr("电梯调度模拟器")
    property var curr1: 7
    property var curr2: 1
    property var curr3: 8
    property var curr4: 20
    Row {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 10
        Elevator {
            elevData: ele0
        }
        Elevator {
            elevData: ele1
        }
        Elevator {
            elevData: ele2
        }
        Elevator {
            elevData: ele3
        }
        Column {
            width: 150
            height: window.height
            anchors.top: parent.top
            anchors.topMargin: 30
            ListView {
                model: 21
                spacing: 2
                height: parent.height
                width: 100
                delegate: Rectangle {
                    width: 100
                    height: 20
                    Button {
                        anchors.top: parent.top
                        anchors.left: parent.left
                        width: 48
                        height: 20
                        text: "🔺"
                        onClicked: {
                            console.log(index + "上")
                        }
                    }
                    Button {
                        anchors.top: parent.top
                        anchors.right: parent.right
                        height: 20
                        width: 48
                        text: "🔻"
                        onClicked: {
                            console.log(index + "下")
                        }
                    }
                }
            }
        }
    }
}

