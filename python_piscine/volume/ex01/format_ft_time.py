import time
import datetime

# 그래고리력
tm = time.time()

print( "Seconds since January 1, 1970: "
      , tm
      , "or"
      , format(tm, ".2e")
      , "in scientific notation"
      )
print(time.strftime("%B %d %Y"))



