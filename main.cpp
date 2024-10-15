#include "gis.hpp"
#include "classCsv.hpp"

#include <vector>
#include <iostream>
#include <thread>
#include <mutex>

int main() {
    std::vector<std::pair<double, double>> coordinates = {
        {32.0853, 34.7818}, // Tel Aviv
        {40.7128, -74.0060}, // New York
        {48.8566, 2.3522}    // Paris
    };

    std::mutex mtx;
    std::thread t1(threadTask, std::ref(coordinates), 0, 2, std::ref(mtx));
    std::thread t2(threadTask, std::ref(coordinates), 1, 3, std::ref(mtx));

    t1.join();
    t2.join();

    gis::Csv obj1;
    obj1.read_record("vbe");
    std::cout << obj1.getairports() << std::endl;
}
