

intInput = lambda:[int(x) for x in input().split()]


def main():
    room_num=int(input())
    room_bhopdis=intInput()
    hobbit_room=int(input())
    
    visited=[False]*room_num
    stack=[]

    stack.append(hobbit_room)
    visited[hobbit_room]=True

    while len(stack)>0:
        hobbit_room=stack.pop()

        if room_bhopdis[hobbit_room]==0:
            print('true')
            return

        left_room=hobbit_room-room_bhopdis[hobbit_room]
        right_room=hobbit_room+room_bhopdis[hobbit_room]

        if left_room>=0 and visited[left_room]==False:
            visited[left_room]=True
            stack.append(left_room)
        if right_room<room_num and visited[right_room]==False:
            visited[right_room]=True
            stack.append(right_room)
        
    print('false')
        


if __name__ == "__main__":
    main()