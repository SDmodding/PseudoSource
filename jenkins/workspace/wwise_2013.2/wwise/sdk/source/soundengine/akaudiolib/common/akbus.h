// File Line: 351
// RVA: 0xA7B1E0
__int64 __fastcall CAkBus::Children(CAkBus *this)
{
  return this->m_mapChildId.m_uLength + this->m_mapBusChildId.m_uLength;
}

// File Line: 381
// RVA: 0xA7CCB0
void __fastcall CAkBus::PositioningChangeNotification(
        CAkBus *this,
        float in_RTPCValue,
        __int64 in_ParameterID,
        CAkRegisteredObj *in_GameObj)
{
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 83) & 4) != 0 )
    ((void (__fastcall *)(CAkBus *, CAkIndexableVtbl *, __int64, CAkRegisteredObj *))this->vfptr[6].AddRef)(
      this,
      this->vfptr,
      in_ParameterID,
      in_GameObj);
}

// File Line: 423
// RVA: 0xA52190
bool __fastcall CAkBus::GetHdrGainComputer(CAkBus *this, float *out_fHdrThreshold, float *out_fRatio)
{
  __int64 v4; // rdi
  char *m_pProps; // r8
  unsigned int v8; // r9d
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rdx
  float *p_iValue; // rax
  char *v13; // r8
  unsigned int v14; // r9d
  __int64 v15; // rcx
  __int64 v16; // rdx
  float *v17; // rax
  char v18; // cl
  bool result; // al
  int iValue; // [rsp+40h] [rbp+8h] BYREF

  v4 = 0i64;
  if ( (this->m_RTPCBitArray.m_iBitArray & 0x100000000i64) != 0 )
  {
    *out_fHdrThreshold = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x20u, 0i64);
  }
  else
  {
    m_pProps = this->m_props.m_pProps;
    iValue = g_AkPropDefault[26].iValue;
    if ( m_pProps )
    {
      v8 = (unsigned __int8)*m_pProps;
      v9 = 0i64;
      while ( 1 )
      {
        v10 = (unsigned int)(v9 + 1);
        if ( m_pProps[v10] == 26 )
          break;
        v9 = (unsigned int)v10;
        if ( (unsigned int)v10 >= v8 )
          goto LABEL_7;
      }
      v11 = (__int64)&m_pProps[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_7:
      v11 = 0i64;
    }
    p_iValue = (float *)&iValue;
    if ( v11 )
      p_iValue = (float *)v11;
    *out_fHdrThreshold = *p_iValue;
  }
  if ( (this->m_RTPCBitArray.m_iBitArray & 0x400000000i64) != 0 )
  {
    *out_fRatio = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x22u, 0i64);
  }
  else
  {
    v13 = this->m_props.m_pProps;
    iValue = g_AkPropDefault[27].iValue;
    if ( v13 )
    {
      v14 = (unsigned __int8)*v13;
      v15 = 0i64;
      while ( 1 )
      {
        v16 = (unsigned int)(v15 + 1);
        if ( v13[v16] == 27 )
          break;
        v15 = (unsigned int)v16;
        if ( (unsigned int)v16 >= v14 )
          goto LABEL_20;
      }
      v4 = (__int64)&v13[4 * v15 + ((v14 + 4) & 0xFFFFFFFC)];
    }
LABEL_20:
    v17 = (float *)&iValue;
    if ( v4 )
      v17 = (float *)v4;
    *out_fRatio = *v17;
  }
  v18 = *((_BYTE *)this + 304);
  result = (v18 & 0x40) != 0;
  *((_BYTE *)this + 304) = v18 & 0xBF;
  return result;
}

// File Line: 570
// RVA: 0xA7C820
_BOOL8 __fastcall CAkBus::OnNewActivityChunk(CAkBus *this, unsigned __int16 in_flagForwardToBus)
{
  bool v3; // al
  bool v4; // di

  v3 = CAkParameterNodeBase::OnNewActivityChunk(this, in_flagForwardToBus);
  *((_BYTE *)this + 304) &= ~1u;
  v4 = v3;
  if ( (*((_BYTE *)this + 304) & 1) == 0 )
    CAkBus::UpdateVoiceVolumes(this);
  return v4;
}

