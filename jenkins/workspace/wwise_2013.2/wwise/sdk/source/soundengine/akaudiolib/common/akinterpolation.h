// File Line: 28
// RVA: 0xA564C0
float __fastcall AkInterpolation::InterpolateNoCheck(float in_fTimeRatio, float in_fInitialVal, float in_fTargetVal, AkCurveInterpolation in_eFadeCurve)
{
  float result; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm3_4

  switch ( in_eFadeCurve )
  {
    case 0:
      result = (float)((float)((float)((float)(1.0 - in_fTimeRatio) * (float)(1.0 - in_fTimeRatio))
                             * (float)(1.0 - in_fTimeRatio))
                     * (float)(in_fInitialVal - in_fTargetVal))
             + in_fTargetVal;
      break;
    case 1:
      v5 = in_fTimeRatio * 1.5707964;
      result = (float)((float)((float)((float)((float)((float)((float)(0.0083063254
                                                                     - (float)((float)(v5 * v5) * 0.00018363654))
                                                             * (float)(v5 * v5))
                                                     - 0.16664828)
                                             * (float)(v5 * v5))
                                     + 0.9999966)
                             * v5)
                     * (float)(in_fTargetVal - in_fInitialVal))
             + in_fInitialVal;
      break;
    case 2:
      result = (float)((float)((float)((float)(in_fTimeRatio - 3.0) * in_fTimeRatio) * 0.5)
                     * (float)(in_fInitialVal - in_fTargetVal))
             + in_fInitialVal;
      break;
    case 3:
      v6 = in_fTargetVal - in_fInitialVal;
      if ( in_fTimeRatio > 0.5 )
      {
        v8 = 3.1415927 - (float)(in_fTimeRatio * 3.1415927);
        result = (float)((float)(1.0
                               - (float)((float)((float)((float)((float)((float)(0.0041531627
                                                                               - (float)((float)(v8 * v8) * 0.00009181827))
                                                                       * (float)(v8 * v8))
                                                               - 0.083324142)
                                                       * (float)(v8 * v8))
                                               + 0.4999983)
                                       * v8))
                       * v6)
               + in_fInitialVal;
      }
      else
      {
        v7 = in_fTimeRatio * 3.1415927;
        result = (float)((float)((float)((float)((float)((float)((float)(0.0041531627
                                                                       - (float)((float)(v7 * v7) * 0.00009181827))
                                                               * (float)(v7 * v7))
                                                       - 0.083324142)
                                               * (float)(v7 * v7))
                                       + 0.4999983)
                               * v7)
                       * v6)
               + in_fInitialVal;
      }
      break;
    case 4:
      result = (float)((float)(in_fTargetVal - in_fInitialVal) * in_fTimeRatio) + in_fInitialVal;
      break;
    case 5:
      result = (float)((float)((float)((float)((float)((float)((float)((float)((float)(in_fTimeRatio * 3.1415927)
                                                                             * (float)(in_fTimeRatio * 3.1415927))
                                                                     * 0.00048483399)
                                                             - 0.01961384)
                                                     * (float)((float)(in_fTimeRatio * 3.1415927)
                                                             * (float)(in_fTimeRatio * 3.1415927)))
                                             + 0.24767479)
                                     * (float)((float)(in_fTimeRatio * 3.1415927) * (float)(in_fTimeRatio * 3.1415927)))
                             + 0.00069670216)
                     * (float)(in_fTargetVal - in_fInitialVal))
             + in_fInitialVal;
      break;
    case 6:
      result = (float)((float)((float)((float)(in_fTimeRatio + 1.0) * in_fTimeRatio) * 0.5)
                     * (float)(in_fTargetVal - in_fInitialVal))
             + in_fInitialVal;
      break;
    case 7:
      result = (float)((float)((float)((float)((float)((float)(0.04148775
                                                             - (float)((float)((float)(in_fTimeRatio * 1.5707964)
                                                                             * (float)(in_fTimeRatio * 1.5707964))
                                                                     * 0.0012712094))
                                                     * (float)((float)(in_fTimeRatio * 1.5707964)
                                                             * (float)(in_fTimeRatio * 1.5707964)))
                                             - 0.49991244)
                                     * (float)((float)(in_fTimeRatio * 1.5707964) * (float)(in_fTimeRatio * 1.5707964)))
                             + 0.99999332)
                     * (float)(in_fInitialVal - in_fTargetVal))
             + in_fTargetVal;
      break;
    case 8:
      result = (float)((float)((float)(in_fTimeRatio * in_fTimeRatio) * in_fTimeRatio)
                     * (float)(in_fTargetVal - in_fInitialVal))
             + in_fInitialVal;
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

