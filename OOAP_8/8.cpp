#include <iostream>
#include <string>

// ��������� Phone (ֳ������ ���������)
class Phone {
public:
    virtual void MakeCall(const std::string& number) = 0; // ����� ��� �������
    virtual ~Phone() = default;
};

// ���� VideoCamera (����, ���� ������� ����������)
class VideoCamera {
public:
    void StartVideoCall(const std::string& videoId) {
        std::cout << "Starting video call with video ID: " << videoId << std::endl;
    }
};
//�������� ��������
// Adapter (������� ��� VideoCamera, ���� ������� �� �� Phone)
class VideoCameraAdapter : public Phone {
private:
    VideoCamera* camera; // �������� �� ����������� ����
public:
    VideoCameraAdapter(VideoCamera* cam) : camera(cam) {}

    void MakeCall(const std::string& number) override {
        std::cout << "Adapting call to video..." << std::endl;
        // ������������� ID �� �������� ��� ����������
        camera->StartVideoCall(number);
    }
};

// ���� ��� ���������� ����������� �������
class RegularPhone : public Phone {
public:
    void MakeCall(const std::string& number) override {
        std::cout << "Making a regular phone call to: " << number << std::endl;
    }
};

// ������� �������
int main() {
    // ��������� ��������� �������
    RegularPhone regularPhone;
    regularPhone.MakeCall("123-456-789");

    // ��������� ���������� �� �������
    VideoCamera videoCamera;
    VideoCameraAdapter videoAdapter(&videoCamera);

    // ������������� ������� ��� ����������
    videoAdapter.MakeCall("VideoCall123");

    return 0;
}
