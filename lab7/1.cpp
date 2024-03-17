// linearsearch
// public static int linearsearch(int[] a,int value){

// int n=a.length() for(int i=0; i<n; i++){if(a[i]==value){return i;}} return -1;

//binary search

// public static ont binarysearch(int[] a,int value){
//     int lowindex=0;
//     int high=a.length();
//     while(lowindex<=high){
//         mid=high+lowindex/2
//         if(value<a[mid]){
//             high=mid-1;
//         }else if(value>a[mid]){
//             lowindex=mid+1;
//         }else{
//             return mid;
//         }
//     }
//     return -1;
// }

// struct Node{
//     type data;
//     Node* left;
//     Node* right;
// }
// void insert(head,newdata){
//     newnode= new Node;
//     newNode.data=newdata;
//     newNode.left=NULL;
//     newNode.right=NULL;

//     if(head is NULL){
//         head=newNode
//         return head
//     }
//     current=head;
//     while current.right is not NULL{
//         current=current.right
//     }
//     current.right=newNode
//     newNode.left=current 
//     return head

// }