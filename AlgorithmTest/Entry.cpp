#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
namespace AT1 {
	auto printVecInt = [](vector<int> vec)->void {
		for (int i = 0; i < vec.size(); i++)
			printf("%d\n", vec[i]);
	};

	/*** 整形反序 ***/
	int reverse(int x)
	{
		int result = 0;

		while (x != 0)
		{
			int tail = x % 10;
			int newResult = result * 10 + tail;
			if ((newResult - tail) / 10 != result)
			{
				return 0;
			}
			result = newResult;
			x = x / 10;
		}

		return result;
	}
	//https://leetcode.com/problems/reverse-integer 
	void test1()
	{
		std::cout << reverse(123) << std::endl;
	}

	//---------------------------------------------------------------
	/* 查找重复元素
	// when find a number i, flip the number at position i-1 to negative.
	// if the number at position i-1 is already negative, i is the number that occurs twice.
	*/
	vector<int> findDuplicates(vector<int> nums)
	{
		vector<int> retVec;
		for (int i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1;
			if (nums[index] < 0)
				retVec.push_back(abs(index + 1));
			nums[index] = -nums[index];
		}
		return retVec;
	}

	/* Firstly, we put each element x in nums[x - 1]. Since x ranges from 1 to N, then x - 1 ranges from 0 to N - 1, it won't exceed the bound of the array.
	Secondly, we check through the array. If a number x doesn't present in nums[x - 1], then x is absent.
	*/
	vector<int> findDuplicates2(vector<int>& nums) {
		vector<int> res;
		int i = 0;
		while (i < nums.size()) {
			if (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
			else i++;
		}
		for (i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1) res.push_back(nums[i]);
		}
		return res;
	}

	//https://leetcode.com/problems/find-all-duplicates-in-an-array/?tab=Description
	void test2()
	{
		vector<int> srcVec = { 4,3,2,7,8,2,3,1 };
		printVecInt(findDuplicates2(srcVec));
	}

	//---------------------------------------------------------------
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.size();) {
			if (s.size() - i <= max_len / 2) break;
			int j = i, k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
	}

	//https://discuss.leetcode.com/topic/12187/simple-c-solution-8ms-13-lines
	//查找最长的回文子字符串 
	void test3()
	{
		string src = "bababd";
		string str = longestPalindrome(src);
		printf("%s\n", str.c_str());
	}

	//---------------------------------------------------------------
	/*
	 def median(A, B):
	m, n = len(A), len(B)
	if m > n:
		A, B, m, n = B, A, n, m
	if n == 0:
		raise ValueError

	imin, imax, half_len = 0, m, (m + n + 1) / 2
	while imin <= imax:
		i = (imin + imax) / 2
		j = half_len - i
		if i < m and B[j-1] > A[i]:
			# i is too small, must increase it
			imin = i + 1
		elif i > 0 and A[i-1] > B[j]:
			# i is too big, must decrease it
			imax = i - 1
		else:
			# i is perfect

			if i == 0: max_of_left = B[j-1]
			elif j == 0: max_of_left = A[i-1]
			else: max_of_left = max(A[i-1], B[j-1])

			if (m + n) % 2 == 1:
				return max_of_left

			if i == m: min_of_right = B[j]
			elif j == n: min_of_right = A[i]
			else: min_of_right = min(A[i], B[j])

			return (max_of_left + min_of_right) / 2.0
	*/

	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	//	int m = nums1.size();
	//	int n = nums2.size();
	//}

	//https://leetcode.com/problems/median-of-two-sorted-arrays/#/solutions
	// 两个已排序的数组的中位数
	//void test3() {

	//}


	//---------------------------------------------------------------
	class ListNode {
	public:
		int val = 0;
		ListNode* next = nullptr;
	};
	auto printList = [](ListNode* node) -> void {
		while (node != nullptr) {
			printf("%d ->", node->val);
			node = node->next;
		}
		printf("\n");
	};

	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}

	//https://leetcode.com/problems/merge-two-sorted-lists/#/solutions
	//合并两个有序链表
	void test4() {
		ListNode* n1 = new ListNode();
		n1->val = 1;
		ListNode* n2 = new ListNode();
		n2->val = 2;
		ListNode* n3 = new ListNode();
		n3->val = 6;
		ListNode* n4 = new ListNode();
		n4->val = 9;
		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		printList(n1);

		ListNode* n5 = new ListNode();
		n5->val = 4;
		ListNode* n6 = new ListNode();
		n6->val = 7;
		ListNode* n7 = new ListNode();
		n7->val = 8;
		ListNode* n8 = new ListNode();
		n8->val = 10;
		n5->next = n6;
		n6->next = n7;
		n7->next = n8;
		printList(n5);

		ListNode* n9 = mergeTwoLists(n1, n5);
		printList(n9);
	}

	//---------------------------------------------------------------
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* start = new ListNode();
		ListNode* slow = start;
		ListNode* fast = start;
		slow->next = head;

		//Move fast in front so that the gap between slow and fast becomes n
		for (int i = 1; i < n+1; i++) {
			fast = fast->next;
		}

		//Move fast to the end, maintaining the gap
		while (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}

		//Skip the desired node
		slow->next = slow->next->next;
		return start->next;
	}

	//https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/solutions
	//移除链表中倒数第二个节点
	void test5() {
		ListNode* n1 = new ListNode();
		n1->val = 1;
		ListNode* n2 = new ListNode();
		n2->val = 2;
		ListNode* n3 = new ListNode();
		n3->val = 6;
		ListNode* n4 = new ListNode();
		n4->val = 9;
		ListNode* n5 = new ListNode();
		n5->val = 4;
		ListNode* n6 = new ListNode();
		n6->val = 7;
		ListNode* n7 = new ListNode();
		n7->val = 8;
		ListNode* n8 = new ListNode();
		n8->val = 10;

		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		n5->next = n6;
		n6->next = n7;
		n7->next = n8;

		printList(n1);

		removeNthFromEnd(n1, 2);
		printList(n1);
	}

	//---------------------------------------------------------------

	//https://leetcode.com/problems/swap-nodes-in-pairs/#/solutions
	//成对交换相邻的两个节点

	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* n = head->next;
		head->next = swapPairs(head->next->next);
		n->next = head;
		return n;
	}

	void test6() {
		ListNode* n1 = new ListNode();
		n1->val = 1;
		ListNode* n2 = new ListNode();
		n2->val = 2;
		ListNode* n3 = new ListNode();
		n3->val = 3;
		ListNode* n4 = new ListNode();
		n4->val = 4;
		ListNode* n5 = new ListNode();
		n5->val = 5;

		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		printList(n1);

		ListNode* nx = swapPairs(n1);
		printList(nx);
	}

	void main() {
		//AT1::test1();
		//AT1::test2();
		//AT1::test3();
		//AT1::test4();
		//AT1::test5();
		AT1::test6();
	}
};


