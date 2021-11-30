#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <random>
#include <chrono> 

bool g_showMoves, g_toMove{ 0 }, g_castleKing{ 1 }, g_castleQueen{ 1 }, g_opponentCastleKing{ 1 }, g_opponentCastleQueen{ 1 };
int g_fiftyMoveRule, g_weightMaster[5][705], g_weightTest[100][705], g_masterBoard[64]{ -4, -2, -3, -5, -6, -3, -2, -4, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 3, 5, 6, 3, 2, 4 }, g_boardTemp[64], g_prevMove1, g_prevMove2;
//starting position {-4, -2, -3, -5, -6, -3, -2, -4, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 3, 5, 6, 3, 2, 4}
//benchmark postion for getMove speed testing {-4, -2, 0, -5, -6, 0, 0, -4, 0, -1, 0, 0, -3, -1, -1, -1, -1, 0, 0, -1, -3, -2, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 2, 0, 3, 1, 0, 0, 1, 1, 1, 5, 0, 0, 1, 1, 4, 0, 0, 0, 6, 3, 0, 4}
std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };


class Timer
{
private:
    using clock_type = std::chrono::steady_clock;
    using second_type = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_type> m_beg;

public:
    Timer() : m_beg{ clock_type::now() }
    {
    }

    void reset()
    {
        m_beg = clock_type::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
};

float neuronFinal(float weight, float i1, float i2, float i3, float i4, float i5, float i6, float i7, float i8, float i9, float i10, float i11, float i12, float i13, float i14, float i15, float i16, float i17, float i18, float i19, float i20, float i21, float i22, float i23, float i24, float i25, float i26, float i27, float i28, float i29, float i30, float i31, float i32, float i33, float i34, float i35, float i36, float i37, float i38, float i39, float i40, float i41, float i42, float i43, float i44, float i45, float i46, float i47, float i48, float i49, float i50, float i51, float i52, float i53, float i54, float i55, float i56, float i57, float i58, float i59, float i60, float i61, float i62, float i63, float i64)
{
    float x(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 + i11 + i12 + i13 + i14 + i15 + i16 + i17 + i18 + i19 + i20 + i21 + i22 + i23 + i24 + i25 + i26 + i27 + i28 + i29 + i30 + i31 + i32 + i33 + i34 + i35 + i36 + i37 + i38 + i39 + i40 + i41 + i42 + i43 + i44 + i45 + i46 + i47 + i48 + i49 + i50 + i51 + i52 + i53 + i54 + i55 + i56 + i57 + i58 + i59 + i60 + i61 + i62 + i63 + i64);
    x = x * weight;
    x = -1 * (20 / (1 + std::pow(1.125, x))) + 10;
    return x;
}

float neuron(float weight, float i1, float i2, float i3, float i4, float i5, float i6, float i7, float i8, float i9, float i10, float i11, float i12, float i13, float i14, float i15, float i16, float i17, float i18, float i19, float i20, float i21, float i22, float i23, float i24, float i25, float i26, float i27, float i28, float i29, float i30, float i31, float i32, float i33, float i34, float i35, float i36, float i37, float i38, float i39, float i40, float i41, float i42, float i43, float i44, float i45, float i46, float i47, float i48, float i49, float i50, float i51, float i52, float i53, float i54, float i55, float i56, float i57, float i58, float i59, float i60, float i61, float i62, float i63, float i64)
{
    float x(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 + i11 + i12 + i13 + i14 + i15 + i16 + i17 + i18 + i19 + i20 + i21 + i22 + i23 + i24 + i25 + i26 + i27 + i28 + i29 + i30 + i31 + i32 + i33 + i34 + i35 + i36 + i37 + i38 + i39 + i40 + i41 + i42 + i43 + i44 + i45 + i46 + i47 + i48 + i49 + i50 + i51 + i52 + i53 + i54 + i55 + i56 + i57 + i58 + i59 + i60 + i61 + i62 + i63 + i64);
    x = x * weight;
    x = -2 * (1 / (1 + std::pow(1.01, x))) + 2;
    return x;
}

float neuralnet(int testNum, int variationCount)
{
    float n[64], ntest[64];
    int output1{ 0 }, output2{ 0 }, count{ 0 }, count2{ 0 }, count3{ 0 };
    if (g_toMove == 0)
    {
        while (count < 64)
        {
            n[count] = neuron(g_weightMaster[testNum][count2], g_masterBoard[0], g_masterBoard[1], g_masterBoard[2], g_masterBoard[3], g_masterBoard[4], g_masterBoard[5], g_masterBoard[6], g_masterBoard[7], g_masterBoard[8], g_masterBoard[9], g_masterBoard[10], g_masterBoard[11], g_masterBoard[12], g_masterBoard[13], g_masterBoard[14], g_masterBoard[15], g_masterBoard[16], g_masterBoard[17], g_masterBoard[18], g_masterBoard[19], g_masterBoard[20], g_masterBoard[21], g_masterBoard[22], g_masterBoard[23], g_masterBoard[24], g_masterBoard[25], g_masterBoard[26], g_masterBoard[27], g_masterBoard[28], g_masterBoard[29], g_masterBoard[30], g_masterBoard[31], g_masterBoard[32], g_masterBoard[33], g_masterBoard[34], g_masterBoard[35], g_masterBoard[36], g_masterBoard[37], g_masterBoard[38], g_masterBoard[39], g_masterBoard[40], g_masterBoard[41], g_masterBoard[42], g_masterBoard[43], g_masterBoard[44], g_masterBoard[45], g_masterBoard[46], g_masterBoard[47], g_masterBoard[48], g_masterBoard[49], g_masterBoard[50], g_masterBoard[51], g_masterBoard[52], g_masterBoard[53], g_masterBoard[54], g_masterBoard[55], g_masterBoard[56], g_masterBoard[57], g_masterBoard[58], g_masterBoard[59], g_masterBoard[60], g_masterBoard[61], g_masterBoard[62], g_masterBoard[63]);
            ++count;
            ++count2;
        }
        count = 0;
        while (count3 < 2)
        {
            while (count < 64)
            {
                ntest[count] = neuron(g_weightMaster[testNum][count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
                ++count;
                ++count2;
            }
            count = 0;
            while (count < 64)
            {
                n[count] = ntest[count];
                ++count;
            }
            count = 0;
            ++count3;
        }
        n[0] = neuronFinal(g_weightMaster[testNum][count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
        return n[0];
    }
    else
    {
        while (count < 64)
        {
            n[count] = neuron(g_weightMaster[variationCount][count2], g_masterBoard[0], g_masterBoard[1], g_masterBoard[2], g_masterBoard[3], g_masterBoard[4], g_masterBoard[5], g_masterBoard[6], g_masterBoard[7], g_masterBoard[8], g_masterBoard[9], g_masterBoard[10], g_masterBoard[11], g_masterBoard[12], g_masterBoard[13], g_masterBoard[14], g_masterBoard[15], g_masterBoard[16], g_masterBoard[17], g_masterBoard[18], g_masterBoard[19], g_masterBoard[20], g_masterBoard[21], g_masterBoard[22], g_masterBoard[23], g_masterBoard[24], g_masterBoard[25], g_masterBoard[26], g_masterBoard[27], g_masterBoard[28], g_masterBoard[29], g_masterBoard[30], g_masterBoard[31], g_masterBoard[32], g_masterBoard[33], g_masterBoard[34], g_masterBoard[35], g_masterBoard[36], g_masterBoard[37], g_masterBoard[38], g_masterBoard[39], g_masterBoard[40], g_masterBoard[41], g_masterBoard[42], g_masterBoard[43], g_masterBoard[44], g_masterBoard[45], g_masterBoard[46], g_masterBoard[47], g_masterBoard[48], g_masterBoard[49], g_masterBoard[50], g_masterBoard[51], g_masterBoard[52], g_masterBoard[53], g_masterBoard[54], g_masterBoard[55], g_masterBoard[56], g_masterBoard[57], g_masterBoard[58], g_masterBoard[59], g_masterBoard[60], g_masterBoard[61], g_masterBoard[62], g_masterBoard[63]);
            ++count;
            ++count2;
        }
        count = 0;
        while (count3 < 100)
        {
            while (count < 64)
            {
                ntest[count] = neuron(g_weightTest[variationCount][count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
                ++count;
                ++count2;
            }
            count = 0;
            while (count < 64)
            {
                n[count] = ntest[count];
                ++count;
            }
            count = 0;
            ++count3;
        }
        n[0] = neuronFinal(g_weightTest[variationCount][count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
        return n[0];
    }
    return 0;
}

bool isKingSafe()
{
    int count{ 0 };
    while (count < 64)
    {
        if (g_boardTemp[count] == 6)
        {
            //upwards checks
            if (count > 7)
            {
                if (g_boardTemp[count - 8] == -4 || g_boardTemp[count - 8] == -5 || g_boardTemp[count - 8] == -6)
                {
                    return 0;
                }
            }
            if (count > 15)
            {
                if (g_boardTemp[count - 16] == -4 || g_boardTemp[count - 16] == -5)
                {
                    if (g_boardTemp[count - 8] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count > 23)
            {
                if (g_boardTemp[count - 24] == -4 || g_boardTemp[count - 24] == -5)
                {
                    if (g_boardTemp[count - 8] == 0 && g_boardTemp[count - 16] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count > 31)
            {
                if (g_boardTemp[count - 32] == -4 || g_boardTemp[count - 32] == -5)
                {
                    if (g_boardTemp[count - 8] == 0 && g_boardTemp[count - 16] == 0 && g_boardTemp[count - 24] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count > 39)
            {
                if (g_boardTemp[count - 40] == -4 || g_boardTemp[count - 40] == -5)
                {
                    if (g_boardTemp[count - 8] == 0 && g_boardTemp[count - 16] == 0 && g_boardTemp[count - 24] == 0 && g_boardTemp[count - 32] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count > 47)
            {
                if (g_boardTemp[count - 48] == -4 || g_boardTemp[count - 48] == -5)
                {
                    if (g_boardTemp[count - 8] == 0 && g_boardTemp[count - 16] == 0 && g_boardTemp[count - 24] == 0 && g_boardTemp[count - 32] == 0 && g_boardTemp[count - 40] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count > 55)
            {
                if (g_boardTemp[count - 56] == -4 || g_boardTemp[count - 56] == -5)
                {
                    if (g_boardTemp[count - 8] == 0 && g_boardTemp[count - 16] == 0 && g_boardTemp[count - 24] == 0 && g_boardTemp[count - 32] == 0 && g_boardTemp[count - 40] == 0 && g_boardTemp[count - 48] == 0)
                    {
                        return 0;
                    }
                }
            }
            //downwards checks
            if (count < 56)
            {
                if (g_boardTemp[count + 8] == -4 || g_boardTemp[count + 8] == -5 || g_boardTemp[count + 8] == -6)
                {
                    return 0;
                }
            }
            if (count < 48)
            {
                if (g_boardTemp[count + 16] == -4 || g_boardTemp[count + 16] == -5)
                {
                    if (g_boardTemp[count + 8] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count < 40)
            {
                if (g_boardTemp[count + 24] == -4 || g_boardTemp[count + 24] == -5)
                {
                    if (g_boardTemp[count + 8] == 0 && g_boardTemp[count + 16] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count < 32)
            {
                if (g_boardTemp[count + 32] == -4 || g_boardTemp[count + 32] == -5)
                {
                    if (g_boardTemp[count + 8] == 0 && g_boardTemp[count + 16] == 0 && g_boardTemp[count + 24] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count < 24)
            {
                if (g_boardTemp[count + 40] == -4 || g_boardTemp[count + 40] == -5)
                {
                    if (g_boardTemp[count + 8] == 0 && g_boardTemp[count + 16] == 0 && g_boardTemp[count + 24] == 0 && g_boardTemp[count + 32] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count < 16)
            {
                if (g_boardTemp[count + 48] == -4 || g_boardTemp[count + 48] == -5)
                {
                    if (g_boardTemp[count + 8] == 0 && g_boardTemp[count + 16] == 0 && g_boardTemp[count + 24] == 0 && g_boardTemp[count + 32] == 0 && g_boardTemp[count + 40] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count < 8)
            {
                if (g_boardTemp[count + 56] == -4 || g_boardTemp[count + 56] == -5)
                {
                    if (g_boardTemp[count + 8] == 0 && g_boardTemp[count + 16] == 0 && g_boardTemp[count + 24] == 0 && g_boardTemp[count + 32] == 0 && g_boardTemp[count + 40] == 0 && g_boardTemp[count + 48] == 0)
                    {
                        return 0;
                    }
                }
            }
            //checks from right
            if (count % 8 < 7)
            {
                if (g_boardTemp[count + 1] == -4 || g_boardTemp[count + 1] == -5 || g_boardTemp[count + 1] == -6)
                {
                    return 0;
                }
            }
            if (count % 8 < 6)
            {
                if (g_boardTemp[count + 2] == -4 || g_boardTemp[count + 2] == -5)
                {
                    if (g_boardTemp[count + 1] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 < 5)
            {
                if (g_boardTemp[count + 3] == -4 || g_boardTemp[count + 3] == -5)
                {
                    if (g_boardTemp[count + 1] == 0 && g_boardTemp[count + 2] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 < 4)
            {
                if (g_boardTemp[count + 4] == -4 || g_boardTemp[count + 4] == -5)
                {
                    if (g_boardTemp[count + 1] == 0 && g_boardTemp[count + 2] == 0 && g_boardTemp[count + 3] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 < 3)
            {
                if (g_boardTemp[count + 5] == -4 || g_boardTemp[count + 5] == -5)
                {
                    if (g_boardTemp[count + 1] == 0 && g_boardTemp[count + 2] == 0 && g_boardTemp[count + 3] == 0 && g_boardTemp[count + 4] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 < 2)
            {
                if (g_boardTemp[count + 6] == -4 || g_boardTemp[count + 6] == -5)
                {
                    if (g_boardTemp[count + 1] == 0 && g_boardTemp[count + 2] == 0 && g_boardTemp[count + 3] == 0 && g_boardTemp[count + 4] == 0 && g_boardTemp[count + 5] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 < 1)
            {
                if (g_boardTemp[count + 7] == -4 || g_boardTemp[count + 7] == -5)
                {
                    if (g_boardTemp[count + 1] == 0 && g_boardTemp[count + 2] == 0 && g_boardTemp[count + 3] == 0 && g_boardTemp[count + 4] == 0 && g_boardTemp[count + 5] == 0 && g_boardTemp[count + 6] == 0)
                    {
                        return 0;
                    }
                }
            }
            //checks from left
            if (count % 8 > 0)
            {
                if (g_boardTemp[count - 1] == -4 || g_boardTemp[count - 1] == -5 || g_boardTemp[count - 1] == -6)
                {
                    return 0;
                }
            }
            if (count % 8 > 1)
            {
                if (g_boardTemp[count - 2] == -4 || g_boardTemp[count - 2] == -5)
                {
                    if (g_boardTemp[count - 1] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 > 2)
            {
                if (g_boardTemp[count - 3] == -4 || g_boardTemp[count - 3] == -5)
                {
                    if (g_boardTemp[count - 1] == 0 && g_boardTemp[count - 2] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 > 3)
            {
                if (g_boardTemp[count - 4] == -4 || g_boardTemp[count - 4] == -5)
                {
                    if (g_boardTemp[count - 1] == 0 && g_boardTemp[count - 2] == 0 && g_boardTemp[count - 3] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 > 4)
            {
                if (g_boardTemp[count - 5] == -4 || g_boardTemp[count - 5] == -5)
                {
                    if (g_boardTemp[count - 1] == 0 && g_boardTemp[count - 2] == 0 && g_boardTemp[count - 3] == 0 && g_boardTemp[count - 4] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 > 5)
            {
                if (g_boardTemp[count - 7] == -4 || g_boardTemp[count - 7] == -5)
                {
                    if (g_boardTemp[count - 1] == 0 && g_boardTemp[count - 2] == 0 && g_boardTemp[count - 3] == 0 && g_boardTemp[count - 4] == 0 && g_boardTemp[count - 5] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count % 8 > 6)
            {
                if (g_boardTemp[count - 7] == -4 || g_boardTemp[count - 7] == -5)
                {
                    if (g_boardTemp[count - 1] == 0 && g_boardTemp[count - 2] == 0 && g_boardTemp[count - 3] == 0 && g_boardTemp[count - 4] == 0 && g_boardTemp[count - 5] == 0 && g_boardTemp[count - 6] == 0)
                    {
                        return 0;
                    }
                }
            }
            //checks from negative diagonal
            if (count == 0)
            {
                if (g_boardTemp[63] == -3 || g_boardTemp[63] == -5)
                {
                    if (g_boardTemp[9] == 0 && g_boardTemp[18] == 0 && g_boardTemp[27] == 0 && g_boardTemp[36] == 0 && g_boardTemp[45] == 0 && g_boardTemp[54] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 63)
            {
                if (g_boardTemp[0] == -3 || g_boardTemp[0] == -5)
                {
                    if (g_boardTemp[9] == 0 && g_boardTemp[18] == 0 && g_boardTemp[27] == 0 && g_boardTemp[36] == 0 && g_boardTemp[45] == 0 && g_boardTemp[54] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 0 || count == 1 || count == 8 || count == 9)
            {
                if (g_boardTemp[count + 54] == -3 || g_boardTemp[count + 54] == -5)
                {
                    if (g_boardTemp[count + 45] == 0 && g_boardTemp[count + 36] == 0 && g_boardTemp[count + 27] == 0 && g_boardTemp[count + 18] == 0 && g_boardTemp[count + 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18)
            {
                if (g_boardTemp[count + 45] == -3 || g_boardTemp[count + 45] == -5)
                {
                    if (g_boardTemp[count + 36] == 0 && g_boardTemp[count + 27] == 0 && g_boardTemp[count + 18] == 0 && g_boardTemp[count + 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18 || count == 3 || count == 11 || count == 19 || count == 24 || count == 25 || count == 26 || count == 27)
            {
                if (g_boardTemp[count + 36] == -3 || g_boardTemp[count + 36] == -5)
                {
                    if (g_boardTemp[count + 27] == 0 && g_boardTemp[count + 18] == 0 && g_boardTemp[count + 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18 || count == 3 || count == 11 || count == 19 || count == 24 || count == 25 || count == 26 || count == 27 || count == 4 || count == 12 || count == 20 || count == 28 || count == 32 || count == 33 || count == 34 || count == 35 || count == 36)
            {
                if (g_boardTemp[count + 27] == -3 || g_boardTemp[count + 27] == -5)
                {
                    if (g_boardTemp[count + 18] == 0 && g_boardTemp[count + 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18 || count == 3 || count == 11 || count == 19 || count == 24 || count == 25 || count == 26 || count == 27 || count == 4 || count == 12 || count == 20 || count == 28 || count == 32 || count == 33 || count == 34 || count == 35 || count == 36 || count == 5 || count == 13 || count == 21 || count == 29 || count == 37 || count == 40 || count == 41 || count == 42 || count == 43 || count == 44 || count == 45)
            {
                if (g_boardTemp[count + 18] == -3 || g_boardTemp[count + 18] == -5)
                {
                    if (g_boardTemp[count + 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count != 7 && count != 15 && count != 23 && count != 31 && count != 39 && count != 47 && count != 55 && count != 56 && count != 57 && count != 58 && count != 59 && count != 60 && count != 61 && count != 62 && count != 63)
            {
                if (g_boardTemp[count + 9] == -3 || g_boardTemp[count + 9] == -5 || g_boardTemp[count + 9] == -6)
                {
                    return 0;
                }
            }
            if (count == 63 || count == 62 || count == 55 || count == 54)
            {
                if (g_boardTemp[count - 54] == -3 || g_boardTemp[count - 54] == -5)
                {
                    if (g_boardTemp[count - 45] == 0 && g_boardTemp[count - 36] == 0 && g_boardTemp[count - 27] == 0 && g_boardTemp[count - 18] == 0 && g_boardTemp[count - 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45)
            {
                if (g_boardTemp[count - 45] == -3 || g_boardTemp[count - 45] == -5)
                {
                    if (g_boardTemp[count - 36] == 0 && g_boardTemp[count - 27] == 0 && g_boardTemp[count - 18] == 0 && g_boardTemp[count - 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45 || count == 60 || count == 52 || count == 44 || count == 39 || count == 38 || count == 37 || count == 36)
            {
                if (g_boardTemp[count - 36] == -3 || g_boardTemp[count - 36] == -5)
                {
                    if (g_boardTemp[count - 27] == 0 && g_boardTemp[count - 18] == 0 && g_boardTemp[count - 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45 || count == 60 || count == 52 || count == 44 || count == 39 || count == 38 || count == 37 || count == 36 || count == 59 || count == 51 || count == 43 || count == 35 || count == 31 || count == 30 || count == 29 || count == 28 || count == 27)
            {
                if (g_boardTemp[count - 27] == -3 || g_boardTemp[count - 27] == -5)
                {
                    if (g_boardTemp[count - 18] == 0 && g_boardTemp[count - 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45 || count == 60 || count == 52 || count == 44 || count == 39 || count == 38 || count == 37 || count == 36 || count == 59 || count == 51 || count == 43 || count == 35 || count == 31 || count == 30 || count == 29 || count == 28 || count == 27 || count == 58 || count == 50 || count == 42 || count == 34 || count == 37 || count == 23 || count == 22 || count == 21 || count == 20 || count == 19 || count == 18)
            {
                if (g_boardTemp[count - 18] == -3 || g_boardTemp[count - 18] == -5)
                {
                    if (g_boardTemp[count - 9] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count != 0 && count != 1 && count != 2 && count != 3 && count != 4 && count != 5 && count != 6 && count != 7 && count != 8 && count != 16 && count != 24 && count != 32 && count != 40 && count != 48 && count != 56)
            {
                if (g_boardTemp[count - 9] == -3 || g_boardTemp[count - 9] == -5 || g_boardTemp[count - 9] == -6 || g_boardTemp[count - 9] == -1)
                {
                    return 0;
                }
            }
            //checks from positive diagonal
            if (count == 56)
            {
                if (g_boardTemp[7] == -3 || g_boardTemp[7] == -5)
                {
                    if (g_boardTemp[49] == 0 && g_boardTemp[42] == 0 && g_boardTemp[35] == 0 && g_boardTemp[28] == 0 && g_boardTemp[21] == 0 && g_boardTemp[14] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 7)
            {
                if (g_boardTemp[56] == -3 || g_boardTemp[56] == -5)
                {
                    if (g_boardTemp[49] == 0 && g_boardTemp[42] == 0 && g_boardTemp[35] == 0 && g_boardTemp[28] == 0 && g_boardTemp[21] == 0 && g_boardTemp[14] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 56 || count == 57 || count == 48 || count == 49)
            {
                if (g_boardTemp[count - 42] == -3 || g_boardTemp[count - 42] == -5)
                {
                    if (g_boardTemp[count - 35] == 0 && g_boardTemp[count - 28] == 0 && g_boardTemp[count - 21] == 0 && g_boardTemp[count - 14] == 0 && g_boardTemp[count - 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42)
            {
                if (g_boardTemp[count - 35] == -3 || g_boardTemp[count - 35] == -5)
                {
                    if (g_boardTemp[count - 28] == 0 && g_boardTemp[count - 21] == 0 && g_boardTemp[count - 14] == 0 && g_boardTemp[count - 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42 || count == 59 || count == 51 || count == 43 || count == 32 || count == 33 || count == 34 || count == 35)
            {
                if (g_boardTemp[count - 28] == -3 || g_boardTemp[count - 28] == -5)
                {
                    if (g_boardTemp[count - 21] == 0 && g_boardTemp[count - 14] == 0 && g_boardTemp[count - 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42 || count == 59 || count == 51 || count == 43 || count == 32 || count == 33 || count == 34 || count == 35 || count == 60 || count == 52 || count == 44 || count == 36 || count == 24 || count == 25 || count == 26 || count == 27 || count == 28)
            {
                if (g_boardTemp[count - 21] == -3 || g_boardTemp[count - 21] == -5)
                {
                    if (g_boardTemp[count - 14] == 0 && g_boardTemp[count - 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42 || count == 59 || count == 51 || count == 43 || count == 32 || count == 33 || count == 34 || count == 35 || count == 60 || count == 52 || count == 44 || count == 36 || count == 24 || count == 25 || count == 26 || count == 27 || count == 28 || count == 61 || count == 53 || count == 45 || count == 37 || count == 29 || count == 16 || count == 17 || count == 18 || count == 19 || count == 20 || count == 21)
            {
                if (g_boardTemp[count - 14] == -3 || g_boardTemp[count - 14] == -5)
                {
                    if (g_boardTemp[count - 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count != 0 && count != 1 && count != 2 && count != 3 && count != 4 && count != 5 && count != 6 && count != 7 && count != 15 && count != 23 && count != 31 && count != 39 && count != 47 && count != 55 && count != 63)
            {
                if (g_boardTemp[count - 7] == -3 || g_boardTemp[count - 7] == -5 || g_boardTemp[count - 7] == -6 || g_boardTemp[count - 7] == -1)
                {
                    return 0;
                }
            }
            if (count == 7 || count == 6 || count == 15 || count == 14)
            {
                if (g_boardTemp[count + 42] == -3 || g_boardTemp[count + 42] == -5)
                {
                    if (g_boardTemp[count + 35] == 0 && g_boardTemp[count + 28] == 0 && g_boardTemp[count + 21] == 0 && g_boardTemp[count + 14] == 0 && g_boardTemp[count + 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21)
            {
                if (g_boardTemp[count + 35] == -3 || g_boardTemp[count + 35] == -5)
                {
                    if (g_boardTemp[count + 28] == 0 && g_boardTemp[count + 21] == 0 && g_boardTemp[count + 14] == 0 && g_boardTemp[count + 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21 || count == 4 || count == 12 || count == 20 || count == 31 || count == 30 || count == 29 || count == 28)
            {
                if (g_boardTemp[count + 28] == -3 || g_boardTemp[count + 28] == -5)
                {
                    if (g_boardTemp[count + 21] == 0 && g_boardTemp[count + 14] == 0 && g_boardTemp[count + 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21 || count == 4 || count == 12 || count == 20 || count == 31 || count == 30 || count == 29 || count == 28 || count == 3 || count == 11 || count == 19 || count == 27 || count == 39 || count == 38 || count == 37 || count == 36 || count == 35)
            {
                if (g_boardTemp[count + 21] == -3 || g_boardTemp[count + 21] == -5)
                {
                    if (g_boardTemp[count + 14] == 0 && g_boardTemp[count + 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21 || count == 4 || count == 12 || count == 20 || count == 31 || count == 30 || count == 29 || count == 28 || count == 3 || count == 11 || count == 19 || count == 27 || count == 39 || count == 38 || count == 37 || count == 36 || count == 35 || count == 2 || count == 10 || count == 18 || count == 26 || count == 34 || count == 47 || count == 46 || count == 45 || count == 44 || count == 43 || count == 42)
            {
                if (g_boardTemp[count + 14] == -3 || g_boardTemp[count + 14] == -5)
                {
                    if (g_boardTemp[count + 7] == 0)
                    {
                        return 0;
                    }
                }
            }
            if (count != 0 && count != 8 && count != 16 && count != 24 && count != 32 && count != 40 && count != 48 && count != 56 && count != 57 && count != 58 && count != 59 && count != 60 && count != 61 && count != 62 && count != 63)
            {
                if (g_boardTemp[count + 7] == -3 || g_boardTemp[count + 7] == -5 || g_boardTemp[count + 7] == -6)
                {
                    return 0;
                }
            }
            //checks from knights
            if (count == 0)
            {
                if (g_boardTemp[10] == -2 || g_boardTemp[17] == -2)
                {
                    return 0;
                }
            }
            if (count == 1)
            {
                if (g_boardTemp[11] == -2 || g_boardTemp[18] == -2 || g_boardTemp[16] == -2)
                {
                    return 0;
                }
            }
            if (count == 8)
            {
                if (g_boardTemp[18] == -2 || g_boardTemp[25] == -2 || g_boardTemp[2] == -2)
                {
                    return 0;
                }
            }
            if (count == 2 || count == 3 || count == 4 || count == 5)
            {
                if (g_boardTemp[count + 10] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count + 6] == -2)
                {
                    return 0;
                }
            }
            if (count == 6)
            {
                if (g_boardTemp[21] == -2 || g_boardTemp[12] == -2 || g_boardTemp[19])
                {
                    return 0;
                }
            }
            if (count == 15)
            {
                if (g_boardTemp[30] == -2 || g_boardTemp[21] == -2 || g_boardTemp[5] == -2)
                {
                    return 0;
                }
            }
            if (count == 9)
            {
                if (g_boardTemp[19] == -2 || g_boardTemp[26] == -2 || g_boardTemp[24] == -2 || g_boardTemp[3] == -2)
                {
                    return 0;
                }
            }
            if (count == 10 || count == 11 || count == 12 || count == 13)
            {
                if (g_boardTemp[count - 10] == -2 || g_boardTemp[count - 6] == -2 || g_boardTemp[count + 10] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count + 6] == -2)
                {
                    return 0;
                }
            }
            if (count == 14)
            {
                if (g_boardTemp[count - 10] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count + 6] == -2)
                {
                    return 0;
                }
            }
            if (count == 16 || count == 24 || count == 32 || count == 40)
            {
                if (g_boardTemp[count - 15] == -2 || g_boardTemp[count - 6] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 10] == -2)
                {
                    return 0;
                }
            }
            if (count == 17 || count == 25 || count == 33 || count == 41)
            {
                if (g_boardTemp[count - 17] == -2 || g_boardTemp[count - 6] == -2 || g_boardTemp[count + 10] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count - 15] == -2)
                {
                    return 0;
                }
            }
            if (count == 18 || count == 19 || count == 20 || count == 21 || count == 26 || count == 27 || count == 28 || count == 29 || count == 34 || count == 35 || count == 36 || count == 37 || count == 42 || count == 43 || count == 44 || count == 45)
            {
                if (g_boardTemp[count - 17] == -2 || g_boardTemp[count - 15] || g_boardTemp[count - 6] == -2 || g_boardTemp[count + 10] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count - 10] == -2 || g_boardTemp[count + 6] == -2)
                {
                    return 0;
                }
            }
            if (count == 22 || count == 30 || count == 38 || count == 46)
            {
                if (g_boardTemp[count - 17] == -2 || g_boardTemp[count - 10] == -2 || g_boardTemp[count + 6] == -2 || g_boardTemp[count + 17] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count - 15] == -2)
                {
                    return 0;
                }
            }
            if (count == 23 || count == 31 || count == 39 || count == 47)
            {
                if (g_boardTemp[count - 17] == -2 || g_boardTemp[count + 6] == -2 || g_boardTemp[count + 15] == -2 || g_boardTemp[count - 10] == -2)
                {
                    return 0;
                }
            }
            if (count == 48)
            {
                if (g_boardTemp[33] == -2 || g_boardTemp[42] == -2 || g_boardTemp[58] == -2)
                {
                    return 0;
                }
            }
            if (count == 57)
            {
                if (g_boardTemp[42] == -2 || g_boardTemp[51] == -2 || g_boardTemp[40] == -2)
                {
                    return 0;
                }
            }
            if (count == 49)
            {
                if (g_boardTemp[32] == -2 || g_boardTemp[34] == -2 || g_boardTemp[43] == -2 || g_boardTemp[59] == -2)
                {
                    return 0;
                }
            }
            if (count == 50 || count == 51 || count == 52 || count == 53)
            {
                if (g_boardTemp[count + 10] == -2 || g_boardTemp[count + 6] == -2 || g_boardTemp[count - 10] == -2 || g_boardTemp[count - 17] == -2 || g_boardTemp[count - 15] == -2 || g_boardTemp[count - 6] == -2)
                {
                    return 0;
                }
            }
            if (count == 58 || count == 59 || count == 60 || count == 61)
            {
                if (g_boardTemp[count - 10] == -2 || g_boardTemp[count - 17] == -2 || g_boardTemp[count - 15] == -2 || g_boardTemp[count - 6] == -2)
                {
                    return 0;
                }
            }
            if (count == 54)
            {
                if (g_boardTemp[60] == -2 || g_boardTemp[44] == -2 || g_boardTemp[37] == -2 || g_boardTemp[39] == -2)
                {
                    return 0;
                }
            }
            if (count == 55)
            {
                if (g_boardTemp[61] == -2 || g_boardTemp[45] == -2 || g_boardTemp[38] == -2)
                {
                    return 0;
                }
            }
            if (count == 62)
            {
                if (g_boardTemp[52] == -2 || g_boardTemp[45] == -2 || g_boardTemp[47] == -2)
                {
                    return 0;
                }
            }
            if (count == 7)
            {
                if (g_boardTemp[13] == -2 || g_boardTemp[22] == -2)
                {
                    return 0;
                }
            }
            if (count == 56)
            {
                if (g_boardTemp[41] == -2 || g_boardTemp[50] == -2)
                {
                    return 0;
                }
            }
            if (count == 63)
            {
                if (g_boardTemp[46] == -2 || g_boardTemp[53] == -2)
                {
                    return 0;
                }
            }
        }
        ++count;
    }
    return 1;
}

int playMove(int testNum, int variationCount)
{
    int move1[540], move2[540], moveValue[540], moveCount{ 0 };
    float moveEval[540];
    for (int count{ 0 }; count < 540; ++count)
    {
        move1[count] = 0;
        move2[count] = 0;
        moveValue[count] = 0;
        moveEval[count] = 0;
    }
    for (int count{ 0 }; count < 64; ++count)
    {
        if (g_masterBoard[count] == 1)
        {
            g_boardTemp[count] = 0;
            if (count > 47 && count < 56 && g_masterBoard[count - 16] == 0 && g_masterBoard[count - 8] == 0)
            {
                g_boardTemp[count - 16] = 1;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 16;
                    moveValue[moveCount] = 1;
                    ++moveCount;
                }
                g_boardTemp[count - 16] = 0;
            }
            if (count > 7)
            {

                if (g_boardTemp[count - 8] == 0)
                {
                    if (count - 8 < 8)
                    {
                        g_boardTemp[count - 8] = 2;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 8;
                            moveValue[moveCount] = 2;
                            ++moveCount;
                        }
                        g_boardTemp[count - 8] = 3;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 8;
                            moveValue[moveCount] = 3;
                            ++moveCount;
                        }
                        g_boardTemp[count - 8] = 4;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 8;
                            moveValue[moveCount] = 4;
                            ++moveCount;
                        }
                        g_boardTemp[count - 8] = 5;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 8;
                            moveValue[moveCount] = 5;
                            ++moveCount;
                        }
                        g_boardTemp[count - 8] = 0;
                    }
                    else
                    {
                        g_boardTemp[count - 8] = 1;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 8;
                            moveValue[moveCount] = 1;
                            ++moveCount;
                        }
                        g_boardTemp[count - 8] = 0;
                    }
                }
                if (g_boardTemp[count - 7] < 0 && count % 8 != 7)
                {
                    if (count - 7 < 8)
                    {
                        g_boardTemp[count - 7] = 2;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 7;
                            moveValue[moveCount] = 2;
                            ++moveCount;
                        }
                        g_boardTemp[count - 7] = 3;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 7;
                            moveValue[moveCount] = 3;
                            ++moveCount;
                        }
                        g_boardTemp[count - 7] = 4;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 7;
                            moveValue[moveCount] = 4;
                            ++moveCount;
                        }
                        g_boardTemp[count - 7] = 5;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 7;
                            moveValue[moveCount] = 5;
                            ++moveCount;
                        }
                        g_boardTemp[count - 7] = g_masterBoard[count - 7];
                    }
                    else
                    {
                        g_boardTemp[count - 7] = 1;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 7;
                            moveValue[moveCount] = 1;
                            ++moveCount;
                        }
                        g_boardTemp[count - 7] = g_masterBoard[count - 7];
                    }
                }
                if (g_boardTemp[count - 9] < 0 && count % 8 != 0)
                {
                    if (count - 9 < 8)
                    {
                        g_boardTemp[count - 9] = 2;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 9;
                            moveValue[moveCount] = 2;
                            ++moveCount;
                        }
                        g_boardTemp[count - 9] = 3;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 9;
                            moveValue[moveCount] = 3;
                            ++moveCount;
                        }
                        g_boardTemp[count - 9] = 4;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 9;
                            moveValue[moveCount] = 4;
                            ++moveCount;
                        }
                        g_boardTemp[count - 9] = 5;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 9;
                            moveValue[moveCount] = 5;
                            ++moveCount;
                        }
                        g_boardTemp[count - 9] = g_masterBoard[count - 9];
                    }
                    else
                    {
                        g_boardTemp[count - 9] = 1;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 9;
                            moveValue[moveCount] = 1;
                            ++moveCount;
                        }
                        g_boardTemp[count - 9] = g_masterBoard[count - 9];
                    }
                }
                if (g_prevMove1 == count - 15 && g_prevMove2 == count + 1 && g_masterBoard[count + 1] == -1 && count % 8 != 7)
                {
                    g_boardTemp[count - 7] = 1;
                    g_boardTemp[count + 1] = 0;
                    if (isKingSafe() == 1)
                    {
                        moveEval[moveCount] = neuralnet(testNum, variationCount);
                        move1[moveCount] = count;
                        move2[moveCount] = count - 7;
                        moveValue[moveCount] = 1;
                        ++moveCount;
                    }
                    g_boardTemp[count - 7] = 0;
                    g_boardTemp[count + 1] = -1;
                }
                if (g_prevMove1 == count - 17 && g_prevMove2 == count - 1 && g_masterBoard[count - 1] == -1 && count % 8 != 0)
                {
                    g_boardTemp[count - 9] = 1;
                    g_boardTemp[count - 1] = 0;
                    if (isKingSafe() == 1)
                    {
                        moveEval[moveCount] = neuralnet(testNum, variationCount);
                        move1[moveCount] = count;
                        move2[moveCount] = count - 9;
                        moveValue[moveCount] = 1;
                        ++moveCount;
                    }
                    g_boardTemp[count - 9] = 0;
                    g_boardTemp[count - 1] = -1;
                }
            }
            g_boardTemp[count] = 1;
        }
        if (g_masterBoard[count] == 6)
        {
            g_boardTemp[count] = 0;
            if (count > 7)
            {
                if (g_masterBoard[count - 8] < 1)
                {
                    g_boardTemp[count - 8] = 6;
                    if (isKingSafe() == 1)
                    {
                        moveEval[moveCount] = neuralnet(testNum, variationCount);
                        move1[moveCount] = count;
                        move2[moveCount] = count - 8;
                        moveValue[moveCount] = 6;
                        ++moveCount;
                    }
                    g_boardTemp[count - 8] = g_masterBoard[count - 8];
                }
                if (g_masterBoard[count - 9] < 1)
                {
                    if (count % 8 != 0)
                    {
                        g_boardTemp[count - 9] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 9;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[count - 9] = g_masterBoard[count - 9];
                    }
                }
                if (g_masterBoard[count - 9] < 1)
                {
                    if (count % 8 != 7)
                    {
                        g_boardTemp[count - 7] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count - 7;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[count - 7] = g_masterBoard[count - 7];
                    }
                }

            }
            if (count % 8 != 0)
            {
                if (g_masterBoard[count - 1] < 1)
                {
                    g_boardTemp[count - 1] = 6;
                    if (isKingSafe() == 1)
                    {
                        moveEval[moveCount] = neuralnet(testNum, variationCount);
                        move1[moveCount] = count;
                        move2[moveCount] = count - 1;
                        moveValue[moveCount] = 6;
                        ++moveCount;
                    }
                    g_boardTemp[count - 1] = g_masterBoard[count - 1];
                }
            }
            if (count % 8 != 7)
            {
                if (g_masterBoard[count + 1] < 1)
                {
                    g_boardTemp[count + 1] = 6;
                    if (isKingSafe() == 1)
                    {
                        moveEval[moveCount] = neuralnet(testNum, variationCount);
                        move1[moveCount] = count;
                        move2[moveCount] = count + 1;
                        moveValue[moveCount] = 6;
                        ++moveCount;
                    }
                    g_boardTemp[count + 1] = g_masterBoard[count + 1];
                }
            }
            if (count < 56)
            {
                if (g_masterBoard[count + 8] < 1)
                {
                    g_boardTemp[count + 8] = 6;
                    if (isKingSafe() == 1)
                    {
                        moveEval[moveCount] = neuralnet(testNum, variationCount);
                        move1[moveCount] = count;
                        move2[moveCount] = count + 8;
                        moveValue[moveCount] = 6;
                        ++moveCount;
                    }
                    g_boardTemp[count + 8] = g_masterBoard[count + 8];
                }
                if (g_masterBoard[count + 7] < 1)
                {
                    if (count % 8 != 0)
                    {
                        g_boardTemp[count + 7] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count + 7;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[count + 7] = g_masterBoard[count + 7];
                    }
                }
                if (g_masterBoard[count + 9] < 1)
                {
                    if (count % 8 != 7)
                    {
                        g_boardTemp[count + 9] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = count;
                            move2[moveCount] = count + 9;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[count + 9] = g_masterBoard[count + 9];
                    }
                }
            }
            if (count == 60 && g_masterBoard[61] == 0 && g_masterBoard[62] == 0 && g_masterBoard[63] == 4)
            {
                if (g_toMove == 0 && g_castleKing == 1)
                {
                    g_boardTemp[61] = 6;
                    if (isKingSafe() == 1)
                    {
                        g_boardTemp[61] = 0;
                        g_boardTemp[62] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = 60;
                            move2[moveCount] = 62;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[62] = 0;
                    }
                    g_boardTemp[61] = 0;
                }
                if (g_toMove == 1 && g_opponentCastleKing == 1)
                {
                    g_boardTemp[61] = 6;
                    if (isKingSafe() == 1)
                    {
                        g_boardTemp[61] = 0;
                        g_boardTemp[62] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = 60;
                            move2[moveCount] = 62;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[62] = 0;
                    }
                    g_boardTemp[61] = 0;
                }
            }
            if (count == 60 && g_masterBoard[59] == 0 && g_masterBoard[58] == 0 && g_masterBoard[57] == 0 && g_masterBoard[56] == 4)
            {
                if (g_toMove == 0 && g_castleQueen == 1)
                {
                    g_boardTemp[59] = 6;
                    if (isKingSafe() == 1)
                    {
                        g_boardTemp[59] = 0;
                        g_boardTemp[58] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = 60;
                            move2[moveCount] = 58;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[58] = 0;
                    }
                    g_boardTemp[59] = 0;
                }
                if (g_toMove == 1 && g_opponentCastleQueen == 1)
                {
                    g_boardTemp[59] = 6;
                    if (isKingSafe() == 1)
                    {
                        g_boardTemp[59] = 0;
                        g_boardTemp[58] = 6;
                        if (isKingSafe() == 1)
                        {
                            moveEval[moveCount] = neuralnet(testNum, variationCount);
                            move1[moveCount] = 60;
                            move2[moveCount] = 58;
                            moveValue[moveCount] = 6;
                            ++moveCount;
                        }
                        g_boardTemp[58] = 0;
                    }
                    g_boardTemp[59] = 0;
                }
            }
            g_boardTemp[count] = 6;
        }
        if (g_masterBoard[count] == 2)
        {
            g_boardTemp[count] = 0;
            if (count % 8 < 7 && count > 15 && g_masterBoard[count - 15] < 1)
            {
                g_boardTemp[count - 15] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 15;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count - 15] = g_masterBoard[count - 15];
            }
            if (count % 8 > 0 && count > 15 && g_masterBoard[count - 17] < 1)
            {
                g_boardTemp[count - 17] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 17;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count - 17] = g_masterBoard[count - 17];
            }
            if (count % 8 > 1 && count > 7 && g_masterBoard[count - 10] < 1)
            {
                g_boardTemp[count - 10] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 10;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count - 10] = g_masterBoard[count - 10];
            }
            if (count % 8 > 1 && count < 56 && g_masterBoard[count + 6] < 1)
            {
                g_boardTemp[count + 6] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 6;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count + 6] = g_masterBoard[count + 6];
            }
            if (count % 8 > 0 && count < 48 && g_masterBoard[count + 15] < 1)
            {
                g_boardTemp[count + 15] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 15;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count + 15] = g_masterBoard[count + 15];
            }
            if (count % 8 < 7 && count < 48 && g_masterBoard[count + 17] < 1)
            {
                g_boardTemp[count + 17] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 17;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count + 17] = g_masterBoard[count + 17];
            }
            if (count % 8 < 6 && count < 56 && g_masterBoard[count + 10] < 1)
            {
                g_boardTemp[count + 10] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 10;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count + 10] = g_masterBoard[count + 10];
            }
            if (count % 8 < 6 && count > 7 && g_masterBoard[count - 6] < 1)
            {
                g_boardTemp[count - 6] = 2;
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 6;
                    moveValue[moveCount] = 2;
                    ++moveCount;
                }
                g_boardTemp[count - 6] = g_masterBoard[count - 6];
            }
            g_boardTemp[count] = 2;
        }

        //bishop, rook, and queen moves
        if (g_masterBoard[count] == 3 || g_masterBoard[count] == 5)
        {
            g_boardTemp[count] = 0;
            if (count > 7 && count % 8 != 0 && g_masterBoard[count - 9] < 1)
            {
                g_boardTemp[count - 9] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 9;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 9] = g_masterBoard[count - 9];
            }
            if (count > 15 && count % 8 > 1 && g_masterBoard[count - 18] < 1 && g_masterBoard[count - 9] == 0)
            {
                g_boardTemp[count - 18] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 18;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 18] = g_masterBoard[count - 18];
            }
            if (count > 23 && count % 8 > 2 && g_masterBoard[count - 27] < 1 && g_masterBoard[count - 9] == 0 && g_masterBoard[count - 18] == 0)
            {
                g_boardTemp[count - 27] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 27;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 27] = g_masterBoard[count - 27];
            }
            if (count > 31 && count % 8 > 3 && g_masterBoard[count - 36] < 1 && g_masterBoard[count - 9] == 0 && g_masterBoard[count - 18] == 0 && g_masterBoard[count - 27] == 0)
            {
                g_boardTemp[count - 36] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 36;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 36] = g_masterBoard[count - 36];
            }
            if (count > 39 && count % 8 > 4 && g_masterBoard[count - 45] < 1 && g_masterBoard[count - 9] == 0 && g_masterBoard[count - 18] == 0 && g_masterBoard[count - 27] == 0 && g_masterBoard[count - 36] == 0)
            {
                g_boardTemp[count - 45] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 45;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 45] = g_masterBoard[count - 45];
            }
            if (count > 47 && count % 8 > 5 && g_masterBoard[count - 54] < 1 && g_masterBoard[count - 9] == 0 && g_masterBoard[count - 18] == 0 && g_masterBoard[count - 27] == 0 && g_masterBoard[count - 36] == 0 && g_masterBoard[count - 45] == 0)
            {
                g_boardTemp[count - 54] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 54;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 54] = g_masterBoard[count - 54];
            }
            if (count == 63 && g_masterBoard[0] < 1 && g_masterBoard[9] == 0 && g_masterBoard[18] == 0 && g_masterBoard[27] == 0 && g_masterBoard[36] == 0 && g_masterBoard[45] == 0 && g_masterBoard[54] == 0)
            {
                g_boardTemp[0] = g_masterBoard[63];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = 63;
                    move2[moveCount] = 0;
                    moveValue[moveCount] = g_masterBoard[63];
                    ++moveCount;
                }
                g_boardTemp[0] = g_masterBoard[0];
            }



            if (count < 56 && count % 8 != 7 && g_masterBoard[count + 9] < 1)
            {
                g_boardTemp[count + 9] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 9;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 9] = g_masterBoard[count + 9];
            }
            if (count < 48 && count % 8 < 6 && g_masterBoard[count + 18] < 1 && g_masterBoard[count + 9] == 0)
            {
                g_boardTemp[count + 18] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 18;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 18] = g_masterBoard[count + 18];
            }
            if (count < 40 && count % 8 < 5 && g_masterBoard[count + 27] < 1 && g_masterBoard[count + 9] == 0 && g_masterBoard[count + 18] == 0)
            {
                g_boardTemp[count + 27] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 27;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 27] = g_masterBoard[count + 27];
            }
            if (count < 32 && count % 8 < 4 && g_masterBoard[count + 36] < 1 && g_masterBoard[count + 9] == 0 && g_masterBoard[count + 18] == 0 && g_masterBoard[count + 27] == 0)
            {
                g_boardTemp[count + 36] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 36;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 36] = g_masterBoard[count + 36];
            }
            if (count < 24 && count % 8 < 3 && g_masterBoard[count + 45] < 1 && g_masterBoard[count + 9] == 0 && g_masterBoard[count + 18] == 0 && g_masterBoard[count + 27] == 0 && g_masterBoard[count + 36] == 0)
            {
                g_boardTemp[count + 45] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 45;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 45] = g_masterBoard[count + 45];
            }
            if (count < 16 && count % 8 < 2 && g_masterBoard[count + 54] < 1 && g_masterBoard[count + 9] == 0 && g_masterBoard[count + 18] == 0 && g_masterBoard[count + 27] == 0 && g_masterBoard[count + 36] == 0 && g_masterBoard[count + 45] == 0)
            {
                g_boardTemp[count + 54] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 54;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 54] = g_masterBoard[count + 54];
            }
            if (count == 0 && g_masterBoard[63] < 1 && g_masterBoard[9] == 0 && g_masterBoard[18] == 0 && g_masterBoard[27] == 0 && g_masterBoard[36] == 0 && g_masterBoard[45] == 0 && g_masterBoard[54] == 0)
            {
                g_boardTemp[63] = g_masterBoard[0];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = 0;
                    move2[moveCount] = 63;
                    moveValue[moveCount] = g_masterBoard[0];
                    ++moveCount;
                }
                g_boardTemp[63] = g_masterBoard[63];
            }




            if (count > 7 && count % 8 != 7 && g_masterBoard[count - 7] < 1)
            {
                g_boardTemp[count - 7] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 7;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 7] = g_masterBoard[count - 7];
            }
            if (count > 15 && count % 8 < 6 && g_masterBoard[count - 14] < 1 && g_masterBoard[count - 7] == 0)
            {
                g_boardTemp[count - 14] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 14;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 14] = g_masterBoard[count - 14];
            }
            if (count > 23 && count % 8 < 5 && g_masterBoard[count - 21] < 1 && g_masterBoard[count - 7] == 0 && g_masterBoard[count - 14] == 0)
            {
                g_boardTemp[count - 21] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 21;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 21] = g_masterBoard[count - 21];
            }
            if (count > 31 && count % 8 < 4 && g_masterBoard[count - 28] < 1 && g_masterBoard[count - 7] == 0 && g_masterBoard[count - 14] == 0 && g_masterBoard[count - 21] == 0)
            {
                g_boardTemp[count - 28] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 28;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 28] = g_masterBoard[count - 28];
            }
            if (count > 39 && count % 8 < 3 && g_masterBoard[count - 35] < 1 && g_masterBoard[count - 7] == 0 && g_masterBoard[count - 14] == 0 && g_masterBoard[count - 21] == 0 && g_masterBoard[count - 28] == 0)
            {
                g_boardTemp[count - 35] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 35;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 35] = g_masterBoard[count - 35];
            }
            if (count > 47 && count % 8 < 2 && g_masterBoard[count - 42] < 1 && g_masterBoard[count - 7] == 0 && g_masterBoard[count - 14] == 0 && g_masterBoard[count - 21] == 0 && g_masterBoard[count - 28] == 0 && g_masterBoard[count - 35] == 0)
            {
                g_boardTemp[count - 42] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 42;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 54] = g_masterBoard[count - 54];
            }
            if (count == 56 && g_masterBoard[7] < 1 && g_masterBoard[14] == 0 && g_masterBoard[21] == 0 && g_masterBoard[28] == 0 && g_masterBoard[35] == 0 && g_masterBoard[42] == 0 && g_masterBoard[49] == 0)
            {
                g_boardTemp[7] = g_masterBoard[56];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = 56;
                    move2[moveCount] = 7;
                    moveValue[moveCount] = g_masterBoard[56];
                    ++moveCount;
                }
                g_boardTemp[7] = g_masterBoard[7];
            }





            if (count < 56 && count % 8 != 0 && g_masterBoard[count + 7] < 1)
            {
                g_boardTemp[count + 7] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 7;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 7] = g_masterBoard[count + 7];
            }
            if (count < 48 && count % 8 > 1 && g_masterBoard[count + 14] < 1 && g_masterBoard[count + 7] == 0)
            {
                g_boardTemp[count + 14] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 18;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 14] = g_masterBoard[count + 14];
            }
            if (count < 40 && count % 8 > 2 && g_masterBoard[count + 21] < 1 && g_masterBoard[count + 7] == 0 && g_masterBoard[count + 14] == 0)
            {
                g_boardTemp[count + 21] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 21;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 21] = g_masterBoard[count + 21];
            }
            if (count < 32 && count % 8 > 3 && g_masterBoard[count + 28] < 1 && g_masterBoard[count + 7] == 0 && g_masterBoard[count + 14] == 0 && g_masterBoard[count + 21] == 0)
            {
                g_boardTemp[count + 28] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 28;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 28] = g_masterBoard[count + 28];
            }
            if (count < 24 && count % 8 > 2 && g_masterBoard[count + 35] < 1 && g_masterBoard[count + 7] == 0 && g_masterBoard[count + 14] == 0 && g_masterBoard[count + 21] == 0 && g_masterBoard[count + 28] == 0)
            {
                g_boardTemp[count + 35] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 35;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 35] = g_masterBoard[count + 35];
            }
            if (count < 16 && count % 8 > 1 && g_masterBoard[count + 42] < 1 && g_masterBoard[count + 7] == 0 && g_masterBoard[count + 14] == 0 && g_masterBoard[count + 21] == 0 && g_masterBoard[count + 28] == 0 && g_masterBoard[count + 35] == 0)
            {
                g_boardTemp[count + 42] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 42;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 42] = g_masterBoard[count + 42];
            }
            if (count == 7 && g_masterBoard[56] < 1 && g_masterBoard[14] == 0 && g_masterBoard[21] == 0 && g_masterBoard[28] == 0 && g_masterBoard[35] == 0 && g_masterBoard[42] == 0 && g_masterBoard[49] == 0)
            {
                g_boardTemp[56] = g_masterBoard[7];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = 7;
                    move2[moveCount] = 56;
                    moveValue[moveCount] = g_masterBoard[7];
                    ++moveCount;
                }
                g_boardTemp[56] = g_masterBoard[56];
            }
            g_boardTemp[count] = g_masterBoard[count];
        }
        if (g_masterBoard[count] == 4 || g_masterBoard[count] == 5)
        {
            g_boardTemp[count] = 0;
            if (count > 7 && g_masterBoard[count - 8] < 1)
            {
                g_boardTemp[count - 8] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 8;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 8] = g_masterBoard[count - 8];
            }
            if (count > 15 && g_masterBoard[count - 16] < 1 && g_masterBoard[count - 8] == 0)
            {
                g_boardTemp[count - 16] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 16;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 16] = g_masterBoard[count - 16];
            }
            if (count > 23 && g_masterBoard[count - 24] < 1 && g_masterBoard[count - 8] == 0 && g_masterBoard[count - 16] == 0)
            {
                g_boardTemp[count - 24] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 24;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 24] = g_masterBoard[count - 24];
            }
            if (count > 31 && g_masterBoard[count - 32] < 1 && g_masterBoard[count - 8] == 0 && g_masterBoard[count - 16] == 0 && g_masterBoard[count - 24] == 0)
            {
                g_boardTemp[count - 32] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 32;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 32] = g_masterBoard[count - 32];
            }
            if (count > 39 && g_masterBoard[count - 40] < 1 && g_masterBoard[count - 8] == 0 && g_masterBoard[count - 16] == 0 && g_masterBoard[count - 24] == 0 && g_masterBoard[count - 32] == 0)
            {
                g_boardTemp[count - 40] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 40;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 40] = g_masterBoard[count - 40];
            }
            if (count > 47 && g_masterBoard[count - 48] < 1 && g_masterBoard[count - 8] == 0 && g_masterBoard[count - 16] == 0 && g_masterBoard[count - 24] == 0 && g_masterBoard[count - 32] == 0 && g_masterBoard[count - 40] == 0)
            {
                g_boardTemp[count - 48] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 48;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 48] = g_masterBoard[count - 48];
            }
            if (count > 55 && g_masterBoard[count - 56] < 1 && g_masterBoard[count - 8] == 0 && g_masterBoard[count - 16] == 0 && g_masterBoard[count - 24] == 0 && g_masterBoard[count - 32] == 0 && g_masterBoard[count - 40] == 0 && g_masterBoard[count - 48] == 0)
            {
                g_boardTemp[count - 56] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 56;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 56] = g_masterBoard[count - 56];
            }





            if (count < 56 && g_masterBoard[count + 8] < 1)
            {
                g_boardTemp[count + 8] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 8;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 8] = g_masterBoard[count + 8];
            }
            if (count < 48 && g_masterBoard[count + 16] < 1 && g_masterBoard[count + 8] == 0)
            {
                g_boardTemp[count + 16] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 16;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 16] = g_masterBoard[count + 16];
            }
            if (count < 40 && g_masterBoard[count + 24] < 1 && g_masterBoard[count + 8] == 0 && g_masterBoard[count + 16] == 0)
            {
                g_boardTemp[count + 24] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 24;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 24] = g_masterBoard[count + 24];
            }
            if (count < 32 && g_masterBoard[count + 32] < 1 && g_masterBoard[count + 8] == 0 && g_masterBoard[count + 16] == 0 && g_masterBoard[count + 24] == 0)
            {
                g_boardTemp[count + 32] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 32;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 32] = g_masterBoard[count + 32];
            }
            if (count < 24 && g_masterBoard[count + 40] < 1 && g_masterBoard[count + 8] == 0 && g_masterBoard[count + 16] == 0 && g_masterBoard[count + 24] == 0 && g_masterBoard[count + 32] == 0)
            {
                g_boardTemp[count + 40] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 40;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 40] = g_masterBoard[count + 40];
            }
            if (count < 16 && g_masterBoard[count + 48] < 1 && g_masterBoard[count + 8] == 0 && g_masterBoard[count + 16] == 0 && g_masterBoard[count + 24] == 0 && g_masterBoard[count + 32] == 0 && g_masterBoard[count + 40] == 0)
            {
                g_boardTemp[count + 48] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 48;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 48] = g_masterBoard[count + 48];
            }
            if (count < 8 && g_masterBoard[count + 56] < 1 && g_masterBoard[count + 8] == 0 && g_masterBoard[count + 16] == 0 && g_masterBoard[count + 24] == 0 && g_masterBoard[count + 32] == 0 && g_masterBoard[count + 40] == 0 && g_masterBoard[count + 48] == 0)
            {
                g_boardTemp[count + 56] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 56;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 56] = g_masterBoard[count + 56];
            }





            if (count % 8 < 7 && g_masterBoard[count + 1] < 1)
            {
                g_boardTemp[count + 1] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 1;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 1] = g_masterBoard[count + 1];
            }
            if (count % 8 < 6 && g_masterBoard[count + 2] < 1 && g_masterBoard[count + 1] == 0)
            {
                g_boardTemp[count + 2] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 2;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 2] = g_masterBoard[count + 2];
            }
            if (count % 8 < 5 && g_masterBoard[count + 3] < 1 && g_masterBoard[count + 2] == 0 && g_masterBoard[count + 1] == 0)
            {
                g_boardTemp[count + 3] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 3;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 3] = g_masterBoard[count + 3];
            }
            if (count % 8 < 4 && g_masterBoard[count + 4] < 1 && g_masterBoard[count + 3] == 0 && g_masterBoard[count + 2] == 0 && g_masterBoard[count + 1] == 0)
            {
                g_boardTemp[count + 4] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 4;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 4] = g_masterBoard[count + 4];
            }
            if (count % 8 < 3 && g_masterBoard[count + 5] < 1 && g_masterBoard[count + 4] == 0 && g_masterBoard[count + 3] == 0 && g_masterBoard[count + 2] == 0 && g_masterBoard[count + 1] == 0)
            {
                g_boardTemp[count + 5] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 5;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 5] = g_masterBoard[count + 5];
            }
            if (count % 8 < 2 && g_masterBoard[count + 6] < 1 && g_masterBoard[count + 5] == 0 && g_masterBoard[count + 4] == 0 && g_masterBoard[count + 3] == 0 && g_masterBoard[count + 2] == 0 && g_masterBoard[count + 1] == 0)
            {
                g_boardTemp[count + 6] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 6;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 6] = g_masterBoard[count + 6];
            }
            if (count % 8 == 0 && g_masterBoard[count + 7] < 1 && g_masterBoard[count + 6] == 0 && g_masterBoard[count + 5] == 0 && g_masterBoard[count + 4] == 0 && g_masterBoard[count + 3] == 0 && g_masterBoard[count + 2] == 0 && g_masterBoard[count + 1] == 0)
            {
                g_boardTemp[count + 7] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count + 7;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count + 7] = g_masterBoard[count + 7];
            }





            if (count % 8 != 0 && g_masterBoard[count - 1] < 1)
            {
                g_boardTemp[count - 1] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 1;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 1] = g_masterBoard[count - 1];
            }
            if (count % 8 > 1 && g_masterBoard[count - 2] < 1 && g_masterBoard[count - 1] == 0)
            {
                g_boardTemp[count - 2] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 2;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 2] = g_masterBoard[count - 2];
            }
            if (count % 8 > 2 && g_masterBoard[count - 3] < 1 && g_masterBoard[count - 2] == 0 && g_masterBoard[count - 1] == 0)
            {
                g_boardTemp[count - 3] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 3;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 3] = g_masterBoard[count - 3];
            }
            if (count % 8 > 3 && g_masterBoard[count - 4] < 1 && g_masterBoard[count - 3] == 0 && g_masterBoard[count - 2] == 0 && g_masterBoard[count - 1] == 0)
            {
                g_boardTemp[count - 4] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 4;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 4] = g_masterBoard[count - 4];
            }
            if (count % 8 > 4 && g_masterBoard[count - 5] < 1 && g_masterBoard[count - 4] == 0 && g_masterBoard[count - 3] == 0 && g_masterBoard[count - 2] == 0 && g_masterBoard[count - 1] == 0)
            {
                g_boardTemp[count - 5] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 5;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 5] = g_masterBoard[count - 5];
            }
            if (count % 8 > 5 && g_masterBoard[count - 6] < 1 && g_masterBoard[count - 5] == 0 && g_masterBoard[count - 4] == 0 && g_masterBoard[count - 3] == 0 && g_masterBoard[count - 2] == 0 && g_masterBoard[count - 1] == 0)
            {
                g_boardTemp[count - 6] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 6;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 6] = g_masterBoard[count - 6];
            }
            if (count % 8 == 7 && g_masterBoard[count - 7] < 1 && g_masterBoard[count - 6] == 0 && g_masterBoard[count - 5] == 0 && g_masterBoard[count - 4] == 0 && g_masterBoard[count - 3] == 0 && g_masterBoard[count - 2] == 0 && g_masterBoard[count - 1] == 0)
            {
                g_boardTemp[count - 7] = g_masterBoard[count];
                if (isKingSafe() == 1)
                {
                    moveEval[moveCount] = neuralnet(testNum, variationCount);
                    move1[moveCount] = count;
                    move2[moveCount] = count - 7;
                    moveValue[moveCount] = g_masterBoard[count];
                    ++moveCount;
                }
                g_boardTemp[count - 7] = g_masterBoard[count - 7];
            }
            g_boardTemp[count] = g_masterBoard[count];
        }
    }
    for (int count{}; count < moveCount; ++count)
    {
        //std::cout << moveEval[count] << '\n';
    }
        
    if (moveCount == 0)
    {
        if (g_toMove == 0)
        {
            return 2;
        }
        if (g_toMove == 1)
        {
            return 1;
        }
    }
    int bestMove1{}, bestMove2{}, bestMoveEval{ -20 }, bestMoveValue{};
    while (moveCount > 0)
    {
        if (moveEval[moveCount] > bestMoveEval)
        {
            bestMoveEval = moveEval[moveCount - 1];
            bestMove1 = move1[moveCount - 1];
            bestMove2 = move2[moveCount - 1];
            bestMoveValue = moveValue[moveCount - 1];
        }
        --moveCount;
    }
    if (g_masterBoard[bestMove1] == 6)
    {
        if (g_toMove == 0)
        {
            g_castleKing = 0;
            g_castleQueen = 0;
        }
        if (g_toMove == 1)
        {
            g_opponentCastleKing = 0;
            g_opponentCastleQueen = 0;
        }
    }
    if (g_masterBoard[bestMove1] == 4)
    {
        if (g_toMove == 0)
        {
            if (bestMove1 == 63)
            {
                g_castleKing = 0;
            }
            if (bestMove1 == 56)
            {
                g_castleQueen = 0;
            }
        }
        if (g_toMove == 1)
        {
            if (bestMove1 == 63)
            {
                g_opponentCastleKing = 0;
            }
            if (bestMove1 == 56)
            {
                g_opponentCastleQueen = 0;
            }
        }
    }
    if (g_masterBoard[bestMove2] == -4)
    {
        if (g_toMove == 0)
        {
            if (bestMove2 == 7)
            {
                g_opponentCastleKing = 0;
            }
            if (bestMove1 == 0)
            {
                g_opponentCastleQueen = 0;
            }
        }
        if (g_toMove == 1)
        {
            if (bestMove2 == 7)
            {
                g_castleKing = 0;
            }
            if (bestMove1 == 0)
            {
                g_castleQueen = 0;
            }
        }
    }
    for (int count{}; count < 64; ++count)
    {
        g_masterBoard[bestMove2] = bestMoveValue;
        g_masterBoard[bestMove1] = 0;
    }
    if (bestMove1 == 60 && bestMove2 == 62 && bestMoveValue == 6)
    {
        g_masterBoard[63] = 0;
        g_masterBoard[61] = 4;
    }
    if (bestMove1 == 60 && bestMove2 == 58 && bestMoveValue == 6)
    {
        g_masterBoard[56] = 0;
        g_masterBoard[59] = 4;
    }
    g_prevMove1 = std::abs(bestMove1 - 63);
    g_prevMove2 = std::abs(bestMove2 - 63);
    ++g_fiftyMoveRule;
    if (g_fiftyMoveRule > 100)
    {
        return 1;
    }
    //std::cout << bestMoveEval << '\t';
    //std::cout << bestMoveValue << '\t';
    //std::cout << bestMove1 << '\t';
    //std::cout << bestMove2 << '\n';
    return 0;
}

void generateNewWeights()
{
    std::uniform_int_distribution<> die{ 1, 704 };
    std::uniform_int_distribution<> die2{ 1, 4};
    std::uniform_int_distribution<> die3{ -1000, 1000 };
    for (int count{}; count < 100; ++count)
    {
        int count2{};
        for (; count2 < die(mersenne); ++count2)
        {
            g_weightTest[count][count2] = g_weightMaster[die2(mersenne)][count2];
        }
        for (; count2 < 705; ++count2)
        {
            g_weightTest[count][count2] = g_weightMaster[0][count2];
        }
    }
    for (int count{}; count < 100; ++count)
    {
        g_weightTest[count][die(mersenne)] = die3(mersenne) / 100;
    }
}

void train()
{
    std::cout << "how many generations do you want to train the neural net?\n";
    int generations, result{}, moveCount{};
    std::cin >> generations;
    Timer t;
    while (generations > 0)
    {
        generateNewWeights();
        int fitness[100]{}, bestFitness1{2}, bestFitness2{ 2 }, bestFitness3{ 2 }, bestFitness4{ 2 }, bestFitness5{ 2 }, bestFitnessCount{0};
        for (int variationCount{}; variationCount < 1; ++variationCount)
        {
            for (int count{}; count < 5; ++count)
            {
                while (result == 0)
                {
                    result = playMove(count, variationCount);
                    ++moveCount;
                    if (g_showMoves == 1 && variationCount==99)
                    {
                        for (int count2{}; count2 < 64; ++count2)
                        {
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\t';
                            ++count2;
                            std::cout << g_masterBoard[count2] << '\n';
                        }
                        std::cout << '\n';
                    }
                    for (int count2{}; count2 < 64; ++count2)
                    {
                        g_masterBoard[count2] = g_masterBoard[count2] * -1;
                        g_boardTemp[count2] = g_masterBoard[count2];
                    }
                    int count3{ 63 };
                    for (int count2{}; count2 < 64; ++count2)
                    {
                        g_masterBoard[count2] = g_boardTemp[count3];
                        --count3;
                    }
                    count3 = 63;
                    for (int count2{}; count2 < 64; ++count2)
                    {
                        g_boardTemp[count2] = g_masterBoard[count2];
                    }
                }
                if (result == 2)
                {
                    ++fitness[variationCount];
                }
                result = 0;
                g_fiftyMoveRule = 0;
                g_masterBoard[0] = -4;
                g_masterBoard[1] = -2;
                g_masterBoard[2] = -3;
                g_masterBoard[3] = -5;
                g_masterBoard[4] = -6;
                g_masterBoard[5] = -3;
                g_masterBoard[6] = -2;
                g_masterBoard[7] = -4;
                g_masterBoard[8] = -1;
                g_masterBoard[9] = -1;
                g_masterBoard[10] = -1;
                g_masterBoard[11] = -1;
                g_masterBoard[12] = -1;
                g_masterBoard[13] = -1;
                g_masterBoard[14] = -1;
                g_masterBoard[15] = -1;
                for (int count2{ 16 }; count2 < 48; ++count2)
                {
                    g_masterBoard[count2] = 0;
                }
                g_masterBoard[49] = 1;
                g_masterBoard[50] = 1;
                g_masterBoard[51] = 1;
                g_masterBoard[52] = 1;
                g_masterBoard[53] = 1;
                g_masterBoard[54] = 1;
                g_masterBoard[55] = 1;
                g_masterBoard[56] = 4;
                g_masterBoard[57] = 2;
                g_masterBoard[58] = 3;
                g_masterBoard[59] = 5;
                g_masterBoard[60] = 6;
                g_masterBoard[61] = 3;
                g_masterBoard[62] = 2;
                g_masterBoard[63] = 4;
            }
        }
        --generations;
        for (int count{}; count < 100; ++count)
        {
            if (fitness[count] > bestFitness1)
            {
                for (int count2{}; count2 < 705; ++count2)
                {
                    g_weightMaster[0][count2] = g_weightTest[count][count2];
                }
            }
            else if (fitness[count] > bestFitness2)
            {
                for (int count2{}; count2 < 705; ++count2)
                {
                    g_weightMaster[0][count2] = g_weightTest[count][count2];
                }
            }
            else if (fitness[count] > bestFitness3)
            {
                for (int count2{}; count2 < 705; ++count2)
                {
                    g_weightMaster[0][count2] = g_weightTest[count][count2];
                }
            }
            else if (fitness[count] > bestFitness4)
            {
                for (int count2{}; count2 < 705; ++count2)
                {
                    g_weightMaster[0][count2] = g_weightTest[count][count2];
                }
            }
            else if (fitness[count] > bestFitness5)
            {
                for (int count2{}; count2 < 705; ++count2)
                {
                    g_weightMaster[0][count2] = g_weightTest[count][count2];
                }
            }
        }
        std::cout << moveCount << '\n';
    }
    std::cout << "training finished\n";
    std::cout << t.elapsed();
}

int main()
{
    std::fstream neuralNetWeights;
    neuralNetWeights.open("neuralNetWeights705.txt");
    if (!neuralNetWeights)
    {
        std::cerr << "no weights file";
        return 1;
    }
    for (int count{}; count < 705; ++count)
    {
        for (int count2{}; count2 < 5; ++count2)
        {
            neuralNetWeights >> g_weightMaster[count2][count];
        }
    }
    for (int count{}; count < 40; ++count)
    {
        std::cout << g_weightMaster[0][count];
    }
    std::cout << "do you want to show moves? 1 for yes, 0 for no\n";
    std::cin >> g_showMoves;
    train();
    neuralNetWeights.seekg(0, std::ios::beg);
    for (int count{}; count < 705; ++count)
    {
        neuralNetWeights << g_weightMaster[0][count];
    }
    neuralNetWeights.close();
    return 0;
}
