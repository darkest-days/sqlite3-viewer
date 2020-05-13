#ifndef DRAGANDDROPWIDGET_H
#define DRAGANDDROPWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QLayout>

class DragAndDropWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DragAndDropWidget(QWidget *parent = nullptr);
    ~DragAndDropWidget();
signals:
    void filePathRecived(const QString& path);
public slots:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QString dbPath;

    bool fileCanBeOpened(const QString &path) const;
};

#endif // DRAGANDDROPWIDGET_H
