#ifndef CHIP_ADDRESS
#define CHIP_ADDRESS 0x38
#endif

// Calibration Data

#define CAL_CVRMS 41951
#define CAL_CIRMS 17687307
#define CAL_CPOW 18628

//#define PMAX 0x34630B8
#define PMAX 0x1FF6A6B

// Register addresses

#define AIGAIN 0x4380              //	Phase A current gain adjust.	(	24	bits DV=	0x000000	)
#define AVGAIN 0x4381              //	Phase A voltage gain adjust.	(	24	bits DV=	0x000000	)
#define BIGAIN 0x4382              //	Phase B current gain adjust.	(	24	bits DV=	0x000000	)
#define BVGAIN 0x4383              //	Phase B voltage gain adjust.	(	24	bits DV=	0x000000	)
#define CIGAIN 0x4384              //	Phase C current gain adjust.	(	24	bits DV=	0x000000	)
#define CVGAIN 0x4385              //	Phase C voltage gain adjust.	(	24	bits DV=	0x000000	)
#define NIGAIN 0x4386              //	Neutral current gain adjust (ADE7868 and ADE7878 only).	(	24	bits DV=	0x000000	)
#define AIRMSOS 0x4387             //	Phase A current rms offset.	(	24	bits DV=	0x000000	)
#define AVRMSOS 0x4388             //	Phase A voltage rms offset.	(	24	bits DV=	0x000000	)
#define BIRMSOS 0x4389             //	Phase B current rms offset.	(	24	bits DV=	0x000000	)
#define BVRMSOS 0x438A             //	Phase B voltage rms offset.	(	24	bits DV=	0x000000	)
#define CIRMSOS 0x438B             //	Phase C current rms offset.	(	24	bits DV=	0x000000	)
#define CVRMSOS 0x438C             //	Phase C voltage rms offset.	(	24	bits DV=	0x000000	)
#define NIRMSOS 0x438D             //	Neutral current rms offset (ADE7868 and ADE7878 only).	(	24	bits DV=	0x000000	)
#define AVAGAIN 0x438E             //	Phase A apparent power gain adjust.	(	24	bits DV=	0x000000	)
#define BVAGAIN 0x438F             //	Phase B apparent power gain adjust.	(	24	bits DV=	0x000000	)
#define CVAGAIN 0x4390             //	Phase C apparent power gain adjust.	(	24	bits DV=	0x000000	)
#define AWGAIN 0x4391              //	Phase A total active power gain adjust.	(	24	bits DV=	0x000000	)
#define AWATTOS 0x4392             //	Phase A total active power offset adjust.	(	24	bits DV=	0x000000	)
#define BWGAIN 0x4393              //	Phase B total active power gain adjust.	(	24	bits DV=	0x000000	)
#define BWATTOS 0x4394             //	Phase B total active power offset adjust.	(	24	bits DV=	0x000000	)
#define CWGAIN 0x4395              //	Phase C total active power gain adjust.	(	24	bits DV=	0x000000	)
#define CWATTOS 0x4396             //	Phase C total active power offset adjust.	(	24	bits DV=	0x000000	)
#define AVARGAIN 0x4397            //	Phase A total reactive power gain adjust (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define AVAROS 0x4398              //	Phase A total reactive power offset adjust (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define BVARGAIN 0x4399            //	Phase B total reactive power gain adjust (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define BVAROS 0x439A              //	Phase B total reactive power offset adjust (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define CVARGAIN 0x439B            //	Phase C total reactive power gain adjust (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define CVAROS 0x439C              //	Phase C total reactive power offset adjust (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define AFWGAIN 0x439D             //	Phase A fundamental active power gain adjust. Location reserved for ADE7854, ADE7858, and ADE7868.	(	24	bits DV=	0x000000	)
#define AFWATTOS 0x439E            //	Phase A fundamental active power offset adjust. Location reserved for ADE7854, ADE7858, and ADE7868.	(	24	bits DV=	0x000000	)
#define BFWGAIN 0x439F             //	Phase B fundamental active power gain adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define BFWATTOS 0x43A0            //	Phase B fundamental active power offset adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define CFWGAIN 0x43A1             //	Phase C fundamental active power gain adjust.	(	24	bits DV=	0x000000	)
#define CFWATTOS 0x43A2            //	Phase C fundamental active power offset adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define AFVARGAIN 0x43A3           //	Phase A fundamental reactive power gain adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define AFVAROS 0x43A4             //	Phase A fundamental reactive power offset adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define BFVARGAIN 0x43A5           //	Phase B fundamental reactive power gain adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define BFVAROS 0x43A6             //	Phase B fundamental reactive power offset adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define CFVARGAIN 0x43A7           //	Phase C fundamental reactive power gain adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define CFVAROS 0x43A8             //	Phase C fundamental reactive power offset adjust (ADE7878 only).	(	24	bits DV=	0x000000	)
#define VATHR1 0x43A9              //	Most significant 24 bits of VATHR[47:0] threshold used in phase apparent power datapath.	(	24	bits DV=	0x000000	)
#define VATHR0 0x43AA              //	Less significant 24 bits of VATHR[47:0] threshold used in phase apparent power datapath.	(	24	bits DV=	0x000000	)
#define WTHR1 0x43AB               //	Most significant 24 bits of WTHR[47:0] threshold used in phase total/fundamental active power datapath.	(	24	bits DV=	0x000000	)
#define WTHR0 0x43AC               //	Less significant 24 bits of WTHR[47:0] threshold used in phase total/fundamental active power datapath.	(	24	bits DV=	0x000000	)
#define VARTHR1 0x43AD             //	Most significant 24 bits of VARTHR[47:0] threshold used in phase total/fundamental reactive power datapath (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define VARTHR0 0x43AE             //	Less significant 24 bits of VARTHR[47:0] threshold used in phase total/fundamental reactive power datapath (ADE7858, ADE7868, and ADE7878).	(	24	bits DV=	0x000000	)
#define Reserved 0x43AF            //	This memory location should be kept at 0x000000 for proper operation.	(	N/A4	bits DV=	0x000000	)
#define VANOLOAD 0x43B0            //	No load threshold in the apparent power datapath.	(	24	bits DV=	0x0000000	)
#define APNOLOAD 0x43B1            //	No load threshold in the total/fundamental active power datapath.	(	24	bits DV=	0x0000000	)
#define VARNOLOAD 0x43B2           //	No load threshold in the total/fundamental reactive power datapath. Location reserved for ADE7854.	(	24	bits DV=	0x0000000	)
#define VLEVEL 0x43B3              //	Register used in the algorithm that computes the fundamental active and reactive powers (ADE7878 only).	(	24	bits DV=	0x000000	)
#define Reserved1 0x43B4           //	This location should not be written for proper operation.	(	N/A4	bits DV=	0x000000	)
#define DICOEFF 0x43B5             //	Register used in the digital integrator algorithm. If the integrator is turned on, it must be set at 0xFF8000. In practice, it is transmitted as 0xFFF8000.	(	24	bits DV=	0x0000000	)
#define HPFDIS 0x43B6              //	Disables/enables the HPF in the current datapath (see Table 34).	(	24	bits DV=	0x000000	)
#define Reserved2 0x43B7           //	This memory location should be kept at 0x000000 for proper operation.	(	N/A4	bits DV=	0x000000	)
#define ISUMLVL 0x43B8             //	Threshold used in comparison between the sum of phase currents and the neutral current (ADE7868 and ADE7878 only).	(	24	bits DV=	0x000000	)
#define Reserved3 0x43B9 to 0x43BE //	These memory locations should be kept at 0x000000 for proper operation.	(	N/A4	bits DV=	0x000000	)
#define ISUM 0x43BF                //	Sum of IAWV, IBWV, and ICWV registers (ADE7868 and ADE7878 only).	(	28	bits DV=	N/A4	)
#define AIRMS 0x43C0               //	Phase A current rms value.	(	24	bits DV=	N/A4	)
#define AVRMS 0x43C1               //	Phase A voltage rms value.	(	24	bits DV=	N/A4	)
#define BIRMS 0x43C2               //	Phase B current rms value.	(	24	bits DV=	N/A4	)
#define BVRMS 0x43C3               //	Phase B voltage rms value.	(	24	bits DV=	N/A4	)
#define CIRMS 0x43C4               //	Phase C current rms value.	(	24	bits DV=	N/A4	)
#define CVRMS 0x43C5               //	Phase C voltage rms value.	(	24	bits DV=	N/A4	)
#define NIRMS 0x43C6               //	Neutral current rms value (ADE7868 and ADE7878 only).	(	24	bits DV=	N/A4	)
#define Reserved4 0x43C7 to 0x43FF //	These memory locations should not be written for proper operation.	(	N/A4	bits DV=	N/A4	)

#define Reserved5 0xE203 //	This memory location should not be written for proper operation.	(	16	bits DV=	0x0000	)
#define Run 0xE228       //	Run register starts and stops the DSP. See the Digital Signal Processor section for more details.	(	16	bits DV=	0x0000	)

#define AWATTHR 0xE400  //	Phase A total active energy accumulation.	(	32	bits DV=	0x00000000	)
#define BWATTHR 0xE401  //	Phase B total active energy accumulation.	(	32	bits DV=	0x00000000	)
#define CWATTHR 0xE402  //	Phase C total active energy accumulation.	(	32	bits DV=	0x00000000	)
#define AFWATTHR 0xE403 //	Phase A fundamental active energy accumulation (ADE7878 only).	(	32	bits DV=	0x00000000	)
#define BFWATTHR 0xE404 //	Phase B fundamental active energy accumulation (ADE7878 only).	(	32	bits DV=	0x00000000	)
#define CFWATTHR 0xE405 //	Phase C fundamental active energy accumulation (ADE7878 only).	(	32	bits DV=	0x00000000	)
#define AVARHR 0xE406   //	Phase A total reactive energy accumulation (ADE7858, ADE7868, and ADE7878 only).	(	32	bits DV=	0x00000000	)
#define BVARHR 0xE407   //	Phase B total reactive energy accumulation (ADE7858, ADE7868, and ADE7878 only).	(	32	bits DV=	0x00000000	)
#define CVARHR 0xE408   //	Phase C total reactive energy accumulation (ADE7858, ADE7868, and ADE7878 only).	(	32	bits DV=	0x00000000	)
#define AFVARHR 0xE409  //	Phase A fundamental reactive energy accumulation (ADE7878 only).	(	32	bits DV=	0x00000000	)
#define BFVARHR 0xE40A  //	Phase B fundamental reactive energy accumulation (ADE7878 only).	(	32	bits DV=	0x00000000	)
#define CFVARHR 0xE40B  //	Phase C fundamental reactive energy accumulation (ADE7878 only).	(	32	bits DV=	0x00000000	)
#define AVAHR 0xE40C    //	Phase A apparent energy accumulation.	(	32	bits DV=	0x00000000	)
#define BVAHR 0xE40D    //	Phase B apparent energy accumulation.	(	32	bits DV=	0x00000000	)
#define CVAHR 0xE40E    //	Phase C apparent energy accumulation.	(	32	bits DV=	0x00000000	)

#define IPEAK 0xE500    //	Current peak register. See Figure 50 and Table 35 for details about its composition.	(	32	bits DV=	N/A	)
#define VPEAK 0xE501    //	Voltage peak register. See Figure 50 and Table 36 for details about its composition.	(	32	bits DV=	N/A	)
#define STATUS0 0xE502  //	Interrupt Status Register 0. See Table 37.	(	32	bits DV=	N/A	)
#define STATUS1 0xE503  //	Interrupt Status Register 1. See Table 38.	(	32	bits DV=	N/A	)
#define AIMAV 0xE504    //	Phase A current mean absolute value computed during PSM0 and PSM1 modes (ADE7868 and ADE7878 only).	(	20	bits DV=	N/A	)
#define BIMAV 0xE505    //	Phase B current mean absolute value computed during PSM0 and PSM1 modes (ADE7868 and ADE7878 only).	(	20	bits DV=	N/A	)
#define CIMAV 0xE506    //	Phase C current mean absolute value computed during PSM0 and PSM1 modes (ADE7868 and ADE7878 only).	(	20	bits DV=	N/A	)
#define OILVL 0xE507    //	Overcurrent threshold.	(	24	bits DV=	0xFFFFFF	)
#define OVLVL 0xE508    //	Overvoltage threshold.	(	24	bits DV=	0xFFFFFF	)
#define SAGLVL 0xE509   //	Voltage SAG level threshold.	(	24	bits DV=	0x000000	)
#define MASK0 0xE50A    //	Interrupt Enable Register 0. See Table 39.	(	32	bits DV=	0x00000000	)
#define MASK1 0xE50B    //	Interrupt Enable Register 1. See Table 40.	(	32	bits DV=	0x00000000	)
#define IAWV 0xE50C     //	Instantaneous value of Phase A current.	(	24	bits DV=	N/A	)
#define IBWV 0xE50D     //	Instantaneous value of Phase B current.	(	24	bits DV=	N/A	)
#define ICWV 0xE50E     //	Instantaneous value of Phase C current.	(	24	bits DV=	N/A	)
#define INWV 0xE50F     //	Instantaneous value of neutral current (ADE7868 and ADE7878 only).	(	24	bits DV=	N/A	)
#define VAWV 0xE510     //	Instantaneous value of Phase A voltage.	(	24	bits DV=	N/A	)
#define VBWV 0xE511     //	Instantaneous value of Phase B voltage.	(	24	bits DV=	N/A	)
#define VCWV 0xE512     //	Instantaneous value of Phase C voltage.	(	24	bits DV=	N/A	)
#define AWATT 0xE513    //	Instantaneous value of Phase A total active power.	(	24	bits DV=	N/A	)
#define BWATT 0xE514    //	Instantaneous value of Phase B total active power.	(	24	bits DV=	N/A	)
#define CWATT 0xE515    //	Instantaneous value of Phase C total active power.	(	24	bits DV=	N/A	)
#define AVAR 0xE516     //	Instantaneous value of Phase A total reactive power (ADE7858, ADE7868, and ADE7878 only).	(	24	bits DV=	N/A	)
#define BVAR 0xE517     //	Instantaneous value of Phase B total reactive power (ADE7858, ADE7868, and ADE7878 only).	(	24	bits DV=	N/A	)
#define CVAR 0xE518     //	Instantaneous value of Phase C total reactive power (ADE7858, ADE7868, and ADE7878 only).	(	24	bits DV=	N/A	)
#define AVA 0xE519      //	Instantaneous value of Phase A apparent power.	(	24	bits DV=	N/A	)
#define BVA 0xE51A      //	Instantaneous value of Phase B apparent power.	(	24	bits DV=	N/A	)
#define CVA 0xE51B      //	Instantaneous value of Phase C apparent power.	(	24	bits DV=	N/A	)
#define CHECKSUM 0xE51F //	Checksum verification. See the Checksum Register section for details.	(	32	bits DV=	0x33666787	)
#define VNOM 0xE520     //	Nominal phase voltage rms used in the alternative computation of the apparent power. When the VNOMxEN bit is set, the applied voltage input in the corresponding phase is ignored and all corresponding rms voltage instances are replaced by the value in	(	24	bits DV=	0x000000	)

#define Reserved6 0xE521 to 0xE52E //	These addresses should not be written for proper operation.	(		bits DV=		)
#define PHSTATUS 0xE600            //	Phase peak register. See Table 41.	(	16	bits DV=	N/A	)
#define ANGLE0 0xE601              //	Time Delay 0. See the Time Interval Between Phases section for details.	(	16	bits DV=	N/A	)
#define ANGLE1 0xE602              //	Time Delay 1. See the Time Interval Between Phases section for details.	(	16	bits DV=	N/A	)
#define ANGLE2 0xE603              //	Time Delay 2. See the Time Interval Between Phases section for details.	(	16	bits DV=	N/A	)
#define Reserved7 0xE604 to 0xE606 //	These addresses should not be written for proper operation.	(		bits DV=		)
#define PERIOD 0xE607              //	Network line period.	(	16	bits DV=	N/A	)
#define PHNOLOAD 0xE608            //	Phase no load register. See Table 42.	(	16	bits DV=	N/A	)
#define Reserved8 0xE609 to 0xE60B //	These addresses should not be written for proper operation.	(		bits DV=		)
#define LINECYC 0xE60C             //	Line cycle accumulation mode count.	(	16	bits DV=	0xFFFF	)
#define ZXTOUT 0xE60D              //	Zero-crossing timeout count.	(	16	bits DV=	0xFFFF	)
#define COMPMODE 0xE60E            //	Computation-mode register. See Table 43.	(	16	bits DV=	0x01FF	)
#define Gain 0xE60F                //	PGA gains at ADC inputs. See Table 44.	(	16	bits DV=	0x0000	)
#define CFMODE 0xE610              //	CFx configuration register. See Table 45.	(	16	bits DV=	0x0E88	)
#define CF1DEN 0xE611              //	CF1 denominator.	(	16	bits DV=	0x0000	)
#define CF2DEN 0xE612              //	CF2 denominator.	(	16	bits DV=	0x0000	)
#define CF3DEN 0xE613              //	CF3 denominator.	(	16	bits DV=	0x0000	)
#define APHCAL 0xE614              //	Phase calibration of Phase A. See Table 46.	(	10	bits DV=	0x0000	)
#define BPHCAL 0xE615              //	Phase calibration of Phase B. See Table 46.	(	10	bits DV=	0x0000	)
#define CPHCAL 0xE616              //	Phase calibration of Phase C. See Table 46.	(	10	bits DV=	0x0000	)
#define PHSIGN 0xE617              //	Power sign register. See Table 47.	(	16	bits DV=	N/A	)
#define CONFIG 0xE618              //	ADE7878 configuration register. See Table 48.	(	16	bits DV=	0x0000	)
#define MMODE 0xE700               //	Measurement mode register. See Table 49.	(	8	bits DV=	0x1C	)
#define ACCMODE 0xE701             //	Accumulation mode register. See Table 50.	(	8	bits DV=	0x00	)
#define LCYCMODE 0xE702            //	Line accumulation mode behavior. See Table 52.	(	8	bits DV=	0x78	)
#define PEAKCYC 0xE703             //	Peak detection half line cycles.	(	8	bits DV=	0x00	)
#define SAGCYC 0xE704              //	SAG detection half line cycles.	(	8	bits DV=	0x00	)
#define CFCYC 0xE705               //	Number of CF pulses between two consecutive energy latches. See the Synchronizing Energy Registers with CFx Outputs section.	(	8	bits DV=	0x01	)
#define HSDC_CFG 0xE706            //	HSDC configuration register. See Table 53.	(	8	bits DV=	0x00	)
#define Version 0xE707             //	Version of die.	(	8	bits DV=		)
#define Reserved9 0xEBFF           //	This address can be used in manipulating the SS/HSA pin when SPI is chosen as	(	8	bits DV=		) --	the active port. See the Serial Interfaces section for details.	(		bits DV=		) 
#define LPOILVL 0xEC00             //	Overcurrent threshold used during PSM2 mode (ADE7868 and ADE7878	(	8	bits DV=	0x07	)	only).--- See Table 54 in which the register is detailed.	(		bits DV=		)
#define CONFIG2 0xEC01             //	Configuration register used during PSM1 mode. See Table 55.	(	8	bits DV=	0x00	)

// Register bit masks

// IPEAK
#define IPEAKVAL 0xFFFFFF
#define IPPHASE0 0x1000000
#define IPPHASE1 0x2000000
#define IPPHASE2 0x4000000

// VPEAK
#define VPEAKVAL 0xFFFFFF
#define VPPHASE0 0x1000000
#define VPPHASE1 0x2000000
#define VPPHASE2 0x4000000

// STATUS0, MASK0
#define AEHF 0x1
#define FAEHF 0x2
#define REHF 0x4
#define FREHF 0x8
#define VAEHF 0x10
#define LENERGY 0x20
#define REVAPA 0x40
#define REVAPB 0x80
#define REVAPC 0x100
#define REVPSUM1 0x200
#define REVRPA 0x400
#define REVRPB 0x800
#define REVRPC 0x1000
#define REVPSUM2 0x2000
#define CF1 0x4000
#define CF2 0x8000
#define CF3 0x10000
#define DREADY 0x20000
#define REVPSUM3 0x40000

// STATUS1, MASK1
#define NLOAD 0x1
#define FNLOAD 0x2
#define VANLOAD 0x4
#define ZXTOVA 0x8
#define ZXTOVB 0x10
#define ZXTOVC 0x20
#define ZXTOIA 0x40
#define ZXTOIB 0x80
#define ZXTOIC 0x100
#define ZXVA 0x200
#define ZXVB 0x400
#define ZXVC 0x800
#define ZXIA 0x1000
#define ZXIB 0x2000
#define ZXIC 0x4000
#define RSTDONE 0x8000
#define SAG 0x10000
#define OI 0x20000
#define OV 0x40000
#define SEQERR 0x80000
#define MISMTCH 0x100000
#define PKI 0x800000
#define PKV 0x1000000

#define ALL2 0xFFFF

// PHSTATUS
#define OIPHASE0 0x4
#define OIPHASE1 0x8
#define OIPHASE2 0x10
#define OVPHASE0 0x200
#define OVPHASE1 0x400
#define OVPHASE2 0x800
#define VSPHASE0 0x1000
#define VSPHASE1 0x2000
#define VSPHASE2 0x4000

// PHNOLOAD
#define NLPHASE0 0x1
#define NLPHASE1 0x2
#define NLPHASE2 0x4
#define FNLPHASE0 0x8
#define FNLPHASE1 0x10
#define FNLPHASE2 0x20
#define VANLPHASE0 0x40
#define VANLPHASE1 0x80
#define VANLPHASE2 0x100

// COMPMODE
#define TERMSEL10 0x1
#define TERMSEL11 0x2
#define TERMSEL12 0x4
#define TERMSEL20 0x8
#define TERMSEL21 0x10
#define TERMSEL22 0x20
#define TERMSEL30 0x40
#define TERMSEL31 0x80
#define TERMSEL32 0x100
#define ANGLESEL 0x600
#define VNOMAEN 0x800
#define VNOMBEN 0x1000
#define VNOMCEN 0x2000
#define SELFREQ 0x4000

// GAIN
#define PGA1 0x7
#define PGA2 0x38
#define PGA3 0x1C0
// GAIN set values
#define PGA1_1 0x0
#define PGA1_2 0x1
#define PGA1_4 0x2
#define PGA1_8 0x3
#define PGA1_16 0x4
#define PGA2_1 0x0
#define PGA2_2 0x8
#define PGA2_4 0x10
#define PGA2_8 0x18
#define PGA2_16 0x20
#define PGA3_1 0x0
#define PGA3_2 0x40
#define PGA3_4 0x80
#define PGA3_8 0xC0
#define PGA3_16 0x100

// CFMODE
#define CF1SEL 0x7
#define CF2SEL 0x38
#define CF3SEL 0x1C0
#define CF1DIS 0x200
#define CF2DIS 0x400
#define CF3DIS 0x800
#define CF1LATCH 0x1000
#define CF2LATCH 0x2000
#define CF3LATCH 0x4000
#define RSTDONE 0x8000

// APHCAL, BPHCAL, CPHCAL
#define PHCALVAL 0x3FF

// PHSIGN
#define AWSIGN 0x1
#define BWSIGN 0x2
#define CWSIGN 0x4
#define SUM1SIGN 0x8
#define AVARSIGN 0x10
#define BVARSIGN 0x20
#define CVARSIGN 0x40
#define SUM2SIGN 0x80
#define SUM3SIGN 0x100

// CONFIG
#define INTEN 0x1
#define SWAP 0x8
#define MOD1SHORT 0x10
#define MOD2SHORT 0x20
#define HSDCEN 0x40
#define SWRST 0x80
#define VTOIA 0x300
#define VTOIB 0xC00
#define VTOIC 0x3000

// VTOI set values
#define VTOIA_A 0x0
#define VTOIA_B 0x100
#define VTOIA_C 0x200
#define VTOIB_B 0x0
#define VTOIB_C 0x400
#define VTOIB_A 0x800
#define VTOIC_C 0x0
#define VTOIC_A 0x1000
#define VTOIC_B 0x2000

// MMODE
#define PERSEL 0x3
#define PEAKSEL0 0x4
#define PEAKSEL1 0x8
#define PEAKSEL2 0x10

// ACCMODE
#define WATTACC 0x3
#define VARACC 0xC
#define CONSEL 0x30
#define REVAPSEL 0x40
#define REVRPSEL 0x80

// LCYCMODE
#define LWATT 0x1
#define LVAR 0x2
#define LVA 0x4
#define ZXSEL0 0x8
#define ZXSEL1 0x10
#define ZXSEL2 0x20
#define RSTREAD 0x40

// HSDC_CFG
#define HCLK 0x1
#define HSIZE 0x2
#define HGAP 0x4
#define HXFER 0x18
#define HSAPOL 0x20

// LPOILVL
#define LPOIL 0x7
#define LPLINE 0xF8

// CONFIG2
#define EXTREFEN 0x1
#define I2C_LOCK 0x2

// RUN
#define STOP 0x0
#define START 0x1
