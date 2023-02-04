#include "Graphics/render.h"
#include "Graphics/image.h"
#include <iostream>
using namespace std;

int main(void)
{
    int n = 10;
    Image image(n, n);
    Renderer r(image);
    r.PixelShader(1,1);
 
    return 0;
}