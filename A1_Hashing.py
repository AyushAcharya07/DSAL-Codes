'''
Consider telephone book database of N clients. Make use
of a hash table implementation to quickly look up client’s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons required to find
a set of telephone numbers.
'''

class linear_probing:   # linear probing without replacement
    record=[]

    def __init__(self):
        self.hash_size=int(input("Enter the size of Hash Table for Linear Probing : "))
        self.hash_table=[0]*self.hash_size

    def count(self,key):
        if (len(key)==10):
            return True
        else:
            return False

    def hash_func(self,key):
        return key % self.hash_size

    def get_data(self):
        self.n=int(input("Enter the No. of Entries :"))
        for i in range(self.n):
            self.temp=[]
            self.temp.append(input("Enter the Name : "))
            self.mobile=int(input("Enter the Mobile Number : "))
            if (self.count(str(self.mobile))==True):
                self.temp.append(self.mobile)
            else:
                while(self.count(str(self.mobile))==False):
                    self.mobile = int(input("Enter the Correct Mobile Number : "))
                self.temp.append(self.mobile)
            self.record.append(self.temp)

    def opern(self):
        for i in self.record :
            index=self.hash_func(i[1])
            while (self.hash_table[index]!=0):
                index=(index+1)%self.hash_size
            self.hash_table[index]=i


    def search(self):
        key=input("Enter the Name you want to search : ")
        for i in self.hash_table:
            if (i!=0 and i[0]==key):
                return i[1]
        return False

    def display(self):
        for i in range(self.hash_size):
            print(i," : ",self.hash_table[i])


class double_hashing:
    record=[]

    def prime_check(self,a):
        if (a<=1):
            return False
        for i in range (2,int(a**0.5)+1):
            if (a%i==0):
                return False
        return True

    def prime(self,a):
        while(True):
            if (self.prime_check(a)):
                return a
            a=a-1

    def __init__(self):
        self.hash_size=int(input("Enter the size of the Hash Table foe Double Hashing : "))
        self.hash_size2=self.prime(self.hash_size-1)
        self.hash_table=[0]*self.hash_size

    def hash_func1(self,key):
        return key%self.hash_size

    def hash_func2(self,key):
        return key%self.hash_size2

    def count(self,key):
        if (len(key)==10):
            return True
        else:
            return False

    def get_data(self):
        n=int(input("Enter the no. of entries : "))
        for i in range (n):
            temp=[]
            temp.append(input("Enter the Name : "))
            mobile=int(input("Enter the Mobile Number : "))
            if (self.count(str(mobile))==True):
                temp.append(mobile)
            else:
                while(self.count(str(mobile))==False):
                    mobile = int(input("Enter the Correct Mobile Number : "))
                temp.append(mobile)
            self.record.append(temp)


    def opern(self):
        for i in self.record:
            index1 = self.hash_func1(i[1])
            index2 = self.hash_func2(i[1])
            if self.hash_table[index1] == 0:
                self.hash_table[index1] = i
            else:
                j = 1
                while True:
                    new_index = (index1 + j * index2) % self.hash_size
                    if self.hash_table[new_index] == 0:
                        self.hash_table[new_index] = i
                        break
                    j += 1

    def search(self):
        key=input("Enter the name you want to search : ")
        for i in self.hash_table:
            if (i!=0 and i[0]==key):
                return i[1]
        return False

    def display(self):
        for i in range(self.hash_size):
            print(i," : ",self.hash_table[i])

def main():
    obj1=linear_probing()
    obj2=double_hashing()
    while(True):
            print("*"*10,"MENU FOR HASHING METHOD","*"*10)
            print("1.Linear Probing Method\n2.Double Hashing Method\n3.Exit")
            ch=int(input("Enter your choice : "))

            if (ch == 1):
                while (True):
                    print("1.Add Data in the Directory\n2.Perform Hashing\n3.Search for Mobile no. in directory\n4.See entire Directory\n5.Exit")
                    ans = int(input("Enter your choice : "))

                    if (ans==1):
                        obj1.get_data()

                    elif (ans==2):
                        obj1.opern()

                    elif (ans==3):
                        val=obj1.search()
                        if (val==False):
                            print("The name entered was not found in the directory !")
                        else:
                            print("Mobile No. is : ",val)

                    elif (ans==4):
                        obj1.display()

                    elif (ans==5):
                        print("Exiting from the program...........")
                        break

                    else:
                        print("You have entered a wrong choice !")
                        continue

            if (ch==2):
                while (True):
                    print("1.Add Data in the Directory\n2.Perform Hashing\n3.Search for Mobile no. in directory\n4.See entire Directory\n5.Exit")
                    ans = int(input("Enter your choice : "))


                    if (ans == 1):
                        obj2.get_data()

                    elif (ans == 2):
                        obj2.opern()

                    elif (ans == 3):
                        val = obj2.search()
                        if (val == False):
                            print("The name entered was not found in the directory !")
                        else:
                            print("Mobile No. is : ", val)

                    elif (ans == 4):
                        obj2.display()

                    elif (ans == 5):
                        print("Exiting from the program...........")
                        break

                    else:
                        print("You have entered a wrong choice !")
                        continue

            elif (ch==3):
                print("Exiting from the Program..........")
                break

            else:
                print("You have entered a wrong choice !")
                continue

main()
