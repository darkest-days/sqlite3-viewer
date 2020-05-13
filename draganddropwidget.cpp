#include "draganddropwidget.h"

DragAndDropWidget::DragAndDropWidget(QWidget *parent) : QWidget(parent)
{
    setAcceptDrops(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *ql = new QLabel("Drag and Drop here!",this);

    layout->addWidget(ql);

}

DragAndDropWidget::~DragAndDropWidget()
{
}

void DragAndDropWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/plain")){
        qDebug() << "dragEnterEvent";
        event->acceptProposedAction();
    }
}

void DragAndDropWidget::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    // check for our needed mime type, here a file or a list of files
    if (mimeData->hasUrls())
    {
        QStringList pathList;
        QList<QUrl> urlList = mimeData->urls();

        QString dbPath = urlList.first().toLocalFile();

        if(fileCanBeOpened(dbPath)){
            emit filePathRecived(dbPath);
        }
    }
}

void DragAndDropWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
    QString dbPath = QFileDialog::getOpenFileName(nullptr,tr("Open file"), "/home", tr("Any files (*)"));
//    ui->File1Path->setText(file1Name);


    if(Utils::fileCanBeOpened(dbPath)){
        emit filePathRecived(dbPath);
    }
}

//bool DragAndDropWidget::fileCanBeOpened(const QString &path) const{
//    QFile dbFile(path);
//    dbFile.open(QIODevice::ReadOnly);
//    if(!dbFile.isOpen()){
//        qDebug() << "File can't be opened, path: " << path;
//        return false;
//    }

//    return  true;
//}
