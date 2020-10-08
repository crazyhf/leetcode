//
//  reverseinteger.cpp
//  leetcode
//
//  Created by HavenLin on 2019/9/1.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "reverseinteger.hpp"

using namespace std;
using namespace leetcode;


vector<HFReverseIntegerSolution::TestParam> HFReverseIntegerSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .x=123, .expect=321 });
    paramVec.push_back({ .x=-123, .expect=-321 });
    paramVec.push_back({ .x=120, .expect=21 });
    paramVec.push_back({ .x=-2147483648, .expect=0 });
    paramVec.push_back({ .x=1534236469, .expect=0 });
    return paramVec;
}

void HFReverseIntegerSolution::testReverse()
{
    cout << "===============================================" << endl
         << "HFReverseIntegerSolution (7. 整数反转) :" << endl
         << "给出一个32位的有符号整数，你需要将这个整数中每位上的数字进行反转。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        int result = reverse3(param.x);
        cout << endl << "Input : " << param.x << endl
             << "Output: " << result << endl
             << "Expect: " << param.expect << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

int HFReverseIntegerSolution::reverse(int x)
{
    bool isNegative = false;
    unsigned value  = x;
    if (x < 0) { isNegative = true; value = (unsigned)(-(long)x); }
    
    unsigned long result = 0;
    while (value) {
        result = result * 10 + value % 10;
        if (result > UINT_MAX) { return 0; }
        value /= 10;
    }
    
    // [-2147483648, 2147483647]
    if (isNegative) {
        return (int)(result > 2147483648 ? 0 : -result);
    } else {
        return (int)(result > 2147483647 ? 0 : result);
    }
}

int HFReverseIntegerSolution::reverse2(int x)
{
    unsigned value = x >= 0 ? x : (unsigned)(-(long)x);
    unsigned long result = 0;
    while (value) {
        result = result * 10 + value % 10;
        if (result > UINT_MAX) { return 0; }
        value /= 10;
    }
    
    // [-2147483648, 2147483647]
    if (x < 0) {
        return (int)(result > 2147483648 ? 0 : -result);
    } else {
        return (int)(result > 2147483647 ? 0 : result);
    }
}

int HFReverseIntegerSolution::reverse3(int x)
{
    unsigned value = x;
    short flag = 1;
    if (x < 0) { value = (unsigned)(-(long)x); flag = -1; }
    
    // [-2147483648, 2147483647]
    long result = 0;
    while (value) {
        result = result * 10 + (short)(value % 10) * flag;
        if (result > INT32_MAX || result < INT32_MIN) { return 0; }
        value /= 10;
    }
    return (int)result;
}
