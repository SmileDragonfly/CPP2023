import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    color: "lightgreen"
    title: qsTr("CryptoInfomation")
    ColumnLayout{
        id: layout
        Text {
            id: label1
            text: "Hello 1"
        }
        Text {
            id: label2
            anchors.left: label1.right
            text: "Hello 2"
        }
        Text {
            id: label3
            text: "Hello 3"
        }
    }
}
