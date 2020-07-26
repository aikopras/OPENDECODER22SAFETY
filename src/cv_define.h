//------------------------------------------------------------------------
//
// OpenDCC - OpenDecoder2.2
//
// Copyright (c) 2007 Kufer
//
// This source file is subject of the GNU general public license 2,
// that is available at the world-wide-web at
// http://www.gnu.org/licenses/gpl.txt
// 
//------------------------------------------------------------------------
//
// file:      cv_dedine.h
// author:    Wolfgang Kufer / Aiko Pras
// contact:   kufer@gmx.de
// webpage:   http://www.opendcc.de
// history:   2007-08-03 V0.1 kw start
//            2011-01-15 V0.2 ap New CV have been added: CmdStation. 
//                               Note that "reserved CVs" have been (mis)used for this purpose
//                               CmdStation is included to correct "errors" made by LENZ LZV100
//                               master stations. Although this correction will not be needed if 
//                               the decoder is used in the traditional way (controlling four 
//                               switches via four subsequent addresses, no RS-bus feedback), it 
//                               will improve operation if it is used together with 
//                               LENZ LZV100 master stations.
//            2012-01-03 v0.3 ap New Cvs for GBM added. 
//            2012-12-27 v0.4 ap Cvs have been reorded and cleaned up, to better support PoM.
//            2013-03-12 v0.5 ap The ability is added to program the CVs on the main (PoM).
//            2014-01-12 v0.6 ap Customized for safety decoder
//
//
//------------------------------------------------------------------------
//
// purpose:   flexible general purpose decoder for dcc
//            This is the cv-structure definition for the project
//            cv_data_xxxxx.h will contain the intial values.
//
//========================================================================

typedef struct
  {
    //            Name          CV   alt  Access comment
    unsigned char myAddrL;      //513   1  R/W    Accessory Address low (6 bits). Note: not the RS-Bus address
    unsigned char cv514;        //514   2  R      not used
    unsigned char cv515;        //515   3  R      not used
    unsigned char cv516;        //516   4  R      not used
    unsigned char cv517;        //517   5  R      not used
    unsigned char cv518;        //518   6  R      not used
    unsigned char version;      //519   7  R      Version. Should be > 7
    unsigned char VID;          //520   8  R/W    Vendor ID (0x0D = DIY Decoder
                                                    // write value 0x0D = 13 to reset CVs to default values
    unsigned char myAddrH;      //521   9  R/W    Accessory Address high (3 bits)
    unsigned char MyRsAddr;     //522  10  R/W    RS-bus address of this feedback decoder
    unsigned char cv523;        //523  11  R      not used
    unsigned char cv524;        //524  12  R      not used
    unsigned char cv525;        //525  13  R      not used
    unsigned char cv526;        //526  14  R      not used
    unsigned char cv527;        //527  15  R      not used
    unsigned char cv528;        //528  16  R      not used
    unsigned char cv529;        //529  17  R      not used
    unsigned char cv530;        //530  18  R      not used
    unsigned char CmdStation;   //531  19  R/W    Command Station. 0 = standard / 1 = Lenz
    unsigned char RSRetry;      //532  20  R/W    Number of RS-Bus retransmissions
    unsigned char SkipEven;     //533  21  R/W    Only Decoder Addresses 1, 3, 5 .... 1023 will be used
    unsigned char cv534;        //534  22  R      not used
    unsigned char Search;       //535  23  R/W*   If set to 1: decoder LED blinks. Value will be 0 after restart
    unsigned char cv536;        //536  24  R      not used
    unsigned char Restart;      //537  25  R/W*   To restart (as opposed to reset) the decoder: use after PoM write
    unsigned char DccQuality;   //538  26  R      DCC Signal Quality
    unsigned char DecType;      //539  27  R      Decoder Type (see global.h for possible values)
    unsigned char BiDi;         //540  28  R      Bi-Directional Communication Config. Since BiDi is not used, keep at 0
    unsigned char Config;       //541  29  R      Accessory Decoder configuration (similar to CV#29)
    unsigned char VID_2;        //542  30  R      Second Vendor ID, to detect AP decoders
    unsigned char cv543;        //543  31  R      not used
    unsigned char cv544;        //544  32  R      not used

    unsigned char SendFB;       //545  33  R/W    Decoder will send switch feedback messages via RS-Bus 

    unsigned char P_Emergency;	//546  34  R/W    Which Pin on the X8 connector is for emergency stop. Possible values: 1 .. 4
    unsigned char T_Watchdog;	//547  35  R/W    Number of seconds watchdog relay will remain active received
    unsigned char T_TrainMove;	//548  36  R/W    Time after an RS-emergency button push for PC to stop all trains (in 100 msec steps)
    unsigned char T_CheckMove;	//549  37  R/W    Interval in which we check if PC stopped all trains (in 100 msec steps)
    unsigned char T_RS_Push1;	//550  38  R/W    Time RS-bus stays ON after a PUSH button is pushed (in 20 ms steps) 
    unsigned char T_RS_Push2;	//551  39  R/W    Same here. A value of 0 means a toggle button 
    unsigned char T_RS_Push3;	//552  40  R/W    Same here 
    unsigned char T_RS_Push4;	//553  41  R/W    Same here 

    
 } t_cv_record;
