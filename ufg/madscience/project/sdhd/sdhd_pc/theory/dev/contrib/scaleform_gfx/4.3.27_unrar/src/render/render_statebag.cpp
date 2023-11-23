// File Line: 30
// RVA: 0x159CDD0
hkSeekableStreamReader *Scaleform::Render::_dynamic_initializer_for__Render_States_ForceLinkClassInstance__()
{
  return Assembly::GetRCX(&Scaleform::Render::Render_States_ForceLinkClassInstance);
}

// File Line: 55
// RVA: 0x9A75B0
void __fastcall Scaleform::Render::StateData::ArrayData::Release(
        Scaleform::Render::StateData::ArrayData *this,
        unsigned __int64 count)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::StateData::ArrayData *v4; // rbx

  v2 = count;
  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    v4 = this + 1;
    if ( count )
    {
      do
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)&v4->RefCount + 16i64))(
          *(_QWORD *)&v4->RefCount,
          *(_QWORD *)&v4[2].RefCount,
          1i64);
        v4 += 4;
        --v2;
      }
      while ( v2 );
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}

// File Line: 83
// RVA: 0x9DF860
void __fastcall Scaleform::Render::StateData::destroyBag_NotEmpty(Scaleform::Render::StateData *this)
{
  if ( ((__int64)this->pInterface & 1) != 0 )
    (*(void (__fastcall **)(unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)(this->ArraySize & 0xFFFFFFFFFFFFFFFEui64)
                                                                        + 16i64))(
      this->ArraySize & 0xFFFFFFFFFFFFFFFEui64,
      this->DataValue,
      1i64);
  else
    Scaleform::Render::StateData::ArrayData::Release(this->pArray, this->ArraySize >> 1);
  this->DataValue = 0i64;
  this->ArraySize = 0i64;
}

// File Line: 98
// RVA: 0x9CEB40
void __fastcall Scaleform::Render::StateData::assignBag(
        Scaleform::Render::StateData *this,
        Scaleform::Render::StateData *src)
{
  unsigned __int64 ArraySize; // rcx
  unsigned __int64 v5; // rcx

  ArraySize = src->ArraySize;
  if ( src->ArraySize )
  {
    if ( (ArraySize & 1) != 0 )
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)(ArraySize & 0xFFFFFFFFFFFFFFFEui64)
                                                                          + 8i64))(
        ArraySize & 0xFFFFFFFFFFFFFFFEui64,
        src->DataValue,
        1i64);
    else
      _InterlockedExchangeAdd((volatile signed __int32 *)src->pData, 1u);
  }
  v5 = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( (v5 & 1) != 0 )
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)(v5 & 0xFFFFFFFFFFFFFFFEui64)
                                                                          + 16i64))(
        v5 & 0xFFFFFFFFFFFFFFFEui64,
        this->DataValue,
        1i64);
    else
      Scaleform::Render::StateData::ArrayData::Release(this->pArray, v5 >> 1);
    this->ArraySize = 0i64;
    this->DataValue = 0i64;
  }
  this->ArraySize = src->ArraySize;
  this->DataValue = src->DataValue;
}

// File Line: 133
// RVA: 0x9B3CB0
void __fastcall Scaleform::Render::StateBag::SetStateVoid(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::StateData::Interface *pi,
        void *data)
{
  unsigned __int64 ArraySize; // rsi
  __int64 v7; // rax
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // r15
  unsigned __int64 v12; // rsi
  Scaleform::Render::StateData::Interface **v13; // rax
  __int64 v14; // rdi
  _DWORD *v15; // rax
  unsigned __int64 v16; // r13
  unsigned __int64 v17; // r12
  _QWORD *v18; // rdi
  __int64 v19; // r15
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rdi

  ArraySize = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( ((__int64)this->pInterface & 1) != 0 )
    {
      if ( (Scaleform::Render::StateData::Interface *)(ArraySize & 0xFFFFFFFFFFFFFFFEui64) == pi )
      {
        pi->vfptr->AddRef(pi, data, Ref_All);
        pi->vfptr->Release(pi, (void *)this->DataValue, Ref_All);
        this->DataValue = (unsigned __int64)data;
      }
      else
      {
        v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::StateBag *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
               Scaleform::Memory::pGlobalHeap,
               this,
               36i64);
        v8 = v7;
        if ( v7 )
        {
          *(_DWORD *)v7 = 1;
          v9 = this->ArraySize;
          *(_QWORD *)(v7 + 12) = this->pData;
          *(_QWORD *)(v7 + 4) = v9 & 0xFFFFFFFFFFFFFFFEui64;
          *(_QWORD *)(v7 + 20) = pi;
          *(_QWORD *)(v7 + 28) = data;
          pi->vfptr->AddRef(pi, data, Ref_All);
          this->DataValue = v8;
          this->ArraySize = 4i64;
        }
      }
    }
    else
    {
      v10 = 0i64;
      v11 = this->DataValue + 4;
      v12 = ArraySize >> 1;
      if ( v12 )
      {
        v13 = (Scaleform::Render::StateData::Interface **)(this->DataValue + 4);
        while ( *v13 != pi )
        {
          ++v10;
          v13 += 2;
          if ( v10 >= v12 )
            goto LABEL_12;
        }
        pi->vfptr->AddRef(pi, data, Ref_All);
        v22 = 2 * v10;
        pi->vfptr->Release(pi, *(void **)(v11 + 8 * v22 + 8), Ref_All);
        *(_QWORD *)(v11 + 8 * v22 + 8) = data;
      }
      else
      {
LABEL_12:
        v14 = 16 * v12;
        v15 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                Scaleform::Memory::pGlobalHeap,
                this,
                16 * v12 + 20,
                0i64);
        v16 = (unsigned __int64)v15;
        if ( v15 )
        {
          *v15 = 1;
          v17 = v12;
          if ( v12 )
          {
            v18 = (_QWORD *)(v11 + 8);
            v19 = (__int64)v15 - v11 - 4;
            do
            {
              v20 = *(v18 - 1);
              v21 = *v18;
              *(_QWORD *)((char *)v18 + v19) = v20;
              *(_QWORD *)((char *)v18 + v19 + 8) = v21;
              (*(void (__fastcall **)(__int64, _QWORD, __int64))(*(_QWORD *)v20 + 8i64))(v20, *v18, 1i64);
              v18 += 2;
              --v17;
            }
            while ( v17 );
            v14 = 16 * v12;
          }
          *(_QWORD *)(v14 + v16 + 4) = pi;
          *(_QWORD *)(v14 + v16 + 12) = data;
          pi->vfptr->AddRef(pi, data, Ref_All);
          Scaleform::Render::StateData::ArrayData::Release(this->pArray, v12);
          this->ArraySize = 2 * v12 + 2;
          this->DataValue = v16;
        }
      }
    }
  }
  else
  {
    this->DataValue = (unsigned __int64)data;
    this->ArraySize = (unsigned __int64)pi | 1;
    pi->vfptr->AddRef(pi, data, Ref_All);
  }
}

// File Line: 188
// RVA: 0x9AA4D0
bool __fastcall Scaleform::Render::StateBag::RemoveState(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::StateType type)
{
  unsigned __int64 ArraySize; // rbx
  Scaleform::Render::StateData::ArrayData *v4; // rax
  Scaleform::Render::StateData::Interface *v5; // rcx
  unsigned __int64 v6; // rbx
  char *pData; // r14
  Scaleform::Render::StateData::Interface **v8; // rax
  unsigned __int64 i; // r10
  __int64 v10; // r15
  __int64 v11; // r10
  __int64 v12; // rax
  unsigned __int64 v13; // rbp
  unsigned __int64 v14; // r13
  char *v15; // rdi
  signed __int64 v16; // r12
  __int64 v17; // rcx
  __int64 v18; // rax

  ArraySize = this->ArraySize;
  if ( !this->ArraySize )
  {
LABEL_2:
    LOBYTE(v4) = 0;
    return (char)v4;
  }
  v5 = StateType_Interfaces[type];
  if ( (ArraySize & 1) != 0 )
  {
    if ( (Scaleform::Render::StateData::Interface *)(ArraySize & 0xFFFFFFFFFFFFFFFEui64) == v5 )
    {
      v5->vfptr->Release(v5, this->pData, Ref_All);
      LOBYTE(v4) = 1;
      this->ArraySize = 0i64;
      this->DataValue = 0i64;
      return (char)v4;
    }
    goto LABEL_2;
  }
  v6 = ArraySize >> 1;
  pData = (char *)this->pData;
  v8 = (Scaleform::Render::StateData::Interface **)(pData + 4);
  for ( i = 0i64; i < v6; v8 += 2 )
  {
    if ( *v8 == v5 )
      break;
    ++i;
  }
  if ( i != v6 )
  {
    v10 = 2 * i;
    if ( v6 == 2 )
    {
      v11 = 2 * (i ^ 1);
      v12 = *(_QWORD *)&pData[8 * v11 + 4];
      this->DataValue = *(_QWORD *)&pData[8 * v11 + 12];
      this->ArraySize = v12 | 1;
      (*(void (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)&pData[8 * v11 + 4] + 8i64))(
        *(_QWORD *)&pData[8 * v11 + 4],
        *(_QWORD *)&pData[8 * v11 + 12],
        1i64);
    }
    else
    {
      v13 = v6 - i - 1;
      v4 = Scaleform::Render::StateBag::allocData(this, (Scaleform::Render::State *)(pData + 4), i, v13);
      v14 = (unsigned __int64)v4;
      if ( !v4 )
        return (char)v4;
      if ( v13 )
      {
        v15 = &pData[8 * v10 + 28];
        v16 = (char *)v4 - pData;
        do
        {
          v17 = *((_QWORD *)v15 - 1);
          v18 = *(_QWORD *)v15;
          *(_QWORD *)&v15[v16 - 24] = v17;
          *(_QWORD *)&v15[v16 - 16] = v18;
          (*(void (__fastcall **)(__int64, _QWORD, __int64))(*(_QWORD *)v17 + 8i64))(v17, *(_QWORD *)v15, 1i64);
          v15 += 16;
          --v13;
        }
        while ( v13 );
      }
      this->DataValue = v14;
      this->ArraySize = 2 * v6 - 2;
    }
    (*(void (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)&pData[8 * v10 + 4] + 16i64))(
      *(_QWORD *)&pData[8 * v10 + 4],
      *(_QWORD *)&pData[8 * v10 + 12],
      2i64);
    Scaleform::Render::StateData::ArrayData::Release((Scaleform::Render::StateData::ArrayData *)pData, v6);
    LOBYTE(v4) = 1;
    return (char)v4;
  }
  LOBYTE(v4) = 0;
  return (char)v4;
}

// File Line: 259
// RVA: 0x9A8050
void __fastcall Scaleform::Render::StateBag::ReleaseNodes(Scaleform::Render::StateBag *this)
{
  unsigned __int64 ArraySize; // rbx
  _QWORD *v2; // rdi
  unsigned __int64 i; // rbx

  ArraySize = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( (ArraySize & 1) != 0 )
    {
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)(ArraySize & 0xFFFFFFFFFFFFFFFEui64)
                                                                          + 16i64))(
        ArraySize & 0xFFFFFFFFFFFFFFFEui64,
        this->DataValue,
        2i64);
    }
    else
    {
      v2 = (_QWORD *)(this->DataValue + 4);
      for ( i = ArraySize >> 1; i; --i )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64))(*(_QWORD *)*v2 + 16i64))(*v2, v2[1], 2i64);
        v2 += 2;
      }
    }
  }
}

// File Line: 282
// RVA: 0x9CB930
Scaleform::Render::StateData::ArrayData *__fastcall Scaleform::Render::StateBag::allocData(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::State *source,
        unsigned __int64 count,
        unsigned __int64 extra)
{
  unsigned __int64 v4; // rdi
  Scaleform::Render::StateData::ArrayData *result; // rax
  Scaleform::Render::StateData::ArrayData *v7; // r14
  $3DD7D63E6D9E31A762B81B9587FE7A03 *v8; // rbx
  signed __int64 v9; // rsi
  void *pData; // rcx
  unsigned __int64 DataValue; // rax

  v4 = count;
  result = (Scaleform::Render::StateData::ArrayData *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        16 * (extra + count) + 4,
                                                        0i64);
  v7 = result;
  if ( result )
  {
    result->RefCount = 1;
    if ( v4 )
    {
      v8 = &source->8;
      v9 = (char *)result - (char *)source - 4;
      do
      {
        pData = v8[-1].pData;
        DataValue = v8->DataValue;
        *(unsigned __int64 *)((char *)&v8->DataValue + v9) = (unsigned __int64)pData;
        *(unsigned __int64 *)((char *)&v8[1].DataValue + v9) = DataValue;
        (*(void (__fastcall **)(void *, unsigned __int64, __int64))(*(_QWORD *)pData + 8i64))(
          pData,
          v8->DataValue,
          1i64);
        v8 += 2;
        --v4;
      }
      while ( v4 );
    }
    return v7;
  }
  return result;
}

// File Line: 313
// RVA: 0x944880
void __fastcall Scaleform::Render::StateBag::StateBag(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::StateBag *src)
{
  unsigned __int64 ArraySize; // rcx
  char *pData; // rdx

  this->ArraySize = 0i64;
  this->DataValue = 0i64;
  ArraySize = src->ArraySize;
  if ( src->ArraySize )
  {
    pData = (char *)src->pData;
    if ( (ArraySize & 1) != 0 )
    {
      (*(void (__fastcall **)(unsigned __int64, char *, __int64))(*(_QWORD *)(ArraySize & 0xFFFFFFFFFFFFFFFEui64) + 8i64))(
        ArraySize & 0xFFFFFFFFFFFFFFFEui64,
        pData,
        1i64);
      this->ArraySize = src->ArraySize;
      this->DataValue = src->DataValue;
    }
    else
    {
      this->DataValue = (unsigned __int64)Scaleform::Render::StateBag::allocData(
                                            this,
                                            (Scaleform::Render::State *)(pData + 4),
                                            ArraySize >> 1,
                                            0i64);
      this->ArraySize = src->ArraySize;
    }
  }
}

