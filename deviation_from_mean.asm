section .text
    global _deviation_from_mean 

_deviation_from_mean:
    subsd xmm0, xmm1
    ret