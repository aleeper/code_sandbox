#!/usr/bin/python

import math

def CalculateZetaAndWn(Tperiod, decayRatio):
  logDecrement = -math.log(decayRatio)
  zeta = math.sqrt(logDecrement**2 / (4*math.pi**2 + logDecrement**2))
  wn = logDecrement/(zeta*Tperiod)
  return zeta, wn

def ControllerFromZetaAndWn(m, b, k, zeta, wn):
  kp = wn**2 * m - k
  kd = 2*zeta*wn*m - b
  return kd, kp

def ControllerFromPeriodAndDecayRatio(m, b, k, Tperiod, decayRatio):
  zeta, wn = CalculateZetaAndWn(Tperiod, decayRatio)
  return ControllerFromZetaAndWn(m, b, k, zeta, wn)


def PrintStuff1(m, b, k, Tperiod, decayRatio):
  kd, kp = ControllerFromPeriodAndDecayRatio(m, b, k, Tperiod, decayRatio)
  print "Tperiod = %f, DecayRatio = %f, kd = %f, kp = %f"%(
      Tperiod, decayRatio, kd, kp)

def PrintStuff2(m, b, k, kd, kp):
  wn = math.sqrt((k+kp)/m)
  zeta = (b + kd)/(2*wn*m)
  wd = wn*math.sqrt(1 - zeta**2)
  Tperiod = 2*math.pi/wd
  logDecrement = zeta*wn*Tperiod
  decayRatio = math.exp(-logDecrement)
  print "Tperiod = %f, DecayRatio = %f"%(Tperiod, decayRatio)


m = 200
b = 204.3
k = 7948

PrintStuff1(m, b, k, 1.0, 0.6)
PrintStuff1(m, b, k, 1.0, 0.4)
PrintStuff1(m, b, k, 0.75, 0.4)
kd_crit, kp_crit = ControllerFromZetaAndWn(m, b, k, 1, 1.857)
print "Critical: kd = %f, kp = %f"%(kd_crit, kp_crit)
