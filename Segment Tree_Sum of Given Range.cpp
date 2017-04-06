//here index is 1 based
int input[100005]={0};
int SegTree[300005]={0};
int lazy[300005]={0};
//here node is equalent to "pos"
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        SegTree[node] = input[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        SegTree[node] = SegTree[2*node] + SegTree[2*node+1];
    }
}
//To update an element we need to look at the interval in which the element is 
//and recurse accordingly on the left or the right child.
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        input[idx] += val;
        SegTree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        SegTree[node] = SegTree[2*node] + SegTree[2*node+1];
    }
}
//If the range represented by a node is completely outside the given range, we will simply return 0.
//If the range represented by a node is completely inside the given range, we will return the value of the node which is the sum of all the elements in the range represented by the node.
//And if the range represented by a node is partially inside and partially outside the given range, we will return sum of the left child and the right child.
int query(int node, int start, int end, int l, int r)                 //sum of range
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return SegTree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
//Sometimes problems will ask you to update an interval from l to r, instead of a single element.
//we can modify the update function to work on an interval.
void updateRange(int node, int start, int end, int l, int r, int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;

    // Current node is a leaf node
    if (start == end)
    {
        // Add the difference to current node
        SegTree[node] += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);

    // Use the result of children calls to update this node
    SegTree[node] = SegTree[node*2] + SegTree[node*2+1];
}
//Let's be Lazy
//Since we have/will changed the update function to postpone the update operation, we will have to change the query function also.
void updateRangeLazy(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        //suppose there is update for arr[start] to arr[end] adding v so total added is (end-start+1)*v .
        //As in a segment tree a node (tree[node] )gives sum of array values it covers ,
        //so we updated tree node as tree[node]+=(end-start+1)*v ,later we will update left and right node
        // This node needs to be updated
        SegTree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        SegTree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRangeLazy(node*2, start, mid, l, r, val);        // Updating left child
    updateRangeLazy(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    SegTree[node] = SegTree[node*2] + SegTree[node*2+1];        // Updating root with max value 
}

int queryRangeLazy(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        SegTree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return SegTree[node];
    int mid = (start + end) / 2;
    int p1 = queryRangeLazy(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRangeLazy(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}