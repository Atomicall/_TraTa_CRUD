/********************************************************************************
** Form generated from reading UI file 'authentication_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATION_DIALOG_H
#define UI_AUTHENTICATION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Authentication_dialog
{
public:
    QGroupBox *groupBox;
    QLineEdit *login_LineEdit;
    QLineEdit *pass_LineEdit;
    QLabel *login_Label;
    QLabel *pass_Label;
    QDialogButtonBox *DialogButtonBox;
    QCheckBox *remember_CB;

    void setupUi(QDialog *Authentication_dialog)
    {
        if (Authentication_dialog->objectName().isEmpty())
            Authentication_dialog->setObjectName(QString::fromUtf8("Authentication_dialog"));
        Authentication_dialog->resize(370, 203);
        groupBox = new QGroupBox(Authentication_dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 351, 181));
        login_LineEdit = new QLineEdit(groupBox);
        login_LineEdit->setObjectName(QString::fromUtf8("login_LineEdit"));
        login_LineEdit->setGeometry(QRect(50, 50, 113, 20));
        pass_LineEdit = new QLineEdit(groupBox);
        pass_LineEdit->setObjectName(QString::fromUtf8("pass_LineEdit"));
        pass_LineEdit->setGeometry(QRect(50, 100, 113, 20));
        login_Label = new QLabel(groupBox);
        login_Label->setObjectName(QString::fromUtf8("login_Label"));
        login_Label->setGeometry(QRect(50, 30, 47, 13));
        pass_Label = new QLabel(groupBox);
        pass_Label->setObjectName(QString::fromUtf8("pass_Label"));
        pass_Label->setGeometry(QRect(50, 80, 71, 16));
        DialogButtonBox = new QDialogButtonBox(groupBox);
        DialogButtonBox->setObjectName(QString::fromUtf8("DialogButtonBox"));
        DialogButtonBox->setGeometry(QRect(180, 140, 161, 32));
        DialogButtonBox->setOrientation(Qt::Horizontal);
        DialogButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        remember_CB = new QCheckBox(groupBox);
        remember_CB->setObjectName(QString::fromUtf8("remember_CB"));
        remember_CB->setGeometry(QRect(50, 130, 101, 17));

        retranslateUi(Authentication_dialog);

        QMetaObject::connectSlotsByName(Authentication_dialog);
    } // setupUi

    void retranslateUi(QDialog *Authentication_dialog)
    {
        Authentication_dialog->setWindowTitle(QCoreApplication::translate("Authentication_dialog", "Dialog", nullptr));
        groupBox->setTitle(QString());
        login_Label->setText(QCoreApplication::translate("Authentication_dialog", "Login", nullptr));
        pass_Label->setText(QCoreApplication::translate("Authentication_dialog", "Password", nullptr));
        remember_CB->setText(QCoreApplication::translate("Authentication_dialog", "rememberMe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authentication_dialog: public Ui_Authentication_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATION_DIALOG_H
