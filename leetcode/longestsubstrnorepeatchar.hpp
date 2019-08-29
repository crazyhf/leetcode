//
//  longestsubstrnorepeatchar.hpp
//  leetcode
//
//  Created by HavenLin on 2019/8/29.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef longestsubstrnorepeatchar_hpp
#define longestsubstrnorepeatchar_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
     *
     *  3. 无重复字符的最长子串
     *
     *  给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
     *
     *  示例 1:
     *      输入: "abcabcbb"
     *      输出: 3
     *      解释: 因为无重复字符的最长子串是"abc"，所以其长度为3。
     *
     *  示例 2:
     *      输入: "bbbbb"
     *      输出: 1
     *      解释: 因为无重复字符的最长子串是"b"，所以其长度为1。
     *
     *  示例 3:
     *      输入: "pwwkew"
     *      输出: 3
     *      解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     *           请注意，你的答案必须是子串的长度，"pwke"是一个子序列，不是子串。
     */
    class HFLongestSubstrNoRepeatCharSolution : HFSolution
    {
    private:
        struct TestParam {
            std::string s;
            int expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testLenOfLongestSubstr();
        
        int lenOfLongestSubstr(std::string s);
        
        int lenOfLongestSubstr2(std::string s);
    };
}

#endif /* longestsubstrnorepeatchar_hpp */
