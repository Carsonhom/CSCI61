// I understand that the final exam for this class has been rescheduled to June 5 and 7 in class.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node;

class Link {
public:
  Link(Node* n1, Node* n2) : node1(n1), node2(n2) {};
  Node* node1;
  Node* node2;
};

class Node {
public:
  Node(int n) : id(n) {};
  Node() : id(0) {};
  
  void MarkAllConnected(vector<int>& connected) {
    if (mark != 0) return;
    connected.push_back(id);
    mark = 1;
    for (Link* k : links) {
      if (k->node1 == this) {
	k->node2->MarkAllConnected(connected);
      } else {
        k->node1->MarkAllConnected(connected);
      }
    }
  };

  void PrintNodesAtDist(int d) {
    cout << "Nodes at distance " << d << endl;
    queue<Node*> q;
    mark = 0;
    q.push(this);
    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();
      if (curr->mark == d) {
	cout << curr->id << " ";
      } else if (curr->mark < d) {
	for (Link* k : curr->links) {
	  Node* other = k->node1;
	  if (other == curr) {
	    other = k->node2;
	  }
	  if (other->mark < 0) {
	    other->mark = curr->mark + 1;
	    q.push(other);
	  }
	}
      }
    }
    cout << endl;
  };

  int id;
  int mark;
  vector<Link*> links;
};

#define NUM_NODES 32

class Graph {
public:
  Graph() {
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].id = i;
    }
  };
  void AddLink(int n1, int n2) {
    Link* ptr = new Link(&(nodes[n1]), &(nodes[n2]));
    nodes[n1].links.push_back(ptr);
    nodes[n2].links.push_back(ptr);
  };

  void FindConnectedComponents() {
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].mark = 0;
    }
    for (int i = 0; i < NUM_NODES; i++) {
      vector<int> connected;
      nodes[i].MarkAllConnected(connected);
      if (connected.size() > 1) {
	for (int i : connected) {
	  cout << i << " ";
	}
	cout << endl;
      }
    }
  };

  void PrintNodesAtDist(int d, int ind) {
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].mark = -1;
    }
    nodes[ind].PrintNodesAtDist(d);
  };

  // Implement this. You may write helper function in Graph or in Node.
  bool TwoColorable()
  {
    for(int i = 0; i < NUM_NODES; ++i)
    {
      nodes[i].mark = 0;
    }
    int currentmark = 1;
    for(int i = 0; i < NUM_NODES; ++i)
    {
      if(!nodes[i].links.empty() && nodes[i].mark < 1)
      {
        nodes[i].mark = currentmark;
        if(currentmark == 1)
        {
          currentmark = 2;
        } 
        else
        {
          currentmark = 1;
        }
        // cout << currentmark << "was a 0" << endl;
      }
      else if(!nodes[i].links.empty())
      {
        if(currentmark == nodes[i].mark && currentmark == 1)
        {
          currentmark = 2;
        } 
        else
        {
          currentmark = 1;
        }
        // cout << currentmark << "wasn't a 0" << endl;
      }
      // cout << nodes[i].id << endl;
      // if(nodes[i].mark < 1)
      // {
        // if(nodes[i] -> mark == currentmark || nodes)
        // {
        //   nodes[i].mark = currentmark;
        // }
        // vector<Link*>::iterator it;
        // for(it = nodes[i].links.begin(); it != nodes[i].links.end(); ++it)
        for (Link* it : nodes[i].links)
        {
          Node * lptr;
          if(it -> node1 -> id == nodes[i].id)
          {
            lptr = it -> node2;
          }
          else lptr = it -> node1;
          if(lptr -> mark == currentmark || lptr -> mark < 1)
          {
            lptr -> mark = currentmark;
            // cout << lptr -> mark << " " << lptr -> id << endl;
          }
          else
          {
            return false;
          }
        }
      // }
    }
    return true;
  };

  Node nodes[NUM_NODES];
};

int main() {
  Graph G;

  G.AddLink(1, 5);
  G.AddLink(5, 8);
  G.AddLink(2, 8);
  G.AddLink(1, 2);
  G.AddLink(8, 12);

  if (G.TwoColorable()) {
    cout << "Is Two Colorable" << endl;
  } else {
    cout << "Not Two Colorable" << endl;
  }

  G.AddLink(13, 14);
  G.AddLink(14, 15);
  G.AddLink(16, 15);
  G.AddLink(16, 17);
  G.AddLink(13, 17);

  if (G.TwoColorable()) {
    cout << "Is Two Colorable" << endl;
  } else {
    cout << "Not Two Colorable" << endl;
  }

  return 0;
}

/*
Is Two Colorable
Not Two Colorable
*/

