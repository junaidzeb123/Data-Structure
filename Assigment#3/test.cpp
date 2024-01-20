#include "pch.h"
#include"Header.h"

// Test case

TEST(q1, T1) {
	string input = "fghfzydxo";
	int k = 6;
	string result = largestString(input, k);
	string exp = "zyx";
	EXPECT_EQ(result, exp);
}
TEST(q1, T2) {
	string input = "fzlyoapx";
	int k = 2;
	string result = largestString(input, k);
	string exp = "zyoapx";
	EXPECT_EQ(result, exp);
}
TEST(q1, T3) {
	string input = "xdycz";
	int k = 2;
	string result = largestString(input, k);
	string exp = "ycz";
	EXPECT_EQ(result, exp);
}
TEST(q1, T4) {
	string input = "helloworld";
	int k = 7;
	string result = largestString(input, k);
	string exp = "wrl";
	EXPECT_EQ(result, exp);
}
TEST(q1, T5) {
	string input = "datastructures";
	int k = 6;
	string result = largestString(input, k);
	string exp = "tuctures";
	EXPECT_EQ(result, exp);
}
TEST(q1, T6) {
	string input = "datastructures";
	int k = 5;
	string result = largestString(input, k);
	string exp = "ttuctures";
	EXPECT_EQ(result, exp);
}
TEST(q1, T7) {
	string input = "datastructures";
	int k = 9;
	string result = largestString(input, k);
	string exp = "uures";
	EXPECT_EQ(result, exp);
}
TEST(q1, T8) {
	string input = "datastructures";
	int k = 0;
	string result = largestString(input, k);
	string exp = "datastructures";
	EXPECT_EQ(result, exp);
}
TEST(q1, T9) {
	string input = "datastructures";
	int k = 14;
	string result = largestString(input, k);
	string exp = "";
	EXPECT_EQ(result, exp);
}
TEST(q1, T10) {
	string input = "aquickbrownfox";
	int k = 4;
	string result = largestString(input, k);
	string exp = "ukbrownfox";
	EXPECT_EQ(result, exp);
}
TEST(q1, T11) {
	string input = "zzzzzg";
	int k = 1;
	string result = largestString(input, k);
	string exp = "zzzzz";
	EXPECT_EQ(result, exp);
}
TEST(q1, T12) {
	string input = "zzzgzz";
	int k = 1;
	string result = largestString(input, k);
	string exp = "zzzzz";
	EXPECT_EQ(result, exp);
}
TEST(q1, T13) {
	string input = "zzzgzbxz";
	int k = 3;
	string result = largestString(input, k);
	string exp = "zzzzz";
	EXPECT_EQ(result, exp);
}
TEST(q1, T14) {
	string input = "abczzzgzz";
	int k = 6;
	string result = largestString(input, k);
	string exp = "zzz";
	EXPECT_EQ(result, exp);
}

TEST(Question_1, Test1) {
	std::string str = "mytttiiifsdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
	int k = 4;
	std::string ans = "ytttisdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}
TEST(Question_1, Test20) {
	std::string str = "dcba";
	int k = 2;
	std::string ans = "dc";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test2) {
	std::string str = "codingisnofununtilyoudodsa";
	int k = 8;
	std::string ans = "sofununtilyoudodsa";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test3) {
	std::string str = "rebmasitohsui";
	int k = 3;
	std::string ans = "rmsitohsui";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test4) {
	std::string str = "farigballdamhadbj";
	int k = 5;
	std::string ans = "rilldamhadbj";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test5) {
	std::string str = "maajyutrrabcde";
	int k = 2;
	std::string ans = "mjyutrrabcde";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_2, Test1) {
	std::string str = "45";
	int k = 1;
	std::string ans = "4";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test2) {
	std::string str = "96";
	int k = 1;
	std::string ans = "6";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test3) {
	std::string str = "6789";
	int k = 0;
	std::string ans = "6789";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test4) {
	std::string str = "6";
	int k = 0;
	std::string ans = "6";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test5) {
	std::string str = "287948768";
	int k = 0;
	std::string ans = "287948768";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}

TEST(Question_2, Test6) {
	std::string str = "53980517";
	int k = 2;
	std::string ans = "380517";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test7) {
	std::string str = "37594852632";
	int k = 10;
	std::string ans = "2";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test8) {
	std::string str = "739717549062896";
	int k = 1;
	std::string ans = "39717549062896";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test9) {
	std::string str = "2233300000000000000";
	int k = 3;
	std::string ans = "2200000000000000";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}

TEST(Question_2, Test10) {
	std::string str = "1766739498453158327826647316936982938316534805172218962557053186925224732";
	int k = 2;
	std::string ans = "16639498453158327826647316936982938316534805172218962557053186925224732";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}

TEST(Question_2, Test20) {
	std::string str = "464038665066592229991395446868568";
	int k = 20;
	std::string ans = "1395446868568";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}

TEST(Question_2, Test11) {
	std::string str = "464038665066592229991395446868568141659015313318498114800229294263538051662670061878";
	int k = 28;
	std::string ans = "13445141659015313318498114800229294263538051662670061878";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}




// Test case Question-3
TEST(Question_3, Test1) {
	int arr[5] = { 1,2,3,4,5 };
	int arr2[1] = { 5 };
	int k = 1;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test2) {
	int arr[10] = { 3, -1, -2, 4, 6, -2, 2, 4, 6, -1 };
	int arr2[5] = { 6, -2 , 2 , 4 , 6 };
	int k = 5;
	int size = 10;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++) {
		EXPECT_EQ(arr2[i], result[i]);
		
	}
}

TEST(Question_3, Test3) {
	int arr[5] = { 0, 0 , 0 , 0 , 0 };
	int arr2[5] = { 0, 0 , 0 , 0 , 0 };
	int k = 5;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test4) {
	int arr[5] = { -5,-1,-1,-1,-1 };
	int arr2[2] = { -1, -1 };
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test5) {
	int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[4] = { 7, -3, 5, 1 };
	int k = 4;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test6) {
	int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[1] = {10 };
	int k = 1;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}
TEST(Question_3, Test7) {
	int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[2] = {5,1 };
	int k = 2;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}
TEST(Question_3, Test8) {
	int arr[2] = {  -2, -6 };
	int arr2[2] = {-2,-6 };
	int k = 2;
	int size = 2;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}


TEST(Question_3, Test9) {
	int arr[5] = { -5,-4,-3,-2 ,-1};
	int arr2[2] = { -2, -1 };
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}
TEST(Question_3, Test10) {
	int arr[5] = { 5,4,3,2,1};
	int arr2[2] = { 5,4 };
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}
TEST(Question_3, Test11) {
	int arr[10] = { 0,10,1,9,8,3,7,4,6,5};
	int arr2[2] = { 9,8 };
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}


///
TEST(GCR_Question__2, asked1) {
	std::string str = "1040";
	int k = 2;
	std::string ans = "10";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(GCR_Question__2, asked2) {
	std::string str = "1000";
	int k = 2;
	std::string ans = "10";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(GCR_Question__2, asked3) {
	std::string str = "65401110";
	int k = 4;
	std::string ans = "1110";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(GCR_Question__2, asked4) {
	std::string str = "10";
	int k = 1;
	std::string ans = "1";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(GCR_Question__2, asked5) {
	std::string str = "9010";
	int k = 2;
	std::string ans = "10";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(GCR_Question__2, asked6) {
	std::string str = "10200";
	int k = 1;
	std::string ans = "1000";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
 TEST(Question_2, Test12) {
	std::string str = "10210";
	int k = 1;
	std::string ans = "1010";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test13) {
	std::string str = "426010";
	int k = 4;
	std::string ans = "10";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test14) {
	std::string str = "245678";
	int k = 3;
	std::string ans = "245";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test15) {
	std::string str = "245678";
	int k = 6;
	std::string ans = "";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test16) {
	std::string str = "363";
	int k = 2;
	std::string ans = "3";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test17) {
	std::string str = "363";
	int k = 2;
	std::string ans = "3";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test18) {
	std::string str = "000000";
	int k = 1;
	std::string ans = "";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
 TEST(Question_2, Test19) {
	std::string str = "102200";
	int k = 3;
	std::string ans = "100";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test21) {
	std::string str = "101200";
	int k = 1;
	std::string ans = "10100";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test22) {
	std::string str = "10210";
	int k = 1;
	std::string ans = "1010";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test23) {
	std::string str = "404";
	int k = 1;
	std::string ans = "40";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test24) {
	std::string str = "2040";
	int k = 2;
	std::string ans = "20";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test25) {
	std::string str = "2400";
	int k = 2;
	std::string ans = "20";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test26) {
	std::string str = "20402";
	int k = 2;
	std::string ans = "200";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test27) {
	std::string str = "4020";
	int k = 2;
	std::string ans = "20";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}
TEST(Question_2, Test28) {
	std::string str = "2004";
	int k = 2;
	std::string ans = "20";
	EXPECT_EQ(ans, solve(str, k)); // This expectation will fail
}


TEST(Question_2, Test29) {
	std::string str = "2910325986297865201398145278756";
	int k = 27;
	std::string ans = "1001";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test30) {
	std::string str = "930879762870164";
	int k = 10;
	std::string ans = "20164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test31) {
	std::string str = "930879762870164";
	int k = 7;
	std::string ans = "30270164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test32) {
	std::string str = "98270191379642239801000";
	int k = 17;
	std::string ans = "101000";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test33) {
	std::string str = "9130879762870164";
	int k = 6;
	std::string ans = "1062870164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test34) {
	std::string str = "20401010100";
	int k = 4;
	std::string ans = "1010100";
	EXPECT_EQ(ans, solve(str, k));
}