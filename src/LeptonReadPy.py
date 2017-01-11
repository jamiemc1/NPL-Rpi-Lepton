mport numpy as np
import cv2
from pylepton import Lepton

with Lepton() as l:
    a,_ = l.capture()
cv2.normalize(a, a, 0, 65535, cv2.NORM_MINMAX)
np.right_shift(a,8,a)
cv2.imwrite("output.jpg", np.uint8(a))

return 0
