# Data Structures CS214: Social networking project - 2021
**Introduction**

Me and my friends are building a smart social networking system like facebook app. we are going to compete with the facebook app. Competition is very hard, and we need to build strong features. One of the most critical parts of this system is **user manager** , and we decided to develop it. 

**Problem Statement**

we are required to implement the **user manager** for your system. This is a program that keeps track of all user information (profile, friends, ..). we can also quickly reach a user through search.

**Project Structure** 

**User Manager**

- User linked list 
You are given a file with all users. This file is called "all-users.in". Each line of the file
will be in the following format (without quotes):
"username","name","email"
A linked list will be created to save all user in the system and each user object
contains (username -is a unique value-, name, email, friendsBST)


- Friend list Balanced BST
You will get a file with all users relations. This file is called "all-users-relations.in".
Each line of the file will be in the following format (without quotes):
"username1","username2"
"username2","username3"
"username1","username4"

You are required to build a friends list using a balanced BST with all the users sorted
by username alphabetically. Each friend is an object, carrying the username and
reference to the user object.
Using Linked List to keep all user friends is inefficient for this task. We need a better
data structure to efficiently search for a username and get the name. We will use a
“Balanced Binary Search Tree” because it allows us to search in O(log n) while
keeping the friend list dynamic. Each node in the tree will carry a username and a
pointer to the user.For this task you are required to implement a "Treap". It is a
Randomized Balanced Binary Search Tree that performs very well in practice. Read
the document attached parts 8.1 to 8.4 to understand more about them.

We won’t need all of the functionality of the tree for this problem. The required
operations are:
Add(username, pointer to user): adds a username and pointer to user in its
right position in the tree.
Find(username): Searches for a username in the tree. If found, returns the user,
otherwise returns null.


**Application:**

1) Login: type “username” to be logged in 

2) Logout: type “logout” 

3) Exit: type “exit” 

4) Application actions
○ Login
○ Exit

5) List of all action logged in user can do 
○ List all friends 
○ Search by username 
○ Add friend 
○ Remove friend 
○ People you may know 
○ logout


Logged in user Actions Description:

● List all friends

○ Traverse “friendsBST” of the logged in user
○ Print these information for each friend in the tree
Username1, name1
Username2, name2
Username3, name3

● Search by username

○ If the username belongs to the friend list, display the user “name”.
○ Otherwise display the not found message
Enter “usernameX”
If exist, print
UsernameX, nameX, email
If doesn’t exist, print
“not found”

● Add friend

○ if userA become friend with userB this mean userB also become friend with
userA so you need to update the two users friendsBST
Enter “usernameX”
Print
You are now friends
If they are already friends then print
You are already friends

● Remove friend

○ if userA remove userB from his friends this mean userA will be removed from
userB friends so you need to update the two users friendsBST
Enter “usernameX”
Print
Done
If they are already not friends then do nothing

● people you may know

○ List any users not in user friend list
○ Recommend 5 new friends - if the existed less than 5 view them -
Username1, name1
Username2, name2
Username3, name3

