#include "Graphics/Color.h"
#include "Graphics/vec3.h"
#include "Graphics/ray.h"
#include "Graphics/image.h"
#include "Graphics/render.h"
#include <iostream>
using namespace std;

int main(void)
{
    int n = 10;
    Image image(n, n);
    Color color(1, 1, 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            coord c(j, i);
            image.SetColor(c, color);
        }
    }
    int count = 0;
    Renderer r(image);
    r.render();
    image.FreeImage();
    return 0;
}