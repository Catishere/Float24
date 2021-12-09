#include "float24.h"

#include <iostream>

int main()
{
    int start, end, n;
    int counter = 0;
    Float24 f24_temp_all(0.0f);
    Float24 f24_temp_interval(0.0f);
    std::cin >> start >> end >> n;
    for (int i = 0; i < n; ++i) {
        int time = -1;
        float temp;
        while (time > 23 || time < 0)
            std::cin >> time >> temp;
        Float24 f24_temp2(temp);
        f24_temp_all += f24_temp2;
        if (time >= start && time <= end) {
            counter++;
            f24_temp_interval += f24_temp2;
        }
    }

    f24_temp_all  /= Float24(static_cast<float>(n));
    f24_temp_interval = f24_temp_interval / Float24(static_cast<float>(counter));

    bool rounded_equal = f24_temp_all.equals(f24_temp_interval, 2);
    std::cout << f24_temp_all << " " << f24_temp_interval << (rounded_equal ? " equal" : " different") << std::endl;

    return 0;
}
