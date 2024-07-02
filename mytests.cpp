#include <gtest/gtest.h>
#include "myfunctions.h"

TEST(myfunctions, fExample)
{
    double x = 1.0;
    double y = 1.0;

    GTEST_ASSERT_EQ(fExample(x, y), 2.0);
}

TEST(myfunctions, slopeF)
{
    double x = 0;
    double y = 0;

    GTEST_ASSERT_EQ(slopeF(x, y), 5);
}

TEST(myfunctions, euler005)
{
    double x0 = 1;
    double y0 = 1;
    double xLast = 1.1;
    double h = 0.05;

    SlopeFunction chosenSlopeF = fExample;

    std::vector<std::vector<double>> ans = {{1, 1},{1.05, 1.1},{1.1, 1.2155}};

    GTEST_ASSERT_EQ(euler(x0, y0, xLast, h, chosenSlopeF), ans);
}

TEST(myfunctions, RK4)
{
    double x0 = 1;
    double y0 = 1;
    double xLast = 1.5;
    double h = 0.1;

    SlopeFunction chosenSlopeF = fExample;

    std::vector<std::vector<double>> ans = {{1, 1},
    {1.1, 1.2337},
    {1.2, 1.5527},
    {1.3, 1.9937},
    {1.4, 2.6116},
    {1.5, 3.4902}};

    GTEST_ASSERT_EQ(RK4(x0, y0, xLast, h, chosenSlopeF), ans);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
