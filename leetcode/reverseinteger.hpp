//
//  reverseinteger.hpp
//  leetcode
//
//  Created by HavenLin on 2019/9/1.
//  Copyright © 2019 Haven·Lin. All rights reserved.
//

#ifndef reverseinteger_hpp
#define reverseinteger_hpp

#include "solution.hpp"


namespace leetcode
{
    /**
     *  https://leetcode-cn.com/problems/reverse-integer
     *
     *  7. 整数反转
     *
     *  给出一个32位的有符号整数，你需要将这个整数中每位上的数字进行反转。
     *
     *  示例 1:
     *      输入: 123
     *      输出: 321
     *
     *  示例 2:
     *      输入: -123
     *      输出: -321
     *
     *  示例 3:
     *      输入: 120
     *      输出: 21
     *
     *  注意:
     *      假设我们的环境只能存储得下32位的有符号整数，则其数值范围为[−2^31, 2^31−1]。
     *      请根据这个假设，如果反转后整数溢出那么就返回0。
     */
    class HFReverseIntegerSolution : HFSolution
    {
    private:
        struct TestParam {
            int x;
            int expect;
        };
        std::vector<TestParam> testParams();
        
    public:
        void testReverse();
        
        int reverse(int x);
        int reverse2(int x);
        int reverse3(int x);
    };
}

#endif /* reverseinteger_hpp */
