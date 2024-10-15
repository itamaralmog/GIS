#ifndef CSV_
#define CSV_
#include <map>
#include <vector>
#include <string>

namespace gis{
    class Csv
    {
        private:
            std::map<std::string,std::pair<double,double>> airportsnames;
            std::vector<std::pair<double,double>> airports;
        public:

            Csv();
            void read_record(std::string filename);
            double getairports();

    };
}

#endif
