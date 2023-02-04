#include "Graphics/Color.h"
#include "Graphics/vec3.h"
#include "Graphics/ray.h"
#include "Graphics/image.h"
using namespace std;

int main(void)
{

    double a = 1.0;
    uint8_t t = static_cast<int>(a * 255.999f);
    cout << (unsigned)t << endl;

}