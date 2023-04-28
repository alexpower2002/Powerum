//
// Created by Alex Dol on 30.11.2022.
//

#pragma once

#include "UIView.h"
#include "FileSystem.h"
#include "Display.h"
#include "Utils.h"

class UIImage: public UIView {
public:
    File* img;
    void Draw() override;
    void LoadImage(char* filename);
};
