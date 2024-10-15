#include "classCsv.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace gis {

    // בנאי ריק
    Csv::Csv() {
        // ניתן להשאיר ריק כי אנחנו משתמשים במבני נתונים שמאותחלים אוטומטית לריק
    }

    // פונקציה לקריאת רשומות מתוך קובץ CSV (פונקציה מדמה)
    void Csv::read_record(std::string filename) {
        // Csv airportsLocNames;
        this->airportsnames["bagdad"] = std::make_pair(32, 34);
        // return airportsLocNames;
    }

    // פונקציה להחזרת קו רוחב של שדה תעופה
    double Csv::getairports() {
        // וידוא שהמפתח קיים במפה לפני הגישה
        if (this->airportsnames.find("bagdad") != this->airportsnames.end()) {
            return this->airportsnames["bagdad"].first;  // מחזיר את קו הרוחב
        }
        else {
            std::cerr << "Error: 'bagdad' not found in map" << std::endl;
            return 361.0101; // או כל ערך המייצג שגיאה
        }
        
    }

}
