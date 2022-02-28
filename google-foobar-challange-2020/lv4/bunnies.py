from itertools import combinations

def solution(num_buns, num_required):

    holes = [[] for num in range(num_buns)]
    
    key_copies_number = num_buns - num_required + 1

    bunny_comb = combinations(range(num_buns), key_copies_number)
    

    for key_index, bunnies in enumerate(bunny_comb):
    
        for bunny_hole in bunnies:
    
            holes[bunny_hole].append(key_index)

    return holes


if __name__ == "__main__":
    solution(5, 3)