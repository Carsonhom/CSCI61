#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node;

class Link {
public:
  int distance;
  Node* node1;
  Node* node2;
  Link(int d, Node* n1, Node* n2) : distance(d), node1(n1), node2(n2) {};
};

class Node {
private:
  string city;
  // (a) [40 points] Change links from vector<Link*> to
  // unordered_map<string, Link*>, a map from the name of the other city to
  // Link*.
  // Then change the implementation of AddLink and PrintConnectedCities
  // accordingly.
  // Basically uncomment the following line and comment the line after.
  unordered_map<string, Link*> links;
  // vector<Link*> links;
public:
  Node() : city("") {};
  Node(string str) : city(str) {};
  string GetCity() { return city; };

  // (a) Change this to AddLink(const string& other_city_name, Link* link).
  // Make sure you change the calls to this function in Graph::AddLink.
  void AddLink(const string& other_city_name, Link* link) {
    if(link -> node1 -> city == city)
    {
      links[link -> node2 -> city] = link; 
    }
    else
    {
      links[link -> node1 -> city] = link;
    }
    // links.push_back(link);
  };

  void RemoveLink(string city) //Helper function I added
  {
    unordered_map<string, Link*>::iterator it = links.find(city);
    if(it == links.end())
    {
      return;
    }
    it = links.erase(it);
  }

  // (a) Change this.
  void PrintConnectedCities() {
    unordered_map<string, Link*>::iterator it;
    for(it = links.begin(); it != links.end(); it++)
    {
      if(it -> second -> node1 == this)
      {
        cout << it -> second -> node2 -> city << endl;
      }
      else
      {
        cout << it -> second -> node1 -> city << endl;
      }
    }
  };
};

class Graph {
public:
  unordered_map<string, Node> nodes;

  Graph() {
    vector<string> city_names =
      { "San Francisco", "Seattle", "Portland", "Los Angeles", "San Diego",
	"Salt Lake City", "Phoenix", "Denver", "St. Louis", "New Orleans",
	"Houston", "San Antonio", "Dallas", "Austin", "Minneapolis", "Chicago",
	"Las Vegas", "Tucson", "Kansas City", "Nashville", "Charlotte", 
	"Indianapolis", "New York", "Washington", "Philadelphia", "Boston",
	"Miami", "Fort Lauderdale", "Orlando", "Atlanta", "Charleston",
	"Richmond", "Raleigh" };
    for (int i = 0; i < city_names.size(); i++) {
      nodes[city_names[i]] = (Node(city_names[i]));
    }
  };

  void AddLink(string c1, string c2, int d) {
    unordered_map<string, Node>::iterator it1 = nodes.find(c1);
    unordered_map<string, Node>::iterator it2 = nodes.find(c2);
    if ((it1 == nodes.end()) || (it2 == nodes.end())) return;
    Link* link = new Link(d, &((*it1).second), &((*it2).second));
    // (a) Change the calls to Node::AddLink.
    (*it1).second.AddLink(c2, link);
    (*it2).second.AddLink(c1, link);
  };

  // (b) [40 points] Write a RemoveLink function that will remove the link
  // between the two named cities, if such a link exists.
  // Make sure you remove them from both nodes.
  // Make sure you free the space on the memory heap so that
  // there is no memory leak.
  // You may write helper functions in the Node class as you need.
  // Implement it assuming that you have done Question (a).
  void RemoveLink(string c1, string c2)
  {
    unordered_map<string, Node>::iterator it1 = nodes.find(c1);
    unordered_map<string, Node>::iterator it2 = nodes.find(c2);
    if((it1 == nodes.end()) || (it2 == nodes.end()))
    {
      return;
    }
    it1 -> second.RemoveLink(c2);
    it2 -> second.RemoveLink(c1);
  }

  // (c) [20 points] Write a destructor for the Graph class, to free
  // all the dynamically allocated memory for all the links.
  // You may write helper functions in the Node class as you need.
  ~Graph() 
  {
    unordered_map<string, Node>::iterator it1;
    unordered_map<string, Node>::iterator it2;
    for(it1 = nodes.begin(); it1 != nodes.end(); it1++)
    {
      for(it2 = nodes.begin(); it2 != nodes.end(); it2++)
      {
        string c1 = it1 -> second.GetCity();
        string c2 = it2 -> second.GetCity();
        RemoveLink(c1, c2);
      }
    }
    // cout << "Before" << endl;
    // for(it1 = nodes.begin(); it1 != nodes.end(); it1++)
    // {
    //   cout << it1 -> first << endl;
    // }
    nodes.clear();
    // cout << "After" << endl;
    // for(it1 = nodes.begin(); it1 != nodes.end(); it1++)
    // {
    //   cout << it1 -> first << endl;
    // }
  };

  

  void PrintConnectedCities(string city) {
    unordered_map<string, Node>::iterator it = nodes.find(city);
    if (it != nodes.end()) {
      (*it).second.PrintConnectedCities();
    }
  };
};

int main() {
  Graph g;

  g.AddLink("San Diego", "Chicago", 3000);
  g.AddLink("Chicago", "Washington", 500);
  // g.RemoveLink("San Diego", "Chicago");

  g.PrintConnectedCities("Chicago");

  return 0;
}

