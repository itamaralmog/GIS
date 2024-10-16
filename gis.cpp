#include "gis.hpp"

#include <iostream>
#include <cmath>
#include <map>
#include <thread>
#include <mutex>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

std::map<std::thread::id, int> thread_ids;
std::mutex id_mutex;
int id_counter = 1;

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    double Dlat = lat2 - lat1;
    double Dlon = lon2 - lon1;

    double a1 = pow(sin(Dlat/2), 2);
    double a2 = cos(lat1) * cos(lat2) * pow(sin(Dlon/2), 2);
    double a = a1 + a2;

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

void threadTask(const std::vector<std::pair<double, double>>& coords, int start, int end, std::mutex& mtx) {

    {
        std::lock_guard<std::mutex> lock(id_mutex);
        if (thread_ids.find(std::this_thread::get_id()) == thread_ids.end()) {
            thread_ids[std::this_thread::get_id()] = id_counter++;
        }
    }

    for (int i = start; i < end; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread ID: " << thread_ids[std::this_thread::get_id()] 
                  << "| Distance between point " << i << " and " << i+1 << ": " 
                  << haversine(coords[i].first, coords[i].second, coords[i+1].first, coords[i+1].second) 
                  << " km" << std::endl;
    }
}
