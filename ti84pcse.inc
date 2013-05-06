;TI-84 Plus C Silver Edition Include File
;03/16/2013

;Banked Call Equates/Macros
;-----------------------------------------------
rBR_CALL		equ 28h
BRT_JUMP0		equ 50h

;Common Restart Routines
;------------------------------
rOP1TOOP2		equ 08h
rFINDSYM		equ 10h
rPUSHREALO1		equ 18h
rMOV9TOOP1		equ 20h
rFPADD			equ 30h

;Error Handler Equates/Macros
;-------------------------------------------
APP_PUSH_ERRORH		equ 59h
APP_POP_ERRORH		equ 5Ch

;TI-OS ROM Calls
;--------------------------------
_JErrorNo	equ	4000h
_CallFontHook	equ	4003h
_CallLocalizeHook	equ	4006h
_ldHLind	equ	4009h
_CpHLDE	equ	400Ch
_DivHLBy10	equ	400Fh
_DivHLByA	equ	4012h
_KbdScan	equ	4015h
_GetCSC	equ	4018h
_coorMon	equ	401Bh
_Mon	equ	401Eh
_monForceKey	equ	4021h
_SendKPress	equ	4024h
_JForceCmdNoChar	equ	4027h
_JForceCmd	equ	402Ah
_sysErrHandler	equ	402Dh
_NewContext	equ	4030h
_maybe_NewContext0	equ	4033h
_maybe_PPutAwayPrompt	equ	4036h
_maybe_PPutAway	equ	4039h
_maybe_PutAway	equ	403Ch
_maybe_SizeWind	equ	403Fh
_maybe_ErrorEP	equ	4042h
_maybe_CallMain	equ	4045h
_monErrHand	equ	4048h
_maybe_AppInit	equ	404Bh
_initialize	equ	404Eh
_Min	equ	4051h
_Max	equ	4054h
_AbsO1PAbsO2	equ	4057h
_Intgr	equ	405Ah
_Trunc	equ	405Dh
_InvSub	equ	4060h
_Times2	equ	4063h
_Plus1	equ	4066h
_Minus1	equ	4069h
_FPSub	equ	406Ch
_FPAdd	equ	406Fh
_maybe_DToR	equ	4072h
_maybe_RToD	equ	4075h
_Cube	equ	4078h
_TimesPt5	equ	407Bh
_FPSquare	equ	407Eh
_FPMult	equ	4081h
_LJRnd	equ	4084h
_InvOP1SC	equ	4087h
_InvOP1S	equ	408Ah
_InvOP2S	equ	408Dh
_Frac	equ	4090h
_FPRecip	equ	4093h
_FPDiv	equ	4096h
_SqRoot	equ	4099h
_RndGuard	equ	409Ch
_RnFx	equ	409Fh
_Int	equ	40A2h
_Round	equ	40A5h
_LnX	equ	40A8h
_LogX	equ	40ABh
_LJNoRnd	equ	40AEh
_EToX	equ	40B1h
_TenX	equ	40B4h
_SinCosRad	equ	40B7h
_Sin	equ	40BAh
_Cos	equ	40BDh
_Tan	equ	40C0h
_SinHCosH	equ	40C3h
_TanH	equ	40C6h
_CosH	equ	40C9h
_SinH	equ	40CCh
_ACosRad	equ	40CFh
_ATanRad	equ	40D2h
_ATan2Rad	equ	40D5h
_ASinRad	equ	40D8h
_ACos	equ	40DBh
_ATan	equ	40DEh
_ASin	equ	40E1h
_ATan2	equ	40E4h
_ATanH	equ	40E7h
_ASinH	equ	40EAh
_ACosH	equ	40EDh
_PToR	equ	40F0h
_RToP	equ	40F3h
_HLTimes9	equ	40F6h
_CkOP1Cplx	equ	40F9h
_CkOP1Real	equ	40FCh
_Angle	equ	40FFh
_COP1Set0	equ	4102h
_CpOP4OP3	equ	4105h
_Mov9OP2Cp	equ	4108h
_AbsO1O2Cp	equ	410Bh
_CpOP1OP2	equ	410Eh
_OP3ToOP4	equ	4111h
_OP1ToOP4	equ	4114h
_OP2ToOP4	equ	4117h
_OP4ToOP2	equ	411Ah
_OP3ToOP2	equ	411Dh
_OP1ToOP3	equ	4120h
_OP5ToOP2	equ	4123h
_OP5ToOP6	equ	4126h
_OP5ToOP4	equ	4129h
_OP1ToOP2	equ	412Ch
_OP6ToOP2	equ	412Fh
_OP6ToOP1	equ	4132h
_OP4ToOP1	equ	4135h
_OP5ToOP1	equ	4138h
_OP3ToOP1	equ	413Bh
_OP6ToOP5	equ	413Eh
_OP4ToOP5	equ	4141h
_OP3ToOP5	equ	4144h
_OP2ToOP5	equ	4147h
_OP2ToOP6	equ	414Ah
_OP1ToOP6	equ	414Dh
_OP1ToOP5	equ	4150h
_OP2ToOP1	equ	4153h
_Mov11B	equ	4156h
_Mov10B	equ	4159h
_Mov9B	equ	415Ch
_Mov8B	equ	4162h
_Mov7B	equ	4165h
_OP2ToOP3	equ	416Bh
_OP4ToOP3	equ	416Eh
_OP5ToOP3	equ	4171h
_OP4ToOP6	equ	4174h
_Mov9ToOP1	equ	4177h
_Mov9OP1OP2	equ	417Ah
_Mov9ToOP2	equ	417Dh
_MovFrOP1	equ	4180h
_OP4Set1	equ	4183h
_OP3Set1	equ	4186h
_OP2Set8	equ	4189h
_OP2Set5	equ	418Ch
_OP2SetA	equ	418Fh
_OP2Set4	equ	4192h
_OP2Set3	equ	4195h
_OP1Set1	equ	4198h
_OP1Set4	equ	419Bh
_OP1Set3	equ	419Eh
_OP3Set2	equ	41A1h
_OP1Set2	equ	41A4h
_OP2Set2	equ	41A7h
_OP2Set1	equ	41AAh
_Zero16D	equ	41ADh
_OP5Set0	equ	41B0h
_OP4Set0	equ	41B3h
_OP3Set0	equ	41B6h
_OP2Set0	equ	41B9h
_OP1Set0	equ	41BCh
_SetNum0	equ	41BFh
_ZeroOP1	equ	41C2h
_ZeroOP2	equ	41C5h
_ZeroOP3	equ	41C8h
_ZeroOP	equ	41CBh
_ClrLp	equ	41CEh
_ShRAcc	equ	41D1h
_ShLAcc	equ	41D4h
_ShR18	equ	41D7h
_ShR18A	equ	41DAh
_ShR16	equ	41DDh
_ShR14	equ	41E0h
_ShL16	equ	41E3h
_ShL14	equ	41E6h
_SRDO1	equ	41E9h
_ShRDRnd	equ	41ECh
_MantPA	equ	41EFh
_ADDPROP	equ	41F2h
_ADDPROPLP	equ	41F5h
_Add16D	equ	41F8h
_Add14D	equ	41FBh
_Sub16D	equ	41FEh
_Sub14D	equ	4201h
_OP2ExOP6	equ	4204h
_OP5ExOP6	equ	4207h
_OP1ExOP5	equ	420Ah
_OP1ExOP6	equ	420Dh
_OP2ExOP4	equ	4210h
_OP2ExOP5	equ	4213h
_OP1ExOP3	equ	4216h
_OP1ExOP4	equ	4219h
_OP1ExOP2	equ	421Ch
_ExLp	equ	421Fh
_CkOP1C0	equ	4222h
_CkOP1FP0	equ	4225h
_CkOP2FP0	equ	4228h
_PosNo0Int	equ	422Bh
_CkPosInt	equ	422Eh
_CkInt	equ	4231h
_CkOdd	equ	4234h
_CkOP1M	equ	4237h
_GetCon1	equ	423Ah
_GetCon	equ	423Dh
_PIDIV2	equ	4240h
_PIDIV4	equ	4243h
_TWOPI	equ	4246h
_PICON	equ	4249h
_ExpToHex	equ	424Ch
_OP1ExpToDec	equ	424Fh
_CkOP2Pos	equ	4252h
_CkOP1Pos	equ	4255h
_ClrOP2S	equ	4258h
_ClrOP1S	equ	425Bh
_FDiv100	equ	425Eh
_FDiv10	equ	4261h
_DecO1Exp	equ	4264h
_IncO1Exp	equ	4267h
_IncExp	equ	426Ah
_CkValidNum	equ	426Dh
_GetExp	equ	4270h
_HTimesL	equ	4273h
_EOP1NotReal	equ	4276h
_ThetaName	equ	4279h
_RName	equ	427Ch
_RegEqName	equ	427Fh
_RecurNName	equ	4282h
_XName	equ	4285h
_YName	equ	4288h
_TName	equ	428Bh
_RealName	equ	428Eh
_SetEStoFPS	equ	4291h
_ChkTempDirt	equ	4294h
_OP1MOP2Exp	equ	4297h
_OP1ExpMDE	equ	429Ah
_ChkErrBreak	equ	429Dh
_IsA2ByteTok	equ	42A0h
_maybe_GetLastEntry	equ	42A3h
_maybe_GetLastEntryPtr	equ	42A6h
_maybe_RegrClrChng	equ	42A9h
_ResetWinTop	equ	42ACh
_IsO1NonTLstOrProg	equ	42AFh
_IsO1NonTempLst	equ	42B2h
_Is_A_LstOrCLst	equ	42B5h
_Chk_HL_999	equ	42B8h
_Equ_or_NewEqu	equ	42BBh
_ErrD_OP1NotPos	equ	42BEh
_ErrD_OP1Not_R	equ	42C1h
_ErrD_OP1NotPosInt	equ	42C4h
_ErrD_OP1_LE_0	equ	42C7h
_ErrD_OP1_0	equ	42CAh
_FindSym_Get_Size	equ	42CDh
_Sto_StatVar	equ	42D0h
_maybe_Rcl_StatVar	equ	42D3h
_CkOP2Real	equ	42D6h
_maybe_Get_X_Indirect	equ	42D9h
_MemChk	equ	42DCh
_CmpPrgNamLen1	equ	42DFh
_CmpPrgNamLen	equ	42E2h
_FindProgSym	equ	42E5h
_ChkFindSym	equ	42E8h
_FindSym	equ	42EBh
_InsertMem	equ	42EEh
_InsertMemA	equ	42F1h
_EnoughMem	equ	42F4h
_CmpMemNeed	equ	42F7h
_maybe_CreatePVar4	equ	42FAh
_maybe_CreatePVar3	equ	42FDh
_maybe_CreateVar3	equ	4300h
_CreateCplx	equ	4303h
_CreateReal	equ	4306h
_CreateTRList	equ	4309h
_CreateRList	equ	430Ch
_CreateTCList	equ	430Fh
_CreateCList	equ	4312h
_CreateTRMat	equ	4315h
_CreateRMat	equ	4318h
_CreateTStrng	equ	431Bh
_CreateStrng	equ	431Eh
_Create0Equ	equ	4321h
_CreateTEqu	equ	4324h
_CreateEqu	equ	4327h
_CreateGDB	equ	432Dh
_CreateProg	equ	4330h
_ChkDel	equ	4333h
_ChkDelA	equ	4336h
_AdjParser	equ	4339h
_AdjMath	equ	433Ch
_AdjM7	equ	433Fh
_DelMemA	equ	4342h
_Get_Form_Num	equ	4345h
_DelVar	equ	4348h
_DelVarIO	equ	434Bh
_DelMem	equ	434Eh
_DelVar3D	equ	4351h
_DelVar3C	equ	4354h
_DelVar3DC	equ	4357h
_Sym_Prog_Non_T_Lst	equ	435Ah
_AdjSymPtrs	equ	435Dh
_DataSizeA	equ	4360h
_DataSize	equ	4363h
_PopMCplxO1	equ	4366h
_PopMCplx	equ	4369h
_MovCplx	equ	436Ch
_PopOP5	equ	436Fh
_PopOP3	equ	4372h
_PopOP1	equ	4375h
_PopRealO6	equ	4378h
_PopRealO5	equ	437Bh
_PopRealO4	equ	437Eh
_PopRealO3	equ	4381h
_PopRealO2	equ	4384h
_PopRealO1	equ	4387h
_PopReal	equ	438Ah
_FPopCplx	equ	438Dh
_FPopReal	equ	4390h
_FPopFPS	equ	4393h
_DeallocFPS	equ	4396h
_DeallocFPS1	equ	4399h
_AllocFPS	equ	439Ch
_AllocFPS1	equ	439Fh
_PushRealO6	equ	43A2h
_PushRealO5	equ	43A5h
_PushRealO4	equ	43A8h
_PushRealO3	equ	43ABh
_PushRealO2	equ	43AEh
_PushRealO1	equ	43B1h
_PushReal	equ	43B4h
_PushOP5	equ	43B7h
_PushOP3	equ	43BAh
_PushMCplxO3	equ	43BDh
_PushOP1	equ	43C0h
_PushMCplxO1_lets_see_if_ti_screws_this_one_up	equ	43C3h
_PushMCplx	equ	43C6h
_ExMCplxO1	equ	43C9h
_Exch9	equ	43CCh
_CpyTo1FPS11	equ	43CFh
_CpyTo2FPS5	equ	43D2h
_CpyTo1FPS5	equ	43D5h
_CpyTo2FPS6	equ	43D8h
_CpyTo1FPS6	equ	43DBh
_CpyTo2FPS7	equ	43DEh
_CpyTo1FPS7	equ	43E1h
_CpyTo1FPS8	equ	43E4h
_CpyTo2FPS8	equ	43E7h
_CpyTo1FPS10	equ	43EAh
_CpyTo1FPS9	equ	43EDh
_CpyTo2FPS4	equ	43F0h
_CpyTo6FPS3	equ	43F3h
_CpyTo6FPS2	equ	43F6h
_CpyTo2FPS3	equ	43F9h
_CpyCTo1FPS3	equ	43FCh
_CpyTo1FPS3	equ	43FFh
_CpyFPS3	equ	4402h
_CpyTo1FPS4	equ	4405h
_CpyTo3FPS2	equ	4408h
_CpyTo5FPST	equ	440Bh
_CpyTo6FPST	equ	440Eh
_CpyTo4FPST	equ	4411h
_CpyTo3FPST	equ	4414h
_CpyTo2FPST	equ	4417h
_CpyTo1FPST	equ	441Ah
_CpyFPST	equ	441Dh
_CpyStack	equ	4420h
_CpyTo3FPS1	equ	4423h
_CpyTo2FPS1	equ	4426h
_CpyTo1FPS1	equ	4429h
_CpyFPS1	equ	442Ch
_CpyTo2FPS2	equ	442Fh
_CpyTo1FPS2	equ	4432h
_CpyFPS2	equ	4435h
_CpyO3ToFPST	equ	4438h
_CpyO2ToFPST	equ	443Bh
_CpyO6ToFPST	equ	443Eh
_CpyO1ToFPST	equ	4441h
_CpyToFPST	equ	4444h
_CpyToStack	equ	4447h
_CpyO3ToFPS1	equ	444Ah
_CpyO5ToFPS1	equ	444Dh
_CpyO2ToFPS1	equ	4450h
_CpyO1ToFPS1	equ	4453h
_CpyToFPS1	equ	4456h
_CpyO2ToFPS2	equ	4459h
_CpyO3ToFPS2	equ	445Ch
_CpyO6ToFPS2	equ	445Fh
_CpyO1ToFPS2	equ	4462h
_CpyToFPS2	equ	4465h
_CpyO5ToFPS3	equ	4468h
_CpyO2ToFPS3	equ	446Bh
_CpyO1ToFPS3	equ	446Eh
_CpyToFPS3	equ	4471h
_CpyO1ToFPS6	equ	4474h
_CpyO1ToFPS7	equ	4477h
_CpyO1ToFPS5	equ	447Ah
_CpyO2ToFPS4	equ	447Dh
_CpyO1ToFPS4	equ	4480h
_ErrNotEnoughMem	equ	4483h
_FPSMinus9	equ	4486h
_HLMinus9	equ	4489h
_maybe_ErrOverflow	equ	448Ch
_maybe_ErrDivBy0	equ	448Fh
_ErrSingularMat	equ	4492h
_ErrDomain	equ	4495h
_ErrIncrement	equ	4498h
_maybe_ErrNon_Real	equ	449Bh
_ErrSyntax	equ	449Eh
_ErrDataType	equ	44A1h
_ErrArgument	equ	44A4h
_ErrDimMismatch	equ	44A7h
_ErrDimension	equ	44AAh
_ErrUndefined	equ	44ADh
_ErrMemory	equ	44B0h
_maybe_ErrInvalid	equ	44B3h
_ErrBreak	equ	44B6h
_maybe_ErrStat	equ	44B9h
_ErrSignChange	equ	44BCh
_maybe_ErrIterations	equ	44BFh
_maybe_ErrBadGuess	equ	44C2h
_maybe_ErrTolTooSmall	equ	44C5h
_maybe_ErrStatPlot	equ	44C8h
_maybe_ErrLinkXmit	equ	44CBh
_JError	equ	44CEh
_noErrorEntry	equ	44D1h
_pushErrorHandler	equ	44D4h
_popErrorHandler	equ	44D7h
_StrCopy	equ	44DAh
_StrCat	equ	44DDh
_IsInSet	equ	44E0h
_GEQNAMEA	equ	44E3h
_RECNAME	equ	44E6h
___bank_call	equ	44E9h
___bank_ret	equ	44ECh
___bank_jump	equ	44EFh
___bank_entry	equ	44F2h
_PutMap	equ	44F8h
_PutC	equ	44FBh
_DispHL	equ	44FEh
_PutS	equ	4501h
_PutPSB	equ	4504h
_PutPS	equ	4507h
_WPutPS	equ	450Ah
_PutBuf	equ	450Dh
_PutBuf1	equ	4510h
_WPutC	equ	4513h
_WPutS	equ	4516h
_WPutSEOL	equ	4519h
_WDispEOL	equ	451Ch
_WHomeUp	equ	451Fh
_SetNumWindow	equ	4522h
_NewLine	equ	4525h
_MoveDown	equ	4528h
_ScrollUp	equ	452Bh
_ShrinkWindow	equ	452Eh
_MoveUp	equ	4531h
_ScrollDown	equ	4534h
_ClrLCDFull	equ	4537h
_maybe_ClrLCD	equ	453Ah
_maybe_ClrScrnFull	equ	453Dh
_maybe_ClrScrn	equ	4540h
_clrTxtShd	equ	4543h
_ClrWindow	equ	4546h
_maybe_EraseEOL	equ	4549h
_EraseEOW	equ	454Ch
_HomeUp	equ	454Fh
_GetCurLoc	equ	4552h
_VPutMap	equ	4555h
_VPutS	equ	4558h
_VPutSN	equ	455Bh
_VPutSNG	equ	455Eh
_VPutSNT	equ	4561h
_runIndicOn	equ	4564h
_runIndicOff	equ	4567h
_SaveCmdShadow	equ	456Ah
_SaveShadow	equ	456Dh
_maybe_RstrShadow	equ	4570h
_RstrPartial	equ	4573h
_RstrCurRow	equ	4576h
_RstrUnderMenu	equ	4579h
_maybe_RstrBotRow	equ	457Ch
_GetKeyPress	equ	457Fh
_GetTokLen	equ	4582h
_Get_Tok_Strng	equ	4585h
_GetTokString	equ	4588h
_maybe_PUTBPATBUF2	equ	458Bh
_maybe_PUTBPATBUF	equ	458Eh
_maybe_PUTBPAT	equ	4591h
_maybe_putcCheckScroll	equ	4594h
_maybe_DispEOL	equ	4597h
_maybe_fdispEOL	equ	459Ah
_MakeRowCmd	equ	459Dh
_TOTOSTRP	equ	45A0h
_DispDone	equ	45A6h
_FinishOutput	equ	45A9h
_CurBlink	equ	45ACh
_CursorOff	equ	45AFh
_HideCursor	equ	45B2h
_CursorOn	equ	45B5h
_ShowCursor	equ	45B8h
_KeyToString	equ	45BBh
_maybe_PullDownChk	equ	45BEh
_maybe_MenuCatCommon	equ	45C1h
_LoadCurCat	equ	45C4h
_NCifprgmedmode	equ	45C7h
_LoadMenuNum	equ	45CAh
_LoadMenuNumL	equ	45CDh
_maybe_MenuEdKey	equ	45D0h
_MenCatRet	equ	45D3h
_NotAlphNum	equ	45D6h
_DispListName	equ	45E5h
_DispLAlphaName	equ	45E8h
_AbortPrgmode	equ	45EBh
_Is_FullCntx	equ	45EEh
_AdrMRow	equ	45F1h
_AdrMEle	equ	45F4h
_GetMatOP1A	equ	45F7h
_GetM1ToOP1	equ	45FAh
_GetM1TOP1A	equ	45FDh
_GetMToOP1	equ	4600h
_PutToM1A	equ	4603h
_PutToMa1	equ	4606h
_PutToMat	equ	4609h
_Mat_El_Div	equ	460Ch
_CMATFUN	equ	460Fh
_RowEch_Poly	equ	4612h
_RowEchelon	equ	4615h
_AdrLEle	equ	4618h
_GetL1ToOP1	equ	461Bh
_GetL1TOP1A	equ	461Eh
_GetLToOP1	equ	4621h
_GetL1ToOP2	equ	4624h
_GetL1TOP2A	equ	4627h
_GetL2TOP1A	equ	462Ah
_PutToLA1	equ	462Dh
_PutToL	equ	4630h
_MaxMinLst	equ	4633h
_LLow	equ	4636h
_LHigh	equ	4639h
_LSum	equ	463Ch
_CumSum	equ	463Fh
_ToFrac	equ	4642h
_SeqSet	equ	4645h
_SeqSolve	equ	4648h
_Cmp_Num_Init	equ	464Bh
_BinOPExec	equ	464Eh
_ExMean1	equ	4651h
_Set2MVLPtrs	equ	4654h
_SetMat1	equ	4657h
_CreateTList	equ	465Ah
_UnOPExec	equ	465Dh
_ThreeExec	equ	4660h
_RestoreErrNo	equ	4663h
_FourExec	equ	4666h
_FiveExec	equ	4669h
_CpyTo2ES1	equ	466Ch
_CpyTo6ES1	equ	466Fh
_CpyTo1ES1	equ	4672h
_CpyTo3ES1	equ	4675h
_CpyTo3ES2	equ	4678h
_CpyTo2ES2	equ	467Bh
_CpyTo1ES2	equ	467Eh
_CpyTo2ES3	equ	4681h
_CpyTo1ES3	equ	4684h
_CpyTo3ES4	equ	4687h
_CpyTo6ES3	equ	468Ah
_CpyTo2ES4	equ	468Dh
_CpyTo1ES4	equ	4690h
_CpyTo2ES5	equ	4693h
_CpyTo1ES5	equ	4696h
_CpyTo4EST	equ	4699h
_CpyTo2EST	equ	469Ch
_CpyTo1EST	equ	469Fh
_CpyTo2ES6	equ	46A2h
_CpyTo1ES6	equ	46A5h
_CpyTo2ES7	equ	46A8h
_CpyTo1ES7	equ	46ABh
_CpyTo2ES8	equ	46AEh
_CpyTo1ES8	equ	46B1h
_CpyTo1ES9	equ	46B4h
_CpyTo2ES9	equ	46B7h
_CpyTo2ES10	equ	46BAh
_CpyTo1ES10	equ	46BDh
_CpyTo2ES11	equ	46C0h
_CpyTo1ES11	equ	46C3h
_CpyTo2ES12	equ	46C6h
_CpyTo1ES12	equ	46C9h
_CpyTo2ES13	equ	46CCh
_CpyTo1ES13	equ	46CFh
_CpyTo1ES14	equ	46D2h
_CpyTo1ES16	equ	46D5h
_CpyTo1ES17	equ	46D8h
_CpyTo1ES18	equ	46DBh
_CpyTo1ES15	equ	46DEh
_CpyTo2ES15	equ	46E1h
_CpyO1ToEST	equ	46E4h
_CpyO1ToES1	equ	46E7h
_CpyO6ToES1	equ	46EAh
_CpyO6ToES3	equ	46EDh
_CpyO1ToES2	equ	46F0h
_CpyO2ToES2	equ	46F3h
_CpyO1ToES3	equ	46F6h
_CpyO1ToES4	equ	46F9h
_CpyO1ToES5	equ	46FCh
_CpyO1ToES6	equ	46FFh
_CpyO1ToES7	equ	4702h
_CpyO2ToES4	equ	4705h
_CpyO2ToES5	equ	4708h
_CpyO2ToES6	equ	470Bh
_CpyO2ToES7	equ	470Eh
_CpyO2ToES8	equ	4711h
_CpyO2ToES9	equ	4714h
_CpyO1ToES8	equ	4717h
_CpyO1ToES9	equ	471Ah
_CpyO1ToES10	equ	471Dh
_CpyO1ToES11	equ	4720h
_CpyO1ToES12	equ	4723h
_CpyO1ToES13	equ	4726h
_CpyO1ToES14	equ	4729h
_EvalF3A	equ	472Ch
_GetK	equ	472Fh
_SetTitle	equ	4732h
_DispVarVal	equ	4735h
_maybe_RecallEd	equ	4738h
_maybe_SetupBuffer	equ	473Bh
_maybe_CreateNumEditBuf	equ	473Eh
_maybe_CallCommon	equ	4741h
_CommonKeys	equ	4744h
_Leftmore	equ	4747h
_fDel	equ	474Ah
_maybe_fClear	equ	474Dh
_maybe_fInsDisp	equ	4750h
_maybe_fInsDisp02	equ	4753h
_SetIndicator	equ	4756h
_CloseEditBufNoR	equ	4759h
_ReleaseBuffer	equ	475Ch
_VarNameToOP1HL	equ	475Fh
_NameToOP1	equ	4762h
_maybe_numPPutAway	equ	4765h
_maybe_numRedisp	equ	4768h
_maybe_numError02	equ	476Bh
_Load_SFont	equ	476Eh
_SFont_Len	equ	4771h
_maybe_InitNumVec	equ	4774h
_SetXXOP1	equ	4777h
_SetXXOP2	equ	477Ah
_SetXXXXOP2	equ	477Dh
_UCLineS	equ	4780h
_CLine	equ	4783h
_CLineS	equ	4786h
_XRootY	equ	4789h
_YToX	equ	478Ch
_Mov18B	equ	47C5h
_DarkLine	equ	47C8h
_ILine	equ	47CBh
_IPoint	equ	47CEh
_XYRndBoth	equ	47D1h
_XYRnd	equ	47D4h
_CheckTop	equ	47D7h
_CheckXY	equ	47DAh
_DarkPnt	equ	47DDh
_CPointS	equ	47E0h
_WToV	equ	47E3h
_VtoWHLDE	equ	47E6h
_Xitof	equ	47E9h
_YftoI	equ	47ECh
_XftoI	equ	47EFh
_maybe_GrLabels	equ	4807h
_ChkTextCurs	equ	4876h
_DoRefFlags02	equ	487Ch
_YRes	equ	487Fh
_PlotPtXY2	equ	4882h
_maybe_PDspGrph	equ	488Eh
_maybe_HorizCmd	equ	4891h
_maybe_VertCmd	equ	4894h
_maybe_LineCmd	equ	4897h
_maybe_UnLineCmd	equ	489Ah
_PutSM	equ	48C4h
_VPutBlank	equ	48DCh
_DispListNameY	equ	48E2h
_CurNameLength	equ	48E5h
_NameToBuf	equ	48E8h
_JPromptCursor	equ	48EBh
_BufLeft	equ	48EEh
_BufRight	equ	48F1h
_BufInsert	equ	48F4h
_BufQueueChar	equ	48F7h
_BufReplace	equ	48FAh
_BufDelete	equ	48FDh
_BufPeek	equ	4900h
_BufPeek1	equ	4903h
_BufPeek2	equ	4906h
_BufPeek3	equ	4909h
_BufToBtm	equ	490Ch
_SetupEditEqu	equ	490Fh
_BufToTop	equ	4912h
_IsEditFull	equ	4915h
_IsEditEmpty	equ	4918h
_IsAtTop	equ	491Bh
_IsAtBtm	equ	491Eh
_JCursorFirst	equ	4924h
_JCursorLast	equ	4927h
_CursorLeft	equ	492Ah
_JCursorRight	equ	492Dh
_JCursorUp	equ	4930h
_CursorDown	equ	4933h
_CursorToOffset	equ	4936h
_InsDisp	equ	4939h
_FDispBOL1	equ	493Ch
_FDispBOL	equ	493Fh
_DispEOW	equ	4942h
_DispHead	equ	4945h
_DispTail	equ	4948h
_PutTokString	equ	494Bh
_SetupEditCmd	equ	494Eh
_SetEmptyEditEqu	equ	4951h
_SetEmptyEditPtr	equ	4954h
_CloseEditEqu	equ	4957h
_GetPrevTok	equ	495Ah
_getkey	equ	495Dh
_FormDisp	equ	4969h
_FormMatrix	equ	496Ch
_WScrollLeft	equ	496Fh
_WScrollUp	equ	4972h
_WScrollDown	equ	4975h
_WScrollRight	equ	4978h
_FormEReal	equ	497Bh
_FormERealTok	equ	497Eh
_FormDCplx	equ	4981h
_FormReal	equ	4984h
_FormScrollUp	equ	4987h
_SetWinAbove	equ	498Ah
_DisarmScroll	equ	498Dh
_OP1toEdit	equ	4990h
_RclVarToEdit	equ	4996h
_RclVarToEditPtr	equ	4999h
_RclEntryToEdit	equ	499Ch
_RclToQueue	equ	499Fh
_Disp_Interval	equ	49A5h
_maybe_EditEqu	equ	49AEh
_maybe_CloseEquField	equ	49B1h
_maybe_AutoSelect	equ	49B4h
_DispYEOS	equ	49B7h
_DispNumEOS	equ	49BAh
_SetupDispEq	equ	49BDh
_DispForward	equ	49C0h
_DispYPrompt2	equ	49C3h
_SaveScreen	equ	49D2h
_RetScreen	equ	49D5h
_RetScreenErr	equ	49D8h
_CheckSplitFlag	equ	49DBh
_maybe_SolveRedisp	equ	49DEh
_maybe_SolveDisp	equ	49E1h
_maybe_ItemName	equ	49E4h
_ConvKeyToTok	equ	49EDh
_KeyToTokNew2B	equ	49F0h
_KeyToTok2Byte	equ	49F3h
_TokToKey	equ	49F6h
_Send1BErr	equ	49F9h
_GetVarCmd	equ	49FCh
_SendVarCmd	equ	49FFh
_KeyScnLnk	equ	4A05h
_ConvLcToLr	equ	4A0Eh
_RedimMat	equ	4A11h
_IncLstSize	equ	4A14h
_InsertList	equ	4A17h
_DelListEl	equ	4A1Ah
_EditProg	equ	4A1Dh
_CreateTemp	equ	4A38h
_CleanAll	equ 4A3Bh
_BC2NonReal	equ	4A74h
_ErrNonReal	equ	4A77h
_Write_Text	equ	4A7Ah
_ForSeqInit	equ	4A7Dh
_GrphPars	equ	4A80h
_PlotPars	equ	4A83h
_ParseInp	equ	4A86h
_ParseOff	equ	4A89h
_ParseScan	equ	4A8Ch
_GetParse	equ	4A8Fh
_SaveParse	equ	4A92h
_InitPFlgs	equ	4A95h
_CkEndLinErr	equ	4A98h
_OP2Set60	equ	4A9Bh
_GetStatPtr	equ	4A9Eh
_Cmp_StatPtr	equ	4AA1h
_VarSysAdr	equ	4AA4h
_StoSysTok	equ	4AA7h
_maybe_StoAns	equ	4AAAh
_StoTheta	equ	4AADh
_StoR	equ	4AB0h
_StoY	equ	4AB3h
_StoN	equ	4AB6h
_StoT	equ	4AB9h
_StoX	equ	4ABCh
_StoOther	equ	4ABFh
_RclAns	equ	4AC2h
_RclY	equ	4AC5h
_RclN	equ	4AC8h
_RclX	equ	4ACBh
_RclVarSym	equ	4ACEh
_RclSysTok	equ	4AD1h
_maybe_StMatEl	equ	4AD4h
_maybe_StLstVecEl	equ	4AD7h
_ConvOP1	equ	4ADAh
_Find_Parse_Formula	equ	4ADDh
_Parse_Formula	equ	4AE0h
_StrngEnt1	equ	4AE3h
_PrgRdLp	equ	4AE6h
_VarEnt	equ	4AE9h
_ParseOnC	equ	4AECh
_ParseOn	equ	4AEFh
_ParseCmd	equ	4AF2h
_StoType	equ	4AF5h
_CreatePair	equ	4AF8h
_PushNum	equ	4AFBh
_IncCurPCErrEnd	equ	4AFEh
_ErrEnd	equ	4B01h
_CommaErrF	equ	4B04h
_CommaErr	equ	4B07h
_StEqArg2	equ	4B0Ah
_StEqArg	equ	4B0Dh
_InpArg	equ	4B10h
_StEqArg3	equ	4B13h
_NxtFetch	equ	4B16h
_maybe_CkFetchVar	equ	4B19h
_maybe_FetchVarA	equ	4B1Ch
_maybe_FetchVar	equ	4B1Fh
_CkEndLin	equ	4B22h
_CkEndExp	equ	4B25h
_CkParsEnd	equ	4B28h
_StoTypeArg	equ	4B2Bh
_ConvDim	equ	4B2Eh
_ConvDim00	equ	4B31h
_maybe_ParsAheadS	equ	4B37h
_AnsName	equ	4B3Dh
_StoCmpReals	equ	4B40h
_Push2BOper	equ	4B46h
_Pop2BOper	equ	4B49h
_PushOper	equ	4B4Ch
_PopOper	equ	4B4Fh
_Find_E_UndefOrArchived	equ	4B52h
_StTmpEq	equ	4B55h
_FindEOL	equ	4B58h
_BrkInc	equ	4B5Bh
_IncFetch	equ	4B5Eh
_CurFetch	equ	4B61h
_maybe_Factorial	equ	4B70h
_YOnOff	equ	4B73h
_EqSelUnsel	equ	4B76h
_ITSOLVER	equ	4B79h
_GRITSOLVER	equ	4B7Ch
_ITSOLVERB	equ	4B7Fh
_ITSOLVERNB	equ	4B82h
_OutputExpr	equ	4B9Dh
_Next_Y_Style	equ	4BC7h
_maybe_SetPenX	equ	4BD3h
_maybe_SetPenY	equ	4BD6h
_maybe_SetPenT	equ	4BD9h
_maybe_DispOP1A	equ	4BE2h
_maybe_SetTblGraphDraw	equ	4BEBh
_MemClear	equ	4C1Bh
_MemSet	equ	4C1Eh
_maybe_ReloadAppEntryVecs	equ	4C21h
_PointOn	equ	4C24h
_ExecuteNewPrgm	equ	4C27h
_UserPutMap	equ	4C2Dh
_getRomPage	equ	4C30h
_FindAppUp	equ	4C33h
_FindAppDn	equ	4C36h
_FindApp	equ	4C39h
_ExecuteApp	equ	4C3Ch
_IBounds	equ	4C4Bh
_IOffset	equ	4C4Eh
_maybe_DrawCirc2	equ	4C51h
_CanAlphIns	equ	4C54h
_maybe_Redisp	equ	4C57h
_GetBaseVer	equ	4C5Ah
_SetFP0	equ	4C5Dh
_maybe_AppGetCbl	equ	4C60h
_maybe_AppGetCalc	equ	4C63h
_SetIgnoreKey	equ	4C69h
_SetSendThisKeyBack	equ	4C6Ch
_DisableApd	equ	4C6Fh
_EnableAPD	equ	4C72h
_forcecmd	equ	4C7Bh
_ApdSetup	equ	4C7Eh
_HandleLinkActivity	equ	4C84h
_SGetTokString	equ	4C96h
_LoadPattern	equ	4C99h
_SStringLength	equ	4C9Ch
_SPutTokString	equ	4CF0h
_maybe_ErrCustom1	equ	4D29h
_maybe_ErrCustom2	equ	4D2Ch
_RstrCursorAndFlags	equ	4D53h
_VerticalLine	equ	4D7Dh
_IBoundsFull	equ	4D80h
_CPoint	equ	4DADh
_maybe_DeleteApp	equ	4DB0h
_HorizontalLine	equ	4E4Ch
_CreateAppVar	equ	4E4Fh
_CreateProtProg	equ	4E52h
_CreateVar	equ	4E55h
_AsmComp	equ	4E58h
_GetAsmSize	equ	4E5Bh
_SquishPrgm	equ	4E5Eh
_ExecutePrgm	equ	4E61h
_ChkFindSymAsm	equ	4E64h
_CSub	equ	4E6Ah
_CAdd	equ	4E6Dh
_CSquare	equ	4E70h
_CMult	equ	4E73h
_CRecip	equ	4E76h
_CDiv	equ	4E79h
_CAbs	equ	4E7Ch
_CSqrAbs	equ	4E7Fh
_CSqRoot	equ	4E82h
_CLN	equ	4E85h
_CLog	equ	4E88h
_CTenX	equ	4E8Bh
_CEtoX	equ	4E8Eh
_CXrootY	equ	4E91h
_CYtoX	equ	4E97h
_Conj	equ	4E9Ah
_CMltByReal	equ	4E9Dh
_CDivByReal	equ	4EA0h
_CTrunc	equ	4EA3h
_CFrac	equ	4EA6h
_CIntgr	equ	4EA9h
_SendHeaderPacket	equ	4EACh
_CancelTransmission	equ	4EAFh
_SendRAMVarData	equ	4EB5h
_SendRAMCmd	equ	4EB8h
_SendPacket	equ	4EBBh
_ReceiveAck	equ	4EBEh
_GetSmallPacket	equ	4ED0h
_GetDataPacket	equ	4ED3h
_SendAck	equ	4ED6h
_Get4Bytes	equ	4ED9h
_Get3Bytes	equ	4EDCh
_Rec1stByte	equ	4EDFh
_Rec1stByteNC	equ	4EE2h
_ContinueGetByte	equ	4EE5h
_RecAByteIO	equ	4EE8h
_ReceiveVar	equ	4EEBh
_ReceiveVarData2	equ	4EEEh
_maybe_ReceiveVarData	equ	4EF1h
_Get4BytesCursor	equ	4EFDh
_Get4BytesNC	equ	4F00h
_SendReadyPacket	equ	4F09h
_SendCmd	equ	4F24h
_Disp	equ	4F2Ah
_GetHookByte	equ	4F36h
_LoadBIndPaged	equ	4F39h
_CallCursorHook	equ	4F3Ch
_CallRawKeyHook	equ	4F42h
_SetCursorHook	equ	4F45h
_SetRawKeyHook	equ	4F4Bh
_ClrCursorHook	equ	4F4Eh
_ClrRawKeyHook	equ	4F54h
_AdjustAllHooks	equ	4F5Ah
_CallGetKeyHook	equ	4F5Dh
_SetGetKeyHook	equ	4F60h
_ClrGetKeyHook	equ	4F63h
_SetLocalizeHook	equ	4F78h
_ClrLocalizeHook	equ	4F7Bh
_Bit_VertSplit	equ	4F8Dh
_SetWindowHook	equ	4F96h
_ClrWindowHook	equ	4F99h
_DelVarArc	equ	4FABh
_DelVarNoArc	equ	4FAEh
_SetAllPlots	equ	4FB1h
_archiveVar		equ 4FC0h ;set 0,(iy+24h) to check for low battery first
_SetFontHook	equ	4FC9h
_ClrFontHook	equ	4FCCh
_SetRegraphHook	equ	4FCFh
_ClrRegraphHook	equ	4FD2h
_CallRegraphHook	equ	4FD5h
_JForceGraphNoKey	equ	4FE7h
_JForceGraphKey	equ	4FEAh
_maybe_PowerOff	equ	4FEDh
_GetKeyRetOff	equ	4FF0h
_FindGroupSym	equ	4FF3h
_maybe_FillBasePageTable	equ	4FF6h
_maybe_ArcChk	equ	4FF9h
_FlashToRam	equ	4FFCh
_LoadDEIndPaged	equ	4FFFh
_LoadCIndPaged	equ	5002h
_SetupPagedPtr	equ	5005h
_PagedGet	equ	5008h
_SetDrawingHook	equ	5017h
_ClrDrawingHook	equ	501Ah
_IPoint_NoHook	equ	501Dh
_ILine_NoHook	equ	5020h
_CLineS_NoHook	equ	5023h
_DispMenuTitle	equ	504Ah
_GetBCOffsetIX	equ	506Eh
_ForceFullScreen	equ	5074h
_GetVariableData	equ	5077h
_FindSwapSector	equ	507Ah
_CopyFlashPage	equ	507Dh
_FindAppNumPages	equ	5080h
_HLMinus5	equ	5083h
_SendArcPacket	equ	5086h
_FormBase	equ	508Fh
_Fake_Chk_Batt_Low	equ	5098h
_Fake_Chk_Batt_Low2	equ	509Bh
_maybe_GetAppBasePage	equ	50A1h
_SetExSpeed	equ	50A4h
_WriteToFlash	equ	50B0h
_maybe_SendUSBData	equ	50D4h
_GetVarCmdUSB	equ	50DDh
_InvertTextInsMode	equ	5104h
_DispHeader	equ	5110h
_GetRelSeconds	equ	5125h
_DisableClock	equ	5128h
_EnableClock	equ	512Bh
_GetDayOfWeek	equ	512Eh
_GetDate	equ	5131h
_FormDate	equ	5134h
_GetDateFmt	equ	5137h
_FormDateString	equ	513Ah
_GetTime	equ	513Dh
_FormTime	equ	5140h
_GetTimeFmt	equ	5143h
_FormTimeString	equ	5146h
_GetClockStatus	equ	5149h
_SetDateMakeList	equ	514Ch
_SetDateFmt	equ	514Fh
_SetTimeMakeList	equ	5152h
_SetTimeFmt	equ	5155h
_GetAbsSeconds	equ	5158h
_AbsSecondsToTimeList	equ	515Bh
_ClrWindowAndFlags	equ	5161h
_ResetLists	equ	5167h
_ExecLib	equ	5173h
_OpenLib	equ	517Fh
_WaitEnterKey	equ	5182h
_Disp32	equ	51AFh
_GetTokenCompatLevel	equ	5221h
_EnableUSBHook	equ	5269h
_DisableUSBHook	equ	526Ch
_maybe_InitUSBDevice	equ	526Fh
_maybe_KillUSBPeripheral	equ	5272h
_GraphLine	equ	527Bh
_DelVarSym	equ	52C3h
_FindAppUpNoCase	equ	52C6h
_FindAppDnNoCase	equ	52C9h
_maybe_DeleteApp_Link	equ	52CFh
_maybe_CheckAppRestrictions	equ	52DBh
_maybe_DispAppRestrictions	equ	52DEh
_PolarEquToOP1	equ	52F3h
_maybe_GetRestrictionsOptions	equ	52FCh
_maybe_DispResetComplete	equ	52FFh
_FindAppCustom	equ	5305h
_GetFastCircCoord	equ	53B0h
_WPutSN	equ	5428h
_Load_LFont	equ	5482h
_SendScreenContents	equ	5575h
_SetTextFGColor_3	equ	5581h
_SetTextFGColor_2	equ	5584h
_SetTextFGColor	equ	5587h
_VPutPS	equ	558Ah

;Page 1Fh ROM Calls
;--------------------------------
bootbtf				equ 8000h
_MD5Final	equ	8018h
_BigNumCompare	equ	801Eh
_WriteAByteUnsafe	equ	8021h
_EraseFlash	equ	8024h
_FindFirstCertificateField	equ	8027h
_ZeroToCertificate	equ	802Ah
_GetCertificateEnd	equ	802Dh
_FindGroupedField	equ	8030h
_ATimesE	equ	8042h
_ATimesDE	equ	8045h
_DivHLByE	equ	8048h
_DivHLByDE	equ	804Bh
_LoadAIndPaged	equ	8051h
_FlashToRAM2	equ	8054h
_GetCertificateStart	equ	8057h
_GetFieldSize	equ	805Ah
_FindSubField	equ	805Dh
_EraseCertificateSector	equ	8060h
_ClearFullScreen	equ	806Ch
_FindOSHeaderSubField	equ	8075h
_FindNextCertificateField	equ	8078h
_GetCalcSerial	equ	807Eh
_EraseFlashPage	equ	8084h
_WriteFlashUnsafe	equ	8087h
_DispBootVer	equ	808Ah
_MD5Init			equ 808Dh
_MD5Update			equ 8090h
_MarkOSValid		equ 8099h
_FindAppHeaderSubField	equ	80ABh
_Div32ByDE	equ	80B1h
_FindSimpleGroupedField	equ	80B4h
_getBootVer			equ 80B7h
_getHardwareVersion	equ	80BAh
_WriteAByteSafe	equ	80C6h
_WriteFlashSafe	equ	80C9h

;RAM Equates
;--------------------------------
ramStart		equ 8000h
appData			equ 8000h
ramCode			equ 8100h
ramCodeEnd		equ	822Fh
MD5Hash			equ		8272h
interruptBackup		equ	8282h
appSearchPage	equ	8283h
MD5Buffer		equ	83B3h
arcInfo			equ	83FCh
appInfo			equ	8440h
kbdScanCode	equ	0844Dh
kbdLGSC	equ	0844Eh
kbdPSC	equ	0844Fh
kbdWUR	equ	08450h
kbdDebncCnt	equ	08451h
kbdKey	equ	08452h
kbdGetKy	equ	08453h
keyExtend	equ	08454h
apdSubTimer	equ	08456h
apdTimer	equ	08457h
curTime	equ	08458h
curRow	equ	08459h
curCol	equ	0845Ah
lFont_record	equ	08463h
sFont_record	equ	08487h
OP1	equ	084AEh
OP2	equ	084B9h
OP3	equ	084C4h
OP4	equ	084CFh
OP5	equ	084DAh
OP6	equ	084E5h
nameBuff	equ	08519h
iMathPtr1	equ	08525h
iMathPtr2	equ	08527h
iMathPtr3	equ	08529h
iMathPtr4	equ	0852Bh
iMathPtr5	equ	0852Dh
iMathPtr6	equ	0852Fh
iMathPtr7	equ	08531h
iMathPtr8	equ	08533h
chkDelPtr1	equ	08535h
chkDelPtr2	equ	08537h
insDelPtr	equ	08539h
maybe_fOutDat	equ	0853Dh
asm_data_ptr1	equ	08543h
asm_data_ptr2	equ	08545h
textShadow	equ	08560h
textShadCur	equ	08664h
textShadTop	equ	08666h
textShadAlph	equ	08667h
textShadIns	equ	08668h
cxCurApp	equ	08676h
onSP	equ	08686h
MenuCurrent	equ	086A9h
maybe_ioPrompt	equ	08700h
ioFlag	equ	0871Bh
header	equ	0871Fh
ioData	equ	08728h
ioNewData	equ	08734h
penCol	equ	08782h
penRow	equ	08784h
rclQueue	equ	08785h
errNo	equ	08789h
errSP	equ	0878Ah
usermem_offset	equ	08B22h
flags	equ	08B26h
tempSwapArea	equ		8B8Ch
maybe_curGX2	equ	08E6Eh
maybe_lcdTallP	equ	08F02h
maybe_pixWide_m_1	equ	08F05h
orgXmin	equ	09250h
panShift	equ	09259h
uXmin	equ	09264h
uXmax	equ	0926Dh
uXscl	equ	09276h
uYmin	equ	0927Fh
uYmax	equ	09288h
uYscl	equ	09291h
uThetMin	equ	0929Ah
uThetMax	equ	092A3h
uThetStep	equ	092ACh
uTmin	equ	092B5h
uTmax	equ	092BEh
uTStep	equ	092C7h
uPlotStart	equ	092D0h
unMax	equ	092D9h
uu0	equ	092E2h
uv0	equ	092EBh
unMin	equ	092F4h
uu02	equ	092FDh
uv02	equ	09306h
uw02	equ	0932Ah
Xmin	equ	09336h
Xmax	equ	0933Fh
Xscl	equ	09348h
Ymin	equ	09351h
Ymax	equ	0935Ah
Yscl	equ	09363h
ThetaMin	equ	0936Ch
ThetaMax	equ	09375h
ThetaStep	equ	0937Eh
TminPar	equ	09387h
TmaxPar	equ	09390h
Tstep	equ	09399h
PlotStart	equ	093A2h
nMax	equ	093ABh
u0	equ	093B4h
v0	equ	093BDh
nMin	equ	093C6h
u02	equ	093CFh
v02	equ	093D8h
w02	equ	093FCh
un1	equ	09405h
vn1	equ	09417h
wn1	equ	09429h
XFact	equ	09525h
YFact	equ	0952Eh
deltaX	equ	09538h
deltaY	equ	09541h
shortX	equ	0954Ah
shortY	equ	09553h
maybe_XOutSym	equ	09574h
XOutDat	equ	09576h
maybe_YOutSym	equ	09578h
YOutDat	equ	0957Ah
inputSym	equ	0957Ch
maybe_inputDat	equ	0957Eh
TblMin	equ	097EBh
TblStep	equ	097F4h
ES	equ	0983Eh
parseVar	equ	09B8Eh
begPC	equ	09B97h
curPC	equ	09B99h
endPC	equ	09B9Bh
cmdShadow	equ	09BAAh
editTop	equ	09CB4h
editCursor	equ	09CB6h
editTail	equ	09CB8h
editBtm	equ	09CBAh
maybe_editSym	equ	09CC6h
maybe_editDat	equ	09CC8h
modePtr	equ	09D84h
winTop	equ	09D86h
winBtm	equ	09D87h
winLeftEdge	equ	09D88h
winLeft	equ	09D89h
winAbove	equ	09D8Bh
fmtDigits	equ	09D91h
fmtString	equ	09D92h
maybe_fmtMatSym	equ	09DE9h
maybe_fmtMatMem	equ	09DEBh
EQS	equ	09DEDh
maybe_tSymPtr1	equ	09DF9h
maybe_tSymPtr2	equ	09DFBh
maybe_chkDelPtr3	equ	09DFDh
maybe_chkDelPtr4	equ	09DFFh
FPS	equ	09E05h
OPBase	equ	09E07h
OPS	equ	09E09h
pTempCnt	equ	09E0Bh
pTemp	equ	09E0Fh
progPtr	equ	09E11h
maybe_newDataPtr	equ	09E13h
pagedCount	equ	09E15h
pagedPN	equ	09E16h
pagedGetPtr	equ	09E17h
pagedPutPtr	equ	09E19h
pagedBuf	equ	09E1Bh
cursorHookPtr	equ	09E5Dh
rawKeyHookPtr	equ	09E65h
getKeyHookPtr	equ	09E69h
windowHookPtr	equ	09E71h
fontHookPtr	equ	09E7Dh
regraphHookPtr	equ	09E81h
drawingHookPtr	equ	09E85h
localizeHookPtr	equ	09EADh
usbHookPtr	equ	09EB5h
DBKeyScanCode	equ	09FABh
DBKeyRptCtr	equ	09FACh
textFGColor	equ	0A015h
textBGColor	equ	0A017h
drawBGColor	equ	0A036h
drawFGColor	equ	0A038h
userMem	equ	0A60Bh
symTable	equ	0FD9Eh

;System Flags
;----------------------------------------------------------------------
kbdFlags	equ	00h
trigFlags	equ	00h
trigDeg	equ	2
kbdSCR	equ	3
kbdKeyPress	equ	4
;----------------------------------------------------------------------
plotFlags	equ	02h
plotTrace	equ	0
plotDisp	equ	2
;----------------------------------------------------------------------
graphFlags	equ	03h
graphProg	equ	1
;----------------------------------------------------------------------
textFlags	equ	05h
textEraseBelow	equ	1
textScrolled	equ	2
textInverse	equ	3
textInsMode	equ	4
;----------------------------------------------------------------------
ParsFlag2	equ	07h
numOP1	equ	0
;----------------------------------------------------------------------
apdFlags	equ	08h
maybe_preClrForMode	equ	0
apdAble	equ	2
apdRunning	equ	3
;----------------------------------------------------------------------
onFlags	equ	09h
appWantAlphaUpDn	equ	0
onInterrupt	equ	4
statsValid	equ	6
;----------------------------------------------------------------------
curFlags	equ	0Ch
fmtEditFlags	equ	0Ch
fmtEdit	equ	0
curAble	equ	2
curOn	equ	3
curLock	equ	4
;----------------------------------------------------------------------
appFlags	equ	0Dh
appTextSave	equ	1
appAutoScroll	equ	2
appCurGraphic	equ	5
appCurWord	equ	6
;----------------------------------------------------------------------
seqFlags	equ	0Fh
webMode	equ	0
;----------------------------------------------------------------------
plotFlag2	equ	11h
expr_param	equ	3
expr_writing	equ	4
;----------------------------------------------------------------------
indicFlags		equ 12h	;Indicator flags
indicRun		equ 0		;1=run indicator ON
indicInUse		equ 1		;indicator save area in use=1, free=0 ;resetting will disable 2nd while in _getkey
indicOnly		equ 2		;interrupt handler only checks run indicator

shiftFlags	equ	12h
indicOnly	equ	2
shift2nd	equ	3
shiftAlpha	equ	4
shiftLwrAlph	equ	5
shiftALock	equ	6
;----------------------------------------------------------------------
sGrFlags	equ	14h
grfSplit	equ	0
vertSplit	equ	1
grfSplitOverride	equ	3
write_on_graph	equ	4
;----------------------------------------------------------------------
smartFlags	equ	17h
smartGraph	equ	0
smartGraph_inv	equ	1
;----------------------------------------------------------------------
gkKeyRepeating	equ	0
;----------------------------------------------------------------------
remoteKeyPress	equ	5
;----------------------------------------------------------------------
maybe_fullScrnTextDraw	equ	4
;----------------------------------------------------------------------
appRetOffKey	equ	7
;----------------------------------------------------------------------
appWantDiagonalKeys	equ	0
;----------------------------------------------------------------------
asm_Flag1		equ 21h	;ASM CODING
asm_Flag2		equ 22h	;ASM CODING
asm_Flag3		equ 23h	;ASM CODING
;----------------------------------------------------------------------
appLwrCaseFlag		equ 24h
lwrCaseActive		equ 3
;----------------------------------------------------------------------
fontFlags	equ	32h
fracDrawLFont	equ	2
drawLFont	equ	6
;----------------------------------------------------------------------
ignoreBPLink	equ	3
;----------------------------------------------------------------------
getKeyHookActive	equ	0
rawKeyHookActive	equ	5
cursorHookActive	equ	7
;----------------------------------------------------------------------
localizeHookActive	equ	1
windowHookActive	equ	2
fontHookActive	equ	5
regraphHookActive	equ	6
drawingHookActive	equ	7
;----------------------------------------------------------------------
usbHookActive	equ	0
;----------------------------------------------------------------------
DBKeyFlags	equ	3Dh
haveDBKey	equ	5
HWLinkErrF	equ	7
;----------------------------------------------------------------------
textDrawColor	equ	4

;Character Font Equates  
;-------------------------------
LrecurN			equ 001h
LrecurU			equ 002h
LrecurV			equ 003h
LrecurW			equ 004h
Lconvert		equ 005h
LsqUp			equ 006h
LsqDown			equ 007h
Lintegral		equ 008h
Lcross			equ 009h
LboxIcon 		equ 00Ah
LcrossIcon 		equ 00Bh
LdotIcon 		equ 00Ch
LsubT   		equ 00Dh ;small capital T for parametric mode.
LcubeR  		equ 00Eh ;slightly different 3 for cubed root.
LhexF			equ 00Fh
Lroot			equ 010h
Linverse		equ 011h
Lsquare			equ 012h
Langle			equ 013h
Ldegree			equ 014h
Lradian			equ 015h
Ltranspose		equ 016h
LLE			equ 017h
LNE			equ 018h
LGE			equ 019h
Lneg			equ 01Ah
Lexponent		equ 01Bh
Lstore			equ 01Ch
Lten			equ 01Dh
LupArrow		equ 01Eh
LdownArrow		equ 01Fh
Lspace			equ 020h
Lexclam			equ 021h
Lquote			equ 022h
Lpound			equ 023h
Lfourth			equ 024h
Lpercent		equ 025h
Lampersand		equ 026h
Lapostrophe		equ 027h
LlParen			equ 028h
LrParen			equ 029h
Lasterisk		equ 02Ah
LplusSign		equ 02Bh
Lcomma			equ 02Ch
Ldash			equ 02Dh
Lperiod			equ 02Eh
Lslash			equ 02Fh
L0			equ 030h
L1			equ 031h
L2			equ 032h
L3			equ 033h
L4			equ 034h
L5			equ 035h
L6			equ 036h
L7			equ 037h
L8			equ 038h
L9			equ 039h
Lcolon			equ 03Ah
Lsemicolon		equ 03Bh
LLT			equ 03Ch
LEQ			equ 03Dh
LGT			equ 03Eh
Lquestion		equ 03Fh
LatSign			equ 040h
LcapA			equ 041h
LcapB			equ 042h
LcapC			equ 043h
LcapD			equ 044h
LcapE			equ 045h
LcapF			equ 046h
LcapG			equ 047h
LcapH			equ 048h
LcapI			equ 049h
LcapJ			equ 04Ah
LcapK			equ 04Bh
LcapL			equ 04Ch
LcapM			equ 04Dh
LcapN			equ 04Eh
LcapO			equ 04Fh
LcapP			equ 050h
LcapQ			equ 051h
LcapR			equ 052h
LcapS			equ 053h
LcapT			equ 054h
LcapU			equ 055h
LcapV			equ 056h
LcapW			equ 057h
LcapX			equ 058h
LcapY			equ 059h
LcapZ			equ 05Ah
Ltheta			equ 05Bh
Lbackslash		equ 05Ch
LrBrack			equ 05Dh
Lcaret			equ 05Eh
Lunderscore		equ 05Fh
Lbackquote		equ 060h
La			equ 061h
Lb			equ 062h
Lc			equ 063h
Ld			equ 064h
Le			equ 065h
Lf			equ 066h
Lg			equ 067h
Lh			equ 068h
Li			equ 069h
Lj			equ 06Ah
Lk			equ 06Bh
Ll			equ 06Ch
Lm			equ 06Dh
Ln			equ 06Eh
Lo			equ 06Fh
Lp			equ 070h
Lq			equ 071h
Lr			equ 072h
Ls			equ 073h
Lt			equ 074h
Lu			equ 075h
Lv			equ 076h
Lw			equ 077h
Lx			equ 078h
Ly			equ 079h
Lz			equ 07Ah
LlBrace			equ 07Bh
Lbar			equ 07Ch
LrBrace			equ 07Dh
Ltilde			equ 07Eh
LinvEQ			equ 07Fh
Lsub0			equ 080h
Lsub1			equ 081h
Lsub2			equ 082h
Lsub3			equ 083h
Lsub4			equ 084h
Lsub5			equ 085h
Lsub6			equ 086h
Lsub7			equ 087h
Lsub8			equ 088h
Lsub9			equ 089h
LcapAAcute		equ 08Ah
LcapAGrave		equ 08Bh
LcapACaret		equ 08Ch
LcapADier		equ 08Dh
LaAcute			equ 08Eh
LaGrave			equ 08Fh
LaCaret			equ 090h
LaDier			equ 091h
LcapEAcute		equ 092h
LcapEGrave		equ 093h
LcapECaret		equ 094h
LcapEDier		equ 095h
LeAcute			equ 096h
LeGrave			equ 097h
LeCaret			equ 098h
LeDier			equ 099h
LcapIAcute		equ 09Ah
LcapIGrave		equ 09Bh
LcapICaret		equ 09Ch
LcapIDier		equ 09Dh
LiAcute			equ 09Eh
LiGrave			equ 09Fh
LiCaret			equ 0A0h
LiDier			equ 0A1h
LcapOAcute		equ 0A2h
LcapOGrave		equ 0A3h
LcapOCaret		equ 0A4h
LcapODier		equ 0A5h
LoAcute			equ 0A6h
LoGrave			equ 0A7h
LoCaret			equ 0A8h
LoDier			equ 0A9h
LcapUAcute		equ 0AAh
LcapUGrave		equ 0ABh
LcapUCaret		equ 0ACh
LcapUDier		equ 0ADh
LuAcute			equ 0AEh
LuGrave			equ 0AFh
LuCaret			equ 0B0h
LuDier			equ 0B1h
LcapCCed		equ 0B2h
LcCed			equ 0B3h
LcapNTilde		equ 0B4h
LnTilde			equ 0B5h
Laccent			equ 0B6h
Lgrave			equ 0B7h
Ldieresis		equ 0B8h
LquesDown		equ 0B9h
LexclamDown		equ 0BAh
Lalpha			equ 0BBh
Lbeta			equ 0BCh
Lgamma			equ 0BDh
LcapDelta		equ 0BEh
Ldelta			equ 0BFh
Lepsilon		equ 0C0h
LlBrack 		equ 0C1h
Llambda			equ 0C2h
Lmu			equ 0C3h
Lpi			equ 0C4h
Lrho			equ 0C5h
LcapSigma		equ 0C6h
Lsigma			equ 0C7h
Ltau			equ 0C8h
Lphi			equ 0C9h
LcapOmega		equ 0CAh
LxMean			equ 0CBh
LyMean			equ 0CCh
LsupX			equ 0CDh
Lellipsis		equ 0CEh
Lleft			equ 0CFh
Lblock			equ 0D0h
Lper			equ 0D1h
Lhyphen			equ 0D2h
Larea			equ 0D3h
Ltemp			equ 0D4h
Lcube			equ 0D5h
Lenter			equ 0D6h
LimagI			equ 0D7h
Lphat			equ 0D8h
Lchi			equ 0D9h
LstatF			equ 0DAh
Llne			equ 0DBh
LlistL			equ 0DCh
LfinanN 		equ 0DDh
L2_r_paren 		equ 0DEh
LblockArrow     	equ 0DFh
LcurO   		equ 0E0h
LcurO2  		equ 0E1h
LcurOcapA       	equ 0E2h
LcurOa  		equ 0E3h
LcurI   		equ 0E4h
LcurI2  		equ 0E5h
LcurIcapA       	equ 0E6h
LcurIa  		equ 0E7h
LGline          	equ 0E8h ; = 0
LGthick         	equ 0E9h ; = 1
LGabove			equ 0EAh ; = 2
LGbelow			equ 0EBh ; = 3
LGpath			equ 0ECh ; = 4
LGanimate		equ 0EDh ; = 5
LGdot			equ 0EEh ; = 6
LUpBlk			equ 0EFh ;Up arrow and Block in solver
LDnBlk			equ 0F0h ;Down arrow and Block in solver
LcurFull		equ 0F1h ;note: must be last char (PutMap checks)

;Keypress Equates
;-------------------------------
kRight			equ 001h
kLeft			equ 002h
kUp			equ 003h
kDown			equ 004h
kEnter			equ 005h
kAlphaEnter		equ 006h
kAlphaUp		equ 007h
kAlphaDown		equ 008h
kClear			equ 009h
kDel			equ 00Ah
kIns			equ 00Bh
kRecall			equ 00Ch
kLastEnt		equ 00Dh
kBOL			equ 00Eh
kEOL			equ 00Fh

kSelAll			equ 010h
kUnselAll		equ 011h
kLtoTI82		equ 012h
kBackup			equ 013h
kRecieve		equ 014h
kLnkQuit		equ 015h
kTrans			equ 016h
kRename			equ 017h
kOverw			equ 018h
kOmit			equ 019h
kCont			equ 01Ah
kSendID			equ 01Bh
kSendSW			equ 01Ch
kYes			equ 01Dh
kNoWay			equ 01Eh
kvSendType		equ 01Fh
kOverWAll		equ 020h
kNo			equ 025h
kKReset			equ 026h
kApp			equ 027h
kDoug			equ 028h
kListflag		equ 029h
menuStart		equ 02Bh
kAreYouSure		equ 02Bh
kAppsMenu		equ 02Ch
kPrgm			equ 02Dh
kZoom			equ 02Eh
kDraw			equ 02Fh
kSPlot			equ 030h
kStat			equ 031h
kMath			equ 032h
kTest			equ 033h
kChar			equ 034h
kVars			equ 035h
kMem			equ 036h
kMatrix			equ 037h
kDist			equ 038h
kAngle			equ 039h
kList			equ 03Ah
kCalc			equ 03Bh
kFin			equ 03Ch
menuEnd			equ kFin
kCatalog		equ 03Eh
kInputDone		equ 03Fh
kOff			equ kInputDone
kQuit			equ 040h
appStart		equ kQuit
kLinkIO			equ 041h
kMatrixEd		equ 042h
kStatEd			equ 043h
kGraph			equ 044h
kMode			equ 045h
kPrgmEd			equ 046h ;PROGRAM EDIT
kPrgmCr			equ 047h ;PROGRAM CREATE
kWindow			equ 048h ;RANGE EDITOR
kYequ			equ 049h ;EQUATION EDITOR
kTable			equ 04Ah ;TABLE EDITOR
kTblSet			equ 04Bh ;TABLE SET
kChkRAM			equ 04Ch ;CHECK RAM (About screen)
kDelMem			equ 04Dh ;DELETE MEM
kResetMem		equ 04Eh ;RESET MEM
kResetDef		equ 04Fh ;RESET DEFAULT
kPrgmInput		equ 050h ;PROGRAM INPUT
kZFactEd		equ 051h ;ZOOM FACTOR EDITOR
kError			equ 052h ;ERROR
kSolveTVM		equ 053h ;TVM SOLVER
kSolveRoot		equ 054h ;SOLVE EDITOR
kStatP			equ 055h ;stat plot
kInfStat		equ 056h ;Inferential Statistic
kFormat			equ 057h ;FORMAT
kExtApps		equ 058h ;External Applications.     NEW
kNewApps		equ 059h ;New Apps for Cerberus.
append			equ kNewApps
echoStart1		equ 05Ah
kTrace			equ 05Ah
kZFit			equ 05Bh
kZIn			equ 05Ch
kZOut			equ 05Dh
kZPrev			equ 05Eh
kBox			equ 05Fh
kDecml			equ 060h
kSetZm			equ 061h
kSquar			equ 062h
kStd			equ 063h
kTrig			equ 064h
kUsrZm			equ 065h
kZSto			equ 066h
kZInt			equ 067h
kZStat			equ 068h
echoStart2		equ 069h
kSelect			equ 069h
kCircl			equ 06Ah
kClDrw			equ 06Bh
kLine			equ 06Ch
kPen			equ 06Dh
kPtChg			equ 06Eh
kPtOff			equ 06Fh
kPtOn			equ 070h
kVert			equ 071h
kHoriz			equ 072h
kText			equ 073h
kTanLn			equ 074h
kEval			equ 075h
kInters			equ 076h
kDYDX			equ 077h
kFnIntg			equ 078h
kRootG			equ 079h
kDYDT			equ 07Ah
kDXDT			equ 07Bh
kDRDo			equ 07Ch
KGFMin			equ 07Dh
KGFMax			equ 07Eh
EchoStart		equ 07Fh
kListName		equ 07Fh
kAdd			equ 080h
kSub			equ 081h
kMul			equ 082h
kDiv			equ 083h
kExpon			equ 084h
kLParen			equ 085h
kRParen			equ 086h
kLBrack			equ 087h
kRBrack			equ 088h
kShade			equ 089h
kStore			equ 08Ah
kComma			equ 08Bh
kChs			equ 08Ch
kDecPnt			equ 08Dh
k0			equ 08Eh
k1			equ 08Fh
k2			equ 090h
k3			equ 091h
k4			equ 092h
k5			equ 093h
k6			equ 094h
k7			equ 095h
k8			equ 096h
k9			equ 097h
kEE			equ 098h
kSpace			equ 099h
kCapA			equ 09Ah
kCapB			equ 09Bh
kCapC			equ 09Ch
kCapD			equ 09Dh
kCapE			equ 09Eh
kCapF			equ 09Fh
kCapG			equ 0A0h
kCapH			equ 0A1h
kCapI			equ 0A2h
kCapJ			equ 0A3h
kCapK			equ 0A4h
kCapL			equ 0A5h
kCapM			equ 0A6h
kCapN			equ 0A7h
kCapO			equ 0A8h
kCapP			equ 0A9h
kCapQ			equ 0AAh
kCapR			equ 0ABh
kCapS			equ 0ACh
kCapT			equ 0ADh
kCapU			equ 0AEh
kCapV			equ 0AFh
kCapW			equ 0B0h
kCapX			equ 0B1h
kCapY			equ 0B2h
kCapZ			equ 0B3h
kVarx			equ 0B4h
kPi			equ 0B5h
kInv			equ 0B6h
kSin			equ 0B7h
kASin			equ 0B8h
kCos			equ 0B9h
kACos			equ 0BAh
kTan			equ 0BBh
kATan			equ 0BCh
kSquare			equ 0BDh
kSqrt			equ 0BEh
kLn			equ 0BFh
kExp			equ 0C0h
kLog			equ 0C1h
kALog			equ 0C2h
kToABC			equ 0C3h
kClrTbl			equ 0C4h
kAns			equ 0C5h
kColon			equ 0C6h
kNDeriv			equ 0C7h
kFnInt			equ 0C8h
kRoot			equ 0C9h
kQuest			equ 0CAh
kQuote			equ 0CBh
kTheta			equ 0CCh
kIf			equ 0CDh
kThen			equ 0CEh
kElse			equ 0CFh
kFor			equ 0D0h
kWhile			equ 0D1h
kRepeat			equ 0D2h
kEnd			equ 0D3h
kPause			equ 0D4h
kLbl			equ 0D5h
kGoto			equ 0D6h
kISG			equ 0D7h
kDSL			equ 0D8h
kMenu			equ 0D9h
kExec			equ 0DAh
kReturn			equ 0DBh
kStop			equ 0DCh
kInput			equ 0DDh
kPrompt			equ 0DEh
kDisp			equ 0DFh
kDispG			equ 0E0h
kDispT			equ 0E1h
kOutput			equ 0E2h
kGetKey			equ 0E3h
kClrHome		equ 0E4h
kPrtScr			equ 0E5h
kSinH			equ 0E6h
kCosH			equ 0E7h
kTanH			equ 0E8h
kASinH			equ 0E9h
kACosH			equ 0EAh
kATanH			equ 0EBh
kLBrace			equ 0ECh
kRBrace			equ 0EDh
kI			equ 0EEh
kCONSTeA		equ 0EFh
kPlot3			equ 0F0h
kFMin			equ 0F1h
kFMax			equ 0F2h
kL1A			equ 0F3h
kL2A			equ 0F4h
kL3A			equ 0F5h
kL4A			equ 0F6h
kL5A			equ 0F7h
kL6A			equ 0F8h
kunA			equ 0F9h
kvnA			equ 0FAh
kwnA			equ 0FBh

;THIS KEY MEANS THAT IT IS A 2 BYTE KEYCODE
;THERE ARE 2 OF THESE KEYS; BE CAREFUL WITH USAGE
;------------------------------------------------
kExtendEcho2		equ 0FCh

;THIS KEY MEANS THAT THE KEY PRESS IS ONE THAT ECHOS
;INTO A BUFFER, AND IT IS A 2 BYTE KEY CODE, GO LOOK AT
;(EXTECHO) FOR THE KEY VALUE 
;------------------------------------------------------
kExtendEcho		equ 0FEh

kE1BT			equ 0
kDrawInv		equ kE1BT
kDrawF			equ kE1BT+1
kPixelOn		equ kE1BT+2
kPixelOff		equ kE1BT+3
kPxlTest		equ kE1BT+4
kRCGDB			equ kE1BT+5
kRCPic			equ kE1BT+6
kSTGDB			equ kE1BT+7
kSTPic			equ kE1BT+8
kAbs			equ kE1BT+9
kTEqu			equ kE1BT+10 ;==
kTNoteQ			equ kE1BT+11 ;<&gt;
kTGT			equ kE1BT+12 ;&gt;
kTGTE			equ kE1BT+13 ;&gt;=
kTLT			equ kE1BT+14 ;<
kTLTE			equ kE1BT+15 ;<=
kAnd			equ kE1BT+16
kOr			equ kE1BT+17
kXor			equ kE1BT+18
kNot			equ kE1BT+19
kLR1			equ kE1BT+20
kXRoot			equ kE1BT+21
kCube			equ kE1BT+22
kCbRt			equ kE1BT+23 ;Cube ROOT
kToDec			equ kE1BT+24
kCubicR			equ kE1BT+25
kQuartR			equ kE1BT+26
kPlot1			equ kE1BT+27
kPlot2			equ kE1BT+28
kRound			equ kE1BT+29
kIPart			equ kE1BT+30
kFPart			equ kE1BT+31
kInt			equ kE1BT+32
kRand			equ kE1BT+33
kNPR			equ kE1BT+34
kNCR			equ kE1BT+35
kXFactorial		equ kE1BT+36
kRad			equ kE1BT+37
kDegr			equ kE1BT+38 ;DEGREES CONV
kAPost			equ kE1BT+39
kToDMS			equ kE1BT+40
kRToPo			equ kE1BT+41 ;R
kRToPr			equ kE1BT+42
kPToRx			equ kE1BT+43
kPToRy			equ kE1BT+44
kRowSwap		equ kE1BT+45
kRowPlus		equ kE1BT+46
kTimRow			equ kE1BT+47
kTRowP			equ kE1BT+48
kSortA			equ kE1BT+49
kSortD			equ kE1BT+50
kSeq			equ kE1BT+51
kMin			equ kE1BT+52
kMax			equ kE1BT+53
kMean			equ kE1BT+54
kMedian			equ kE1BT+55
kSum			equ kE1BT+56
kProd			equ kE1BT+57
kDet			equ kE1BT+58
kTransp			equ kE1BT+59
kDim			equ kE1BT+60
kFill			equ kE1BT+61
kIdent			equ kE1BT+62
kRandm			equ kE1BT+63
kAug			equ kE1BT+64
kOneVar			equ kE1BT+65
kTwoVar			equ kE1BT+66
kLR			equ kE1BT+67
kLRExp			equ kE1BT+68
kLRLn			equ kE1BT+69
kLRPwr			equ kE1BT+70
kMedMed			equ kE1BT+71
kQuad			equ kE1BT+72
kClrLst			equ kE1BT+73
kHist			equ kE1BT+74
kxyLine			equ kE1BT+75
kScatter		equ kE1BT+76
kmRad			equ kE1BT+77
kmDeg			equ kE1BT+78
kmNormF			equ kE1BT+79
kmSci			equ kE1BT+80
kmEng			equ kE1BT+81
kmFloat			equ kE1BT+82
kFix			equ kE1BT+83
kSplitOn		equ kE1BT+84
kFullScreen		equ kE1BT+85
kStndrd			equ kE1BT+86
kParam			equ kE1BT+87
kPolar			equ kE1BT+88
kSeqG			equ kE1BT+89
kAFillOn		equ kE1BT+90
kAFillOff		equ kE1BT+91
kACalcOn		equ kE1BT+92
kACalcOff		equ kE1BT+93
kFNOn			equ kE1BT+94
kFNOff			equ kE1BT+95
kPlotsOn		equ kE1BT+96
kPlotsOff		equ kE1BT+97
kPixelChg		equ kE1BT+98
kSendMBL		equ kE1BT+99
kRecvMBL		equ kE1BT+100
kBoxPlot		equ kE1BT+101
kBoxIcon		equ kE1BT+102
kCrossIcon		equ kE1BT+103
kDotIcon		equ kE1BT+104
kE2BT			equ kE1BT+105
kSeqential		equ kE2BT
kSimulG			equ kE2BT+1
kPolarG			equ kE2BT+2
kRectG			equ kE2BT+3
kCoordOn		equ kE2BT+4
kCoordOff		equ kE2BT+5
kDrawLine		equ kE2BT+6
kDrawDot		equ kE2BT+7
kAxisOn			equ kE2BT+8
kAxisOff		equ kE2BT+9
kGridOn			equ kE2BT+10
kGridOff		equ kE2BT+11
kLblOn			equ kE2BT+12
kLblOff			equ kE2BT+13
kL1			equ kE2BT+14
kL2			equ kE2BT+15
kL3			equ kE2BT+16
kL4			equ kE2BT+17
kL5			equ kE2BT+18
kL6			equ kE2BT+19

;These keys are laid on top of existing keys to
;enable localization in the inferential stats editor.
;----------------------------------------------------
kinfData		equ kL1
kinfStats		equ kL1+1
kinfYes			equ kL1+2
kinfNo			equ kL1+3
kinfCalc		equ kL1+4
kinfDraw		equ kL1+5
kinfAlt1ne		equ kL1+6
kinfAlt1lt		equ kL1+7
kinfAlt1gt		equ kL1+8
kinfAlt2ne		equ kL1+9
kinfAlt2lt		equ kL1+10
kinfAlt2gt		equ kL1+11
kinfAlt3ne		equ kL1+12
kinfAlt3lt		equ kL1+13
kinfAlt3gt		equ kL1+14
kinfAlt4ne		equ kL1+15
kinfAlt4lt		equ kL1+16
kinfAlt4gt		equ kL1+17
kinfAlt5ne		equ kL1+18
kinfAlt5lt		equ kL1+19
kinfAlt5gt		equ kL1+20
kinfAlt6ne		equ kL1+21
kinfAlt6lt		equ kL1+22
kinfAlt6gt		equ kL1+23
kMatA			equ kE2BT+20
kMatB			equ kE2BT+21
kMatC			equ kE2BT+22
kMatD			equ kE2BT+23
kMatE			equ kE2BT+24
kXmin			equ kE2BT+25
kXmax			equ kE2BT+26
kXscl			equ kE2BT+27
kYmin			equ kE2BT+28
kYmax			equ kE2BT+29
kYscl			equ kE2BT+30
kTmin			equ kE2BT+31
kTmax			equ kE2BT+32
kTStep			equ kE2BT+33
kOmin			equ kE2BT+34
kOmax			equ kE2BT+35
kOStep			equ kE2BT+36
ku0			equ kE2BT+37
kv0			equ kE2BT+38
knMin			equ kE2BT+39
knMax			equ kE2BT+40
kDeltaY			equ kE2BT+41
kDeltaX			equ kE2BT+42
kZXmin			equ kE2BT+43
kZXmax			equ kE2BT+44
kZXscl			equ kE2BT+45
kZYmin			equ kE2BT+46
kZYmax			equ kE2BT+47
kZYscl			equ kE2BT+48
kZTmin			equ kE2BT+49
kZTmax			equ kE2BT+50
kZTStep			equ kE2BT+51
kZOmin			equ kE2BT+52
kZOmax			equ kE2BT+53
kZOStep			equ kE2BT+54
kZu0			equ kE2BT+55
kZv0			equ kE2BT+56
kZnMin			equ kE2BT+57
kZnMax			equ kE2BT+58
kDelLast		equ kE2BT+59
kSinReg			equ kE2BT+60
kConstE			equ kE2BT+61
kPic1			equ kE2BT+62
kPic2			equ kE2BT+63
kPic3			equ kE2BT+64
kDelVar			equ kE2BT+65
kGetCalc		equ kE2BT+66
kRealM			equ kE2BT+67
kPolarM			equ kE2BT+68
kRectM			equ kE2BT+69
kuv			equ kE2BT+70 ;U vs V
kvw			equ kE2BT+71 ;V vs W
kuw			equ kE2BT+72 ;U vs W
kFinPMTend		equ kE2BT+73
kFinPMTbeg		equ kE2BT+74
kGraphStyle		equ kE2BT+75
kExprOn			equ kE2BT+76
kExprOff		equ kE2BT+77
kStatA			equ kE2BT+78
kStatB			equ kE2BT+79
kStatC			equ kE2BT+80
kCorr			equ kE2BT+81
kStatD			equ kE2BT+82
kStatE			equ kE2BT+83
kRegEq			equ kE2BT+84
kMinX			equ kE2BT+85
kQ1			equ kE2BT+86
kMD			equ kE2BT+87
kQ3			equ kE2BT+88
kMaxX			equ kE2BT+89
kStatX1			equ kE2BT+90
kStatY1			equ kE2BT+91
kStatX2			equ kE2BT+92
kStatY2			equ kE2BT+93
kStatX3			equ kE2BT+94
kStatY3			equ kE2BT+95
kTblMin			equ kE2BT+96
kTblStep		equ kE2BT+97
kSetupLst		equ kE2BT+98
kClrAllLst		equ kE2BT+99
kLogistic		equ kE2BT+100
kZTest			equ kE2BT+101
kTTest			equ kE2BT+102
k2SampZTest		equ kE2BT+103
k2SampTTest		equ kE2BT+104
k1PropZTest		equ kE2BT+105
k2PropZTest		equ kE2BT+106
kChiTest		equ kE2BT+107
k2SampFTest		equ kE2BT+108
kZIntVal		equ kE2BT+109
kTIntVal		equ kE2BT+110
k2SampTInt		equ kE2BT+111
k2SampZInt		equ kE2BT+112
k1PropZInt		equ kE2BT+113
k2PropZInt		equ kE2BT+114
kDNormal		equ kE2BT+115
kInvNorm		equ kE2BT+116
kDT			equ kE2BT+117
kChi			equ kE2BT+118
kDF			equ kE2BT+119
kBinPDF			equ kE2BT+120
kBinCDF			equ kE2BT+121
kPoiPDF			equ kE2BT+122
kPoiCDF			equ kE2BT+123
kun			equ kE2BT+124
kvn			equ kE2BT+125
kwn			equ kE2BT+126
kRecn			equ kE2BT+127
kPlotStart		equ kE2BT+128
kZPlotStart		equ kE2BT+129 ;recursion n
kXFact			equ kE2BT+130 ;PlotStart
kYFact			equ kE2BT+131 ;ZPlotStart
kANOVA			equ kE2BT+132 ;XFact
kMaxY			equ kE2BT+133 ;YFact
kWebOn			equ kE2BT+134 ;MinY
kWebOff			equ kE2BT+135 ;MaxY
kTblInput		equ kE2BT+136 ;WEB ON
kGeoPDF			equ kE2BT+137 ;WEB OFF
kGeoCDF			equ kE2BT+138 ;WEB OFF
kShadeNorm		equ kE2BT+139
kShadeT			equ kE2BT+140
kShadeChi		equ kE2BT+141
kShadeF			equ kE2BT+142
kPlotStep		equ kE2BT+143
kZPlotStep		equ kE2BT+144
kLinRegtTest		equ kE2BT+145
KMGT			equ kE2BT+146 ;VERT SPLIT
kSelectA		equ kE2BT+147
kZFitA			equ kE2BT+148
kE2BT_End		equ kZFitA

;More 2 Byte Keys 
;------------------------------------
kE2BT2			equ 0
kGDB1			equ kE2BT2
kGDB2			equ kE2BT2+1
kGDB3			equ kE2BT2+2
kY1			equ kE2BT2+3
kY2			equ kE2BT2+4
kY3			equ kE2BT2+5
kY4			equ kE2BT2+6
kY5			equ kE2BT2+7
kY6			equ kE2BT2+8
kY7			equ kE2BT2+9
kY8			equ kE2BT2+10
kY9			equ kE2BT2+11
kY0			equ kE2BT2+12
kX1T			equ kE2BT2+13
kY1T			equ kE2BT2+14
kX2T			equ kE2BT2+15
kY2T			equ kE2BT2+16
kX3T			equ kE2BT2+17
kY3T			equ kE2BT2+18
kX4T			equ kE2BT2+19
kY4T			equ kE2BT2+20
kX5T			equ kE2BT2+21
kY5T			equ kE2BT2+22
kX6T			equ kE2BT2+23
kY6T			equ kE2BT2+24
kR1			equ kE2BT2+25
kR2			equ kE2BT2+26
kR3			equ kE2BT2+27
kR4			equ kE2BT2+28
kR5			equ kE2BT2+29
kR6			equ kE2BT2+30
kGDB4			equ kE2BT2+31
kGDB5			equ kE2BT2+32
kGDB6			equ kE2BT2+33
kPic4			equ kE2BT2+34
kPic5			equ kE2BT2+35
kPic6			equ kE2BT2+36
kGDB7			equ kE2BT2+37
kGDB8			equ kE2BT2+38
kGDB9			equ kE2BT2+39
kGDB0			equ kE2BT2+40
kPic7			equ kE2BT2+41
kPic8			equ kE2BT2+42
kPic9			equ kE2BT2+43
kPic0			equ kE2BT2+44
kStatN			equ kE2BT2+45
kXMean			equ kE2BT2+46
kConj			equ kE2BT2+47
kReal			equ kE2BT2+48
kFAngle			equ kE2BT2+49
kLCM			equ kE2BT2+50
kGCD			equ kE2BT2+51
kRandInt		equ kE2BT2+52
kRandNorm		equ kE2BT2+53
kToPolar		equ kE2BT2+54
kToRect			equ kE2BT2+55
kYMean			equ kE2BT2+56
kStdX			equ kE2BT2+57
kStdX1			equ kE2BT2+58
kw0			equ kE2BT2+59
kMatF			equ kE2BT2+60
kMatG			equ kE2BT2+61
kMatRH			equ kE2BT2+62
kMatI			equ kE2BT2+63
kMatJ			equ kE2BT2+64
kYMean1			equ kE2BT2+65
kStdY			equ kE2BT2+66
kStdY1			equ kE2BT2+67
kMatToLst		equ kE2BT2+68
kLstToMat		equ kE2BT2+69
kCumSum			equ kE2BT2+70
kDeltaLst		equ kE2BT2+71
kStdDev			equ kE2BT2+72
kVariance		equ kE2BT2+73
kLength			equ kE2BT2+74
kEquToStrng		equ kE2BT2+75
kStrngToEqu		equ kE2BT2+76
kExpr			equ kE2BT2+77
kSubStrng		equ kE2BT2+78
kInStrng		equ kE2BT2+79
kStr1			equ kE2BT2+80
kStr2			equ kE2BT2+81
kStr3			equ kE2BT2+82
kStr4           	equ kE2BT2+83
kStr5           	equ kE2BT2+84
kStr6           	equ kE2BT2+85
kStr7           	equ kE2BT2+86
kStr8           	equ kE2BT2+87
kStr9           	equ kE2BT2+88
kStr0           	equ kE2BT2+89
kFinN           	equ kE2BT2+90
kFinI           	equ kE2BT2+91
kFinPV          	equ kE2BT2+92
kFinPMT         	equ kE2BT2+93
kFinFV          	equ kE2BT2+94
kFinPY          	equ kE2BT2+95
kFinCY          	equ kE2BT2+96
kFinFPMT        	equ kE2BT2+97
kFinFI          	equ kE2BT2+98
kFinFPV         	equ kE2BT2+99
kFinFN          	equ kE2BT2+100
kFinFFV         	equ kE2BT2+101
kFinNPV         	equ kE2BT2+102
kFinIRR         	equ kE2BT2+103
kFinBAL         	equ kE2BT2+104
kFinPRN         	equ kE2BT2+105
kFinINT         	equ kE2BT2+106
kSumX           	equ kE2BT2+107
kSumX2          	equ kE2BT2+108
kFinToNom       	equ kE2BT2+109
kFinToEff       	equ kE2BT2+110
kFinDBD         	equ kE2BT2+111
kStatVP         	equ kE2BT2+112
kStatZ          	equ kE2BT2+113
kStatT          	equ kE2BT2+114
kStatChi        	equ kE2BT2+115
kStatF          	equ kE2BT2+116
kStatDF         	equ kE2BT2+117
kStatPhat       	equ kE2BT2+118
kStatPhat1      	equ kE2BT2+119
kStatPhat2      	equ kE2BT2+120
kStatMeanX1     	equ kE2BT2+121
kStatMeanX2     	equ kE2BT2+122
kStatStdX1      	equ kE2BT2+123
kStatStdX2      	equ kE2BT2+124
kStatStdXP		equ kE2BT2+125
kStatN1			equ kE2BT2+126
kStatN2			equ kE2BT2+127
kStatLower		equ kE2BT2+128
kStatUpper		equ kE2BT2+129
kuw0			equ kE2BT2+130
kImag			equ kE2BT2+131
kSumY			equ kE2BT2+132
kXres			equ kE2BT2+133
kStat_s			equ kE2BT2+134
kSumY2			equ kE2BT2+135
kSumXY			equ kE2BT2+136
kuXres			equ kE2BT2+137
kModBox			equ kE2BT2+138
kNormProb		equ kE2BT2+139
kNormalPDF		equ kE2BT2+140
kTPDF			equ kE2BT2+141
kChiPDF			equ kE2BT2+142
kFPDF			equ kE2BT2+143
kMinY			equ kE2BT2+144 ;MinY
kRandBin		equ kE2BT2+145
kRef			equ kE2BT2+146
kRRef			equ kE2BT2+147
kLRSqr			equ kE2BT2+148
kBRSqr			equ kE2BT2+149
kDiagOn			equ kE2BT2+150
kDiagOff		equ kE2BT2+151
kun1			equ kE2BT2+152 ;FOR RCL USE WHEN GOTTEN FROM 82
kvn1			equ kE2BT2+153 ;FOR RCL USE WHEN GOTTEN FROM 82
k83_00End		equ kvn1 ;end of original keys...
kArchive		equ k83_00End + 1
kUnarchive		equ k83_00End + 2
kAsm			equ k83_00End + 3 ;Asm(
kAsmPrgm		equ k83_00End + 4 ;AsmPrgm
kAsmComp		equ k83_00End + 5 ;AsmComp(
kcapAAcute		equ k83_00End + 6
kcapAGrave		equ k83_00End + 7
kcapACaret		equ k83_00End + 8
kcapADier		equ k83_00End + 9
kaAcute			equ k83_00End + 10
kaGrave			equ k83_00End + 11
kaCaret			equ k83_00End + 12
kaDier			equ k83_00End + 13
kcapEAcute		equ k83_00End + 14
kcapEGrave		equ k83_00End + 15
kcapECaret		equ k83_00End + 16
kcapEDier		equ k83_00End + 17
keAcute			equ k83_00End + 18
keGrave			equ k83_00End + 19
keCaret			equ k83_00End + 20
keDier			equ k83_00End + 21
kcapIAcute		equ k83_00End + 22
kcapIGrave		equ k83_00End + 23
kcapICaret		equ k83_00End + 24
kcapIDier		equ k83_00End + 25
kiAcute			equ k83_00End + 26
kiGrave			equ k83_00End + 27
kiCaret			equ k83_00End + 28
kiDier			equ k83_00End + 29
kcapOAcute		equ k83_00End + 30
kcapOGrave		equ k83_00End + 31
kcapOCaret		equ k83_00End + 32
kcapODier		equ k83_00End + 33
koAcute			equ k83_00End + 34
koGrave			equ k83_00End + 35
koCaret			equ k83_00End + 36
koDier			equ k83_00End + 37
kcapUAcute		equ k83_00End + 38
kcapUGrave		equ k83_00End + 39
kcapUCaret		equ k83_00End + 40
kcapUDier		equ k83_00End + 41
kuAcute			equ k83_00End + 42
kuGrave			equ k83_00End + 43
kuCaret			equ k83_00End + 44
kuDier			equ k83_00End + 45
kcapCCed		equ k83_00End + 46
kcCed			equ k83_00End + 47
kcapNTilde		equ k83_00End + 48
knTilde			equ k83_00End + 49
kaccent			equ k83_00End + 50
kgrave			equ k83_00End + 51
kdieresis		equ k83_00End + 52
kquesDown		equ k83_00End + 53
kexclamDown     	equ k83_00End + 54
kalpha          	equ k83_00End + 55
kbeta           	equ k83_00End + 56
kgamma          	equ k83_00End + 57
kcapDelta		equ k83_00End + 58
kdelta			equ k83_00End + 59
kepsilon		equ k83_00End + 60
klambda			equ k83_00End + 61
kmu			equ k83_00End + 62
kpi2			equ k83_00End + 63
krho			equ k83_00End + 64
kcapSigma		equ k83_00End + 65
ksigma			equ k83_00End + 66
ktau			equ k83_00End + 67
kphi			equ k83_00End + 68
kcapOmega		equ k83_00End + 69
kphat			equ k83_00End + 70
kchi2			equ k83_00End + 71
kstatF2			equ k83_00End + 72
kLa			equ k83_00End + 73
kLb			equ k83_00End + 74
kLc			equ k83_00End + 75
kLd			equ k83_00End + 76
kLe			equ k83_00End + 77
kLf			equ k83_00End + 78
kLg			equ k83_00End + 79
kLh			equ k83_00End + 80
kLi			equ k83_00End + 81
kLj			equ k83_00End + 82
kLk			equ k83_00End + 83
kLl			equ k83_00End + 84
kLm			equ k83_00End + 85
kLsmalln		equ k83_00End + 86
kLo			equ k83_00End + 87
kLp			equ k83_00End + 88
kLq			equ k83_00End + 89
kLsmallr		equ k83_00End + 90
kLs			equ k83_00End + 91
kLt			equ k83_00End + 92
kLu			equ k83_00End + 93
kLv			equ k83_00End + 94
kLw			equ k83_00End + 95
kLx			equ k83_00End + 96
kLy			equ k83_00End + 97
kLz			equ k83_00End + 98
kGarbageC		equ k83_00End + 99 ;GarbageCollect
kE2BT2_End		equ kGarbageC

;TI-83 Plus Context Equates
;---------------------------------------------
cxCmd			equ kQuit ;home screen
cxMatEdit		equ kMatrixEd ;matrix editor
cxPrgmEdit		equ kPrgmEd ;program editor
cxEquEdit		equ kYequ ;equation editor
cxGrRange		equ kWindow ;graph range editor
cxGrZfact		equ kZFactEd ;graph zoom factors editor
cxGraph			equ kGraph ;graph mode
cxStatEdit		equ kStatEd ;statistics list editor
cxPrgmInput		equ kPrgmInput ;programmed input
cxError			equ kError ;error handler
cxLinkIO		equ kLinkIO ;LINK I/O interface
cxMem			equ kResetMem ;reset memory
cxDefMem		equ kResetDef ;reset default
cxRAMApp		equ kChkRAM ;RAM usage screen
cxMode			equ kMode ;mode settings screen
cxErase			equ kDelMem ;memory erase
cxPrgmCreate		equ kPrgmCr ;PROGRAM CREATE
cxTableEditor		equ kTable ;TABLE EDITOR
cxTableSet		equ kTblSet ;TABLE SET UP
cxStatPlot		equ kStatP ;STAT PLOTS
cxInfStat		equ kInfStat ;Inferential Statistic
cxFormat		equ kFormat ;FORMAT CONTEXT
cxSolveTVM		equ kSolveTVM ;Solve TVM
cxSolveRoot		equ kSolveRoot ;Solve Root
lastOldApp		equ kExtApps ;external applications
cxextapps		equ kExtApps
cxNewApps		equ kNewApps ;new cerberus applications
cxGroup			equ cxNewApps+0 ;1st new app.
cxUnGroup		equ cxNewApps+1 ;2nd new app.
lastNewApp		equ cxUnGroup ;last new app for this ver

;Scan Code Equates
;-------------------------------
skDown			equ 01h
skLeft			equ 02h
skRight			equ 03h
skUp			equ 04h
skEnter			equ 09h
skAdd			equ 0Ah
skSub			equ 0Bh
skMul			equ 0Ch
skDiv			equ 0Dh
skPower			equ 0Eh
skClear			equ 0Fh
skChs			equ 11h
sk3			equ 12h
sk6			equ 13h
sk9			equ 14h
skRParen		equ 15h
skTan			equ 16h
skVars			equ 17h
skDecPnt		equ 19h
sk2			equ 1Ah
sk5			equ 1Bh
sk8			equ 1Ch
skLParen		equ 1Dh
skCos			equ 1Eh
skPrgm			equ 1Fh
skStat			equ 20h
sk0			equ 21h
sk1			equ 22h
sk4			equ 23h
sk7			equ 24h
skComma			equ 25h
skSin			equ 26h
skMatrix		equ 27h
skGraphvar		equ 28h
skStore			equ 2Ah
skLn			equ 2Bh
skLog			equ 2Ch
skSquare		equ 2Dh
skRecip			equ 2Eh
skMath			equ 2Fh
skAlpha			equ 30h
skGraph			equ 31h
skTrace			equ 32h
skZoom			equ 33h
skWindow		equ 34h
skYEqu			equ 35h
sk2nd			equ 36h
skMode			equ 37h
skDel			equ 38h

;Data Type Equates                                                    
;---------------------------------------------------------------------
RealObj			equ 0
ListObj			equ 1
MatObj			equ 2
EquObj			equ 3
StrngObj		equ 4
ProgObj			equ 5
ProtProgObj		equ 6
PictObj			equ 7
GDBObj			equ 8
UnknownObj		equ 9
UnknownEquObj		equ 0Ah
NewEquObj		equ 0Bh
CplxObj			equ 0Ch
CListObj		equ 0Dh
UndefObj		equ 0Eh
WindowObj		equ 0Fh
ZStoObj			equ 10h
TblRngObj		equ 11h
LCDObj			equ 12h
BackupObj		equ 13h
AppObj			equ 14h	;application, only used in menus/link
AppVarObj		equ 15h	;application variable
TempProgObj		equ 16h ;program, home deletes when finished
GroupObj		equ 17h ;group.

;I/O Equates                                                          
;---------------------------------------------------
D0D1_bits		equ 03h
D0LD1L			equ 03h
D0LD1H			equ 01h
D0HD1L			equ 02h
D0HD1H			equ 00h
bport			equ 0 ;4-bit link port (I/O) 

;Device Codes
;-----------------------------------------------------------------
TI82DEV			equ 82h
PC82DEV			equ 02h
MAC82DEV		equ 12h
TI83FDEV		equ 73h
LINK83FDEV		equ 23h
TI83DEV			equ 83h
PC83DEV			equ 03h
MAC83DEV		equ 13h
TI85DEV			equ 95h ;different than real 85 so me talk
PC85DEV			equ 05h
MAC85DEV		equ 15h
TI73DEV			equ 74h ;device x3 is always an 83
PC73DEV			equ 07h
MAC73DEV		equ 17h
LINK73FDEV		equ 23h
PC83FDEV		equ 23h

;System Error Codes                                                  
;-----------------------------------------------------------
E_EDITF			equ 7 ;allow re-entering application
E_EDIT			equ 1<<E_EDITF
E_Mask			equ 7Fh
E_Overflow		equ 1+E_EDIT
E_DivBy0		equ 2+E_EDIT
E_SingularMat		equ 3+E_EDIT
E_Domain		equ 4+E_EDIT
E_Increment		equ 5+E_EDIT
E_Break			equ 6+E_EDIT
E_NonReal		equ 7+E_EDIT
E_Syntax		equ 8+E_EDIT
E_DataType		equ 9+E_EDIT
E_Argument		equ 10+E_EDIT
E_DimMismatch		equ 11+E_EDIT
E_Dimension		equ 12+E_EDIT
E_Undefined		equ 13+E_EDIT
E_Memory		equ 14+E_EDIT
E_Invalid		equ 15+E_EDIT
E_IllegalNest		equ 16+E_EDIT
E_Bound			equ 17+E_EDIT
E_GraphRange		equ 18+E_EDIT
E_Zoom			equ 19+E_EDIT
E_Label			equ 20
E_Stat			equ 21
E_Solver		equ 22+E_EDIT
E_Singularity		equ 23+E_EDIT
E_SignChange		equ 24+E_EDIT
E_Iterations		equ 25+E_EDIT
E_BadGuess		equ 26+E_EDIT
E_StatPlo		equ 27
E_TolTooSmall		equ 28+E_EDIT
E_Reserved		equ 29+E_EDIT
E_Mode			equ 30+E_EDIT
E_LnkErr		equ 31+E_EDIT
E_LnkMemErr		equ 32+E_EDIT
E_LnkTransErr		equ 33+E_EDIT
E_LnkDupErr		equ 34+E_EDIT
E_LnkMemFull		equ 35+E_EDIT
E_Unknown		equ 36+E_EDIT
E_Scale			equ 37+E_EDIT
E_IdNotFound		equ 38
E_NoMode		equ 39+E_EDIT
E_Validation		equ 40
E_Length		equ 41+E_EDIT
E_Application		equ 42+E_EDIT
E_AppErr1		equ 43+E_EDIT
E_AppErr2		equ 44+E_EDIT
E_ExpiredApp		equ 45
E_BadAdd		equ 46
E_Archived		equ 47+E_EDIT
E_Version		equ 48
E_ArchFull		equ 49
E_Variable		equ 50+E_EDIT
E_Duplicate		equ 51+E_EDIT
HigErrNum		equ 51
;Obsolete error numbers 34 ;first LINK error
E_LinkIOChkSum		equ 34
E_LinkIOTimeOut		equ 35
E_LinkIOBusy		equ 36
E_LinkIOVer		equ 37
