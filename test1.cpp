#include <iostream>
#include "qrcodegen.h"

using namespace qrcodegen;

int main() {
    std::string text;
    std::cout << "Enter text to encode as QR code: ";
    std::cin >> text;

    const int qrVersion = 1;
    const QRErrorCorrectionLevel qrErrorCorrectionLevel = QRErrorCorrectionLevel::LOW;
    QRCode qr = QRCode::encodeText(text.c_str(), qrErrorCorrectionLevel);

    const int qrSize = qr.getSize();
    for (int y = 0; y < qrSize; y++) {
        for (int x = 0; x < qrSize; x++) {
            const bool qrModule = qr.getModule(x, y);
            std::cout << (qrModule ? "██" : "  ");
        }
        std::cout << std::endl;
    }

    return 0;
}
