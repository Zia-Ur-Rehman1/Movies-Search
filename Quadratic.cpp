#include <iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string>
#include <sstream>
using namespace std;
class mix_data{
private:
  float rating=0;
  int voting=0;
public:
void  data(float rate, int vote)
  {
      rating=rate;
      voting=vote;
  }
  int free_space()
  {
    if(voting==0)
      return(0);
    else
        return(-2);
  }
};
class Hashing
{
private:

    int key,i=0;
    int counter=0;
    mix_data array[1800];
public:
    int Hash(int value)
    {
        return((value+3*5/(11*7))%301);//tried to use diffrent prime num
      }
      void Add(int value,float rate,int vote)
      {
        counter++;
        if(counter>=900)
        {
          //std::cout << "There is no space to Add:" << '\n';
          return;
        }
        key=Hash(value);
        if(array[key].free_space()==0)
        {
          array[key].data(rate,vote);
        }
        else
        {
          key=collision(key,value);
          array[key].data(rate,vote);
        }
        return;
      }
      int collision(int key,int value)
      {
        i++;
        key=(Hash(value)+i*i)%101;
        if(array[key].free_space()==0)
        {
          return key;
        }
        else collision(key,value);
      }

};


class file_handling
{
private:
    float max=0;
    float min=999999;
    string max_str,min_str,str;
    float max_rate,min_rate;
    int min_vote,max_vote,convert;
    float weighted_rating=0;
    Hashing h;
public:
    void read()
    {
        int number_of_movies=0;
        int vote=0;
        float rating=0;
        float minimum_vote=1000;

        ifstream file;
        file.open("data.txt");
        while(file.eof()==0)
        {
            file >> str >> rating >> vote;
            convert=stoi(str);
            //cout << str << '\t' << rating  << '\t' << vote << endl;
            //h.Add(vote,rating,vote);
            weighted_rating=((vote/(vote+minimum_vote))*rating+(minimum_vote/(vote+minimum_vote))*6.9181);
            if(weighted_rating>max)
            {
                max=weighted_rating;
                Max(str,rating,vote);
            }
            if(weighted_rating<min)
            {
                min=weighted_rating;
                Min(str,rating,vote);
            }
            number_of_movies++;
        }
        file.close();

    }
    void Max(string str,float rating,float vote)
    {
        max_str=str;
        max_rate=rating;
        max_vote=vote;
    }
    void Min(string str,float rating,float vote)
    {
        min_str=str;
        min_rate=rating;
        min_vote=vote;
    }
    void Rating()
    {
      std::cout << "Movie Having Max Rating:" << '\n';
      cout << max_str << '\t' << max_rate << '\t' << max_vote << endl;
      std::cout << "Movie Having Min Rating:" << '\n';
      cout << min_str << '\t' << min_rate << '\t' << min_vote << endl;
    }
};
int main()
{

  int condition;
    file_handling f;
    f.read();
    return(0);
}
