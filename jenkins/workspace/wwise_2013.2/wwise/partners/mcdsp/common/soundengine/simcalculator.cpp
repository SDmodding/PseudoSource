// File Line: 32
// RVA: 0xB0B690
void __fastcall SIMCalculator::CalculateSIMCoefficients(
        unsigned int sampleRate,
        FutzSIMType type,
        long double tuning,
        SCoefs *hpfCoefs,
        SCoefs *coefs1,
        SCoefs *coefs2,
        SCoefs *coefs3,
        SCoefs *coefs4,
        SCoefs *coefs5,
        SCoefs *lpfCoefs)
{
  long double v12; // xmm2_8
  long double v13; // xmm1_8
  long double v14; // xmm10_8
  long double v15; // xmm10_8
  long double v16; // xmm3_8
  long double v17; // xmm2_8
  long double v18; // xmm10_8
  long double v19; // xmm3_8
  long double v20; // xmm10_8
  long double v21; // xmm10_8
  long double v22; // xmm3_8
  long double v23; // xmm2_8
  long double v24; // xmm10_8
  long double v25; // xmm10_8
  long double v26; // xmm10_8
  long double v27; // xmm2_8
  long double v28; // xmm3_8
  long double v29; // xmm1_8
  long double v30; // xmm10_8
  long double v31; // xmm10_8
  long double v32; // xmm3_8
  long double v33; // xmm2_8

  switch ( type )
  {
    case eFutzSIM_Vintage_Box_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 56.0, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        tuning * 237.0,
        kOneOver_kMax_Post_Q * 12.0,
        4.3,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 336.0, 6.8, 4.1, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 595.0, 12.8, 8.6, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 868.0, 9.300000000000001, -7.3, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_6000_0;
      goto LABEL_172;
    case eFutzSIM_Modern_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 50.0, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 1350.0, kOneOver_kMax_Post_Q * 2.0, -15.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 990.0, 16.0, -3.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1100.0, 16.0, 5.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2500.0, 16.0, 1.5, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_75;
      v13 = tuning * 3000.0;
      goto LABEL_172;
    case eFutzSIM_Answering_Machine:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 80.0, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 400.0, kOneOver_kMax_Post_Q * 10.5, -6.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 625.0, 9.699999999999999, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1640.0, 10.5, 6.2, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3590.0, 7.4, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_1980_0;
      goto LABEL_172;
    case eFutzSIM_Horrortone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 74.59999999999999, 1.4, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 158.8, kOneOver_kMax_Post_Q * 11.0, 7.3, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 224.9, 9.199999999999999, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 692.0, 10.0, 10.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1680.0, 2.7, 8.4, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_6180_0;
      goto LABEL_172;
    case eFutzSIM_BoomBox_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 169.0, 0.51, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 80.0, 16.0, -12.6, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 250.0, 5.0, 6.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 400.0, 5.0, 5.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 900.0, 4.0, -5.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_61;
      v13 = tuning * 9710.0;
      goto LABEL_172;
    case eFutzSIM_BoomBox_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 99.0, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 290.0, 5.0, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 780.0, 12.0, -3.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 999.0, 4.0, 4.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1650.0, 16.0, 8.800000000000001, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_6;
      v13 = DOUBLE_8760_0;
      goto LABEL_172;
    case eFutzSIM_Car_Radio_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 106.0, 1.4, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 47.5, kOneOver_kMax_Post_Q * 16.0, -13.6, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 212.9, 6.4, 3.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 439.4, 5.7, 4.3, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1810.0, 11.6, 8.6, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_55;
      v13 = DOUBLE_8900_0;
      goto LABEL_172;
    case eFutzSIM_Car_Radio_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 124.1, 0.24, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 192.3, 7.0, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 655.2, 6.4, 9.199999999999999, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 2040.0, 5.7, 8.800000000000001, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 3790.0, 11.6, 8.6, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_6;
      v13 = tuning * 8800.0;
      goto LABEL_172;
    case eFutzSIM_Van_Radio:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 50.0, 0.25, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 108.0, 16.0, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 321.0, 15.0, 12.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.3, 6.9, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4850.0, 1.6, 8.6, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3260.0, lpfCoefs);
      return;
    case eFutzSIM_Garbage_Can_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 34.8, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 120.6, 8.300000000000001, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 265.2, 13.2, -15.9, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 503.9, 16.0, -16.3, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2190.0, 9.5, -10.3, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v14 = tuning * 4670.0;
      goto LABEL_12;
    case eFutzSIM_Vacuum_Cleaner_Tube_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 69.27, 0.25, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 81.0, 16.0, 16.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 243.0, 16.0, 12.86, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 405.0, 16.0, 12.64, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 567.0, 16.0, 10.07, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 729.0, 16.0, 9.0, coefs5);
      v12 = DOUBLE_0_58;
      v13 = DOUBLE_1366_19;
      goto LABEL_172;
    case eFutzSIM_Garbage_Can_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 44.0, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 80.40000000000001, 2.4, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 224.9, 13.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 353.1, 16.0, 11.4, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 924.3, 16.0, -14.8, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 4620.0, lpfCoefs);
      return;
    case eFutzSIM_Glass_Cup:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 26.4, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 484.0, 4.6, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 925.0, 16.0, 14.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1270.0, 7.7, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1700.0, 16.0, 14.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_7130_0;
      goto LABEL_172;
    case eFutzSIM_Glass_Jar_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 24.4, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 161.2, 2.0, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 633.8, 1.9, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 803.1, 16.0, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1340.0, 16.0, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_1;
      v13 = DOUBLE_6890_0;
      goto LABEL_172;
    case eFutzSIM_Glass_Jar_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 24.4, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 156.8, 5.3, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 587.1, 8.199999999999999, -16.3, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 825.4, 16.0, 15.4, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1040.0, 16.0, -14.8, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_7380_0;
      goto LABEL_172;
    case eFutzSIM_Glass_Jar_3:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 22.5, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 170.0, 2.0, 11.4, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 498.1, 2.0, -6.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 921.1, 16.0, 9.6, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1140.0, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_4260_0;
      goto LABEL_172;
    case eFutzSIM_Guitar_Amp_I:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 80.0, 0.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 120.0, 2.0, 2.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 360.0, 3.0, -3.5, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 480.0, 5.0, 1.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1500.0, 1.0, 1.5, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_4;
      v13 = tuning * 4000.0;
      goto LABEL_172;
    case eFutzSIM_Guitar_Amp_II:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 80.0, 0.7, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 120.0, 8.0, 0.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 240.0, 8.0, 0.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 360.0, 8.0, 0.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 480.0, 8.0, 0.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_7;
      v13 = tuning * 8000.0;
      goto LABEL_172;
    case eFutzSIM_Intercom_Small:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 45.0, 0.8, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 90.0, 1.0, -18.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 254.0, 7.0, 5.9, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 760.0, 4.2, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2190.0, 7.8, 17.8, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3840.0, lpfCoefs);
      return;
    case eFutzSIM_Metal_Pail_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 55.9, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 400.0, kOneOver_kMax_Post_Q * 0.4, 9.6, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 511.9, 16.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 648.5, 16.0, 11.4, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2070.0, 2.9, -10.3, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3820.0, lpfCoefs);
      return;
    case eFutzSIM_Metal_Pail_2:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 20.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 163.2, 1.5, 15.6, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 348.8, 9.9, -16.5, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 648.5, 16.0, 11.4, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1580.0, 6.4, -10.3, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3820.0, lpfCoefs);
      return;
    case eFutzSIM_Low_Rider:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 27.85, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 43.43, 2.42, 17.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1174.24, 4.48, 0.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2858.28, 9.24, 0.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6148.1, 16.0, 0.0, coefs4);
      CoefficientCalculator::CalculatePostGHighShelf(sampleRate, 443.25, kOneOver_kMax_Post_Q * 16.0, -13.01, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_9521_35;
      goto LABEL_172;
    case eFutzSIM_Classic_Headphones_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 63.76, 0.71, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 246.02, 4.66, -15.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 741.17, 12.0, -4.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2539.58, 7.73, 12.86, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4225.42, 11.02, 12.43, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9729.610000000001, 2.0, 0.0, coefs5);
      v12 = DOUBLE_0_76;
      v13 = tuning * 7141.38;
      goto LABEL_172;
    case eFutzSIM_Blue_Megaphone_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 432.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 424.0, 4.1, 12.9, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1310.0, 11.5, 12.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2920.0, 12.3, 16.3, coefs3);
      CoefficientCalculator::CalculatePostGHighShelf(sampleRate, 8250.0, kOneOver_kMax_Post_Q, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 6000.0, lpfCoefs);
      return;
    case eFutzSIM_Blue_Megaphone_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 55.0, 0.5, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 424.0, kOneOver_kMax_Post_Q * 4.1, -14.4, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 474.0, 4.9, 14.6, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1360.0, 11.7, 14.8, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2980.0, 15.0, 10.9, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_25;
      v13 = DOUBLE_2690_0;
      goto LABEL_172;
    case eFutzSIM_PVC_Pipe:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 331.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 111.8, 3.2, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 400.0, 3.7, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1750.0, 16.0, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3200.0, 16.0, 11.6, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 5640.0, lpfCoefs);
      return;
    case eFutzSIM_Truck_Radio:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 40.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 475.0, 3.6, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1070.0, 16.0, 6.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1430.0, 16.0, 8.4, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5710.0, 16.0, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_26;
      v13 = DOUBLE_3840_0;
      goto LABEL_172;
    case eFutzSIM_Antique_Tube_Radio_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 81.73999999999999, 0.37, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 285.39, 3.44, 16.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 469.7, 1.14, -15.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 629.3200000000001, 11.51, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 400.0, 16.0, 12.64, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1305.08, 7.08, 13.93, coefs5);
      v12 = DOUBLE_0_42;
      v13 = tuning * 3738.69;
      goto LABEL_172;
    case eFutzSIM_Radio_Tube_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 76.7, 0.3, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 200.9, 3.5, 8.4, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 400.0, 3.9, -4.7, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 610.5, 10.4, 10.1, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1620.0, 2.5, 4.9, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_8;
      v13 = DOUBLE_5230_0;
      goto LABEL_172;
    case eFutzSIM_Radio_Tube_2:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 113.9, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 163.9, 5.5, -7.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 298.0, 12.0, -14.6, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 554.7, 10.0, 13.1, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 861.8, 9.0, 7.7, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_525;
      v13 = DOUBLE_3710_0;
      goto LABEL_172;
    case eFutzSIM_Portable_Radio:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 307.56, 0.8, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 156.27, 1.414, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 346.32, 7.11, 14.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 626.35, 9.9, 10.07, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3831.73, 2.52, 10.29, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2015.77, 4.3, -10.5, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2804.16, lpfCoefs);
      return;
    case eFutzSIM_Driver:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 128.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 169.0, 3.3, -5.1, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 229.0, 5.0, 15.1, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1860.0, 4.7, -6.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1320.0, 16.0, 9.6, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_6210_0;
      goto LABEL_172;
    case eFutzSIM_Small_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 358.2, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 258.3, 15.7, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 290.0, 12.0, 12.9, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 439.4, 16.0, -14.6, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3030.0, 15.8, -9.199999999999999, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 4180.0, lpfCoefs);
      return;
    case eFutzSIM_Tiny_Speaker:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 47.0, 1.4, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 280.1, kOneOver_kMax_Post_Q * 0.4, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 240.0, 6.0, -6.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 946.7, 16.0, 16.4, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3000.0, 7.2, 16.7, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3130.0, lpfCoefs);
      return;
    case eFutzSIM_Bookshelf_Speaker_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 156.2, 0.25, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 308.8, 8.4, 7.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 617.9, 6.5, 14.4, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 896.2, 16.0, 10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2730.0, 3.0, 8.1, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_45;
      v13 = DOUBLE_10000_0;
      goto LABEL_172;
    case eFutzSIM_Toy_Speaker_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 296.7, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 440.0, 9.6, 13.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1910.0, 3.1, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3530.0, 11.3, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 13800.0, 12.0, -12.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_65;
      v13 = tuning * 2630.0;
      goto LABEL_172;
    case eFutzSIM_Toy_Speaker_2:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 296.7, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 922.0, 9.6, -9.6, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1620.0, 3.1, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3730.0, 11.3, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 6080.0, 12.0, -10.4, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_0_65;
      v13 = tuning * 1870.0;
      goto LABEL_172;
    case eFutzSIM_Portable_TapeDeck_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 118.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 116.5, 6.0, -19.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 218.9, 16.0, -9.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 290.0, 15.7, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2135.0, 5.3, 15.9, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_6;
      v13 = DOUBLE_6020_0;
      goto LABEL_172;
    case eFutzSIM_Portable_TapeDeck_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 2648.84, 0.6899999999999999, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 861.92, 12.0, 4.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2188.54, 16.0, 3.64, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3433.32, 16.0, 7.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5712.44, 16.0, -11.14, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 12115.28, 6.5, 6.64, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_3237_88;
      goto LABEL_172;
    case eFutzSIM_Euro_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 2066.12, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 397.19, 14.03, 11.57, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1765.29, 9.449999999999999, 13.07, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2085.01, 16.0, 16.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3684.22, 16.0, -16.07, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9653.49, 16.0, 13.71, coefs5);
      v12 = DOUBLE_0_6;
      v13 = DOUBLE_2103_23;
      goto LABEL_172;
    case eFutzSIM_Small_Television_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 46.0, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 111.2, kOneOver_kMax_Post_Q * 2.0, -15.6, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 272.0, 4.9, 5.8, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 562.3, 5.5, -13.1, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1810.0, 5.9, -9.9, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_3130_0;
      goto LABEL_172;
    case eFutzSIM_Cheapo_Earbuds_2:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 7773.58, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4000.0, 16.0, 0.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 244.22, 4.68, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1683.41, 1.78, -10.93, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4000.0, 16.0, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5108.97, 16.0, 14.57, coefs5);
      v12 = DOUBLE_0_85;
      v13 = tuning * 11813.7;
      goto LABEL_172;
    case eFutzSIM_Tin_Can:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 145.96, 0.32, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 311.0, 15.31, 13.29, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 479.9, 16.0, 10.9, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 792.27, 7.75, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2040.0, 13.39, 13.5, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4480.75, 13.42, 13.07, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_5356_3;
      goto LABEL_172;
    case eFutzSIM_Toy_Mic:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 60.5, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 306.5, 0.4, 10.9, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1770.0, 3.7, -12.6, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6630.0, 8.800000000000001, -18.0, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 9060.0, 1.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_0;
      v13 = DOUBLE_9080_0;
      goto LABEL_172;
    case eFutzSIM_Vacuum_Cleaner_Tube_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 21.0, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 80.0, 7.9, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 160.0, 15.0, 16.1, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 240.0, 16.0, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1270.0, 3.6, 13.1, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_6210_0;
      goto LABEL_172;
    case eFutzSIM_Wash_Tub:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 22.5, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 42.1, 3.4, 16.9, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 175.7, 15.4, 16.3, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 179.4, 6.6, 9.9, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1710.0, 2.3, -10.3, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 5800.0, lpfCoefs);
      return;
    case eFutzSIM_Watercooler_Bottle:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 28.5, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 130.0, 4.6, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 311.3, 3.1, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 165.0, 12.0, 11.9, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1190.0, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_7630_0;
      goto LABEL_172;
    case eFutzSIM_Cheapo_Earbuds_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 60.4, 1.4, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 300.0, 11.0, -12.2, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 727.0, 0.4, -12.4, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3890.0, 5.3, 13.3, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8930.0, 10.5, 5.4, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_4;
      v13 = DOUBLE_11800_0;
      goto LABEL_172;
    case eFutzSIM_Classic_Headphones_1:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 81.73999999999999, 1.11, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4000.0, 6.5, 9.859999999999999, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1133.55, 7.14, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1146.9, 1.47, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4859.41, 9.66, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8961.5, 16.0, -9.210000000000001, coefs5);
      v12 = DOUBLE_0_6;
      v13 = DOUBLE_8860_73;
      goto LABEL_172;
    case eFutzSIM_Crystal_Earbud:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 123.68, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 239.49, 0.4, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1737.78, 8.789999999999999, 17.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2993.58, 15.65, 14.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9323.870000000001, 7.42, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3101.03, 13.72, 12.86, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 887.4299999999999, lpfCoefs);
      return;
    case eFutzSIM_Canceling_Headphones:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 73.2, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 515.96, 2.44, -17.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2878.74, 2.76, -6.86, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5179.47, 16.0, -12.21, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6202.06, 16.0, 7.93, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9466.52, 16.0, -6.43, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3237.88, lpfCoefs);
      return;
    case eFutzSIM_Pillow_Speaker_Alone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 902.59, 0.9, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 831.3, 2.0, 5.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1230.71, 10.38, -9.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3831.19, 12.57, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 5871.2, 14.12, 13.07, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 2833.88, 16.0, 10.71, coefs5);
      v12 = DOUBLE_0_71;
      v13 = DOUBLE_2609_6;
      goto LABEL_172;
    case eFutzSIM_Pillow_Speaker_Under_Pillow:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 572.37, 0.79, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 3040.97, 11.26, 8.359999999999999, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 935.64, 3.16, 5.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1211.53, 2.0, -4.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3535.81, 16.0, -15.86, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 4616.21, 16.0, 9.640000000000001, coefs5);
      v12 = DOUBLE_0_72;
      v13 = DOUBLE_2180_22;
      goto LABEL_172;
    case eFutzSIM_Studio_Headphones_1:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 20.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3212.34, 6.65, -2.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4352.1, 5.96, 10.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7530.09, 15.65, 9.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9448.32, 16.0, -8.57, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10857.11, 16.0, 11.79, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 12694.49, lpfCoefs);
      return;
    case eFutzSIM_Tinny_Earbuds:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 902.59, 0.68, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 902.59, 0.68, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1622.29, 7.26, 10.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4893.62, 6.8, -15.64, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3930.09, 14.03, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2609.6, 0.46, coefs5);
      v12 = DOUBLE_0_46;
      v13 = DOUBLE_2609_6;
      goto LABEL_172;
    case eFutzSIM_Emergency_Radio:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 220.83, 0.5, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 484.61, 5.96, 14.14, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1520.49, 4.36, 10.07, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2600.86, 6.95, 13.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4325.49, 8.279999999999999, 18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 7673.81, 0.25, coefs5);
      v14 = tuning * 7673.81;
      goto LABEL_12;
    case eFutzSIM_Mono_BoomBox:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 220.83, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 183.1, 8.460000000000001, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 627.52, 2.9, 5.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1761.36, 16.0, -14.79, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4780.82, 16.0, 11.57, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6576.85, 16.0, 12.64, coefs5);
      v12 = DOUBLE_0_43;
      v13 = DOUBLE_11813_7;
      goto LABEL_172;
    case eFutzSIM_Stereo_BoomBox:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 134.36, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 60.0, 8.279999999999999, -6.21, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 209.21, 3.58, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 393.77, 4.19, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 4.19, 15.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4816.96, 16.0, 18.0, coefs5);
      v12 = DOUBLE_0_43;
      v13 = DOUBLE_10231_23;
      goto LABEL_172;
    case eFutzSIM_Clock_Radio:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 158.56, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 57.12, 3.92, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 348.77, 2.22, 8.359999999999999, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2231.77, 5.22, 11.79, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4660.21, 16.0, -6.86, coefs4);
      v15 = tuning * 13257.41;
      v16 = DOUBLE_12_0;
      v17 = DOUBLE_16_0;
      goto LABEL_61;
    case eFutzSIM_Cube_Alarm_Clock:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 307.56, 0.65, hpfCoefs);
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 307.56, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4300.0, 16.0, 15.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5526.33, 16.0, -10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9941.65, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 7673.81, 0.98, coefs5);
      v12 = DOUBLE_0_98;
      v13 = DOUBLE_7673_81;
      goto LABEL_172;
    case eFutzSIM_Red_Megaphone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 362.96, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 57.12, 0.4, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 223.18, 3.37, -9.210000000000001, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 0.4, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5000.0, 8.460000000000001, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8000.0, 16.0, -18.0, coefs5);
      v12 = DOUBLE_1_37;
      v13 = DOUBLE_4638_81;
      goto LABEL_172;
    case eFutzSIM_Stereo_Alarm_Clock:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 58.69, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 57.12, 3.92, 0.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 113.36, 1.43, 11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 346.04, 3.15, 14.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5802.88, 16.0, 4.71, coefs4);
      v18 = tuning * 8860.73;
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 8860.73, 1.41, coefs5);
      v12 = DOUBLE_1_41;
      v13 = v18;
      goto LABEL_172;
    case eFutzSIM_Antique_Speaker:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 113.85, 0.72, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 339.34, 11.77, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 697.48, 4.59, 11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2316.84, 16.0, -5.14, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3720.43, 11.77, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9977.200000000001, 11.77, -18.0, coefs5);
      v12 = DOUBLE_0_65;
      v13 = DOUBLE_3013_23;
      goto LABEL_172;
    case eFutzSIM_Large_Active_Speakers:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 260.61, 0.74, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2651.48, 10.38, 7.07, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 255.17, 5.26, 3.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 972.96, 1.09, -12.43, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4111.16, 7.63, 3.86, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8961.5, 5.37, 4.5, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_6411_18;
      goto LABEL_172;
    case eFutzSIM_Large_Passive_Speakers:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 203.28, 0.25, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, tuning * 40.0, kOneOver_kMax_Post_Q * 2.0, 7.29, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 885.72, 4.31, -4.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1000.0, 0.4, -12.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2442.16, 6.55, 6.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4079.0, 5.96, 5.57, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_12694_49;
      goto LABEL_172;
    case eFutzSIM_Large_Studio_Monitors:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 20.0, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 20.0, 1.41, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 120.69, 14.98, -12.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 582.53, 14.98, -5.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4125.69, 16.0, 4.29, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7057.47, 6.65, 3.64, coefs5);
      v13 = DOUBLE_18187_0;
      v12 = DOUBLE_1_41;
      goto LABEL_172;
    case eFutzSIM_Medium_Active_Speakers:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 648.0700000000001, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 91.75, 5.22, 8.140000000000001, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 348.77, 6.84, 12.64, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 275.73, 10.78, 10.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1575.06, 1.35, -12.64, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8254.040000000001, 8.15, 9.43, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 5356.3, lpfCoefs);
      return;
    case eFutzSIM_Medium_Speakers:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 75.25, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 117.42, 1.06, -7.07, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 259.49, 4.07, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 307.68, 0.4, -13.93, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5407.7, 16.0, 1.5, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8254.040000000001, 16.0, 6.0, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_7141_38;
      goto LABEL_172;
    case eFutzSIM_Medium_Studio_Monitors:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 75.25, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 75.25, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 84.51000000000001, 14.98, -4.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 480.82, 16.0, -9.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3187.21, 16.0, 7.73, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4682.28, 16.0, 5.36, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_14657_96;
      goto LABEL_172;
    case eFutzSIM_Portable_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 307.56, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 311.3, 16.0, 15.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 500.0, 16.0, -9.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2700.0, 16.0, 10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4328.96, 8.1, 14.36, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10000.0, 16.0, 0.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3479.29, lpfCoefs);
      return;
    case eFutzSIM_Cylinder_Speakers:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 334.11, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 145.07, 1.37, 9.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 719.63, 9.24, 11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 556.99, 0.96, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5183.97, 0.4, -12.64, coefs4);
      v19 = DOUBLE_18_0;
      goto LABEL_171;
    case eFutzSIM_Small_Passive_Speakers:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 1750.75, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1387.96, 9.039999999999999, 10.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 224.94, 1.35, 16.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 291.26, 1.75, 13.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5161.48, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7196.86, 10.09, 18.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 3237.88, lpfCoefs);
      return;
    case eFutzSIM_Small_Studio_Monitors:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 134.36, 1.03, hpfCoefs);
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 134.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 475.23, 16.0, -12.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 632.46, 16.0, -15.21, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2778.99, 4.89, -8.359999999999999, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 12694.49, 0.93, coefs5);
      v12 = DOUBLE_0_93;
      v13 = DOUBLE_12694_49;
      goto LABEL_172;
    case eFutzSIM_Studio_Subwoofer:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 20.0, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 46.24, 1.1, 3.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 133.62, 1.44, 6.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 362.11, 1.414, coefs4);
      v20 = tuning * 66.66;
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 66.66, 1.0, coefs5);
      v12 = DOUBLE_1_0;
      v13 = v20;
      goto LABEL_172;
    case eFutzSIM_Surround_Speakers:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 505.5, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 106.68, 6.4, 2.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 536.34, 6.5, 9.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 221.43, 5.58, 11.79, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1710.06, 4.19, -8.140000000000001, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6275.08, 3.54, 9.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2770.75, lpfCoefs);
      return;
    case eFutzSIM_Surround_System:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 58.69, 0.68, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 106.68, 6.4, 6.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 443.91, 2.0, 7.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 221.43, 5.58, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1710.06, 4.19, -11.79, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6275.08, 3.54, 7.5, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2770.75, lpfCoefs);
      return;
    case eFutzSIM_Surround_Subwoofer:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 30.26, 0.87, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 93.02, 2.84, 6.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 443.91, 6.84, 6.64, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 182.43, 1.41, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_182_43;
      goto LABEL_172;
    case eFutzSIM_Bookshelf_Speaker_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 172.25, 0.62, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 92.76000000000001, 1.53, 5.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3816.47, 1.9, 5.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 0.4, -13.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2188.54, 7.15, -14.57, coefs4);
      v21 = tuning * 4565.87;
      v22 = DOUBLE_9_41;
      v23 = DOUBLE_6_0;
      goto LABEL_81;
    case eFutzSIM_Station_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 102.25, 0.62, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 89.27, 1.66, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 137.63, 1.85, -18.0, coefs2);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2036.31, 1.414, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2036.31, 1.414, coefs4);
      v24 = tuning * 2609.6;
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2609.6, 0.25, coefs5);
      v12 = DOUBLE_0_25;
      v13 = v24;
      goto LABEL_172;
    case eFutzSIM_NOS_Telephone_Receiver:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 1365.6, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 207.18, 5.46, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4031.54, 16.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4811.66, 16.0, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5521.95, 11.0, -8.789999999999999, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2804.16, 0.54, coefs5);
      v12 = DOUBLE_0_54;
      v13 = tuning * 2804.16;
      goto LABEL_172;
    case eFutzSIM_Business_Phone:
      CoefficientCalculator::CalculateGParametric(sampleRate, 122.07, 1.74, -18.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 188.6, 2.76, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1437.78, 1.2, 16.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1974.23, 7.42, 5.57, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 894.75, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2804.16, 0.62, coefs5);
      v12 = DOUBLE_0_62;
      v13 = DOUBLE_2804_16;
      goto LABEL_172;
    case eFutzSIM_Business_Speaker_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 745.52, 1.414, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 134.67, 4.01, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 479.04, 3.92, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 765.39, 4.01, -10.5, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 872.9400000000001, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2804.16, 0.44, coefs5);
      v12 = DOUBLE_0_44;
      v13 = DOUBLE_2804_16;
      goto LABEL_172;
    case eFutzSIM_Cheapo_Handset:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 1919.43, 1.414, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 306.49, 2.32, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 630.11, 1.74, 6.0, coefs2);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2794.76, 1.414, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2794.76, 1.414, coefs4);
      v25 = tuning * 2609.6;
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2609.6, 0.44, coefs5);
      v12 = DOUBLE_0_44;
      v13 = v25;
      goto LABEL_172;
    case eFutzSIM_Cheapo_Headset:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 362.96, 0.36, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 362.96, 0.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 620.21, 4.01, 6.21, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 4000.0, 8.460000000000001, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 5557.98, 4.1, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 3013.23, 0.26, coefs5);
      v12 = DOUBLE_0_26;
      v13 = DOUBLE_3013_23;
      goto LABEL_172;
    case eFutzSIM_Classic_Desk_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 1628.34, 1.414, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 306.49, 2.32, 16.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 667.45, 1.74, 7.07, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1974.23, 3.67, 5.57, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2095.77, 1.414, coefs4);
      v26 = tuning * 2609.6;
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2609.6, 0.44, coefs5);
      v12 = DOUBLE_0_44;
      v13 = v26;
      goto LABEL_172;
    case eFutzSIM_Classic_Headset:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 428.34, 1.05, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1060.0, 4.4, -8.4, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4924.22, 16.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4234.48, 16.0, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5802.88, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 3237.88, 0.25, coefs5);
      v12 = DOUBLE_0_25;
      v13 = DOUBLE_3237_88;
      goto LABEL_172;
    case eFutzSIM_Classic_Wall_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 954.12, 1.414, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2627.82, 5.0, 15.64, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3146.15, 8.1, 15.0, coefs2);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2794.76, 1.414, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2794.76, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2609.6, 1.41, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_2609_6;
      goto LABEL_172;
    case eFutzSIM_Cradle_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 764.8200000000001, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 141.15, 6.13, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2755.21, 3.52, 3.6, coefs2);
      CoefficientCalculator::CalculatePostGHighShelf(sampleRate, 7396.86, kOneOver_kMax_Post_Q * 16.0, -18.0, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2715.46, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2715.46, 1.414, coefs5);
      v12 = DOUBLE_0_46;
      v13 = tuning * 2609.6;
      goto LABEL_172;
    case eFutzSIM_Desk_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 220.83, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 142.26, 3.15, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2559.6, 3.67, 11.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3863.23, 16.0, -18.0, coefs3);
      v27 = DOUBLE_5_34;
      v28 = DOUBLE_N18_0;
      v29 = tuning * 5370.08;
      goto LABEL_93;
    case eFutzSIM_Desk_Speaker_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 465.33, 0.82, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 142.26, 3.15, -9.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1400.45, 6.09, 9.640000000000001, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3863.23, 16.0, -18.0, coefs3);
      v28 = DOUBLE_N15_86;
      v27 = DOUBLE_7_1;
      v29 = tuning * 5672.71;
LABEL_93:
      CoefficientCalculator::CalculateGParametric(sampleRate, v29, v27, v28, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2260.04, 0.25, coefs5);
      v14 = tuning * 2260.04;
      goto LABEL_12;
    case eFutzSIM_Fax_Machine:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 465.33, 0.37, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 465.33, 0.37, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 138.42, 16.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4172.44, 5.96, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5964.15, 2.64, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 3237.88, 0.31, coefs5);
      v12 = DOUBLE_0_31;
      v13 = DOUBLE_3237_88;
      goto LABEL_172;
    case eFutzSIM_Rotary_Desk_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 1365.6, 0.55, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3786.61, 16.0, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4377.09, 16.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5224.07, 11.02, -12.21, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6690.0, 11.0, -15.43, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2804.16, 0.25, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2804.16, lpfCoefs);
      return;
    case eFutzSIM_House_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 1157.15, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 110.29, 16.0, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 733.09, 1.4, 7.67, coefs2);
      CoefficientCalculator::CalculatePostGHighShelf(sampleRate, 7396.86, kOneOver_kMax_Post_Q * 16.0, -18.0, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 3621.13, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 3621.13, 1.414, coefs5);
      v12 = DOUBLE_0_86;
      v13 = tuning * 2609.6;
      goto LABEL_172;
    case eFutzSIM_House_Speaker_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 334.11, 0.32, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 245.65, 1.414, coefs1);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 245.65, 1.414, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 458.76, 1.72, 7.71, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2816.74, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2816.74, 1.414, coefs5);
      v12 = DOUBLE_0_53;
      v13 = tuning * 2314.86;
      goto LABEL_172;
    case eFutzSIM_Modern_Headset:
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 80.0, 16.0, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 250.0, 4.01, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 250.0, 4.01, 9.210000000000001, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5000.0, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 3013.23, 0.25, coefs5);
      v12 = DOUBLE_0_25;
      v13 = DOUBLE_3013_23;
      goto LABEL_172;
    case eFutzSIM_Studio_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 549.15, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 571.24, kOneOver_kMax_Post_Q * 16.0, -5.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 208.81, 3.15, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 980.63, 1.9, 10.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3970.59, 11.02, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7063.64, 2.42, -9.0, coefs5);
      v12 = DOUBLE_0_36;
      v13 = DOUBLE_2260_04;
      goto LABEL_172;
    case eFutzSIM_Studio_Speaker_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 260.61, 1.41, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        200.0,
        kOneOver_kMax_Post_Q * 9.039999999999999,
        -18.0,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 400.0, 3.43, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 180.0, 16.0, -9.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4143.58, 5.21, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2428.54, 0.25, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2428.54, lpfCoefs);
      return;
    case eFutzSIM_Small_Television_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 307.56, 0.25, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2000.0, 7.8, 11.8, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4730.0, 16.0, 11.56, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 5000.0, 16.0, -10.93, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6399.01, 16.0, 7.71, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 10000.0, 16.0, -10.29, coefs5);
      v12 = DOUBLE_0_46;
      v13 = tuning * 12694.49;
      goto LABEL_172;
    case eFutzSIM_Karaoke_Toy:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 195.03, 0.25, hpfCoefs);
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 195.03, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 674.8, 16.0, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1339.06, 1.15, 8.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5029.73, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8699.309999999999, 16.0, 0.0, coefs5);
      v12 = DOUBLE_0_39;
      v13 = DOUBLE_2804_16;
      goto LABEL_172;
    case eFutzSIM_Analog_Baby_Monitor:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 362.96, 0.74, hpfCoefs);
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 362.96, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 616.67, 4.36, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1160.0, 8.65, 9.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2180.0, 7.1, 16.3, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 3738.69, 0.26, coefs5);
      v12 = DOUBLE_0_26;
      v13 = DOUBLE_3738_69;
      goto LABEL_172;
    case eFutzSIM_Blue_Walkie_Talkie:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 526.88, 0.92, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 327.46, 4.1, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 533.41, 2.42, 12.64, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 883.95, 5.46, 8.42, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3076.77, 7.92, 14.79, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 1957.3, 0.83, coefs5);
      v12 = DOUBLE_0_83;
      v13 = DOUBLE_1957_3;
      goto LABEL_172;
    case eFutzSIM_Cheapo_CB_Radio:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 541.62, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 494.0, 7.26, 6.29, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 530.88, 4.58, 16.5, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1418.2, 0.4, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1606.77, 8.65, 10.71, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 1695.11, 0.62, coefs5);
      v12 = DOUBLE_0_62;
      v13 = DOUBLE_1695_11;
      goto LABEL_172;
    case eFutzSIM_Digital_Baby_Monitor:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 465.33, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 300.0, 1.87, 0.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 99.62, 16.0, -17.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 627.51, 2.95, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3742.55, 7.92, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2609.6, 0.37, coefs5);
      v12 = DOUBLE_0_37;
      v13 = DOUBLE_2609_6;
      goto LABEL_172;
    case eFutzSIM_External_CB_Speaker:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 465.33, 0.29, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        186.62,
        kOneOver_kMax_Post_Q * 14.65,
        -9.210000000000001,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 223.71, 7.42, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1178.77, 0.59, -13.29, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1835.03, 2.76, 14.57, coefs4);
      v30 = tuning * 1271.4;
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 1271.4, 1.41, coefs5);
      v12 = DOUBLE_1_41;
      v13 = v30;
      goto LABEL_172;
    case eFutzSIM_Modern_CB_Radio:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 362.96, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 199.31, kOneOver_kMax_Post_Q * 0.4, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 312.55, 9.039999999999999, 14.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 594.03, 3.46, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2673.38, 4.19, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4503.72, 1.05, -18.0, coefs5);
      v12 = DOUBLE_0_6899999999999999;
      v13 = tuning * 1715.55;
      goto LABEL_172;
    case eFutzSIM_Modern_Handheld_CB:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 549.15, 0.57, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 257.98, 10.09, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1467.8, 4.81, -15.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1757.59, 11.77, 3.64, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2735.68, 11.77, 15.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 1933.98, 0.6, coefs5);
      v12 = DOUBLE_0_6;
      v13 = tuning * 1933.98;
      goto LABEL_172;
    case eFutzSIM_Modern_Walkie_Talkie:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 428.34, 0.28, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 161.88, 8.279999999999999, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 131.03, 16.0, -7.71, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 650.03, 4.58, 8.359999999999999, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5365.39, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 3237.88, 0.78, coefs5);
      v12 = DOUBLE_0_78;
      v13 = tuning * 3237.88;
      goto LABEL_172;
    case eFutzSIM_Tiny_Handheld_CB:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 704.03, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 246.14, 16.0, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 695.88, 3.1, 12.24, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1878.49, 10.09, 7.07, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2275.01, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2578.51, 0.52, coefs5);
      v12 = DOUBLE_0_52;
      v13 = tuning * 2578.51;
      goto LABEL_172;
    case eFutzSIM_Toy_Walkie_Talkie:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 307.56, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 300.0, 2.02, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 661.58, 7.89, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 830.2, 4.48, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3977.22, 9.449999999999999, 18.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6238.46, 16.0, 0.0, coefs5);
      v12 = DOUBLE_0_25;
      v13 = tuning * 6645.88;
      goto LABEL_172;
    case eFutzSIM_Vintage_Handheld_CB:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 596.5700000000001, 0.79, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 596.5700000000001, 0.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 782.9400000000001, 6.0, 7.5, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1131.28, 1.37, 11.14, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2428.81, 7.8, 15.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2888.78, 7.15, 15.21, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_1271_4;
      goto LABEL_172;
    case eFutzSIM_Wireless_Intercom:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 260.61, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 200.0, 5.4, -16.06, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 400.0, 2.98, 11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2560.0, 9.710000000000001, 13.47, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3971.27, 16.0, -12.64, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 10358.95, 6.95, -18.0, coefs5);
      v12 = DOUBLE_0_71;
      v13 = tuning * 6184.77;
      goto LABEL_172;
    case eFutzSIM_Candlestick_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 1365.6, 0.83, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 437.71, 1.57, 0.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1730.44, 8.460000000000001, 6.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1506.52, 16.0, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2640.6, 9.76, 16.71, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 1610.86, 1.414, coefs5);
      v12 = DOUBLE_0_72;
      v13 = DOUBLE_1695_11;
      goto LABEL_172;
    case eFutzSIM_Black_Transistor_Radio:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 1611.6, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 132.68, 1.12, -10.07, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 346.48, 8.460000000000001, 14.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1162.89, 2.41, 10.93, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2224.84, 7.42, 3.21, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4127.02, 2.89, 7.93, coefs5);
      v12 = DOUBLE_0_61;
      v13 = DOUBLE_2428_54;
      goto LABEL_172;
    case eFutzSIM_Silver_Transistor_Radio:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 902.59, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 353.03, 6.34, 16.93, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 835.25, 1.2, -11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3035.32, 8.279999999999999, 10.93, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 6374.42, 16.0, -8.359999999999999, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4605.28, 16.0, 7.07, coefs5);
      v12 = DOUBLE_0_64;
      v13 = tuning * 1957.3;
      goto LABEL_172;
    case eFutzSIM_Globe_Radio:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 239.9, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 89.27, 2.82, -12.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 344.39, 5.7, 18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 446.35, 4.58, 13.71, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1433.84, 4.48, 9.640000000000001, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 4017.43, 0.76, coefs5);
      v12 = DOUBLE_0_76;
      v13 = DOUBLE_4017_43;
      goto LABEL_172;
    case eFutzSIM_Antique_Tube_Radio_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 145.96, 0.71, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 231.71, 5.08, -12.21, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 367.01, 13.18, 9.640000000000001, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1957.62, 8.65, -8.359999999999999, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2442.16, 6.65, 6.21, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 3237.88, 1.15, coefs5);
      v12 = DOUBLE_1_15;
      v13 = DOUBLE_3237_88;
      goto LABEL_172;
    case eFutzSIM_Classic_Cell_Phone:
      CoefficientCalculator::CalculateGParametric(sampleRate, 1000.0, 16.0, 0.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 321.23, 2.9, 17.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 471.51, 11.09, 16.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 120.0, 0.4, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4715.07, 6.69, 11.14, coefs4);
      v15 = tuning * 10857.11;
      v16 = DOUBLE_15_0;
      v17 = DOUBLE_4_29;
LABEL_61:
      CoefficientCalculator::CalculateGParametric(sampleRate, v15, v17, v16, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2609.6, lpfCoefs);
      return;
    case eFutzSIM_Cheapo_Cell_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 307.56, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 217.14, 1.414, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 320.0, 2.16, 12.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 640.0, 9.24, 17.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2800.9, 10.09, 16.93, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2260.04, 0.61, coefs5);
      v12 = DOUBLE_0_61;
      v13 = tuning * 2260.04;
      goto LABEL_172;
    case eFutzSIM_Beat_Up_Cell_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 172.25, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 751.4, 6.36, -15.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1206.87, 6.36, -6.86, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2295.44, 16.0, -4.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4684.51, 11.0, 8.140000000000001, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7259.95, 16.0, 6.43, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 6184.77, lpfCoefs);
      return;
    case eFutzSIM_Awesome_Cell_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 203.28, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 163.2, 5.1, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 642.47, 2.03, 12.64, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2045.81, 16.0, -3.21, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4411.6, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 3013.23, 0.65, coefs5);
      v12 = DOUBLE_0_65;
      v13 = DOUBLE_3013_23;
      goto LABEL_172;
    case eFutzSIM_Awesome_Cell_Phone_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 88.8, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        tuning * 190.82,
        kOneOver_kMax_Post_Q * 16.0,
        -18.0,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 80.0, 1.53, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4059.62, 16.0, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5645.98, 4.29, -13.07, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2260.04, 0.46, coefs5);
      v12 = DOUBLE_0_46;
      v13 = DOUBLE_2260_04;
      goto LABEL_172;
    case eFutzSIM_Free_Headphone_Clips:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 96.47, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 471.51, 2.89, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4031.54, 6.65, 15.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7419.76, 16.0, 5.79, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10040.12, 10.54, 9.859999999999999, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 16966.86, 16.0, -18.0, coefs5);
      v12 = DOUBLE_0_25;
      v13 = DOUBLE_19542_95;
      goto LABEL_172;
    case eFutzSIM_Portable_DVD_Player:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 704.03, 0.76, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 704.03, 0.76, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1270.0, 8.5, -15.2, coefs2);
      CoefficientCalculator::CalculateGParametric(
        sampleRate,
        tuning * 8325.110000000001,
        16.0,
        9.640000000000001,
        coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10650.3, 16.0, 12.64, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 14806.67, 16.0, -18.0, coefs5);
      v12 = DOUBLE_0_36;
      v13 = tuning * 4017.43;
      goto LABEL_172;
    case eFutzSIM_Cool_Headphones:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 307.56, 1.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4000.0, 3.53, 11.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 882.3200000000001, 1.19, -11.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3577.94, 6.07, 11.79, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5059.64, 9.66, 17.14, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6225.99, 14.35, -15.43, coefs5);
      v12 = DOUBLE_0_71;
      v13 = DOUBLE_11813_7;
      goto LABEL_172;
    case eFutzSIM_Guitar_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 283.11, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4000.0, 16.0, 11.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1663.82, 9.720000000000001, 11.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 631.84, 7.26, 10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 315.13, 9.449999999999999, 16.71, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9210.549999999999, 12.57, 6.86, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_3237_88;
      goto LABEL_172;
    case eFutzSIM_Kids_Pod_Toy:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 764.8200000000001, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 536.97, 4.37, 15.21, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2180.13, 16.0, -13.07, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3396.36, 11.23, 12.43, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7937.41, 16.0, 13.5, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10480.9, 16.0, 10.71, coefs5);
      v12 = DOUBLE_0_62;
      v13 = DOUBLE_2260_04;
      goto LABEL_172;
    case eFutzSIM_Cash_Register_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 30.26, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 392.35, 7.92, -14.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 716.92, 3.29, -11.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3843.05, 9.039999999999999, 10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6655.3, 14.34, 5.36, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9283.18, 16.0, -15.0, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_8860_73;
      goto LABEL_172;
    case eFutzSIM_Shopping_Cart_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 902.59, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 392.2, 14.03, 9.640000000000001, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 996.16, 9.449999999999999, 10.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3949.85, 16.0, 9.210000000000001, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10040.12, 16.0, 11.14, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6866.64, 16.0, 9.859999999999999, coefs5);
      v12 = DOUBLE_0_35;
      v13 = DOUBLE_2804_16;
      goto LABEL_172;
    case eFutzSIM_Two_Inch_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 283.11, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 304.1, 3.67, 15.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1174.24, 4.48, -15.43, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2858.28, 9.24, 9.210000000000001, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6148.1, 16.0, 12.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10656.15, 16.0, -11.36, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 5755.65, lpfCoefs);
      return;
    case eFutzSIM_One_Inch_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 27.85, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 446.35, 4.89, 12.64, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 822.23, 6.36, -12.9, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5667.75, 5.11, 17.79, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8554.379999999999, 16.0, 10.07, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10952.29, 16.0, 9.210000000000001, coefs5);
      v12 = DOUBLE_0_54;
      v13 = DOUBLE_17544_72;
      goto LABEL_172;
    case eFutzSIM_Tiny_Piezo_Speaker:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 63.76, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 845.08, 5.22, 6.21, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 400.0, 1.01, -5.14, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 4275.16, 2.0, 6.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8617.74, 10.85, 10.07, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 11468.95, 6.55, 11.14, coefs5);
      v14 = tuning * 16925.12;
      goto LABEL_12;
    case eFutzSIM_Cell_Phone_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 123.68, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 312.55, 2.47, -10.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 892.71, 16.0, 11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1440.41, 9.449999999999999, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4684.51, 9.039999999999999, 15.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6506.01, 16.0, 5.14, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 6184.77, lpfCoefs);
      return;
    case eFutzSIM_Large_Flip_Phone_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 134.36, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        tuning * 1111.87,
        kOneOver_kMax_Post_Q * 2.08,
        -18.0,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, 2088.13, 8.460000000000001, 3.21, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 4407.57, 16.0, -4.71, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, 6300.25, 7.42, 4.29, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 11559.39, 16.0, 1.93, coefs5);
      v14 = tuning * 8245.940000000001;
      goto LABEL_12;
    case eFutzSIM_Small_Flip_Phone_Toy:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 21.73, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 903.95, 5.44, 5.14, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 823.88, 5.53, 12.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1156.53, 10.78, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3487.68, 6.21, 15.21, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5579.42, 9.630000000000001, 7.71, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_8245_940000000001;
      goto LABEL_172;
    case eFutzSIM_Learning_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 21.73, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 267.2, 8.460000000000001, 15.64, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 414.36, 5.58, -9.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2618.24, 16.0, 15.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6655.3, 14.34, 6.64, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8550.32, 16.0, -15.0, coefs5);
      v12 = DOUBLE_0_89;
      v13 = DOUBLE_11813_7;
      goto LABEL_172;
    case eFutzSIM_Large_Work_Surface_Toy:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 104.8, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 560.1, 4.01, 11.14, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1771.45, 3.22, 13.71, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5339.89, 16.0, 10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7426.54, 16.0, 7.71, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9806.32, 16.0, 5.79, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2428.54, lpfCoefs);
      return;
    case eFutzSIM_Red_Pocket_Radio:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 134.36, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, 295.87, kOneOver_kMax_Post_Q * 2.89, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 295.9, 2.32, -13.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1215.28, 1.37, 9.859999999999999, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5802.88, 16.0, 6.43, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 4017.43, 0.46, coefs5);
      v14 = tuning * 4017.43;
LABEL_12:
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, v14, lpfCoefs);
      return;
    case eFutzSIM_Cool_Earbuds:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 88.8, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1663.82, 16.0, 8.359999999999999, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2394.86, 16.0, -11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5224.07, 16.0, 6.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8321.83, 16.0, -7.71, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 14406.3, 16.0, -5.14, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 8860.73, lpfCoefs);
      return;
    case eFutzSIM_Gamer_Headset:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 203.28, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 625.25, 2.08, -11.36, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2088.13, 5.58, 5.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3638.03, 7.26, 8.140000000000001, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6475.34, 16.0, -17.36, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 11246.83, 16.0, -9.210000000000001, coefs5);
      v12 = DOUBLE_0_5;
      v13 = DOUBLE_8245_940000000001;
      goto LABEL_172;
    case eFutzSIM_Nameless_Earbuds:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 81.73999999999999, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3463.2, 9.449999999999999, 6.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8000.0, 16.0, -6.64, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 303.53, 0.79, -10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1856.64, 5.81, 13.71, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4668.83, 6.93, 6.21, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 7141.38, lpfCoefs);
      return;
    case eFutzSIM_Quality_Earbuds:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 27.85, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, 115.69, 1.12, -2.14, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1657.43, 1.12, -10.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3119.67, 3.36, 11.14, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7722.79, 16.0, 13.5, coefs4);
      v31 = tuning * 5000.0;
      v32 = DOUBLE_3_86;
      v33 = DOUBLE_1_56;
      goto LABEL_146;
    case eFutzSIM_Mid_Grade_Headphones:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, tuning * 1483.51, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2753.67, 5.53, 12.19, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 420.92, 0.6899999999999999, -13.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 5701.82, 13.81, 17.14, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4587.58, 4.37, -13.93, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, 8211.950000000001, 16.0, 12.86, coefs5);
      v12 = DOUBLE_1_41;
      v13 = tuning * 3237.88;
      goto LABEL_172;
    case eFutzSIM_Studio_Headphones_2:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 20.0, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(
        sampleRate,
        tuning * 2571.77,
        9.720000000000001,
        8.789999999999999,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2442.16, 2.0, 13.29, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3433.32, 12.57, -13.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4587.58, 5.14, 3.21, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8530.07, 12.85, 12.21, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_13640_94;
      goto LABEL_172;
    case eFutzSIM_In_Ear_Headphones:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 20.0, 1.41, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2242.38, 11.77, 12.21, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2725.17, 2.0, 8.359999999999999, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4903.16, 4.01, -13.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4980.79, 16.0, 12.86, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7856.66, 13.13, 14.14, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_10231_23;
      goto LABEL_172;
    case eFutzSIM_Broken_Cell_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 123.68, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 378.66, 8.84, 16.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1111.6, 2.53, -16.71, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3278.14, 16.0, 16.07, coefs3);
      CoefficientCalculator::CalculateGParametric(
        sampleRate,
        tuning * 4084.51,
        9.039999999999999,
        -9.859999999999999,
        coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7461.71, 16.0, 12.0, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 7673.81, lpfCoefs);
      return;
    case eFutzSIM_Mini_Video_Camera:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 104.8, 1.14, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 711.3099999999999, 6.5, -17.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2088.13, 9.24, -14.57, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7023.93, 7.42, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10605.93, 16.0, 14.79, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 14793.73, 16.0, 14.36, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 2260.04, lpfCoefs);
      return;
    case eFutzSIM_Medium_Flat_Panel_Television:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 902.59, 0.76, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 426.53, 5.32, 11.79, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 569.05, 11.23, 9.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, 1408.87, 1.25, -15.21, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1757.59, 6.48, 9.0, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4070.84, 6.95, 13.29, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_4638_81;
      goto LABEL_172;
    case eFutzSIM_Large_Flat_Panel_Television:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 99.17, 0.53, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 130.72, 1.78, 6.43, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1839.72, 4.37, 9.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 9376.450000000001, 12.29, 11.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 12163.89, 5.94, 15.86, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5825.27, 9.869999999999999, 16.29, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 1695.11, lpfCoefs);
      return;
    case eFutzSIM_Iso_Headphones:
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 368.42, 16.0, -7.29, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 144.62, 0.9399999999999999, 12.64, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1373.33, 9.300000000000001, -13.93, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2275.85, 4.89, 8.140000000000001, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 6034.36, 16.0, -7.5, coefs4);
      v31 = tuning * 9518.559999999999;
      v32 = DOUBLE_14_14;
      v33 = DOUBLE_5_22;
LABEL_146:
      CoefficientCalculator::CalculateGParametric(sampleRate, v31, v33, v32, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 4638.81, lpfCoefs);
      return;
    case eFutzSIM_Extra_Iso_Headphones:
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 108.18, 5.7, 10.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1502.79, 3.15, -16.5, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3443.95, 16.0, -12.43, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8287.16, 16.0, -13.29, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 16061.71, 16.0, -18.0, coefs5);
      v12 = DOUBLE_0_54;
      v13 = DOUBLE_10231_23;
      goto LABEL_172;
    case eFutzSIM_Classic_4_x_4_Vehicle:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 42.14, 1.18, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        tuning * 446.35,
        kOneOver_kMax_Post_Q * 4.89,
        11.36,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 969.22, 12.03, 8.140000000000001, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1792.3, 16.0, -14.14, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 7879.06, 16.0, 6.21, coefs4);
      v21 = tuning * 13269.0;
      v22 = DOUBLE_5_79;
      v23 = DOUBLE_16_0;
LABEL_81:
      CoefficientCalculator::CalculateGParametric(sampleRate, v21, v23, v22, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 4984.67, lpfCoefs);
      return;
    case eFutzSIM_Modern_Compact_Vehicle:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 81.73999999999999, 0.25, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        tuning * 446.35,
        kOneOver_kMax_Post_Q * 4.89,
        10.07,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 969.22, 5.46, 8.140000000000001, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 8100.0, 16.0, -10.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 12200.0, 16.0, -6.6, coefs4);
      CoefficientCalculator::CalculatePostGHighShelf(
        sampleRate,
        tuning * 4082.57,
        kOneOver_kMax_Post_Q * 16.0,
        -6.21,
        coefs5);
      v12 = DOUBLE_0_98;
      v13 = DOUBLE_13640_94;
      goto LABEL_172;
    case eFutzSIM_Ultra_Hybrid_Vehicle:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 128.2, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 300.0, 6.0, 8.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 933.0, 6.4, 14.4, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1230.0, 5.7, -19.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3300.0, 12.0, 6.2, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1000.0, 1.0, 0.0, coefs5);
      v12 = DOUBLE_1_5;
      v13 = DOUBLE_4410_0;
      goto LABEL_172;
    case eFutzSIM_Flip_Phone:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 145.96, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 131.06, 5.96, -18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 131.03, 0.9399999999999999, -18.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 923.91, 2.32, 18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4922.83, 10.78, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2609.6, 0.87, coefs5);
      v12 = DOUBLE_0_87;
      v13 = DOUBLE_2609_6;
      goto LABEL_172;
    case eFutzSIM_Flip_Phone_Speaker:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 465.33, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(
        sampleRate,
        tuning * 163.2,
        kOneOver_kMax_Post_Q * 16.0,
        -15.0,
        coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 80.0, 2.95, -17.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3172.07, 16.0, 9.859999999999999, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4411.6, 16.0, -18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2103.23, 0.51, coefs5);
      v12 = DOUBLE_0_51;
      v13 = DOUBLE_2103_23;
      goto LABEL_172;
    case eFutzSIM_Pocket_Cell_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 239.9, 1.19, hpfCoefs);
      CoefficientCalculator::CalculatePostGLowShelf(sampleRate, tuning * 177.14, 2.0, -10.5, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 400.0, 3.12, 12.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 2762.78, 16.0, 16.93, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1904.42, 8.800000000000001, 7.29, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 2260.04, 0.68, coefs5);
      v12 = DOUBLE_0_68;
      v13 = DOUBLE_2260_04;
      goto LABEL_172;
    case eFutzSIM_Pocket_Cell_Phone_Speaker:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 307.56, 0.25, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 648.0700000000001, 1.41, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 263.29, 5.44, 15.21, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 482.75, 3.76, -16.93, coefs3);
      CoefficientCalculator::CalculateGParametric(
        sampleRate,
        tuning * 1803.07,
        8.279999999999999,
        8.140000000000001,
        coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 3123.54, 0.25, coefs5);
      v12 = DOUBLE_1_19;
      v13 = tuning * 1957.3;
      goto LABEL_172;
    case eFutzSIM_Classic_Bar_Phone:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 334.11, 0.65, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 334.11, 0.65, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 338.03, 2.21, 6.0, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3584.6, 2.36, 13.29, coefs3);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2524.99, 1.414, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2804.16, 0.35, coefs5);
      v12 = DOUBLE_0_35;
      v13 = DOUBLE_2804_16;
      goto LABEL_172;
    case eFutzSIM_Cheapo_Cell_Phone_Speaker:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 902.59, 0.31, hpfCoefs);
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, tuning * 1035.89, 1.414, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 385.99, 6.94, 17.79, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1352.12, 2.64, 9.859999999999999, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3269.24, 4.33, 18.0, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, 894.75, 1.414, coefs5);
      v12 = DOUBLE_0_25;
      v13 = tuning * 2804.16;
      goto LABEL_172;
    case eFutzSIM_Classic_Television:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 307.56, 0.89, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 142.26, 4.31, 16.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 458.76, 8.33, -13.5, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 307.68, 8.880000000000001, 13.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1149.19, 5.96, 4.07, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4442.41, 9.869999999999999, 6.64, coefs5);
      CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, 1577.5, lpfCoefs);
      return;
    case eFutzSIM_Modern_Widescreen_Television:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 69.27, 0.44, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 172.35, 9.039999999999999, 10.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1856.64, 6.55, 8.789999999999999, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3831.19, 5.03, 8.359999999999999, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5712.44, 2.0, -7.29, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 10738.72, 16.0, 13.5, coefs5);
      v12 = DOUBLE_0_87;
      v13 = DOUBLE_7673_81;
      goto LABEL_172;
    case eFutzSIM_Large_CRT_Television:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 96.47, 0.64, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 84.51000000000001, 2.0, 7.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 201.58, 2.0, -2.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 464.16, 2.0, 7.5, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5407.7, 8.9, 8.57, coefs4);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 1211.53, 9.24, 5.14, coefs5);
      v12 = DOUBLE_1_41;
      v13 = DOUBLE_7141_38;
      goto LABEL_172;
    case eFutzSIM_AM_BoomBox:
      CoefficientCalculator::CalculateSecondOrderHighPass(sampleRate, 197.74, 0.44, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 368.42, 8.1, 13.71, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 3922.53, 16.0, 16.07, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5640.82, 11.02, 14.57, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5645.98, 11.51, 14.57, coefs4);
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, tuning * 2260.04, 0.64, coefs5);
      v12 = DOUBLE_0_64;
      v13 = DOUBLE_2260_04;
      goto LABEL_172;
    case eFutzSIM_Cylinder_Speakers_Bass:
      CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, 334.11, hpfCoefs);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 145.07, 1.37, 18.0, coefs1);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 719.63, 9.24, 11.36, coefs2);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 556.99, 0.96, -18.0, coefs3);
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 5183.97, 0.4, -12.64, coefs4);
      v19 = DOUBLE_18_0;
LABEL_171:
      CoefficientCalculator::CalculateGParametric(sampleRate, tuning * 4275.16, 8.1, v19, coefs5);
      v13 = DOUBLE_6807_11;
      v12 = DOUBLE_0_68;
LABEL_172:
      CoefficientCalculator::CalculateSecondOrderLowPass(sampleRate, v13, v12, lpfCoefs);
      break;
    default:
      return;
  }
}reak;
    default:
      return;
  }
}

// File Line: 1727
// RVA: 0xB15AB0
long double __fastcall SIMCalculator::GetSIMMixValue(FutzSIMType type)
{
  long double result; // xmm0_8

  switch ( type )
  {
    case eFutzSIM_Vintage_Box_Speaker:
      result = DOUBLE_N0_9;
      break;
    case eFutzSIM_Answering_Machine:
      result = DOUBLE_N7_2;
      break;
    case eFutzSIM_Horrortone:
    case eFutzSIM_Guitar_Amp_II:
    case eFutzSIM_Cheapo_Handset:
    case eFutzSIM_Two_Inch_Speaker:
    case eFutzSIM_Classic_4_x_4_Vehicle:
      result = DOUBLE_N4_9;
      break;
    case eFutzSIM_BoomBox_1:
    case eFutzSIM_Van_Radio:
    case eFutzSIM_Guitar_Amp_I:
    case eFutzSIM_Desk_Phone:
    case eFutzSIM_Nameless_Earbuds:
      result = DOUBLE_N6_6;
      break;
    case eFutzSIM_BoomBox_2:
      result = DOUBLE_N8_699999999999999;
      break;
    case eFutzSIM_Car_Radio_1:
    case eFutzSIM_Glass_Cup:
    case eFutzSIM_Stereo_Alarm_Clock:
    case eFutzSIM_Portable_Speaker:
    case eFutzSIM_Cheapo_Cell_Phone_Speaker:
      result = DOUBLE_N7_0;
      break;
    case eFutzSIM_Car_Radio_2:
    case eFutzSIM_Tin_Can:
      result = DOUBLE_N10_0;
      break;
    case eFutzSIM_Garbage_Can_1:
    case eFutzSIM_Large_Active_Speakers:
    case eFutzSIM_Medium_Active_Speakers:
      result = DOUBLE_N0_8;
      break;
    case eFutzSIM_Vacuum_Cleaner_Tube_2:
    case eFutzSIM_Radio_Tube_1:
    case eFutzSIM_House_Speaker_Phone:
    case eFutzSIM_Gamer_Headset:
      result = DOUBLE_N5_0;
      break;
    case eFutzSIM_Garbage_Can_2:
      result = DOUBLE_N2_5;
      break;
    case eFutzSIM_Glass_Jar_1:
    case eFutzSIM_Glass_Jar_2:
    case eFutzSIM_Metal_Pail_2:
      result = DOUBLE_N4_0;
      break;
    case eFutzSIM_Glass_Jar_3:
    case eFutzSIM_Medium_Flat_Panel_Television:
      result = DOUBLE_N0_4;
      break;
    case eFutzSIM_Intercom_Small:
    case eFutzSIM_Small_Flip_Phone_Toy:
      result = DOUBLE_N11_3;
      break;
    case eFutzSIM_Metal_Pail_1:
    case eFutzSIM_Surround_Speakers:
      result = DOUBLE_N1_5;
      break;
    case eFutzSIM_Classic_Headphones_2:
    case eFutzSIM_Euro_Phone:
      result = DOUBLE_N11_4;
      break;
    case eFutzSIM_Blue_Megaphone_1:
    case eFutzSIM_Bookshelf_Speaker_1:
    case eFutzSIM_Cube_Alarm_Clock:
      result = DOUBLE_N8_199999999999999;
      break;
    case eFutzSIM_Blue_Megaphone_2:
      result = DOUBLE_N13_5;
      break;
    case eFutzSIM_PVC_Pipe:
      result = DOUBLE_N8_9;
      break;
    case eFutzSIM_Truck_Radio:
      result = DOUBLE_N13_1;
      break;
    case eFutzSIM_Antique_Tube_Radio_1:
    case eFutzSIM_Radio_Tube_2:
    case eFutzSIM_Guitar_Toy:
    case eFutzSIM_Cash_Register_Toy:
      result = DOUBLE_N5_4;
      break;
    case eFutzSIM_Portable_Radio:
    case eFutzSIM_Quality_Earbuds:
    case eFutzSIM_Flip_Phone_Speaker:
      result = DOUBLE_N6_0;
      break;
    case eFutzSIM_Driver:
    case eFutzSIM_Modern_Handheld_CB:
    case eFutzSIM_Extra_Iso_Headphones:
      result = DOUBLE_N2_3;
      break;
    case eFutzSIM_Tiny_Speaker:
    case eFutzSIM_Studio_Headphones_1:
      result = DOUBLE_N9_199999999999999;
      break;
    case eFutzSIM_Toy_Speaker_1:
      result = DOUBLE_N1_8;
      break;
    case eFutzSIM_Portable_TapeDeck_1:
      result = DOUBLE_N9_0;
      break;
    case eFutzSIM_Portable_TapeDeck_2:
      result = DOUBLE_N1_4;
      break;
    case eFutzSIM_Cheapo_Earbuds_2:
    case eFutzSIM_Large_Work_Surface_Toy:
    case eFutzSIM_Iso_Headphones:
      result = DOUBLE_N7_5;
      break;
    case eFutzSIM_Toy_Mic:
    case eFutzSIM_Large_Studio_Monitors:
    case eFutzSIM_Kids_Pod_Toy:
      result = DOUBLE_N4_3;
      break;
    case eFutzSIM_Vacuum_Cleaner_Tube_1:
    case eFutzSIM_Red_Pocket_Radio:
      result = DOUBLE_N8_0;
      break;
    case eFutzSIM_Wash_Tub:
    case eFutzSIM_Small_Studio_Monitors:
      result = DOUBLE_N5_1;
      break;
    case eFutzSIM_Watercooler_Bottle:
      result = DOUBLE_N3_5;
      break;
    case eFutzSIM_Cheapo_Earbuds_1:
    case eFutzSIM_Station_Phone:
    case eFutzSIM_Fax_Machine:
      result = DOUBLE_N5_9;
      break;
    case eFutzSIM_Crystal_Earbud:
    case eFutzSIM_Cool_Earbuds:
      result = DOUBLE_N2_6;
      break;
    case eFutzSIM_Pillow_Speaker_Alone:
      result = DOUBLE_N3_8;
      break;
    case eFutzSIM_Pillow_Speaker_Under_Pillow:
      result = DOUBLE_N1_7;
      break;
    case eFutzSIM_Tinny_Earbuds:
    case eFutzSIM_Pocket_Cell_Phone:
      result = DOUBLE_N11_8;
      break;
    case eFutzSIM_Emergency_Radio:
      result = DOUBLE_N17_3;
      break;
    case eFutzSIM_Mono_BoomBox:
      result = DOUBLE_N12_4;
      break;
    case eFutzSIM_Stereo_BoomBox:
      result = DOUBLE_N16_7;
      break;
    case eFutzSIM_Clock_Radio:
    case eFutzSIM_Cradle_Phone:
      result = DOUBLE_N4_5;
      break;
    case eFutzSIM_Red_Megaphone:
      result = DOUBLE_N12_3;
      break;
    case eFutzSIM_Antique_Speaker:
    case eFutzSIM_Classic_Cell_Phone:
    case eFutzSIM_Large_CRT_Television:
      result = DOUBLE_N5_3;
      break;
    case eFutzSIM_Medium_Studio_Monitors:
      result = DOUBLE_N4_4;
      break;
    case eFutzSIM_Small_Passive_Speakers:
    case eFutzSIM_Modern_Walkie_Talkie:
    case eFutzSIM_Awesome_Cell_Phone_Speaker:
    case eFutzSIM_Shopping_Cart_Toy:
    case eFutzSIM_Large_Flat_Panel_Television:
      result = DOUBLE_N6_4;
      break;
    case eFutzSIM_NOS_Telephone_Receiver:
    case eFutzSIM_Rotary_Desk_Phone:
      result = DOUBLE_N3_3;
      break;
    case eFutzSIM_Business_Phone:
    case eFutzSIM_Studio_Phone:
      result = DOUBLE_N6_7;
      break;
    case eFutzSIM_Cheapo_Headset:
      result = DOUBLE_N8_4;
      break;
    case eFutzSIM_Classic_Desk_Phone:
      result = DOUBLE_N8_300000000000001;
      break;
    case eFutzSIM_Classic_Headset:
      result = DOUBLE_N11_1;
      break;
    case eFutzSIM_Classic_Wall_Phone:
    case eFutzSIM_Broken_Cell_Phone:
      result = DOUBLE_N5_6;
      break;
    case eFutzSIM_Desk_Speaker_Phone:
    case eFutzSIM_Tiny_Handheld_CB:
      result = DOUBLE_N5_5;
      break;
    case eFutzSIM_House_Phone:
      result = DOUBLE_N2_9;
      break;
    case eFutzSIM_Modern_Headset:
      result = DOUBLE_N16_8;
      break;
    case eFutzSIM_Studio_Speaker_Phone:
      result = DOUBLE_N4_8;
      break;
    case eFutzSIM_Small_Television_2:
      result = DOUBLE_N9_4;
      break;
    case eFutzSIM_Karaoke_Toy:
      result = DOUBLE_N8_6;
      break;
    case eFutzSIM_Analog_Baby_Monitor:
    case eFutzSIM_One_Inch_Speaker:
      result = DOUBLE_N18_0;
      break;
    case eFutzSIM_Blue_Walkie_Talkie:
      result = DOUBLE_N7_1;
      break;
    case eFutzSIM_Digital_Baby_Monitor:
      result = DOUBLE_N10_9;
      break;
    case eFutzSIM_Modern_CB_Radio:
      result = DOUBLE_N4_7;
      break;
    case eFutzSIM_Toy_Walkie_Talkie:
      result = DOUBLE_N17_9;
      break;
    case eFutzSIM_Vintage_Handheld_CB:
      result = DOUBLE_N12_8;
      break;
    case eFutzSIM_Wireless_Intercom:
      result = DOUBLE_N6_1;
      break;
    case eFutzSIM_Candlestick_Phone:
      result = DOUBLE_N13_3;
      break;
    case eFutzSIM_Black_Transistor_Radio:
    case eFutzSIM_Portable_DVD_Player:
    case eFutzSIM_AM_BoomBox:
      result = DOUBLE_N6_9;
      break;
    case eFutzSIM_Globe_Radio:
      result = DOUBLE_N11_7;
      break;
    case eFutzSIM_Antique_Tube_Radio_2:
      result = DOUBLE_N0_5;
      break;
    case eFutzSIM_Cheapo_Cell_Phone:
      result = DOUBLE_N13_7;
      break;
    case eFutzSIM_Beat_Up_Cell_Phone:
    case eFutzSIM_Large_Flip_Phone_Toy:
      result = DOUBLE_N3_0;
      break;
    case eFutzSIM_Awesome_Cell_Phone:
      result = DOUBLE_N6_3;
      break;
    case eFutzSIM_Free_Headphone_Clips:
      result = DOUBLE_N12_0;
      break;
    case eFutzSIM_Cool_Headphones:
      result = DOUBLE_N18_2;
      break;
    case eFutzSIM_Tiny_Piezo_Speaker:
      result = DOUBLE_N13_9;
      break;
    case eFutzSIM_Cell_Phone_Toy:
    case eFutzSIM_Learning_Toy:
      result = DOUBLE_N7_7;
      break;
    case eFutzSIM_Studio_Headphones_2:
      result = DOUBLE_N14_5;
      break;
    case eFutzSIM_In_Ear_Headphones:
      result = DOUBLE_N10_2;
      break;
    case eFutzSIM_Mini_Video_Camera:
      result = DOUBLE_N6_8;
      break;
    case eFutzSIM_Modern_Compact_Vehicle:
    case eFutzSIM_Modern_Widescreen_Television:
      result = DOUBLE_N6_2;
      break;
    case eFutzSIM_Flip_Phone:
      result = DOUBLE_N8_5;
      break;
    case eFutzSIM_Pocket_Cell_Phone_Speaker:
      result = DOUBLE_N3_1;
      break;
    case eFutzSIM_Classic_Bar_Phone:
      result = DOUBLE_N18_1;
      break;
    case eFutzSIM_Classic_Television:
      result = DOUBLE_N1_0;
      break;
    default:
      result = DOUBLE_1_0;
      break;
  }
  return result;
}

// File Line: 1904
// RVA: 0xB16060
// attributes: thunk
double __fastcall SIMCalculator::CalculateDecayTime(BiquadCoefficients *in_coeffs)
{
  double result; // xmm0_8

  *(float *)&result = CoefficientCalculator::CalculateDecayTime(in_coeffs);
  return result;
}

