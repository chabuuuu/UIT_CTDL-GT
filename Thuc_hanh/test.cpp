#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string title;
    std::string data;
    std::string line;
    int newsCount = 1;  // Số thứ tự của tin tức

    // Mở tệp để đọc dữ liệu
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cout << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Mở tệp để ghi dữ liệu
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cout << "Failed to open the output file." << std::endl;
        inputFile.close();
        return 1;
    }

    while (std::getline(inputFile, line)) {
        if (line.find('[') == 0 && line.find(']') != std::string::npos) {
            // Tìm vị trí của dấu '[' và ']'
            size_t titleStart = line.find('[') + 1;
            size_t titleEnd = line.find(']');

            // Lấy nội dung trong dấu '[' và ']'
            title = line.substr(titleStart, titleEnd - titleStart);

            // Đọc dòng tiếp theo để lấy dữ liệu
            std::getline(inputFile, line);
            if (line.find('[') != std::string::npos) {
                // Tạo biến để lưu dữ liệu trong dấu '[' và ']'
                std::string tempData;

                // Lặp qua các dòng để lấy dữ liệu cho đến khi gặp dấu ']'
                while (line.find(']') == std::string::npos) {
                    tempData += line + "\n";
                    std::getline(inputFile, line);
                }

                // Tìm vị trí của dấu '[' trong dữ liệu tạm thời
                size_t dataStart = tempData.find('[') + 1;

                // Lấy nội dung trong dấu '[' và ']'
                data = tempData.substr(dataStart);

                // Xuất kết quả vào tệp
                outputFile << "\"" << newsCount << "\": {\"title\":\"" << title << "\",\"data\":\"" << data << "\",\"__collections__\":{}},\n";
                newsCount++;
            }
        }
    }

    // Đóng tệp
    inputFile.close();
    outputFile.close();

    return 0;
}
