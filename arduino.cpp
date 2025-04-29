#include "arduino.h"

Arduino::Arduino()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}
int Arduino::connect_arduino() {
    qDebug() << "=== Connection Attempt ===";

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Found port:" << info.portName();
        qDebug() << "VID:" << info.vendorIdentifier();
        qDebug() << "PID:" << info.productIdentifier();

        if(info.vendorIdentifier() == 6790 && info.productIdentifier() == 29987) {
            arduino_port_name = info.portName();
            arduino_is_available = true;
            qDebug() << "Matched on port:" << arduino_port_name;
            break;
        }
    }

    if(arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if(serial->open(QIODevice::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Successfully opened port";
            return 0;
        }
        qDebug() << "Failed to open port:" << serial->errorString();
    }
    return -1;
}

int Arduino::close_arduino()
{
    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data = serial->readAll();
        return data;
    }
    return QByteArray();
}

void Arduino::write_to_arduino(QByteArray d)
{
    if(serial->isWritable()){
        serial->write(d);
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}
