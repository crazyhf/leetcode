//
//  longestsubstrnorepeatchar.cpp
//  leetcode
//
//  Created by HavenLin on 2019/8/29.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#include "longestsubstrnorepeatchar.hpp"
#include <map>
#include <set>

using namespace std;
using namespace leetcode;


vector<HFLongestSubstrNoRepeatCharSolution::TestParam> HFLongestSubstrNoRepeatCharSolution::testParams()
{
    vector<TestParam> paramVec;
    
    paramVec.push_back({ .s="abcabcbb", .expect=3 });
    paramVec.push_back({ .s="bbbbb", .expect=1 });
    paramVec.push_back({ .s="pwwkew", .expect=3 });
    paramVec.push_back({ .s="dvdf", .expect=3 });
    return paramVec;
}

void HFLongestSubstrNoRepeatCharSolution::testLenOfLongestSubstr()
{
    cout << "===============================================" << endl
         << "HFLongestSubstrNoRepeatCharSolution (3. 无重复字符的最长子串) :" << endl
         << "给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。" << endl;
    
    vector<TestParam> paramVec = testParams();
    for (size_t idx = 0; idx < paramVec.size(); idx++) {
        TestParam param = paramVec[idx];
        int result = lenOfLongestSubstr2(param.s);
        cout << endl << "Input : " << param.s << endl
             << "Output: " << result << endl
             << "Expect: " << param.expect << endl;
    }
    
    cout << "===============================================" << endl << endl;
}


/// ======================================================================

int HFLongestSubstrNoRepeatCharSolution::lenOfLongestSubstr(string s)
{
    map<char, size_t> auxMap;
    int result = 0, length = 0;
    for (size_t idx = 0; idx < s.length(); idx++) {
        map<char, size_t>::const_iterator ite = auxMap.find(s[idx]);
        if (auxMap.end() == ite) {
            auxMap[s[idx]] = idx;
            length++;
        } else {
            idx = ite->second;
            if (length > result) {
                result = length;
            }
            length = 0;
            auxMap.clear();
        }
    }
    return (length > result ? length : result);
}

int HFLongestSubstrNoRepeatCharSolution::lenOfLongestSubstr2(string s)
{
    map<char, int> auxMap;
    int result = 0, startIdx = 0;
    for (int idx = 0; idx < s.length(); idx++) {
        map<char, int>::iterator ite = auxMap.find(s[idx]);
        if (auxMap.end() == ite) {
            auxMap[s[idx]] = idx;
        } else {
            if (ite->second >= startIdx) {
                if (idx - startIdx > result) {
                    result = idx - startIdx;
                }
                startIdx = ite->second + 1;
            }
            ite->second = idx;
        }
    }
    return ((int)s.length() - startIdx > result ? (int)s.length() - startIdx : result);
}
