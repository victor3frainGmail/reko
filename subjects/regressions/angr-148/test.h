// test.h
// Generated by decompiling test
// using Reko decompiler version 0.6.2.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals" (40053D Eq_28 t40053D) (400550 Eq_31 t400550) (4005C0 Eq_32 t4005C0) (600E10 (arr Eq_218) a600E10) (600E20 word64 qw600E20) (600FF8 word64 qw600FF8) (601040 byte b601040))
	globals_t (in globals : (ptr (struct "Globals")))
Eq_17: (fn void ())
	T_17 (in rdx : (ptr Eq_17))
	T_33 (in rtld_fini : (ptr (fn void ())))
Eq_20: (fn void (ptr64))
	T_20 (in __align : ptr64)
Eq_26: (fn int32 ((ptr Eq_28), Eq_29, (ptr (ptr char)), (ptr Eq_31), (ptr Eq_32), (ptr Eq_17), (ptr void)))
	T_26 (in __libc_start_main : ptr64)
	T_27 (in signature of __libc_start_main : void)
Eq_28: (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char))))
	T_28 (in main : (ptr (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char))))))
	T_35 (in 0x000000000040053D : word64)
Eq_29: (union "Eq_29" (int32 u0) (word64 u1))
	T_29 (in argc : int32)
	T_36 (in qwArg00 : word64)
Eq_31: (fn void ())
	T_31 (in init : (ptr (fn void ())))
	T_38 (in 0x0000000000400550 : word64)
Eq_32: (fn void ())
	T_32 (in fini : (ptr (fn void ())))
	T_39 (in 0x00000000004005C0 : word64)
Eq_45: (fn void ())
	T_45 (in __hlt : ptr64)
Eq_73: (union "Eq_73" (word32 u0) ((ptr code) u1))
	T_73 (in 0x00000000 : word32)
Eq_79: (union "Eq_79" (int64 u0) (uint64 u1))
	T_79 (in rdx_13 : Eq_79)
	T_83 (in rax_4 >> 0x0000000000000003 >> 0x000000000000003F : word64)
Eq_81: (union "Eq_81" (int64 u0) (uint64 u1))
	T_81 (in rax_4 >> 0x0000000000000003 : word64)
Eq_84: (union "Eq_84" (int64 u0) (uint64 u1))
	T_84 (in rax_4 >> 0x0000000000000003 : word64)
Eq_85: (union "Eq_85" (int64 u0) (uint64 u1))
	T_85 (in (rax_4 >> 0x0000000000000003) + rdx_13 : word64)
Eq_90: (union "Eq_90" (int64 u0) (uint64 u1))
	T_90 (in rdx_45 : Eq_90)
	T_92 (in DPB(rdx_13, 0x00000000, 0) : word64)
	T_93 (in 0x0000000000000000 : word64)
Eq_108: (union "Eq_108" (word32 u0) ((ptr code) u1))
	T_108 (in 0x00000000 : word32)
Eq_116: (fn word64 (word64))
	T_116 (in deregister_tm_clones : ptr64)
	T_117 (in signature of deregister_tm_clones : void)
Eq_137: (fn void (word64))
	T_137 (in register_tm_clones : ptr64)
	T_138 (in signature of register_tm_clones : void)
	T_162 (in register_tm_clones : ptr64)
Eq_152: (union "Eq_152" (ptr64 u0) (word32 u1))
	T_152 (in rbp : word64)
	T_153 (in dwLoc04 : word32)
	T_154 (in qwLoc04 : word64)
	T_155 (in DPB(qwLoc04, dwLoc04, 0) : word64)
	T_158 (in fp - 0x0000000000000004 : word64)
Eq_159: (union "Eq_159" (word32 u0) ((ptr code) u1))
	T_159 (in 0x00000000 : word32)
Eq_167: (fn int32 (Eq_169))
	T_167 (in putchar : ptr64)
	T_168 (in signature of putchar : void)
Eq_169: (union "Eq_169" (int32 u0) (word64 u1))
	T_169 (in ch : int32)
	T_172 (in DPB(rdi, 0x00000078, 0) : word64)
Eq_178: (fn word64 (word64))
	T_178 (in f : ptr64)
	T_179 (in signature of f : void)
Eq_185: (fn void ())
	T_185 (in _init : ptr64)
	T_186 (in signature of _init : void)
Eq_218: (union "Eq_218" (word32 u0) ((ptr code) u1))
	T_218 (in 0x0000000000600E10[rbx_28 * 0x00000008] : word32)
// Type Variables ////////////
globals_t: (in globals : (ptr (struct "Globals")))
  Class: Eq_1
  DataType: (ptr Eq_1)
  OrigDataType: (ptr (struct "Globals"))
T_2: (in rax_4 : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_3: (in 0000000000600FF8 : ptr64)
  Class: Eq_3
  DataType: (ptr word64)
  OrigDataType: (ptr (struct (0 T_6 t0000)))
T_4: (in 0x0000000000000000 : word64)
  Class: Eq_4
  DataType: word64
  OrigDataType: word64
T_5: (in 0x0000000000600FF8 + 0x0000000000000000 : word64)
  Class: Eq_5
  DataType: ptr64
  OrigDataType: ptr64
T_6: (in Mem0[0x0000000000600FF8 + 0x0000000000000000:word64] : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_7: (in 0x0000000000000000 : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_8: (in rax_4 == 0x0000000000000000 : bool)
  Class: Eq_8
  DataType: bool
  OrigDataType: bool
T_9: (in rsp_15 : word64)
  Class: Eq_9
  DataType: word64
  OrigDataType: word64
T_10: (in SCZO_16 : byte)
  Class: Eq_10
  DataType: byte
  OrigDataType: byte
T_11: (in rax_17 : word64)
  Class: Eq_11
  DataType: word64
  OrigDataType: word64
T_12: (in SZO_18 : byte)
  Class: Eq_12
  DataType: byte
  OrigDataType: byte
T_13: (in C_19 : byte)
  Class: Eq_13
  DataType: byte
  OrigDataType: byte
T_14: (in Z_20 : byte)
  Class: Eq_14
  DataType: byte
  OrigDataType: byte
T_15: (in __gmon_start__ : ptr64)
  Class: Eq_15
  DataType: (ptr code)
  OrigDataType: (ptr code)
T_16: (in rax : word64)
  Class: Eq_16
  DataType: word64
  OrigDataType: word64
T_17: (in rdx : (ptr Eq_17))
  Class: Eq_17
  DataType: (ptr Eq_17)
  OrigDataType: (ptr (fn void ()))
T_18: (in qwArg00 : word64)
  Class: Eq_18
  DataType: word64
  OrigDataType: word64
T_19: (in dwArg04 : word32)
  Class: Eq_19
  DataType: word32
  OrigDataType: word32
T_20: (in __align : ptr64)
  Class: Eq_20
  DataType: (ptr Eq_20)
  OrigDataType: (ptr (fn T_24 (T_23)))
T_21: (in fp : ptr64)
  Class: Eq_21
  DataType: ptr64
  OrigDataType: ptr64
T_22: (in 0x0000000000000008 : word64)
  Class: Eq_22
  DataType: int64
  OrigDataType: int64
T_23: (in fp + 0x0000000000000008 : word64)
  Class: Eq_23
  DataType: ptr64
  OrigDataType: ptr64
T_24: (in __align(fp + 0x0000000000000008) : void)
  Class: Eq_24
  DataType: void
  OrigDataType: void
T_25: (in rax_21 : word64)
  Class: Eq_25
  DataType: word64
  OrigDataType: word64
T_26: (in __libc_start_main : ptr64)
  Class: Eq_26
  DataType: (ptr Eq_26)
  OrigDataType: (ptr (fn T_43 (T_35, T_36, T_37, T_38, T_39, T_17, T_42)))
T_27: (in signature of __libc_start_main : void)
  Class: Eq_26
  DataType: (ptr Eq_26)
  OrigDataType: 
T_28: (in main : (ptr (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char))))))
  Class: Eq_28
  DataType: (ptr Eq_28)
  OrigDataType: 
T_29: (in argc : int32)
  Class: Eq_29
  DataType: Eq_29
  OrigDataType: 
T_30: (in ubp_av : (ptr (ptr char)))
  Class: Eq_30
  DataType: (ptr (ptr char))
  OrigDataType: 
T_31: (in init : (ptr (fn void ())))
  Class: Eq_31
  DataType: (ptr Eq_31)
  OrigDataType: 
T_32: (in fini : (ptr (fn void ())))
  Class: Eq_32
  DataType: (ptr Eq_32)
  OrigDataType: 
T_33: (in rtld_fini : (ptr (fn void ())))
  Class: Eq_17
  DataType: (ptr Eq_17)
  OrigDataType: 
T_34: (in stack_end : (ptr void))
  Class: Eq_34
  DataType: (ptr void)
  OrigDataType: 
T_35: (in 0x000000000040053D : word64)
  Class: Eq_28
  DataType: (ptr Eq_28)
  OrigDataType: (ptr (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char)))))
T_36: (in qwArg00 : word64)
  Class: Eq_29
  DataType: Eq_29
  OrigDataType: (union (int32 u1) (word64 u0))
T_37: (in fp + 0x0000000000000008 : word64)
  Class: Eq_30
  DataType: (ptr (ptr char))
  OrigDataType: (ptr (ptr char))
T_38: (in 0x0000000000400550 : word64)
  Class: Eq_31
  DataType: (ptr Eq_31)
  OrigDataType: (ptr (fn void ()))
T_39: (in 0x00000000004005C0 : word64)
  Class: Eq_32
  DataType: (ptr Eq_32)
  OrigDataType: (ptr (fn void ()))
T_40: (in 0x0000000000000004 : word64)
  Class: Eq_40
  DataType: int64
  OrigDataType: int64
T_41: (in fp + 0x0000000000000004 : word64)
  Class: Eq_41
  DataType: ptr64
  OrigDataType: ptr64
T_42: (in DPB(qwArg00, fp + 0x0000000000000004, 0) : word64)
  Class: Eq_34
  DataType: (ptr void)
  OrigDataType: (ptr void)
T_43: (in __libc_start_main(&globals->t40053D, qwArg00, fp + 0x0000000000000008, &globals->t400550, &globals->t4005C0, rdx, DPB(qwArg00, fp + 0x0000000000000004, 0)) : int32)
  Class: Eq_43
  DataType: int32
  OrigDataType: int32
T_44: (in DPB(rax, __libc_start_main(&globals->t40053D, qwArg00, fp + 0x0000000000000008, &globals->t400550, &globals->t4005C0, rdx, DPB(qwArg00, fp + 0x0000000000000004, 0)), 0) : word64)
  Class: Eq_25
  DataType: word64
  OrigDataType: word64
T_45: (in __hlt : ptr64)
  Class: Eq_45
  DataType: (ptr Eq_45)
  OrigDataType: (ptr (fn T_46 ()))
T_46: (in __hlt() : void)
  Class: Eq_46
  DataType: void
  OrigDataType: void
T_47: (in rsp : ptr64)
  Class: Eq_47
  DataType: ptr64
  OrigDataType: word64
T_48: (in r8 : word64)
  Class: Eq_48
  DataType: word64
  OrigDataType: word64
T_49: (in rax : word64)
  Class: Eq_49
  DataType: word64
  OrigDataType: word64
T_50: (in 0x00601047 : word32)
  Class: Eq_50
  DataType: word32
  OrigDataType: word32
T_51: (in DPB(rax, 0x00601047, 0) : word64)
  Class: Eq_51
  DataType: uint64
  OrigDataType: uint64
T_52: (in 0x000000000000000E : word64)
  Class: Eq_51
  DataType: uint64
  OrigDataType: uint64
T_53: (in DPB(rax, 0x00601047, 0) > 0x000000000000000E : bool)
  Class: Eq_53
  DataType: bool
  OrigDataType: bool
T_54: (in rax_37 : word64)
  Class: Eq_54
  DataType: word64
  OrigDataType: word64
T_55: (in 0x00000000 : word32)
  Class: Eq_55
  DataType: word32
  OrigDataType: word32
T_56: (in DPB(rax, 0x00000000, 0) : word64)
  Class: Eq_54
  DataType: word64
  OrigDataType: word64
T_57: (in 0x0000000000000000 : word64)
  Class: Eq_54
  DataType: word64
  OrigDataType: word64
T_58: (in rax_37 == 0x0000000000000000 : bool)
  Class: Eq_58
  DataType: bool
  OrigDataType: bool
T_59: (in fp : ptr64)
  Class: Eq_59
  DataType: ptr64
  OrigDataType: ptr64
T_60: (in 0x0000000000000004 : word64)
  Class: Eq_60
  DataType: int64
  OrigDataType: int64
T_61: (in fp + 0x0000000000000004 : word64)
  Class: Eq_47
  DataType: ptr64
  OrigDataType: ptr64
T_62: (in rsp_44 : ptr64)
  Class: Eq_47
  DataType: ptr64
  OrigDataType: word64
T_63: (in eax_45 : word32)
  Class: Eq_63
  DataType: word32
  OrigDataType: word32
T_64: (in rbp_46 : word64)
  Class: Eq_64
  DataType: word64
  OrigDataType: word64
T_65: (in r8_47 : word64)
  Class: Eq_65
  DataType: word64
  OrigDataType: word64
T_66: (in SCZO_48 : byte)
  Class: Eq_66
  DataType: byte
  OrigDataType: byte
T_67: (in rax_49 : word64)
  Class: Eq_67
  DataType: word64
  OrigDataType: word64
T_68: (in CZ_50 : byte)
  Class: Eq_68
  DataType: byte
  OrigDataType: byte
T_69: (in SZO_51 : byte)
  Class: Eq_69
  DataType: byte
  OrigDataType: byte
T_70: (in C_52 : byte)
  Class: Eq_70
  DataType: byte
  OrigDataType: byte
T_71: (in Z_53 : byte)
  Class: Eq_71
  DataType: byte
  OrigDataType: byte
T_72: (in edi_54 : word32)
  Class: Eq_72
  DataType: word32
  OrigDataType: word32
T_73: (in 0x00000000 : word32)
  Class: Eq_73
  DataType: word32
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_74: (in r8 : word64)
  Class: Eq_74
  DataType: word64
  OrigDataType: word64
T_75: (in rax_4 : int64)
  Class: Eq_75
  DataType: int64
  OrigDataType: int64
T_76: (in rax : word64)
  Class: Eq_76
  DataType: word64
  OrigDataType: word64
T_77: (in 0x00601040 : word32)
  Class: Eq_77
  DataType: word32
  OrigDataType: word32
T_78: (in DPB(rax, 0x00601040, 0) : word64)
  Class: Eq_75
  DataType: int64
  OrigDataType: word64
T_79: (in rdx_13 : Eq_79)
  Class: Eq_79
  DataType: Eq_79
  OrigDataType: (union (int64 u1) (uint64 u0))
T_80: (in 0x0000000000000003 : word64)
  Class: Eq_80
  DataType: word64
  OrigDataType: word64
T_81: (in rax_4 >> 0x0000000000000003 : word64)
  Class: Eq_81
  DataType: Eq_81
  OrigDataType: (union (int64 u0) (uint64 u1))
T_82: (in 0x000000000000003F : word64)
  Class: Eq_82
  DataType: word64
  OrigDataType: word64
T_83: (in rax_4 >> 0x0000000000000003 >> 0x000000000000003F : word64)
  Class: Eq_79
  DataType: Eq_79
  OrigDataType: uint64
T_84: (in rax_4 >> 0x0000000000000003 : word64)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: (union (int64 u1) (uint64 u0))
T_85: (in (rax_4 >> 0x0000000000000003) + rdx_13 : word64)
  Class: Eq_85
  DataType: Eq_85
  OrigDataType: (union (int64 u1) (uint64 u0))
T_86: (in 0x0000000000000001 : word64)
  Class: Eq_86
  DataType: word64
  OrigDataType: word64
T_87: (in (rax_4 >> 0x0000000000000003) + rdx_13 >> 0x0000000000000001 : word64)
  Class: Eq_87
  DataType: int64
  OrigDataType: int64
T_88: (in 0x0000000000000000 : word64)
  Class: Eq_87
  DataType: int64
  OrigDataType: word64
T_89: (in (rax_4 >> 0x0000000000000003) + rdx_13 >> 0x0000000000000001 != 0x0000000000000000 : bool)
  Class: Eq_89
  DataType: bool
  OrigDataType: bool
T_90: (in rdx_45 : Eq_90)
  Class: Eq_90
  DataType: Eq_90
  OrigDataType: (union (int64 u1) (uint64 u0))
T_91: (in 0x00000000 : word32)
  Class: Eq_91
  DataType: word32
  OrigDataType: word32
T_92: (in DPB(rdx_13, 0x00000000, 0) : word64)
  Class: Eq_90
  DataType: Eq_90
  OrigDataType: (union (int64 u1) (uint64 u0))
T_93: (in 0x0000000000000000 : word64)
  Class: Eq_90
  DataType: int64
  OrigDataType: word64
T_94: (in rdx_45 == 0x0000000000000000 : bool)
  Class: Eq_94
  DataType: bool
  OrigDataType: bool
T_95: (in rsp_53 : word64)
  Class: Eq_95
  DataType: word64
  OrigDataType: word64
T_96: (in eax_54 : word32)
  Class: Eq_96
  DataType: word32
  OrigDataType: word32
T_97: (in rbp_55 : word64)
  Class: Eq_97
  DataType: word64
  OrigDataType: word64
T_98: (in r8_56 : word64)
  Class: Eq_98
  DataType: word64
  OrigDataType: word64
T_99: (in SCZO_57 : byte)
  Class: Eq_99
  DataType: byte
  OrigDataType: byte
T_100: (in rax_58 : word64)
  Class: Eq_100
  DataType: word64
  OrigDataType: word64
T_101: (in rdx_59 : word64)
  Class: Eq_101
  DataType: word64
  OrigDataType: word64
T_102: (in Z_60 : byte)
  Class: Eq_102
  DataType: byte
  OrigDataType: byte
T_103: (in edx_61 : word32)
  Class: Eq_103
  DataType: word32
  OrigDataType: word32
T_104: (in SZO_62 : byte)
  Class: Eq_104
  DataType: byte
  OrigDataType: byte
T_105: (in C_63 : byte)
  Class: Eq_105
  DataType: byte
  OrigDataType: byte
T_106: (in rsi_64 : word64)
  Class: Eq_106
  DataType: word64
  OrigDataType: word64
T_107: (in edi_65 : word32)
  Class: Eq_107
  DataType: word32
  OrigDataType: word32
T_108: (in 0x00000000 : word32)
  Class: Eq_108
  DataType: word32
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_109: (in r8 : word64)
  Class: Eq_48
  DataType: word64
  OrigDataType: word64
T_110: (in 0000000000601040 : ptr64)
  Class: Eq_110
  DataType: (ptr byte)
  OrigDataType: (ptr (struct (0 T_113 t0000)))
T_111: (in 0x0000000000000000 : word64)
  Class: Eq_111
  DataType: word64
  OrigDataType: word64
T_112: (in 0x0000000000601040 + 0x0000000000000000 : word64)
  Class: Eq_112
  DataType: ptr64
  OrigDataType: ptr64
T_113: (in Mem0[0x0000000000601040 + 0x0000000000000000:byte] : byte)
  Class: Eq_113
  DataType: byte
  OrigDataType: byte
T_114: (in 0x00 : byte)
  Class: Eq_113
  DataType: byte
  OrigDataType: byte
T_115: (in *&globals->b601040 != 0x00 : bool)
  Class: Eq_115
  DataType: bool
  OrigDataType: bool
T_116: (in deregister_tm_clones : ptr64)
  Class: Eq_116
  DataType: (ptr Eq_116)
  OrigDataType: (ptr (fn T_118 (T_109)))
T_117: (in signature of deregister_tm_clones : void)
  Class: Eq_116
  DataType: (ptr Eq_116)
  OrigDataType: 
T_118: (in deregister_tm_clones(r8) : word64)
  Class: Eq_118
  DataType: word64
  OrigDataType: word64
T_119: (in 0x01 : byte)
  Class: Eq_119
  DataType: byte
  OrigDataType: byte
T_120: (in 0000000000601040 : ptr64)
  Class: Eq_120
  DataType: (ptr byte)
  OrigDataType: (ptr (struct (0 T_123 t0000)))
T_121: (in 0x0000000000000000 : word64)
  Class: Eq_121
  DataType: word64
  OrigDataType: word64
T_122: (in 0x0000000000601040 + 0x0000000000000000 : word64)
  Class: Eq_122
  DataType: ptr64
  OrigDataType: ptr64
T_123: (in Mem17[0x0000000000601040 + 0x0000000000000000:byte] : byte)
  Class: Eq_119
  DataType: byte
  OrigDataType: byte
T_124: (in r8 : word64)
  Class: Eq_74
  DataType: word64
  OrigDataType: word64
T_125: (in fp : ptr64)
  Class: Eq_125
  DataType: ptr64
  OrigDataType: ptr64
T_126: (in rsp : word64)
  Class: Eq_125
  DataType: ptr64
  OrigDataType: ptr64
T_127: (in 0000000000600E20 : ptr64)
  Class: Eq_127
  DataType: (ptr word64)
  OrigDataType: (ptr (struct (0 T_130 t0000)))
T_128: (in 0x0000000000000000 : word64)
  Class: Eq_128
  DataType: word64
  OrigDataType: word64
T_129: (in 0x0000000000600E20 + 0x0000000000000000 : word64)
  Class: Eq_129
  DataType: ptr64
  OrigDataType: ptr64
T_130: (in Mem0[0x0000000000600E20 + 0x0000000000000000:word64] : word64)
  Class: Eq_130
  DataType: word64
  OrigDataType: word64
T_131: (in 0x0000000000000000 : word64)
  Class: Eq_131
  DataType: word64
  OrigDataType: word64
T_132: (in *&globals->qw600E20 - 0x0000000000000000 : word64)
  Class: Eq_132
  DataType: word64
  OrigDataType: word64
T_133: (in cond(*&globals->qw600E20 - 0x0000000000000000) : byte)
  Class: Eq_133
  DataType: byte
  OrigDataType: byte
T_134: (in SCZO : byte)
  Class: Eq_133
  DataType: byte
  OrigDataType: byte
T_135: (in Z : byte)
  Class: Eq_133
  DataType: byte
  OrigDataType: byte
T_136: (in Test(EQ,Z) : bool)
  Class: Eq_136
  DataType: Eq_136
  OrigDataType: 
T_137: (in register_tm_clones : ptr64)
  Class: Eq_137
  DataType: (ptr Eq_137)
  OrigDataType: (ptr (fn T_139 (T_124)))
T_138: (in signature of register_tm_clones : void)
  Class: Eq_137
  DataType: (ptr Eq_137)
  OrigDataType: 
T_139: (in register_tm_clones(r8) : void)
  Class: Eq_139
  DataType: void
  OrigDataType: void
T_140: (in 0x00000000 : word32)
  Class: Eq_140
  DataType: word32
  OrigDataType: word32
T_141: (in eax : word32)
  Class: Eq_140
  DataType: word32
  OrigDataType: word32
T_142: (in rax : word64)
  Class: Eq_142
  DataType: ui64
  OrigDataType: ui64
T_143: (in DPB(rax, eax, 0) : word64)
  Class: Eq_142
  DataType: ui64
  OrigDataType: word64
T_144: (in rax & rax : word64)
  Class: Eq_144
  DataType: ui64
  OrigDataType: ui64
T_145: (in cond(rax & rax) : byte)
  Class: Eq_133
  DataType: byte
  OrigDataType: byte
T_146: (in SZO : byte)
  Class: Eq_133
  DataType: byte
  OrigDataType: byte
T_147: (in false : bool)
  Class: Eq_147
  DataType: bool
  OrigDataType: bool
T_148: (in C : byte)
  Class: Eq_147
  DataType: bool
  OrigDataType: bool
T_149: (in Test(EQ,Z) : bool)
  Class: Eq_149
  DataType: Eq_149
  OrigDataType: 
T_150: (in 0x0000000000000004 : word64)
  Class: Eq_150
  DataType: ui64
  OrigDataType: ui64
T_151: (in fp - 0x0000000000000004 : word64)
  Class: Eq_125
  DataType: ptr64
  OrigDataType: ptr64
T_152: (in rbp : word64)
  Class: Eq_152
  DataType: Eq_152
  OrigDataType: ptr64
T_153: (in dwLoc04 : word32)
  Class: Eq_152
  DataType: Eq_152
  OrigDataType: (union (ptr64 u1) (word32 u0))
T_154: (in qwLoc04 : word64)
  Class: Eq_152
  DataType: Eq_152
  OrigDataType: word64
T_155: (in DPB(qwLoc04, dwLoc04, 0) : word64)
  Class: Eq_152
  DataType: Eq_152
  OrigDataType: word64
T_156: (in 0x00600E20 : word32)
  Class: Eq_156
  DataType: word32
  OrigDataType: word32
T_157: (in edi : word32)
  Class: Eq_156
  DataType: word32
  OrigDataType: word32
T_158: (in fp - 0x0000000000000004 : word64)
  Class: Eq_152
  DataType: Eq_152
  OrigDataType: ptr64
T_159: (in 0x00000000 : word32)
  Class: Eq_159
  DataType: word32
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_160: (in 0x0000000000000004 : word64)
  Class: Eq_160
  DataType: int64
  OrigDataType: int64
T_161: (in fp + 0x0000000000000004 : word64)
  Class: Eq_125
  DataType: ptr64
  OrigDataType: ptr64
T_162: (in register_tm_clones : ptr64)
  Class: Eq_137
  DataType: (ptr Eq_137)
  OrigDataType: (ptr (fn T_163 (T_124)))
T_163: (in register_tm_clones(r8) : void)
  Class: Eq_139
  DataType: void
  OrigDataType: void
T_164: (in rsp : ptr64)
  Class: Eq_164
  DataType: ptr64
  OrigDataType: word64
T_165: (in rax : word64)
  Class: Eq_165
  DataType: word64
  OrigDataType: word64
T_166: (in rax_11 : word64)
  Class: Eq_166
  DataType: word64
  OrigDataType: word64
T_167: (in putchar : ptr64)
  Class: Eq_167
  DataType: (ptr Eq_167)
  OrigDataType: (ptr (fn T_173 (T_172)))
T_168: (in signature of putchar : void)
  Class: Eq_167
  DataType: (ptr Eq_167)
  OrigDataType: 
T_169: (in ch : int32)
  Class: Eq_169
  DataType: Eq_169
  OrigDataType: 
T_170: (in rdi : word64)
  Class: Eq_170
  DataType: word64
  OrigDataType: word64
T_171: (in 0x00000078 : word32)
  Class: Eq_171
  DataType: word32
  OrigDataType: word32
T_172: (in DPB(rdi, 0x00000078, 0) : word64)
  Class: Eq_169
  DataType: Eq_169
  OrigDataType: (union (int32 u1) (word64 u0))
T_173: (in putchar(DPB(rdi, 0x00000078, 0)) : int32)
  Class: Eq_173
  DataType: int32
  OrigDataType: int32
T_174: (in DPB(rax, putchar(DPB(rdi, 0x00000078, 0)), 0) : word64)
  Class: Eq_166
  DataType: word64
  OrigDataType: word64
T_175: (in fp : ptr64)
  Class: Eq_175
  DataType: ptr64
  OrigDataType: ptr64
T_176: (in 0x0000000000000004 : word64)
  Class: Eq_176
  DataType: int64
  OrigDataType: int64
T_177: (in fp + 0x0000000000000004 : word64)
  Class: Eq_164
  DataType: ptr64
  OrigDataType: ptr64
T_178: (in f : ptr64)
  Class: Eq_178
  DataType: (ptr Eq_178)
  OrigDataType: (ptr (fn T_183 (T_182)))
T_179: (in signature of f : void)
  Class: Eq_178
  DataType: (ptr Eq_178)
  OrigDataType: 
T_180: (in rax : word64)
  Class: Eq_180
  DataType: word64
  OrigDataType: word64
T_181: (in 0x00000000 : word32)
  Class: Eq_181
  DataType: word32
  OrigDataType: word32
T_182: (in DPB(rax, 0x00000000, 0) : word64)
  Class: Eq_165
  DataType: word64
  OrigDataType: word64
T_183: (in f(DPB(rax, 0x00000000, 0)) : word64)
  Class: Eq_183
  DataType: word64
  OrigDataType: word64
T_184: (in rsi : word64)
  Class: Eq_184
  DataType: word64
  OrigDataType: word64
T_185: (in _init : ptr64)
  Class: Eq_185
  DataType: (ptr Eq_185)
  OrigDataType: (ptr (fn T_187 ()))
T_186: (in signature of _init : void)
  Class: Eq_185
  DataType: (ptr Eq_185)
  OrigDataType: 
T_187: (in _init() : void)
  Class: Eq_187
  DataType: void
  OrigDataType: void
T_188: (in rbx_28 : ui64)
  Class: Eq_188
  DataType: ui64
  OrigDataType: ui64
T_189: (in rbx : word64)
  Class: Eq_189
  DataType: word64
  OrigDataType: word64
T_190: (in 0x00000000 : word32)
  Class: Eq_190
  DataType: word32
  OrigDataType: word32
T_191: (in DPB(rbx, 0x00000000, 0) : word64)
  Class: Eq_188
  DataType: ui64
  OrigDataType: word64
T_192: (in 0000000000600E18 : ptr64)
  Class: Eq_192
  DataType: ptr64
  OrigDataType: ptr64
T_193: (in 0000000000600E10 : ptr64)
  Class: Eq_193
  DataType: ptr64
  OrigDataType: ptr64
T_194: (in 0x0000000000600E18 - 0x0000000000600E10 : word64)
  Class: Eq_194
  DataType: Eq_194
  OrigDataType: 
T_195: (in 0x0000000000000003 : word64)
  Class: Eq_195
  DataType: Eq_195
  OrigDataType: 
T_196: (in 0x0000000000600E18 - 0x0000000000600E10 >> 0x0000000000000003 : word64)
  Class: Eq_196
  DataType: Eq_196
  OrigDataType: 
T_197: (in 0x0000000000000000 : word64)
  Class: Eq_196
  DataType: Eq_196
  OrigDataType: 
T_198: (in 0x0000000000600E18 - 0x0000000000600E10 >> 0x0000000000000003 == 0x0000000000000000 : bool)
  Class: Eq_198
  DataType: Eq_198
  OrigDataType: 
T_199: (in rsp_69 : word64)
  Class: Eq_199
  DataType: word64
  OrigDataType: word64
T_200: (in rdi_70 : word64)
  Class: Eq_200
  DataType: word64
  OrigDataType: word64
T_201: (in r15d_71 : word32)
  Class: Eq_201
  DataType: word32
  OrigDataType: word32
T_202: (in edi_72 : word32)
  Class: Eq_202
  DataType: word32
  OrigDataType: word32
T_203: (in rsi_73 : word64)
  Class: Eq_203
  DataType: word64
  OrigDataType: word64
T_204: (in r14_74 : word64)
  Class: Eq_204
  DataType: word64
  OrigDataType: word64
T_205: (in rbp_75 : word64)
  Class: Eq_205
  DataType: word64
  OrigDataType: word64
T_206: (in r13_76 : word64)
  Class: Eq_206
  DataType: word64
  OrigDataType: word64
T_207: (in rdx_77 : word64)
  Class: Eq_207
  DataType: word64
  OrigDataType: word64
T_208: (in r12_78 : word64)
  Class: Eq_208
  DataType: word64
  OrigDataType: word64
T_209: (in rbx_79 : word64)
  Class: Eq_209
  DataType: word64
  OrigDataType: word64
T_210: (in SCZO_80 : byte)
  Class: Eq_210
  DataType: byte
  OrigDataType: byte
T_211: (in ebx_81 : word32)
  Class: Eq_211
  DataType: word32
  OrigDataType: word32
T_212: (in SZO_82 : byte)
  Class: Eq_212
  DataType: byte
  OrigDataType: byte
T_213: (in C_83 : byte)
  Class: Eq_213
  DataType: byte
  OrigDataType: byte
T_214: (in Z_84 : byte)
  Class: Eq_214
  DataType: byte
  OrigDataType: byte
T_215: (in 0000000000600E10 : ptr64)
  Class: Eq_215
  DataType: (ptr (arr Eq_218))
  OrigDataType: (ptr (struct (0 (arr T_222) a0000)))
T_216: (in 0x00000008 : word32)
  Class: Eq_216
  DataType: ui32
  OrigDataType: ui32
T_217: (in rbx_28 * 0x00000008 : word64)
  Class: Eq_217
  DataType: ui64
  OrigDataType: ui64
T_218: (in 0x0000000000600E10[rbx_28 * 0x00000008] : word32)
  Class: Eq_218
  DataType: Eq_218
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_219: (in 0x0000000000000001 : word64)
  Class: Eq_219
  DataType: word64
  OrigDataType: word64
T_220: (in rbx_79 + 0x0000000000000001 : word64)
  Class: Eq_205
  DataType: word64
  OrigDataType: word64
T_221: (in rbx_79 + 0x0000000000000001 != rbp_75 : bool)
  Class: Eq_221
  DataType: bool
  OrigDataType: bool
T_222:
  Class: Eq_222
  DataType: Eq_218
  OrigDataType: (struct 0008 (0 T_218 t0000))
*/
typedef struct Globals {
	Eq_28 t40053D;	// 40053D
	Eq_31 t400550;	// 400550
	Eq_32 t4005C0;	// 4005C0
	Eq_218 a600E10[];	// 600E10
	word64 qw600E20;	// 600E20
	word64 qw600FF8;	// 600FF8
	byte b601040;	// 601040
} Eq_1;

typedef void (Eq_17)();

typedef void (Eq_20)(ptr64);

typedef int32 (Eq_26)( *, Eq_29, char * *,  *,  *,  *, void);

typedef int32 (Eq_28)(int32 rdi, char * * rsi, char * * rdx);

typedef union Eq_29 {
	int32 u0;
	word64 u1;
} Eq_29;

typedef void (Eq_31)();

typedef void (Eq_32)();

typedef void (Eq_45)();

typedef union Eq_73 {
	word32 u0;
	<anonymous> * u1;
} Eq_73;

typedef union Eq_79 {
	int64 u0;
	uint64 u1;
} Eq_79;

typedef union Eq_81 {
	int64 u0;
	uint64 u1;
} Eq_81;

typedef union Eq_84 {
	int64 u0;
	uint64 u1;
} Eq_84;

typedef union Eq_85 {
	int64 u0;
	uint64 u1;
} Eq_85;

typedef union Eq_90 {
	int64 u0;
	uint64 u1;
} Eq_90;

typedef union Eq_108 {
	word32 u0;
	<anonymous> * u1;
} Eq_108;

typedef word64 (Eq_116)(word64);

typedef void (Eq_137)(word64);

typedef union Eq_152 {
	ptr64 u0;
	word32 u1;
} Eq_152;

typedef union Eq_159 {
	word32 u0;
	<anonymous> * u1;
} Eq_159;

typedef int32 (Eq_167)(Eq_169);

typedef union Eq_169 {
	int32 u0;
	word64 u1;
} Eq_169;

typedef word64 (Eq_178)(word64);

typedef void (Eq_185)();

typedef union Eq_218 {
	word32 u0;
	<anonymous> * u1;
} Eq_218;

