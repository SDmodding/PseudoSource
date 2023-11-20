// File Line: 35
// RVA: 0xA98040
void __fastcall AkDownmix::ComputeVolumes(AkSpeakerVolumes *in_volumes, unsigned int in_uOutputConfig, float *out_fOutputVolumes)
{
  unsigned int v3; // edx
  int v4; // edx
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  unsigned int v10; // edx
  int v11; // edx

  if ( in_uOutputConfig > 0x33 )
  {
    v10 = in_uOutputConfig - 55;
    if ( v10 )
    {
      v11 = v10 - 1532;
      if ( v11 )
      {
        if ( v11 == 4 )
        {
          *out_fOutputVolumes = in_volumes->fFrontLeft;
          out_fOutputVolumes[1] = in_volumes->fFrontRight;
          out_fOutputVolumes[2] = in_volumes->fCenter;
          out_fOutputVolumes[3] = in_volumes->fRearLeft;
          out_fOutputVolumes[4] = in_volumes->fRearRight;
          out_fOutputVolumes[5] = in_volumes->fSideLeft;
          out_fOutputVolumes[6] = in_volumes->fSideRight;
        }
      }
      else
      {
        *out_fOutputVolumes = (float)(in_volumes->fCenter * 0.70710677) + in_volumes->fFrontLeft;
        out_fOutputVolumes[1] = (float)(in_volumes->fCenter * 0.70710677) + in_volumes->fFrontRight;
        out_fOutputVolumes[2] = in_volumes->fRearLeft;
        out_fOutputVolumes[3] = in_volumes->fRearRight;
        out_fOutputVolumes[4] = in_volumes->fSideLeft;
        out_fOutputVolumes[5] = in_volumes->fSideRight;
      }
    }
    else
    {
      *out_fOutputVolumes = in_volumes->fFrontLeft;
      out_fOutputVolumes[1] = in_volumes->fFrontRight;
      out_fOutputVolumes[2] = in_volumes->fCenter;
      out_fOutputVolumes[3] = in_volumes->fRearLeft;
      out_fOutputVolumes[4] = in_volumes->fRearRight;
      out_fOutputVolumes[3] = in_volumes->fSideLeft + out_fOutputVolumes[3];
      out_fOutputVolumes[4] = in_volumes->fSideRight + out_fOutputVolumes[4];
    }
  }
  else if ( in_uOutputConfig == 51 )
  {
    *out_fOutputVolumes = in_volumes->fFrontLeft;
    out_fOutputVolumes[1] = in_volumes->fFrontRight;
    *out_fOutputVolumes = (float)(in_volumes->fCenter * 0.70710677) + *out_fOutputVolumes;
    out_fOutputVolumes[1] = (float)(in_volumes->fCenter * 0.70710677) + out_fOutputVolumes[1];
    out_fOutputVolumes[2] = in_volumes->fRearLeft;
    out_fOutputVolumes[3] = in_volumes->fRearRight;
    out_fOutputVolumes[2] = in_volumes->fSideLeft + out_fOutputVolumes[2];
    out_fOutputVolumes[3] = in_volumes->fSideRight + out_fOutputVolumes[3];
  }
  else
  {
    v3 = in_uOutputConfig - 3;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( !v4 )
      {
        *out_fOutputVolumes = (float)((float)((float)((float)((float)(in_volumes->fCenter * 0.70710677)
                                                            + in_volumes->fFrontRight)
                                                    + (float)(in_volumes->fRearRight * 0.70710677))
                                            + (float)(in_volumes->fSideRight * 0.70710677))
                                    + (float)((float)((float)((float)(in_volumes->fCenter * 0.70710677)
                                                            + in_volumes->fFrontLeft)
                                                    + (float)(in_volumes->fRearLeft * 0.70710677))
                                            + (float)(in_volumes->fSideLeft * 0.70710677)))
                            * 0.70710677;
        return;
      }
      if ( v4 != 3 )
        return;
      v5 = FLOAT_0_70710677;
      *out_fOutputVolumes = in_volumes->fFrontLeft;
      out_fOutputVolumes[1] = in_volumes->fFrontRight;
      out_fOutputVolumes[2] = in_volumes->fCenter;
      v6 = (float)(in_volumes->fRearLeft * 0.70710677) + *out_fOutputVolumes;
      *out_fOutputVolumes = v6;
      v7 = (float)(in_volumes->fRearRight * 0.70710677) + out_fOutputVolumes[1];
    }
    else
    {
      v5 = FLOAT_0_70710677;
      *out_fOutputVolumes = in_volumes->fFrontLeft;
      out_fOutputVolumes[1] = in_volumes->fFrontRight;
      v8 = (float)(in_volumes->fCenter * 0.70710677) + *out_fOutputVolumes;
      *out_fOutputVolumes = v8;
      v9 = (float)(in_volumes->fCenter * 0.70710677) + out_fOutputVolumes[1];
      out_fOutputVolumes[1] = v9;
      v6 = (float)(in_volumes->fRearLeft * 0.70710677) + v8;
      *out_fOutputVolumes = v6;
      v7 = (float)(in_volumes->fRearRight * 0.70710677) + v9;
    }
    out_fOutputVolumes[1] = v7;
    *out_fOutputVolumes = (float)(in_volumes->fSideLeft * v5) + v6;
    out_fOutputVolumes[1] = (float)(in_volumes->fSideRight * v5) + v7;
  }
}

