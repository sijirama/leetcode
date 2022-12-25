class Solution(object):
#     ["--X","X++","X++"]
# ["++X","++X","X++"]
# ["X++","++X","--X","X--"]
    # operations = ["--X","X++","X++"]
    def finalValueAfterOperations(self, operations):
        x = 0
        for p in operations:
            if p[1]  == '+':
                x = x + 1
            elif p[1] == '-':
                x = x - 1
        return(x)
        