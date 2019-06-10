from ctypes import *
from enum import Enum

lib = cdll.LoadLibrary("C:\\Users\\kendo\\source\\repos\\CppLinuxApp\\x64\\Debug\\CppWindowsLibWrapper.dll")

lib.xpl_xxx_cstr_del_.argtypes = [c_void_p]
lib.xpl_xxx_cstr_del_.restype = None


lib.xpl_time_Weekday_Sun_.argtypes = []
lib.xpl_time_Weekday_Sun_.restype = c_int

lib.xpl_time_Weekday_Mon_.argtypes = []
lib.xpl_time_Weekday_Mon_.restype = c_int

lib.xpl_time_Weekday_Tue_.argtypes = []
lib.xpl_time_Weekday_Tue_.restype = c_int

lib.xpl_time_Weekday_Wed_.argtypes = []
lib.xpl_time_Weekday_Wed_.restype = c_int

lib.xpl_time_Weekday_Thu_.argtypes = []
lib.xpl_time_Weekday_Thu_.restype = c_int

lib.xpl_time_Weekday_Fri_.argtypes = []
lib.xpl_time_Weekday_Fri_.restype = c_int

lib.xpl_time_Weekday_Sat_.argtypes = []
lib.xpl_time_Weekday_Sat_.restype = c_int

class Weekday(Enum):
    Sun = lib.xpl_time_Weekday_Sun_()
    Mon = lib.xpl_time_Weekday_Mon_()
    Tue = lib.xpl_time_Weekday_Tue_()
    Wed = lib.xpl_time_Weekday_Wed_()
    Thu = lib.xpl_time_Weekday_Thu_()
    Fri = lib.xpl_time_Weekday_Fri_()
    Sat = lib.xpl_time_Weekday_Sat_()


lib.xpl_time_Date_new_.argtypes = [c_int, c_int, c_int]
lib.xpl_time_Date_new_.restype = c_int

lib.xpl_time_Date_cstr_new_.argtypes = [c_int]
lib.xpl_time_Date_cstr_new_.restype = c_void_p

class Date:

    def __init__(self, ref):
        self.__ref = ref

    @staticmethod
    def new(y, m, d):
        return Date(lib.xpl_time_Date_new_(y, m, d))

    def __str__(self):
        cstr = lib.xpl_time_Date_cstr_new_(self.__ref)
        pystr = str(cast(cstr, c_char_p).value)
        lib.xpl_xxx_cstr_del_(cstr)
        return pystr

