import QtQuick 2.0
import QtQuick.Controls 2.0
import ElevatorData 1.0

Rectangle {
    id: rectangle
    implicitHeight: 560
    implicitWidth: 100
    property ElevatorData elevData: null
    property var currFloor: elevData.floor
    property var elevatorId: 1
    property var odd: true
    property var even: true
    property var loadCount: elevData.loadCount
    border.color: "#F0AE03"
    border.width: 3
    Rectangle {
        anchors.centerIn: parent.Center
        width: 80
        height: 550
        border.width: 0
        anchors.top: parent.top
        anchors.topMargin: 5
        //        border.color: "#eee"
        //        border.width: 1
        anchors.horizontalCenter: parent.horizontalCenter
        Column {
            width: parent.width
            height: parent.height
            spacing: 2
            Text {
                height: 15
                text: "电梯" + elevatorId
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: status.horizontalCenter
            }

            Row {
                id: status
                height: 30
                Text {
                    opacity: currFloor === 0 ? 0 : 1
                    height: 30
                    width: 20
                    text: currFloor == 1 ? "B1" : currFloor - 1
                    color: "#aaa"
                    font.pointSize: 10
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                Text {
                    height: 30
                    width: 40
                    text: currFloor == 0 ? "B1" : currFloor
                    font.bold: true
                    font.pointSize: 18
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                Text {
                    opacity: currFloor >= 21 ? 0 : 1
                    height: 30
                    width: 20
                    text: currFloor + 1
                    color: "#aaa"
                    font.pointSize: 10
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Rectangle {
                id: spliter
                height: 2
                width: 70
                color: "#eee"
                anchors.horizontalCenter: status.horizontalCenter
            }
            Item {
                height: 465
                width: 80
                ListView {
                    interactive: false
                    model: 21
                    anchors.fill: parent
                    spacing: 2
                    delegate: Rectangle {
                        height: 20
                        width: 80
                        property var isCurr: elevData.floor == 20 - index
                        ElevatorPointer {
                            height: 20
                            width: 30
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.top: parent.top
                            status: elevData.direction
                            reached: elevData.floor == 20 - index
                            Text {
                                visible: elevData.floor !== 20 - index
                                color: "#a6a6a6"
                                text: elevData.list[20 - index] + " ▷"
                                anchors.fill: parent
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 7
                                font.family: "Arial"
                                horizontalAlignment: Text.AlignHCenter
                            }
                        }

                        ElevatorButton {
                            enabled: (odd && (index % 2))
                                     || (even && (index % 2 == 0))
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.rightMargin: 5
                            height: 20
                            width: 35
                            text: index === 20 ? -1 : 20 - index
                            onClicked: {
                                elevData.increaseFloor()
                                elevData.increaseItem(20 - index)
                            }
                            activated: elevData.list[20 - index]
                        }
                    }
                }
            }
            Text {
                height: 10
                width: 80
                text: "电梯内人数"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: status.horizontalCenter
            }
            Text {
                height: 15
                width: 80
                text: loadCount
                font.family: "Arial"
                font.pointSize: 12
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: status.horizontalCenter
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}
}
##^##*/

