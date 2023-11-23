// File Line: 120
// RVA: 0xA6EE30
__int64 __fastcall AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetInitialParams(
        AkPropBundle<RANGED_MODIFIERS<AkPropValue> > *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  unsigned __int8 v5; // bl
  unsigned int v6; // esi
  char *v7; // rax
  char *v8; // r14
  size_t v10; // rbx

  v5 = *(*io_rpData)++;
  if ( v5 )
  {
    v6 = (v5 + 4) & 0xFFFFFFFC;
    v7 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6 + 8 * v5);
    v8 = v7;
    if ( !v7 )
      return 52i64;
    *v7 = v5;
    memmove(v7 + 1, *io_rpData, v5);
    *io_rpData += v5;
    v10 = 8i64 * v5;
    memmove(&v8[v6], *io_rpData, v10);
    *io_rpData += v10;
    this->m_pProps = v8;
  }
  return 1i64;
}

// File Line: 150
// RVA: 0xA6B570
AkPropValue *__fastcall AkPropBundle<AkPropValue>::AddAkProp(AkPropBundle<AkPropValue> *this, char in_ePropID)
{
  __int64 v4; // rdi
  int v5; // ebp
  AkPropValue *result; // rax
  char *v7; // rsi

  if ( this->m_pProps )
    v4 = *(unsigned __int8 *)this->m_pProps;
  else
    v4 = 0i64;
  v5 = v4 + 5;
  result = (AkPropValue *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (((_DWORD)v4 + 5) & 0xFFFFFFFC) + 4 + 4 * (_DWORD)v4);
  v7 = (char *)result;
  if ( result )
  {
    if ( this->m_pProps )
    {
      memmove((char *)&result->fValue + 1, this->m_pProps + 1, (unsigned int)v4);
      memmove(&v7[v5 & 0xFFFFFFFC], &this->m_pProps[((_DWORD)v4 + 4) & 0xFFFFFFFC], 4 * v4);
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pProps);
    }
    v7[(unsigned int)(v4 + 1)] = in_ePropID;
    *v7 = v4 + 1;
    this->m_pProps = v7;
    return (AkPropValue *)&v7[4 * v4 + (v5 & 0xFFFFFFFC)];
  }
  return result;
}

// File Line: 182
// RVA: 0xA6E740
__int64 __fastcall AkPropBundle<AkPropValue>::SetAkProp(
        AkPropBundle<AkPropValue> *this,
        char in_ePropID,
        AkPropValue in_Value)
{
  char *m_pProps; // r11
  unsigned int v4; // ebx
  int v5; // r9d
  __int64 v6; // r10
  AkPropValue *v7; // rax
  int iValue; // [rsp+40h] [rbp+18h]

  iValue = in_Value.iValue;
  m_pProps = this->m_pProps;
  if ( this->m_pProps )
  {
    v4 = (unsigned __int8)*m_pProps;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( m_pProps[v6] == in_ePropID )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_7;
    }
    v7 = (AkPropValue *)&m_pProps[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
    if ( v7 )
      goto LABEL_9;
  }
LABEL_7:
  v7 = AkPropBundle<AkPropValue>::AddAkProp(this, in_ePropID);
  if ( v7 )
  {
    LODWORD(in_Value.fValue) = (AkPropValue)iValue;
LABEL_9:
    v7->fValue = in_Value.fValue;
    return 1i64;
  }
  return 2i64;
}

