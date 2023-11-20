// File Line: 351
// RVA: 0xA7B1E0
__int64 __fastcall CAkBus::Children(CAkBus *this)
{
  return this->m_mapChildId.m_uLength + this->m_mapBusChildId.m_uLength;
}

// File Line: 381
// RVA: 0xA7CCB0
void __fastcall CAkBus::PositioningChangeNotification(CAkBus *this, float in_RTPCValue, __int64 in_ParameterID, CAkRegisteredObj *in_GameObj)
{
  if ( *((_BYTE *)&this->0 + 83) & 4 )
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
  unsigned __int64 v3; // rax
  float *v4; // r14
  signed __int64 v5; // rdi
  float *v6; // rsi
  CAkBus *v7; // rbx
  char *v8; // r8
  unsigned int v9; // er9
  __int64 v10; // rcx
  __int64 v11; // rdx
  signed __int64 v12; // rdx
  int *v13; // rax
  unsigned __int64 v14; // rax
  char *v15; // r8
  unsigned int v16; // er9
  __int64 v17; // rcx
  __int64 v18; // rdx
  int *v19; // rax
  unsigned __int8 v20; // cl
  bool result; // al
  int v22; // [rsp+40h] [rbp+8h]

  v3 = this->m_RTPCBitArray.m_iBitArray;
  v4 = out_fRatio;
  v5 = 0i64;
  v6 = out_fHdrThreshold;
  v7 = this;
  if ( _bittest64((const signed __int64 *)&v3, 0x20ui64) )
  {
    *out_fHdrThreshold = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x20u, 0i64);
  }
  else
  {
    v8 = this->m_props.m_pProps;
    v22 = g_AkPropDefault[26].iValue;
    if ( v8 )
    {
      v9 = (unsigned __int8)*v8;
      v10 = 0i64;
      while ( 1 )
      {
        v11 = (unsigned int)(v10 + 1);
        if ( v8[v11] == 26 )
          break;
        v10 = (unsigned int)v11;
        if ( (unsigned int)v11 >= v9 )
          goto LABEL_7;
      }
      v12 = (signed __int64)&v8[4 * v10 + ((v9 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_7:
      v12 = 0i64;
    }
    v13 = &v22;
    if ( v12 )
      v13 = (int *)v12;
    *(_DWORD *)v6 = *v13;
  }
  v14 = v7->m_RTPCBitArray.m_iBitArray;
  if ( _bittest64((const signed __int64 *)&v14, 0x22ui64) )
  {
    *v4 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v7, 0x22u, 0i64);
  }
  else
  {
    v15 = v7->m_props.m_pProps;
    v22 = g_AkPropDefault[27].iValue;
    if ( v15 )
    {
      v16 = (unsigned __int8)*v15;
      v17 = 0i64;
      while ( 1 )
      {
        v18 = (unsigned int)(v17 + 1);
        if ( v15[v18] == 27 )
          break;
        v17 = (unsigned int)v18;
        if ( (unsigned int)v18 >= v16 )
          goto LABEL_20;
      }
      v5 = (signed __int64)&v15[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
    }
LABEL_20:
    v19 = &v22;
    if ( v5 )
      v19 = (int *)v5;
    *(_DWORD *)v4 = *v19;
  }
  v20 = *((_BYTE *)v7 + 304);
  result = (v20 >> 6) & 1;
  *((_BYTE *)v7 + 304) = v20 & 0xBF;
  return result;
}

// File Line: 570
// RVA: 0xA7C820
__int64 __fastcall CAkBus::OnNewActivityChunk(CAkBus *this, unsigned __int16 in_flagForwardToBus)
{
  CAkBus *v2; // rbx
  unsigned __int8 v3; // al
  unsigned __int8 v4; // di

  v2 = this;
  v3 = CAkParameterNodeBase::OnNewActivityChunk((CAkParameterNodeBase *)&this->vfptr, in_flagForwardToBus);
  *((_BYTE *)v2 + 304) &= 0xFEu;
  v4 = v3;
  if ( !(*((_BYTE *)v2 + 304) & 1) )
    CAkBus::UpdateVoiceVolumes(v2);
  return v4;
}

