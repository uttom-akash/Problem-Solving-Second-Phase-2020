def gcd(a,b):
    while a>0 and b>0:
        if a>b:
            a%=b
        else :
            b%=a
    return a+b

def lcd(a,b):
    return (a*b)//gcd(a,b)

def fractionMultiply(a,b):
    return (a[0]*b[0],a[1]*b[1])
def fractionDivision(a,b):
    return (a[0]*b[1],a[1]*b[0])

def fractionAddition(a,b):  
    denominator=lcd(a[1],b[1])
    nominator=(denominator//a[1])*a[0]+(denominator//b[1])*b[0]
    return (nominator,denominator)

def fractionSubtraction(a,b):  
    denominator=lcd(a[1],b[1])
    nominator=(denominator//a[1])*a[0]-(denominator//b[1])*b[0]
    return (nominator,denominator)

def printMatrix(matrix,rows,cols):
    for i in range(rows):
        print(*matrix[i])

def zerosMatrix(rows,cols):
    mat=[[] for i in range(rows)]
    for i in range(rows):
        for j in range(cols):
            mat[i].append(0)
    return mat

def identityMatrx(rows,cols):
    matA=zerosMatrix(rows,cols)
    for i in range(rows):
        matA[i][i]=1
    return matA

def copyMatrix(matA,rows,cols):
    matB= zerosMatrix(rows,cols)
    for i in range(rows):
        for j in range(cols):
            matB[i][j]=matA[i][j]
    return matB

def multiplyMatrix(matA,rowsA,colsA,matB,rowsB,colsB):
    if colsA!=rowsB:
        print("cols should be equal to rowsB")
        return -1
    
    matC=zerosMatrix(rowsA,colsB)
    for i in range(rowsA):
        for j in range(colsB):
            for ii in range(colsA):
                matC[i][j]+=matA[i][ii]*matB[ii][j]
    return matC

def minusMatrix(matA,rowsA,colsA,matB,rowsB,colsB):
    if rowsA!=rowsB or colsA!=colsB:
        print("missmatch in minus")
        return -1

    matC=zerosMatrix(rowsA,colsA)
    for i in range(rowsA):
        for j in range(colsA):
            matC[i][j]=matA[i][j]-matB[i][j]
    return matC

def inverseMatrix(matA,rowsA,colsA):
    if rowsA!=colsA:
        print("matrix should be squared")
        return -1
    IM=identityMatrx(rowsA,colsA)
    for diagonal in range(rowsA):
        reverseDiagValue=1/matA[diagonal][diagonal]
        for i in range(colsA):
            matA[diagonal][i]*=reverseDiagValue
            IM[diagonal][i]*=reverseDiagValue
        
        for ro in range(rowsA):
            if ro==diagonal:
                continue
            valueToMinus=matA[ro][diagonal]
            for col in range(colsA):
                matA[ro][col]-=valueToMinus*matA[diagonal][col]
                IM[ro][col]-=valueToMinus*IM[diagonal][col]
    
    return IM


def main():
    matA=[
        [1,2],
        [2,3]
    ]
    im=inverseMatrix(matA,2,2)
    # printMatrix(im,2,2)

main()


        
    




