#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
float g_weight[705], g_weightTest[705];
bool g_toMove{ 0 }, g_castleKing, g_castleQueen, g_opponentCastleKing, g_opponentCastleQueen;
int g_masterBoard[64]{ -4, -2, -3, -5, -6, -3, -2, -4, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 3, 5, 6, 3, 2, 4 }, g_prevMove1, g_prevMove2, g_fiftyMoveRule, g_squareTemp[64];
//neuronfinal
float neuronFinal(float weight, float i1, float i2, float i3, float i4, float i5, float i6, float i7, float i8, float i9, float i10, float i11, float i12, float i13, float i14, float i15, float i16, float i17, float i18, float i19, float i20, float i21, float i22, float i23, float i24, float i25, float i26, float i27, float i28, float i29, float i30, float i31, float i32, float i33, float i34, float i35, float i36, float i37, float i38, float i39, float i40, float i41, float i42, float i43, float i44, float i45, float i46, float i47, float i48, float i49, float i50, float i51, float i52, float i53, float i54, float i55, float i56, float i57, float i58, float i59, float i60, float i61, float i62, float i63, float i64)
{
   float x(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10+i11+i12+i13+i14+i15+i16+i17+i18+i19+i20+i21+i22+i23+i24+i25+i26+i27+i28+i29+i30+i31+i32+i33+i34+i35+i36+i37+i38+i39+i40+i41+i42+i43+i44+i45+i46+i47+i48+i49+i50+i51+i52+i53+i54+i55+i56+i57+i58+i59+i60+i61+i62+i63+i64);
   x=x*weight;
   x=-1*(20/(1 + std::pow(1.125, x))) + 10;
   return x;
}
//neuron
float neuron(float weight, float i1, float i2, float i3, float i4, float i5, float i6, float i7, float i8, float i9, float i10, float i11, float i12, float i13, float i14, float i15, float i16, float i17, float i18, float i19, float i20, float i21, float i22, float i23, float i24, float i25, float i26, float i27, float i28, float i29, float i30, float i31, float i32, float i33, float i34, float i35, float i36, float i37, float i38, float i39, float i40, float i41, float i42, float i43, float i44, float i45, float i46, float i47, float i48, float i49, float i50, float i51, float i52, float i53, float i54, float i55, float i56, float i57, float i58, float i59, float i60, float i61, float i62, float i63, float i64)
{
   float x(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10+i11+i12+i13+i14+i15+i16+i17+i18+i19+i20+i21+i22+i23+i24+i25+i26+i27+i28+i29+i30+i31+i32+i33+i34+i35+i36+i37+i38+i39+i40+i41+i42+i43+i44+i45+i46+i47+i48+i49+i50+i51+i52+i53+i54+i55+i56+i57+i58+i59+i60+i61+i62+i63+i64);
   x=x*weight;
   x=-2*(1/(1 + std::pow(2, x))) + 2;
   return x;
}
//neuralnet
float neuralNet(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int c0, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int e0, int e1, int e2, int e3, int e4, int e5, int e6, int e7, int f0, int f1, int f2, int f3, int f4, int f5, int f6, int f7, int g0, int g1, int g2, int g3, int g4, int g5, int g6, int g7, int h0, int h1, int h2, int h3, int h4, int h5, int h6, int h7)
{
   float n[64], ntest[64];
   int output1{ 0 }, output2{ 0 }, count{ 0 }, count2{ 0 }, count3{ 0 };
   if (g_toMove==0)
   {
      while (count<64)
      {
         n[count]=neuron(g_weight[count2], a0, a1, a2, a3, a4, a5, a6, a7, b0, b1, b2, b3, b4, b5, b6, b7, c0, c1, c2, c3, c4, c5, c6, c7, d0, d1, d2, d3, d4, d5, d6, d7, e0, e1, e2, e3, e4, e5, e6, e7, f0, f1, f2, f3, f4, f5, f6, f7, g0, g1, g2, g3, g4, g5, g6, g7, h0, h1, h2, h3, h4, h5, h6, h7);
         ++count;
         ++count2;
      }
      count=0;
      while (count3<10)
      {
         while (count<64)
         {
            ntest[count]=neuron(g_weight[count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
            ++count;
            ++count2;
         }
         count=0;
         while (count<64)
         {
            n[count]=ntest[count];
            ++count;
         }
         count=0;
         ++count3;
      }
      n[0]=neuronFinal(g_weight[count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
      return n[0];
   }
   
   
   if (g_toMove==1)
   {
      while (count<64)
      {
         n[count]=neuron(g_weightTest[count2], a0, a1, a2, a3, a4, a5, a6, a7, b0, b1, b2, b3, b4, b5, b6, b7, c0, c1, c2, c3, c4, c5, c6, c7, d0, d1, d2, d3, d4, d5, d6, d7, e0, e1, e2, e3, e4, e5, e6, e7, f0, f1, f2, f3, f4, f5, f6, f7, g0, g1, g2, g3, g4, g5, g6, g7, h0, h1, h2, h3, h4, h5, h6, h7);
         ++count;
         ++count2;
      }
      count=0;
      while (count3<10)
      {
         while (count<64)
         {
            ntest[count]=neuron(g_weightTest[count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
            ++count;
            ++count2;
         }
         count=0;
         while (count<64)
         {
            n[count]=ntest[count];
            ++count;
         }
         count=0;
         ++count3;
      }
      n[0]=neuronFinal(g_weightTest[count2], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20], n[21], n[22], n[23], n[24], n[25], n[26], n[27], n[28], n[29], n[30], n[31], n[32], n[33], n[34], n[35], n[36], n[37], n[38], n[39], n[40], n[41], n[42], n[43], n[44], n[45], n[46], n[47], n[48], n[49], n[50], n[51], n[52], n[53], n[54], n[55], n[56], n[57], n[58], n[59], n[60], n[61], n[62], n[63]);
      return n[0];
   }
   return 0;
}
//mutate
void mutate()
{
   int x, count{0};
   while (count<705)
   {
      g_weightTest[count]=g_weight[count];
      ++count;
   }
   std::uniform_int_distribution<> die1{1, 706};
   std::uniform_int_distribution<> die2{-10000, 10000};
   x = die1(mersenne);
   while (x>0)
   {
      int y;
      y=die1(mersenne)-1;
      g_weightTest[y]=die2(mersenne);
      g_weightTest[y]=g_weightTest[y]/100;
      --x;
   }
}
//draws
bool gameDrawn()
{
    bool draw{1};
    int count{0}, bishopCount{0}, knightCount{0};
   while (count<64)
   {
      if (g_masterBoard[count]==4 || g_masterBoard[count]==5 || g_masterBoard[count]==1)
      {
         draw=0;
      }
      if (g_masterBoard[count]==3)
      {
         ++bishopCount;
      }
      if (g_masterBoard[count]==2)
      {
         ++knightCount;
      }
      if (bishopCount==2)
      {
         draw=0;
      }
      if (bishopCount==1 && knightCount>0)
      {
         draw=0;
      }
      ++count;
   }
   if (g_fiftyMoveRule==100)
   {
      draw=1;
   }
   
   return draw;
}
bool isKingAttacked()
{
    bool isLegalMove{ true };
    int count{ 0 }, square[64];
    while (count < 64)
    {
        square[count] = g_squareTemp[count];
        ++count;
    }
        while (count < 64)
        {
            if (g_squareTemp[count] == 6)
            {
                //upwards checks
                if (count > 7)
                {
                    if (g_squareTemp[count - 8] == -4 || g_squareTemp[count - 8] == -5 || g_squareTemp[count - 8] == -6)
                    {
                        isLegalMove = false;
                    }
                }
                if (count > 15)
                {
                    if (g_squareTemp[count - 16] == -4 || g_squareTemp[count - 16] == -5)
                    {
                        if (g_squareTemp[count - 8] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count > 23)
                {
                    if (g_squareTemp[count - 24] == -4 || g_squareTemp[count - 24] == -5)
                    {
                        if (g_squareTemp[count - 8] == 0 && g_squareTemp[count - 16] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count > 31)
                {
                    if (g_squareTemp[count - 32] == -4 || g_squareTemp[count - 32] == -5)
                    {
                        if (g_squareTemp[count - 8] == 0 && g_squareTemp[count - 16] == 0 && g_squareTemp[count - 24] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count > 39)
                {
                    if (g_squareTemp[count - 40] == -4 || g_squareTemp[count - 40] == -5)
                    {
                        if (g_squareTemp[count - 8] == 0 && g_squareTemp[count - 16] == 0 && g_squareTemp[count - 24] == 0 && g_squareTemp[count - 32] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count > 47)
                {
                    if (g_squareTemp[count - 48] == -4 || g_squareTemp[count - 48] == -5)
                    {
                        if (g_squareTemp[count - 8] == 0 && g_squareTemp[count - 16] == 0 && g_squareTemp[count - 24] == 0 && g_squareTemp[count - 32] == 0 && g_squareTemp[count - 40] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count > 55)
                {
                    if (g_squareTemp[count - 56] == -4 || g_squareTemp[count - 56] == -5)
                    {
                        if (g_squareTemp[count - 8] == 0 && g_squareTemp[count - 16] == 0 && g_squareTemp[count - 24] == 0 && g_squareTemp[count - 32] == 0 && g_squareTemp[count - 40] == 0 && g_squareTemp[count - 48] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                //downwards checks
                if (count < 56)
                {
                    if (g_squareTemp[count + 8] == -4 || g_squareTemp[count + 8] == -5 || g_squareTemp[count + 8] == -6)
                    {
                        isLegalMove = false;
                    }
                }
                if (count < 48)
                {
                    if (g_squareTemp[count + 16] == -4 || g_squareTemp[count + 16] == -5)
                    {
                        if (g_squareTemp[count + 8] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count < 40)
                {
                    if (g_squareTemp[count + 24] == -4 || g_squareTemp[count + 24] == -5)
                    {
                        if (g_squareTemp[count + 8] == 0 && g_squareTemp[count + 16] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count < 32)
                {
                    if (g_squareTemp[count + 32] == -4 || g_squareTemp[count + 32] == -5)
                    {
                        if (g_squareTemp[count + 8] == 0 && g_squareTemp[count + 16] == 0 && g_squareTemp[count + 24] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count < 24)
                {
                    if (g_squareTemp[count + 40] == -4 || g_squareTemp[count + 40] == -5)
                    {
                        if (g_squareTemp[count + 8] == 0 && g_squareTemp[count + 16] == 0 && g_squareTemp[count + 24] == 0 && g_squareTemp[count + 32] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count < 16)
                {
                    if (g_squareTemp[count + 48] == -4 || g_squareTemp[count + 48] == -5)
                    {
                        if (g_squareTemp[count + 8] == 0 && g_squareTemp[count + 16] == 0 && g_squareTemp[count + 24] == 0 && g_squareTemp[count + 32] == 0 && g_squareTemp[count + 40] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count < 8)
                {
                    if (g_squareTemp[count + 56] == -4 || g_squareTemp[count + 56] == -5)
                    {
                        if (g_squareTemp[count + 8] == 0 && g_squareTemp[count + 16] == 0 && g_squareTemp[count + 24] == 0 && g_squareTemp[count + 32] == 0 && g_squareTemp[count + 40] == 0 && g_squareTemp[count + 48] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                //checks from right
                if (count % 8 < 7)
                {
                    if (g_squareTemp[count + 1] == -4 || g_squareTemp[count + 1] == -5 || g_squareTemp[count + 1] == -6)
                    {
                        isLegalMove = false;
                    }
                }
                if (count % 8 < 6)
                {
                    if (g_squareTemp[count + 2] == -4 || g_squareTemp[count + 2] == -5)
                    {
                        if (g_squareTemp[count + 1] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 < 5)
                {
                    if (g_squareTemp[count + 3] == -4 || g_squareTemp[count + 3] == -5)
                    {
                        if (g_squareTemp[count + 1] == 0 && g_squareTemp[count + 2] == 0)
                        {
                            isLegalMove = true;
                        }
                    }
                }
                if (count % 8 < 4)
                {
                    if (g_squareTemp[count + 4] == -4 || g_squareTemp[count + 4] == -5)
                    {
                        if (g_squareTemp[count + 1] == 0 && g_squareTemp[count + 2] == 0 && g_squareTemp[count + 3] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 < 3)
                {
                    if (g_squareTemp[count + 5] == -4 || g_squareTemp[count + 5] == -5)
                    {
                        if (g_squareTemp[count + 1] == 0 && g_squareTemp[count + 2] == 0 && g_squareTemp[count + 3] == 0 && g_squareTemp[count + 4] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 < 2)
                {
                    if (g_squareTemp[count + 6] == -4 || g_squareTemp[count + 6] == -5)
                    {
                        if (g_squareTemp[count + 1] == 0 && g_squareTemp[count + 2] == 0 && g_squareTemp[count + 3] == 0 && g_squareTemp[count + 4] == 0 && g_squareTemp[count + 5] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 < 1)
                {
                    if (g_squareTemp[count + 7] == -4 || g_squareTemp[count + 7] == -5)
                    {
                        if (g_squareTemp[count + 1] == 0 && g_squareTemp[count + 2] == 0 && g_squareTemp[count + 3] == 0 && g_squareTemp[count + 4] == 0 && g_squareTemp[count + 5] == 0 && g_squareTemp[count + 6] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                //checks from left
                if (count % 8 > 6)
                {
                    if (g_squareTemp[count - 1] == -4 || g_squareTemp[count - 1] == -5 || g_squareTemp[count - 1] == -6)
                    {
                        isLegalMove = false;
                    }
                }
                if (count % 8 > 5)
                {
                    if (g_squareTemp[count - 2] == -4 || g_squareTemp[count - 2] == -5)
                    {
                        if (g_squareTemp[count - 1] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 > 4)
                {
                    if (g_squareTemp[count - 3] == -4 || g_squareTemp[count - 3] == -5)
                    {
                        if (g_squareTemp[count - 1] == 0 && g_squareTemp[count - 2] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 > 3)
                {
                    if (g_squareTemp[count - 4] == -4 || g_squareTemp[count - 4] == -5)
                    {
                        if (g_squareTemp[count - 1] == 0 && g_squareTemp[count - 2] == 0 && g_squareTemp[count - 3] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 > 2)
                {
                    if (g_squareTemp[count - 5] == -4 || g_squareTemp[count - 5] == -5)
                    {
                        if (g_squareTemp[count - 1] == 0 && g_squareTemp[count - 2] == 0 && g_squareTemp[count - 3] == 0 && g_squareTemp[count - 4] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 < 2)
                {
                    if (g_squareTemp[count - 6] == -4 || g_squareTemp[count - 6] == -5)
                    {
                        if (g_squareTemp[count - 1] == 0 && g_squareTemp[count - 2] == 0 && g_squareTemp[count + 3] == 0 && g_squareTemp[count - 4] == 0 && g_squareTemp[count - 5] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count % 8 < 1)
                {
                    if (g_squareTemp[count - 7] == -4 || g_squareTemp[count - 7] == -5)
                    {
                        if (g_squareTemp[count - 1] == 0 && g_squareTemp[count - 2] == 0 && g_squareTemp[count - 3] == 0 && g_squareTemp[count - 4] == 0 && g_squareTemp[count - 5] == 0 && g_squareTemp[count - 6] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                //checks from negative diagonal
                if (count == 0)
                {
                    if (g_squareTemp[63] == -3 || g_squareTemp[63] == -5)
                    {
                        if (g_squareTemp[9] == 0 && g_squareTemp[18] == 0 && g_squareTemp[27] == 0 && g_squareTemp[36] == 0 && g_squareTemp[45] == 0 && g_squareTemp[54] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 63)
                {
                    if (g_squareTemp[0] == -3 || g_squareTemp[0] == -5)
                    {
                        if (g_squareTemp[9] == 0 && g_squareTemp[18] == 0 && g_squareTemp[27] == 0 && g_squareTemp[36] == 0 && g_squareTemp[45] == 0 && g_squareTemp[54] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 0 || count == 1 || count == 8 || count == 9)
                {
                    if (g_squareTemp[count + 54] == -3 || g_squareTemp[count + 54] == -5)
                    {
                        if (g_squareTemp[count + 45] == 0 && g_squareTemp[count + 36] == 0 && g_squareTemp[count + 27] == 0 && g_squareTemp[count + 18] == 0 && g_squareTemp[count + 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18)
                {
                    if (g_squareTemp[count + 45] == -3 || g_squareTemp[count + 45] == -5)
                    {
                        if (g_squareTemp[count + 36] == 0 && g_squareTemp[count + 27] == 0 && g_squareTemp[count + 18] == 0 && g_squareTemp[count + 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18 || count == 3 || count == 11 || count == 19 || count == 24 || count == 25 || count == 26 || count == 27)
                {
                    if (g_squareTemp[count + 36] == -3 || g_squareTemp[count + 36] == -5)
                    {
                        if (g_squareTemp[count + 27] == 0 && g_squareTemp[count + 18] == 0 && g_squareTemp[count + 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18 || count == 3 || count == 11 || count == 19 || count == 24 || count == 25 || count == 26 || count == 27 || count == 4 || count == 12 || count == 20 || count == 28 || count == 32 || count == 33 || count == 34 || count == 35 || count == 36)
                {
                    if (g_squareTemp[count + 27] == -3 || g_squareTemp[count + 27] == -5)
                    {
                        if (g_squareTemp[count + 18] == 0 && g_squareTemp[count + 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 0 || count == 1 || count == 8 || count == 9 || count == 2 || count == 10 || count == 16 || count == 17 || count == 18 || count == 3 || count == 11 || count == 19 || count == 24 || count == 25 || count == 26 || count == 27 || count == 4 || count == 12 || count == 20 || count == 28 || count == 32 || count == 33 || count == 34 || count == 35 || count == 36 || count == 5 || count == 13 || count == 21 || count == 29 || count == 37 || count == 40 || count == 41 || count == 42 || count == 43 || count == 44 || count == 45)
                {
                    if (g_squareTemp[count + 18] == -3 || g_squareTemp[count + 18] == -5)
                    {
                        if (g_squareTemp[count + 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count != 7 && count != 15 && count != 23 && count != 31 && count != 39 && count != 47 && count != 55 && count != 56 && count != 57 && count != 58 && count != 59 && count != 60 && count != 61 && count != 62 && count != 63)
                {
                    if (g_squareTemp[count + 9] == -3 || g_squareTemp[count + 9] == -5 || g_squareTemp[count + 9] == -6)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 63 || count == 62 || count == 55 || count == 54)
                {
                    if (g_squareTemp[count - 54] == -3 || g_squareTemp[count - 54] == -5)
                    {
                        if (g_squareTemp[count - 45] == 0 && g_squareTemp[count - 36] == 0 && g_squareTemp[count - 27] == 0 && g_squareTemp[count - 18] == 0 && g_squareTemp[count - 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45)
                {
                    if (g_squareTemp[count - 45] == -3 || g_squareTemp[count - 45] == -5)
                    {
                        if (g_squareTemp[count - 36] == 0 && g_squareTemp[count - 27] == 0 && g_squareTemp[count - 18] == 0 && g_squareTemp[count - 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45 || count == 60 || count == 52 || count == 44 || count == 39 || count == 38 || count == 37 || count == 36)
                {
                    if (g_squareTemp[count - 36] == -3 || g_squareTemp[count - 36] == -5)
                    {
                        if (g_squareTemp[count - 27] == 0 && g_squareTemp[count - 18] == 0 && g_squareTemp[count - 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45 || count == 60 || count == 52 || count == 44 || count == 39 || count == 38 || count == 37 || count == 36 || count == 59 || count == 51 || count == 43 || count == 35 || count == 31 || count == 30 || count == 29 || count == 28 || count == 27)
                {
                    if (g_squareTemp[count - 27] == -3 || g_squareTemp[count - 27] == -5)
                    {
                        if (g_squareTemp[count - 18] == 0 && g_squareTemp[count - 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 63 || count == 62 || count == 55 || count == 54 || count == 61 || count == 53 || count == 47 || count == 46 || count == 45 || count == 60 || count == 52 || count == 44 || count == 39 || count == 38 || count == 37 || count == 36 || count == 59 || count == 51 || count == 43 || count == 35 || count == 31 || count == 30 || count == 29 || count == 28 || count == 27 || count == 58 || count == 50 || count == 42 || count == 34 || count == 37 || count == 23 || count == 22 || count == 21 || count == 20 || count == 19 || count == 18)
                {
                    if (g_squareTemp[count - 18] == -3 || g_squareTemp[count - 18] == -5)
                    {
                        if (g_squareTemp[count - 9] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count != 0 && count != 1 && count != 2 && count != 3 && count != 4 && count != 5 && count != 6 && count != 7 && count != 8 && count != 16 && count != 24 && count != 32 && count != 40 && count != 48 && count != 56)
                {
                    if (g_squareTemp[count - 9] == -3 || g_squareTemp[count - 9] == -5 || g_squareTemp[count - 9] == -6 || g_squareTemp[count - 9] == -1)
                    {
                        isLegalMove = false;
                    }
                }
                //checks from positive diagonal
                if (count == 56)
                {
                    if (g_squareTemp[7] == -3 || g_squareTemp[7] == -5)
                    {
                        if (g_squareTemp[49] == 0 && g_squareTemp[42] == 0 && g_squareTemp[35] == 0 && g_squareTemp[28] == 0 && g_squareTemp[21] == 0 && g_squareTemp[14] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 7)
                {
                    if (g_squareTemp[56] == -3 || g_squareTemp[56] == -5)
                    {
                        if (g_squareTemp[49] == 0 && g_squareTemp[42] == 0 && g_squareTemp[35] == 0 && g_squareTemp[28] == 0 && g_squareTemp[21] == 0 && g_squareTemp[14] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 56 || count == 57 || count == 48 || count == 49)
                {
                    if (g_squareTemp[count - 42] == -3 || g_squareTemp[count - 42] == -5)
                    {
                        if (g_squareTemp[count - 35] == 0 && g_squareTemp[count - 28] == 0 && g_squareTemp[count - 21] == 0 && g_squareTemp[count - 14] == 0 && g_squareTemp[count - 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42)
                {
                    if (g_squareTemp[count - 35] == -3 || g_squareTemp[count - 35] == -5)
                    {
                        if (g_squareTemp[count - 28] == 0 && g_squareTemp[count - 21] == 0 && g_squareTemp[count - 14] == 0 && g_squareTemp[count - 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42 || count == 59 || count == 51 || count == 43 || count == 32 || count == 33 || count == 34 || count == 35)
                {
                    if (g_squareTemp[count - 28] == -3 || g_squareTemp[count - 28] == -5)
                    {
                        if (g_squareTemp[count - 21] == 0 && g_squareTemp[count - 14] == 0 && g_squareTemp[count - 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42 || count == 59 || count == 51 || count == 43 || count == 32 || count == 33 || count == 34 || count == 35 || count == 60 || count == 52 || count == 44 || count == 36 || count == 24 || count == 25 || count == 26 || count == 27 || count == 28)
                {
                    if (g_squareTemp[count - 21] == -3 || g_squareTemp[count - 21] == -5)
                    {
                        if (g_squareTemp[count - 14] == 0 && g_squareTemp[count - 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 56 || count == 57 || count == 48 || count == 49 || count == 58 || count == 50 || count == 40 || count == 41 || count == 42 || count == 59 || count == 51 || count == 43 || count == 32 || count == 33 || count == 34 || count == 35 || count == 60 || count == 52 || count == 44 || count == 36 || count == 24 || count == 25 || count == 26 || count == 27 || count == 28 || count == 61 || count == 53 || count == 45 || count == 37 || count == 29 || count == 16 || count == 17 || count == 18 || count == 19 || count == 20 || count == 21)
                {
                    if (g_squareTemp[count - 14] == -3 || g_squareTemp[count - 14] == -5)
                    {
                        if (g_squareTemp[count - 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count != 0 && count != 1 && count != 2 && count != 3 && count != 4 && count != 5 && count != 6 && count != 7 && count != 15 && count != 23 && count != 31 && count != 39 && count != 47 && count != 55 && count != 63)
                {
                    if (g_squareTemp[count - 7] == -3 || g_squareTemp[count - 7] == -5 || g_squareTemp[count - 7] == -6 || g_squareTemp[count - 7] == -1)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 7 || count == 6 || count == 15 || count == 14)
                {
                    if (g_squareTemp[count + 42] == -3 || g_squareTemp[count + 42] == -5)
                    {
                        if (g_squareTemp[count + 35] == 0 && g_squareTemp[count + 28] == 0 && g_squareTemp[count + 21] == 0 && g_squareTemp[count + 14] == 0 && g_squareTemp[count + 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21)
                {
                    if (g_squareTemp[count + 35] == -3 || g_squareTemp[count + 35] == -5)
                    {
                        if (g_squareTemp[count + 28] == 0 && g_squareTemp[count + 21] == 0 && g_squareTemp[count + 14] == 0 && g_squareTemp[count + 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21 || count == 4 || count == 12 || count == 20 || count == 31 || count == 30 || count == 29 || count == 28)
                {
                    if (g_squareTemp[count + 28] == -3 || g_squareTemp[count + 28] == -5)
                    {
                        if (g_squareTemp[count + 21] == 0 && g_squareTemp[count + 14] == 0 && g_squareTemp[count + 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21 || count == 4 || count == 12 || count == 20 || count == 31 || count == 30 || count == 29 || count == 28 || count == 3 || count == 11 || count == 19 || count == 27 || count == 39 || count == 38 || count == 37 || count == 36 || count == 35)
                {
                    if (g_squareTemp[count + 21] == -3 || g_squareTemp[count + 21] == -5)
                    {
                        if (g_squareTemp[count + 14] == 0 && g_squareTemp[count + 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count == 7 || count == 6 || count == 15 || count == 14 || count == 5 || count == 13 || count == 23 || count == 22 || count == 21 || count == 4 || count == 12 || count == 20 || count == 31 || count == 30 || count == 29 || count == 28 || count == 3 || count == 11 || count == 19 || count == 27 || count == 39 || count == 38 || count == 37 || count == 36 || count == 35 || count == 2 || count == 10 || count == 18 || count == 26 || count == 34 || count == 47 || count == 46 || count == 45 || count == 44 || count == 43 || count == 42)
                {
                    if (g_squareTemp[count + 14] == -3 || g_squareTemp[count + 14] == -5)
                    {
                        if (g_squareTemp[count + 7] == 0)
                        {
                            isLegalMove = false;
                        }
                    }
                }
                if (count != 0 && count != 8 && count != 16 && count != 24 && count != 32 && count != 40 && count != 48 && count != 56 && count != 57 && count != 58 && count != 59 && count != 60 && count != 61 && count != 62 && count != 63)
                {
                    if (g_squareTemp[count + 7] == -3 || g_squareTemp[count + 7] == -5 || g_squareTemp[count + 7] == -6)
                    {
                        isLegalMove = false;
                    }
                }
                //checks from knights
                if (count == 0)
                {
                    if (g_squareTemp[10] == -2 || g_squareTemp[17] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 1)
                {
                    if (g_squareTemp[11] == -2 || g_squareTemp[18] == -2 || g_squareTemp[16] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 8)
                {
                    if (g_squareTemp[18] == -2 || g_squareTemp[25] == -2 || g_squareTemp[2] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 2 || count == 3 || count == 4 || count == 5)
                {
                    if (g_squareTemp[count + 10] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count + 6] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 6)
                {
                    if (g_squareTemp[21] == -2 || g_squareTemp[12] == -2 || g_squareTemp[19])
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 15)
                {
                    if (g_squareTemp[30] == -2 || g_squareTemp[21] == -2 || g_squareTemp[5] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 9)
                {
                    if (g_squareTemp[19] == -2 || g_squareTemp[26] == -2 || g_squareTemp[24] == -2 || g_squareTemp[3] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 10 || count == 11 || count == 12 || count == 13)
                {
                    if (g_squareTemp[count - 10] == -2 || g_squareTemp[count - 6] == -2 || g_squareTemp[count + 10] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count + 6] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 14)
                {
                    if (g_squareTemp[count - 10] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count + 6] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 16 || count == 24 || count == 32 || count == 40)
                {
                    if (g_squareTemp[count - 15] == -2 || g_squareTemp[count - 6] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 10] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 17 || count == 25 || count == 33 || count == 41)
                {
                    if (g_squareTemp[count - 17] == -2 || g_squareTemp[count - 6] == -2 || g_squareTemp[count + 10] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count - 15] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 18 || count == 19 || count == 20 || count == 21 || count == 26 || count == 27 || count == 28 || count == 29 || count == 34 || count == 35 || count == 36 || count == 37 || count == 42 || count == 43 || count == 44 || count == 45)
                {
                    if (g_squareTemp[count - 17] == -2 || g_squareTemp[count - 15] || g_squareTemp[count - 6] == -2 || g_squareTemp[count + 10] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count - 10] == -2 || g_squareTemp[count + 6] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 22 || count == 30 || count == 38 || count == 46)
                {
                    if (g_squareTemp[count - 17] == -2 || g_squareTemp[count - 10] == -2 || g_squareTemp[count + 6] == -2 || g_squareTemp[count + 17] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count - 15] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 23 || count == 31 || count == 39 || count == 47)
                {
                    if (g_squareTemp[count - 17] == -2 || g_squareTemp[count + 6] == -2 || g_squareTemp[count + 15] == -2 || g_squareTemp[count - 10] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 48)
                {
                    if (g_squareTemp[33] == -2 || g_squareTemp[42] == -2 || g_squareTemp[58] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 57)
                {
                    if (g_squareTemp[42] == -2 || g_squareTemp[51] == -2 || g_squareTemp[40] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 49)
                {
                    if (g_squareTemp[32] == -2 || g_squareTemp[34] == -2 || g_squareTemp[43] == -2 || g_squareTemp[59] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 50 || count == 51 || count == 52 || count == 53)
                {
                    if (g_squareTemp[count + 10] == -2 || g_squareTemp[count + 6] == -2 || g_squareTemp[count - 10] == -2 || g_squareTemp[count - 17] == -2 || g_squareTemp[count - 15] == -2 || g_squareTemp[count - 6] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 58 || count == 59 || count == 60 || count == 61)
                {
                    if (g_squareTemp[count - 10] == -2 || g_squareTemp[count - 17] == -2 || g_squareTemp[count - 15] == -2 || g_squareTemp[count - 6] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 54)
                {
                    if (g_squareTemp[60] == -2 || g_squareTemp[44] == -2 || g_squareTemp[37] == -2 || g_squareTemp[39] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 55)
                {
                    if (g_squareTemp[61] == -2 || g_squareTemp[45] == -2 || g_squareTemp[38] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 62)
                {
                    if (g_squareTemp[52] == -2 || g_squareTemp[45] == -2 || g_squareTemp[47] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 7)
                {
                    if (g_squareTemp[13] == -2 || g_squareTemp[22] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 56)
                {
                    if (g_squareTemp[41] == -2 || g_squareTemp[50] == -2)
                    {
                        isLegalMove = false;
                    }
                }
                if (count == 63)
                {
                    if (g_squareTemp[46] == -2 || g_squareTemp[53] == -2)
                    {
                        isLegalMove = false;
                    }
                }
            }
            ++count;
        }
    return isLegalMove;
}
//getmove
bool getMove()
{
    std::cout << g_fiftyMoveRule << '\t';
    bool loss{ 0 };
    float posEval[540];
    int square[64], count{ 0 }, move1[540], move2[540], count2{ 0 };
    while (count < 64)
    {
        g_masterBoard[count] = g_masterBoard[count] * -1;
        ++count;
    }
    count = 0;
    while (count < 64)
    {
        square[count] = g_masterBoard[count];
        g_squareTemp[count] = g_masterBoard[count];
        ++count;
    }
    count = 0;
    while (count < 64)
    {
        //pawn moves
        if (square[count] == 1)
        {
            if (square[count - 8] == 0)
            {
                g_squareTemp[count - 8] = 1;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    if (count - 8 < 8)
                    {
                        g_squareTemp[count - 8] = 2;
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                        g_squareTemp[count - 8] = 3;
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = g_squareTemp[count];
                        move2[count2] = g_squareTemp[count - 8];
                        ++count2;
                        g_squareTemp[count - 8] = 4;
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                        g_squareTemp[count - 8] = 5;
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                    }
                    else
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                    }
                }
                g_squareTemp[count] = 1;
                g_squareTemp[count - 8] = 0;
            }
            if (square[count - 7] < 0)
            {
                if (count % 8 != 7)
                {
                    g_squareTemp[count - 7] = 1;
                    g_squareTemp[count] = 0;
                    if (isKingAttacked() == true)
                    {
                        if (count - 7 < 8)
                        {
                            g_squareTemp[count - 7] = 2;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 7;
                            ++count2;
                            g_squareTemp[count - 7] = 3;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 7;
                            ++count2;
                            g_squareTemp[count - 7] = 4;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 7;
                            ++count2;
                            g_squareTemp[count - 7] = 5;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 7;
                            ++count2;
                        }
                        else
                        {
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 7;
                            ++count2;
                        }
                    }
                    g_squareTemp[count] = 1;
                    g_squareTemp[count - 7] = square[count - 7];
                }
            }
            if (square[count - 9] < 0)
            {
                if (count % 8 != 0)
                {
                    g_squareTemp[count - 9] = 1;
                    g_squareTemp[count] = 0;
                    if (isKingAttacked() == true)
                    {
                        if (count - 9 < 8)
                        {
                            g_squareTemp[count - 9] = 2;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 9;
                            ++count2;
                            g_squareTemp[count - 9] = 3;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 9;
                            ++count2;
                            g_squareTemp[count - 9] = 4;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 9;
                            ++count2;
                            g_squareTemp[count - 9] = 5;
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 9;
                            ++count2;
                        }
                        else
                        {
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = count;
                            move2[count2] = count - 9;
                            ++count2;
                        }
                    }
                    g_squareTemp[count] = 1;
                    g_squareTemp[count - 9] = square[count - 9];
                }
            }
            if (g_prevMove1 == count - 17 && g_prevMove2 == count - 1 && square[count - 1] == 1)
            {
                g_squareTemp[count - 9] = 1;
                g_squareTemp[count] = 0;
                g_squareTemp[count - 1] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 7;
                    ++count2;
                }
                g_squareTemp[count] = 1;
                g_squareTemp[count - 9] = 0;
                g_squareTemp[count - 1] = 1;
            }
            if (g_prevMove1 == count - 15 && g_prevMove2 == count + 1 && square[count + 1] == 1)
            {
                g_squareTemp[count - 7] = 1;
                g_squareTemp[count] = 0;
                g_squareTemp[count + 1] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 7;
                    ++count2;
                }
                g_squareTemp[count] = 1;
                g_squareTemp[count - 7] = 0;
                g_squareTemp[count + 1] = 1;
            }
        }
        //king moves
        if (square[count] == 6)
        {
            if (count % 8 != 0 && count % 8 != 7 && count > 7 && count < 55)
            {
                g_squareTemp[count] = 0;
                if (square[count + 7] < 1)
                {
                    g_squareTemp[count - 7] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 7;
                        ++count2;
                    }
                    g_squareTemp[count - 7] = square[count - 7];
                }
                if (square[count - 8] < 1)
                {
                    g_squareTemp[count - 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                    }
                    g_squareTemp[count - 8] = square[count - 8];
                }
                if (square[count - 9] < 1)
                {
                    g_squareTemp[count - 9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 9;
                        ++count2;
                    }
                    g_squareTemp[count - 9] = square[count - 9];
                }
                if (square[count - 1] < 1)
                {
                    g_squareTemp[count - 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 1;
                        ++count2;
                    }
                    g_squareTemp[count - 1] = square[count - 1];
                }
                if (square[count + 1] < 1)
                {
                    g_squareTemp[count + 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 1;
                        ++count2;
                    }
                    g_squareTemp[count + 1] = square[count + 1];
                }
                if (square[count + 7] < 1)
                {
                    g_squareTemp[count + 7] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 7;
                        ++count2;
                    }
                    g_squareTemp[count + 7] = square[count + 7];
                }
                if (square[count + 8] < 1)
                {
                    g_squareTemp[count + 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 8;
                        ++count2;
                    }
                    g_squareTemp[count + 8] = square[count + 8];
                }
                if (square[count + 9] < 1)
                {
                    g_squareTemp[count + 9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 9;
                        ++count2;
                    }
                    g_squareTemp[count + 9] = square[count + 9];
                }
                g_squareTemp[count] = 6;
            }
            if (count < 7 && count > 0)
            {
                g_squareTemp[count] = 0;
                if (square[count - 1] < 1)
                {
                    g_squareTemp[count - 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 1;
                        ++count2;
                    }
                    g_squareTemp[count - 1] = square[count - 1];
                }
                if (square[count + 1] < 1)
                {
                    g_squareTemp[count + 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 1;
                        ++count2;
                    }
                    g_squareTemp[count + 1] = square[count + 1];
                }
                if (square[count + 7] < 1)
                {
                    g_squareTemp[count + 7] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 7;
                        ++count2;
                    }
                    g_squareTemp[count + 7] = square[count + 7];
                }
                if (square[count + 8] < 1)
                {
                    g_squareTemp[count + 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 8;
                        ++count2;
                    }
                    g_squareTemp[count + 8] = square[count + 8];
                }
                if (square[count + 9] < 1)
                {
                    g_squareTemp[count + 9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 9;
                        ++count2;
                    }
                    g_squareTemp[count + 9] = square[count + 9];
                }
                g_squareTemp[count] = 6;
            }
            if (count == 0)
            {
                g_squareTemp[0] = 0;
                if (square[1] < 1)
                {
                    g_squareTemp[1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 0;
                        move2[count2] = 1;
                        ++count2;
                    }
                    g_squareTemp[1] = square[1];
                }
                if (square[8] < 1)
                {
                    g_squareTemp[8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 0;
                        move2[count2] = 8;
                        ++count2;
                    }
                    g_squareTemp[8] = square[8];
                }
                if (square[9] < 1)
                {
                    g_squareTemp[9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 0;
                        move2[count2] = 9;
                        ++count2;
                    }
                    g_squareTemp[9] = square[9];
                }
                g_squareTemp[0] = 6;
            }
            if (count == 7)
            {
                g_squareTemp[7] = 0;
                if (square[6] < 1)
                {
                    g_squareTemp[6] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 7;
                        move2[count2] = 6;
                        ++count2;
                    }
                    g_squareTemp[6] = square[6];
                }
                if (square[15] < 1)
                {
                    g_squareTemp[15] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 7;
                        move2[count2] = 15;
                        ++count2;
                    }
                    g_squareTemp[15] = square[15];
                }
                if (square[14] < 1)
                {
                    g_squareTemp[14] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 7;
                        move2[count2] = 14;
                        ++count2;
                    }
                    g_squareTemp[14] = square[14];
                }
                g_squareTemp[count] = 6;
            }
            if (count == 56)
            {
                g_squareTemp[56] = 0;
                if (square[57] < 1)
                {
                    g_squareTemp[57] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 56;
                        move2[count2] = 57;
                        ++count2;
                    }
                    g_squareTemp[57] = square[57];
                }
                if (square[48] < 1)
                {
                    g_squareTemp[56] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 56;
                        move2[count2] = 48;
                        ++count2;
                    }
                    g_squareTemp[48] = square[48];
                }
                if (square[49] < 1)
                {
                    g_squareTemp[49] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 56;
                        move2[count2] = 49;
                        ++count2;
                    }
                    g_squareTemp[49] = square[49];
                }
                g_squareTemp[count] = 6;
            }
            if (count == 63)
            {
                g_squareTemp[63] = 0;
                if (square[62] < 1)
                {
                    g_squareTemp[62] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 63;
                        move2[count2] = 62;
                        ++count2;
                    }
                    g_squareTemp[62] = square[62];
                }
                if (square[55] < 1)
                {
                    g_squareTemp[55] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 63;
                        move2[count2] = 55;
                        ++count2;
                    }
                    g_squareTemp[55] = square[55];
                }
                if (square[54] < 1)
                {
                    g_squareTemp[54] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 63;
                        move2[count2] = 54;
                        ++count2;
                    }
                    g_squareTemp[54] = square[54];
                }
                g_squareTemp[63] = 6;
            }
            if (count < 63 && count > 56)
            {
                g_squareTemp[count] = 0;
                if (square[count - 1] < 1)
                {
                    g_squareTemp[count - 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 1;
                        ++count2;
                    }
                    g_squareTemp[count - 1] = square[count - 1];
                }
                if (square[count + 1] < 1)
                {
                    g_squareTemp[count + 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 1;
                        ++count2;
                    }
                    g_squareTemp[count + 1] = square[count + 1];
                }
                if (square[count - 7] < 1)
                {
                    g_squareTemp[count - 7] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 7;
                        ++count2;
                    }
                    g_squareTemp[count - 7] = square[count - 7];
                }
                if (square[count - 8] < 1)
                {
                    g_squareTemp[count - 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                    }
                    g_squareTemp[count - 8] = square[count - 8];
                }
                if (square[count - 9] < 1)
                {
                    g_squareTemp[count - 9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 9;
                        ++count2;
                    }
                    g_squareTemp[count - 9] = 0;
                }
                g_squareTemp[count] = 6;
            }
            if (count % 8 == 0 && count != 0 && count != 56)
            {
                g_squareTemp[count] = 0;
                if (square[count - 7] < 1)
                {
                    g_squareTemp[count - 7] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 7;
                        ++count2;
                    }
                    g_squareTemp[count - 7] = square[count - 7];
                }
                if (square[count + 1] < 1)
                {
                    g_squareTemp[count + 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 1;
                        ++count2;
                    }
                    g_squareTemp[count + 1] = square[count + 1];
                }
                if (square[count + 8] < 1)
                {
                    g_squareTemp[count + 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 8;
                        ++count2;
                    }
                    g_squareTemp[count + 8] = square[count + 8];
                }
                if (square[count + 9] < 1)
                {
                    g_squareTemp[count + 9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 9;
                        ++count2;
                    }
                    g_squareTemp[count + 9] = square[count + 9];
                }
                if (square[count - 8] < 1)
                {
                    g_squareTemp[count - 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                    }
                    g_squareTemp[count - 8] = square[count - 8];
                }
                g_squareTemp[count] = 6;
            }
            if (count % 8 == 7 && count != 7 && count != 63)
            {
                g_squareTemp[count] = 0;
                if (square[count - 8] < 1)
                {
                    g_squareTemp[count - 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 8;
                        ++count2;
                    }
                    g_squareTemp[count - 8] = square[count - 8];
                }
                if (square[count - 9] < 1)
                {
                    g_squareTemp[count - 9] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 9;
                        ++count2;
                    }
                    g_squareTemp[count - 9] = square[count - 9];
                }
                if (square[count - 1] < 1)
                {
                    g_squareTemp[count - 1] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 1;
                        ++count2;
                    }
                    g_squareTemp[count - 1] = square[count - 1];
                }
                if (square[count + 7] < 1)
                {
                    g_squareTemp[count + 7] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 7;
                        ++count2;
                    }
                    g_squareTemp[count + 7] = square[count + 7];
                }
                if (square[count + 8] < 1)
                {
                    g_squareTemp[count + 8] = 6;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 8;
                        ++count2;
                    }
                    g_squareTemp[count + 8] = square[count + 8];
                }
                g_squareTemp[count] = 6;
            }
            if (count == 60 && square[61] == 0 && square[62] == 0 && square[63] == 4)
            {
                if (g_toMove == 0 && g_castleKing == true)
                {
                    g_squareTemp[61] = 6;
                    if (isKingAttacked() == true)
                    {
                        g_squareTemp[62] = 6;
                        g_squareTemp[61] = 4;
                        g_squareTemp[60] = 0;
                        g_squareTemp[63] = 0;
                        if (isKingAttacked() == true)
                        {
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = 60;
                            move2[count2] = 62;
                            ++count2;
                        }
                        g_squareTemp[62] = 0;
                        g_squareTemp[60] = 6;
                        g_squareTemp[63] = 4;
                    }
                    g_squareTemp[61] = 0;
                }
                if (g_toMove == 1 && g_opponentCastleKing == true)
                {
                    g_squareTemp[61] = 6;
                    if (isKingAttacked() == true)
                    {
                        g_squareTemp[62] = 6;
                        g_squareTemp[61] = 4;
                        g_squareTemp[60] = 0;
                        g_squareTemp[63] = 0;
                        if (isKingAttacked() == true)
                        {
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = 60;
                            move2[count2] = 62;
                            ++count2;
                        }
                        g_squareTemp[62] = 0;
                        g_squareTemp[60] = 6;
                        g_squareTemp[63] = 4;
                    }
                    g_squareTemp[61] = 0;
                }
            }
            if (count == 60 && square[59] == 0 && square[58] == 0 && square[57] == 0 && square[56] == 4)
            {
                if (g_toMove == 0 && g_castleQueen == true)
                {
                    g_squareTemp[59] = 6;
                    if (isKingAttacked() == true)
                    {
                        g_squareTemp[58] = 6;
                        g_squareTemp[59] = 4;
                        g_squareTemp[60] = 0;
                        g_squareTemp[56] = 0;
                        if (isKingAttacked() == true)
                        {
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = 60;
                            move2[count2] = 58;
                            ++count2;
                        }
                        g_squareTemp[58] = 0;
                        g_squareTemp[60] = 6;
                        g_squareTemp[56] = 4;
                    }
                    g_squareTemp[59] = 0;
                }
                if (g_toMove == 1 && g_opponentCastleQueen == true)
                {
                    g_squareTemp[59] = 6;
                    if (isKingAttacked() == true)
                    {
                        g_squareTemp[58] = 6;
                        g_squareTemp[59] = 4;
                        g_squareTemp[60] = 0;
                        g_squareTemp[56] = 0;
                        if (isKingAttacked() == true)
                        {
                            posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                            move1[count2] = 60;
                            move2[count2] = 58;
                            ++count2;
                        }
                        g_squareTemp[58] = 0;
                        g_squareTemp[60] = 6;
                        g_squareTemp[56] = 4;
                    }
                    g_squareTemp[59] = 0;
                }
            }
        }
        //knight moves
        if (square[count] == 2)
        {
            if (count == 0)
            {
                g_squareTemp[0] = 0;
                if (square[10] < 1)
                {
                    g_squareTemp[10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 0;
                        move2[count2] = 10;
                        ++count2;
                    }
                    g_squareTemp[10] = square[10];
                }
                if (square[17] < 1)
                {
                    g_squareTemp[17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 0;
                        move2[count2] = 17;
                        ++count2;
                    }
                    g_squareTemp[17] = square[17];
                }
                g_squareTemp[0] = 2;
            }
            if (count == 1)
            {
                g_squareTemp[1] = 0;
                if (square[11] < 1)
                {
                    g_squareTemp[11] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 1;
                        move2[count2] = 11;
                        ++count2;
                    }
                    g_squareTemp[11] = square[11];
                }
                if (square[18] < 1)
                {
                    g_squareTemp[18] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 1;
                        move2[count2] = 18;
                        ++count2;
                    }
                    g_squareTemp[18] = square[18];
                }
                if (square[16] < 1)
                {
                    g_squareTemp[16] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 1;
                        move2[count2] = 16;
                        ++count2;
                    }
                    g_squareTemp[16] = square[16];
                }
                g_squareTemp[1] = 2;
            }
            if (count == 8)
            {
                g_squareTemp[8] = 0;
                if (square[2] < 1)
                {
                    g_squareTemp[2] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 8;
                        move2[count2] = 2;
                        ++count2;
                    }
                    g_squareTemp[2] = square[2];
                }
                if (square[18] < 1)
                {
                    g_squareTemp[18] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 8;
                        move2[count2] = 18;
                        ++count2;
                    }
                    g_squareTemp[18] = square[18];
                }
                if (square[25] < 1)
                {
                    g_squareTemp[25] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 8;
                        move2[count2] = 25;
                        ++count2;
                    }
                    g_squareTemp[25] = square[25];
                }
                g_squareTemp[8] = 2;
            }
            if (count == 2 || count == 3 || count == 4 || count == 5)
            {
                g_squareTemp[count] = 0;
                if (square[count + 10] < 1)
                {
                    g_squareTemp[count + 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 10;
                        ++count2;
                    }
                    g_squareTemp[count + 10] = square[count + 10];
                }
                if (square[count + 17] < 1)
                {
                    g_squareTemp[count + 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 17;
                        ++count2;
                    }
                    g_squareTemp[count + 17] = square[count + 17];
                }
                if (square[count + 15] < 1)
                {
                    g_squareTemp[count + 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 15;
                        ++count2;
                    }
                    g_squareTemp[count + 15] = square[count + 15];
                }
                if (square[count + 6] < 1)
                {
                    g_squareTemp[count + 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 6;
                        ++count2;
                    }
                    g_squareTemp[count + 6] = square[count + 6];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 6)
            {
                g_squareTemp[6] = 0;
                if (square[12] < 1)
                {
                    g_squareTemp[12] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 6;
                        move2[count2] = 12;
                        ++count2;
                    }
                    g_squareTemp[12] = square[12];
                }
                if (square[21] < 1)
                {
                    g_squareTemp[21] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 6;
                        move2[count2] = 21;
                        ++count2;
                    }
                    g_squareTemp[21] = square[21];
                }
                if (square[23] < 1)
                {
                    g_squareTemp[23] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 6;
                        move2[count2] = 23;
                        ++count2;
                    }
                    g_squareTemp[23] = square[23];
                }
                g_squareTemp[6] = 2;
            }
            if (count == 7)
            {
                g_squareTemp[7] = 0;
                if (square[13] < 1)
                {
                    g_squareTemp[13] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 7;
                        move2[count2] = 13;
                        ++count2;
                    }
                    g_squareTemp[13] = square[13];
                }
                if (square[22] < 1)
                {
                    g_squareTemp[22] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 7;
                        move2[count2] = 22;
                        ++count2;
                    }
                    g_squareTemp[22] = square[22];
                }
                g_squareTemp[7] = 2;
            }
            if (count == 9)
            {
                g_squareTemp[9] = 0;
                if (square[3] < 1)
                {
                    g_squareTemp[3] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 9;
                        move2[count2] = 3;
                        ++count2;
                    }
                    g_squareTemp[3] = square[3];
                }
                if (square[19] < 1)
                {
                    g_squareTemp[19] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 9;
                        move2[count2] = 19;
                        ++count2;
                    }
                    g_squareTemp[19] = square[19];
                }
                if (square[24] < 1)
                {
                    g_squareTemp[24] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 9;
                        move2[count2] = 24;
                        ++count2;
                    }
                    g_squareTemp[24] = square[24];
                }
                if (square[26] < 1)
                {
                    g_squareTemp[26] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 9;
                        move2[count2] = 26;
                        ++count2;
                    }
                    g_squareTemp[26] = square[26];
                }
                g_squareTemp[9] = 2;
            }
            if (count == 10 || count == 11 || count == 12 || count == 13)
            {
                g_squareTemp[count] = 0;
                if (square[count + 10] < 1)
                {
                    g_squareTemp[count + 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 10;
                        ++count2;
                    }
                    g_squareTemp[count + 10] = square[count + 10];
                }
                if (square[count + 17] < 1)
                {
                    g_squareTemp[count + 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 17;
                        ++count2;
                    }
                    g_squareTemp[count + 17] = square[count + 17];
                }
                if (square[count + 15] < 1)
                {
                    g_squareTemp[count + 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 15;
                        ++count2;
                    }
                    g_squareTemp[count + 15] = square[count + 15];
                }
                if (square[count + 6] < 1)
                {
                    g_squareTemp[count + 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 6;
                        ++count2;
                    }
                    g_squareTemp[count + 6] = square[count + 6];
                }
                if (square[count - 10] < 1)
                {
                    g_squareTemp[count - 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 10;
                        ++count2;
                    }
                    g_squareTemp[count - 10] = square[count - 10];
                }
                if (square[count - 6] < 1)
                {
                    g_squareTemp[count - 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 6;
                        ++count2;
                    }
                    g_squareTemp[count - 6] = square[count - 6];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 14)
            {
                g_squareTemp[14] = 0;
                if (square[count - 1] < 1)
                {
                    g_squareTemp[4] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 14;
                        move2[count2] = 4;
                        ++count2;
                    }
                    g_squareTemp[4] = square[4];
                }
                if (square[20] < 1)
                {
                    g_squareTemp[20] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 14;
                        move2[count2] = 20;
                        ++count2;
                    }
                    g_squareTemp[20] = square[20];
                }
                if (square[31] < 1)
                {
                    g_squareTemp[31] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 14;
                        move2[count2] = 31;
                        ++count2;
                    }
                    g_squareTemp[31] = square[31];
                }
                if (square[29] < 1)
                {
                    g_squareTemp[29] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 14;
                        move2[count2] = 29;
                        ++count2;
                    }
                    g_squareTemp[29] = square[29];
                }
                g_squareTemp[14] = 2;
            }
            if (count == 15)
            {
                g_squareTemp[15] = 0;
                if (square[5] < 1)
                {
                    g_squareTemp[5] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 15;
                        move2[count2] = 5;
                        ++count2;
                    }
                    g_squareTemp[5] = square[5];
                }
                if (square[21] < 1)
                {
                    g_squareTemp[21] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 15;
                        move2[count2] = 21;
                        ++count2;
                    }
                    g_squareTemp[21] = square[21];
                }
                if (square[30] < 1)
                {
                    g_squareTemp[30] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 15;
                        move2[count2] = 30;
                        ++count2;
                    }
                    g_squareTemp[30] = square[30];
                }
                g_squareTemp[15] = 2;
            }
            if (count == 16 || count == 24 || count == 32 || count == 40)
            {
                g_squareTemp[count] = 0;
                if (square[count - 15] < 1)
                {
                    g_squareTemp[count - 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 15;
                        ++count2;
                    }
                    g_squareTemp[count - 15] = square[count - 15];
                }
                if (square[count - 6] < 1)
                {
                    g_squareTemp[count - 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 6;
                        ++count2;
                    }
                    g_squareTemp[count - 6] = square[count - 6];
                }
                if (square[count + 10] < 1)
                {
                    g_squareTemp[count + 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 10;
                        ++count2;
                    }
                    g_squareTemp[count + 10] = square[count + 10];
                }
                if (square[count + 17] < 1)
                {
                    g_squareTemp[count + 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 17;
                        ++count2;
                    }
                    g_squareTemp[count + 17] = square[count + 17];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 17 || count == 25 || count == 33 || count == 41)
            {
                g_squareTemp[count] = 0;
                if (square[count - 15] < 1)
                {
                    g_squareTemp[count - 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 15;
                        ++count2;
                    }
                    g_squareTemp[count - 15] = square[count - 15];
                }
                if (square[count - 6] < 1)
                {
                    g_squareTemp[count - 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 6;
                        ++count2;
                    }
                    g_squareTemp[count - 6] = square[count - 6];
                }
                if (square[count + 10] < 1)
                {
                    g_squareTemp[count + 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 10;
                        ++count2;
                    }
                    g_squareTemp[count + 10] = square[count + 10];
                }
                if (square[count + 17] < 1)
                {
                    g_squareTemp[count + 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 17;
                        ++count2;
                    }
                    g_squareTemp[count + 17] = square[count + 17];
                }
                if (square[count - 17] < 1)
                {
                    g_squareTemp[count - 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 17;
                        ++count2;
                    }
                    g_squareTemp[count - 17] = square[count - 17];
                }
                if (square[count + 15] < 1)
                {
                    g_squareTemp[count + 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 15;
                        ++count2;
                    }
                    g_squareTemp[count + 15] = square[count + 15];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 18 || count == 19 || count == 20 || count == 21 || count == 26 || count == 27 || count == 28 || count == 29 || count == 34 || count == 35 || count == 36 || count == 37 || count == 42 || count == 43 || count == 44 || count == 45)
            {
                g_squareTemp[count] = 0;
                if (square[count - 15] < 1)
                {
                    g_squareTemp[count - 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 15;
                        ++count2;
                    }
                    g_squareTemp[count - 15] = square[count - 15];
                }
                if (square[count - 6] < 1)
                {
                    g_squareTemp[count - 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 6;
                        ++count2;
                    }
                    g_squareTemp[count - 6] = square[count - 6];
                }
                if (square[count + 10] < 1)
                {
                    g_squareTemp[count + 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 10;
                        ++count2;
                    }
                    g_squareTemp[count + 10] = square[count + 10];
                }
                if (square[count + 17] < 1)
                {
                    g_squareTemp[count + 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 17;
                        ++count2;
                    }
                    g_squareTemp[count + 17] = square[count + 17];
                }
                if (square[count - 17] < 1)
                {
                    g_squareTemp[count - 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 17;
                        ++count2;
                    }
                    g_squareTemp[count - 17] = square[count - 17];
                }
                if (square[count + 15] < 1)
                {
                    g_squareTemp[count + 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 15;
                        ++count2;
                    }
                    g_squareTemp[count + 15] = square[count + 15];
                }
                if (square[count + 6] < 1)
                {
                    g_squareTemp[count + 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 6;
                        ++count2;
                    }
                    g_squareTemp[count + 6] = square[count + 6];
                }
                if (square[count - 10] < 1)
                {
                    g_squareTemp[count - 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 10;
                        ++count2;
                    }
                    g_squareTemp[count - 10] = square[count - 10];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 22 || count == 30 || count == 38 || count == 46)
            {
                g_squareTemp[count] = 0;
                if (square[count - 15] < 1)
                {
                    g_squareTemp[count - 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 15;
                        ++count2;
                    }
                    g_squareTemp[count - 15] = square[count - 15];
                }
                if (square[count + 17] < 1)
                {
                    g_squareTemp[count + 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 17;
                        ++count2;
                    }
                    g_squareTemp[count + 17] = square[count + 17];
                }
                if (square[count - 17] < 1)
                {
                    g_squareTemp[count - 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 17;
                        ++count2;
                    }
                    g_squareTemp[count - 17] = square[count - 17];
                }
                if (square[count + 15] < 1)
                {
                    g_squareTemp[count + 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 15;
                        ++count2;
                    }
                    g_squareTemp[count + 15] = square[count + 15];
                }
                if (square[count + 6] < 1)
                {
                    g_squareTemp[count + 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 6;
                        ++count2;
                    }
                    g_squareTemp[count + 6] = square[count + 6];
                }
                if (square[count - 10] < 1)
                {
                    g_squareTemp[count - 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 10;
                        ++count2;
                    }
                    g_squareTemp[count - 10] = square[count - 10];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 23 || count == 31 || count == 39 || count == 47)
            {
                g_squareTemp[count] = 0;
                if (square[count - 17] < 1)
                {
                    g_squareTemp[count - 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 17;
                        ++count2;
                    }
                    g_squareTemp[count - 17] = square[count - 17];
                }
                if (square[count + 15] < 1)
                {
                    g_squareTemp[count + 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 15;
                        ++count2;
                    }
                    g_squareTemp[count + 15] = square[count + 15];
                }
                if (square[count + 6] < 1)
                {
                    g_squareTemp[count + 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 6;
                        ++count2;
                    }
                    g_squareTemp[count + 6] = square[count + 6];
                }
                if (square[count - 10] < 1)
                {
                    g_squareTemp[count - 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 10;
                        ++count2;
                    }
                    g_squareTemp[count - 10] = square[count - 10];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 48)
            {
                g_squareTemp[48] = 0;
                if (square[58] < 1)
                {
                    g_squareTemp[58] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 48;
                        move2[count2] = 58;
                        ++count2;
                    }
                    g_squareTemp[58] = square[58];
                }
                if (square[42] < 1)
                {
                    g_squareTemp[42] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 48;
                        move2[count2] = 42;
                        ++count2;
                    }
                    g_squareTemp[42] = square[42];
                }
                if (square[33] < 1)
                {
                    g_squareTemp[33] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 48;
                        move2[count2] = 33;
                        ++count2;
                    }
                    g_squareTemp[33] = square[33];
                }
                g_squareTemp[48] = 2;
            }
            if (count == 49)
            {
                g_squareTemp[49] = 0;
                if (square[59] < 1)
                {
                    g_squareTemp[59] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 49;
                        move2[count2] = 59;
                        ++count2;
                    }
                    g_squareTemp[59] = square[59];
                }
                if (square[43] < 1)
                {
                    g_squareTemp[43] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 49;
                        move2[count2] = 43;
                        ++count2;
                    }
                    g_squareTemp[43] = square[43];
                }
                if (square[34] < 1)
                {
                    g_squareTemp[34] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 49;
                        move2[count2] = 34;
                        ++count2;
                    }
                    g_squareTemp[34] = square[34];
                }
                if (square[32] < 1)
                {
                    g_squareTemp[32] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 49;
                        move2[count2] = 32;
                        ++count2;
                    }
                    g_squareTemp[32] = square[32];
                }
                g_squareTemp[49] = 2;
            }
            if (count == 50 || count == 51 || count == 52 || count == 53)
            {
                g_squareTemp[count] = 0;
                if (square[count + 10] < 1)
                {
                    g_squareTemp[count + 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 10;
                        ++count2;
                    }
                    g_squareTemp[count + 10] = square[count + 10];
                }
                if (square[count - 17] < 1)
                {
                    g_squareTemp[count - 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 17;
                        ++count2;
                    }
                    g_squareTemp[count - 17] = square[count - 17];
                }
                if (square[count - 15] < 1)
                {
                    g_squareTemp[count - 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 15;
                        ++count2;
                    }
                    g_squareTemp[count - 15] = square[count - 15];
                }
                if (square[count + 6] < 1)
                {
                    g_squareTemp[count + 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count + 6;
                        ++count2;
                    }
                    g_squareTemp[count + 6] = square[count + 6];
                }
                if (square[count - 10] < 1)
                {
                    g_squareTemp[count - 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 10;
                        ++count2;
                    }
                    g_squareTemp[count - 10] = square[count - 10];
                }
                if (square[count - 6] < 1)
                {
                    g_squareTemp[count - 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 6;
                        ++count2;
                    }
                    g_squareTemp[count - 6] = square[count - 6];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 54)
            {
                g_squareTemp[54] = 0;
                if (square[60] < 1)
                {
                    g_squareTemp[60] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 54;
                        move2[count2] = 60;
                        ++count2;
                    }
                    g_squareTemp[60] = square[60];
                }
                if (square[44] < 1)
                {
                    g_squareTemp[44] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 54;
                        move2[count2] = 44;
                        ++count2;
                    }
                    g_squareTemp[44] = square[44];
                }
                if (square[37] < 1)
                {
                    g_squareTemp[37] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 54;
                        move2[count2] = 37;
                        ++count2;
                    }
                    g_squareTemp[37] = square[37];
                }
                if (square[39] < 1)
                {
                    g_squareTemp[39] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 54;
                        move2[count2] = 39;
                        ++count2;
                    }
                    g_squareTemp[39] = square[39];
                }
                g_squareTemp[54] = 2;
            }
            if (count == 55)
            {
                g_squareTemp[55] = 0;
                if (square[61] < 1)
                {
                    g_squareTemp[61] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 55;
                        move2[count2] = 61;
                        ++count2;
                    }
                    g_squareTemp[61] = square[61];
                }
                if (square[45] < 1)
                {
                    g_squareTemp[45] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 55;
                        move2[count2] = 45;
                        ++count2;
                    }
                    g_squareTemp[45] = square[45];
                }
                if (square[38] < 1)
                {
                    g_squareTemp[38] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 55;
                        move2[count2] = 38;
                        ++count2;
                    }
                    g_squareTemp[38] = square[38];
                }
                g_squareTemp[55] = 2;
            }
            if (count == 56)
            {
                g_squareTemp[56] = 0;
                if (square[41] < 1)
                {
                    g_squareTemp[41] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 56;
                        move2[count2] = 41;
                        ++count2;
                    }
                    g_squareTemp[41] = square[41];
                }
                if (square[50] < 1)
                {
                    g_squareTemp[50] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 56;
                        move2[count2] = 50;
                        ++count2;
                    }
                    g_squareTemp[50] = square[50];
                }
                g_squareTemp[56] = 2;
            }
            if (count == 57)
            {
                g_squareTemp[57] = 0;
                if (square[40] < 1)
                {
                    g_squareTemp[40] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 57;
                        move2[count2] = 40;
                        ++count2;
                    }
                    g_squareTemp[40] = square[40];
                }
                if (square[42] < 1)
                {
                    g_squareTemp[42] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 57;
                        move2[count2] = 42;
                        ++count2;
                    }
                    g_squareTemp[42] = square[42];
                }
                if (square[51] < 1)
                {
                    g_squareTemp[51] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 57;
                        move2[count2] = 51;
                        ++count2;
                    }
                    g_squareTemp[51] = square[51];
                }
                g_squareTemp[57] = 2;
            }
            if (count == 58 || count == 59 || count == 60 || count == 61)
            {
                g_squareTemp[count] = 0;
                if (square[count - 10] < 1)
                {
                    g_squareTemp[count - 10] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 10;
                        ++count2;
                    }
                    g_squareTemp[count - 10] = square[count - 10];
                }
                if (square[count - 17] < 1)
                {
                    g_squareTemp[count - 17] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 17;
                        ++count2;
                    }
                    g_squareTemp[count - 17] = square[count - 17];
                }
                if (square[count - 15] < 1)
                {
                    g_squareTemp[count - 15] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 15;
                        ++count2;
                    }
                    g_squareTemp[count - 15] = square[count - 15];
                }
                if (square[count - 6] < 1)
                {
                    g_squareTemp[count - 6] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = count;
                        move2[count2] = count - 6;
                        ++count2;
                    }
                    g_squareTemp[count - 6] = square[count - 6];
                }
                g_squareTemp[count] = 2;
            }
            if (count == 62)
            {
                g_squareTemp[62] = 0;
                if (square[52] < 1)
                {
                    g_squareTemp[52] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 62;
                        move2[count2] = 52;
                        ++count2;
                    }
                    g_squareTemp[52] = square[52];
                }
                if (square[45] < 1)
                {
                    g_squareTemp[45] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 62;
                        move2[count2] = 45;
                        ++count2;
                    }
                    g_squareTemp[45] = square[45];
                }
                if (square[47] < 1)
                {
                    g_squareTemp[47] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 62;
                        move2[count2] = 47;
                        ++count2;
                    }
                    g_squareTemp[47] = square[47];
                }
                g_squareTemp[62] = 2;
            }
            if (count == 63)
            {
                g_squareTemp[63] = 0;
                if (square[53] < 1)
                {
                    g_squareTemp[53] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 63;
                        move2[count2] = 53;
                        ++count2;
                    }
                    g_squareTemp[53] = square[53];
                }
                if (square[46] < 1)
                {
                    g_squareTemp[46] = 2;
                    if (isKingAttacked() == true)
                    {
                        posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                        move1[count2] = 63;
                        move2[count2] = 46;
                        ++count2;
                    }
                    g_squareTemp[46] = square[46];
                }
                g_squareTemp[63] = 2;
            }
        }
        //bishop moves
        if (square[count] == 3)
        {
            if (count < 56 && count % 8 != 7 && square[count + 9] < 1)
            {
                g_squareTemp[count + 9] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 9;
                    ++count2;
                }
                g_squareTemp[count + 9] = square[count + 9];
                g_squareTemp[count] = 3;
            }
            if (count < 48 && count % 8 < 6 && square[count + 9] == 0 && square[count + 18] < 1)
            {
                g_squareTemp[count + 18] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 18;
                    ++count2;
                }
                g_squareTemp[count + 18] = square[count + 18];
                g_squareTemp[count] = 3;
            }
            if (count < 40 && count % 8 < 5 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] < 1)
            {
                g_squareTemp[count + 27] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 27;
                    ++count2;
                }
                g_squareTemp[count + 27] = square[count + 27];
                g_squareTemp[count] = 3;
            }
            if (count < 32 && count % 8 < 4 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] == 0 && square[count + 36] < 1)
            {
                g_squareTemp[count + 36] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 36;
                    ++count2;
                }
                g_squareTemp[count + 36] = square[count + 36];
                g_squareTemp[count] = 3;
            }
            if (count < 24 && count % 8 < 3 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] == 0 && square[count + 36] == 0 && square[count + 45] < 1)
            {
                g_squareTemp[count + 45] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 45;
                    ++count2;
                }
                g_squareTemp[count + 45] = square[count + 45];
                g_squareTemp[count] = 3;
            }
            if (count < 16 && count % 8 < 2 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] == 0 && square[count + 36] == 0 && square[count + 45] == 0 && square[count + 54] < 1)
            {
                g_squareTemp[count + 54] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 54;
                    ++count2;
                }
                g_squareTemp[count + 54] = square[count + 54];
                g_squareTemp[count] = 3;
            }
            if (count == 0 && square[9] == 0 && square[18] == 0 && square[27] == 0 && square[36] == 0 && square[45] == 0 && square[54] == 0 && square[63] < 1)
            {
                g_squareTemp[63] = 3;
                g_squareTemp[0] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 0;
                    move2[count2] = 63;
                    ++count2;
                }
                g_squareTemp[63] = square[63];
                g_squareTemp[0] = 3;
            }
            if (count < 56 && count % 8 != 0 && square[count + 7] < 1)
            {
                g_squareTemp[count + 7] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 7;
                    ++count2;
                }
                g_squareTemp[count + 7] = square[count + 7];
                g_squareTemp[count] = 3;
            }
            if (count < 48 && count % 8 > 1 && square[count + 7] == 0 && square[count + 14] < 1)
            {
                g_squareTemp[count + 14] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 14;
                    ++count2;
                }
                g_squareTemp[count + 14] = square[count + 14];
                g_squareTemp[count] = 3;
            }
            if (count < 40 && count % 8 > 2 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] < 1)
            {
                g_squareTemp[count + 21] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 21;
                    ++count2;
                }
                g_squareTemp[count + 21] = square[count + 21];
                g_squareTemp[count] = 3;
            }
            if (count < 32 && count % 8 > 3 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] == 0 && square[count + 28] < 1)
            {
                g_squareTemp[count + 28] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 28;
                    ++count2;
                }
                g_squareTemp[count + 28] = square[count + 28];
                g_squareTemp[count] = 3;
            }
            if (count < 24 && count % 8 > 4 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] == 0 && square[count + 28] == 0 && square[count + 35] < 1)
            {
                g_squareTemp[count + 35] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 35;
                    ++count2;
                }
                g_squareTemp[count + 35] = square[count + 35];
                g_squareTemp[count] = 3;
            }
            if (count < 16 && count % 8 > 5 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] == 0 && square[count + 28] == 0 && square[count + 35] == 0 && square[count + 42] < 1)
            {
                g_squareTemp[count + 42] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 42;
                    ++count2;
                }
                g_squareTemp[count + 42] = square[count + 42];
                g_squareTemp[count] = 3;
            }
            if (count == 7 && square[14] == 0 && square[21] == 0 && square[28] == 0 && square[35] == 0 && square[42] == 0 && square[49] == 0 && square[56] < 1)
            {
                g_squareTemp[56] = 3;
                g_squareTemp[7] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 7;
                    move2[count2] = 56;
                    ++count2;
                }
                g_squareTemp[56] = square[56];
                g_squareTemp[7] = 3;
            }
            if (count >= 8 && count % 8 != 7 && square[count - 7] < 1)
            {
                g_squareTemp[count - 7] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 7;
                    ++count2;
                }
                g_squareTemp[count - 7] = square[count - 7];
                g_squareTemp[count] = 3;
            }
            if (count >= 16 && count % 8 < 6 && square[count - 7] == 0 && square[count - 14] < 1)
            {
                g_squareTemp[count - 14] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 14;
                    ++count2;
                }
                g_squareTemp[count - 14] = square[count - 14];
                g_squareTemp[count] = 3;
            }
            if (count >= 24 && count % 8 < 5 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] < 1)
            {
                g_squareTemp[count - 21] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 21;
                    ++count2;
                }
                g_squareTemp[count - 21] = square[count - 21];
                g_squareTemp[count] = 3;
            }
            if (count >= 32 && count % 8 < 4 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] == 0 && square[count - 28] < 1)
            {
                g_squareTemp[count - 28] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 28;
                    ++count2;
                }
                g_squareTemp[count - 28] = square[count - 28];
                g_squareTemp[count] = 3;
            }
            if (count >= 40 && count % 8 < 3 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] == 0 && square[count - 28] == 0 && square[count - 35] < 1)
            {
                g_squareTemp[count - 35] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 35;
                    ++count2;
                }
                g_squareTemp[count - 35] = square[count - 35];
                g_squareTemp[count] = 3;
            }
            if (count >= 48 && count % 8 < 2 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] == 0 && square[count - 28] == 0 && square[count - 35] == 0 && square[count - 42] < 1)
            {
                g_squareTemp[count - 42] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 42;
                    ++count2;
                }
                g_squareTemp[count - 42] = square[count - 42];
                g_squareTemp[count] = 3;
            }
            if (count == 56 && square[14] == 0 && square[21] == 0 && square[28] == 0 && square[35] == 0 && square[42] == 0 && square[49] == 0 && square[7] < 1)
            {
                g_squareTemp[7] = 3;
                g_squareTemp[56] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 56;
                    move2[count2] = 7;
                    ++count2;
                }
                g_squareTemp[7] = square[7];
                g_squareTemp[56] = 3;
            }
            if (count > 8 && count % 8 != 0 && square[count - 9] < 1)
            {
                g_squareTemp[count - 9] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 9;
                    ++count2;
                }
                g_squareTemp[count - 9] = square[count - 9];
                g_squareTemp[count] = 3;
            }
            if (count > 16 && count % 8 > 1 && square[count - 9] == 0 && square[count - 18] < 1)
            {
                g_squareTemp[count - 18] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 18;
                    ++count2;
                }
                g_squareTemp[count - 18] = square[count - 18];
                g_squareTemp[count] = 3;
            }
            if (count > 24 && count % 8 > 2 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] < 1)
            {
                g_squareTemp[count - 27] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 27;
                    ++count2;
                }
                g_squareTemp[count - 27] = square[count - 27];
                g_squareTemp[count] = 3;
            }
            if (count > 32 && count % 8 > 3 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] == 0 && square[count - 36] < 1)
            {
                g_squareTemp[count - 36] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 36;
                    ++count2;
                }
                g_squareTemp[count - 36] = square[count - 36];
                g_squareTemp[count] = 3;
            }
            if (count > 40 && count % 8 > 4 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] == 0 && square[count - 36] == 0 && square[count - 45] < 1)
            {
                g_squareTemp[count - 45] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 45;
                    ++count2;
                }
                g_squareTemp[count - 45] = square[count - 45];
                g_squareTemp[count] = 3;
            }
            if (count > 48 && count % 8 > 5 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] == 0 && square[count - 36] == 0 && square[count - 45] == 0 && square[count - 54] < 1)
            {
                g_squareTemp[count - 54] = 3;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 54;
                    ++count2;
                }
                g_squareTemp[count - 54] = square[count - 54];
                g_squareTemp[count] = 3;
            }
            if (count == 63 && square[9] == 0 && square[18] == 0 && square[27] == 0 && square[36] == 0 && square[45] == 0 && square[54] == 0 && square[0] < 1)
            {
                g_squareTemp[0] = 3;
                g_squareTemp[63] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 63;
                    move2[count2] = 0;
                    ++count2;
                }
                g_squareTemp[0] = square[0];
                g_squareTemp[63] = 3;
            }
        }
        //rook moves
        if (square[count] == 4)
        {
            if (count < 56 && square[count + 8] < 1)
            {
                g_squareTemp[count + 8] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 8;
                    ++count2;
                }
                g_squareTemp[count + 8] = square[count + 8];
                g_squareTemp[count] = 4;
            }
            if (count < 48 && square[count + 8] == 0 && square[count + 16] < 1)
            {
                g_squareTemp[count + 16] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 16;
                    ++count2;
                }
                g_squareTemp[count + 16] = square[count + 16];
                g_squareTemp[count] = 4;
            }
            if (count < 40 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] < 1)
            {
                g_squareTemp[count + 24] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 24;
                    ++count2;
                }
                g_squareTemp[count + 24] = square[count + 24];
                g_squareTemp[count] = 4;
            }
            if (count < 32 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] < 1)
            {
                g_squareTemp[count + 32] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 32;
                    ++count2;
                }
                g_squareTemp[count + 32] = square[count + 32];
                g_squareTemp[count] = 4;
            }
            if (count < 24 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] == 0 && square[count + 40] < 1)
            {
                g_squareTemp[count + 40] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 40;
                    ++count2;
                }
                g_squareTemp[count + 40] = square[count + 40];
                g_squareTemp[count] = 4;
            }
            if (count < 16 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] == 0 && square[count + 40] == 0 && square[count + 48] < 1)
            {
                g_squareTemp[count + 48] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 48;
                    ++count2;
                }
                g_squareTemp[count + 48] = square[count + 48];
                g_squareTemp[count] = 4;
            }
            if (count < 8 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] == 0 && square[count + 40] == 0 && square[count + 48] == 0 && square[count + 56] < 1)
            {
                g_squareTemp[count + 56] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 56;
                    ++count2;
                }
                g_squareTemp[count + 56] = square[count + 56];
                g_squareTemp[count] = 4;
            }
            if (count > 7 && square[count - 8] < 1)
            {
                g_squareTemp[count - 8] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 8;
                    ++count2;
                }
                g_squareTemp[count - 8] = square[count - 8];
                g_squareTemp[count] = 4;
            }
            if (count > 15 && square[count - 8] == 0 && square[count - 16] < 1)
            {
                g_squareTemp[count - 16] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 16;
                    ++count2;
                }
                g_squareTemp[count - 16] = square[count - 16];
                g_squareTemp[count] = 4;
            }
            if (count > 23 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] < 1)
            {
                g_squareTemp[count - 24] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 24;
                    ++count2;
                }
                g_squareTemp[count - 24] = square[count - 24];
                g_squareTemp[count] = 4;
            }
            if (count > 31 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] < 1)
            {
                g_squareTemp[count - 32] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 32;
                    ++count2;
                }
                g_squareTemp[count - 32] = square[count - 32];
                g_squareTemp[count] = 4;
            }
            if (count > 39 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] == 0 && square[count - 40] < 1)
            {
                g_squareTemp[count - 40] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 40;
                    ++count2;
                }
                g_squareTemp[count - 40] = square[count - 40];
                g_squareTemp[count] = 4;
            }
            if (count > 47 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] == 0 && square[count - 40] == 0 && square[count - 48] < 1)
            {
                g_squareTemp[count - 48] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 48;
                    ++count2;
                }
                g_squareTemp[count - 48] = square[count - 48];
                g_squareTemp[count] = 4;
            }
            if (count > 55 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] == 0 && square[count - 40] == 0 && square[count - 48] == 0 && square[count - 56] < 1)
            {
                g_squareTemp[count - 56] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 56;
                    ++count2;
                }
                g_squareTemp[count - 56] = square[count - 56];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 7 && square[count + 1] < 1)
            {
                g_squareTemp[count + 1] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 1;
                    ++count2;
                }
                g_squareTemp[count + 1] = square[count + 1];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 6 && square[count + 1] == 0 && square[count + 2] < 1)
            {
                g_squareTemp[count + 2] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 2;
                    ++count2;
                }
                g_squareTemp[count + 2] = square[count + 2];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 5 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] < 1)
            {
                g_squareTemp[count + 3] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 3;
                    ++count2;
                }
                g_squareTemp[count + 3] = square[count + 3];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 4 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] < 1)
            {
                g_squareTemp[count + 4] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 4;
                    ++count2;
                }
                g_squareTemp[count + 4] = square[count + 4];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 3 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] == 0 && square[count + 5] < 1)
            {
                g_squareTemp[count + 5] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 5;
                    ++count2;
                }
                g_squareTemp[count + 5] = square[count + 5];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 2 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] == 0 && square[count + 5] == 0 && square[count + 6] < 1)
            {
                g_squareTemp[count + 6] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 6;
                    ++count2;
                }
                g_squareTemp[count + 6] = square[count + 6];
                g_squareTemp[count] = 4;
            }
            if (count % 8 < 1 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] == 0 && square[count + 5] == 0 && square[count + 6] == 0 && square[count + 7] < 1)
            {
                g_squareTemp[count + 7] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 7;
                    ++count2;
                }
                g_squareTemp[count + 7] = square[count + 7];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 0 && square[count - 1] < 1)
            {
                g_squareTemp[count - 1] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 1;
                    ++count2;
                }
                g_squareTemp[count - 1] = square[count - 1];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 1 && square[count - 1] == 0 && square[count - 2] < 1)
            {
                g_squareTemp[count - 2] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 2;
                    ++count2;
                }
                g_squareTemp[count - 2] = square[count - 2];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 2 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] < 1)
            {
                g_squareTemp[count - 3] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 3;
                    ++count2;
                }
                g_squareTemp[count - 3] = square[count - 3];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 3 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] < 1)
            {
                g_squareTemp[count - 4] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 4;
                    ++count2;
                }
                g_squareTemp[count - 4] = square[count - 4];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 4 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] == 0 && square[count - 5] < 1)
            {
                g_squareTemp[count - 5] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 5;
                    ++count2;
                }
                g_squareTemp[count - 5] = square[count - 5];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 5 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] == 0 && square[count - 5] == 0 && square[count - 6] < 1)
            {
                g_squareTemp[count - 6] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 6;
                    ++count2;
                }
                g_squareTemp[count - 6] = square[count - 6];
                g_squareTemp[count] = 4;
            }
            if (count % 8 > 6 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] == 0 && square[count - 5] == 0 && square[count - 6] == 0 && square[count - 7] < 1)
            {
                g_squareTemp[count - 7] = 4;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 7;
                    ++count2;
                }
                g_squareTemp[count - 7] = square[count - 7];
                g_squareTemp[count] = 4;
            }
        }
        //queen moves
        if (square[count] == 5)
        {
            //rook movement
            if (count < 56 && square[count + 8] < 1)
            {
                g_squareTemp[count + 8] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 8;
                    ++count2;
                }
                g_squareTemp[count + 8] = square[count + 8];
                g_squareTemp[count] = 5;
            }
            if (count < 48 && square[count + 8] == 0 && square[count + 16] < 1)
            {
                g_squareTemp[count + 16] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 16;
                    ++count2;
                }
                g_squareTemp[count + 16] = square[count + 16];
                g_squareTemp[count] = 5;
            }
            if (count < 40 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] < 1)
            {
                g_squareTemp[count + 24] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 24;
                    ++count2;
                }
                g_squareTemp[count + 24] = square[count + 24];
                g_squareTemp[count] = 5;
            }
            if (count < 32 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] < 1)
            {
                g_squareTemp[count + 32] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 32;
                    ++count2;
                }
                g_squareTemp[count + 32] = square[count + 32];
                g_squareTemp[count] = 5;
            }
            if (count < 24 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] == 0 && square[count + 40] < 1)
            {
                g_squareTemp[count + 40] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 40;
                    ++count2;
                }
                g_squareTemp[count + 40] = square[count + 40];
                g_squareTemp[count] = 5;
            }
            if (count < 16 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] == 0 && square[count + 40] == 0 && square[count + 48] < 1)
            {
                g_squareTemp[count + 48] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 48;
                    ++count2;
                }
                g_squareTemp[count + 48] = square[count + 48];
                g_squareTemp[count] = 5;
            }
            if (count < 8 && square[count + 8] == 0 && square[count + 16] == 0 && square[count + 24] == 0 && square[count + 32] == 0 && square[count + 40] == 0 && square[count + 48] == 0 && square[count + 56] < 1)
            {
                g_squareTemp[count + 56] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 56;
                    ++count2;
                }
                g_squareTemp[count + 56] = square[count + 56];
                g_squareTemp[count] = 5;
            }
            if (count > 7 && square[count - 8] < 1)
            {
                g_squareTemp[count - 8] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 8;
                    ++count2;
                }
                g_squareTemp[count - 8] = square[count - 8];
                g_squareTemp[count] = 5;
            }
            if (count > 15 && square[count - 8] == 0 && square[count - 16] < 1)
            {
                g_squareTemp[count - 16] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 16;
                    ++count2;
                }
                g_squareTemp[count - 16] = square[count - 16];
                g_squareTemp[count] = 5;
            }
            if (count > 23 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] < 1)
            {
                g_squareTemp[count - 24] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 24;
                    ++count2;
                }
                g_squareTemp[count - 24] = square[count - 24];
                g_squareTemp[count] = 5;
            }
            if (count > 31 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] < 1)
            {
                g_squareTemp[count - 32] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 32;
                    ++count2;
                }
                g_squareTemp[count - 32] = square[count - 32];
                g_squareTemp[count] = 5;
            }
            if (count > 39 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] == 0 && square[count - 40] < 1)
            {
                g_squareTemp[count - 40] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 40;
                    ++count2;
                }
                g_squareTemp[count - 40] = square[count - 40];
                g_squareTemp[count] = 5;
            }
            if (count > 47 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] == 0 && square[count - 40] == 0 && square[count - 48] < 1)
            {
                g_squareTemp[count - 48] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 48;
                    ++count2;
                }
                g_squareTemp[count - 48] = square[count - 48];
                g_squareTemp[count] = 5;
            }
            if (count > 55 && square[count - 8] == 0 && square[count - 16] == 0 && square[count - 24] == 0 && square[count - 32] == 0 && square[count - 40] == 0 && square[count - 48] == 0 && square[count - 56] < 1)
            {
                g_squareTemp[count - 56] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 56;
                    ++count2;
                }
                g_squareTemp[count - 56] = square[count - 56];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 7 && square[count + 1] < 1)
            {
                g_squareTemp[count + 1] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 1;
                    ++count2;
                }
                g_squareTemp[count + 1] = square[count + 1];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 6 && square[count + 1] == 0 && square[count + 2] < 1)
            {
                g_squareTemp[count + 2] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 2;
                    ++count2;
                }
                g_squareTemp[count + 2] = square[count + 2];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 5 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] < 1)
            {
                g_squareTemp[count + 3] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 3;
                    ++count2;
                }
                g_squareTemp[count + 3] = square[count + 3];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 4 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] < 1)
            {
                g_squareTemp[count + 4] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 4;
                    ++count2;
                }
                g_squareTemp[count + 4] = square[count + 4];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 3 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] == 0 && square[count + 5] < 1)
            {
                g_squareTemp[count + 5] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 5;
                    ++count2;
                }
                g_squareTemp[count + 5] = square[count + 5];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 2 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] == 0 && square[count + 5] == 0 && square[count + 6] < 1)
            {
                g_squareTemp[count + 6] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 6;
                    ++count2;
                }
                g_squareTemp[count + 6] = square[count + 6];
                g_squareTemp[count] = 5;
            }
            if (count % 8 < 1 && square[count + 1] == 0 && square[count + 2] == 0 && square[count + 3] == 0 && square[count + 4] == 0 && square[count + 5] == 0 && square[count + 6] == 0 && square[count + 7] < 1)
            {
                g_squareTemp[count + 7] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 7;
                    ++count2;
                }
                g_squareTemp[count + 7] = square[count + 7];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 0 && square[count - 1] < 1)
            {
                g_squareTemp[count - 1] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 1;
                    ++count2;
                }
                g_squareTemp[count - 1] = square[count - 1];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 1 && square[count - 1] == 0 && square[count - 2] < 1)
            {
                g_squareTemp[count - 2] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 2;
                    ++count2;
                }
                g_squareTemp[count - 2] = square[count - 2];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 2 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] < 1)
            {
                g_squareTemp[count - 3] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 3;
                    ++count2;
                }
                g_squareTemp[count - 3] = square[count - 3];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 3 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] < 1)
            {
                g_squareTemp[count - 4] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 4;
                    ++count2;
                }
                g_squareTemp[count - 4] = square[count - 4];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 4 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] == 0 && square[count - 5] < 1)
            {
                g_squareTemp[count - 5] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 5;
                    ++count2;
                }
                g_squareTemp[count - 5] = square[count - 5];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 5 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] == 0 && square[count - 5] == 0 && square[count - 6] < 1)
            {
                g_squareTemp[count - 6] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 6;
                    ++count2;
                }
                g_squareTemp[count - 6] = square[count - 6];
                g_squareTemp[count] = 5;
            }
            if (count % 8 > 6 && square[count - 1] == 0 && square[count - 2] == 0 && square[count - 3] == 0 && square[count - 4] == 0 && square[count - 5] == 0 && square[count - 6] == 0 && square[count - 7] < 1)
            {
                g_squareTemp[count - 7] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 7;
                    ++count2;
                }
                g_squareTemp[count - 7] = square[count - 7];
                g_squareTemp[count] = 5;
            }
            //bishop movement
            if (count < 56 && count % 8 != 7 && square[count + 9] < 1)
            {
                g_squareTemp[count + 9] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 9;
                    ++count2;
                }
                g_squareTemp[count + 9] = square[count + 9];
                g_squareTemp[count] = 5;
            }
            if (count < 48 && count % 8 < 6 && square[count + 9] == 0 && square[count + 18] < 1)
            {
                g_squareTemp[count + 18] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 18;
                    ++count2;
                }
                g_squareTemp[count + 18] = square[count + 18];
                g_squareTemp[count] = 5;
            }
            if (count < 40 && count % 8 < 5 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] < 1)
            {
                g_squareTemp[count + 27] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 27;
                    ++count2;
                }
                g_squareTemp[count + 27] = square[count + 27];
                g_squareTemp[count] = 5;
            }
            if (count < 32 && count % 8 < 4 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] == 0 && square[count + 36] < 1)
            {
                g_squareTemp[count + 36] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 36;
                    ++count2;
                }
                g_squareTemp[count + 36] = square[count + 36];
                g_squareTemp[count] = 5;
            }
            if (count < 24 && count % 8 < 3 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] == 0 && square[count + 36] == 0 && square[count + 45] < 1)
            {
                g_squareTemp[count + 45] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 45;
                    ++count2;
                }
                g_squareTemp[count + 45] = square[count + 45];
                g_squareTemp[count] = 5;
            }
            if (count < 16 && count % 8 < 2 && square[count + 9] == 0 && square[count + 18] == 0 && square[count + 27] == 0 && square[count + 36] == 0 && square[count + 45] == 0 && square[count + 54] < 1)
            {
                g_squareTemp[count + 54] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 54;
                    ++count2;
                }
                g_squareTemp[count + 54] = square[count + 54];
                g_squareTemp[count] = 5;
            }
            if (count == 0 && square[9] == 0 && square[18] == 0 && square[27] == 0 && square[36] == 0 && square[45] == 0 && square[54] == 0 && square[count + 63] < 1)
            {
                g_squareTemp[count + 63] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 63;
                    ++count2;
                }
                g_squareTemp[count + 63] = square[count + 63];
                g_squareTemp[count] = 5;
            }
            if (count < 56 && count % 8 != 0 && square[count + 7] < 1)
            {
                g_squareTemp[count + 7] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 7;
                    ++count2;
                }
                g_squareTemp[count + 7] = square[count + 7];
                g_squareTemp[count] = 5;
            }
            if (count < 48 && count % 8 > 1 && square[count + 7] == 0 && square[count + 14] < 1)
            {
                g_squareTemp[count + 14] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 14;
                    ++count2;
                }
                g_squareTemp[count + 14] = square[count + 14];
                g_squareTemp[count] = 5;
            }
            if (count < 40 && count % 8 > 2 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] < 1)
            {
                g_squareTemp[count + 21] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 21;
                    ++count2;
                }
                g_squareTemp[count + 21] = square[count + 21];
                g_squareTemp[count] = 5;
            }
            if (count < 32 && count % 8 > 3 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] == 0 && square[count + 28] < 1)
            {
                g_squareTemp[count + 28] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 28;
                    ++count2;
                }
                g_squareTemp[count + 28] = square[count + 28];
                g_squareTemp[count] = 5;
            }
            if (count < 24 && count % 8 > 4 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] == 0 && square[count + 28] == 0 && square[count + 35] < 1)
            {
                g_squareTemp[count + 35] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 35;
                    ++count2;
                }
                g_squareTemp[count + 35] = square[count + 35];
                g_squareTemp[count] = 5;
            }
            if (count < 16 && count % 8 > 5 && square[count + 7] == 0 && square[count + 14] == 0 && square[count + 21] == 0 && square[count + 28] == 0 && square[count + 35] == 0 && square[count + 42] < 1)
            {
                g_squareTemp[count + 42] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count + 42;
                    ++count2;
                }
                g_squareTemp[count + 42] = square[count + 42];
                g_squareTemp[count] = 5;
            }
            if (count == 7 && square[14] == 0 && square[21] == 0 && square[28] == 0 && square[35] == 0 && square[42] == 0 && square[49] == 0 && square[56] < 1)
            {
                g_squareTemp[56] = 5;
                g_squareTemp[7] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 7;
                    move2[count2] = 56;
                    ++count2;
                }
                g_squareTemp[56] = square[56];
                g_squareTemp[7] = 5;
            }
            if (count >= 8 && count % 8 != 7 && square[count - 7] < 1)
            {
                g_squareTemp[count - 7] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 7;
                    ++count2;
                }
                g_squareTemp[count - 7] = square[count - 7];
                g_squareTemp[count] = 5;
            }
            if (count >= 16 && count % 8 < 6 && square[count - 7] == 0 && square[count - 14] < 1)
            {
                g_squareTemp[count - 14] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 14;
                    ++count2;
                }
                g_squareTemp[count - 14] = square[count - 14];
                g_squareTemp[count] = 5;
            }
            if (count >= 24 && count % 8 < 5 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] < 1)
            {
                g_squareTemp[count - 21] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 21;
                    ++count2;
                }
                g_squareTemp[count - 21] = square[count - 21];
                g_squareTemp[count] = 5;
            }
            if (count >= 32 && count % 8 < 4 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] == 0 && square[count - 28] < 1)
            {
                g_squareTemp[count - 28] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 28;
                    ++count2;
                }
                g_squareTemp[count - 28] = square[count - 28];
                g_squareTemp[count] = 5;
            }
            if (count >= 40 && count % 8 < 3 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] == 0 && square[count - 28] == 0 && square[count - 35] < 1)
            {
                g_squareTemp[count - 35] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 35;
                    ++count2;
                }
                g_squareTemp[count - 35] = square[count - 35];
                g_squareTemp[count] = 5;
            }
            if (count >= 48 && count % 8 < 2 && square[count - 7] == 0 && square[count - 14] == 0 && square[count - 21] == 0 && square[count - 28] == 0 && square[count - 35] == 0 && square[count - 42] < 1)
            {
                g_squareTemp[count - 42] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 42;
                    ++count2;
                }
                g_squareTemp[count - 42] = square[count - 42];
                g_squareTemp[count] = 5;
            }
            if (count == 56 && square[14] == 0 && square[21] == 0 && square[28] == 0 && square[35] == 0 && square[42] == 0 && square[49] == 0 && square[7] < 1)
            {
                g_squareTemp[7] = 5;
                g_squareTemp[56] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 56;
                    move2[count2] = 7;
                    ++count2;
                }
                g_squareTemp[7] = square[7];
                g_squareTemp[56] = 5;
            }
            if (count > 8 && count % 8 != 0 && square[count - 9] < 1)
            {
                g_squareTemp[count - 9] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 9;
                    ++count2;
                }
                g_squareTemp[count - 9] = square[count - 9];
                g_squareTemp[count] = 5;
            }
            if (count > 16 && count % 8 > 1 && square[count - 9] == 0 && square[count - 18] < 1)
            {
                g_squareTemp[count - 18] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 18;
                    ++count2;
                }
                g_squareTemp[count - 18] = square[count - 18];
                g_squareTemp[count] = 5;
            }
            if (count > 24 && count % 8 > 2 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] < 1)
            {
                g_squareTemp[count - 27] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 27;
                    ++count2;
                }
                g_squareTemp[count - 27] = square[count - 27];
                g_squareTemp[count] = 5;
            }
            if (count > 32 && count % 8 > 3 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] == 0 && square[count - 36] < 1)
            {
                g_squareTemp[count - 36] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 36;
                    ++count2;
                }
                g_squareTemp[count - 36] = square[count - 36];
                g_squareTemp[count] = 5;
            }
            if (count > 40 && count % 8 > 4 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] == 0 && square[count - 36] == 0 && square[count - 45] < 1)
            {
                g_squareTemp[count - 45] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 45;
                    ++count2;
                }
                g_squareTemp[count - 45] = square[count - 45];
                g_squareTemp[count] = 5;
            }
            if (count > 48 && count % 8 > 5 && square[count - 9] == 0 && square[count - 18] == 0 && square[count - 27] == 0 && square[count - 36] == 0 && square[count - 45] == 0 && square[count - 54] < 1)
            {
                g_squareTemp[count - 54] = 5;
                g_squareTemp[count] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = count;
                    move2[count2] = count - 54;
                    ++count2;
                }
                g_squareTemp[count - 54] = square[count - 54];
                g_squareTemp[count] = 5;
            }
            if (count == 63 && square[9] == 0 && square[18] == 0 && square[27] == 0 && square[36] == 0 && square[45] == 0 && square[54] == 0 && square[0] < 1)
            {
                g_squareTemp[0] = 5;
                g_squareTemp[63] = 0;
                if (isKingAttacked() == true)
                {
                    posEval[count2] = neuralNet(g_squareTemp[0], g_squareTemp[1], g_squareTemp[2], g_squareTemp[3], g_squareTemp[4], g_squareTemp[5], g_squareTemp[6], g_squareTemp[7], g_squareTemp[8], g_squareTemp[9], g_squareTemp[10], g_squareTemp[11], g_squareTemp[12], g_squareTemp[13], g_squareTemp[14], g_squareTemp[15], g_squareTemp[16], g_squareTemp[17], g_squareTemp[18], g_squareTemp[19], g_squareTemp[20], g_squareTemp[21], g_squareTemp[22], g_squareTemp[23], g_squareTemp[24], g_squareTemp[25], g_squareTemp[26], g_squareTemp[27], g_squareTemp[28], g_squareTemp[29], g_squareTemp[30], g_squareTemp[31], g_squareTemp[32], g_squareTemp[33], g_squareTemp[34], g_squareTemp[35], g_squareTemp[36], g_squareTemp[37], g_squareTemp[38], g_squareTemp[39], g_squareTemp[40], g_squareTemp[41], g_squareTemp[42], g_squareTemp[43], g_squareTemp[44], g_squareTemp[45], g_squareTemp[46], g_squareTemp[47], g_squareTemp[48], g_squareTemp[49], g_squareTemp[50], g_squareTemp[51], g_squareTemp[52], g_squareTemp[53], g_squareTemp[54], g_squareTemp[55], g_squareTemp[56], g_squareTemp[57], g_squareTemp[58], g_squareTemp[59], g_squareTemp[60], g_squareTemp[61], g_squareTemp[62], g_squareTemp[63]);
                    move1[count2] = 63;
                    move2[count2] = 0;
                    ++count2;
                }
                g_squareTemp[0] = square[0];
                g_squareTemp[63] = 5;
            }
        }
        ++count;

    }
    count = 0;
    float bestEval{ -15 };
    int bestMove1{ -1 }, bestMove2{ -1 };
    while (count < 540)
    {
        if (posEval[count] > bestEval)
        {
            bestEval = posEval[count];
            bestMove1 = move1[count];
            bestMove2 = move2[count];
        }
        ++count;
    }
    count = 0;
    if (square[bestMove1] != 1 || square[bestMove2] == 0)
    {
        ++g_fiftyMoveRule;
    }
    if (bestMove1 == -1)
    {
        loss=1;
    }
    if (bestMove1 == 60 && bestMove2 == 62 && square[60] == 6)
    {
        g_masterBoard[63] = 0;
        g_masterBoard[61] = 4;
        if (g_toMove == 0)
        {
            g_castleKing = false;
            g_castleQueen = false;
        }
        else
        {
            g_opponentCastleKing = false;
            g_opponentCastleQueen = false;
        }
    }
    if (bestMove1 == 60 && bestMove2 == 58 && square[60] == 6)
    {
        g_masterBoard[56] = 0;
        g_masterBoard[59] = 4;
        if (g_toMove == 0)
        {
            g_castleKing = false;
            g_castleQueen = false;
        }
        else
        {
            g_opponentCastleKing = false;
            g_opponentCastleQueen = false;
        }
    }
    g_masterBoard[bestMove2] = square[bestMove1];
    g_masterBoard[bestMove1] = 0;
    if (square[bestMove1] == 6)
    {
        if (g_toMove == 0)
        {
            g_castleKing = false;
            g_castleQueen = false;
        }
        else
        {
            g_opponentCastleKing = false;
            g_opponentCastleQueen = false;
        }
    }
    if (gameDrawn() == true)
    {
        loss=1;
    }
    if (g_toMove == 0)
    {
        g_toMove = 1;
    }
    else
    {
        g_toMove = 0;
    }
    return loss;
}
//self train
void selfTrain(int trainCount)
{
bool x{0}, result{0};
int count{0}, count2{0};
while (trainCount > 0)
{
    while (result == 0)
    {
        result=getMove();
        while (count < 64)
        {
            g_masterBoard[count] = g_masterBoard[count] * -1;
            ++count;
        }
        count = 0;
        while (count < 64)
        {
            g_squareTemp[count] = g_masterBoard[count];
            ++count;
        }
        count = 0;
        count2 = 63;
        while (count < 64)
        {
            g_masterBoard[count] = g_squareTemp[count2];
            --count2;
            ++count;
        }
        count = 0;
        count2 = 63;
    }
    if (g_toMove == 0)
    {
        while (count < 705)
        {
            g_weight[count] = g_weightTest[count];
            ++count;
        }
        count = 0;
    }
    mutate();
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
    while (count < 32)
    {
        g_masterBoard[count] = 0;
        ++count;
    }
    count = 0;
    g_masterBoard[48] = 1;
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
    g_fiftyMoveRule = 0;
    g_toMove = 0;
    g_castleKing = 1;
    g_castleQueen = 1;
    g_opponentCastleKing = 1;
    g_opponentCastleQueen = 1;
    result = 0;
    --trainCount;
    std::cout << result << "\n";
}
}
//main
int main()
{
   std::cout << "inputting neural net weights\n";
   int count{0};
   std::fstream neural_net_weights{"neuralNetWeights705.txt"};
   neural_net_weights.seekg(0, std::ios::beg);
   if (!neural_net_weights)
   {
      std::cerr << "No weights file\n";
      return 1;
   }
   else
   {

      while (count<705)
      {
         neural_net_weights >> g_weight[count];
         ++count;
      }
      count=0;
   }
   std::cout << "how many generations do you want to train the neural net?\n";
   int trainCount;
   std::cin >> trainCount;
   std::cout << "training neural net\n";
   selfTrain(trainCount);
   neural_net_weights.seekg(0, std::ios::beg);
   while (count<705)
   {
      neural_net_weights << g_weight[count] << '\n';
      ++count;
   }
   count=0;
   neural_net_weights.seekg(0, std::ios::beg);
   std::cout << "training finished";
   return 0;
}
