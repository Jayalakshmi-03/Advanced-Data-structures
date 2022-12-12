#include<iostream>
using namespace std;

class Set {

    public:

    int data;
    int rank;
    Set* parent;

    Set (int d){
        data = d;
        rank = 0;
        parent = this;
        cout << "Created set:" << data << "  Parent:" << parent->data <<  "  Rank:" << rank << endl;
    }

    Set* FindParent (Set& );
    void Union (Set&, Set&);
};

// FindParent applies path compression to all the nodes in the search path of the parent
// without changing their ranks.
Set* FindParent (Set& s) {
    if ( s.data == s.parent->data )
        return s.parent;
    else
        return FindParent (*(s.parent));
}

// Union operation makes use of heuristic union-by-rank.
void Union (Set& a, Set& b) {

    Set* parent_of_a = FindParent(a);
    Set* parent_of_b = FindParent(b);

    if ( parent_of_a->data != parent_of_b->data )
    {
        if ( a.rank < b.rank )
        {
          a.parent = parent_of_b;
          b.rank += 1;
        }
        else
        {
          b.parent = parent_of_a;
          a.rank += 1;
        }
    }

    cout << "\nUNION OF " << a.data << " & " << b.data << endl;
    cout << "\tRank of : " << a.data << " = " << a.rank << endl;
    cout << "\tParent of : " << a.data << " = " << a.parent->data << endl;
    cout << "\tRank of : " << b.data << " = " << b.rank << endl;
    cout << "\tParent of : " << b.data << " = " << b.parent->data << endl;
}

int main() {

    // Initially every node in a set has a rank 0 and is a parent of itself
    Set s1(1);
    Set s2(2);
    Set s3(3);
    Set s4(4);
    Set s5(5);
    Set s6(6);
    Set s7(7);
    Set s8(8);
    Set s9(9);
    Set s10(10);

    Union (s1, s3);
    Union (s2, s4);
    Union (s3, s5);
    Union (s4, s6);
    Union (s1, s6);

    return 0;
}
