// File Line: 30
// RVA: 0x159CDD0
hkSeekableStreamReader *Scaleform::Render::_dynamic_initializer_for__Render_States_ForceLinkClassInstance__()
{
  return Assembly::GetRCX(&Scaleform::Render::Render_States_ForceLinkClassInstance);
}

// File Line: 55
// RVA: 0x9A75B0
void __fastcall Scaleform::Render::StateData::ArrayData::Release(Scaleform::Render::StateData::ArrayData *this, unsigned __int64 count)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::StateData::ArrayData *v3; // rsi
  Scaleform::Render::StateData::ArrayData *v4; // rbx

  v2 = count;
  v3 = this;
  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    v4 = this + 1;
    if ( count )
    {
      do
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, signed __int64))(**(_QWORD **)&v4->RefCount + 16i64))(
          *(_QWORD *)&v4->RefCount,
          *(_QWORD *)&v4[2].RefCount,
          1i64);
        v4 += 4;
        --v2;
      }
      while ( v2 );
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
}

// File Line: 83
// RVA: 0x9DF860
void __fastcall Scaleform::Render::StateData::destroyBag_NotEmpty(Scaleform::Render::StateData *this)
{
  Scaleform::Render::StateData *v1; // rbx

  v1 = this;
  if ( (_QWORD)this->pInterface & 1 )
    (*(void (__fastcall **)(unsigned __int64, unsigned __int64, signed __int64))(*(_QWORD *)(this->ArraySize & 0xFFFFFFFFFFFFFFFEui64)
                                                                               + 16i64))(
      this->ArraySize & 0xFFFFFFFFFFFFFFFEui64,
      this->DataValue,
      1i64);
  else
    Scaleform::Render::StateData::ArrayData::Release(this->pArray, this->ArraySize >> 1);
  v1->DataValue = 0i64;
  v1->ArraySize = 0i64;
}

// File Line: 98
// RVA: 0x9CEB40
void __fastcall Scaleform::Render::StateData::assignBag(Scaleform::Render::StateData *this, Scaleform::Render::StateData *src)
{
  Scaleform::Render::StateData *v2; // rbx
  unsigned __int64 v3; // rcx
  Scaleform::Render::StateData *v4; // rdi
  unsigned __int64 v5; // rcx

  v2 = this;
  v3 = src->ArraySize;
  v4 = src;
  if ( src->ArraySize )
  {
    if ( v3 & 1 )
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, signed __int64))(*(_QWORD *)(v3 & 0xFFFFFFFFFFFFFFFEui64)
                                                                                 + 8i64))(
        v3 & 0xFFFFFFFFFFFFFFFEui64,
        src->DataValue,
        1i64);
    else
      _InterlockedExchangeAdd((volatile signed __int32 *)src->pData, 1u);
  }
  v5 = v2->ArraySize;
  if ( v2->ArraySize )
  {
    if ( v5 & 1 )
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, signed __int64))(*(_QWORD *)(v5 & 0xFFFFFFFFFFFFFFFEui64)
                                                                                 + 16i64))(
        v5 & 0xFFFFFFFFFFFFFFFEui64,
        v2->DataValue,
        1i64);
    else
      Scaleform::Render::StateData::ArrayData::Release(v2->pArray, v5 >> 1);
    v2->ArraySize = 0i64;
    v2->DataValue = 0i64;
  }
  v2->ArraySize = v4->ArraySize;
  v2->DataValue = v4->DataValue;
}

// File Line: 133
// RVA: 0x9B3CB0
void __fastcall Scaleform::Render::StateBag::SetStateVoid(Scaleform::Render::StateBag *this, Scaleform::Render::StateData::Interface *pi, void *data)
{
  unsigned __int64 v3; // rsi
  void *v4; // rbp
  Scaleform::Render::StateData::Interface *v5; // rbx
  Scaleform::Render::StateBag *v6; // r14
  __int64 v7; // rax
  __int64 v8; // rdi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // r15
  unsigned __int64 v12; // rsi
  Scaleform::Render::StateData::Interface **v13; // rax
  signed __int64 v14; // rdi
  _DWORD *v15; // rax
  _DWORD *v16; // r13
  unsigned __int64 v17; // r12
  __int64 *v18; // rdi
  signed __int64 v19; // r15
  __int64 v20; // rcx
  __int64 v21; // rax
  signed __int64 v22; // rdi

  v3 = this->ArraySize;
  v4 = data;
  v5 = pi;
  v6 = this;
  if ( this->ArraySize )
  {
    if ( (_QWORD)this->pInterface & 1 )
    {
      if ( (Scaleform::Render::StateData::Interface *)(v3 & 0xFFFFFFFFFFFFFFFEui64) == pi )
      {
        pi->vfptr->AddRef(pi, data, 0i64);
        v5->vfptr->Release(v5, v6->pData, 0i64);
        v6->DataValue = (unsigned __int64)v4;
      }
      else
      {
        v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::StateBag *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
               Scaleform::Memory::pGlobalHeap,
               this,
               36i64);
        v8 = v7;
        if ( v7 )
        {
          *(_DWORD *)v7 = 1;
          v9 = v6->ArraySize;
          *(_QWORD *)(v7 + 12) = v6->pData;
          *(_QWORD *)(v7 + 4) = v9 & 0xFFFFFFFFFFFFFFFEui64;
          *(_QWORD *)(v7 + 20) = v5;
          *(_QWORD *)(v7 + 28) = v4;
          v5->vfptr->AddRef(v5, v4, 0i64);
          v6->DataValue = v8;
          v6->ArraySize = 4i64;
        }
      }
    }
    else
    {
      v10 = 0i64;
      v11 = this->DataValue + 4;
      v12 = v3 >> 1;
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
        pi->vfptr->AddRef(pi, data, 0i64);
        v22 = 2 * v10;
        v5->vfptr->Release(v5, *(void **)(v11 + 8 * v22 + 8), 0i64);
        *(_QWORD *)(v11 + 8 * v22 + 8) = v4;
      }
      else
      {
LABEL_12:
        v14 = 4 * v12;
        v15 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                          Scaleform::Memory::pGlobalHeap,
                          this,
                          16 * v12 + 20,
                          0i64);
        v16 = v15;
        if ( v15 )
        {
          *v15 = 1;
          v17 = v12;
          if ( v12 )
          {
            v18 = (__int64 *)(v11 + 8);
            v19 = (signed __int64)((char *)v15 - v11 - 4);
            do
            {
              v20 = *(v18 - 1);
              v21 = *v18;
              *(__int64 *)((char *)v18 + v19) = v20;
              *(__int64 *)((char *)v18 + v19 + 8) = v21;
              (*(void (__fastcall **)(__int64, __int64, signed __int64))(*(_QWORD *)v20 + 8i64))(v20, *v18, 1i64);
              v18 += 2;
              --v17;
            }
            while ( v17 );
            v14 = 4 * v12;
          }
          *(_QWORD *)&v16[v14 + 1] = v5;
          *(_QWORD *)&v16[v14 + 3] = v4;
          v5->vfptr->AddRef(v5, v4, 0i64);
          Scaleform::Render::StateData::ArrayData::Release(v6->pArray, v12);
          v6->ArraySize = 2 * v12 + 2;
          v6->DataValue = (unsigned __int64)v16;
        }
      }
    }
  }
  else
  {
    this->DataValue = (unsigned __int64)data;
    this->ArraySize = (unsigned __int64)pi | 1;
    pi->vfptr->AddRef(pi, data, 0i64);
  }
}

// File Line: 188
// RVA: 0x9AA4D0
bool __fastcall Scaleform::Render::StateBag::RemoveState(Scaleform::Render::StateBag *this, Scaleform::Render::StateType type)
{
  unsigned __int64 v2; // rbx
  Scaleform::Render::StateBag *v3; // rsi
  Scaleform::Render::StateData::ArrayData *v4; // rax
  Scaleform::Render::StateData::Interface *v5; // rcx
  unsigned __int64 v6; // rbx
  char *v7; // r14
  Scaleform::Render::StateData::Interface **v8; // rax
  unsigned __int64 v9; // r10
  signed __int64 v10; // r15
  signed __int64 v11; // r10
  __int64 v12; // rax
  unsigned __int64 v13; // rbp
  Scaleform::Render::StateData::ArrayData *v14; // r13
  char *v15; // rdi
  char *v16; // r12
  __int64 v17; // rcx
  __int64 v18; // rax

  v2 = this->ArraySize;
  v3 = this;
  if ( !this->ArraySize )
  {
LABEL_2:
    LOBYTE(v4) = 0;
    return (char)v4;
  }
  v5 = StateType_Interfaces[type];
  if ( v2 & 1 )
  {
    if ( (Scaleform::Render::StateData::Interface *)(v2 & 0xFFFFFFFFFFFFFFFEui64) == v5 )
    {
      v5->vfptr->Release(v5, v3->pData, 0i64);
      LOBYTE(v4) = 1;
      v3->ArraySize = 0i64;
      v3->DataValue = 0i64;
      return (char)v4;
    }
    goto LABEL_2;
  }
  v6 = v2 >> 1;
  v7 = (char *)v3->pData;
  v8 = (Scaleform::Render::StateData::Interface **)(v7 + 4);
  v9 = 0i64;
  if ( v6 )
  {
    do
    {
      if ( *v8 == v5 )
        break;
      ++v9;
      v8 += 2;
    }
    while ( v9 < v6 );
  }
  if ( v9 != v6 )
  {
    v10 = 2 * v9;
    if ( v6 == 2 )
    {
      v11 = 2 * (v9 ^ 1);
      v12 = *(_QWORD *)&v7[8 * v11 + 4];
      v3->DataValue = *(_QWORD *)&v7[8 * v11 + 12];
      v3->ArraySize = v12 | 1;
      (*(void (__fastcall **)(_QWORD, _QWORD, signed __int64))(**(_QWORD **)&v7[8 * v11 + 4] + 8i64))(
        *(_QWORD *)&v7[8 * v11 + 4],
        *(_QWORD *)&v7[8 * v11 + 12],
        1i64);
    }
    else
    {
      v13 = v6 - v9 - 1;
      v4 = Scaleform::Render::StateBag::allocData(v3, (Scaleform::Render::State *)(v7 + 4), v9, v13);
      v14 = v4;
      if ( !v4 )
        return (char)v4;
      if ( v13 )
      {
        v15 = &v7[8 * v10 + 28];
        v16 = (char *)((char *)v4 - v7);
        do
        {
          v17 = *((_QWORD *)v15 - 1);
          v18 = *(_QWORD *)v15;
          *(_QWORD *)&v15[(_QWORD)v16 - 24] = v17;
          *(_QWORD *)&v15[(_QWORD)v16 - 16] = v18;
          (*(void (__fastcall **)(__int64, __int64, signed __int64))(*(_QWORD *)v17 + 8i64))(v17, *(_QWORD *)v15, 1i64);
          v15 += 16;
          --v13;
        }
        while ( v13 );
      }
      v3->DataValue = (unsigned __int64)v14;
      v3->ArraySize = 2 * v6 - 2;
    }
    (*(void (__fastcall **)(_QWORD, _QWORD, signed __int64))(**(_QWORD **)&v7[8 * v10 + 4] + 16i64))(
      *(_QWORD *)&v7[8 * v10 + 4],
      *(_QWORD *)&v7[8 * v10 + 12],
      2i64);
    Scaleform::Render::StateData::ArrayData::Release((Scaleform::Render::StateData::ArrayData *)v7, v6);
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
  unsigned __int64 v1; // rbx
  _QWORD *v2; // rdi
  unsigned __int64 i; // rbx

  v1 = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( v1 & 1 )
    {
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, signed __int64))(*(_QWORD *)(v1 & 0xFFFFFFFFFFFFFFFEui64)
                                                                                 + 16i64))(
        v1 & 0xFFFFFFFFFFFFFFFEui64,
        this->DataValue,
        2i64);
    }
    else
    {
      v2 = (_QWORD *)(this->DataValue + 4);
      for ( i = v1 >> 1; i; --i )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, signed __int64))(*(_QWORD *)*v2 + 16i64))(*v2, v2[1], 2i64);
        v2 += 2;
      }
    }
  }
}

// File Line: 282
// RVA: 0x9CB930
Scaleform::Render::StateData::ArrayData *__fastcall Scaleform::Render::StateBag::allocData(Scaleform::Render::StateBag *this, Scaleform::Render::State *source, unsigned __int64 count, unsigned __int64 extra)
{
  unsigned __int64 v4; // rdi
  Scaleform::Render::State *v5; // rsi
  Scaleform::Render::StateData::ArrayData *result; // rax
  Scaleform::Render::StateData::ArrayData *v7; // r14
  unsigned __int64 *v8; // rbx
  char *v9; // rsi
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax

  v4 = count;
  v5 = source;
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
      v8 = (unsigned __int64 *)&v5->8;
      v9 = (char *)((char *)result - (char *)v5 - 4);
      do
      {
        v10 = *(v8 - 1);
        v11 = *v8;
        *(unsigned __int64 *)((char *)v8 + (_QWORD)v9) = v10;
        *(unsigned __int64 *)((char *)v8 + (_QWORD)v9 + 8) = v11;
        (*(void (__fastcall **)(unsigned __int64, unsigned __int64, signed __int64))(*(_QWORD *)v10 + 8i64))(
          v10,
          *v8,
          1i64);
        v8 += 2;
        --v4;
      }
      while ( v4 );
    }
    result = v7;
  }
  return result;
}

// File Line: 313
// RVA: 0x944880
void __fastcall Scaleform::Render::StateBag::StateBag(Scaleform::Render::StateBag *this, Scaleform::Render::StateBag *src)
{
  Scaleform::Render::StateBag *v2; // rbx
  Scaleform::Render::StateBag *v3; // rdi
  unsigned __int64 v4; // rcx
  char *v5; // rdx

  v2 = this;
  v3 = src;
  this->ArraySize = 0i64;
  this->DataValue = 0i64;
  v4 = src->ArraySize;
  if ( src->ArraySize )
  {
    v5 = (char *)src->pData;
    if ( v4 & 1 )
    {
      (*(void (__fastcall **)(unsigned __int64, char *, signed __int64))(*(_QWORD *)(v4 & 0xFFFFFFFFFFFFFFFEui64) + 8i64))(
        v4 & 0xFFFFFFFFFFFFFFFEui64,
        v5,
        1i64);
      v2->ArraySize = v3->ArraySize;
      v2->DataValue = v3->DataValue;
    }
    else
    {
      v2->DataValue = (unsigned __int64)Scaleform::Render::StateBag::allocData(
                                          v2,
                                          (Scaleform::Render::State *)(v5 + 4),
                                          v4 >> 1,
                                          0i64);
      v2->ArraySize = v3->ArraySize;
    }
  }
}

