import math


def ZetaFromMp(Mp):
  from math import log, pi, sqrt
  return sqrt(log(Mp)**2/(pi**2 + log(Mp)**2))

def CalculateWn(zeta, Tsettle):
  return 4.6/(zeta*Tsettle)

Mp = 0.125
Tsettle = 10
zeta = ZetaFromMp(Mp)
wn = CalculateWn(zeta, Tsettle)
m = 200
k = m*wn**2
b = 2*math.sqrt(m*k)*zeta
print "Mp = %f, Tsettle = %f, zeta = %f, wn = %f, b = %f, k = %f"%(
    Mp, Tsettle, zeta, wn, b, k)
