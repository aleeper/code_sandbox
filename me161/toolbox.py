import math


def CalculateDamping(mass, zeta, wn):
  return mass * 2*zeta*wn

def CalculateStiffness(mass, wn):
  return mass * wn**2

# - - - - - - -

def MpFromZeta(zeta):
  return math.exp((-zeta * math.pi) / math.sqrt(1 - zeta**2))

# - - - - - - -

def LogDecrementFromDecayRatio(decayRatio):
  return -math.log(decayRatio)

def LogDecrementFromZeta(zeta):
  return 2*math.pi*zeta / math.sqrt(1 - zeta**2)

def LogDecrementFromZetaWnTperiod(zeta, wn, Tperiod):
  return zeta*wn*Tperiod

# - - - - - - -

def ZetaFromLogDecrement(logDecrement):
  return math.sqrt(logDecrement**2 / (4*math.pi**2 + logDecrement**2))

def ZetaFromMp(Mp):
  return math.sqrt(math.log(Mp)**2 / (math.log(Mp)**2 + math.pi**2))

# - - - - - - -

def WnFromZetaTperiodLogDecrement(zeta, Tperiod, logDecrement):
  return logDecrement / (zeta * Tperiod)


def WnFromZetaTperiod(zeta, Tperiod):
  return WnFromZetaTperiodLogDecrement(zeta, Tperiod, LogDecrementFromZeta(zeta))

def WnFromMpTperiod(Mp, Tperiod):
  return WnFromZetaTperiod(ZetaFromMp(Mp), Tperiod)

def WnFromZetaTsettle(zeta, Tsettle):
  return 4.6/(zeta*Tsettle)

# - - - - - - -

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


