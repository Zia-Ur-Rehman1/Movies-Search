#include <iostream>
#include<fstream>
#include<string>
using namespace std;
class Node
{
private:
    string str;
    float rate;
    float vote;
    Node *next;
public:
    Node()
    {}
    Node(string st,float rating,float voting)
    {
        str=st;
        rate=rating;
        vote=voting;
        next=NULL;
    }
    string get_string()
    {
        return(str);
    }
    float get_rate()
    {
        return(rate);
    }
    float get_vote()
    {
        return(vote);
    }
    void setnext(Node *pointer)
    {
        next=pointer;
    }
    Node* getnext()
    {
        return(next);
    }
};
class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    {
        first=NULL;
    }
    //addatstart will take three attributes and store them at node
    void addatstart(string link_str,float link_rate, float link_vote)//checked
    {
        Node *temp=new Node(link_str,link_rate,link_vote);
        Node *temp2=first;//temp2 ko first pass kr dia
        first=temp;//first main temp a gia
        first->setnext(temp2);//first k next main temp 2 a gia
    }

};

class Hashing
{
public:
  //take rating and return after Hashing
    int Hash(float value)
    {
        return(value*10);
    }
};
class Chaining
{
private:
    LinkedList array[101];
    int counter[101]= {0};
    Hashing h;
public:
      //add_chain will take all three attributes of file and apply and hsing and pass to linkedlist to stor it
    void  add_chain(string chain_str,float chain_rate,float chain_vote)
    {
        int key=h.Hash(chain_rate);
        array[key].addatstart(chain_str,chain_rate,chain_vote);
        counter[key]=counter[key]+1;
    }
    //check will tell how much movies have same Rating according to key given by user
    void check(float key)
    {
        int value=h.Hash(key);
        cout<<'\t'<<'\t'<<'\t'<<'\t'<< "Number of Movies Having Rating "<<"'"<<key<<"'"<<" are : "<<'\t'<< counter[value]<<'\n';
               cout<<'\t'<<'\t'<<'\t'<<'\t'<<"============================================"<<endl;
    }

};
//reading and storing the file
class File_handling
{
private:
    float max=0;//to get maximum rating
    float min=999999;//to get minimum rating
    string max_str,min_str;
    float max_rate,max_vote,min_rate,min_vote;
    float weighted_rating=0;
    float minimum_vote=1000;//going to use in formula to detect ranking
    Chaining objc;
public:
    void read()
    {
        int number_of_movies=0;//counting the data founded
        float vote=0;
        float rating=0;
        ifstream file;
        file.open("data.txt");
        string str;
        //reading file and storing
        while(file.eof()==0)
        {
            file >> str >> rating >> vote;//takiing all three attributes
            //formula to compute weighted_rating
            weighted_rating=((vote/(vote+minimum_vote))*rating+(minimum_vote/(vote+minimum_vote))*6.9181);
            //passing attributes to Chaining class
            objc.add_chain(str,rating,vote);
            //finding max rating
            if(weighted_rating>max)
            {
                max=weighted_rating;
                Max(str,rating,vote);
            }
            //finding min rating
            if(weighted_rating<min)
            {
                min=weighted_rating;
                Min(str,rating,vote);
            }
            number_of_movies++;
        }
        std::cout<<'\t'<<'\t'<<'\t'<<'\t'<< "Number Of Movies: " <<'\t'<< number_of_movies<<'\n';
               cout<<'\t'<<'\t'<<'\t'<<'\t'<<"=================================="<<endl;
    }
    //storing Data of movie having max rating
    void Max(string str,float rating,float vote)
    {
        max_str=str;
        max_rate=rating;
        max_vote=vote;
    }
    //storing Data of movie having min rating

    void Min(string str,float rating,float vote)
    {
        min_str=str;
        min_rate=rating;
        min_vote=vote;
    }
    //Displaing user asked values
    void display(){
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"Movie Having Max Ranking: "<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"=================================="<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"Movie ID"<<"   "<<"|"<<"  "<<"Rating"<<"   "<<"|"<<"  "<<"Votes"<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<max_str<<'\t'<<max_rate <<'\t'<<max_vote<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"__________________________________"<<endl;

      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"Movies Having Min Ranking: "<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"=================================="<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<"Movie ID"<<"   "<<"|"<<"  "<<"Rating"<<"   "<<"|"<<"  "<<"Votes"<<endl;
      cout<<'\t'<<'\t'<<'\t'<<'\t'<<min_str <<'\t'<<min_rate<<'\t'<<min_vote<<endl;

  }
    //taking value from user and passing to chain class to detect movie having same rating
    void check(float value)
    {
        objc.check(value);
    }
};
