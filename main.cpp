#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QStyleFactory>
#include <QStyleHints>

class SettingsWindow : public QWidget {
public:
    SettingsWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建主布局
        QHBoxLayout *mainLayout = new QHBoxLayout(this);

        // 左侧标签栏
        QListWidget *listWidget = new QListWidget(this);
        listWidget->setFixedWidth(100);

        // 创建列表项并设置高度
        QListWidgetItem *generalItem = new QListWidgetItem("General");
        QListWidgetItem *audioItem = new QListWidgetItem("Audio");
        QListWidgetItem *videoItem = new QListWidgetItem("Video");
        QListWidgetItem *outputItem = new QListWidgetItem("Output");

        // 设置每个项目的高度
        QSize itemSize = QSize(0, 50); // 修改高度为50px或你希望的高度
        generalItem->setSizeHint(itemSize);
        audioItem->setSizeHint(itemSize);
        videoItem->setSizeHint(itemSize);
        outputItem->setSizeHint(itemSize);

        // 将项目添加到列表中
        listWidget->addItem(generalItem);
        listWidget->addItem(audioItem);
        listWidget->addItem(videoItem);
        listWidget->addItem(outputItem);

        listWidget->setStyleSheet(
            "QListWidget::item:hover { background-color: #e0e0e0; }"  // 悬停时背景颜色
            "QListWidget::item:selected { background-color: #d0d0d0; }"  // 选中时背景颜色
        );

        // 右侧内容区域
        QStackedWidget *stackedWidget = new QStackedWidget(this);

        // General设置页
        QWidget *generalPage = new QWidget(this);
        QVBoxLayout *generalLayout = new QVBoxLayout(generalPage);
        generalLayout->addWidget(new QLabel("General Settings", generalPage));
        stackedWidget->addWidget(generalPage);

        // Audio设置页
        QWidget *audioPage = new QWidget(this);
        QVBoxLayout *audioLayout = new QVBoxLayout(audioPage);
        audioLayout->addWidget(new QLabel("Audio Settings", audioPage));
        stackedWidget->addWidget(audioPage);

        // Video设置页
        QWidget *videoPage = new QWidget(this);
        QVBoxLayout *videoLayout = new QVBoxLayout(videoPage);
        videoLayout->addWidget(new QLabel("Video Settings", videoPage));
        stackedWidget->addWidget(videoPage);

        // Output设置页
        QWidget *outputPage = new QWidget(this);
        QVBoxLayout *outputLayout = new QVBoxLayout(outputPage);
        outputLayout->addWidget(new QLabel("Output Settings", outputPage));
        outputLayout->addWidget(new QPushButton("Hello world"));
        stackedWidget->addWidget(outputPage);

        // 将左侧标签栏和右侧内容区域添加到主布局
        mainLayout->addWidget(listWidget);
        mainLayout->addWidget(stackedWidget);

        // 连接标签选择和内容显示
        connect(listWidget, &QListWidget::currentRowChanged, stackedWidget, &QStackedWidget::setCurrentIndex);

        // 设置初始状态
        listWidget->setCurrentRow(0);

    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    SettingsWindow window;

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(42, 42, 42));
    darkPalette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    app.setPalette(darkPalette);

    window.setWindowTitle("Remotop");
    window.resize(600, 400);
    window.show();

    return app.exec();
}
