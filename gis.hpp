#ifndef GIS_HPP
#define GIS_HPP

#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <map>

const double R = 6371.0;

double toRadians(double degree);
double haversine(double lat1, double lon1, double lat2, double lon2);
void threadTask(const std::vector<std::pair<double, double>>& coords, int start, int end, std::mutex& mtx);

extern std::map<std::thread::id, int> thread_ids;
extern std::mutex id_mutex;
extern int id_counter;

#endif
