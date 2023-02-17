import QtQuick
import QtQuick.Window
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    color: "azure"
    title: qsTr("CryptoInfomation")
    ColumnLayout{
        id: columnLayout
        spacing: 10
        RowLayout{
            id: rowBlance
            spacing: 10
            Text {
                id: textBalance
                text: qsTr("Balance:")
                font.family: "Ubuntu"
                font.pixelSize: 28
            }
            Text {
                focus: true
                id: balance
                text: qsTr("100")
                Keys.onSpacePressed: {
                    balance.text = ''
                }
                font.family: "Ubuntu"
                font.pixelSize: 28
            }
            Text {
                id: currency
                text: qsTr("USD")
                font.family: "Ubuntu"
                font.pixelSize: 28
            }

        }

        Rectangle{
            id: recChart
            Text {
                id: chartText
                text: qsTr("Chart")
            }
        }
    }
}
