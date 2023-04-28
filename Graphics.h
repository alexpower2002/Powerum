//
// Created by Alex Dol on 07.01.2023.
//

#pragma once

#include "Point.h"
#include "Rectangle.h"

class Graphics {
public:
    static void GaussianBlur(Point p1, Point p2);
    static void DrawAACircle2(Point Start, Point End);
    static void DrawAACircle(Point Start, Point End);
    static void Blur(Point p1, Point p2, int Radius);
    static void DrawCircle(Point Center, int Radius, RGB Color);
    static void put_aa_pixel(double x, double y, RGB Color);
    static void DrawWuLine(int X0, int Y0, int X1, int Y1, RGB clrLine);
    static void PunctLineV(Point p1, Point p2, RGB nc, RGB pc, int punctLen);
    static void HomeButton();
};

