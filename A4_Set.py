'''
To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the
value
c. Contains (element) Return true if element is in collection, d. Size () Return number of
values in collection Iterator () Return an iterator used to loop over collection, e.
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset
'''

l1 = []
l2 = []


def create():
    n1 = int(input("Enter the no. of inputs needed in 1st set : "))
    for i in range(n1):
        l1.append(str(input("Enter the elements for set1 : ")))
    n2 = int(input("Enter the no. of inputs needed in 2nd set : "))
    for i in range(n2):
        l2.append(str(input("Enter the elements for set2  : ")))

    print("{" + str(l1)[1:-1] + "}")
    print("{" + str(l2)[1:-1] + "}")


class set():


    def addition(self):

        while (True):
            print("*****MENU FOR ADDITION*****")
            print("1.Add element by default at last place in 1st set\n2.Add element at particular place in the 1st set\n3.Add element by default at last place in 2nd set\n4.Add element at particular place in the 2nd set\n5.Exit")
            ch = int(input("Enter your choice : "))
            if (ch == 1):

                m = int(input("Enter the no. of new entries you need : "))
                for j in range(m):
                    l1.append(str(input("Enter the new entries : ")))

                print("{" + str(l1)[1:-1] + "}")
                continue


            if (ch == 2):
                new = str(input("Enter the element to be inserted : "))
                index = int(input("Enter the place at which you want to add : "))
                l1.insert(index, new)

                print("{" + str(l1)[1:-1] + "}")
                continue



            if (ch == 3):

                m = int(input("Enter the no. of new entries you need : "))
                for j in range(m):
                    l2.append(str(input("Enter the new entries : ")))

                print("{" + str(l2)[1:-1] + "}")
                continue



            if (ch == 4):
                new = str(input("Enter the element to be inserted : "))
                index = int(input("Enter the place at which you want to add : "))
                l2.insert(index, new)

                print("{" + str(l2)[1:-1] + "}")
                continue



            if (ch>=5):
                break


    def deletion(self):
        while (True):
            print("*****MENU FOE DELETION*****")
            print("1.Delete element from last place in set1\n2.Delete element from last place in set2\n3.Delete a particular element in set1\n4.Delete a particular element in set2\n5.Exit")
            ch = int(input("Enter your choice : "))

            if (ch == 1):
                l1.pop()
                print("{" + str(l1)[1:-1] + "}")
                continue

            if (ch == 2):
                l2.pop()
                print("{" + str(l2)[1:-1] + "}")
                continue

            if (ch == 3):
                entry = (input("Enter the element you want to delete : "))
                l1.remove(entry)
                print("{" + str(l1)[1:-1] + "}")
                continue

            if (ch == 4):
                entry = (input("Enter the element you want to delete : "))
                l2.remove(entry)
                print("{" + str(l2)[1:-1] + "}")
                continue

            if (ch>=5):
                break


    def checking(self):
        while(True):
            print("*****MENU FOR CHECKING*****")
            print("1.Search in set1\n2.Search in set2\n3.Exit")
            ch = int(input("Enter your choice : "))

            if (ch == 1):
                key = str(input("Enter the element you want to search : "))
                if key in l1:
                    print(key," is present in set1")

                else:
                    print(key," is not present in set1")

                continue

            if (ch==2):
                key = str(input("Enter the element you want to search : "))
                if key in l2:
                    print(key, " is present in set2")

                else:
                    print(key, " is not present in set2")

                continue

            if (ch>=3):
                break


    def size(self):
        while(True):
            print("*****MENU FOR SIZE*****")
            print("1.Size of set1\n2.Size of set2\n3.Exit")
            ch=int(input("Enter your choice : "))
            if (ch==1):
                print("Size of set1 is : ",len(l1))
                continue

            if (ch==2):
                print("Size of set2 is : ",len(l2))
                continue

            if (ch>=3):
                break


    def union(self,a,b):
        unilist=a+b
        for i in a:
            if i in b:
                unilist.remove(i)

        print("Union of set1 and set2 is ","{" + str(unilist)[1:-1] + "}")


    def intersecn(self,a,b):
        interlist=[]
        for i in a:
            for j in b:
                if (i==j):
                    interlist.append(i)

        print("Intersection of set1 and set2 is : ","{" + str(interlist)[1:-1] + "}")


    def diff(self,a,b):
        c=[]
        for i in a:
            if i not in b:
                c.append(i)
        print("Difference between the sets is : ","{" + str(c)[1:-1] + "}")


    def subset(self,a,b):
        for i in a:
            if i not in b:
                return False
        return True


    def iterator(self,a):
        myit=iter(a)
        for i in range(len(a)):
            print(next(myit))


def main():
    obj=set()
    create()
    while(True):
        print("*"*10,"MENU FOR SET OPERATIONS","*"*10)
        print("1.Add new element\t\t\t\t2.Delete an element\n3.Search for an element\t\t\t4.Size of the set\n5.Union of the sets\t\t\t\t6.Intersection of the Sets\n7.Difference between the sets\t8.Check for subsets\n9.Use iterator\t\t\t\t\t10.Exit")
        ch=int(input("Enter your choice : "))

        if (ch==1):
            obj.addition()
            continue

        if (ch==2):
            obj.deletion()
            continue

        if (ch==3):
            obj.checking()
            continue

        if (ch==4):
            obj.size()
            continue

        if (ch==5):
            obj.union(l1, l2)
            continue

        if (ch==6):
            obj.intersecn(l1,l2)
            continue

        if (ch==7):
            obj.diff(l1,l2)
            obj.diff(l2,l1)
            continue

        if (ch==8):
            ans1 = obj.subset(l1, l2)
            if (ans1 == True):
                print("Set1 is subset of Set2")
            else:
                print("Set1 is not a subset of Set2")

            ans2 = obj.subset(l2, l1)
            if (ans2 == True):
                print("Set2 is subset of Set1")
            else:
                print("Set2 is not a subset of Set1")

        if (ch==9):
            print("Elements of set1 using iterator : ")
            obj.iterator(l1)
            print("Elements of set2 using iterator : ")
            obj.iterator(l2)
            continue

        if (ch==10):
            print("Exited successfully!!!")
            break

        if (ch>=11):
            print("You have entered a wrong choice!!\nPlease try again!!")
            continue

main()
