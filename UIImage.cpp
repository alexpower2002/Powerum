//
// Created by Alex Dol on 30.11.2022.
//

#include "UIImage.h"

void UIImage::Draw() {
    Width = Utils::ToInt32(img->Contents, 0);
    Height = Utils::ToInt32(img->Contents, 4);

    for(int y = 0; y < Height; y++)
    {
        for(int x = 0; x < Width; x++)
        {
            auto color = RGB{img->Contents[8+(y*Width+x)*3], img->Contents[8+(y*Width+x)*3+1], img->Contents[8+(y*Width+x)*3+2]};

            Display::SetPixel(Point{Position.X+x, Position.Y+y}, color);
        }
    }
}

void UIImage::LoadImage(char *filename) {
    img = FileSystem::LoadFile(filename);
}
