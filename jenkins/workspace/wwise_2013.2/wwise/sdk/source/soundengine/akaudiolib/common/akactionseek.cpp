// File Line: 40
// RVA: 0xA97390
CAkActionSeek *__fastcall CAkActionSeek::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionSeek *result; // rax
  CAkActionSeek *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionSeek *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v5 = result;
  if ( result )
  {
    CAkActionExcept::CAkActionExcept((CAkActionExcept *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSeek::`vftable';
    *(_QWORD *)&v5->m_position.m_base = 0i64;
    v5->m_position.m_mod.m_max = 0.0;
    *(_WORD *)&v5->m_bIsSeekRelativeToDuration = 0;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 72
// RVA: 0xA97590
AKRESULT __fastcall CAkActionSeek::SetActionParams(CAkActionSeek *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  CAkActionSeek *v3; // r10
  char v4; // r9
  char *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  char v8; // cl

  v3 = this;
  v4 = *(*io_rpData)++;
  this->m_bIsSeekRelativeToDuration = v4 != 0;
  v5 = *io_rpData + 12;
  *io_rpData = v5;
  v6 = *((float *)v5 - 2);
  v7 = *((float *)v5 - 1);
  this->m_position.m_base = *((float *)v5 - 3);
  this->m_position.m_mod.m_min = v6;
  this->m_position.m_mod.m_max = v7;
  v8 = *(*io_rpData)++;
  v3->m_bSnapToNearestMarker = v8 != 0;
  return CAkActionExcept::SetExceptParams((CAkActionExcept *)&v3->vfptr, io_rpData, io_rulDataSize);
}

// File Line: 93
// RVA: 0xA97500
signed __int64 __fastcall CAkActionSeek::Execute(CAkActionSeek *this, AkPendingAction *in_pAction)
{
  signed __int64 result; // rax

  switch ( this->m_eActionType )
  {
    case 0x1E02u:
    case 0x1E03u:
      result = CAkActionSeek::Exec(this, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      break;
    case 0x1E04u:
    case 0x1E05u:
      CAkActionSeek::AllExec(this, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      result = 1i64;
      break;
    case 0x1E08u:
    case 0x1E09u:
      CAkActionSeek::AllExecExcept(this, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      goto LABEL_5;
    default:
LABEL_5:
      result = 1i64;
      break;
  }
  return result;
}

// File Line: 125
// RVA: 0xA97410
signed __int64 __fastcall CAkActionSeek::Exec(CAkActionSeek *this, CAkRegisteredObj *in_pGameObj, unsigned int in_TargetPlayingID)
{
  unsigned int v3; // esi
  CAkRegisteredObj *v4; // rbp
  CAkActionSeek *v5; // rbx
  CAkIndexable *v6; // rdi
  bool v7; // cl
  RANGED_PARAMETER<float> *v8; // rdx
  RandomizerModifier *v9; // rcx
  char v10; // cl
  unsigned int v11; // ebx
  int v13; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v14; // [rsp+28h] [rbp-30h]
  unsigned int v15; // [rsp+30h] [rbp-28h]
  int v16; // [rsp+34h] [rbp-24h]
  int v17; // [rsp+38h] [rbp-20h]
  __int16 v18; // [rsp+3Ch] [rbp-1Ch]
  char v19; // [rsp+3Eh] [rbp-1Ah]
  int v20; // [rsp+48h] [rbp-10h]
  unsigned __int8 v21; // [rsp+4Ch] [rbp-Ch]

  v3 = in_TargetPlayingID;
  v4 = in_pGameObj;
  v5 = this;
  v6 = CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
  if ( !v6 )
    return 15i64;
  v8 = (RANGED_PARAMETER<float> *)v21;
  v7 = v5->m_bIsSeekRelativeToDuration;
  v18 = 0;
  v19 = 0;
  v17 = 4;
  v14 = v4;
  v15 = v3;
  LOBYTE(v8) = (v21 ^ v7) & 1 ^ v21;
  v16 = 0;
  v9 = (RandomizerModifier *)&v5->m_position;
  v21 = (unsigned __int8)v8;
  if ( (unsigned __int8)v8 & 1 )
    v20 = RandomizerModifier::GetModValue<float>(v9, v8);
  else
    v20 = (signed int)RandomizerModifier::GetModValue<float>(v9, v8);
  v10 = 2 * v5->m_bSnapToNearestMarker;
  v13 = 4;
  v21 ^= (v21 ^ v10) & 2;
  v11 = (__int64)v6->vfptr[4].__vecDelDtor(v6, (unsigned int)&v13);
  v6->vfptr->Release(v6);
  return v11;
}

// File Line: 158
// RVA: 0xA970F0
void __fastcall CAkActionSeek::AllExec(CAkActionSeek *this, CAkRegisteredObj *in_pGameObj, unsigned int in_TargetPlayingID)
{
  char v3; // al
  CAkActionSeek *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm6_4
  bool v7; // al
  char v8; // cl
  signed int v9; // eax
  signed int v10; // eax
  bool v11; // al
  CAkBus *v12; // rax
  CAkBus *v13; // rbx
  CAkBus *v14; // rax
  CAkBus *v15; // rbx
  int v16; // [rsp+20h] [rbp-48h]
  CAkRegisteredObj *v17; // [rsp+28h] [rbp-40h]
  unsigned int v18; // [rsp+30h] [rbp-38h]
  int v19; // [rsp+34h] [rbp-34h]
  int v20; // [rsp+38h] [rbp-30h]
  char v21; // [rsp+3Ch] [rbp-2Ch]
  bool v22; // [rsp+3Dh] [rbp-2Bh]
  char v23; // [rsp+3Eh] [rbp-2Ah]
  float v24; // [rsp+48h] [rbp-20h]
  char v25; // [rsp+4Ch] [rbp-1Ch]

  v3 = *((_BYTE *)&this->0 + 54);
  v4 = this;
  v21 = 0;
  v23 = 0;
  v5 = 0.0;
  v6 = this->m_position.m_mod.m_max - this->m_position.m_mod.m_min;
  v20 = v3 & 0x1F;
  v7 = this->m_bIsSeekRelativeToDuration;
  v17 = in_pGameObj;
  v18 = in_TargetPlayingID;
  v19 = 0;
  v8 = (v25 ^ v7) & 1 ^ v25;
  v25 = v8;
  if ( v8 & 1 )
  {
    if ( v6 != 0.0 )
    {
      v9 = rand();
      v8 = v25;
      v5 = (double)v9 * 0.00003051850947599719 * v6;
    }
    v24 = (float)(v5 + v4->m_position.m_mod.m_min) + v4->m_position.m_base;
  }
  else
  {
    if ( v6 != 0.0 )
    {
      v10 = rand();
      v8 = v25;
      v5 = (double)v10 * 0.00003051850947599719 * v6;
    }
    LODWORD(v24) = (signed int)(float)((float)(v5 + v4->m_position.m_mod.m_min) + v4->m_position.m_base);
  }
  v11 = v4->m_bSnapToNearestMarker;
  v16 = 4;
  v22 = v17 == 0i64;
  v25 = (v8 ^ 2 * v11) & 2 ^ v8;
  v12 = CAkBus::GetPrimaryMasterBusAndAddRef();
  v13 = v12;
  if ( v12 )
  {
    v12->vfptr[4].__vecDelDtor((CAkIndexable *)&v12->vfptr, (unsigned int)&v16);
    v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
  }
  v14 = CAkBus::GetSecondaryMasterBusAndAddRef();
  v15 = v14;
  if ( v14 )
  {
    v14->vfptr[4].__vecDelDtor((CAkIndexable *)&v14->vfptr, (unsigned int)&v16);
    v15->vfptr->Release((CAkIndexable *)&v15->vfptr);
  }
}

// File Line: 182
// RVA: 0xA97240
void __fastcall CAkActionSeek::AllExecExcept(CAkActionSeek *this, CAkRegisteredObj *in_pGameObj, unsigned int in_TargetPlayingID)
{
  char v3; // al
  CAkActionSeek *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm6_4
  bool v7; // al
  char v8; // cl
  signed int v9; // eax
  signed int v10; // eax
  bool v11; // al
  CAkBus *v12; // rax
  CAkBus *v13; // rbx
  CAkBus *v14; // rax
  CAkBus *v15; // rbx
  int v16; // [rsp+20h] [rbp-48h]
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v17; // [rsp+28h] [rbp-40h]
  CAkRegisteredObj *v18; // [rsp+30h] [rbp-38h]
  unsigned int v19; // [rsp+38h] [rbp-30h]
  int v20; // [rsp+3Ch] [rbp-2Ch]
  int v21; // [rsp+40h] [rbp-28h]
  __int16 v22; // [rsp+44h] [rbp-24h]
  float v23; // [rsp+48h] [rbp-20h]
  char v24; // [rsp+4Ch] [rbp-1Ch]

  v3 = *((_BYTE *)&this->0 + 54);
  v4 = this;
  v22 = 0;
  v18 = in_pGameObj;
  v5 = 0.0;
  v6 = this->m_position.m_mod.m_max - this->m_position.m_mod.m_min;
  v21 = v3 & 0x1F;
  v7 = this->m_bIsSeekRelativeToDuration;
  v19 = in_TargetPlayingID;
  v20 = 0;
  v8 = (v24 ^ v7) & 1 ^ v24;
  v24 = v8;
  if ( v8 & 1 )
  {
    if ( v6 != 0.0 )
    {
      v9 = rand();
      v8 = v24;
      v5 = (double)v9 * 0.00003051850947599719 * v6;
    }
    v23 = (float)(v5 + v4->m_position.m_mod.m_min) + v4->m_position.m_base;
  }
  else
  {
    if ( v6 != 0.0 )
    {
      v10 = rand();
      v8 = v24;
      v5 = (double)v10 * 0.00003051850947599719 * v6;
    }
    LODWORD(v23) = (signed int)(float)((float)(v5 + v4->m_position.m_mod.m_min) + v4->m_position.m_base);
  }
  v11 = v4->m_bSnapToNearestMarker;
  v16 = 4;
  v17 = &v4->m_listElementException;
  v24 = (v8 ^ 2 * v11) & 2 ^ v8;
  v12 = CAkBus::GetPrimaryMasterBusAndAddRef();
  v13 = v12;
  if ( v12 )
  {
    ((void (__fastcall *)(CAkBus *, int *))v12->vfptr[4].AddRef)(v12, &v16);
    v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
  }
  v14 = CAkBus::GetSecondaryMasterBusAndAddRef();
  v15 = v14;
  if ( v14 )
  {
    ((void (__fastcall *)(CAkBus *, int *))v14->vfptr[4].AddRef)(v14, &v16);
    v15->vfptr->Release((CAkIndexable *)&v15->vfptr);
  }
}

