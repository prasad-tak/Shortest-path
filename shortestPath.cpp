//

#include <iostream>
#include <list>
#include <utility>
#include <map>
using namespace std;

class node{
    public:
    string name;
    string type;
    list<pair<node*,int>> neig; //list of neighbours and their distances
    
    node(string b, string a){
        type = b;
       
        name = a;
    }

};

class graph{
    
map <string,node*> l; //list of units

public:
void addNode(string a, string b){
    
    l[b] = new node(a,b);

}

// view function to view all the nodes in the fraph along with it's neighbours
void veiw(){ 
    auto i = l.begin();
    while(i!= l.end()){
    string s = i->first;
    cout << l[s]->type << " name- " << l[s]->name <<":" << endl;
    
    auto it = l[s]->neig.begin();
    while(it!= l[s]->neig.end()){
        cout << it->first->name << " (" << it->second << "kms) " <<endl;
        ++it;
    }++i;
    }
}
void addEdge(string a, string b,int x, bool undir = true){

   
    l[a]->neig.push_back({l[b],x});
    if(undir){
         l[b]->neig.push_back({l[a],x});
    }

}

//function to calculate the shortest path

void shortestPath(string a, string b){
string x, y;
int sum{INT16_MAX};
auto it = l[a]->neig.begin();
while(it!=l[a]->neig.end()){
        
    auto i = it->first->neig.begin();
    while(i != it->first->neig.end()){
        if(i->first->type == "SmallWarehouse"){ int path{it->second};
        path += i->second;
         
        auto ir = i->first->neig.begin();
        while(ir!= i->first->neig.end()){
           if(ir->first->type != "BigWarehouse") {if(ir->first->name==b){
                
                path += ir->second;
               
            }}
            ++ir;
        }if(path <= sum){
            sum = path;
            x = it->first->name;
            y = i->first->name;
        }}
        ++i;
    }
++it;
}cout << a << " -> " << x << " -> " << y << " -> " << b << endl; // the required path

}
   
};

int main(){
graph g;
//Manufacturers:
g.addNode("Manufacturer","JK");
g.addNode("Manufacturer","NKG");
g.addNode("Manufacturer","SMV");
g.addNode("Manufacturer","BGL");

//Big Warehouses:
g.addNode("BigWarehouse","BG1");
g.addNode("BigWarehouse","BG2");
g.addNode("BigWarehouse","BG3");
g.addNode("BigWarehouse","BG4");
g.addNode("BigWarehouse","BG5");

//Small Warehouses:
g.addNode("SmallWarehouse","SM1");
g.addNode("SmallWarehouse","SM2");
g.addNode("SmallWarehouse","SM3");
g.addNode("SmallWarehouse","SM4");
g.addNode("SmallWarehouse","SM5");

//Distributers:
g.addNode("Distributers","NSL");
g.addNode("Distributers","CCL");
g.addNode("Distributers","LKL");
g.addNode("Distributers","PCL");

//Manufacturer to Big Warehouses:
g.addEdge("JK","BG1",20);
g.addEdge("JK","BG2",25);
g.addEdge("JK","BG3",47);
g.addEdge("JK","BG4",36);
g.addEdge("JK","BG5",40);

g.addEdge("NKG","BG1",50);
g.addEdge("NKG","BG2",27);
g.addEdge("NKG","BG3",15);
g.addEdge("NKG","BG4",40);
g.addEdge("NKG","BG5",55);

g.addEdge("SMV","BG1",40);
g.addEdge("SMV","BG2",45);
g.addEdge("SMV","BG3",55);
g.addEdge("SMV","BG4",25);
g.addEdge("SMV","BG5",18);

g.addEdge("BGL","BG1",45);
g.addEdge("BGL","BG2",40);
g.addEdge("BGL","BG3",45);
g.addEdge("BGL","BG4",15);
g.addEdge("BGL","BG5",40);

//Big Warehouses to Small Warehouses
g.addEdge("BG1","SM1",15);
g.addEdge("BG1","SM2",35);
g.addEdge("BG1","SM3",45);
g.addEdge("BG1","SM4",55);
g.addEdge("BG1","SM5",42);

g.addEdge("BG2","SM1",25);
g.addEdge("BG2","SM2",14);
g.addEdge("BG2","SM3",15);
g.addEdge("BG2","SM4",25);
g.addEdge("BG2","SM5",42);

g.addEdge("BG3","SM1",45);
g.addEdge("BG3","SM2",30);
g.addEdge("BG3","SM3",12);
g.addEdge("BG3","SM4",25);
g.addEdge("BG3","SM5",55);

g.addEdge("BG4","SM1",23);
g.addEdge("BG4","SM2",10);
g.addEdge("BG4","SM3",40);
g.addEdge("BG4","SM4",25);
g.addEdge("BG4","SM5",18);

g.addEdge("BG5","SM1",25);
g.addEdge("BG5","SM2",32);
g.addEdge("BG5","SM3",50);
g.addEdge("BG5","SM4",50);
g.addEdge("BG5","SM5",28);

//Small Warehouses to Distributers
g.addEdge("SM1","NSL",8);
g.addEdge("SM1","CCL",30);
g.addEdge("SM1","PCL",35);
g.addEdge("SM1","LKL",25);

g.addEdge("SM2","NSL",15);
g.addEdge("SM2","CCL",12);
g.addEdge("SM2","PCL",25);
g.addEdge("SM2","LKL",30);

g.addEdge("SM3","NSL",28);
g.addEdge("SM3","CCL",25);
g.addEdge("SM3","PCL",42);
g.addEdge("SM3","LKL",55);

g.addEdge("SM4","NSL",38);
g.addEdge("SM4","CCL",18);
g.addEdge("SM4","PCL",22);
g.addEdge("SM4","LKL",45);

g.addEdge("SM5","NSL",40);
g.addEdge("SM5","CCL",35);
g.addEdge("SM5","PCL",15);
g.addEdge("SM5","LKL",25);







string manu, distr;
cout << "Enter the name of the Manufacturer:";
cin >> manu;

cout << "Enter the name of the Distributer:";
cin >> distr;

g.shortestPath(manu,distr);

return 0;
}