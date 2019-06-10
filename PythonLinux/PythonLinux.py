#!/usr/bin/env python3

import ptvsd
ptvsd.enable_attach()
ptvsd.wait_for_attach()

import xpl
#from xpl import time
print('start')
date = xpl.time.Date.new(2015, 3, 31)
print(date)