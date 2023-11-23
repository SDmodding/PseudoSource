// File Line: 323
// RVA: 0x9C30C0
void __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float v)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  char *v6; // rcx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v7; // rbx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  char *v10; // rcx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // rbx
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // r8
  char *v14; // rcx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v15; // rbx
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  char *v18; // rcx

  Data = this->Data;
  v4 = this->Data->Data.Size + 1;
  if ( v4 >= this->Data->Data.Size )
  {
    if ( v4 <= Data->Data.Policy.Capacity )
      goto LABEL_7;
    v5 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v5 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v5);
LABEL_7:
  v6 = Data->Data.Data;
  Data->Data.Size = v4;
  v6[v4 - 1] = LOBYTE(v);
  v7 = this->Data;
  v8 = this->Data->Data.Size + 1;
  if ( v8 >= this->Data->Data.Size )
  {
    if ( v8 <= v7->Data.Policy.Capacity )
      goto LABEL_13;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= v7->Data.Policy.Capacity >> 1 )
      goto LABEL_13;
    v9 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v9);
LABEL_13:
  v10 = v7->Data.Data;
  v7->Data.Size = v8;
  v10[v8 - 1] = BYTE1(v);
  v11 = this->Data;
  v12 = this->Data->Data.Size + 1;
  if ( v12 >= this->Data->Data.Size )
  {
    if ( v12 <= v11->Data.Policy.Capacity )
      goto LABEL_19;
    v13 = v12 + (v12 >> 2);
  }
  else
  {
    if ( v12 >= v11->Data.Policy.Capacity >> 1 )
      goto LABEL_19;
    v13 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v13);
LABEL_19:
  v14 = v11->Data.Data;
  v11->Data.Size = v12;
  v14[v12 - 1] = BYTE2(v);
  v15 = this->Data;
  v16 = this->Data->Data.Size + 1;
  if ( v16 >= this->Data->Data.Size )
  {
    if ( v16 > v15->Data.Policy.Capacity )
    {
      v17 = v16 + (v16 >> 2);
      goto LABEL_24;
    }
  }
  else if ( v16 < v15->Data.Policy.Capacity >> 1 )
  {
    v17 = this->Data->Data.Size + 1;
LABEL_24:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
      this->Data,
      v17);
  }
  v18 = v15->Data.Data;
  v15->Data.Size = v16;
  v18[v16 - 1] = HIBYTE(v);
}

// File Line: 381
// RVA: 0x91C420
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rdi
  unsigned __int64 v5; // rbx
  char v6; // si
  unsigned __int64 v7; // r8
  char *v8; // rcx
  char *v9; // rcx
  char v11; // bp
  unsigned __int64 v12; // r8
  char *v13; // rcx
  char *v14; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v15; // rdi
  unsigned int v16; // esi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8
  char *v19; // rcx
  char *v20; // rcx

  Data = this->Data;
  v5 = this->Data->Data.Size + 1;
  if ( v <= 0x7F )
  {
    v6 = 2 * v;
    if ( v5 >= Data->Data.Size )
    {
      if ( v5 > Data->Data.Policy.Capacity )
      {
        v7 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < Data->Data.Policy.Capacity >> 1 )
    {
      v7 = this->Data->Data.Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)Data->Data.pHeap,
        v7);
    }
    v8 = Data->Data.Data;
    Data->Data.Size = v5;
    v9 = &v8[v5 - 1];
    if ( v9 )
      *v9 = v6;
    return 1i64;
  }
  v11 = (2 * v) | 1;
  if ( v5 >= Data->Data.Size )
  {
    if ( v5 <= Data->Data.Policy.Capacity )
      goto LABEL_17;
    v12 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_17;
    v12 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &Data->Data,
    (__int64 *)Data->Data.pHeap,
    v12);
LABEL_17:
  v13 = Data->Data.Data;
  Data->Data.Size = v5;
  v14 = &v13[v5 - 1];
  if ( v14 )
    *v14 = v11;
  v15 = this->Data;
  v16 = v >> 7;
  v17 = this->Data->Data.Size + 1;
  if ( v17 >= this->Data->Data.Size )
  {
    if ( v17 > v15->Data.Policy.Capacity )
    {
      v18 = v17 + (v17 >> 2);
      goto LABEL_24;
    }
  }
  else if ( v17 < v15->Data.Policy.Capacity >> 1 )
  {
    v18 = this->Data->Data.Size + 1;
LABEL_24:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v15->Data,
      (__int64 *)this->Data->Data.pHeap,
      v18);
  }
  v19 = v15->Data.Data;
  v15->Data.Size = v17;
  v20 = &v19[v17 - 1];
  if ( v20 )
    *v20 = v16;
  return 2i64;
}

// File Line: 409
// RVA: 0x9C5030
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // rdi
  unsigned __int64 v5; // rsi
  char v6; // bl
  unsigned __int64 v7; // r8
  bool *v8; // rax
  char v10; // bp
  char v11; // bp
  unsigned __int64 v12; // r8
  bool *v13; // rax
  unsigned int v14; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v15; // rdi
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  bool *v18; // rax
  char v19; // bp
  unsigned __int64 v20; // r8
  bool *v21; // rax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v22; // rdi
  unsigned int v23; // ebp
  unsigned __int64 v24; // rsi
  unsigned __int64 v25; // r8
  bool *v26; // rax
  unsigned int v27; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v28; // rdi
  unsigned __int64 v29; // rsi
  unsigned __int64 v30; // r8
  bool *v31; // rax
  char v32; // bp
  unsigned __int64 v33; // r8
  bool *v34; // rax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v35; // rdi
  unsigned __int64 v36; // rsi
  unsigned __int64 v37; // r8
  bool *v38; // rax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v39; // rdi
  unsigned int v40; // ebp
  unsigned __int64 v41; // rsi
  unsigned __int64 v42; // r8
  bool *v43; // rax
  unsigned int v44; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v45; // rdi
  unsigned __int64 v46; // rsi
  unsigned __int64 v47; // r8
  bool *v48; // rax

  Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v5 = this->Data->Data.Size + 1;
  if ( v <= 0x3F )
  {
    v6 = 4 * v;
    if ( v5 >= Data->Size )
    {
      if ( v5 > Data->Policy.Capacity )
      {
        v7 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < Data->Policy.Capacity >> 1 )
    {
      v7 = this->Data->Data.Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v7);
    }
    v8 = Data->Data;
    Data->Size = v5;
    v8[v5 - 1] = v6;
    return 1i64;
  }
  v10 = 4 * v;
  if ( v <= 0x3FFF )
  {
    v11 = v10 | 1;
    if ( v5 >= Data->Size )
    {
      if ( v5 <= Data->Policy.Capacity )
        goto LABEL_16;
      v12 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= Data->Policy.Capacity >> 1 )
        goto LABEL_16;
      v12 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      v12);
LABEL_16:
    v13 = Data->Data;
    Data->Size = v5;
    v14 = v >> 6;
    v13[v5 - 1] = v11;
    v15 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
    v16 = this->Data->Data.Size + 1;
    if ( v16 >= this->Data->Data.Size )
    {
      if ( v16 > v15->Policy.Capacity )
      {
        v17 = v16 + (v16 >> 2);
        goto LABEL_21;
      }
    }
    else if ( v16 < v15->Policy.Capacity >> 1 )
    {
      v17 = this->Data->Data.Size + 1;
LABEL_21:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v15,
        v15,
        v17);
    }
    v18 = v15->Data;
    v15->Size = v16;
    v18[v16 - 1] = v14;
    return 2i64;
  }
  if ( v <= 0x3FFFFF )
  {
    v19 = v10 | 2;
    if ( v5 >= Data->Size )
    {
      if ( v5 <= Data->Policy.Capacity )
        goto LABEL_30;
      v20 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= Data->Policy.Capacity >> 1 )
        goto LABEL_30;
      v20 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      v20);
LABEL_30:
    v21 = Data->Data;
    Data->Size = v5;
    v21[v5 - 1] = v19;
    v22 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
    v23 = v >> 6;
    v24 = this->Data->Data.Size + 1;
    if ( v24 >= this->Data->Data.Size )
    {
      if ( v24 <= v22->Policy.Capacity )
        goto LABEL_36;
      v25 = v24 + (v24 >> 2);
    }
    else
    {
      if ( v24 >= v22->Policy.Capacity >> 1 )
        goto LABEL_36;
      v25 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v22, v22, v25);
LABEL_36:
    v26 = v22->Data;
    v22->Size = v24;
    v27 = v >> 14;
    v26[v24 - 1] = v23;
    v28 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
    v29 = this->Data->Data.Size + 1;
    if ( v29 >= this->Data->Data.Size )
    {
      if ( v29 > v28->Policy.Capacity )
      {
        v30 = v29 + (v29 >> 2);
        goto LABEL_41;
      }
    }
    else if ( v29 < v28->Policy.Capacity >> 1 )
    {
      v30 = this->Data->Data.Size + 1;
LABEL_41:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v28,
        v28,
        v30);
    }
    v31 = v28->Data;
    v28->Size = v29;
    v31[v29 - 1] = v27;
    return 3i64;
  }
  v32 = v10 | 3;
  if ( v5 >= Data->Size )
  {
    if ( v5 <= Data->Policy.Capacity )
      goto LABEL_49;
    v33 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Data->Policy.Capacity >> 1 )
      goto LABEL_49;
    v33 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(Data, Data, v33);
LABEL_49:
  v34 = Data->Data;
  Data->Size = v5;
  v34[v5 - 1] = v32;
  v35 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v36 = this->Data->Data.Size + 1;
  if ( v36 >= this->Data->Data.Size )
  {
    if ( v36 <= v35->Policy.Capacity )
      goto LABEL_55;
    v37 = v36 + (v36 >> 2);
  }
  else
  {
    if ( v36 >= v35->Policy.Capacity >> 1 )
      goto LABEL_55;
    v37 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v35, v35, v37);
LABEL_55:
  v38 = v35->Data;
  v35->Size = v36;
  v38[v36 - 1] = v >> 6;
  v39 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v40 = v >> 14;
  v41 = this->Data->Data.Size + 1;
  if ( v41 >= this->Data->Data.Size )
  {
    if ( v41 <= v39->Policy.Capacity )
      goto LABEL_61;
    v42 = v41 + (v41 >> 2);
  }
  else
  {
    if ( v41 >= v39->Policy.Capacity >> 1 )
      goto LABEL_61;
    v42 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v39, v39, v42);
LABEL_61:
  v43 = v39->Data;
  v39->Size = v41;
  v44 = v >> 22;
  v43[v41 - 1] = v40;
  v45 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v46 = this->Data->Data.Size + 1;
  if ( v46 >= this->Data->Data.Size )
  {
    if ( v46 > v45->Policy.Capacity )
    {
      v47 = v46 + (v46 >> 2);
      goto LABEL_66;
    }
  }
  else if ( v46 < v45->Policy.Capacity >> 1 )
  {
    v47 = this->Data->Data.Size + 1;
LABEL_66:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v45, v45, v47);
  }
  v48 = v45->Data;
  v45->Size = v46;
  v48[v46 - 1] = v44;
  return 4i64;
}y >> 1 )
  {
    v47 = this->Data->Data.Size + 1;
LABEL_66:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v45, v45, v47);
  }
  v48 = v45->Data;
  v45-

// File Line: 439
// RVA: 0x91C070
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int v)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rsi
  unsigned __int64 v5; // rdi
  char v6; // bl
  unsigned __int64 v7; // r8
  char *v8; // rcx
  char *v9; // rcx
  char v11; // bp
  char v12; // bp
  unsigned __int64 v13; // r8
  char *v14; // rcx
  char *v15; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v16; // rsi
  int v17; // ebx
  unsigned __int64 v18; // rdi
  unsigned __int64 v19; // r8
  char *v20; // rcx
  char *v21; // rcx
  unsigned int v22; // eax
  __int64 *pHeap; // rdx
  char v24; // bp
  unsigned __int64 v25; // r8
  char *v26; // rcx
  char *v27; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v28; // rsi
  unsigned __int64 v29; // rdi
  unsigned __int64 v30; // r8
  char *v31; // rcx
  char *v32; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v33; // rsi
  int v34; // ebx
  unsigned __int64 v35; // rdi
  unsigned __int64 v36; // r8
  char *v37; // rcx
  char *v38; // rcx
  char v39; // bp
  unsigned __int64 v40; // r8
  char *v41; // rcx
  char *v42; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v43; // rsi
  unsigned __int64 v44; // rdi
  unsigned __int64 v45; // r8
  char *v46; // rcx
  char *v47; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v48; // rsi
  unsigned __int64 v49; // rdi
  unsigned __int64 v50; // r8
  char *v51; // rcx
  char *v52; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v53; // rsi
  int v54; // ebx
  unsigned __int64 v55; // rdi
  unsigned __int64 v56; // r8
  char *v57; // rcx
  char *v58; // rcx

  Data = this->Data;
  v5 = this->Data->Data.Size + 1;
  if ( (unsigned int)(v + 32) <= 0x3F )
  {
    v6 = 4 * v;
    if ( v5 >= Data->Data.Size )
    {
      if ( v5 > Data->Data.Policy.Capacity )
      {
        v7 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < Data->Data.Policy.Capacity >> 1 )
    {
      v7 = this->Data->Data.Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)Data->Data.pHeap,
        v7);
    }
    v8 = Data->Data.Data;
    Data->Data.Size = v5;
    v9 = &v8[v5 - 1];
    if ( v9 )
      *v9 = v6;
    return 1i64;
  }
  v11 = 4 * v;
  if ( (unsigned int)(v + 0x2000) <= 0x3FFF )
  {
    v12 = v11 | 1;
    if ( v5 >= Data->Data.Size )
    {
      if ( v5 <= Data->Data.Policy.Capacity )
        goto LABEL_18;
      v13 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= Data->Data.Policy.Capacity >> 1 )
        goto LABEL_18;
      v13 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &Data->Data,
      (__int64 *)Data->Data.pHeap,
      v13);
LABEL_18:
    v14 = Data->Data.Data;
    Data->Data.Size = v5;
    v15 = &v14[v5 - 1];
    if ( v15 )
      *v15 = v12;
    v16 = this->Data;
    v17 = v >> 6;
    v18 = this->Data->Data.Size + 1;
    if ( v18 >= this->Data->Data.Size )
    {
      if ( v18 > v16->Data.Policy.Capacity )
      {
        v19 = v18 + (v18 >> 2);
        goto LABEL_25;
      }
    }
    else if ( v18 < v16->Data.Policy.Capacity >> 1 )
    {
      v19 = this->Data->Data.Size + 1;
LABEL_25:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v19);
    }
    v20 = v16->Data.Data;
    v16->Data.Size = v18;
    v21 = &v20[v18 - 1];
    if ( v21 )
      *v21 = v17;
    return 2i64;
  }
  v22 = v + 0x200000;
  pHeap = (__int64 *)Data->Data.pHeap;
  if ( v22 <= 0x3FFFFF )
  {
    v24 = v11 | 2;
    if ( v5 >= Data->Data.Size )
    {
      if ( v5 <= Data->Data.Policy.Capacity )
        goto LABEL_36;
      v25 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= Data->Data.Policy.Capacity >> 1 )
        goto LABEL_36;
      v25 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &Data->Data,
      pHeap,
      v25);
LABEL_36:
    v26 = Data->Data.Data;
    Data->Data.Size = v5;
    v27 = &v26[v5 - 1];
    if ( v27 )
      *v27 = v24;
    v28 = this->Data;
    v29 = this->Data->Data.Size + 1;
    if ( v29 >= this->Data->Data.Size )
    {
      if ( v29 <= v28->Data.Policy.Capacity )
        goto LABEL_44;
      v30 = v29 + (v29 >> 2);
    }
    else
    {
      if ( v29 >= v28->Data.Policy.Capacity >> 1 )
        goto LABEL_44;
      v30 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v30);
LABEL_44:
    v31 = v28->Data.Data;
    v28->Data.Size = v29;
    v32 = &v31[v29 - 1];
    if ( v32 )
      *v32 = v >> 6;
    v33 = this->Data;
    v34 = v >> 14;
    v35 = this->Data->Data.Size + 1;
    if ( v35 >= this->Data->Data.Size )
    {
      if ( v35 > v33->Data.Policy.Capacity )
      {
        v36 = v35 + (v35 >> 2);
        goto LABEL_51;
      }
    }
    else if ( v35 < v33->Data.Policy.Capacity >> 1 )
    {
      v36 = this->Data->Data.Size + 1;
LABEL_51:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v36);
    }
    v37 = v33->Data.Data;
    v33->Data.Size = v35;
    v38 = &v37[v35 - 1];
    if ( v38 )
      *v38 = v34;
    return 3i64;
  }
  v39 = v11 | 3;
  if ( v5 >= Data->Data.Size )
  {
    if ( v5 <= Data->Data.Policy.Capacity )
      goto LABEL_61;
    v40 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_61;
    v40 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &Data->Data,
    pHeap,
    v40);
LABEL_61:
  v41 = Data->Data.Data;
  Data->Data.Size = v5;
  v42 = &v41[v5 - 1];
  if ( v42 )
    *v42 = v39;
  v43 = this->Data;
  v44 = this->Data->Data.Size + 1;
  if ( v44 >= this->Data->Data.Size )
  {
    if ( v44 <= v43->Data.Policy.Capacity )
      goto LABEL_69;
    v45 = v44 + (v44 >> 2);
  }
  else
  {
    if ( v44 >= v43->Data.Policy.Capacity >> 1 )
      goto LABEL_69;
    v45 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v45);
LABEL_69:
  v46 = v43->Data.Data;
  v43->Data.Size = v44;
  v47 = &v46[v44 - 1];
  if ( v47 )
    *v47 = v >> 6;
  v48 = this->Data;
  v49 = this->Data->Data.Size + 1;
  if ( v49 >= this->Data->Data.Size )
  {
    if ( v49 <= v48->Data.Policy.Capacity )
      goto LABEL_77;
    v50 = v49 + (v49 >> 2);
  }
  else
  {
    if ( v49 >= v48->Data.Policy.Capacity >> 1 )
      goto LABEL_77;
    v50 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v50);
LABEL_77:
  v51 = v48->Data.Data;
  v48->Data.Size = v49;
  v52 = &v51[v49 - 1];
  if ( v52 )
    *v52 = v >> 14;
  v53 = this->Data;
  v54 = v >> 22;
  v55 = this->Data->Data.Size + 1;
  if ( v55 >= this->Data->Data.Size )
  {
    if ( v55 > v53->Data.Policy.Capacity )
    {
      v56 = v55 + (v55 >> 2);
      goto LABEL_84;
    }
  }
  else if ( v55 < v53->Data.Policy.Capacity >> 1 )
  {
    v56 = this->Data->Data.Size + 1;
LABEL_84:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v56);
  }
  v57 = v53->Data.Data;
  v53->Data.Size = v55;
  v58 = &v57[v55 - 1];
  if ( v58 )
    *v58 = v54;
  return 4i64;
}

// File Line: 468
// RVA: 0x9C3220
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int x)
{
  char v3; // bp
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rdi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  char *v8; // rax
  int v9; // esi
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // rbx
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  char *v13; // rax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v15; // rbx
  char v16; // bp
  unsigned __int64 v17; // rdi
  unsigned __int64 v18; // r8
  char *v19; // rax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v20; // rbx
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // r8
  char *v23; // rax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v24; // rbx
  int v25; // ebp
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // r8
  char *v28; // rax
  int v29; // esi
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v30; // rbx
  unsigned __int64 v31; // rdi
  unsigned __int64 v32; // r8
  char *v33; // rax

  v3 = 16 * x;
  if ( (unsigned int)(x + 2048) <= 0xFFF )
  {
    Data = this->Data;
    v6 = this->Data->Data.Size + 1;
    if ( v6 >= this->Data->Data.Size )
    {
      if ( v6 <= Data->Data.Policy.Capacity )
        goto LABEL_8;
      v7 = v6 + (v6 >> 2);
    }
    else
    {
      if ( v6 >= Data->Data.Policy.Capacity >> 1 )
        goto LABEL_8;
      v7 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
      this->Data,
      v7);
LABEL_8:
    v8 = Data->Data.Data;
    Data->Data.Size = v6;
    v9 = x >> 4;
    v8[v6 - 1] = v3;
    v10 = this->Data;
    v11 = this->Data->Data.Size + 1;
    if ( v11 >= this->Data->Data.Size )
    {
      if ( v11 > v10->Data.Policy.Capacity )
      {
        v12 = v11 + (v11 >> 2);
        goto LABEL_13;
      }
    }
    else if ( v11 < v10->Data.Policy.Capacity >> 1 )
    {
      v12 = this->Data->Data.Size + 1;
LABEL_13:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
        this->Data,
        v12);
    }
    v13 = v10->Data.Data;
    v10->Data.Size = v11;
    v13[v11 - 1] = v9;
    return 2i64;
  }
  v15 = this->Data;
  v16 = v3 | 1;
  v17 = this->Data->Data.Size + 1;
  if ( v17 >= this->Data->Data.Size )
  {
    if ( v17 <= v15->Data.Policy.Capacity )
      goto LABEL_21;
    v18 = v17 + (v17 >> 2);
  }
  else
  {
    if ( v17 >= v15->Data.Policy.Capacity >> 1 )
      goto LABEL_21;
    v18 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v18);
LABEL_21:
  v19 = v15->Data.Data;
  v15->Data.Size = v17;
  v19[v17 - 1] = v16;
  v20 = this->Data;
  v21 = this->Data->Data.Size + 1;
  if ( v21 >= this->Data->Data.Size )
  {
    if ( v21 <= v20->Data.Policy.Capacity )
      goto LABEL_27;
    v22 = v21 + (v21 >> 2);
  }
  else
  {
    if ( v21 >= v20->Data.Policy.Capacity >> 1 )
      goto LABEL_27;
    v22 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v22);
LABEL_27:
  v23 = v20->Data.Data;
  v20->Data.Size = v21;
  v23[v21 - 1] = x >> 4;
  v24 = this->Data;
  v25 = x >> 12;
  v26 = this->Data->Data.Size + 1;
  if ( v26 >= this->Data->Data.Size )
  {
    if ( v26 <= v24->Data.Policy.Capacity )
      goto LABEL_33;
    v27 = v26 + (v26 >> 2);
  }
  else
  {
    if ( v26 >= v24->Data.Policy.Capacity >> 1 )
      goto LABEL_33;
    v27 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v27);
LABEL_33:
  v28 = v24->Data.Data;
  v24->Data.Size = v26;
  v29 = x >> 20;
  v28[v26 - 1] = v25;
  v30 = this->Data;
  v31 = this->Data->Data.Size + 1;
  if ( v31 >= this->Data->Data.Size )
  {
    if ( v31 > v30->Data.Policy.Capacity )
    {
      v32 = v31 + (v31 >> 2);
      goto LABEL_38;
    }
  }
  else if ( v31 < v30->Data.Policy.Capacity >> 1 )
  {
    v32 = this->Data->Data.Size + 1;
LABEL_38:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
      this->Data,
      v32);
  }
  v33 = v30->Data.Data;
  v30->Data.Size = v31;
  v33[v31 - 1] = v29;
  return 3i64;
}

// File Line: 485
// RVA: 0x91CA00
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int y)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rdi
  unsigned int v3; // eax
  char v4; // bp
  __int64 *pHeap; // rdx
  unsigned __int64 v7; // rbx
  char v9; // bp
  unsigned __int64 v10; // r8
  char *v11; // rcx
  char *v12; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v13; // rdi
  int v14; // esi
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // r8
  char *v17; // rcx
  char *v18; // rcx
  char v20; // bp
  unsigned __int64 v21; // r8
  char *v22; // rcx
  char *v23; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v24; // rdi
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // r8
  char *v27; // rcx
  char *v28; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v29; // rdi
  unsigned __int64 v30; // rbx
  unsigned __int64 v31; // r8
  char *v32; // rcx
  char *v33; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v34; // rdi
  int v35; // esi
  unsigned __int64 v36; // rbx
  unsigned __int64 v37; // r8
  char *v38; // rcx
  char *v39; // rcx

  Data = this->Data;
  v3 = y + 2048;
  v4 = 16 * y;
  pHeap = (__int64 *)this->Data->Data.pHeap;
  v7 = this->Data->Data.Size + 1;
  if ( v3 <= 0xFFF )
  {
    v9 = v4 | 2;
    if ( v7 >= Data->Data.Size )
    {
      if ( v7 <= Data->Data.Policy.Capacity )
        goto LABEL_8;
      v10 = v7 + (v7 >> 2);
    }
    else
    {
      if ( v7 >= Data->Data.Policy.Capacity >> 1 )
        goto LABEL_8;
      v10 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &Data->Data,
      pHeap,
      v10);
LABEL_8:
    v11 = Data->Data.Data;
    Data->Data.Size = v7;
    v12 = &v11[v7 - 1];
    if ( v12 )
      *v12 = v9;
    v13 = this->Data;
    v14 = y >> 4;
    v15 = this->Data->Data.Size + 1;
    if ( v15 >= this->Data->Data.Size )
    {
      if ( v15 > v13->Data.Policy.Capacity )
      {
        v16 = v15 + (v15 >> 2);
        goto LABEL_15;
      }
    }
    else if ( v15 < v13->Data.Policy.Capacity >> 1 )
    {
      v16 = this->Data->Data.Size + 1;
LABEL_15:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v13->Data,
        (__int64 *)this->Data->Data.pHeap,
        v16);
    }
    v17 = v13->Data.Data;
    v13->Data.Size = v15;
    v18 = &v17[v15 - 1];
    if ( v18 )
      *v18 = v14;
    return 2i64;
  }
  v20 = v4 | 3;
  if ( v7 >= Data->Data.Size )
  {
    if ( v7 <= Data->Data.Policy.Capacity )
      goto LABEL_25;
    v21 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_25;
    v21 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &Data->Data,
    pHeap,
    v21);
LABEL_25:
  v22 = Data->Data.Data;
  Data->Data.Size = v7;
  v23 = &v22[v7 - 1];
  if ( v23 )
    *v23 = v20;
  v24 = this->Data;
  v25 = this->Data->Data.Size + 1;
  if ( v25 >= this->Data->Data.Size )
  {
    if ( v25 <= v24->Data.Policy.Capacity )
      goto LABEL_33;
    v26 = v25 + (v25 >> 2);
  }
  else
  {
    if ( v25 >= v24->Data.Policy.Capacity >> 1 )
      goto LABEL_33;
    v26 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v26);
LABEL_33:
  v27 = v24->Data.Data;
  v24->Data.Size = v25;
  v28 = &v27[v25 - 1];
  if ( v28 )
    *v28 = y >> 4;
  v29 = this->Data;
  v30 = this->Data->Data.Size + 1;
  if ( v30 >= this->Data->Data.Size )
  {
    if ( v30 <= v29->Data.Policy.Capacity )
      goto LABEL_41;
    v31 = v30 + (v30 >> 2);
  }
  else
  {
    if ( v30 >= v29->Data.Policy.Capacity >> 1 )
      goto LABEL_41;
    v31 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v31);
LABEL_41:
  v32 = v29->Data.Data;
  v29->Data.Size = v30;
  v33 = &v32[v30 - 1];
  if ( v33 )
    *v33 = y >> 12;
  v34 = this->Data;
  v35 = y >> 20;
  v36 = this->Data->Data.Size + 1;
  if ( v36 >= this->Data->Data.Size )
  {
    if ( v36 > v34->Data.Policy.Capacity )
    {
      v37 = v36 + (v36 >> 2);
      goto LABEL_48;
    }
  }
  else if ( v36 < v34->Data.Policy.Capacity >> 1 )
  {
    v37 = this->Data->Data.Size + 1;
LABEL_48:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v34->Data,
      (__int64 *)this->Data->Data.pHeap,
      v37);
  }
  v38 = v34->Data.Data;
  v34->Data.Size = v36;
  v39 = &v38[v36 - 1];
  if ( v39 )
    *v39 = v35;
  return 3i64;
}

// File Line: 502
// RVA: 0x91A830
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int x,
        int y)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // r14
  unsigned __int64 v7; // rdi
  char v8; // bp
  unsigned __int64 v9; // r8
  char *v10; // rcx
  char *v11; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // rdi
  char v13; // si
  unsigned __int64 v14; // rbx
  unsigned __int64 v15; // r8
  char *v16; // rcx
  char *v17; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v19; // r14
  unsigned __int64 v20; // rdi
  char v21; // bp
  unsigned __int64 v22; // r8
  char *v23; // rcx
  char *v24; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v25; // rdi
  char v26; // bp
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // r8
  char *v29; // rcx
  char *v30; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v31; // rdi
  int v32; // esi
  unsigned __int64 v33; // rbx
  unsigned __int64 v34; // r8
  char *v35; // rcx
  char *v36; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v37; // r14
  unsigned __int64 v38; // rdi
  char v39; // bp
  unsigned __int64 v40; // r8
  char *v41; // rcx
  char *v42; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v43; // r14
  unsigned __int64 v44; // rdi
  unsigned __int64 v45; // r8
  char *v46; // rcx
  char *v47; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v48; // rdi
  char v49; // bp
  unsigned __int64 v50; // rbx
  unsigned __int64 v51; // r8
  char *v52; // rcx
  char *v53; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v54; // rdi
  int v55; // esi
  unsigned __int64 v56; // rbx
  unsigned __int64 v57; // r8
  char *v58; // rcx
  char *v59; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v60; // r14
  unsigned __int64 v61; // rdi
  char v62; // bp
  unsigned __int64 v63; // r8
  char *v64; // rcx
  char *v65; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v66; // r14
  unsigned __int64 v67; // rdi
  unsigned __int64 v68; // r8
  char *v69; // rcx
  char *v70; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v71; // r14
  unsigned __int64 v72; // rdi
  unsigned __int64 v73; // r8
  char *v74; // rcx
  char *v75; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v76; // r14
  unsigned __int64 v77; // rdi
  unsigned __int64 v78; // r8
  char *v79; // rcx
  char *v80; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v81; // r14
  unsigned __int64 v82; // rdi
  char v83; // bl
  unsigned __int64 v84; // r8
  char *v85; // rcx
  char *v86; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v87; // rdi
  unsigned __int64 v88; // rbx
  unsigned __int64 v89; // r8
  char *v90; // rcx
  char *v91; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v92; // rdi
  unsigned __int64 v93; // rbx
  unsigned __int64 v94; // r8
  char *v95; // rcx
  char *v96; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v97; // rdi
  int v98; // esi
  unsigned __int64 v99; // rbx
  unsigned __int64 v100; // r8
  char *v101; // rcx
  char *v102; // rcx

  if ( (unsigned int)(x + 32) <= 0x3F && (unsigned int)(y + 32) <= 0x3F )
  {
    Data = this->Data;
    v7 = this->Data->Data.Size + 1;
    v8 = (16 * x) | 4;
    if ( v7 >= this->Data->Data.Size )
    {
      if ( v7 <= Data->Data.Policy.Capacity )
        goto LABEL_9;
      v9 = v7 + (v7 >> 2);
    }
    else
    {
      if ( v7 >= Data->Data.Policy.Capacity >> 1 )
        goto LABEL_9;
      v9 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v9);
LABEL_9:
    v10 = Data->Data.Data;
    Data->Data.Size = v7;
    v11 = &v10[v7 - 1];
    if ( v11 )
      *v11 = v8;
    v12 = this->Data;
    v13 = (x >> 4) & 3 | (4 * y);
    v14 = this->Data->Data.Size + 1;
    if ( v14 >= this->Data->Data.Size )
    {
      if ( v14 > v12->Data.Policy.Capacity )
      {
        v15 = v14 + (v14 >> 2);
        goto LABEL_16;
      }
    }
    else if ( v14 < v12->Data.Policy.Capacity >> 1 )
    {
      v15 = this->Data->Data.Size + 1;
LABEL_16:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v12->Data,
        (__int64 *)this->Data->Data.pHeap,
        v15);
    }
    v16 = v12->Data.Data;
    v12->Data.Size = v14;
    v17 = &v16[v14 - 1];
    if ( v17 )
      *v17 = v13;
    return 2i64;
  }
  if ( (unsigned int)(x + 512) <= 0x3FF && (unsigned int)(y + 512) <= 0x3FF )
  {
    v19 = this->Data;
    v20 = this->Data->Data.Size + 1;
    v21 = (16 * x) | 5;
    if ( v20 >= this->Data->Data.Size )
    {
      if ( v20 <= v19->Data.Policy.Capacity )
        goto LABEL_28;
      v22 = v20 + (v20 >> 2);
    }
    else
    {
      if ( v20 >= v19->Data.Policy.Capacity >> 1 )
        goto LABEL_28;
      v22 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v22);
LABEL_28:
    v23 = v19->Data.Data;
    v19->Data.Size = v20;
    v24 = &v23[v20 - 1];
    if ( v24 )
      *v24 = v21;
    v25 = this->Data;
    v26 = (x >> 4) & 0x3F | ((_BYTE)y << 6);
    v27 = this->Data->Data.Size + 1;
    if ( v27 >= this->Data->Data.Size )
    {
      if ( v27 <= v25->Data.Policy.Capacity )
        goto LABEL_36;
      v28 = v27 + (v27 >> 2);
    }
    else
    {
      if ( v27 >= v25->Data.Policy.Capacity >> 1 )
        goto LABEL_36;
      v28 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v28);
LABEL_36:
    v29 = v25->Data.Data;
    v25->Data.Size = v27;
    v30 = &v29[v27 - 1];
    if ( v30 )
      *v30 = v26;
    v31 = this->Data;
    v32 = y >> 2;
    v33 = this->Data->Data.Size + 1;
    if ( v33 >= this->Data->Data.Size )
    {
      if ( v33 > v31->Data.Policy.Capacity )
      {
        v34 = v33 + (v33 >> 2);
        goto LABEL_43;
      }
    }
    else if ( v33 < v31->Data.Policy.Capacity >> 1 )
    {
      v34 = this->Data->Data.Size + 1;
LABEL_43:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v31->Data,
        (__int64 *)this->Data->Data.pHeap,
        v34);
    }
    v35 = v31->Data.Data;
    v31->Data.Size = v33;
    v36 = &v35[v33 - 1];
    if ( v36 )
      *v36 = v32;
    return 3i64;
  }
  if ( (unsigned int)(x + 0x2000) <= 0x3FFF && (unsigned int)(y + 0x2000) <= 0x3FFF )
  {
    v37 = this->Data;
    v38 = this->Data->Data.Size + 1;
    v39 = (16 * x) | 6;
    if ( v38 >= this->Data->Data.Size )
    {
      if ( v38 <= v37->Data.Policy.Capacity )
        goto LABEL_55;
      v40 = v38 + (v38 >> 2);
    }
    else
    {
      if ( v38 >= v37->Data.Policy.Capacity >> 1 )
        goto LABEL_55;
      v40 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v40);
LABEL_55:
    v41 = v37->Data.Data;
    v37->Data.Size = v38;
    v42 = &v41[v38 - 1];
    if ( v42 )
      *v42 = v39;
    v43 = this->Data;
    v44 = this->Data->Data.Size + 1;
    if ( v44 >= this->Data->Data.Size )
    {
      if ( v44 <= v43->Data.Policy.Capacity )
        goto LABEL_63;
      v45 = v44 + (v44 >> 2);
    }
    else
    {
      if ( v44 >= v43->Data.Policy.Capacity >> 1 )
        goto LABEL_63;
      v45 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v45);
LABEL_63:
    v46 = v43->Data.Data;
    v43->Data.Size = v44;
    v47 = &v46[v44 - 1];
    if ( v47 )
      *v47 = x >> 4;
    v48 = this->Data;
    v49 = (x >> 12) & 3 | (4 * y);
    v50 = this->Data->Data.Size + 1;
    if ( v50 >= this->Data->Data.Size )
    {
      if ( v50 <= v48->Data.Policy.Capacity )
        goto LABEL_71;
      v51 = v50 + (v50 >> 2);
    }
    else
    {
      if ( v50 >= v48->Data.Policy.Capacity >> 1 )
        goto LABEL_71;
      v51 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v51);
LABEL_71:
    v52 = v48->Data.Data;
    v48->Data.Size = v50;
    v53 = &v52[v50 - 1];
    if ( v53 )
      *v53 = v49;
    v54 = this->Data;
    v55 = y >> 6;
    v56 = this->Data->Data.Size + 1;
    if ( v56 >= this->Data->Data.Size )
    {
      if ( v56 > v54->Data.Policy.Capacity )
      {
        v57 = v56 + (v56 >> 2);
        goto LABEL_78;
      }
    }
    else if ( v56 < v54->Data.Policy.Capacity >> 1 )
    {
      v57 = this->Data->Data.Size + 1;
LABEL_78:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v54->Data,
        (__int64 *)this->Data->Data.pHeap,
        v57);
    }
    v58 = v54->Data.Data;
    v54->Data.Size = v56;
    v59 = &v58[v56 - 1];
    if ( v59 )
      *v59 = v55;
    return 4i64;
  }
  v60 = this->Data;
  v61 = this->Data->Data.Size + 1;
  v62 = (16 * x) | 7;
  if ( v61 >= this->Data->Data.Size )
  {
    if ( v61 <= v60->Data.Policy.Capacity )
      goto LABEL_88;
    v63 = v61 + (v61 >> 2);
  }
  else
  {
    if ( v61 >= v60->Data.Policy.Capacity >> 1 )
      goto LABEL_88;
    v63 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v63);
LABEL_88:
  v64 = v60->Data.Data;
  v60->Data.Size = v61;
  v65 = &v64[v61 - 1];
  if ( v65 )
    *v65 = v62;
  v66 = this->Data;
  v67 = this->Data->Data.Size + 1;
  if ( v67 >= this->Data->Data.Size )
  {
    if ( v67 <= v66->Data.Policy.Capacity )
      goto LABEL_96;
    v68 = v67 + (v67 >> 2);
  }
  else
  {
    if ( v67 >= v66->Data.Policy.Capacity >> 1 )
      goto LABEL_96;
    v68 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v68);
LABEL_96:
  v69 = v66->Data.Data;
  v66->Data.Size = v67;
  v70 = &v69[v67 - 1];
  if ( v70 )
    *v70 = x >> 4;
  v71 = this->Data;
  v72 = this->Data->Data.Size + 1;
  if ( v72 >= this->Data->Data.Size )
  {
    if ( v72 <= v71->Data.Policy.Capacity )
      goto LABEL_104;
    v73 = v72 + (v72 >> 2);
  }
  else
  {
    if ( v72 >= v71->Data.Policy.Capacity >> 1 )
      goto LABEL_104;
    v73 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v73);
LABEL_104:
  v74 = v71->Data.Data;
  v71->Data.Size = v72;
  v75 = &v74[v72 - 1];
  if ( v75 )
    *v75 = x >> 12;
  v76 = this->Data;
  v77 = this->Data->Data.Size + 1;
  if ( v77 >= this->Data->Data.Size )
  {
    if ( v77 <= v76->Data.Policy.Capacity )
      goto LABEL_112;
    v78 = v77 + (v77 >> 2);
  }
  else
  {
    if ( v77 >= v76->Data.Policy.Capacity >> 1 )
      goto LABEL_112;
    v78 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v78);
LABEL_112:
  v79 = v76->Data.Data;
  v76->Data.Size = v77;
  v80 = &v79[v77 - 1];
  if ( v80 )
    *v80 = x >> 20;
  v81 = this->Data;
  v82 = this->Data->Data.Size + 1;
  v83 = (4 * y) | (x >> 28) & 3;
  if ( v82 >= this->Data->Data.Size )
  {
    if ( v82 <= v81->Data.Policy.Capacity )
      goto LABEL_120;
    v84 = v82 + (v82 >> 2);
  }
  else
  {
    if ( v82 >= v81->Data.Policy.Capacity >> 1 )
      goto LABEL_120;
    v84 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v84);
LABEL_120:
  v85 = v81->Data.Data;
  v81->Data.Size = v82;
  v86 = &v85[v82 - 1];
  if ( v86 )
    *v86 = v83;
  v87 = this->Data;
  v88 = this->Data->Data.Size + 1;
  if ( v88 >= this->Data->Data.Size )
  {
    if ( v88 <= v87->Data.Policy.Capacity )
      goto LABEL_128;
    v89 = v88 + (v88 >> 2);
  }
  else
  {
    if ( v88 >= v87->Data.Policy.Capacity >> 1 )
      goto LABEL_128;
    v89 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v89);
LABEL_128:
  v90 = v87->Data.Data;
  v87->Data.Size = v88;
  v91 = &v90[v88 - 1];
  if ( v91 )
    *v91 = y >> 6;
  v92 = this->Data;
  v93 = this->Data->Data.Size + 1;
  if ( v93 >= this->Data->Data.Size )
  {
    if ( v93 <= v92->Data.Policy.Capacity )
      goto LABEL_136;
    v94 = v93 + (v93 >> 2);
  }
  else
  {
    if ( v93 >= v92->Data.Policy.Capacity >> 1 )
      goto LABEL_136;
    v94 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v94);
LABEL_136:
  v95 = v92->Data.Data;
  v92->Data.Size = v93;
  v96 = &v95[v93 - 1];
  if ( v96 )
    *v96 = y >> 14;
  v97 = this->Data;
  v98 = y >> 22;
  v99 = this->Data->Data.Size + 1;
  if ( v99 >= this->Data->Data.Size )
  {
    if ( v99 > v97->Data.Policy.Capacity )
    {
      v100 = v99 + (v99 >> 2);
      goto LABEL_143;
    }
  }
  else if ( v99 < v97->Data.Policy.Capacity >> 1 )
  {
    v100 = this->Data->Data.Size + 1;
LABEL_143:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v97->Data,
      (__int64 *)this->Data->Data.pHeap,
      v100);
  }
  v101 = v97->Data.Data;
  v97->Data.Size = v99;
  v102 = &v101[v99 - 1];
  if ( v102 )
    *v102 = v98;
  return 8i64;
}

// File Line: 540
// RVA: 0x91AEC0
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int cx,
        int cy,
        int ax,
        int ay)
{
  int v6; // ecx
  int v7; // eax
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // r12
  unsigned __int64 v12; // r15
  char v13; // r13
  unsigned __int64 v14; // r8
  char *v15; // rcx
  char *v16; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v17; // r15
  char v18; // bl
  unsigned __int64 v19; // rsi
  char v20; // bl
  unsigned __int64 v21; // r8
  char *v22; // rcx
  char *v23; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v24; // rsi
  unsigned __int64 v25; // rbx
  char v26; // di
  unsigned __int64 v27; // r8
  char *v28; // rcx
  char *v29; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v31; // r12
  unsigned __int64 v32; // r15
  char v33; // r13
  unsigned __int64 v34; // r8
  char *v35; // rcx
  char *v36; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v37; // r12
  unsigned __int64 v38; // r15
  char v39; // bl
  unsigned __int64 v40; // r8
  char *v41; // rcx
  char *v42; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v43; // r15
  unsigned __int64 v44; // rbx
  char v45; // si
  unsigned __int64 v46; // r8
  char *v47; // rcx
  char *v48; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v49; // rsi
  unsigned __int64 v50; // rbx
  char v51; // di
  unsigned __int64 v52; // r8
  char *v53; // rcx
  char *v54; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v55; // r12
  unsigned __int64 v56; // r15
  char v57; // r13
  unsigned __int64 v58; // r8
  char *v59; // rcx
  char *v60; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v61; // r12
  unsigned __int64 v62; // r15
  char v63; // bl
  unsigned __int64 v64; // r8
  char *v65; // rcx
  char *v66; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v67; // r15
  unsigned __int64 v68; // rbx
  char v69; // si
  unsigned __int64 v70; // r8
  char *v71; // rcx
  char *v72; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v73; // rsi
  unsigned __int64 v74; // rbx
  char v75; // di
  unsigned __int64 v76; // r8
  char *v77; // rcx
  char *v78; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v79; // rdi
  unsigned __int64 v80; // rbx
  unsigned __int64 v81; // r8
  char *v82; // rcx
  char *v83; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v84; // r12
  unsigned __int64 v85; // r15
  char v86; // r13
  unsigned __int64 v87; // r8
  char *v88; // rcx
  char *v89; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v90; // r12
  unsigned __int64 v91; // r15
  char v92; // bl
  unsigned __int64 v93; // r8
  char *v94; // rcx
  char *v95; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v96; // r15
  unsigned __int64 v97; // rbx
  unsigned __int64 v98; // r8
  char *v99; // rcx
  char *v100; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v101; // r15
  unsigned __int64 v102; // rbx
  char v103; // si
  unsigned __int64 v104; // r8
  char *v105; // rcx
  char *v106; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v107; // rsi
  unsigned __int64 v108; // rbx
  char v109; // di
  unsigned __int64 v110; // r8
  char *v111; // rcx
  char *v112; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v113; // rdi
  unsigned __int64 v114; // rbx
  unsigned __int64 v115; // r8
  char *v116; // rcx
  char *v117; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v118; // r12
  unsigned __int64 v119; // r15
  char v120; // r13
  unsigned __int64 v121; // r8
  char *v122; // rcx
  char *v123; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v124; // r12
  unsigned __int64 v125; // r15
  unsigned __int64 v126; // r8
  char *v127; // rcx
  char *v128; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v129; // r12
  unsigned __int64 v130; // r15
  char v131; // bl
  unsigned __int64 v132; // r8
  char *v133; // rcx
  char *v134; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v135; // r15
  unsigned __int64 v136; // rbx
  char v137; // si
  unsigned __int64 v138; // r8
  char *v139; // rcx
  char *v140; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v141; // rsi
  unsigned __int64 v142; // rbx
  unsigned __int64 v143; // r8
  char *v144; // rcx
  char *v145; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v146; // rsi
  unsigned __int64 v147; // rbx
  char v148; // di
  unsigned __int64 v149; // r8
  char *v150; // rcx
  char *v151; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v152; // rdi
  unsigned __int64 v153; // rbx
  unsigned __int64 v154; // r8
  char *v155; // rcx
  char *v156; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v157; // r12
  unsigned __int64 v158; // r15
  char v159; // r13
  unsigned __int64 v160; // r8
  char *v161; // rcx
  char *v162; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v163; // r12
  unsigned __int64 v164; // r15
  unsigned __int64 v165; // r8
  char *v166; // rcx
  char *v167; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v168; // r12
  unsigned __int64 v169; // r15
  char v170; // bl
  unsigned __int64 v171; // r8
  char *v172; // rcx
  char *v173; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v174; // r15
  unsigned __int64 v175; // rbx
  unsigned __int64 v176; // r8
  char *v177; // rcx
  char *v178; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v179; // r15
  unsigned __int64 v180; // rbx
  char v181; // si
  unsigned __int64 v182; // r8
  char *v183; // rcx
  char *v184; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v185; // rsi
  unsigned __int64 v186; // rbx
  unsigned __int64 v187; // r8
  char *v188; // rcx
  char *v189; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v190; // rsi
  unsigned __int64 v191; // rbx
  char v192; // di
  unsigned __int64 v193; // r8
  char *v194; // rcx
  char *v195; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v196; // rdi
  unsigned __int64 v197; // rbx
  unsigned __int64 v198; // r8
  char *v199; // rcx
  char *v200; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v201; // r12
  unsigned __int64 v202; // r15
  char v203; // r13
  unsigned __int64 v204; // r8
  char *v205; // rcx
  char *v206; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v207; // r12
  unsigned __int64 v208; // r15
  unsigned __int64 v209; // r8
  char *v210; // rcx
  char *v211; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v212; // r12
  unsigned __int64 v213; // r15
  unsigned __int64 v214; // r8
  char *v215; // rcx
  char *v216; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v217; // r12
  unsigned __int64 v218; // r15
  unsigned __int64 v219; // r8
  char *v220; // rcx
  char *v221; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v222; // r12
  unsigned __int64 v223; // r15
  char v224; // bl
  unsigned __int64 v225; // r8
  char *v226; // rcx
  char *v227; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v228; // r15
  unsigned __int64 v229; // rbx
  unsigned __int64 v230; // r8
  char *v231; // rcx
  char *v232; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v233; // r15
  unsigned __int64 v234; // rbx
  unsigned __int64 v235; // r8
  char *v236; // rcx
  char *v237; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v238; // r15
  unsigned __int64 v239; // rbx
  unsigned __int64 v240; // r8
  char *v241; // rcx
  char *v242; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v243; // r15
  unsigned __int64 v244; // rbx
  char v245; // si
  unsigned __int64 v246; // r8
  char *v247; // rcx
  char *v248; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v249; // rbx
  char *v250; // rdx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v251; // rbx
  char *v252; // rdx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v253; // rbx
  char *v254; // rdx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v255; // rbx
  char *v256; // rdx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v257; // rbx
  char *v258; // rdx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v259; // rbx
  char *v260; // rdx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v261; // rbx
  char *v262; // rdx

  v6 = cx;
  v7 = cx;
  if ( cy < cx )
    v6 = cy;
  if ( cy > cx )
    v7 = cy;
  if ( ax < v6 )
    v6 = ax;
  if ( ax > v7 )
    v7 = ax;
  if ( ay < v6 )
    v6 = ay;
  if ( ay > v7 )
    v7 = ay;
  if ( v6 >= -16 && v7 <= 15 )
  {
    Data = this->Data;
    v12 = this->Data->Data.Size + 1;
    v13 = (16 * cx) | 8;
    if ( v12 >= this->Data->Data.Size )
    {
      if ( v12 <= Data->Data.Policy.Capacity )
        goto LABEL_21;
      v14 = v12 + (v12 >> 2);
    }
    else
    {
      if ( v12 >= Data->Data.Policy.Capacity >> 1 )
        goto LABEL_21;
      v14 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v14);
LABEL_21:
    v15 = Data->Data.Data;
    Data->Data.Size = v12;
    v16 = &v15[v12 - 1];
    if ( v16 )
      *v16 = v13;
    v17 = this->Data;
    v18 = (2 * cy) | (cx >> 4) & 1;
    v19 = this->Data->Data.Size + 1;
    v20 = ((_BYTE)ax << 6) | v18 & 0x3F;
    if ( v19 >= this->Data->Data.Size )
    {
      if ( v19 <= v17->Data.Policy.Capacity )
        goto LABEL_29;
      v21 = v19 + (v19 >> 2);
    }
    else
    {
      if ( v19 >= v17->Data.Policy.Capacity >> 1 )
        goto LABEL_29;
      v21 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v21);
LABEL_29:
    v22 = v17->Data.Data;
    v17->Data.Size = v19;
    v23 = &v22[v19 - 1];
    if ( v23 )
      *v23 = v20;
    v24 = this->Data;
    v25 = this->Data->Data.Size + 1;
    v26 = (8 * ay) | (ax >> 2) & 7;
    if ( v25 >= this->Data->Data.Size )
    {
      if ( v25 > v24->Data.Policy.Capacity )
      {
        v27 = v25 + (v25 >> 2);
        goto LABEL_36;
      }
    }
    else if ( v25 < v24->Data.Policy.Capacity >> 1 )
    {
      v27 = this->Data->Data.Size + 1;
LABEL_36:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v27);
    }
    v28 = v24->Data.Data;
    v24->Data.Size = v25;
    v29 = &v28[v25 - 1];
    if ( v29 )
      *v29 = v26;
    return 3i64;
  }
  if ( v6 >= -64 && v7 <= 63 )
  {
    v31 = this->Data;
    v32 = this->Data->Data.Size + 1;
    v33 = (16 * cx) | 9;
    if ( v32 >= this->Data->Data.Size )
    {
      if ( v32 <= v31->Data.Policy.Capacity )
        goto LABEL_48;
      v34 = v32 + (v32 >> 2);
    }
    else
    {
      if ( v32 >= v31->Data.Policy.Capacity >> 1 )
        goto LABEL_48;
      v34 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v34);
LABEL_48:
    v35 = v31->Data.Data;
    v31->Data.Size = v32;
    v36 = &v35[v32 - 1];
    if ( v36 )
      *v36 = v33;
    v37 = this->Data;
    v38 = this->Data->Data.Size + 1;
    v39 = (8 * cy) | (cx >> 4) & 7;
    if ( v38 >= this->Data->Data.Size )
    {
      if ( v38 <= v37->Data.Policy.Capacity )
        goto LABEL_56;
      v40 = v38 + (v38 >> 2);
    }
    else
    {
      if ( v38 >= v37->Data.Policy.Capacity >> 1 )
        goto LABEL_56;
      v40 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v40);
LABEL_56:
    v41 = v37->Data.Data;
    v37->Data.Size = v38;
    v42 = &v41[v38 - 1];
    if ( v42 )
      *v42 = v39;
    v43 = this->Data;
    v44 = this->Data->Data.Size + 1;
    v45 = (4 * ax) | (cy >> 5) & 3;
    if ( v44 >= this->Data->Data.Size )
    {
      if ( v44 <= v43->Data.Policy.Capacity )
        goto LABEL_64;
      v46 = v44 + (v44 >> 2);
    }
    else
    {
      if ( v44 >= v43->Data.Policy.Capacity >> 1 )
        goto LABEL_64;
      v46 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v46);
LABEL_64:
    v47 = v43->Data.Data;
    v43->Data.Size = v44;
    v48 = &v47[v44 - 1];
    if ( v48 )
      *v48 = v45;
    v49 = this->Data;
    v50 = this->Data->Data.Size + 1;
    v51 = (2 * ay) | (ax >> 6) & 1;
    if ( v50 >= this->Data->Data.Size )
    {
      if ( v50 > v49->Data.Policy.Capacity )
      {
        v52 = v50 + (v50 >> 2);
        goto LABEL_71;
      }
    }
    else if ( v50 < v49->Data.Policy.Capacity >> 1 )
    {
      v52 = this->Data->Data.Size + 1;
LABEL_71:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v52);
    }
    v53 = v49->Data.Data;
    v49->Data.Size = v50;
    v54 = &v53[v50 - 1];
    if ( v54 )
      *v54 = v51;
    return 4i64;
  }
  if ( v6 >= -256 && v7 <= 255 )
  {
    v55 = this->Data;
    v56 = this->Data->Data.Size + 1;
    v57 = (16 * cx) | 0xA;
    if ( v56 >= this->Data->Data.Size )
    {
      if ( v56 <= v55->Data.Policy.Capacity )
        goto LABEL_83;
      v58 = v56 + (v56 >> 2);
    }
    else
    {
      if ( v56 >= v55->Data.Policy.Capacity >> 1 )
        goto LABEL_83;
      v58 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v58);
LABEL_83:
    v59 = v55->Data.Data;
    v55->Data.Size = v56;
    v60 = &v59[v56 - 1];
    if ( v60 )
      *v60 = v57;
    v61 = this->Data;
    v62 = this->Data->Data.Size + 1;
    v63 = (32 * cy) | (cx >> 4) & 0x1F;
    if ( v62 >= this->Data->Data.Size )
    {
      if ( v62 <= v61->Data.Policy.Capacity )
        goto LABEL_91;
      v64 = v62 + (v62 >> 2);
    }
    else
    {
      if ( v62 >= v61->Data.Policy.Capacity >> 1 )
        goto LABEL_91;
      v64 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v64);
LABEL_91:
    v65 = v61->Data.Data;
    v61->Data.Size = v62;
    v66 = &v65[v62 - 1];
    if ( v66 )
      *v66 = v63;
    v67 = this->Data;
    v68 = this->Data->Data.Size + 1;
    v69 = ((_BYTE)ax << 6) | (cy >> 3) & 0x3F;
    if ( v68 >= this->Data->Data.Size )
    {
      if ( v68 <= v67->Data.Policy.Capacity )
        goto LABEL_99;
      v70 = v68 + (v68 >> 2);
    }
    else
    {
      if ( v68 >= v67->Data.Policy.Capacity >> 1 )
        goto LABEL_99;
      v70 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v70);
LABEL_99:
    v71 = v67->Data.Data;
    v67->Data.Size = v68;
    v72 = &v71[v68 - 1];
    if ( v72 )
      *v72 = v69;
    v73 = this->Data;
    v74 = this->Data->Data.Size + 1;
    v75 = ((_BYTE)ay << 7) | (ax >> 2) & 0x7F;
    if ( v74 >= this->Data->Data.Size )
    {
      if ( v74 <= v73->Data.Policy.Capacity )
        goto LABEL_107;
      v76 = v74 + (v74 >> 2);
    }
    else
    {
      if ( v74 >= v73->Data.Policy.Capacity >> 1 )
        goto LABEL_107;
      v76 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v76);
LABEL_107:
    v77 = v73->Data.Data;
    v73->Data.Size = v74;
    v78 = &v77[v74 - 1];
    if ( v78 )
      *v78 = v75;
    v79 = this->Data;
    v80 = this->Data->Data.Size + 1;
    if ( v80 >= this->Data->Data.Size )
    {
      if ( v80 > v79->Data.Policy.Capacity )
      {
        v81 = v80 + (v80 >> 2);
        goto LABEL_114;
      }
    }
    else if ( v80 < v79->Data.Policy.Capacity >> 1 )
    {
      v81 = this->Data->Data.Size + 1;
LABEL_114:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v81);
    }
    v82 = v79->Data.Data;
    v79->Data.Size = v80;
    v83 = &v82[v80 - 1];
    if ( v83 )
      *v83 = ay >> 1;
    return 5i64;
  }
  if ( v6 >= -1024 && v7 <= 1023 )
  {
    v84 = this->Data;
    v85 = this->Data->Data.Size + 1;
    v86 = (16 * cx) | 0xB;
    if ( v85 >= this->Data->Data.Size )
    {
      if ( v85 <= v84->Data.Policy.Capacity )
        goto LABEL_126;
      v87 = v85 + (v85 >> 2);
    }
    else
    {
      if ( v85 >= v84->Data.Policy.Capacity >> 1 )
        goto LABEL_126;
      v87 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v87);
LABEL_126:
    v88 = v84->Data.Data;
    v84->Data.Size = v85;
    v89 = &v88[v85 - 1];
    if ( v89 )
      *v89 = v86;
    v90 = this->Data;
    v91 = this->Data->Data.Size + 1;
    v92 = ((_BYTE)cy << 7) | (cx >> 4) & 0x7F;
    if ( v91 >= this->Data->Data.Size )
    {
      if ( v91 <= v90->Data.Policy.Capacity )
        goto LABEL_134;
      v93 = v91 + (v91 >> 2);
    }
    else
    {
      if ( v91 >= v90->Data.Policy.Capacity >> 1 )
        goto LABEL_134;
      v93 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v93);
LABEL_134:
    v94 = v90->Data.Data;
    v90->Data.Size = v91;
    v95 = &v94[v91 - 1];
    if ( v95 )
      *v95 = v92;
    v96 = this->Data;
    v97 = this->Data->Data.Size + 1;
    if ( v97 >= this->Data->Data.Size )
    {
      if ( v97 <= v96->Data.Policy.Capacity )
        goto LABEL_142;
      v98 = v97 + (v97 >> 2);
    }
    else
    {
      if ( v97 >= v96->Data.Policy.Capacity >> 1 )
        goto LABEL_142;
      v98 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v98);
LABEL_142:
    v99 = v96->Data.Data;
    v96->Data.Size = v97;
    v100 = &v99[v97 - 1];
    if ( v100 )
      *v100 = cy >> 1;
    v101 = this->Data;
    v102 = this->Data->Data.Size + 1;
    v103 = (4 * ax) | (cy >> 9) & 3;
    if ( v102 >= this->Data->Data.Size )
    {
      if ( v102 <= v101->Data.Policy.Capacity )
        goto LABEL_150;
      v104 = v102 + (v102 >> 2);
    }
    else
    {
      if ( v102 >= v101->Data.Policy.Capacity >> 1 )
        goto LABEL_150;
      v104 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v104);
LABEL_150:
    v105 = v101->Data.Data;
    v101->Data.Size = v102;
    v106 = &v105[v102 - 1];
    if ( v106 )
      *v106 = v103;
    v107 = this->Data;
    v108 = this->Data->Data.Size + 1;
    v109 = (32 * ay) | (ax >> 6) & 0x1F;
    if ( v108 >= this->Data->Data.Size )
    {
      if ( v108 <= v107->Data.Policy.Capacity )
        goto LABEL_158;
      v110 = v108 + (v108 >> 2);
    }
    else
    {
      if ( v108 >= v107->Data.Policy.Capacity >> 1 )
        goto LABEL_158;
      v110 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v110);
LABEL_158:
    v111 = v107->Data.Data;
    v107->Data.Size = v108;
    v112 = &v111[v108 - 1];
    if ( v112 )
      *v112 = v109;
    v113 = this->Data;
    v114 = this->Data->Data.Size + 1;
    if ( v114 >= this->Data->Data.Size )
    {
      if ( v114 > v113->Data.Policy.Capacity )
      {
        v115 = v114 + (v114 >> 2);
        goto LABEL_165;
      }
    }
    else if ( v114 < v113->Data.Policy.Capacity >> 1 )
    {
      v115 = this->Data->Data.Size + 1;
LABEL_165:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v115);
    }
    v116 = v113->Data.Data;
    v113->Data.Size = v114;
    v117 = &v116[v114 - 1];
    if ( v117 )
      *v117 = ay >> 3;
    return 6i64;
  }
  if ( v6 >= -4096 && v7 <= 4095 )
  {
    v118 = this->Data;
    v119 = this->Data->Data.Size + 1;
    v120 = (16 * cx) | 0xC;
    if ( v119 >= this->Data->Data.Size )
    {
      if ( v119 <= v118->Data.Policy.Capacity )
        goto LABEL_177;
      v121 = v119 + (v119 >> 2);
    }
    else
    {
      if ( v119 >= v118->Data.Policy.Capacity >> 1 )
        goto LABEL_177;
      v121 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v121);
LABEL_177:
    v122 = v118->Data.Data;
    v118->Data.Size = v119;
    v123 = &v122[v119 - 1];
    if ( v123 )
      *v123 = v120;
    v124 = this->Data;
    v125 = this->Data->Data.Size + 1;
    if ( v125 >= this->Data->Data.Size )
    {
      if ( v125 <= v124->Data.Policy.Capacity )
        goto LABEL_185;
      v126 = v125 + (v125 >> 2);
    }
    else
    {
      if ( v125 >= v124->Data.Policy.Capacity >> 1 )
        goto LABEL_185;
      v126 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v126);
LABEL_185:
    v127 = v124->Data.Data;
    v124->Data.Size = v125;
    v128 = &v127[v125 - 1];
    if ( v128 )
      *v128 = cx >> 4;
    v129 = this->Data;
    v130 = this->Data->Data.Size + 1;
    v131 = (2 * cy) | (cx >> 12) & 1;
    if ( v130 >= this->Data->Data.Size )
    {
      if ( v130 <= v129->Data.Policy.Capacity )
        goto LABEL_193;
      v132 = v130 + (v130 >> 2);
    }
    else
    {
      if ( v130 >= v129->Data.Policy.Capacity >> 1 )
        goto LABEL_193;
      v132 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v132);
LABEL_193:
    v133 = v129->Data.Data;
    v129->Data.Size = v130;
    v134 = &v133[v130 - 1];
    if ( v134 )
      *v134 = v131;
    v135 = this->Data;
    v136 = this->Data->Data.Size + 1;
    v137 = ((_BYTE)ax << 6) | (cy >> 7) & 0x3F;
    if ( v136 >= this->Data->Data.Size )
    {
      if ( v136 <= v135->Data.Policy.Capacity )
        goto LABEL_201;
      v138 = v136 + (v136 >> 2);
    }
    else
    {
      if ( v136 >= v135->Data.Policy.Capacity >> 1 )
        goto LABEL_201;
      v138 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v138);
LABEL_201:
    v139 = v135->Data.Data;
    v135->Data.Size = v136;
    v140 = &v139[v136 - 1];
    if ( v140 )
      *v140 = v137;
    v141 = this->Data;
    v142 = this->Data->Data.Size + 1;
    if ( v142 >= this->Data->Data.Size )
    {
      if ( v142 <= v141->Data.Policy.Capacity )
        goto LABEL_209;
      v143 = v142 + (v142 >> 2);
    }
    else
    {
      if ( v142 >= v141->Data.Policy.Capacity >> 1 )
        goto LABEL_209;
      v143 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v143);
LABEL_209:
    v144 = v141->Data.Data;
    v141->Data.Size = v142;
    v145 = &v144[v142 - 1];
    if ( v145 )
      *v145 = ax >> 2;
    v146 = this->Data;
    v147 = this->Data->Data.Size + 1;
    v148 = (8 * ay) | (ax >> 10) & 7;
    if ( v147 >= this->Data->Data.Size )
    {
      if ( v147 <= v146->Data.Policy.Capacity )
        goto LABEL_217;
      v149 = v147 + (v147 >> 2);
    }
    else
    {
      if ( v147 >= v146->Data.Policy.Capacity >> 1 )
        goto LABEL_217;
      v149 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v149);
LABEL_217:
    v150 = v146->Data.Data;
    v146->Data.Size = v147;
    v151 = &v150[v147 - 1];
    if ( v151 )
      *v151 = v148;
    v152 = this->Data;
    v153 = this->Data->Data.Size + 1;
    if ( v153 >= this->Data->Data.Size )
    {
      if ( v153 > v152->Data.Policy.Capacity )
      {
        v154 = v153 + (v153 >> 2);
        goto LABEL_224;
      }
    }
    else if ( v153 < v152->Data.Policy.Capacity >> 1 )
    {
      v154 = this->Data->Data.Size + 1;
LABEL_224:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v154);
    }
    v155 = v152->Data.Data;
    v152->Data.Size = v153;
    v156 = &v155[v153 - 1];
    if ( v156 )
      *v156 = ay >> 5;
    return 7i64;
  }
  if ( v6 >= -16384 && v7 <= 0x3FFF )
  {
    v157 = this->Data;
    v158 = this->Data->Data.Size + 1;
    v159 = (16 * cx) | 0xD;
    if ( v158 >= this->Data->Data.Size )
    {
      if ( v158 <= v157->Data.Policy.Capacity )
        goto LABEL_236;
      v160 = v158 + (v158 >> 2);
    }
    else
    {
      if ( v158 >= v157->Data.Policy.Capacity >> 1 )
        goto LABEL_236;
      v160 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v160);
LABEL_236:
    v161 = v157->Data.Data;
    v157->Data.Size = v158;
    v162 = &v161[v158 - 1];
    if ( v162 )
      *v162 = v159;
    v163 = this->Data;
    v164 = this->Data->Data.Size + 1;
    if ( v164 >= this->Data->Data.Size )
    {
      if ( v164 <= v163->Data.Policy.Capacity )
        goto LABEL_244;
      v165 = v164 + (v164 >> 2);
    }
    else
    {
      if ( v164 >= v163->Data.Policy.Capacity >> 1 )
        goto LABEL_244;
      v165 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v165);
LABEL_244:
    v166 = v163->Data.Data;
    v163->Data.Size = v164;
    v167 = &v166[v164 - 1];
    if ( v167 )
      *v167 = cx >> 4;
    v168 = this->Data;
    v169 = this->Data->Data.Size + 1;
    v170 = (8 * cy) | (cx >> 12) & 7;
    if ( v169 >= this->Data->Data.Size )
    {
      if ( v169 <= v168->Data.Policy.Capacity )
        goto LABEL_252;
      v171 = v169 + (v169 >> 2);
    }
    else
    {
      if ( v169 >= v168->Data.Policy.Capacity >> 1 )
        goto LABEL_252;
      v171 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v171);
LABEL_252:
    v172 = v168->Data.Data;
    v168->Data.Size = v169;
    v173 = &v172[v169 - 1];
    if ( v173 )
      *v173 = v170;
    v174 = this->Data;
    v175 = this->Data->Data.Size + 1;
    if ( v175 >= this->Data->Data.Size )
    {
      if ( v175 <= v174->Data.Policy.Capacity )
        goto LABEL_260;
      v176 = v175 + (v175 >> 2);
    }
    else
    {
      if ( v175 >= v174->Data.Policy.Capacity >> 1 )
        goto LABEL_260;
      v176 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v176);
LABEL_260:
    v177 = v174->Data.Data;
    v174->Data.Size = v175;
    v178 = &v177[v175 - 1];
    if ( v178 )
      *v178 = cy >> 5;
    v179 = this->Data;
    v180 = this->Data->Data.Size + 1;
    v181 = (4 * ax) | (cy >> 13) & 3;
    if ( v180 >= this->Data->Data.Size )
    {
      if ( v180 <= v179->Data.Policy.Capacity )
        goto LABEL_268;
      v182 = v180 + (v180 >> 2);
    }
    else
    {
      if ( v180 >= v179->Data.Policy.Capacity >> 1 )
        goto LABEL_268;
      v182 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v182);
LABEL_268:
    v183 = v179->Data.Data;
    v179->Data.Size = v180;
    v184 = &v183[v180 - 1];
    if ( v184 )
      *v184 = v181;
    v185 = this->Data;
    v186 = this->Data->Data.Size + 1;
    if ( v186 >= this->Data->Data.Size )
    {
      if ( v186 <= v185->Data.Policy.Capacity )
        goto LABEL_276;
      v187 = v186 + (v186 >> 2);
    }
    else
    {
      if ( v186 >= v185->Data.Policy.Capacity >> 1 )
        goto LABEL_276;
      v187 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v187);
LABEL_276:
    v188 = v185->Data.Data;
    v185->Data.Size = v186;
    v189 = &v188[v186 - 1];
    if ( v189 )
      *v189 = ax >> 6;
    v190 = this->Data;
    v191 = this->Data->Data.Size + 1;
    v192 = (2 * ay) | (ax >> 14) & 1;
    if ( v191 >= this->Data->Data.Size )
    {
      if ( v191 <= v190->Data.Policy.Capacity )
        goto LABEL_284;
      v193 = v191 + (v191 >> 2);
    }
    else
    {
      if ( v191 >= v190->Data.Policy.Capacity >> 1 )
        goto LABEL_284;
      v193 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v193);
LABEL_284:
    v194 = v190->Data.Data;
    v190->Data.Size = v191;
    v195 = &v194[v191 - 1];
    if ( v195 )
      *v195 = v192;
    v196 = this->Data;
    v197 = this->Data->Data.Size + 1;
    if ( v197 >= this->Data->Data.Size )
    {
      if ( v197 > v196->Data.Policy.Capacity )
      {
        v198 = v197 + (v197 >> 2);
        goto LABEL_291;
      }
    }
    else if ( v197 < v196->Data.Policy.Capacity >> 1 )
    {
      v198 = this->Data->Data.Size + 1;
LABEL_291:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data->Data,
        (__int64 *)this->Data->Data.pHeap,
        v198);
    }
    v199 = v196->Data.Data;
    v196->Data.Size = v197;
    v200 = &v199[v197 - 1];
    if ( v200 )
      *v200 = ay >> 7;
    return 8i64;
  }
  v201 = this->Data;
  v202 = this->Data->Data.Size + 1;
  v203 = (16 * cx) | 0xE;
  if ( v202 >= this->Data->Data.Size )
  {
    if ( v202 <= v201->Data.Policy.Capacity )
      goto LABEL_301;
    v204 = v202 + (v202 >> 2);
  }
  else
  {
    if ( v202 >= v201->Data.Policy.Capacity >> 1 )
      goto LABEL_301;
    v204 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v204);
LABEL_301:
  v205 = v201->Data.Data;
  v201->Data.Size = v202;
  v206 = &v205[v202 - 1];
  if ( v206 )
    *v206 = v203;
  v207 = this->Data;
  v208 = this->Data->Data.Size + 1;
  if ( v208 >= this->Data->Data.Size )
  {
    if ( v208 <= v207->Data.Policy.Capacity )
      goto LABEL_309;
    v209 = v208 + (v208 >> 2);
  }
  else
  {
    if ( v208 >= v207->Data.Policy.Capacity >> 1 )
      goto LABEL_309;
    v209 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v209);
LABEL_309:
  v210 = v207->Data.Data;
  v207->Data.Size = v208;
  v211 = &v210[v208 - 1];
  if ( v211 )
    *v211 = cx >> 4;
  v212 = this->Data;
  v213 = this->Data->Data.Size + 1;
  if ( v213 >= this->Data->Data.Size )
  {
    if ( v213 <= v212->Data.Policy.Capacity )
      goto LABEL_317;
    v214 = v213 + (v213 >> 2);
  }
  else
  {
    if ( v213 >= v212->Data.Policy.Capacity >> 1 )
      goto LABEL_317;
    v214 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v214);
LABEL_317:
  v215 = v212->Data.Data;
  v212->Data.Size = v213;
  v216 = &v215[v213 - 1];
  if ( v216 )
    *v216 = cx >> 12;
  v217 = this->Data;
  v218 = this->Data->Data.Size + 1;
  if ( v218 >= this->Data->Data.Size )
  {
    if ( v218 <= v217->Data.Policy.Capacity )
      goto LABEL_325;
    v219 = v218 + (v218 >> 2);
  }
  else
  {
    if ( v218 >= v217->Data.Policy.Capacity >> 1 )
      goto LABEL_325;
    v219 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v219);
LABEL_325:
  v220 = v217->Data.Data;
  v217->Data.Size = v218;
  v221 = &v220[v218 - 1];
  if ( v221 )
    *v221 = cx >> 20;
  v222 = this->Data;
  v223 = this->Data->Data.Size + 1;
  v224 = (8 * cy) | (cx >> 28) & 7;
  if ( v223 >= this->Data->Data.Size )
  {
    if ( v223 <= v222->Data.Policy.Capacity )
      goto LABEL_333;
    v225 = v223 + (v223 >> 2);
  }
  else
  {
    if ( v223 >= v222->Data.Policy.Capacity >> 1 )
      goto LABEL_333;
    v225 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v225);
LABEL_333:
  v226 = v222->Data.Data;
  v222->Data.Size = v223;
  v227 = &v226[v223 - 1];
  if ( v227 )
    *v227 = v224;
  v228 = this->Data;
  v229 = this->Data->Data.Size + 1;
  if ( v229 >= this->Data->Data.Size )
  {
    if ( v229 <= v228->Data.Policy.Capacity )
      goto LABEL_341;
    v230 = v229 + (v229 >> 2);
  }
  else
  {
    if ( v229 >= v228->Data.Policy.Capacity >> 1 )
      goto LABEL_341;
    v230 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v230);
LABEL_341:
  v231 = v228->Data.Data;
  v228->Data.Size = v229;
  v232 = &v231[v229 - 1];
  if ( v232 )
    *v232 = cy >> 5;
  v233 = this->Data;
  v234 = this->Data->Data.Size + 1;
  if ( v234 >= this->Data->Data.Size )
  {
    if ( v234 <= v233->Data.Policy.Capacity )
      goto LABEL_349;
    v235 = v234 + (v234 >> 2);
  }
  else
  {
    if ( v234 >= v233->Data.Policy.Capacity >> 1 )
      goto LABEL_349;
    v235 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v235);
LABEL_349:
  v236 = v233->Data.Data;
  v233->Data.Size = v234;
  v237 = &v236[v234 - 1];
  if ( v237 )
    *v237 = cy >> 13;
  v238 = this->Data;
  v239 = this->Data->Data.Size + 1;
  if ( v239 >= this->Data->Data.Size )
  {
    if ( v239 <= v238->Data.Policy.Capacity )
      goto LABEL_357;
    v240 = v239 + (v239 >> 2);
  }
  else
  {
    if ( v239 >= v238->Data.Policy.Capacity >> 1 )
      goto LABEL_357;
    v240 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v240);
LABEL_357:
  v241 = v238->Data.Data;
  v238->Data.Size = v239;
  v242 = &v241[v239 - 1];
  if ( v242 )
    *v242 = cy >> 21;
  v243 = this->Data;
  v244 = this->Data->Data.Size + 1;
  v245 = (4 * ax) | (cy >> 29) & 3;
  if ( v244 >= this->Data->Data.Size )
  {
    if ( v244 > v243->Data.Policy.Capacity )
    {
      v246 = v244 + (v244 >> 2);
      goto LABEL_364;
    }
  }
  else if ( v244 < v243->Data.Policy.Capacity >> 1 )
  {
    v246 = this->Data->Data.Size + 1;
LABEL_364:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data->Data,
      (__int64 *)this->Data->Data.pHeap,
      v246);
  }
  v247 = v243->Data.Data;
  v243->Data.Size = v244;
  v248 = &v247[v244 - 1];
  if ( v248 )
    *v248 = v245;
  v249 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v250 = &v249->Data.Data[v249->Data.Size - 1];
  if ( v250 )
    *v250 = ax >> 6;
  v251 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v252 = &v251->Data.Data[v251->Data.Size - 1];
  if ( v252 )
    *v252 = ax >> 14;
  v253 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v254 = &v253->Data.Data[v253->Data.Size - 1];
  if ( v254 )
    *v254 = ax >> 22;
  v255 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v256 = &v255->Data.Data[v255->Data.Size - 1];
  if ( v256 )
    *v256 = (2 * ay) | (ax >> 30) & 1;
  v257 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v258 = &v257->Data.Data[v257->Data.Size - 1];
  if ( v258 )
    *v258 = ay >> 7;
  v259 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v260 = &v259->Data.Data[v259->Data.Size - 1];
  if ( v260 )
    *v260 = ay >> 15;
  v261 = this->Data;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    this->Data->Data.Size + 1);
  v262 = &v261->Data.Data[v261->Data.Size - 1];
  if ( v262 )
    *v262 = ay >> 23;
  return 16i64;
}

// File Line: 632
// RVA: 0x91A4D0
__int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rdi
  unsigned __int64 v2; // rbx
  unsigned __int64 v3; // r8
  char *v4; // rcx
  __int64 result; // rax
  char *v6; // rcx

  Data = this->Data;
  v2 = this->Data->Data.Size + 1;
  if ( v2 >= this->Data->Data.Size )
  {
    if ( v2 <= Data->Data.Policy.Capacity )
      goto LABEL_7;
    v3 = v2 + (v2 >> 2);
  }
  else
  {
    if ( v2 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v3 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->Data->Data,
    (__int64 *)this->Data->Data.pHeap,
    v3);
LABEL_7:
  v4 = Data->Data.Data;
  Data->Data.Size = v2;
  result = 1i64;
  v6 = &v4[v2 - 1];
  if ( v6 )
    *v6 = 15;
  return result;
}

// File Line: 798
// RVA: 0x9A60C0
__int64 __fastcall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
        Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        int *v)
{
  char *Data; // r11
  int v4; // r9d
  int v5; // r9d
  __int64 result; // rax
  int v7; // edx

  Data = this->Data->Data.Data;
  v4 = Data[pos] >> 2;
  if ( (Data[pos] & 3) != 0 )
  {
    v5 = v4 & 0x3F;
    if ( (Data[pos] & 3) == 1 )
    {
      *v = v5 | (Data[pos + 1] << 6);
      return 2i64;
    }
    else
    {
      if ( (Data[pos] & 3) == 2 )
      {
        result = 3i64;
        v7 = v5 | (((unsigned __int8)Data[pos + 1] | (Data[pos + 2] << 8)) << 6);
      }
      else
      {
        result = 4i64;
        v7 = v5 | (((unsigned __int8)Data[pos + 1] | (((unsigned __int8)Data[pos + 2] | (Data[pos + 3] << 8)) << 8)) << 6);
      }
      *v = v7;
    }
  }
  else
  {
    *v = v4;
    return 1i64;
  }
  return result;
}

// File Line: 827
// RVA: 0x9A4760
__int64 __fastcall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        int *data)
{
  __int64 v3; // r9
  char *v4; // r11
  __int64 v5; // rdx
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // r8
  __int64 v9; // rax
  int v10; // ebx
  __int64 v11; // r9
  unsigned __int8 v12; // cl
  unsigned int v13; // eax
  __int64 result; // rax
  int v15; // ecx
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // edx
  int v21; // r8d
  unsigned int v22; // r8d
  int v23; // eax
  int v24; // ecx
  unsigned int v25; // r8d
  int v26; // eax
  int v27; // ecx
  unsigned int v28; // r8d
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  unsigned int v33; // r8d
  int v34; // edx
  unsigned int v35; // r8d
  unsigned int v36; // r9d
  int v37; // eax
  unsigned int v38; // r8d
  int v39; // ecx
  int v40; // eax
  unsigned int v41; // r8d
  unsigned int v42; // edx
  int v43; // ecx
  int v44; // r8d
  char v45; // al
  int v46; // ecx
  int v47; // eax
  int v48; // ecx
  unsigned int v49; // r8d
  unsigned int v50; // r9d
  unsigned __int8 v51; // cl
  unsigned int v52; // edx
  char v53; // al
  int v54; // ecx
  int v55; // eax
  int v56; // ecx
  unsigned int v57; // r8d
  unsigned int v58; // r9d
  unsigned __int8 v59; // cl
  unsigned int v60; // edx
  char v61; // al
  int v62; // ecx
  int v63; // eax
  int v64; // ecx
  unsigned int v65; // r8d
  unsigned int v66; // r9d
  unsigned __int8 v67; // cl
  unsigned int v68; // edx
  char v69; // al
  int v70; // ecx
  int v71; // eax
  int v72; // ecx
  unsigned int v73; // r8d
  unsigned int v74; // r9d
  unsigned __int8 v75; // cl
  unsigned int v76; // edx
  unsigned __int8 v77; // al
  int v78; // ecx
  int v79; // eax
  int v80; // ecx
  char v81; // [rsp+0h] [rbp-10h]
  unsigned __int8 v82; // [rsp+1h] [rbp-Fh] BYREF
  unsigned __int8 v83; // [rsp+2h] [rbp-Eh]
  unsigned __int8 v84; // [rsp+3h] [rbp-Dh]
  unsigned __int8 v85; // [rsp+4h] [rbp-Ch]
  unsigned __int8 v86; // [rsp+5h] [rbp-Bh]
  unsigned __int8 v87; // [rsp+6h] [rbp-Ah]
  unsigned __int8 v88; // [rsp+7h] [rbp-9h]
  unsigned __int8 v89; // [rsp+8h] [rbp-8h]
  unsigned __int8 v90; // [rsp+9h] [rbp-7h]
  unsigned __int8 v91; // [rsp+Ah] [rbp-6h]
  unsigned __int8 v92; // [rsp+Bh] [rbp-5h]
  unsigned __int8 v93; // [rsp+Ch] [rbp-4h]
  unsigned __int8 v94; // [rsp+Dh] [rbp-3h]
  unsigned __int8 v95; // [rsp+Eh] [rbp-2h]
  char v96; // [rsp+Fh] [rbp-1h]

  v3 = pos;
  v4 = this->Data->Data.Data;
  v5 = pos + 1;
  v8 = &v82;
  v81 = v4[v3];
  v7 = v81;
  v9 = v81 & 0xF;
  v10 = (unsigned __int8)Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v9];
  if ( Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v9] )
  {
    v11 = (unsigned __int8)Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v9];
    do
    {
      v12 = v4[v5];
      ++v8;
      v5 = (unsigned int)(v5 + 1);
      *(v8 - 1) = v12;
      --v11;
    }
    while ( v11 );
    v7 = v81;
  }
  v13 = v7;
  switch ( v7 & 0xF )
  {
    case 0:
      *data = 0;
      goto LABEL_7;
    case 1:
      v15 = (char)v83;
      v16 = (char)v84 << 8;
      *data = 0;
      v17 = (v13 >> 4) | (16 * (v82 | ((v15 | v16) << 8)));
      result = (unsigned int)(v10 + 1);
      data[1] = v17;
      return result;
    case 2:
      *data = 1;
LABEL_7:
      data[1] = (16 * (char)v82) | (v7 >> 4);
      return (unsigned int)(v10 + 1);
    case 3:
      v18 = (char)v83;
      v19 = (char)v84 << 8;
      *data = 1;
      v20 = (v13 >> 4) | (16 * (v82 | ((v18 | v19) << 8)));
      result = (unsigned int)(v10 + 1);
      data[1] = v20;
      return result;
    case 4:
      v21 = (char)v82;
      *data = 2;
      data[1] = ((char)((_BYTE)v21 << 6) | (v7 >> 2)) >> 2;
      data[2] = v21 >> 2;
      return (unsigned int)(v10 + 1);
    case 5:
      v22 = v82;
      *data = 2;
      v23 = 4 * (char)v83;
      data[1] = (v7 >> 4) | (4 * (char)(4 * v22));
      v24 = v23 | (v22 >> 6);
      result = (unsigned int)(v10 + 1);
      data[2] = v24;
      return result;
    case 6:
      v25 = v83;
      *data = 2;
      v26 = (char)v84 << 6;
      data[1] = (v7 >> 4) | (16 * (v82 | (4 * (char)((_BYTE)v25 << 6))));
      v27 = v26 | (v25 >> 2);
      result = (unsigned int)(v10 + 1);
      data[2] = v27;
      return result;
    case 7:
      v28 = v85;
      *data = 2;
      v29 = (v7 >> 4) | (16 * (v82 | ((v83 | ((v84 | (4 * (char)((_BYTE)v28 << 6))) << 8)) << 8)));
      v30 = v87 | ((char)v88 << 8);
      v31 = v86;
      data[1] = v29;
      v32 = (v28 >> 2) | ((v31 | (v30 << 8)) << 6);
      result = (unsigned int)(v10 + 1);
      data[2] = v32;
      return result;
    case 8:
      v33 = v82;
      *data = 3;
      v34 = (char)v83;
      data[1] = ((char)((_BYTE)v33 << 7) | (v7 >> 1)) >> 3;
      data[2] = (char)(4 * v33) >> 3;
      data[4] = v34 >> 3;
      result = (unsigned int)(v10 + 1);
      data[3] = (int)((char)(32 * v34) | (v33 >> 3)) >> 3;
      return result;
    case 9:
      v35 = v82;
      *data = 3;
      v36 = v35 >> 2;
      v37 = ((char)(32 * v35) | (v7 >> 3)) >> 1;
      v38 = v83;
      data[1] = v37;
      v39 = (char)(v84 << 7);
      v40 = (char)v84;
      data[2] = (int)((char)((_BYTE)v38 << 6) | v36) >> 1;
      data[4] = v40 >> 1;
      result = (unsigned int)(v10 + 1);
      data[3] = (int)(v39 | (v38 >> 1)) >> 1;
      return result;
    case 0xA:
      v41 = v82;
      *data = 3;
      data[1] = (v7 >> 4) | (2 * (char)(8 * v41));
      v42 = v84;
      v43 = (v41 >> 5) | (2 * (char)(4 * v83));
      v44 = v83 >> 6;
      v45 = 2 * v84;
      data[2] = v43;
      v46 = v45;
      v47 = 2 * (char)v85;
      data[3] = (2 * v46) | v44;
      v48 = v47 | (v42 >> 7);
      result = (unsigned int)(v10 + 1);
      data[4] = v48;
      return result;
    case 0xB:
      v49 = v82;
      v50 = v84;
      v51 = v82;
      *data = 3;
      data[1] = (v13 >> 4) | (8 * (char)(2 * v51));
      v52 = v85;
      v53 = 8 * v85;
      data[2] = (v49 >> 7) | (2 * (v83 | (4 * (char)((_BYTE)v50 << 6))));
      v54 = (v50 >> 2) | (8 * v53);
      v55 = (char)v86;
      data[3] = v54;
      v56 = (8 * v55) | (v52 >> 5);
      result = (unsigned int)(v10 + 1);
      data[4] = v56;
      return result;
    case 0xC:
      v57 = v83;
      v58 = v84;
      v59 = v83;
      *data = 3;
      data[1] = (v13 >> 4) | (16 * (v82 | (2 * (char)(v59 << 7))));
      v60 = v86;
      v61 = 32 * v86;
      data[2] = (v57 >> 1) | (32 * (char)(4 * v58));
      v62 = (v58 >> 6) | (4 * (v85 | (8 * v61)));
      v63 = (char)v87;
      data[3] = v62;
      v64 = (32 * v63) | (v60 >> 3);
      result = (unsigned int)(v10 + 1);
      data[4] = v64;
      return result;
    case 0xD:
      v65 = v83;
      v66 = v85;
      v67 = v83;
      *data = 3;
      data[1] = (v13 >> 4) | (16 * (v82 | (8 * (char)(32 * v67))));
      v68 = v87;
      v69 = v87 << 7;
      data[2] = (v65 >> 3) | (32 * (v84 | (4 * (char)((_BYTE)v66 << 6))));
      v70 = (v66 >> 2) | ((v86 | (2 * v69)) << 6);
      v71 = (char)v88;
      data[3] = v70;
      v72 = (v71 << 7) | (v68 >> 1);
      result = (unsigned int)(v10 + 1);
      data[4] = v72;
      return result;
    case 0xE:
      v73 = v85;
      v74 = v89;
      v75 = v85;
      *data = 3;
      data[1] = (v13 >> 4) | (16 * (v82 | ((v83 | ((v84 | (8 * (char)(32 * v75))) << 8)) << 8)));
      v76 = v93;
      v77 = v93;
      data[2] = (v73 >> 3) | (32 * (v86 | ((v87 | ((v88 | (4 * (char)((_BYTE)v74 << 6))) << 8)) << 8)));
      v78 = (v74 >> 2) | ((v90 | ((v91 | ((v92 | (2 * (char)(v77 << 7))) << 8)) << 8)) << 6);
      v79 = v95;
      data[3] = v78;
      v80 = (v76 >> 1) | ((v94 | ((v79 | (v96 << 8)) << 8)) << 7);
      result = (unsigned int)(v10 + 1);
      data[4] = v80;
      return result;
    case 0xF:
      *data = 4;
      return (unsigned int)(v10 + 1);
    default:
      return (unsigned int)(v10 + 1);
  }
}

