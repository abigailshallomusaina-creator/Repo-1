class human:
    def __init__(self,name,gender,age):
        self.name=name
        self.gender=gender
        self.age=age

    def display(self):
        print("my neighbour is",self.name,"she is a",self.gender,"and is",self.age,"years of age")

    def works(self):
        print(self.name,"goes to work")

    def study(self):
        print(self.name,"goes to school")

neighbour1=human("Sheila","female",25)
neighbour1.display()
neighbour1.works()
neighbour1.study()

