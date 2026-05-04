import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Привіт, світ!")

    Text {
        anchors.centerIn: parent
        text: qsTr("Привіт, світ!")
        font.pixelSize: 32
    }
}
