from collections import defaultdict

def tree():
    return defaultdict(tree)

users=tree()
users[]

print(us)

def tuple_to_list(board):
    return [list(x) for x in board]

def list_to_tuple(board):
    return tuple([tuple(x) for x in board])

def do_position(board,player, position):
    temp_board=tuple_to_list(board)
    position-=1
    row,col=position//3,position%3
    temp_board[row][col]=player
    return list_to_tuple(temp_board)

board = ((1,-1,0),(1,0,-1),(1,-1,0))
do_position(board, -1, 3)