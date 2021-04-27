import QtQuick 2.0
import QtQuick.Controls 2.0
import ElevatorData 1.0

Item {
    width: 100
    height: 500
    property ElevatorData elevData: null
    property var currFloor: elevData.floor
    Column {
        width: parent.height
        height: parent.height
        Row {
            id: status
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

        ListView {
            anchors.top: status.bottom
            model: 21
            height: parent.height
            spacing: 2
            delegate: Button {
                height: 20
                width: 80
                text: index + 1 + "  [" + elevData.list[index] + "]"
                onClicked: {
                    elevData.increaseFloor()
                    elevData.increaseItem(index)
                }
            }
        }
    }
}
