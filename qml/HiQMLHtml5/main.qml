import QtQuick 1.0
import CustomComponents 1.0

import "content"

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    Component.onCompleted: {
//        myWebView.loadFile("html/index.html")
    }

    Flickable {
        id: webView
        width: parent.width
        contentWidth: myWebView.width // Math.max(parent.width,myWebView.width)
        contentHeight: myWebView.height // Math.max(parent.height,myWebView.height)

        MyWebView {
            id: myWebView
            anchors.fill: parent
    //        url: "http://www.google.com"
            url: "html/index.html"
        }
    }

    ScrollBar {
        scrollArea: webView; width: 8
        anchors { right: parent.right; top: header.bottom; bottom: parent.bottom }
    }

    ScrollBar {
        scrollArea: webView; height: 8; orientation: Qt.Horizontal
        anchors { right: parent.right; rightMargin: 8; left: parent.left; bottom: parent.bottom }
    }

    Line {
        id: diagonalLine

        Behavior on x1 { NumberAnimation { duration: 1000 } }
        Behavior on y1 { NumberAnimation { duration: 1000 } }
        Behavior on x2 { NumberAnimation { duration: 1000 } }
        Behavior on y2 { NumberAnimation { duration: 1000 } }

        x1: parent.x + 20; y1: parent.height / 2
        x2: parent.width - 20; y2: parent.height / 2
        color: "tomato"; penWidth: 3; smooth: true
    }
//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();
//        }
//    }
}
