import QtQuick 2.0

Rectangle {
    height: 20
    width: 30
    property var status: 1 //1上 -1下 0停
    property var reached: true
    property var highlightColor: "#17a81a"
    property var defaultColor: "#f0f0f0"
    color: reached ? highlightColor : defaultColor
    Text {
        id: pointer
        color: "#edecec"
        text: {
            if (status == 1)
                return "▲"
            else if (status == -1)
                return "▼"
            else
                return ""
        }
        font.bold: true
        font.pointSize: 10
        font.family: "Arial"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
    }
}
