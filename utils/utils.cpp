#include <cmath>
#include <limits>
#include <memory>

#include "../Graphics/ray.h"
#include "../Graphics/vec3.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180.0;
}
