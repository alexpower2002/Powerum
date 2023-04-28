//
// Created by Alex Dol on 07.01.2023.
//

#include "Graphics.h"

void Graphics::GaussianBlur(Point p1, Point p2)
{
    double** kernel = new double*[21];

    for (int i = 0; i < 21; ++i)
        kernel[i] = new double[21];

    kernel[0][0] = 0;
    kernel[0][1] = 0;
    kernel[0][2] = 0;
    kernel[0][3] = 0;
    kernel[0][4] = 0;
    kernel[0][5] = 0;
    kernel[0][6] = 0;
    kernel[0][7] = 0;
    kernel[0][8] = 0;
    kernel[0][9] = 0;
    kernel[0][10] = 0;
    kernel[0][11] = 0;
    kernel[0][12] = 0;
    kernel[0][13] = 0;
    kernel[0][14] = 0;
    kernel[0][15] = 0;
    kernel[0][16] = 0;
    kernel[0][17] = 0;
    kernel[0][18] = 0;
    kernel[0][19] = 0;
    kernel[0][20] = 0;

    kernel[1][0] = 0;
    kernel[1][1] = 0;
    kernel[1][2] = 0;
    kernel[1][3] = 0;
    kernel[1][4] = 0;
    kernel[1][5] = 0;
    kernel[1][6] = 0;
    kernel[1][7] = 0;
    kernel[1][8] = 0;
    kernel[1][9] = 0;
    kernel[1][10] = 0;
    kernel[1][11] = 0;
    kernel[1][12] = 0;
    kernel[1][13] = 0;
    kernel[1][14] = 0;
    kernel[1][15] = 0;
    kernel[1][16] = 0;
    kernel[1][17] = 0;
    kernel[1][18] = 0;
    kernel[1][19] = 0;
    kernel[1][20] = 0;

    kernel[2][0] = 0;
    kernel[2][1] = 0;
    kernel[2][2] = 0;
    kernel[2][3] = 0;
    kernel[2][4] = 0;
    kernel[2][5] = 0;
    kernel[2][6] = 0;
    kernel[2][7] = 0;
    kernel[2][8] = 0;
    kernel[2][9] = 0;
    kernel[2][10] = 0;
    kernel[2][11] = 0;
    kernel[2][12] = 0;
    kernel[2][13] = 0;
    kernel[2][14] = 0;
    kernel[2][15] = 0;
    kernel[2][16] = 0;
    kernel[2][17] = 0;
    kernel[2][18] = 0;
    kernel[2][19] = 0;
    kernel[2][20] = 0;

    kernel[3][0] = 0;
    kernel[3][1] = 0;
    kernel[3][2] = 0;
    kernel[3][3] = 0;
    kernel[3][4] = 0;
    kernel[3][5] = 0;
    kernel[3][6] = 0;
    kernel[3][7] = 0;
    kernel[3][8] = 0;
    kernel[3][9] = 0;
    kernel[3][10] = 0;
    kernel[3][11] = 0;
    kernel[3][12] = 0;
    kernel[3][13] = 0;
    kernel[3][14] = 0;
    kernel[3][15] = 0;
    kernel[3][16] = 0;
    kernel[3][17] = 0;
    kernel[3][18] = 0;
    kernel[3][19] = 0;
    kernel[3][20] = 0;

    kernel[4][0] = 0;
    kernel[4][1] = 0;
    kernel[4][2] = 0;
    kernel[4][3] = 0;
    kernel[4][4] = 0;
    kernel[4][5] = 0;
    kernel[4][6] = 0;
    kernel[4][7] = 0;
    kernel[4][8] = 0;
    kernel[4][9] = 0;
    kernel[4][10] = 0;
    kernel[4][11] = 0;
    kernel[4][12] = 0;
    kernel[4][13] = 0;
    kernel[4][14] = 0;
    kernel[4][15] = 0;
    kernel[4][16] = 0;
    kernel[4][17] = 0;
    kernel[4][18] = 0;
    kernel[4][19] = 0;
    kernel[4][20] = 0;

    kernel[5][0] = 0;
    kernel[5][1] = 0;
    kernel[5][2] = 0;
    kernel[5][3] = 0;
    kernel[5][4] = 0;
    kernel[5][5] = 0;
    kernel[5][6] = 0;
    kernel[5][7] = 0;
    kernel[5][8] = 0;
    kernel[5][9] = 0.000001;
    kernel[5][10] = 0.000001;
    kernel[5][11] = 0.000001;
    kernel[5][12] = 0;
    kernel[5][13] = 0;
    kernel[5][14] = 0;
    kernel[5][15] = 0;
    kernel[5][16] = 0;
    kernel[5][17] = 0;
    kernel[5][18] = 0;
    kernel[5][19] = 0;
    kernel[5][20] = 0;

    kernel[6][0] = 0;
    kernel[6][1] = 0;
    kernel[6][2] = 0;
    kernel[6][3] = 0;
    kernel[6][4] = 0;
    kernel[6][5] = 0;
    kernel[6][6] = 0;
    kernel[6][7] = 0.000001;
    kernel[6][8] = 0.000014;
    kernel[6][9] = 0.000055;
    kernel[6][10] = 0.000088;
    kernel[6][11] = 0.000055;
    kernel[6][12] = 0.000014;
    kernel[6][13] = 0.000001;
    kernel[6][14] = 0;
    kernel[6][15] = 0;
    kernel[6][16] = 0;
    kernel[6][17] = 0;
    kernel[6][18] = 0;
    kernel[6][19] = 0;
    kernel[6][20] = 0;

    kernel[7][0] = 0;
    kernel[7][1] = 0;
    kernel[7][2] = 0;
    kernel[7][3] = 0;
    kernel[7][4] = 0;
    kernel[7][5] = 0;
    kernel[7][6] = 0.000001;
    kernel[7][7] = 0.000036;
    kernel[7][8] = 0.000362;
    kernel[7][9] = 0.001445;
    kernel[7][10] = 0.002289;
    kernel[7][11] = 0.001445;
    kernel[7][12] = 0.000362;
    kernel[7][13] = 0.000036;
    kernel[7][14] = 0.000001;
    kernel[7][15] = 0;
    kernel[7][16] = 0;
    kernel[7][17] = 0;
    kernel[7][18] = 0;
    kernel[7][19] = 0;
    kernel[7][20] = 0;

    kernel[8][0] = 0;
    kernel[8][1] = 0;
    kernel[8][2] = 0;
    kernel[8][3] = 0;
    kernel[8][4] = 0;
    kernel[8][5] = 0;
    kernel[8][6] = 0.000014;
    kernel[8][7] = 0.000362;
    kernel[8][8] = 0.003672;
    kernel[8][9] = 0.014648;
    kernel[8][10] = 0.023204;
    kernel[8][11] = 0.014648;
    kernel[8][12] = 0.003672;
    kernel[8][13] = 0.000362;
    kernel[8][14] = 0.000014;
    kernel[8][15] = 0;
    kernel[8][16] = 0;
    kernel[8][17] = 0;
    kernel[8][18] = 0;
    kernel[8][19] = 0;
    kernel[8][20] = 0;

    kernel[9][0] = 0;
    kernel[9][1] = 0;
    kernel[9][2] = 0;
    kernel[9][3] = 0;
    kernel[9][4] = 0;
    kernel[9][5] = 0.000001;
    kernel[9][6] = 0.000055;
    kernel[9][7] = 0.001445;
    kernel[9][8] = 0.014648;
    kernel[9][9] = 0.058433;
    kernel[9][10] = 0.092564;
    kernel[9][11] = 0.058433;
    kernel[9][12] = 0.014648;
    kernel[9][13] = 0.001445;
    kernel[9][14] = 0.000055;
    kernel[9][15] = 0.000001;
    kernel[9][16] = 0;
    kernel[9][17] = 0;
    kernel[9][18] = 0;
    kernel[9][19] = 0;
    kernel[9][20] = 0;

    kernel[10][0] = 0;
    kernel[10][1] = 0;
    kernel[10][2] = 0;
    kernel[10][3] = 0;
    kernel[10][4] = 0;
    kernel[10][5] = 0.000001;
    kernel[10][6] = 0.000088;
    kernel[10][7] = 0.002289;
    kernel[10][8] = 0.023204;
    kernel[10][9] = 0.092564;
    kernel[10][10] = 0.146632;
    kernel[10][11] = 0.092564;
    kernel[10][12] = 0.023204;
    kernel[10][13] = 0.002289;
    kernel[10][14] = 0.000088;
    kernel[10][15] = 0.000001;
    kernel[10][16] = 0;
    kernel[10][17] = 0;
    kernel[10][18] = 0;
    kernel[10][19] = 0;
    kernel[10][20] = 0;

    kernel[11][0] = 0;
    kernel[11][1] = 0;
    kernel[11][2] = 0;
    kernel[11][3] = 0;
    kernel[11][4] = 0;
    kernel[11][5] = 0.000001;
    kernel[11][6] = 0.000055;
    kernel[11][7] = 0.001445;
    kernel[11][8] = 0.014648;
    kernel[11][9] = 0.058433;
    kernel[11][10] = 0.092564;
    kernel[11][11] = 0.058433;
    kernel[11][12] = 0.014648;
    kernel[11][13] = 0.001445;
    kernel[11][14] = 0.000055;
    kernel[11][15] = 0.000001;
    kernel[11][16] = 0;
    kernel[11][17] = 0;
    kernel[11][18] = 0;
    kernel[11][19] = 0;
    kernel[11][20] = 0;

    kernel[12][0] = 0;
    kernel[12][1] = 0;
    kernel[12][2] = 0;
    kernel[12][3] = 0;
    kernel[12][4] = 0;
    kernel[12][5] = 0;
    kernel[12][6] = 0.000014;
    kernel[12][7] = 0.000362;
    kernel[12][8] = 0.003672;
    kernel[12][9] = 0.014648;
    kernel[12][10] = 0.023204;
    kernel[12][11] = 0.014648;
    kernel[12][12] = 0.003672;
    kernel[12][13] = 0.000362;
    kernel[12][14] = 0.000014;
    kernel[12][15] = 0;
    kernel[12][16] = 0;
    kernel[12][17] = 0;
    kernel[12][18] = 0;
    kernel[12][19] = 0;
    kernel[12][20] = 0;

    kernel[13][0] = 0;
    kernel[13][1] = 0;
    kernel[13][2] = 0;
    kernel[13][3] = 0;
    kernel[13][4] = 0;
    kernel[13][5] = 0;
    kernel[13][6] = 0.000001;
    kernel[13][7] = 0.000036;
    kernel[13][8] = 0.000362;
    kernel[13][9] = 0.001445;
    kernel[13][10] = 0.002289;
    kernel[13][11] = 0.001445;
    kernel[13][12] = 0.000362;
    kernel[13][13] = 0.000036;
    kernel[13][14] = 0.000001;
    kernel[13][15] = 0;
    kernel[13][16] = 0;
    kernel[13][17] = 0;
    kernel[13][18] = 0;
    kernel[13][19] = 0;
    kernel[13][20] = 0;

    kernel[14][0] = 0;
    kernel[14][1] = 0;
    kernel[14][2] = 0;
    kernel[14][3] = 0;
    kernel[14][4] = 0;
    kernel[14][5] = 0;
    kernel[14][6] = 0;
    kernel[14][7] = 0.000001;
    kernel[14][8] = 0.000014;
    kernel[14][9] = 0.000055;
    kernel[14][10] = 0.000088;
    kernel[14][11] = 0.000055;
    kernel[14][12] = 0.000014;
    kernel[14][13] = 0.000001;
    kernel[14][14] = 0;
    kernel[14][15] = 0;
    kernel[14][16] = 0;
    kernel[14][17] = 0;
    kernel[14][18] = 0;
    kernel[14][19] = 0;
    kernel[14][20] = 0;

    kernel[15][0] = 0;
    kernel[15][1] = 0;
    kernel[15][2] = 0;
    kernel[15][3] = 0;
    kernel[15][4] = 0;
    kernel[15][5] = 0;
    kernel[15][6] = 0;
    kernel[15][7] = 0;
    kernel[15][8] = 0;
    kernel[15][9] = 0.000001;
    kernel[15][10] = 0.000001;
    kernel[15][11] = 0.000001;
    kernel[15][12] = 0;
    kernel[15][13] = 0;
    kernel[15][14] = 0;
    kernel[15][15] = 0;
    kernel[15][16] = 0;
    kernel[15][17] = 0;
    kernel[15][18] = 0;
    kernel[15][19] = 0;
    kernel[15][20] = 0;

    kernel[16][0] = 0;
    kernel[16][1] = 0;
    kernel[16][2] = 0;
    kernel[16][3] = 0;
    kernel[16][4] = 0;
    kernel[16][5] = 0;
    kernel[16][6] = 0;
    kernel[16][7] = 0;
    kernel[16][8] = 0;
    kernel[16][9] = 0;
    kernel[16][10] = 0;
    kernel[16][11] = 0;
    kernel[16][12] = 0;
    kernel[16][13] = 0;
    kernel[16][14] = 0;
    kernel[16][15] = 0;
    kernel[16][16] = 0;
    kernel[16][17] = 0;
    kernel[16][18] = 0;
    kernel[16][19] = 0;
    kernel[16][20] = 0;

    kernel[17][0] = 0;
    kernel[17][1] = 0;
    kernel[17][2] = 0;
    kernel[17][3] = 0;
    kernel[17][4] = 0;
    kernel[17][5] = 0;
    kernel[17][6] = 0;
    kernel[17][7] = 0;
    kernel[17][8] = 0;
    kernel[17][9] = 0;
    kernel[17][10] = 0;
    kernel[17][11] = 0;
    kernel[17][12] = 0;
    kernel[17][13] = 0;
    kernel[17][14] = 0;
    kernel[17][15] = 0;
    kernel[17][16] = 0;
    kernel[17][17] = 0;
    kernel[17][18] = 0;
    kernel[17][19] = 0;
    kernel[17][20] = 0;

    kernel[18][0] = 0;
    kernel[18][1] = 0;
    kernel[18][2] = 0;
    kernel[18][3] = 0;
    kernel[18][4] = 0;
    kernel[18][5] = 0;
    kernel[18][6] = 0;
    kernel[18][7] = 0;
    kernel[18][8] = 0;
    kernel[18][9] = 0;
    kernel[18][10] = 0;
    kernel[18][11] = 0;
    kernel[18][12] = 0;
    kernel[18][13] = 0;
    kernel[18][14] = 0;
    kernel[18][15] = 0;
    kernel[18][16] = 0;
    kernel[18][17] = 0;
    kernel[18][18] = 0;
    kernel[18][19] = 0;
    kernel[18][20] = 0;

    kernel[19][0] = 0;
    kernel[19][1] = 0;
    kernel[19][2] = 0;
    kernel[19][3] = 0;
    kernel[19][4] = 0;
    kernel[19][5] = 0;
    kernel[19][6] = 0;
    kernel[19][7] = 0;
    kernel[19][8] = 0;
    kernel[19][9] = 0;
    kernel[19][10] = 0;
    kernel[19][11] = 0;
    kernel[19][12] = 0;
    kernel[19][13] = 0;
    kernel[19][14] = 0;
    kernel[19][15] = 0;
    kernel[19][16] = 0;
    kernel[19][17] = 0;
    kernel[19][18] = 0;
    kernel[19][19] = 0;
    kernel[19][20] = 0;

    kernel[20][0] = 0;
    kernel[20][1] = 0;
    kernel[20][2] = 0;
    kernel[20][3] = 0;
    kernel[20][4] = 0;
    kernel[20][5] = 0;
    kernel[20][6] = 0;
    kernel[20][7] = 0;
    kernel[20][8] = 0;
    kernel[20][9] = 0;
    kernel[20][10] = 0;
    kernel[20][11] = 0;
    kernel[20][12] = 0;
    kernel[20][13] = 0;
    kernel[20][14] = 0;
    kernel[20][15] = 0;
    kernel[20][16] = 0;
    kernel[20][17] = 0;
    kernel[20][18] = 0;
    kernel[20][19] = 0;
    kernel[20][20] = 0;

    RGB* TempStore = new RGB[6000];

    int si = 0;

    RGB** TempValues = new RGB*[21];

    for (int i = 0; i < 21; ++i)
        TempValues[i] = new RGB[21];

    for (int i = p1.X; i <= p2.X; i++)
    {
        for (int j = p1.Y; j <= p2.Y; j++)
        {
            int vi = 0;
            int vj = 0;

            for (int k = i - 10; k <= i + 10; k++)
            {
                for (int l = j - 10; l <= j + 10; l++)
                {
                    TempValues[vi][vj] = Display::GetPixel(Point{ k,l });

                    vi++;
                }

                vi = 0;
                vj++;
            }

            double nvR = 0;
            double nvG = 0;
            double nvB = 0;

            for (int ki = 0; ki < 21; ki++)
            {
                for (int kj = 0; kj < 21; kj++)
                {
                    nvR += ((double)TempValues[ki][kj].Red / 255) * kernel[ki][kj];
                    nvG += ((double)TempValues[ki][kj].Green / 255) * kernel[ki][kj];
                    nvB += ((double)TempValues[ki][kj].Blue / 255) * kernel[ki][kj];
                }
            }

            TempStore[si] = RGB{ nvR * 255, nvG * 255, nvB * 255 };

            si++;
        }
    }

    si = 0;

    for (int i = p1.X; i <= p2.X; i++)
    {
        for (int j = p1.Y; j <= p2.Y; j++)
        {
            Display::SetPixel(Point{ i,j }, TempStore[si]);

            si++;
        }
    }
}

void Graphics::DrawAACircle2(Point Start, Point End)
{
    double Radius = (End.Y - Start.Y) / 2;

    for (int y = -Radius; y <= Radius; y++)
    {
        double x = Math::sqrt(Radius * Radius - y * y);

        put_aa_pixel(x + Start.X, y + Start.Y, RGB{ 0xc0,0xc0,0xc0 });
        put_aa_pixel(-x + Start.X, y + Start.Y, RGB{ 0xc0,0xc0,0xc0 });
    }
}

void Graphics::DrawAACircle(Point Start, Point End)
{
    double Radius = (End.X - Start.X) / 2;

    for (int x = -Radius; x <= Radius; x++)
    {
        double y = Math::sqrt(Radius * Radius - x * x);

        put_aa_pixel(x + Start.X, y + Start.Y, RGB{ 0xc0,0xc0,0xc0 });
        put_aa_pixel(x + Start.X, -y + Start.Y, RGB{ 0xc0,0xc0,0xc0 });
    }

    DrawAACircle2(Start, End);
}

void Graphics::Blur(Point p1, Point p2, int Radius)
{
    RGB* TempStore = new RGB[16000];

    int si = 0;

    RGB** TempValues = new RGB*[Radius * 2 + 1];

    for (int i = 0; i < Radius * 2 + 1; ++i)
        TempValues[i] = new RGB[Radius * 2 + 1];

    for (int i = p1.X; i <= p2.X; i++)
    {
        for (int j = p1.Y; j <= p2.Y; j++)
        {
            int vi = 0;
            int vj = 0;

            for (int k = i - Radius; k <= i + Radius; k++)
            {
                for (int l = j - Radius; l <= j + Radius; l++)
                {
                    TempValues[vi][vj] = Display::GetPixel(Point{ k,l });

                    vi++;
                }

                vi = 0;
                vj++;
            }

            double nvR = 0;
            double nvG = 0;
            double nvB = 0;

            for (int ki = 0; ki < Radius * 2 + 1; ki++)
            {
                for (int kj = 0; kj < Radius * 2 + 1; kj++)
                {
                    nvR += (double)TempValues[ki][kj].Red;
                    nvG += (double)TempValues[ki][kj].Green;
                    nvB += (double)TempValues[ki][kj].Blue;
                }
            }

            nvR /= (Radius * 2 + 1)*(Radius * 2 + 1);
            nvG /= (Radius * 2 + 1)*(Radius * 2 + 1);
            nvB /= (Radius * 2 + 1)*(Radius * 2 + 1);

            TempStore[si] = RGB{ nvR, nvG, nvB };

            si++;
        }
    }

    si = 0;

    for (int i = p1.X; i <= p2.X; i++)
    {
        for (int j = p1.Y; j <= p2.Y; j++)
        {
            Display::SetPixel(Point{ i,j }, TempStore[si]);

            si++;
        }
    }
}

const double PI = 3.14159265358979323846;

void Graphics::DrawCircle(Point Center, int Radius, RGB Color)
{
    double step = 2 * PI / 1000;

    for (double theta = 0; theta < 2 * PI; theta += step)
    {
        int x = Center.X + Radius * Math::cos(theta);
        int y = Center.Y - Radius * Math::sin(theta);

        DrawWuLine(Center.X, Center.Y, x, y, Color);
    }
}

void Graphics::put_aa_pixel(double x, double y, RGB Color)
{
    int x0 = x;
    int x1 = x0 + 1;
    int y0 = y;
    int y1 = y0 + 1;

    double weight_x1 = x - x0;
    double weight_x0 = 1 - weight_x1;
    double weight_y1 = y - y0;
    double weight_y0 = 1 - weight_y1;

    Display::SetPixel(Point{ x0, y0 }, Display::AlphaBlend(Color, Display::GetPixel(Point{ x0, y0 }), weight_x0 * weight_y0));
    Display::SetPixel(Point{ x1, y0 }, Display::AlphaBlend(Color, Display::GetPixel(Point{ x1, y0 }), weight_x1 * weight_y0));
    Display::SetPixel(Point{ x0, y1 }, Display::AlphaBlend(Color, Display::GetPixel(Point{ x0, y1 }), weight_x0 * weight_y1));
    Display::SetPixel(Point{ x1, y1 }, Display::AlphaBlend(Color, Display::GetPixel(Point{ x1, y1 }), weight_x1 * weight_y1));
}

void Graphics::DrawWuLine(int X0, int Y0, int X1, int Y1, RGB clrLine)
{
    if (Y0 > Y1)
    {
        int Temp = Y0; Y0 = Y1; Y1 = Temp;
        Temp = X0; X0 = X1; X1 = Temp;
    }

    Display::SetPixel(Point{ X0, Y0 }, clrLine);

    int XDir, DeltaX = X1 - X0;
    if (DeltaX >= 0)
    {
        XDir = 1;
    }
    else
    {
        XDir = -1;
        DeltaX = 0 - DeltaX;
    }

    int DeltaY = Y1 - Y0;
    if (DeltaY == 0)
    {
        while (DeltaX-- != 0)
        {
            X0 += XDir;
            Display::SetPixel(Point{ X0, Y0 }, clrLine);
        }
        return;
    }
    if (DeltaX == 0)
    {
        do
        {
            Y0++;
            Display::SetPixel(Point{ X0, Y0 }, clrLine);
        } while (--DeltaY != 0);
        return;
    }

    if (DeltaX == DeltaY)
    {
        do
        {
            X0 += XDir;
            Y0++;
            Display::SetPixel(Point{ X0, Y0 }, clrLine);
        } while (--DeltaY != 0);
        return;
    }

    unsigned short ErrorAdj;
    unsigned short ErrorAccTemp, Weighting;

    unsigned short ErrorAcc = 0;

    unsigned char rl = clrLine.Red;
    unsigned char gl = clrLine.Green;
    unsigned char bl = clrLine.Blue;
    double grayl = rl * 0.299 + gl * 0.587 + bl * 0.114;

    if (DeltaY > DeltaX)
    {
        ErrorAdj = ((unsigned long)DeltaX << 16) / (unsigned long)DeltaY;
        while (--DeltaY) {
            ErrorAccTemp = ErrorAcc;
            ErrorAcc += ErrorAdj;
            if (ErrorAcc <= ErrorAccTemp) {
                X0 += XDir;
            }
            Y0++;
            Weighting = ErrorAcc >> 8;

            RGB clrBackGround = Display::GetPixel(Point{ X0, Y0 });
            unsigned char rb = clrBackGround.Red;
            unsigned char gb = clrBackGround.Green;
            unsigned char bb = clrBackGround.Blue;
            double grayb = rb * 0.299 + gb * 0.587 + bb * 0.114;

            unsigned char rr = (rb > rl ? ((unsigned char)(((double)(grayl < grayb ? Weighting :
                                                                     (Weighting ^ 255))) / 255.0 * (rb - rl) + rl)) :
                                ((unsigned char)(((double)(grayl < grayb ? Weighting : (Weighting ^ 255)))
                                                 / 255.0 * (rl - rb) + rb)));
            unsigned char gr = (gb > gl ? ((unsigned char)(((double)(grayl < grayb ? Weighting :
                                                                     (Weighting ^ 255))) / 255.0 * (gb - gl) + gl)) :
                                ((unsigned char)(((double)(grayl < grayb ? Weighting : (Weighting ^ 255)))
                                                 / 255.0 * (gl - gb) + gb)));
            unsigned char br = (bb > bl ? ((unsigned char)(((double)(grayl < grayb ? Weighting :
                                                                     (Weighting ^ 255))) / 255.0 * (bb - bl) + bl)) :
                                ((unsigned char)(((double)(grayl < grayb ? Weighting : (Weighting ^ 255)))
                                                 / 255.0 * (bl - bb) + bb)));
            Display::SetPixel(Point{ X0, Y0 }, RGB{ rr, gr, br });

            clrBackGround = Display::GetPixel(Point{ X0 + XDir, Y0 });
            rb = clrBackGround.Red;
            gb = clrBackGround.Green;
            bb = clrBackGround.Blue;
            grayb = rb * 0.299 + gb * 0.587 + bb * 0.114;

            rr = (rb > rl ? ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) :
                                                       Weighting)) / 255.0 * (rb - rl) + rl)) :
                  ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) : Weighting))
                                   / 255.0 * (rl - rb) + rb)));
            gr = (gb > gl ? ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) :
                                                       Weighting)) / 255.0 * (gb - gl) + gl)) :
                  ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) : Weighting))
                                   / 255.0 * (gl - gb) + gb)));
            br = (bb > bl ? ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) :
                                                       Weighting)) / 255.0 * (bb - bl) + bl)) :
                  ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) : Weighting))
                                   / 255.0 * (bl - bb) + bb)));
            Display::SetPixel(Point{ X0 + XDir, Y0 }, RGB{ rr, gr, br });
        }
        Display::SetPixel(Point{ X1, Y1 }, clrLine);
        return;
    }
    ErrorAdj = ((unsigned long)DeltaY << 16) / (unsigned long)DeltaX;
    while (--DeltaX) {
        ErrorAccTemp = ErrorAcc;
        ErrorAcc += ErrorAdj;
        if (ErrorAcc <= ErrorAccTemp) {
            Y0++;
        }
        X0 += XDir;
        Weighting = ErrorAcc >> 8;

        RGB clrBackGround = Display::GetPixel(Point{ X0, Y0 });
        unsigned char rb = clrBackGround.Red;
        unsigned char gb = clrBackGround.Green;
        unsigned char bb = clrBackGround.Blue;
        double grayb = rb * 0.299 + gb * 0.587 + bb * 0.114;

        unsigned char rr = (rb > rl ? ((unsigned char)(((double)(grayl < grayb ? Weighting :
                                                                 (Weighting ^ 255))) / 255.0 * (rb - rl) + rl)) :
                            ((unsigned char)(((double)(grayl < grayb ? Weighting : (Weighting ^ 255)))
                                             / 255.0 * (rl - rb) + rb)));
        unsigned char gr = (gb > gl ? ((unsigned char)(((double)(grayl < grayb ? Weighting :
                                                                 (Weighting ^ 255))) / 255.0 * (gb - gl) + gl)) :
                            ((unsigned char)(((double)(grayl < grayb ? Weighting : (Weighting ^ 255)))
                                             / 255.0 * (gl - gb) + gb)));
        unsigned char br = (bb > bl ? ((unsigned char)(((double)(grayl < grayb ? Weighting :
                                                                 (Weighting ^ 255))) / 255.0 * (bb - bl) + bl)) :
                            ((unsigned char)(((double)(grayl < grayb ? Weighting : (Weighting ^ 255)))
                                             / 255.0 * (bl - bb) + bb)));

        Display::SetPixel(Point{ X0, Y0 }, RGB{ rr, gr, br });

        clrBackGround = Display::GetPixel(Point{ X0, Y0 + 1 });
        rb = clrBackGround.Red;
        gb = clrBackGround.Green;
        bb = clrBackGround.Blue;
        grayb = rb * 0.299 + gb * 0.587 + bb * 0.114;

        rr = (rb > rl ? ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) :
                                                   Weighting)) / 255.0 * (rb - rl) + rl)) :
              ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) : Weighting))
                               / 255.0 * (rl - rb) + rb)));
        gr = (gb > gl ? ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) :
                                                   Weighting)) / 255.0 * (gb - gl) + gl)) :
              ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) : Weighting))
                               / 255.0 * (gl - gb) + gb)));
        br = (bb > bl ? ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) :
                                                   Weighting)) / 255.0 * (bb - bl) + bl)) :
              ((unsigned char)(((double)(grayl < grayb ? (Weighting ^ 255) : Weighting))
                               / 255.0 * (bl - bb) + bb)));

        Display::SetPixel(Point{ X0, Y0 + 1 }, RGB{ rr, gr, br });
    }

    Display::SetPixel(Point{ X1, Y1 }, clrLine);
}

void Graphics::PunctLineV(Point p1, Point p2, RGB nc, RGB pc, int punctLen)
{
    bool bw = true;

    for (int h = 0; h < p2.Y - p1.Y; h += punctLen)
    {
        Rectangle line = Rectangle(Point{ p1.X, p1.Y + h }, Point{ p1.X, p1.Y + h + punctLen }, nc);

        if (!bw)
        {
            line.Color = pc;
        }

        line.Draw();

        bw = !bw;
    }
}

void Graphics::HomeButton()
{
    Rectangle* home = new Rectangle(Point{ 420, 760 }, Point{ 603, 762 }, RGB{ 0xff, 0xff, 0xff });

    for (int i = 0; i < 13; i++)
    {
        home->Draw();

        int volatile c = 0;
        int volatile d = 0;

        for (c = 0; c < 32000; c++)
            for (d = 0; d < 3200; d++) {}

        home->Color = Display::AlphaBlend(RGB{ 0xff,0xff,0xff }, { 0,0,0 }, (double)i / 12);
    }

    home->Draw();
}