#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(n2)
    Space Complexty - O(3*n) = O(n)
 */

struct Box {
    int l, b, h;
};

int max(int x, int y) {
    return (x > y) ? x : y;
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

//greater than symbol as we are sorting in decreasing order of base area
bool compare(Box b1, Box b2) {
    return (b1.l*b1.b) > (b2.l*b2.b);
}

void maxStackHeight(vector<Box> box, int n) {

    //create a vector to store the boxes in all 3 rotations. So the size is 3*n
    Box rotBox[3*n];
    int rotIndex = 0;
    for(int i=0;i<n;i++) {
        //original box
        rotBox[rotIndex].h = box[i].h;
        rotBox[rotIndex].l = max(box[i].l, box[i].b);
        rotBox[rotIndex].b = min(box[i].l, box[i].b);
        rotIndex++;

        //first rotation of box
        rotBox[rotIndex].h = box[i].l;
        rotBox[rotIndex].l = max(box[i].h, box[i].b);
        rotBox[rotIndex].b = min(box[i].h, box[i].b);
        rotIndex++;

        //second rotation of box
        rotBox[rotIndex].h = box[i].b;
        rotBox[rotIndex].l = max(box[i].l, box[i].h);
        rotBox[rotIndex].b = min(box[i].l, box[i].h);
        rotIndex++;
    }

    //sort in decreasing order of base area
    n=3*n;
    sort(rotBox, rotBox+n, compare);

    //vector to store the max height of the stack if box i is on top
    vector<int> maxHeightWithBoxOnTop(n);
    for(int i=0;i<n;i++) {
        maxHeightWithBoxOnTop[i] = rotBox[i].h;
    }

    //vector to store the position of the box i.e.. on top of which index can the box be kept
    vector<int> boxPositions(n);
    for(int i=0;i<n;i++) {
        boxPositions[i] = i;
    }

    //simialr to longest increasing subsequence
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(rotBox[i].l < rotBox[j].l && rotBox[i].b < rotBox[j].b)  {
                maxHeightWithBoxOnTop[i] = max(maxHeightWithBoxOnTop[i], maxHeightWithBoxOnTop[j] + rotBox[i].h);
                boxPositions[i] = j;
            }
        }
    }

    int max = 0, index = -1;
    for(int i=0;i<n;i++) {
        if(maxHeightWithBoxOnTop[i] > max) {
            max = maxHeightWithBoxOnTop[i];
            index = i;
        }
    }
    cout<<"The maximum height is "<<max<<"\n";
    cout<<"The boxes are to be placed in the following order:\n";
    while(index != boxPositions[index]) {   
        cout<<rotBox[index].l<<" "<<rotBox[index].b<<" "<<rotBox[index].h<<"\n";
        index = boxPositions[index];
    }
    cout<<rotBox[index].l<<" "<<rotBox[index].b<<" "<<rotBox[index].h<<"\n";
}

int main() {
    vector<Box> box = //{{1,2,4}, {3,2,5}};
    {{4,6,7}, {1,2,3}, {4,5,6}, {10,12,32}};
    int n = box.size();
    maxStackHeight(box, n);
}