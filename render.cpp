#include "Graphics/render.h"
Renderer::Renderer(const Image image)
        :
        image(image)
    {}

void Renderer::render()
{
    uint8_t* rgb_val;
    for(auto i = image.GetHeight() - 1; i-- > 0; )
    {
        for(auto j = 0; j < image.GetWidth(); ++j)
        {
            coord c(j, i);
            rgb_val = image.GetRGB(i, j);
            std::cout << (unsigned)rgb_val[0] << " "
                        << (unsigned)rgb_val[1] << " "
                        << (unsigned)rgb_val[2] << "\n";
        }
    }
}

void Renderer::PixelShader(const uint32_t x, const uint32_t y)
{
    std::cout << "HELLO\n";
}
void Renderer::PixelShader(const coord c)
{

}