import QtQuick 2.0
import QtQuick.Controls 2.0
import ElevatorData 1.0

Item {
    implicitHeight: 550
    implicitWidth: 100
    property ElevatorData elevData: null
    property var currFloor: elevData.floor
    property var elevatorId: 1
    Rectangle {
        anchors.centerIn: parent.Center
        width: 80
        height: 550
        border.color: "#eee"
        border.width: 1
        Column {
            width: parent.height
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
                    opacity: currFloor === 1 ? 0 : 1
                    height: 30
                    width: 20
                    text: currFloor - 1
                    color: "#aaa"
                    font.pointSize: 10
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                Text {
                    height: 30
                    width: 40
                    text: currFloor
                    font.bold: true
                    font.pointSize: 18
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                Text {
                    opacity: currFloor === 21 ? 0 : 1
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
                        property var used: elevData.list[index]
                        ElevatorPointer {
                            height: 20
                            width: 30
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.top: parent.top
                            status: 1
                            reached: elevData.floor == 20 - index
                        }
                        ElevatorButton {
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.rightMargin: 5
                            height: 20
                            width: 30
                            text: index === 20 ? -1 : 20 - index
                            onClicked: {
                                elevData.increaseFloor()
                                elevData.increaseItem(index)
                            }
                            activated: elevData.list[index]
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
                text: "12"
                font.family: "Arial"
                font.pointSize: 12
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: status.horizontalCenter
            }
        }
    }
}
