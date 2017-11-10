/*
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
 ** 这种题目最直观的方法就是暴力破解，使用两层循环直接进行求解,代码如下：
 */

vector<int> twosum(vector<int> &nums, int target)
{
    vector <int> result;
    for(int i = 0; i < nums.length; ++i)
    {
        for(int j = i+1; j < nums.length; ++j)
        {
            if(nums[j] == target - nums[i])
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
}
/*
 ** For each element, we try to find its complement by looping through the rest of array which takes O(n)O(n) time.
 Therefore, the time complexity is O(n^2)
 */

/*
 *   提高的方式是借助哈希表将下表存储在哈希表中来解决冲突，代码如下：
 */
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) 
    {
        int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) 
        {
            //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);    
            result.push_back(i + 1);                   
            return result;
        }
        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}
