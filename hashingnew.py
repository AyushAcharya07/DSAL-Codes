'''
Consider telephone book database of N clients. Make use
of a hash table implementation to quickly look up client’s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons required to find
a set of telephone numbers.
'''

class linear_probing:
    record=[]

    def __init__(self):
        self.hash_size=int(input("Enter the size of the hash table for Linear Probing: "))
        self.hash_table=[0]*self.hash_size

    def hash_func(self,key):
        return key%self.hash_size

    def opern(self):
        self.n = int(input("Enter the no. of entries : "))
        for i in range(self.n):
            self.new = []
            self.new.append(input("Enter the name : "))
            self.mobile = int(input("Enter the mobile no. : "))
            self.new.append(self.mobile)
            self.record.append(self.new)

        print("User entered record : ", self.record)

        for i in self.record:
            index=self.hash_func(i[1])
            while(self.hash_table[index]!=0):
                index=(index+1)%self.hash_size
            self.hash_table[index]=i
        print("Hash Table : ",self.hash_table)

    def search(self):
        self.key=input("Enter the name for which you want to find mob no. : ")
        for i in self.hash_table:
            if i!=0 and i[0]==self.key:
                return i[1]
        return False

    def display(self):
        for i in range(self.hash_size):
            print(i," : ",self.hash_table[i])


class double_hashing:
    record = []

    def __init__(self):
        self.hash_size = int(input("Enter the size of the hash table for Double Hashing : "))
        self.hash_size2=self.prime(self.hash_size-1)
        self.hash_table = [0] * self.hash_size

    def prime_check(self,a):
        if a<=1:
            return False
        for i in range(2,int(a**0.5)+1):
            if a%i==0:
                return False
        return True

    def prime(self,a):
        while (True):
            if self.prime_check(a):
                return a
            a=a-1

    def hash_func(self, key):
        return key % self.hash_size

    def hash_func2(self, key):
        return self.hash_size2 - (key % self.hash_size2)

    def opern(self):
        self.n = int(input("Enter the no. of entries : "))
        for i in range(self.n):
            self.new = []
            self.new.append(input("Enter the name : "))
            self.mobile = int(input("Enter the mobile no. : "))
            self.new.append(self.mobile)
            self.record.append(self.new)

        print("User entered record : ", self.record)

        for i in self.record:
            index = self.hash_func(i[1])
            step_size = self.hash_func2(i[1])
            while (self.hash_table[index] != 0):
                index = (index + step_size) % self.hash_size
            self.hash_table[index] = i
        print("Hash Table : ",self.hash_table)


    def search(self):
        self.key = input("Enter the name for which you want to find mob no. : ")
        for i in self.hash_table:
            if i != 0 and i[0] == self.key:
                return i[1]
        return False

    def display(self):
        for i in range(self.hash_size):
            print(i," : ",self.hash_table[i])



def main():
    o1=linear_probing()
    o2=double_hashing()
    while(True):
        print("*"*10,"MENU FOR HASHING METHOD","*"*10)
        print("1.Linear Probing Method\n2.Double Hashing Method\n3.Exit")
        ch=int(input("Enter your choice : "))

        if (ch==1):
            while (True):
                print("1.Add Data in the Directory\n2.Search for Mobile no. in directory\n3.See entire Directory\n4.Exit")
                ans=int(input("Enter your choice : "))
                if (ans==1):
                    o1.opern()
                    continue

                if (ans==2):
                    value=o1.search()
                    if (value == False):
                        print("Name entered not found in the table")
                    else:
                        print("Mobile no. of entered name : ", value)
                    continue

                if (ans==3):
                    o1.display()
                    continue

                else :
                    break



        if (ch==2):
            while (True):
                print("1.Add Data in the Directory\n2.Search for Mobile no. in directory\n3.See entire Directory\n4.Exit")
                ans = int(input("Enter your choice : "))
                if (ans == 1):
                    o2.opern()
                    continue

                if (ans == 2):
                    value = o2.search()
                    if (value == False):
                        print("Name entered not found in the table")
                    else:
                        print("Mobile no. of entered name : ", value)
                    continue

                if (ans == 3):
                    o2.display()
                    continue

                else:
                    break

        if (ch==3):
            print("Exited Successfully!!!")
            break

        if (ch>=4):
            print("You have entered a wrong choice!!\nPlease try again!!")
            continue

main()