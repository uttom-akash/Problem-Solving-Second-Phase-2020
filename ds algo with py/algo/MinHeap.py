
class MinHeap:
    def __init__(self,cmp=None):
        self.cmp=cmp
        self.array=[]
        self.size=0

    def handleSizeChange(self):
        self.size=len(self.array)

    def getParent(self,child):
        return (child-1)//2
    
    def compare(self,parentI,childI):
        decision=False
        if self.cmp:
            decision=self.cmp(self.array[parentI],self.array[childI])
        else :
            decision= True if self.array[parentI]<self.array[childI] else False
        return not decision
    
    def swap(self,index1,index2):
        self.array[index1],self.array[index2]=(self.array[index2],self.array[index1])

    def isEmpty(self):
        return True if self.size<=0 else False

    def heapify(self,idx):
        while True:
            smallest=idx
            left=2*idx+1
            right=2*idx+2

            if left<self.size and self.compare(smallest,left):
                smallest=left
            if right<self.size and self.compare(smallest,right):
                smallest=right

            if smallest!=idx:
                self.swap(smallest,idx)
                idx=smallest
            else :
                break 

    def push(self,element):
        self.array.append(element)
        self.handleSizeChange()

        i=self.size-1
        while i!=0 and self.compare(self.getParent(i),i):
            self.swap(self.getParent(i),i)
            i=self.getParent(i)

    def pop(self):
        if self.isEmpty():
            print("Priority Queue is empty!") 
            return None

        self.swap(0,self.size-1)
        obj=self.array.pop()
        self.handleSizeChange()
        self.heapify(0)
        return obj



def cmp(a,b):
    return True if a<b else False

pq=MinHeap(cmp=cmp)
pq.push(10)
pq.push(9)
pq.push(8)
pq.push(7)
pq.push(6)
pq.push(5)
print(pq.pop())
print(pq.pop())
print(pq.pop())
print(pq.pop())
print(pq.pop())
print(pq.pop())
print("Finished")


