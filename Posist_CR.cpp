#include <bits/stdc++.h>
using namespace std;

//Defining the schema for a basic Node.

struct Data {
    int ownerId;
    float value;
    char owner_name[50];

};

struct node {
	public:
    time_t time_now ;
    string time_in_date;   // to convert timestamp to user readable date using strftime()
    Data *data ;
    string nodeId ;
    int nodeNumber ;
    node *referenceNodeid ;

    std::vector<node *> childReferenceNodeid;                 // Array of addresses.

    node *genesisReferenceNodeid;
    unordered_map<int> HashValue;         // Hash of value of the set.

    bool isEncrypted;                       //Will block access to node if it has been encrypted.
    string password;

	int available;			//value that can be assigned to siblings

};

// TASK 1
//Creating the ROOT Node (genesis node)
node createGenesisNode(int node_number){

   node *n = new node ;
   n->time_now = time(0);    // Get current timestamp

   n->nodeNumber = node_number;
   n->nodeId = to_string(nodeNumber);
   cout<<"Enter DATA";
   cin>>n->data->ownerId;
   cin>>n->data->value;
   gets(n->data->owner_name);

   n->referenceNodeid = NULL;
   n->genesisReferenceNodeid = &n;   // genesis node is created update address.
   n->HashValue = {n->time_now,n->data,n->nodeNumber,n->referenceNodeid,n->childReferenceNodeid,n->genesisReferenceNodeid}

	n->available=data->value;
	
	cout<<"Root node created"<<endl;
	
 return n;                  // return address of genesis node for future purposes.
}

// TASK 2 and 3 can be achieved here
// Create set of child nodes for a given node, which we are finding using,
// node_number to query genesis node child nodes.
void addChildNode(int node_number,node *genesis, int current_node_number){

    node *l = *(genesis->childReferenceNodeid[node_number]);

    int i=1;
    while(i){
       node *p = new node;
		 no++;
         p->nodeNumber = current_node_number;
         p->nodeId = to_string(nodeNumber);
            cout<<"Enter DATA";
        cin>>p->data->ownerId;
        cin>>p->data->value;
        gets(p->data->owner_name);
        n->referenceNodeid = &l ;      //This node's parent address will be &l
        n->genesisReferenceNodeid = &genesis;   //copying genesis node address we received.
        n->HashValue = {n->time_now,n->data,n->nodeNumber,n->referenceNodeid,n->childReferenceNodeid,n->genesisReferenceNodeid}
		l->available-=data->value;
		n->available=data->value;
        cout<<"Add more (1/0)";
        cin>>i;
    }
    cout<<"Added successfully \n";
}

// TASK 3/4 Encrypting and Decrypting the data using a key.
void encrypt(node *n){

    n->isEncrypted = true;
    cout<<"Enter owner password";
    cin>>n->password;

    //Using a basic approach to encrypt by subtracting some value from ASCII of character.
    for(i = 0; (i < 100 && n->password[i] != '\0'); i++){
    	n->password[i] = n->password[i] + 2;
	}
	
    return;
}

// TASK 5 Would take the address of node and a password string and return true if passwords match;
int decrypt(node *given_node,string pass){


        for(i = 0; (i < 100 && pass[i] != '\0'); i++)
        n->pass[i] = n->pass[i] + 2;

        if(given_node->password == pass){
            return 1;
        }
        else{
            return 0;
        }
}

// TASK 7 Changing ownership through a different password

void change_owner(node *given_node){

    string pass1,pass2;
    cout<<"Owner one enter password";
    cin>>pass;
    if(decrypt(given_node,pass)){
        cout<<"Ownership of node will be changed,enter new owner id";
        cin>>given_node->data->owner_name;
        void encrypt(given_node);
    }
    return;
}

//longest chain [ TASK 8-9 ]
void longest_chain(node *given_node){
    if(given_node == NULL){
		return 0;
	}
	if(given_node->childReferenceNodeid.size() == 0){
		return 1;
	}
	int longest= INT_MIN;
	for(auto i = given_node->childReferenceNodeid.begin(); i!=given_node->childReferenceNodeid.end(); i++){
		longest = max(longest,longestChain(*i));
	}
	cout<<"The longest chain is of length "<< longest + 1;
}


//merge nodes [ TASK 10 ]
void merge_node(node *node1, node* node2){
    if(longest_chain(n1) > longest_chain(n2)){
		n1->data += n2->data;
		n1->password = n2->password;
		delete n2;
		return;
	}
	else{
		n2->data += n1->data;
		n2->password = n1->password;
		delete n1;
		return;
	}
}

int main(){
 static int no;
 no++;                               //Would keep a static variable to keep current count of nodes between function calls, as no database is there.
 node *gen = createGenesisNode(no);
 no++;
 addChildNode(1,gen,n);
 return 0;
}
