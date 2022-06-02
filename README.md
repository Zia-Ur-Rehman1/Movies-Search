# Movies-Search

![](Aspose.Words.7618dafd-9069-4966-87ba-2f8a970b712f.001.png)

DSA Project (Search Engine)

Name Roll No![](Aspose.Words.7618dafd-9069-4966-87ba-2f8a970b712f.002.png)

Zia-Ur-Rehman 1802034 Noman Shahzad 1802038 Muhammad Ali Raza 1802031

Submitted To:Malik-Jahan

January 1, 2020

1  Abstract

Search Engine is a program that identify the data corresponding to the keywords enter by the user nd it by using ecient algorithms.In this project huge amount of data of Movies is given having three attributes Movie ID,Rating and Voting.Purpose is to analyse the data and according to data using dierent techniques of data structure design an ecient algorithm.Main task to minimize the complexity of time.We use the concept of Hashing and Linked-list to apply separate chaining.

Contents

1 Abstract 3

2 Introduction 5

1. Data Analysis . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 5
1. Problem Statement . . . . . . . . . . . . . . . . . . . . . . . . . . 5
1. Possible Solution . . . . . . . . . . . . . . . . . . . . . . . . . . . 6

3 Methodology 6

1. Reading File: . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6
1. Storing . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6
1. Hashing . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6
1. Separate Chaining . . . . . . . . . . . . . . . . . . . . . . . . . . 7
1. Minimum Ranking . . . . . . . . . . . . . . . . . . . . . . . . . . 7
1. Maximum Ranking . . . . . . . . . . . . . . . . . . . . . . . . . . 7
1. Same Rating . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 7
1. Classes . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 7

4 Result 8 5 Conclusion 8

2  Introduction

The word Search Engine means to search a certain data in the cluster of millions of data.In this era of data every one wants to search any kind of data as fast as possible.

There are many search engines having very ecient algorithm which can

search any information given to them in the matter of milliseconds.e.g;Google Search Engine,Mozilla Firefox etc we are computer science students of second year at Namal Institute. In our each subject we are given semester project to test and polish our skill in that particular subject, and to see how much we have gained and how much is remaining.

We are given a task in DSA Project to make an ecient search engine using the concept of Hashing(chaining) , Linked List , File Handling .

1. Data Analysis

By reading the le we analyse the data and we come to know that in le each line has three attribute Movie ID,Rating,Votes. Movie ID is in the form of String(tt4283088) and each movie has a unique ID. First two digits are character and the remaining are integer. 9.9 160520 Rating is in the form of Floating Value(1.5).The third and the last attribute Votes are in the form

of Integer(5423). By data analysis we come to know that as each movie has unique ID if we store according to it there will be no clusters but there are some issues which will be discussed in next section.Rating will form a large clusters because many movies have same rating.Votes will form less clusters.

2. Problem Statement

Our task is to make an algorithm for an ecient search engine.We are given a data of certain record about movies.It has three attributes Movie ID ,Rating and Votes for the Movie..We have to use these attributes to store the data in such a way that all of the search algorithm can give minimum complexity and can answer all types of questions like.

Minimum Rating

Maximum Rating

Movies having same Rating

No. of Movies

In order to minimize the time complexity we have to apply hashing on such an attribute which don't form clusters,use minimum space and less time. As discussed earlier by using ID we can store the data which will not form clusters but it increase the space complexity and the complexity becomes O(n).In order to store by Id we also rst have to convert the given string into an integer which is also a big issue. If we use votes for storing data it will also increase the complexity of space and this will not be a good idea to to search movies by votes. If we use rating to store data it will form a huge amount of clusters.

3. Possible Solution

To store the data by ID we rst have to convert it to integer and as each movie have unique id it will give dierent results and increase space complexity so it should not be used same goes for the votes. We come to realize that only rating can decrease the space complexity but it will form a large amount of clusters. We can minimize the clusters by using an ecient Hashing. If we use linear hashing it will surely form the cluster and quadratic will minimize it but as the data is large and we cannot aord that much space. We are using Hashing in separate chaining to minimize the complexity of space we don't have to form a large array to apply hashing.Methods we used to store the data is given below

3  Methodology

Following are the steps we adopt for making our Search Engine.

1. Reading File:

The data is given to us in a text le "data.txt".This le contains three attributes,in the start there is movie ID (String) ,then there is movie Rating (Float) and in the end there are Votes (Integer) of that movie.

We are reading this le through ReadFile() function. In this function we are using string to read the movie ID , oat to read the movie rating and oat to read votes. we use oat for reading vote because in ranking function if we use integer to read vote it will lose data in decimal values.

2. Storing

We need to store the data in order to apply dierent search functions on it. As the data has three attributes .We are using Separate chaining to store the

data.So a single node contain a Movie ID,Rating and Votes.

In order to store it we use a function add chain() which is a function of Class Chaining.It uses Hash function to get specic index of linked list to store data.This function is storing data right after reading the le the attributes are passed to add chain() function.The data is read line by line and each line contain Movie ID,Rating and Votes.Each new node is added at start to

minimize the complexity of function.Now the complexity of function is O(1).

3. Hashing

In order to apply hashing we use a function Hash() First we try to pass Movie ID as all the movies have unique ID.But it increase the complexity of space.Then we use Rating in order to get specic index and reduce the complexity of space.First we convert the data type of Rating(Float) to integer in order to store but later on to increase the preciseness and dierentiate between decimal values we use oating value by multiplying the Rating with 10 to get specic index.Now 9.1 Rating and 9.2 Rating are dierentiated and less clusters are formed and eciency of search also increase. It has the complexity of O(1).

4. Separate Chaining

As soon as the data is read and passed to function add chain() which pass it to Hash() function.Now come the separate chaining to store the data at

specic key generated by Hash function.An array of Class Linked list is created and key is passed to that array to use as index and a function

addatstart() passed the attribute.Linked list use the function of Class

Node() and store the data at that index.

5. Minimum Ranking

In order to detect the minimum rating we use a formula from a website link[1] to calculate the average rating.As soon we read the le we apply the formula

to calculate the minimum average rating compare it with previously stored minimum rating if it is less then previously stored data we pass it to function Min() and store the new given data.Initially Minimum stored a large number. As it only compare the value so have a complexity of O(1).

6. Maximum Ranking

In order to detect the maximum rating we use the same technique as discussed earlier. We compare the given rating generated by the formula if it is greater than previously stored rating we pass it to function Max() and store the new data.Initially maximum stored zero.

It has the complexity of O(1)

7. Same Rating

In Class of Chaining in function of add chain() after storing the data we also count the same rating.For this we created an array of same size as array of

linked list and after generating the key from hash function as the specic

index number of movie having same rating is also counted and stored in the array. With each generation of key it adds the value with previously stored

value at that index.Initially at all index default value is stored zero.It has the complexity of O(1).

8. Classes

We use Classes to organize the program and to easily read the code. Each Class use his function and changing also become easy by using this Class scope.In order to more organize the code we move all the classes to another le and created a header le classes.h. So that main looks simple and easily understandable.

4  Result

We were able to create an ecient search engine on the given data whose max functions work on O(1). We apply hashing on rating to generate a specic key to store data in an array of Linked list. We apply the concept of Node,Linked list,Separate Chaining,Hashing,File Handling and Classes in our project. At the end we detect following results

Category Movie ID Rating Votes![](Aspose.Words.7618dafd-9069-4966-87ba-2f8a970b712f.003.png)![](Aspose.Words.7618dafd-9069-4966-87ba-2f8a970b712f.004.png)![](Aspose.Words.7618dafd-9069-4966-87ba-2f8a970b712f.004.png)

Max Rating tt4283088 9.9 160520

Min Rating tt7221896 1.3 36794

5  Conclusion

At the end we conclude that very ecient algorithms are required to store and search huge amount of data like in google search engine as it is very complicated task to do. We rst have to read the data type then we have to think which part of data is to be used for indexing and then the most dicult task it to make an ecient algorithm to store that data without creating huge clusters and design an ecient search algorithm.We come to know that Chaining form clusters but use a short array which help in some cases rather than quadratic or double hashing.Some time we have to compromise on space eciency or time eciency depending upon the given data.

References [1]www.quora.com/How-does-IMDbs-rating-system-work
8
