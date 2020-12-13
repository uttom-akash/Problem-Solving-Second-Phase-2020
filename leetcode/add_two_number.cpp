#include<utility>
#include<iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    pair<int,int> getDigitSum(int a,int b,int c){
        if(a+b+c<10){
            return pair<int,int>(a+b+c,0);
        }else{
            return pair<int,int>((a+b+c)%10,(a+b+c)/10);    
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* root=new ListNode(0);
        ListNode* iter=root;

        while (l1 || l2)
        {
            int a=l1==nullptr ? 0 : l1->val;
            int b=l2==nullptr ? 0 : l2->val;
            auto sum=getDigitSum(a,b,carry);


            iter->next=new ListNode(sum.first);
            carry=sum.second;

            iter=iter->next,l1=l1->next,l2=l2->next;
            
        }
        if(carry){
            iter->next=new ListNode(carry);
        }
        return root->next;
    }
};
