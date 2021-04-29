import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.VirtualKeyboard 2.4
import QtQuick.Layouts 1.0
import Working 1.0
import QtQuick.Controls 2.5

Window {
    id: window
    visible: true
    width: 620
    height: 600
    minimumWidth: 580
    minimumHeight: 600
    title: qsTr("电梯调度模拟器")
    property var curr1: 7
    property var curr2: 1
    property var curr3: 8
    property var curr4: 20

    Row {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10
        Elevator {
            elevData: ele0
            elevatorId: 1
        }
        Elevator {
            elevData: ele1
            elevatorId: 2
            even: false
        }
        Elevator {
            elevData: ele2
            elevatorId: 3
            odd: false
        }

        Elevator {
            elevData: ele3
            elevatorId: 4
        }
        Column {
            width: 100
            anchors.top: parent.top
            Rectangle {
                height: 57
                width: 140
                Text {
                    text: "Elevator Simulator"
                    font.underline: true
                    anchors.top: parent.top
                    anchors.margins: 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pointSize: 12
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Arial"
                    horizontalAlignment: Text.AlignHCenter
                }

                Text {
                    text: "Frontend @BladeHiker\nBackend @sunwenli"
                    anchors.bottom: parent.bottom
                    anchors.margins: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pointSize: 8
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Arial"
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Item {
                height: 462
                width: 140
                ListView {
                    interactive: false
                    model: 21
                    spacing: 2
                    width: 140
                    height: parent.height
                    delegate: Rectangle {
                        id: rectangle
                        property var i: 20 - index
                        width: 140
                        height: 20
                        Row {
                            anchors.fill: parent
                            spacing: 5
                            Text {
                                width: 20
                                height: 20
                                text: {
                                    if (i === 0)
                                        return "B  1"
                                    if (i < 10)
                                        return "F  " + i
                                    return "F" + i
                                }
                                font.family: "Arial"
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }
                            ElevatorButton {
                                width: 35
                                height: 20
                                text: "🔺"
                                activated: button0.list[i]
                                onClicked: {
                                    button0.fButtonup(i)
                                }
                            }
                            Text {
                                height: 20
                                width: 15
                                text: "◁ " + button0.list[i]
                                font.family: "Arial"
                                font.pointSize: 7
                                color: "#a6a6a6"
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }

                            ElevatorButton {
                                height: 20
                                width: 35
                                text: "🔻"
                                activated: button1.list[i]
                                onClicked: {
                                    button1.fButtondown(i)
                                }
                            }
                            Text {
                                height: 20
                                width: 15
                                text: "◁ " + button1.list[i]

                                font.family: "Arial"
                                font.pointSize: 7
                                color: "#a6a6a6"
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }
                        }
                    }
                }
            }
            Text {
                text: "▶ 模拟运行中"
                font.pointSize: 12
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                height: 40
                width: 140
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:8}
}
##^##*/

