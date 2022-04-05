# Binary Search in forest
## Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">There are n trees in a forest. The heights of the trees is stored in array <strong>tree[],&nbsp;</strong>where <strong>tree[i]</strong>&nbsp;denotes the height of the&nbsp;<strong>i<sup>th</sup></strong>&nbsp;tree in the&nbsp;forest</span><span style="font-size:18px">. If the&nbsp;<strong>i<sup>th</sup></strong>&nbsp;tree is cut at a height <strong>H</strong>, then the&nbsp;wood collected is <strong>tree[i] - H</strong>, provided&nbsp;<strong>tree[i] &gt; H</strong>. If the total woods that needs to be collected is exactly equal to&nbsp;<strong>k</strong>,&nbsp;find the height&nbsp;<strong>H</strong> at which every tree should be cut (all trees have to be cut at the same height).&nbsp;If it is not possible then return&nbsp;<strong>-1</strong>&nbsp;else return <strong>H</strong>.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 5, k = 4
nums[] = {2, 3, 6, 2, 4}
<strong>Output: </strong>3<strong>
Explanation: </strong>Wood collected by cutting trees
at height 3 = 0 + 0 + (6-3) + 0 + (4-3) = 4
hence 3 is to be subtracted from all numbers.
Since 2 is lesser than 3, nothing gets
subtracted from it.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 6, k = 8
nums[] = {1, 7, 6, 3, 4, 7}
<strong>Output: </strong>4<strong>
</strong><strong>Explanation: </strong>Wood collected by cutting trees
at height 4 = 0+(7-4)+(6-4)+0+0+(7-4) = 8</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete the function <strong>find_height()</strong>. This function takes the array <strong>tree[ ]</strong>, and the integers <strong>n</strong> and <strong>k</strong> as input parameters and returns the height at which trees have to be cut. If no positive integer value of height is possible, return <strong>-1</strong>.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n&nbsp;log h)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:&nbsp;</strong><br>
1 &lt;= n &lt;= 10<sup>4</sup><br>
1 &lt;= tree[i] &lt;= 10<sup>3</sup><br>
1 &lt;= k &lt;= 10<sup>7</sup></span></p>
 <p></p>
            </div>