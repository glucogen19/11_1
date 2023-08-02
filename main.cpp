#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем основное окно
    QWidget window;

    // Создаем компонент для ввода полного пути файла
    QLineEdit filePathInput;

    // Создаем компонент для отображения выбранного изображения
    QLabel imageLabel;

    // Создаем кнопку для открытия файла
    QPushButton openButton("Open");

    // Размещаем компоненты на форме с помощью вертикального слоя
    QVBoxLayout layout;
    layout.addWidget(&filePathInput);
    layout.addWidget(&openButton);
    layout.addWidget(&imageLabel);

    // Устанавливаем вертикальный слой в качестве основного макета окна
    window.setLayout(&layout);

    // Соединяем нажатие на кнопку с открытием изображения
    QObject::connect(&openButton, &QPushButton::clicked, [&]() {
        // Получаем текст из QLineEdit - полный путь к файлу
        QString filePath = filePathInput.text();

        // Если путь не пустой, то отображаем изображение
        if (!filePath.isEmpty()) {
            QPixmap image(filePath);

            // Отображаем изображение в компоненте QLabel
            imageLabel.setPixmap(image.scaled(300, 300, Qt::KeepAspectRatio));
        }
    });

    // Показываем окно
    window.show();

    // Запускаем цикл обработки событий
    return a.exec();
}
