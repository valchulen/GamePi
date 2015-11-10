#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QLabel>
#include "mainwindow.h"

class Thread : public QThread
{
public:
    Thread(QLabel*);
protected:
    void run ();
private:
    QLabel *myLabel = NULL;
    void render ();
};

#endif // THREAD_H
