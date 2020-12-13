def gcd(a,b):
    if a<0:
        a=-a
    if b<0:
        b=-b
    while a!=0 and b!=0:
        if a>b:
            a%=b
        else :
            b%=a
    return a+b

def lcd(a,b):
    return (a*b)//gcd(a,b)

def reduceNominatorDenominator(nomi,denomi):
    if denomi==0:
        denomi=1
    g=gcd(nomi,denomi)
    return (nomi//g,denomi//g)

def fractionMultiply(a,b):
    return reduceNominatorDenominator(a[0]*b[0],a[1]*b[1])

def fractionDivision(a,b):
    return reduceNominatorDenominator(a[0]*b[1],a[1]*b[0])

def fractionAddition(a,b):  
    denominator=lcd(a[1],b[1])
    nominator=(denominator//a[1])*a[0]+(denominator//b[1])*b[0]
    return reduceNominatorDenominator(nominator,denominator)

def fractionSubtraction(a,b):  
    denominator=lcd(a[1],b[1])
    nominator=(denominator//a[1])*a[0]-(denominator//b[1])*b[0]
    return reduceNominatorDenominator(nominator,denominator)

def zerosMatrix(rows,cols):
    mat=[[] for i in range(rows)]
    for i in range(rows):
        for j in range(cols):
            mat[i].append((0,1))
    return mat

def identityMatrx(rows,cols):
    matA=zerosMatrix(rows,cols)
    for i in range(rows):
        matA[i][i]=(1,1)
    return matA

def multiplyMatrix(matA,rowsA,colsA,matB,rowsB,colsB):
    if colsA!=rowsB:
        print("cols should be equal to rowsB")
        return -1
    
    matC=zerosMatrix(rowsA,colsB)
    for i in range(rowsA):
        for j in range(colsB):
            for ii in range(colsA):
                matC[i][j]=fractionAddition(matC[i][j],fractionMultiply(matA[i][ii],matB[ii][j]))
    return matC

def subtractMatrix(matA,matB,rowsA,colsA):
    matC=zerosMatrix(rowsA,colsA)
    for i in range(rowsA):
        for j in range(colsA):
            matC[i][j]=fractionSubtraction(matA[i][j],matB[i][j])
    return matC
    
def reduceMatrixFractions(matA,rowsA,colsA):
    for i in range(rowsA):
        for j in range(colsA):
            frac=matA[i][j]
            matA[i][j]=reduceNominatorDenominator(frac[0],frac[1])
    return matA


def inverseMatrix(matA,rowsA,colsA):
    if rowsA!=colsA:
        print("matrix should be squared")
        return -1
    IM=identityMatrx(rowsA,colsA)
    for diagonal in range(rowsA):
        reverseDiagValue=fractionDivision((1,1),matA[diagonal][diagonal])
        for i in range(colsA):
            matA[diagonal][i]=fractionMultiply(matA[diagonal][i],reverseDiagValue)
            IM[diagonal][i]=fractionMultiply(IM[diagonal][i],reverseDiagValue)
        
        for ro in range(rowsA):
            if ro==diagonal:
                continue
            valueToMinus=matA[ro][diagonal]
            for col in range(colsA):
                matA[ro][col]=fractionSubtraction(matA[ro][col],fractionMultiply(valueToMinus,matA[diagonal][col]))
                IM[ro][col]=fractionSubtraction(IM[ro][col],fractionMultiply(valueToMinus,IM[diagonal][col]))
    
    return IM

def solution(matrix):
    terminals=[]
    nonTerminals=[]
    rows=len(matrix)
    if rows>0:
        cols=len(matrix[0])
    isSourceTerminal=False

    for i in range(rows):
        isTerminal=True
        totalProbablity=0
        for j in range(cols):
            totalProbablity+=matrix[i][j]
            if i==j:
                continue
            if matrix[i][j]>0:
                isTerminal=False
        if isTerminal:
            terminals.append(i)
            if i==0:
                isSourceTerminal=True
        else :
            nonTerminals.append(i)
        for j in range(cols):
            matrix[i][j]=(matrix[i][j],totalProbablity)
    
    matrix=reduceMatrixFractions(matrix,rows,cols)
    ans=[]
    if isSourceTerminal:
        ans=[matrix[0][i] for i in terminals]
        ans[0]=(1,1)
    else :
        nonTermLength=len(nonTerminals)
        termLength=len(terminals)
        # R
        Rmat=zerosMatrix(nonTermLength,termLength)
        for i in range(nonTermLength):
            for j in range(termLength):
                Rmat[i][j]=matrix[nonTerminals[i]][terminals[j]]
        # Q
        Qmat=zerosMatrix(nonTermLength,nonTermLength)
        for i in range(nonTermLength):
            for j in range(nonTermLength):
                Qmat[i][j]=matrix[nonTerminals[i]][nonTerminals[j]]
        # I-Q
        Imat=identityMatrx(nonTermLength,nonTermLength)
        IQ=subtractMatrix(Imat,Qmat,nonTermLength,nonTermLength)
        # (I-Q)^-1=F
        Fmat=inverseMatrix(IQ,nonTermLength,nonTermLength)
        # F*R
        FRmat=multiplyMatrix(Fmat,nonTermLength,nonTermLength,Rmat,nonTermLength,termLength)
        ans=FRmat[0]
    
    loshagu=1
    finalAns=[]
    for f in ans :
        loshagu=lcd(loshagu,f[1])
    for f in ans :
        finalAns.append((loshagu//f[1])*f[0])
    finalAns.append(loshagu)
    return finalAns

# solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]])
# solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0,0], [0, 0, 0, 0, 0]])
solution([[0,0,0],[0,0,0],[0,0,0]])
# solution([[2]])        
    




