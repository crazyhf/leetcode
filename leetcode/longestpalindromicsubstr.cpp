//
//  longestpalindromicsubstr.cpp
//  leetcode
//
//  Created by HavenLin on 2019/8/29.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "longestpalindromicsubstr.hpp"

using namespace std;
using namespace leetcode;


vector<HFLongestPalindromicSubstrSolution::TestParam> HFLongestPalindromicSubstrSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .s="babad", .expect="bab" });
    paramVec.push_back({ .s="cbbd", .expect="bb" });
    return paramVec;
}

void HFLongestPalindromicSubstrSolution::testLongestPalindrome()
{
    cout << "===============================================" << endl
         << "HFLongestPalindromicSubstrSolution (5. 最长回文子串) :" << endl
         << "给定一个字符串s，找到s中最长的回文子串。你可以假设s的最大长度为1000。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        string result = longestPalindrome(param.s);
        cout << endl << "Input : " << param.s << endl
             << "Output: " << result << endl
             << "Expect: " << param.expect << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

string HFLongestPalindromicSubstrSolution::longestPalindrome(string s)
{
    string newStr(s.size() * 2 + 1, '#');
    for (size_t idx = 0; idx < s.length(); idx++) {
        newStr[idx * 2 + 1] = s[idx];
    }
    
    vector<int> p(newStr.size(), 0);
    int result = 0, radius = 1, centerIdx = 0, maxIdx = 0;
    for (int idx = 0; idx < newStr.length(); idx++) {
        p[idx] = idx < maxIdx ? min(p[2 * centerIdx - idx], maxIdx - idx) : 1;
        while (idx - p[idx] >= 0 && idx + p[idx] < newStr.length()) {
            if (newStr[idx - p[idx]] == newStr[idx + p[idx]]) { p[idx]++; }
            else break;
        }
        if (idx + p[idx] > maxIdx) {
            centerIdx = idx; maxIdx = idx + p[idx];
        }
        if (p[idx] > radius) { result = idx; radius = p[idx]; }
    }
    return s.substr((result - radius + 1) / 2, radius - 1);
}
