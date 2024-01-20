#include"pch.h"
#include "Header.h"



TEST(q1, base) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    string result = obj.GetPath(1, 6);
    string org = "1-1 -> 2-1 -> 3-1 -> 4-1 -> 4-2 -> 5-2 -> 6-2";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}
TEST(q1, add_del) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    obj.addNode(1, 5);
    obj.DeleteNode(1, 2);
    string result = obj.GetPath(1, 6);
    string org = "1-1 -> 1-2 -> 2-2 -> 3-2 -> 3-1 -> 4-1 -> 5-1 -> 6-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t2) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T2.txt");
    string result = obj.GetPath(4, 6);
    string org = "4-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3 -> 5-3 -> 6-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}
TEST(q1, base2) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    string result = obj.GetPath(1, 6);
    string org = "1-1 -> 2-1 -> 3-1 -> 4-1 -> 4-2 -> 5-2 -> 6-2";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}

TEST(q1, newTest) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T4.txt");
    string result = obj.GetPath(1, 5);
    string org = "1-1 -> 1-2 -> 1-3 -> 2-3 -> 3-3 -> 4-3 -> 5-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}
TEST(q1, newTest7) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T12.txt");
    string result = obj.GetPath(1, 5);
    string org = "1-1 -> 1-2 -> 2-2 -> 3-2 -> 3-3 -> 4-3 -> 5-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}



TEST(q1, newTest3) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T5.txt");
    string result = obj.GetPath(3, 5);
    string org = "3-1 -> 2-1 -> 1-1 -> 1-2 -> 1-3 -> 2-3 -> 3-3 -> 4-3 -> 5-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}
TEST(q1, newTest4) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T5.txt");
    string result = obj.GetPath(4, 5);
    string org = "4-3 -> 5-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}

TEST(q1, newTest5) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T6.txt");
    string result = obj.GetPath(3, 1);
    string org = "3-3 -> 2-3 -> 1-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}
TEST(q1, newTest6) {                    
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T7.txt");
    string result = obj.GetPath(1, 8);
    string org = "1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 5-1 -> 6-1 -> 7-1 -> 7-2 -> 8-2";
    
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}




TEST(Q1, Reverse)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T8.txt");
    string result = obj.GetPath(8, 9);
    string org = "8-1 -> 7-1 -> 6-1 -> 5-1 -> 4-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 8-3 -> 9-3";
    EXPECT_EQ(result, org);
}
TEST(Q1, NotAgain)      
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T9.txt");
    string result = obj.GetPath(1, 10);
    string org = "1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 5-3 -> 6-3 -> 7-3 -> 8-3 -> 9-3 -> 10-3";
    EXPECT_EQ(result, org);
}

TEST(Q1, Nopes)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T10.txt");
    string result = obj.GetPath(1, 9);
    string org = "1-3 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 8-3 -> 8-2 -> 9-2";
    EXPECT_EQ(result, org);
}


TEST(Q1, Ooops)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T11.txt");
    string result = obj.GetPath(1, 10);
    string org = "1-1 -> 1-2 -> 1-3 -> 2-3 -> 3-3 -> 3-2 -> 3-1 -> 4-1 -> 4-2 -> 4-3 -> 5-3 -> 6-3 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 9-3 -> 10-3";
    EXPECT_EQ(result, org);
}

TEST(Q1, Crazy)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T11.txt");
    string result = obj.GetPath(1, 7);
    string org = "1-1 -> 1-2 -> 1-3 -> 2-3 -> 3-3 -> 3-2 -> 3-1 -> 4-1 -> 4-2 -> 4-3 -> 5-3 -> 6-3 -> 6-2 -> 7-2";
    EXPECT_EQ(result, org);
}
TEST(q1, t3) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(4, 10);
    string org = "4-3 -> 5-3 -> 6-3 -> 7-3 -> 7-2 -> 7-1 -> 8-1 -> 9-1 -> 10-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t4) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(10, 4);
    string org = "10-1 -> 9-1 -> 8-1 -> 7-1 -> 7-2 -> 7-3 -> 6-3 -> 5-3 -> 4-3";
    EXPECT_EQ(result, org);
}


TEST(q1, t5) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(5, 15);
    string org = "5-1 -> 6-1 -> 7-1 -> 8-1 -> 8-2 -> 8-3 -> 9-3 -> 10-3 -> 11-3 -> 12-3 -> 12-2 -> 13-2 -> 14-2 -> 15-2";
    EXPECT_EQ(result, org);
}



TEST(q1, t6) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(15, 5);
    string org = "15-2 -> 14-2 -> 13-2 -> 12-2 -> 12-3 -> 11-3 -> 10-3 -> 9-3 -> 8-3 -> 8-2 -> 8-1 -> 7-1 -> 6-1 -> 5-1";
    EXPECT_EQ(result, org);
}


TEST(q1, t7) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(5, 10);
    string org = "5-1 -> 6-1 -> 7-1 -> 8-1 -> 9-1 -> 10-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t8) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(10, 5);
    string org = "10-1 -> 9-1 -> 8-1 -> 7-1 -> 6-1 -> 5-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t9) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(3, 11);
    string org = "3-1 -> 2-1 -> 2-2 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 7-2 -> 7-1 -> 8-1 -> 8-2 -> 8-3 -> 9-3 -> 10-3 -> 11-3";
    EXPECT_EQ(result, org);
}

// q2 has no restriction on starting layer







TEST(q2, t9) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(70, obj.GetMinCost(26, 7));
    // 26-2 -> 25-2 -> 24-2 -> 23-2 -> 22-2 -> 21-2 -> 20-2 -> 19-2 -> 18-2 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3 -> 13-3 -> 13-2 -> 12-2 -> 11-2 -> 10-2 -> 9-2 -> 8-2 -> 7-2
}

TEST(q2, t15) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(14, obj.GetMinCost(19, 14));
    //19-2 -> 18-2 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3
}


TEST(q2, t19) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(49, obj.GetMinCost(19, 6));
    // 19-2 -> 18-2 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3 -> 13-3 -> 13-2 -> 12-2 -> 11-2 -> 10-2 -> 9-2 -> 8-2 -> 7-2 -> 6-2
}

TEST(q2, t14) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(35, obj.GetMinCost(16, 25));
    // 16-3 -> 17-3 -> 18-3 -> 18-2 -> 19-2 -> 20-2 -> 21-2 -> 22-2 -> 23-2 -> 24-2 -> 25-2
}


TEST(q2, t8) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(45, obj.GetMinCost(7, 20));
    // 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 18-2 -> 19-2 -> 20-2
}

TEST(q2, t20) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(58, obj.GetMinCost(4, 20));
    // 4-2 -> 5-2 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 18-2 -> 19-2 -> 20-2
}

 TEST(q2, t1) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T1.txt");
    EXPECT_EQ(48, obj.GetMinCost(1, 4));
    //1-1 -> 2-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3
    //     1  +   5   +  5   +  5   + 32   = 48
}
TEST(q2, t11) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(10, obj.GetMinCost(13, 10));
    // 13-2 -> 12-2 -> 12-1 -> 11-1 -> 10-1
}

TEST(q2, t3) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(19, obj.GetMinCost(23, 17));
    // 23-3 -> 22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3
}


TEST(q2, t5) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(33, obj.GetMinCost(23, 12));
    // 23-3 -> 22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3 -> 13-3 -> 12-3
}

TEST(q2, t7) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(1, obj.GetMinCost(11, 10));
    // 11-1 -> 10-1
}



TEST(q2, t13) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(15, obj.GetMinCost(22, 17));
    //22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3
}


TEST(q2, t17) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(2, obj.GetMinCost(3, 2));
    // 3-1 -> 2-1
}

TEST(q2, t4) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(1, obj.GetMinCost(1, 2));
    //1-1 -> 2-1
}

TEST(q2, t6) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(14, obj.GetMinCost(12, 17));
    // 12-3 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3
}

TEST(q2, t10) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(76, obj.GetMinCost(1, 22));
    // 1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 20-3 -> 21-3 -> 22-3
}

TEST(q2, t12) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(38, obj.GetMinCost(11, 22));
    // 11-3 -> 12-3 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 20-3 -> 21-3 -> 22-3
}


TEST(q2, t16) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(10, obj.GetMinCost(1, 4));
    // 1-1 -> 2-1 -> 3-1 -> 4-1
}

TEST(q2, t2) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T1.txt");
    EXPECT_EQ(4,obj.GetMinCost(4,5));
}


TEST(q2, t18) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(58, obj.GetMinCost(1, 16));
    // 1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3
}



