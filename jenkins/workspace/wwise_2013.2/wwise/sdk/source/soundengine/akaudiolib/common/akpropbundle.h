// File Line: 120
// RVA: 0xA6EE30
signed __int64 __fastcall AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetInitialParams(AkPropBundle<RANGED_MODIFIERS<AkPropValue> > *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char **v3; // rdi
  AkPropBundle<RANGED_MODIFIERS<AkPropValue> > *v4; // r15
  unsigned __int8 v5; // bl
  unsigned int v6; // esi
  char *v7; // rax
  char *v8; // r14
  size_t v10; // rbx

  v3 = io_rpData;
  v4 = this;
  v5 = *(*io_rpData)++;
  if ( v5 )
  {
    v6 = (v5 + 4) & 0xFFFFFFFC;
    v7 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6 + 8 * v5);
    v8 = v7;
    if ( !v7 )
      return 52i64;
    *v7 = v5;
    memmove(v7 + 1, *v3, v5);
    *v3 += v5;
    v10 = 8i64 * v5;
    memmove(&v8[v6], *v3, v10);
    *v3 += v10;
    v4->m_pProps = v8;
  }
  return 1i64;
}

// File Line: 150
// RVA: 0xA6B570
AkPropValue *__fastcall AkPropBundle<AkPropValue>::AddAkProp(AkPropBundle<AkPropValue> *this, char in_ePropID)
{
  char v2; // r15
  AkPropBundle<AkPropValue> *v3; // r14
  __int64 v4; // rdi
  int v5; // ebp
  AkPropValue *result; // rax
  AkPropValue *v7; // rsi

  v2 = in_ePropID;
  v3 = this;
  if ( this->m_pProps )
    v4 = *(unsigned __int8 *)this->m_pProps;
  else
    v4 = 0i64;
  v5 = v4 + 5;
  result = (AkPropValue *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (((_DWORD)v4 + 5) & 0xFFFFFFFC) + 4 + 4 * (_DWORD)v4);
  v7 = result;
  if ( result )
  {
    if ( v3->m_pProps )
    {
      memmove((char *)&result->fValue + 1, v3->m_pProps + 1, (unsigned int)v4);
      memmove((char *)v7 + (v5 & 0xFFFFFFFC), &v3->m_pProps[((_DWORD)v4 + 4) & 0xFFFFFFFC], 4 * v4);
      AK::MemoryMgr::Free(g_DefaultPoolId, v3->m_pProps);
    }
    *((_BYTE *)&v7->fValue + (unsigned int)(v4 + 1)) = v2;
    LOBYTE(v7->fValue) = v4 + 1;
    v3->m_pProps = (char *)v7;
    result = (AkPropValue *)((char *)&v7[v4] + (v5 & 0xFFFFFFFC));
  }
  return result;
}

// File Line: 182
// RVA: 0xA6E740
signed __int64 __fastcall AkPropBundle<AkPropValue>::SetAkProp(AkPropBundle<AkPropValue> *this, char in_ePropID, AkPropValue in_Value)
{
  char *v3; // r11
  unsigned int v4; // ebx
  int v5; // er9
  __int64 v6; // r10
  AkPropValue *v7; // rax
  float v9; // [rsp+40h] [rbp+18h]

  v9 = in_Value.fValue;
  v3 = this->m_pProps;
  if ( this->m_pProps )
  {
    v4 = (unsigned __int8)*v3;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( v3[v6] == in_ePropID )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_7;
    }
    v7 = (AkPropValue *)&v3[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
    if ( v7 )
      goto LABEL_9;
  }
LABEL_7:
  v7 = AkPropBundle<AkPropValue>::AddAkProp(this, in_ePropID);
  if ( v7 )
  {
    in_Value.fValue = v9;
LABEL_9:
    LODWORD(v7->fValue) = in_Value;
    return 1i64;
  }
  return 2i64;
}

