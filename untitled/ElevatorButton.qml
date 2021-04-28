import QtQuick 2.0
import QtQuick.Controls 2.0

Button {
    property var activated: true
    id: btn
    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: btn.down ? "#eeeeee" : "#FFFFFF"
        border.color: activated ? "#17a81a" : "#eeeeee"
        border.width: 2
    }
}
