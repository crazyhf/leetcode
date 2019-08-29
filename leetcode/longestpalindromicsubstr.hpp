//
//  longestpalindromicsubstr.hpp
//  leetcode
//
//  Created by HavenLin on 2019/8/29.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef longestpalindromicsubstr_hpp
#define longestpalindromicsubstr_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/longest-palindromic-substring
     *
     *  5. 最长回文子串
     *
     *  给定一个字符串s，找到s中最长的回文子串。你可以假设s的最大长度为1000。
     *
     *  示例 1：
     *      输入: "babad"
     *      输出: "bab"
     *      注意: "aba" 也是一个有效答案。
     *
     *  示例 2：
     *      输入: "cbbd"
     *      输出: "bb"
     */
    class HFLongestPalindromicSubstrSolution : HFSolution
    {
    private:
        struct TestParam {
            std::string s;
            std::string expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testLongestPalindrome();
        
        std::string longestPalindrome(std::string s);
    };
}

#endif /* longestpalindromicsubstr_hpp */
