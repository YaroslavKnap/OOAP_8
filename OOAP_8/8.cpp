#include <iostream>
#include <string>

// Інтерфейс Phone (Цільовий інтерфейс)
class Phone {
public:
    virtual void MakeCall(const std::string& number) = 0; // Метод для виклику
    virtual ~Phone() = default;
};

// Клас VideoCamera (Клас, який потрібно адаптувати)
class VideoCamera {
public:
    void StartVideoCall(const std::string& videoId) {
        std::cout << "Starting video call with video ID: " << videoId << std::endl;
    }
};
//дозволяє узгодити
// Adapter (Адаптер для VideoCamera, який підключає її до Phone)
class VideoCameraAdapter : public Phone {
private:
    VideoCamera* camera; // Вказівник на адаптований клас
public:
    VideoCameraAdapter(VideoCamera* cam) : camera(cam) {}

    void MakeCall(const std::string& number) override {
        std::cout << "Adapting call to video..." << std::endl;
        // Використовуємо ID як параметр для відеодзвінка
        camera->StartVideoCall(number);
    }
};

// Клас для звичайного телефонного виклику
class RegularPhone : public Phone {
public:
    void MakeCall(const std::string& number) override {
        std::cout << "Making a regular phone call to: " << number << std::endl;
    }
};

// Головна функція
int main() {
    // Створюємо звичайний телефон
    RegularPhone regularPhone;
    regularPhone.MakeCall("123-456-789");

    // Створюємо відеокамеру та адаптер
    VideoCamera videoCamera;
    VideoCameraAdapter videoAdapter(&videoCamera);

    // Використовуємо адаптер для відеодзвінка
    videoAdapter.MakeCall("VideoCall123");

    return 0;
}
