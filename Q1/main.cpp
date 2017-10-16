//
//  main.cpp
//  LeetCode7
//
//  Created by Jeff Zhao on 10/15/17.
//  Copyright © 2017 Jeff Zhao. All rights reserved.
//
//Q1: Two Sum
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//E.g.
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        // define an unordered_map to restore nums. Key is the number and value is the index in the vector.
        // use an unordered_map here is faster than map, because order is not required, but need a fast speed to retrieve individual value
        unordered_map<int, int> Hash;
        for (int i = 0; i < nums.size(); i++)
        {
            // calculate the number to find
            int numToFind = target - nums[i];
            // if the number to find is in the map, return the result
            if (Hash.find(numToFind) != Hash.end())
            {
                result.push_back(Hash[numToFind]);
                result.push_back(i);
                return result;
            }
            // if the number to find is not in the map, add this number into the map for future search
            Hash[nums[i]] = i;
        }

        // if no solution found
        throw invalid_argument("No Two Sum Solution");
    }
};

int main()
{
    // number list for test
    int numlist[] = {2, 7, 11, 15};
    vector<int>* nums = new vector<int> (numlist, numlist + sizeof(numlist)/sizeof(int));
    // target number, or the sum
    int target = 26;

    // define Solution object
    Solution solve;

    // Solve the result
    vector<int> result = solve.twoSum(*nums, target);

    // output result
    cout << "The contents of the results are:";
    for (vector<int>::iterator i = result.begin(); i != result.end(); ++i)
        cout << ' ' << *i ;
    cout << endl;

    return 0;
}
