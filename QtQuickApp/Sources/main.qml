import QtQuick
import QtQuick.Window
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    color: "azure"
    title: qsTr("CryptoInfomation")
    objectName: "MainWindow"
    ColumnLayout{
        objectName: "ColumnLayout"
        id: columnLayout
        spacing: 10
        RowLayout{
            id: rowBlance
            spacing: 10
            Layout.topMargin: 10
            Text {
                id: textBalance
                Layout.leftMargin: 10
                text: qsTr("Balance:")
                font.family: "Ubuntu"
                font.pixelSize: 20
            }
            Text {
                focus: true
                id: balance                
                text: qsTr("100")
                Keys.onSpacePressed: {
                    balance.text = ''
                }
                font.family: "Ubuntu"
                font.pixelSize: 20
            }
            Text {
                id: currency
                text: qsTr("USD")
                font.family: "Ubuntu"
                font.pixelSize: 20
            }

        }

        Rectangle{
            id: kLineChart
            Layout.leftMargin: 10
            Text {
                id: chartText
                Layout.leftMargin: parent.leftMargin
                text: qsTr("Chart:")
                font.family: "Ubuntu"
                font.pixelSize: 20
            }

        }

        function updateBalance(msg: string) {
            balance.text = qsTr(msg)
        }

        function updateKLineChart(sData: string) {
            console.log("KLine Data: " + sData)
        }
    }
}
