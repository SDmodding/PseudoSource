// File Line: 323
// RVA: 0x9C30C0
void __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, float v)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> **v3; // rsi
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  char *v6; // rcx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v7; // rbx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  bool *v10; // rcx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v11; // rbx
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // r8
  bool *v14; // rcx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v15; // rbx
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  bool *v18; // rcx
  float v19; // [rsp+38h] [rbp+10h]

  v19 = v;
  v2 = this->Data;
  v3 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> **)this;
  v4 = this->Data->Data.Size + 1;
  if ( v4 >= this->Data->Data.Size )
  {
    if ( v4 <= v2->Data.Policy.Capacity )
      goto LABEL_7;
    v5 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= v2->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v5 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v5);
LABEL_7:
  v6 = v2->Data.Data;
  v2->Data.Size = v4;
  v6[v4 - 1] = LOBYTE(v);
  v7 = *v3;
  v8 = (*v3)->Size + 1;
  if ( v8 >= (*v3)->Size )
  {
    if ( v8 <= v7->Policy.Capacity )
      goto LABEL_13;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= v7->Policy.Capacity >> 1 )
      goto LABEL_13;
    v9 = (*v3)->Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(*v3, *v3, v9);
LABEL_13:
  v10 = v7->Data;
  v7->Size = v8;
  v10[v8 - 1] = BYTE1(v19);
  v11 = *v3;
  v12 = (*v3)->Size + 1;
  if ( v12 >= (*v3)->Size )
  {
    if ( v12 <= v11->Policy.Capacity )
      goto LABEL_19;
    v13 = v12 + (v12 >> 2);
  }
  else
  {
    if ( v12 >= v11->Policy.Capacity >> 1 )
      goto LABEL_19;
    v13 = (*v3)->Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(*v3, *v3, v13);
LABEL_19:
  v14 = v11->Data;
  v11->Size = v12;
  v14[v12 - 1] = BYTE2(v);
  v15 = *v3;
  v16 = (*v3)->Size + 1;
  if ( v16 >= (*v3)->Size )
  {
    if ( v16 > v15->Policy.Capacity )
    {
      v17 = v16 + (v16 >> 2);
      goto LABEL_24;
    }
  }
  else if ( v16 < v15->Policy.Capacity >> 1 )
  {
    v17 = (*v3)->Size + 1;
LABEL_24:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(*v3, *v3, v17);
    goto LABEL_25;
  }
LABEL_25:
  v18 = v15->Data;
  v15->Size = v16;
  v18[v16 - 1] = HIBYTE(v);
}

// File Line: 381
// RVA: 0x91C420
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int v)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  unsigned int v3; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v4; // r14
  unsigned __int64 v5; // rbx
  char v6; // si
  unsigned __int64 v7; // r8
  char *v8; // rcx
  char *v9; // rcx
  char v11; // bp
  unsigned __int64 v12; // r8
  char *v13; // rcx
  char *v14; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v15; // rdi
  unsigned int v16; // esi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8
  char *v19; // rcx
  char *v20; // rcx

  v2 = this->Data;
  v3 = v;
  v4 = this;
  v5 = this->Data->Data.Size + 1;
  if ( v <= 0x7F )
  {
    v6 = 2 * v;
    if ( v5 >= v2->Data.Size )
    {
      if ( v5 > v2->Data.Policy.Capacity )
      {
        v7 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < v2->Data.Policy.Capacity >> 1 )
    {
      v7 = this->Data->Data.Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
        v2->Data.pHeap,
        v7);
      goto LABEL_8;
    }
LABEL_8:
    v8 = v2->Data.Data;
    v2->Data.Size = v5;
    v9 = &v8[v5 - 1];
    if ( v9 )
      *v9 = v6;
    return 1i64;
  }
  v11 = 2 * v | 1;
  if ( v5 >= v2->Data.Size )
  {
    if ( v5 <= v2->Data.Policy.Capacity )
      goto LABEL_17;
    v12 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= v2->Data.Policy.Capacity >> 1 )
      goto LABEL_17;
    v12 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
    v2->Data.pHeap,
    v12);
LABEL_17:
  v13 = v2->Data.Data;
  v2->Data.Size = v5;
  v14 = &v13[v5 - 1];
  if ( v14 )
    *v14 = v11;
  v15 = (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Data->Data.Data;
  v16 = v3 >> 7;
  v17 = v4->Data->Data.Size + 1;
  if ( v17 >= v4->Data->Data.Size )
  {
    if ( v17 > v15->Policy.Capacity )
    {
      v18 = v17 + (v17 >> 2);
      goto LABEL_24;
    }
  }
  else if ( v17 < v15->Policy.Capacity >> 1 )
  {
    v18 = v4->Data->Data.Size + 1;
LABEL_24:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v15,
      v4->Data->Data.pHeap,
      v18);
    goto LABEL_25;
  }
LABEL_25:
  v19 = v15->Data;
  v15->Size = v17;
  v20 = &v19[v17 - 1];
  if ( v20 )
    *v20 = v16;
  return 2i64;
}

// File Line: 409
// RVA: 0x9C5030
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int v)
{
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  unsigned int v3; // ebx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v4; // r14
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
  unsigned int v36; // ebp
  unsigned __int64 v37; // rsi
  unsigned __int64 v38; // r8
  bool *v39; // rax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v40; // rdi
  unsigned int v41; // ebp
  unsigned __int64 v42; // rsi
  unsigned __int64 v43; // r8
  bool *v44; // rax
  unsigned int v45; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v46; // rdi
  unsigned __int64 v47; // rsi
  unsigned __int64 v48; // r8
  bool *v49; // rax

  v2 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v3 = v;
  v4 = this;
  v5 = this->Data->Data.Size + 1;
  if ( v <= 0x3F )
  {
    v6 = 4 * v;
    if ( v5 >= v2->Size )
    {
      if ( v5 > v2->Policy.Capacity )
      {
        v7 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < v2->Policy.Capacity >> 1 )
    {
      v7 = this->Data->Data.Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v2, v2, v7);
      goto LABEL_8;
    }
LABEL_8:
    v8 = v2->Data;
    v2->Size = v5;
    v8[v5 - 1] = v6;
    return 1i64;
  }
  v10 = 4 * v;
  if ( v <= 0x3FFF )
  {
    v11 = v10 | 1;
    if ( v5 >= v2->Size )
    {
      if ( v5 <= v2->Policy.Capacity )
        goto LABEL_16;
      v12 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= v2->Policy.Capacity >> 1 )
        goto LABEL_16;
      v12 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v2, v2, v12);
LABEL_16:
    v13 = v2->Data;
    v2->Size = v5;
    v14 = v3 >> 6;
    v13[v5 - 1] = v11;
    v15 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4->Data;
    v16 = v4->Data->Data.Size + 1;
    if ( v16 >= v4->Data->Data.Size )
    {
      if ( v16 > v15->Policy.Capacity )
      {
        v17 = v16 + (v16 >> 2);
        goto LABEL_21;
      }
    }
    else if ( v16 < v15->Policy.Capacity >> 1 )
    {
      v17 = v4->Data->Data.Size + 1;
LABEL_21:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v15,
        v15,
        v17);
      goto LABEL_22;
    }
LABEL_22:
    v18 = v15->Data;
    v15->Size = v16;
    v18[v16 - 1] = v14;
    return 2i64;
  }
  if ( v <= 0x3FFFFF )
  {
    v19 = v10 | 2;
    if ( v5 >= v2->Size )
    {
      if ( v5 <= v2->Policy.Capacity )
        goto LABEL_30;
      v20 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= v2->Policy.Capacity >> 1 )
        goto LABEL_30;
      v20 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v2, v2, v20);
LABEL_30:
    v21 = v2->Data;
    v2->Size = v5;
    v21[v5 - 1] = v19;
    v22 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4->Data;
    v23 = v3 >> 6;
    v24 = v4->Data->Data.Size + 1;
    if ( v24 >= v4->Data->Data.Size )
    {
      if ( v24 <= v22->Policy.Capacity )
        goto LABEL_36;
      v25 = v24 + (v24 >> 2);
    }
    else
    {
      if ( v24 >= v22->Policy.Capacity >> 1 )
        goto LABEL_36;
      v25 = v4->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v22, v22, v25);
LABEL_36:
    v26 = v22->Data;
    v22->Size = v24;
    v27 = v3 >> 14;
    v26[v24 - 1] = v23;
    v28 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4->Data;
    v29 = v4->Data->Data.Size + 1;
    if ( v29 >= v4->Data->Data.Size )
    {
      if ( v29 > v28->Policy.Capacity )
      {
        v30 = v29 + (v29 >> 2);
        goto LABEL_41;
      }
    }
    else if ( v29 < v28->Policy.Capacity >> 1 )
    {
      v30 = v4->Data->Data.Size + 1;
LABEL_41:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v28,
        v28,
        v30);
      goto LABEL_42;
    }
LABEL_42:
    v31 = v28->Data;
    v28->Size = v29;
    v31[v29 - 1] = v27;
    return 3i64;
  }
  v32 = v10 | 3;
  if ( v5 >= v2->Size )
  {
    if ( v5 <= v2->Policy.Capacity )
      goto LABEL_49;
    v33 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= v2->Policy.Capacity >> 1 )
      goto LABEL_49;
    v33 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v2, v2, v33);
LABEL_49:
  v34 = v2->Data;
  v2->Size = v5;
  v34[v5 - 1] = v32;
  v35 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4->Data;
  v36 = v3 >> 6;
  v37 = v4->Data->Data.Size + 1;
  if ( v37 >= v4->Data->Data.Size )
  {
    if ( v37 <= v35->Policy.Capacity )
      goto LABEL_55;
    v38 = v37 + (v37 >> 2);
  }
  else
  {
    if ( v37 >= v35->Policy.Capacity >> 1 )
      goto LABEL_55;
    v38 = v4->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v35, v35, v38);
LABEL_55:
  v39 = v35->Data;
  v35->Size = v37;
  v39[v37 - 1] = v36;
  v40 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4->Data;
  v41 = v3 >> 14;
  v42 = v4->Data->Data.Size + 1;
  if ( v42 >= v4->Data->Data.Size )
  {
    if ( v42 <= v40->Policy.Capacity )
      goto LABEL_61;
    v43 = v42 + (v42 >> 2);
  }
  else
  {
    if ( v42 >= v40->Policy.Capacity >> 1 )
      goto LABEL_61;
    v43 = v4->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v40, v40, v43);
LABEL_61:
  v44 = v40->Data;
  v40->Size = v42;
  v45 = v3 >> 22;
  v44[v42 - 1] = v41;
  v46 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4->Data;
  v47 = v4->Data->Data.Size + 1;
  if ( v47 >= v4->Data->Data.Size )
  {
    if ( v47 > v46->Policy.Capacity )
    {
      v48 = v47 + (v47 >> 2);
      goto LABEL_66;
    }
  }
  else if ( v47 < v46->Policy.Capacity >> 1 )
  {
    v48 = v4->Data->Data.Size + 1;
LABEL_66:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v46, v46, v48);
    goto LABEL_67;
  }
LABEL_67:
  v49 = v46->Data;
  v46->Size = v47;
  v49[v47 - 1] = v45;
  return 4i64;
}4->Data->Data.Size + 1;
LABEL_66:
    Scaleform::ArrayDataBa

// File Line: 439
// RVA: 0x91C070
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, int v)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rsi
  int v3; // ebx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **v4; // r14
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
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v16; // rsi
  int v17; // ebx
  unsigned __int64 v18; // rdi
  unsigned __int64 v19; // r8
  char *v20; // rcx
  char *v21; // rcx
  unsigned int v22; // eax
  Scaleform::MemoryHeap *v23; // rdx
  char v24; // bp
  unsigned __int64 v25; // r8
  char *v26; // rcx
  char *v27; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v28; // rsi
  int v29; // ebp
  unsigned __int64 v30; // rdi
  unsigned __int64 v31; // r8
  char *v32; // rcx
  char *v33; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v34; // rsi
  int v35; // ebx
  unsigned __int64 v36; // rdi
  unsigned __int64 v37; // r8
  char *v38; // rcx
  char *v39; // rcx
  char v40; // bp
  unsigned __int64 v41; // r8
  char *v42; // rcx
  char *v43; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v44; // rsi
  int v45; // ebp
  unsigned __int64 v46; // rdi
  unsigned __int64 v47; // r8
  char *v48; // rcx
  char *v49; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v50; // rsi
  int v51; // ebp
  unsigned __int64 v52; // rdi
  unsigned __int64 v53; // r8
  char *v54; // rcx
  char *v55; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v56; // rsi
  int v57; // ebx
  unsigned __int64 v58; // rdi
  unsigned __int64 v59; // r8
  char *v60; // rcx
  char *v61; // rcx

  v2 = this->Data;
  v3 = v;
  v4 = (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **)this;
  v5 = this->Data->Data.Size + 1;
  if ( (unsigned int)(v + 32) <= 0x3F )
  {
    v6 = 4 * v;
    if ( v5 >= v2->Data.Size )
    {
      if ( v5 > v2->Data.Policy.Capacity )
      {
        v7 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < v2->Data.Policy.Capacity >> 1 )
    {
      v7 = this->Data->Data.Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
        v2->Data.pHeap,
        v7);
      goto LABEL_8;
    }
LABEL_8:
    v8 = v2->Data.Data;
    v2->Data.Size = v5;
    v9 = &v8[v5 - 1];
    if ( v9 )
      *v9 = v6;
    return 1i64;
  }
  v11 = 4 * v;
  if ( (unsigned int)(v + 0x2000) <= 0x3FFF )
  {
    v12 = v11 | 1;
    if ( v5 >= v2->Data.Size )
    {
      if ( v5 <= v2->Data.Policy.Capacity )
        goto LABEL_18;
      v13 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= v2->Data.Policy.Capacity >> 1 )
        goto LABEL_18;
      v13 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
      v2->Data.pHeap,
      v13);
LABEL_18:
    v14 = v2->Data.Data;
    v2->Data.Size = v5;
    v15 = &v14[v5 - 1];
    if ( v15 )
      *v15 = v12;
    v16 = *v4;
    v17 = v3 >> 6;
    v18 = (*v4)->Size + 1;
    if ( v18 >= (*v4)->Size )
    {
      if ( v18 > v16->Policy.Capacity )
      {
        v19 = v18 + (v18 >> 2);
        goto LABEL_25;
      }
    }
    else if ( v18 < v16->Policy.Capacity >> 1 )
    {
      v19 = (*v4)->Size + 1;
LABEL_25:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v4,
        (*v4)[1].Data,
        v19);
      goto LABEL_26;
    }
LABEL_26:
    v20 = v16->Data;
    v16->Size = v18;
    v21 = &v20[v18 - 1];
    if ( v21 )
      *v21 = v17;
    return 2i64;
  }
  v22 = v + 0x200000;
  v23 = v2->Data.pHeap;
  if ( v22 <= 0x3FFFFF )
  {
    v24 = v11 | 2;
    if ( v5 >= v2->Data.Size )
    {
      if ( v5 <= v2->Data.Policy.Capacity )
        goto LABEL_36;
      v25 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= v2->Data.Policy.Capacity >> 1 )
        goto LABEL_36;
      v25 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
      v23,
      v25);
LABEL_36:
    v26 = v2->Data.Data;
    v2->Data.Size = v5;
    v27 = &v26[v5 - 1];
    if ( v27 )
      *v27 = v24;
    v28 = *v4;
    v29 = v3 >> 6;
    v30 = (*v4)->Size + 1;
    if ( v30 >= (*v4)->Size )
    {
      if ( v30 <= v28->Policy.Capacity )
        goto LABEL_44;
      v31 = v30 + (v30 >> 2);
    }
    else
    {
      if ( v30 >= v28->Policy.Capacity >> 1 )
        goto LABEL_44;
      v31 = (*v4)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v4,
      (*v4)[1].Data,
      v31);
LABEL_44:
    v32 = v28->Data;
    v28->Size = v30;
    v33 = &v32[v30 - 1];
    if ( v33 )
      *v33 = v29;
    v34 = *v4;
    v35 = v3 >> 14;
    v36 = (*v4)->Size + 1;
    if ( v36 >= (*v4)->Size )
    {
      if ( v36 > v34->Policy.Capacity )
      {
        v37 = v36 + (v36 >> 2);
        goto LABEL_51;
      }
    }
    else if ( v36 < v34->Policy.Capacity >> 1 )
    {
      v37 = (*v4)->Size + 1;
LABEL_51:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v4,
        (*v4)[1].Data,
        v37);
      goto LABEL_52;
    }
LABEL_52:
    v38 = v34->Data;
    v34->Size = v36;
    v39 = &v38[v36 - 1];
    if ( v39 )
      *v39 = v35;
    return 3i64;
  }
  v40 = v11 | 3;
  if ( v5 >= v2->Data.Size )
  {
    if ( v5 <= v2->Data.Policy.Capacity )
      goto LABEL_61;
    v41 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= v2->Data.Policy.Capacity >> 1 )
      goto LABEL_61;
    v41 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
    v23,
    v41);
LABEL_61:
  v42 = v2->Data.Data;
  v2->Data.Size = v5;
  v43 = &v42[v5 - 1];
  if ( v43 )
    *v43 = v40;
  v44 = *v4;
  v45 = v3 >> 6;
  v46 = (*v4)->Size + 1;
  if ( v46 >= (*v4)->Size )
  {
    if ( v46 <= v44->Policy.Capacity )
      goto LABEL_69;
    v47 = v46 + (v46 >> 2);
  }
  else
  {
    if ( v46 >= v44->Policy.Capacity >> 1 )
      goto LABEL_69;
    v47 = (*v4)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v4,
    (*v4)[1].Data,
    v47);
LABEL_69:
  v48 = v44->Data;
  v44->Size = v46;
  v49 = &v48[v46 - 1];
  if ( v49 )
    *v49 = v45;
  v50 = *v4;
  v51 = v3 >> 14;
  v52 = (*v4)->Size + 1;
  if ( v52 >= (*v4)->Size )
  {
    if ( v52 <= v50->Policy.Capacity )
      goto LABEL_77;
    v53 = v52 + (v52 >> 2);
  }
  else
  {
    if ( v52 >= v50->Policy.Capacity >> 1 )
      goto LABEL_77;
    v53 = (*v4)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v4,
    (*v4)[1].Data,
    v53);
LABEL_77:
  v54 = v50->Data;
  v50->Size = v52;
  v55 = &v54[v52 - 1];
  if ( v55 )
    *v55 = v51;
  v56 = *v4;
  v57 = v3 >> 22;
  v58 = (*v4)->Size + 1;
  if ( v58 >= (*v4)->Size )
  {
    if ( v58 > v56->Policy.Capacity )
    {
      v59 = v58 + (v58 >> 2);
      goto LABEL_84;
    }
  }
  else if ( v58 < v56->Policy.Capacity >> 1 )
  {
    v59 = (*v4)->Size + 1;
LABEL_84:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v4,
      (*v4)[1].Data,
      v59);
    goto LABEL_85;
  }
LABEL_85:
  v60 = v56->Data;
  v56->Size = v58;
  v61 = &v60[v58 - 1];
  if ( v61 )
    *v61 = v57;
  return 4i64;
}

// File Line: 468
// RVA: 0x9C3220
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, int x)
{
  int v2; // esi
  char v3; // bp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> **v4; // r14
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  char *v8; // rax
  int v9; // esi
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v10; // rbx
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  bool *v13; // rax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v15; // rbx
  char v16; // bp
  unsigned __int64 v17; // rdi
  unsigned __int64 v18; // r8
  char *v19; // rax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v20; // rbx
  int v21; // ebp
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // r8
  bool *v24; // rax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v25; // rbx
  int v26; // ebp
  unsigned __int64 v27; // rdi
  unsigned __int64 v28; // r8
  bool *v29; // rax
  int v30; // esi
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v31; // rbx
  unsigned __int64 v32; // rdi
  unsigned __int64 v33; // r8
  bool *v34; // rax

  v2 = x;
  v3 = 16 * x;
  v4 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> **)this;
  if ( (unsigned int)(x + 2048) <= 0xFFF )
  {
    v5 = this->Data;
    v6 = this->Data->Data.Size + 1;
    if ( v6 >= this->Data->Data.Size )
    {
      if ( v6 <= v5->Data.Policy.Capacity )
        goto LABEL_8;
      v7 = v6 + (v6 >> 2);
    }
    else
    {
      if ( v6 >= v5->Data.Policy.Capacity >> 1 )
        goto LABEL_8;
      v7 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
      this->Data,
      v7);
LABEL_8:
    v8 = v5->Data.Data;
    v5->Data.Size = v6;
    v9 = v2 >> 4;
    v8[v6 - 1] = v3;
    v10 = *v4;
    v11 = (*v4)->Size + 1;
    if ( v11 >= (*v4)->Size )
    {
      if ( v11 > v10->Policy.Capacity )
      {
        v12 = v11 + (v11 >> 2);
        goto LABEL_13;
      }
    }
    else if ( v11 < v10->Policy.Capacity >> 1 )
    {
      v12 = (*v4)->Size + 1;
LABEL_13:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v4,
        *v4,
        v12);
      goto LABEL_14;
    }
LABEL_14:
    v13 = v10->Data;
    v10->Size = v11;
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
  v20 = *v4;
  v21 = v2 >> 4;
  v22 = (*v4)->Size + 1;
  if ( v22 >= (*v4)->Size )
  {
    if ( v22 <= v20->Policy.Capacity )
      goto LABEL_27;
    v23 = v22 + (v22 >> 2);
  }
  else
  {
    if ( v22 >= v20->Policy.Capacity >> 1 )
      goto LABEL_27;
    v23 = (*v4)->Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(*v4, *v4, v23);
LABEL_27:
  v24 = v20->Data;
  v20->Size = v22;
  v24[v22 - 1] = v21;
  v25 = *v4;
  v26 = v2 >> 12;
  v27 = (*v4)->Size + 1;
  if ( v27 >= (*v4)->Size )
  {
    if ( v27 <= v25->Policy.Capacity )
      goto LABEL_33;
    v28 = v27 + (v27 >> 2);
  }
  else
  {
    if ( v27 >= v25->Policy.Capacity >> 1 )
      goto LABEL_33;
    v28 = (*v4)->Size + 1;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(*v4, *v4, v28);
LABEL_33:
  v29 = v25->Data;
  v25->Size = v27;
  v30 = v2 >> 20;
  v29[v27 - 1] = v26;
  v31 = *v4;
  v32 = (*v4)->Size + 1;
  if ( v32 >= (*v4)->Size )
  {
    if ( v32 > v31->Policy.Capacity )
    {
      v33 = v32 + (v32 >> 2);
      goto LABEL_38;
    }
  }
  else if ( v32 < v31->Policy.Capacity >> 1 )
  {
    v33 = (*v4)->Size + 1;
LABEL_38:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(*v4, *v4, v33);
    goto LABEL_39;
  }
LABEL_39:
  v34 = v31->Data;
  v31->Size = v32;
  v34[v32 - 1] = v30;
  return 3i64;
}

// File Line: 485
// RVA: 0x91CA00
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, int y)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  unsigned int v3; // eax
  char v4; // bp
  int v5; // esi
  Scaleform::MemoryHeap *v6; // rdx
  unsigned __int64 v7; // rbx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **v8; // r14
  char v9; // bp
  unsigned __int64 v10; // r8
  char *v11; // rcx
  char *v12; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v13; // rdi
  int v14; // esi
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // r8
  char *v17; // rcx
  char *v18; // rcx
  char v20; // bp
  unsigned __int64 v21; // r8
  char *v22; // rcx
  char *v23; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v24; // rdi
  int v25; // ebp
  unsigned __int64 v26; // rbx
  unsigned __int64 v27; // r8
  char *v28; // rcx
  char *v29; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v30; // rdi
  int v31; // ebp
  unsigned __int64 v32; // rbx
  unsigned __int64 v33; // r8
  char *v34; // rcx
  char *v35; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v36; // rdi
  int v37; // esi
  unsigned __int64 v38; // rbx
  unsigned __int64 v39; // r8
  char *v40; // rcx
  char *v41; // rcx

  v2 = this->Data;
  v3 = y + 2048;
  v4 = 16 * y;
  v5 = y;
  v6 = this->Data->Data.pHeap;
  v7 = this->Data->Data.Size + 1;
  v8 = (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **)this;
  if ( v3 <= 0xFFF )
  {
    v9 = v4 | 2;
    if ( v7 >= v2->Data.Size )
    {
      if ( v7 <= v2->Data.Policy.Capacity )
        goto LABEL_8;
      v10 = v7 + (v7 >> 2);
    }
    else
    {
      if ( v7 >= v2->Data.Policy.Capacity >> 1 )
        goto LABEL_8;
      v10 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
      v6,
      v10);
LABEL_8:
    v11 = v2->Data.Data;
    v2->Data.Size = v7;
    v12 = &v11[v7 - 1];
    if ( v12 )
      *v12 = v9;
    v13 = *v8;
    v14 = v5 >> 4;
    v15 = (*v8)->Size + 1;
    if ( v15 >= (*v8)->Size )
    {
      if ( v15 > v13->Policy.Capacity )
      {
        v16 = v15 + (v15 >> 2);
        goto LABEL_15;
      }
    }
    else if ( v15 < v13->Policy.Capacity >> 1 )
    {
      v16 = (*v8)->Size + 1;
LABEL_15:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v13,
        (*v8)[1].Data,
        v16);
      goto LABEL_16;
    }
LABEL_16:
    v17 = v13->Data;
    v13->Size = v15;
    v18 = &v17[v15 - 1];
    if ( v18 )
      *v18 = v14;
    return 2i64;
  }
  v20 = v4 | 3;
  if ( v7 >= v2->Data.Size )
  {
    if ( v7 <= v2->Data.Policy.Capacity )
      goto LABEL_25;
    v21 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= v2->Data.Policy.Capacity >> 1 )
      goto LABEL_25;
    v21 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
    v6,
    v21);
LABEL_25:
  v22 = v2->Data.Data;
  v2->Data.Size = v7;
  v23 = &v22[v7 - 1];
  if ( v23 )
    *v23 = v20;
  v24 = *v8;
  v25 = v5 >> 4;
  v26 = (*v8)->Size + 1;
  if ( v26 >= (*v8)->Size )
  {
    if ( v26 <= v24->Policy.Capacity )
      goto LABEL_33;
    v27 = v26 + (v26 >> 2);
  }
  else
  {
    if ( v26 >= v24->Policy.Capacity >> 1 )
      goto LABEL_33;
    v27 = (*v8)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v8,
    (*v8)[1].Data,
    v27);
LABEL_33:
  v28 = v24->Data;
  v24->Size = v26;
  v29 = &v28[v26 - 1];
  if ( v29 )
    *v29 = v25;
  v30 = *v8;
  v31 = v5 >> 12;
  v32 = (*v8)->Size + 1;
  if ( v32 >= (*v8)->Size )
  {
    if ( v32 <= v30->Policy.Capacity )
      goto LABEL_41;
    v33 = v32 + (v32 >> 2);
  }
  else
  {
    if ( v32 >= v30->Policy.Capacity >> 1 )
      goto LABEL_41;
    v33 = (*v8)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v8,
    (*v8)[1].Data,
    v33);
LABEL_41:
  v34 = v30->Data;
  v30->Size = v32;
  v35 = &v34[v32 - 1];
  if ( v35 )
    *v35 = v31;
  v36 = *v8;
  v37 = v5 >> 20;
  v38 = (*v8)->Size + 1;
  if ( v38 >= (*v8)->Size )
  {
    if ( v38 > v36->Policy.Capacity )
    {
      v39 = v38 + (v38 >> 2);
      goto LABEL_48;
    }
  }
  else if ( v38 < v36->Policy.Capacity >> 1 )
  {
    v39 = (*v8)->Size + 1;
LABEL_48:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v36,
      (*v8)[1].Data,
      v39);
    goto LABEL_49;
  }
LABEL_49:
  v40 = v36->Data;
  v36->Size = v38;
  v41 = &v40[v38 - 1];
  if ( v41 )
    *v41 = v37;
  return 3i64;
}

// File Line: 502
// RVA: 0x91A830
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, int x, int y)
{
  int v3; // esi
  int v4; // ebx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **v5; // r15
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // r14
  unsigned __int64 v7; // rdi
  char v8; // bp
  unsigned __int64 v9; // r8
  char *v10; // rcx
  char *v11; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v12; // rdi
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
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v25; // rdi
  char v26; // bp
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // r8
  char *v29; // rcx
  char *v30; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v31; // rdi
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
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v43; // r14
  int v44; // ebp
  unsigned __int64 v45; // rdi
  unsigned __int64 v46; // r8
  char *v47; // rcx
  char *v48; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v49; // rdi
  char v50; // bp
  unsigned __int64 v51; // rbx
  unsigned __int64 v52; // r8
  char *v53; // rcx
  char *v54; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v55; // rdi
  int v56; // esi
  unsigned __int64 v57; // rbx
  unsigned __int64 v58; // r8
  char *v59; // rcx
  char *v60; // rcx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v61; // r14
  unsigned __int64 v62; // rdi
  char v63; // bp
  unsigned __int64 v64; // r8
  char *v65; // rcx
  char *v66; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v67; // r14
  int v68; // ebp
  unsigned __int64 v69; // rdi
  unsigned __int64 v70; // r8
  char *v71; // rcx
  char *v72; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v73; // r14
  int v74; // ebp
  unsigned __int64 v75; // rdi
  unsigned __int64 v76; // r8
  char *v77; // rcx
  char *v78; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v79; // r14
  int v80; // ebp
  unsigned __int64 v81; // rdi
  unsigned __int64 v82; // r8
  char *v83; // rcx
  char *v84; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v85; // r14
  unsigned __int64 v86; // rdi
  char v87; // bl
  unsigned __int64 v88; // r8
  char *v89; // rcx
  char *v90; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v91; // rdi
  int v92; // ebp
  unsigned __int64 v93; // rbx
  unsigned __int64 v94; // r8
  char *v95; // rcx
  char *v96; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v97; // rdi
  int v98; // ebp
  unsigned __int64 v99; // rbx
  unsigned __int64 v100; // r8
  char *v101; // rcx
  char *v102; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v103; // rdi
  int v104; // esi
  unsigned __int64 v105; // rbx
  unsigned __int64 v106; // r8
  char *v107; // rcx
  char *v108; // rcx

  v3 = y;
  v4 = x;
  v5 = (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **)this;
  if ( (unsigned int)(x + 32) <= 0x3F && (unsigned int)(y + 32) <= 0x3F )
  {
    v6 = this->Data;
    v7 = this->Data->Data.Size + 1;
    v8 = 16 * x | 4;
    if ( v7 >= this->Data->Data.Size )
    {
      if ( v7 <= v6->Data.Policy.Capacity )
        goto LABEL_9;
      v9 = v7 + (v7 >> 2);
    }
    else
    {
      if ( v7 >= v6->Data.Policy.Capacity >> 1 )
        goto LABEL_9;
      v9 = this->Data->Data.Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
      this->Data->Data.pHeap,
      v9);
LABEL_9:
    v10 = v6->Data.Data;
    v6->Data.Size = v7;
    v11 = &v10[v7 - 1];
    if ( v11 )
      *v11 = v8;
    v12 = *v5;
    v13 = (v4 >> 4) & 3 | 4 * v3;
    v14 = (*v5)->Size + 1;
    if ( v14 >= (*v5)->Size )
    {
      if ( v14 > v12->Policy.Capacity )
      {
        v15 = v14 + (v14 >> 2);
        goto LABEL_16;
      }
    }
    else if ( v14 < v12->Policy.Capacity >> 1 )
    {
      v15 = (*v5)->Size + 1;
LABEL_16:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v12,
        (*v5)[1].Data,
        v15);
      goto LABEL_17;
    }
LABEL_17:
    v16 = v12->Data;
    v12->Size = v14;
    v17 = &v16[v14 - 1];
    if ( v17 )
      *v17 = v13;
    return 2i64;
  }
  if ( (unsigned int)(x + 512) <= 0x3FF && (unsigned int)(y + 512) <= 0x3FF )
  {
    v19 = this->Data;
    v20 = this->Data->Data.Size + 1;
    v21 = 16 * x | 5;
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
      (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
      this->Data->Data.pHeap,
      v22);
LABEL_28:
    v23 = v19->Data.Data;
    v19->Data.Size = v20;
    v24 = &v23[v20 - 1];
    if ( v24 )
      *v24 = v21;
    v25 = *v5;
    v26 = (v4 >> 4) & 0x3F | ((_BYTE)v3 << 6);
    v27 = (*v5)->Size + 1;
    if ( v27 >= (*v5)->Size )
    {
      if ( v27 <= v25->Policy.Capacity )
        goto LABEL_36;
      v28 = v27 + (v27 >> 2);
    }
    else
    {
      if ( v27 >= v25->Policy.Capacity >> 1 )
        goto LABEL_36;
      v28 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v28);
LABEL_36:
    v29 = v25->Data;
    v25->Size = v27;
    v30 = &v29[v27 - 1];
    if ( v30 )
      *v30 = v26;
    v31 = *v5;
    v32 = v3 >> 2;
    v33 = (*v5)->Size + 1;
    if ( v33 >= (*v5)->Size )
    {
      if ( v33 > v31->Policy.Capacity )
      {
        v34 = v33 + (v33 >> 2);
        goto LABEL_43;
      }
    }
    else if ( v33 < v31->Policy.Capacity >> 1 )
    {
      v34 = (*v5)->Size + 1;
LABEL_43:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v31,
        (*v5)[1].Data,
        v34);
      goto LABEL_44;
    }
LABEL_44:
    v35 = v31->Data;
    v31->Size = v33;
    v36 = &v35[v33 - 1];
    if ( v36 )
      *v36 = v32;
    return 3i64;
  }
  if ( (unsigned int)(x + 0x2000) <= 0x3FFF && (unsigned int)(y + 0x2000) <= 0x3FFF )
  {
    v37 = this->Data;
    v38 = this->Data->Data.Size + 1;
    v39 = 16 * x | 6;
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
      (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
      this->Data->Data.pHeap,
      v40);
LABEL_55:
    v41 = v37->Data.Data;
    v37->Data.Size = v38;
    v42 = &v41[v38 - 1];
    if ( v42 )
      *v42 = v39;
    v43 = *v5;
    v44 = v4 >> 4;
    v45 = (*v5)->Size + 1;
    if ( v45 >= (*v5)->Size )
    {
      if ( v45 <= v43->Policy.Capacity )
        goto LABEL_63;
      v46 = v45 + (v45 >> 2);
    }
    else
    {
      if ( v45 >= v43->Policy.Capacity >> 1 )
        goto LABEL_63;
      v46 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v46);
LABEL_63:
    v47 = v43->Data;
    v43->Size = v45;
    v48 = &v47[v45 - 1];
    if ( v48 )
      *v48 = v44;
    v49 = *v5;
    v50 = (v4 >> 12) & 3 | 4 * v3;
    v51 = (*v5)->Size + 1;
    if ( v51 >= (*v5)->Size )
    {
      if ( v51 <= v49->Policy.Capacity )
        goto LABEL_71;
      v52 = v51 + (v51 >> 2);
    }
    else
    {
      if ( v51 >= v49->Policy.Capacity >> 1 )
        goto LABEL_71;
      v52 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v52);
LABEL_71:
    v53 = v49->Data;
    v49->Size = v51;
    v54 = &v53[v51 - 1];
    if ( v54 )
      *v54 = v50;
    v55 = *v5;
    v56 = v3 >> 6;
    v57 = (*v5)->Size + 1;
    if ( v57 >= (*v5)->Size )
    {
      if ( v57 > v55->Policy.Capacity )
      {
        v58 = v57 + (v57 >> 2);
        goto LABEL_78;
      }
    }
    else if ( v57 < v55->Policy.Capacity >> 1 )
    {
      v58 = (*v5)->Size + 1;
LABEL_78:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v55,
        (*v5)[1].Data,
        v58);
      goto LABEL_79;
    }
LABEL_79:
    v59 = v55->Data;
    v55->Size = v57;
    v60 = &v59[v57 - 1];
    if ( v60 )
      *v60 = v56;
    return 4i64;
  }
  v61 = this->Data;
  v62 = this->Data->Data.Size + 1;
  v63 = 16 * x | 7;
  if ( v62 >= this->Data->Data.Size )
  {
    if ( v62 <= v61->Data.Policy.Capacity )
      goto LABEL_88;
    v64 = v62 + (v62 >> 2);
  }
  else
  {
    if ( v62 >= v61->Data.Policy.Capacity >> 1 )
      goto LABEL_88;
    v64 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
    this->Data->Data.pHeap,
    v64);
LABEL_88:
  v65 = v61->Data.Data;
  v61->Data.Size = v62;
  v66 = &v65[v62 - 1];
  if ( v66 )
    *v66 = v63;
  v67 = *v5;
  v68 = v4 >> 4;
  v69 = (*v5)->Size + 1;
  if ( v69 >= (*v5)->Size )
  {
    if ( v69 <= v67->Policy.Capacity )
      goto LABEL_96;
    v70 = v69 + (v69 >> 2);
  }
  else
  {
    if ( v69 >= v67->Policy.Capacity >> 1 )
      goto LABEL_96;
    v70 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v70);
LABEL_96:
  v71 = v67->Data;
  v67->Size = v69;
  v72 = &v71[v69 - 1];
  if ( v72 )
    *v72 = v68;
  v73 = *v5;
  v74 = v4 >> 12;
  v75 = (*v5)->Size + 1;
  if ( v75 >= (*v5)->Size )
  {
    if ( v75 <= v73->Policy.Capacity )
      goto LABEL_104;
    v76 = v75 + (v75 >> 2);
  }
  else
  {
    if ( v75 >= v73->Policy.Capacity >> 1 )
      goto LABEL_104;
    v76 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v76);
LABEL_104:
  v77 = v73->Data;
  v73->Size = v75;
  v78 = &v77[v75 - 1];
  if ( v78 )
    *v78 = v74;
  v79 = *v5;
  v80 = v4 >> 20;
  v81 = (*v5)->Size + 1;
  if ( v81 >= (*v5)->Size )
  {
    if ( v81 <= v79->Policy.Capacity )
      goto LABEL_112;
    v82 = v81 + (v81 >> 2);
  }
  else
  {
    if ( v81 >= v79->Policy.Capacity >> 1 )
      goto LABEL_112;
    v82 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v82);
LABEL_112:
  v83 = v79->Data;
  v79->Size = v81;
  v84 = &v83[v81 - 1];
  if ( v84 )
    *v84 = v80;
  v85 = *v5;
  v86 = (*v5)->Size + 1;
  v87 = 4 * v3 | (v4 >> 28) & 3;
  if ( v86 >= (*v5)->Size )
  {
    if ( v86 <= v85->Policy.Capacity )
      goto LABEL_120;
    v88 = v86 + (v86 >> 2);
  }
  else
  {
    if ( v86 >= v85->Policy.Capacity >> 1 )
      goto LABEL_120;
    v88 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v88);
LABEL_120:
  v89 = v85->Data;
  v85->Size = v86;
  v90 = &v89[v86 - 1];
  if ( v90 )
    *v90 = v87;
  v91 = *v5;
  v92 = v3 >> 6;
  v93 = (*v5)->Size + 1;
  if ( v93 >= (*v5)->Size )
  {
    if ( v93 <= v91->Policy.Capacity )
      goto LABEL_128;
    v94 = v93 + (v93 >> 2);
  }
  else
  {
    if ( v93 >= v91->Policy.Capacity >> 1 )
      goto LABEL_128;
    v94 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v94);
LABEL_128:
  v95 = v91->Data;
  v91->Size = v93;
  v96 = &v95[v93 - 1];
  if ( v96 )
    *v96 = v92;
  v97 = *v5;
  v98 = v3 >> 14;
  v99 = (*v5)->Size + 1;
  if ( v99 >= (*v5)->Size )
  {
    if ( v99 <= v97->Policy.Capacity )
      goto LABEL_136;
    v100 = v99 + (v99 >> 2);
  }
  else
  {
    if ( v99 >= v97->Policy.Capacity >> 1 )
      goto LABEL_136;
    v100 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v100);
LABEL_136:
  v101 = v97->Data;
  v97->Size = v99;
  v102 = &v101[v99 - 1];
  if ( v102 )
    *v102 = v98;
  v103 = *v5;
  v104 = v3 >> 22;
  v105 = (*v5)->Size + 1;
  if ( v105 >= (*v5)->Size )
  {
    if ( v105 > v103->Policy.Capacity )
    {
      v106 = v105 + (v105 >> 2);
      goto LABEL_143;
    }
  }
  else if ( v105 < v103->Policy.Capacity >> 1 )
  {
    v106 = (*v5)->Size + 1;
LABEL_143:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v103,
      (*v5)[1].Data,
      v106);
    goto LABEL_144;
  }
LABEL_144:
  v107 = v103->Data;
  v103->Size = v105;
  v108 = &v107[v105 - 1];
  if ( v108 )
    *v108 = v104;
  return 8i64;
}106);
    goto LABEL_144;
  }
LABEL_144:
  v107 = v103->Data;
  v103->Size = v105;
  v108 = &v107[v105 - 1];
  if ( v108 )
    *v108 = v104;
  return 8i64;
}

// File Line: 540
// RVA: 0x91AEC0
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, int cx, int cy, int ax, int ay)
{
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **v5; // r14
  signed int v6; // ecx
  signed int v7; // eax
  int v8; // edi
  int v9; // esi
  int v10; // ebx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v11; // r12
  unsigned __int64 v12; // r15
  char v13; // r13
  unsigned __int64 v14; // r8
  char *v15; // rcx
  char *v16; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v17; // r15
  char v18; // bl
  unsigned __int64 v19; // rsi
  char v20; // bl
  unsigned __int64 v21; // r8
  char *v22; // rcx
  char *v23; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v24; // rsi
  unsigned __int64 v25; // rbx
  char v26; // di
  unsigned __int64 v27; // r8
  char *v28; // rcx
  char *v29; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v31; // r12
  unsigned __int64 v32; // r15
  char v33; // r13
  unsigned __int64 v34; // r8
  char *v35; // rcx
  char *v36; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v37; // r12
  unsigned __int64 v38; // r15
  char v39; // bl
  unsigned __int64 v40; // r8
  char *v41; // rcx
  char *v42; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v43; // r15
  unsigned __int64 v44; // rbx
  char v45; // si
  unsigned __int64 v46; // r8
  char *v47; // rcx
  char *v48; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v49; // rsi
  unsigned __int64 v50; // rbx
  char v51; // di
  unsigned __int64 v52; // r8
  char *v53; // rcx
  char *v54; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v55; // r12
  unsigned __int64 v56; // r15
  char v57; // r13
  unsigned __int64 v58; // r8
  char *v59; // rcx
  char *v60; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v61; // r12
  unsigned __int64 v62; // r15
  char v63; // bl
  unsigned __int64 v64; // r8
  char *v65; // rcx
  char *v66; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v67; // r15
  unsigned __int64 v68; // rbx
  char v69; // si
  unsigned __int64 v70; // r8
  char *v71; // rcx
  char *v72; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v73; // rsi
  unsigned __int64 v74; // rbx
  char v75; // di
  unsigned __int64 v76; // r8
  char *v77; // rcx
  char *v78; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v79; // rdi
  int v80; // ebp
  unsigned __int64 v81; // rbx
  unsigned __int64 v82; // r8
  char *v83; // rcx
  char *v84; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v85; // r12
  unsigned __int64 v86; // r15
  char v87; // r13
  unsigned __int64 v88; // r8
  char *v89; // rcx
  char *v90; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v91; // r12
  unsigned __int64 v92; // r15
  char v93; // bl
  unsigned __int64 v94; // r8
  char *v95; // rcx
  char *v96; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v97; // r15
  int v98; // er12
  unsigned __int64 v99; // rbx
  unsigned __int64 v100; // r8
  char *v101; // rcx
  char *v102; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v103; // r15
  unsigned __int64 v104; // rbx
  char v105; // si
  unsigned __int64 v106; // r8
  char *v107; // rcx
  char *v108; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v109; // rsi
  unsigned __int64 v110; // rbx
  char v111; // di
  unsigned __int64 v112; // r8
  char *v113; // rcx
  char *v114; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v115; // rdi
  int v116; // ebp
  unsigned __int64 v117; // rbx
  unsigned __int64 v118; // r8
  char *v119; // rcx
  char *v120; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v121; // r12
  unsigned __int64 v122; // r15
  char v123; // r13
  unsigned __int64 v124; // r8
  char *v125; // rcx
  char *v126; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v127; // r12
  int v128; // er13
  unsigned __int64 v129; // r15
  unsigned __int64 v130; // r8
  char *v131; // rcx
  char *v132; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v133; // r12
  unsigned __int64 v134; // r15
  char v135; // bl
  unsigned __int64 v136; // r8
  char *v137; // rcx
  char *v138; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v139; // r15
  unsigned __int64 v140; // rbx
  char v141; // si
  unsigned __int64 v142; // r8
  char *v143; // rcx
  char *v144; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v145; // rsi
  int v146; // er15
  unsigned __int64 v147; // rbx
  unsigned __int64 v148; // r8
  char *v149; // rcx
  char *v150; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v151; // rsi
  unsigned __int64 v152; // rbx
  char v153; // di
  unsigned __int64 v154; // r8
  char *v155; // rcx
  char *v156; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v157; // rdi
  int v158; // ebp
  unsigned __int64 v159; // rbx
  unsigned __int64 v160; // r8
  char *v161; // rcx
  char *v162; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v163; // r12
  unsigned __int64 v164; // r15
  char v165; // r13
  unsigned __int64 v166; // r8
  char *v167; // rcx
  char *v168; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v169; // r12
  int v170; // er13
  unsigned __int64 v171; // r15
  unsigned __int64 v172; // r8
  char *v173; // rcx
  char *v174; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v175; // r12
  unsigned __int64 v176; // r15
  char v177; // bl
  unsigned __int64 v178; // r8
  char *v179; // rcx
  char *v180; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v181; // r15
  int v182; // er12
  unsigned __int64 v183; // rbx
  unsigned __int64 v184; // r8
  char *v185; // rcx
  char *v186; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v187; // r15
  unsigned __int64 v188; // rbx
  char v189; // si
  unsigned __int64 v190; // r8
  char *v191; // rcx
  char *v192; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v193; // rsi
  int v194; // er15
  unsigned __int64 v195; // rbx
  unsigned __int64 v196; // r8
  char *v197; // rcx
  char *v198; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v199; // rsi
  unsigned __int64 v200; // rbx
  char v201; // di
  unsigned __int64 v202; // r8
  char *v203; // rcx
  char *v204; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v205; // rdi
  int v206; // ebp
  unsigned __int64 v207; // rbx
  unsigned __int64 v208; // r8
  char *v209; // rcx
  char *v210; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v211; // r12
  unsigned __int64 v212; // r15
  char v213; // r13
  unsigned __int64 v214; // r8
  char *v215; // rcx
  char *v216; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v217; // r12
  int v218; // er13
  unsigned __int64 v219; // r15
  unsigned __int64 v220; // r8
  char *v221; // rcx
  char *v222; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v223; // r12
  int v224; // er13
  unsigned __int64 v225; // r15
  unsigned __int64 v226; // r8
  char *v227; // rcx
  char *v228; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v229; // r12
  int v230; // er13
  unsigned __int64 v231; // r15
  unsigned __int64 v232; // r8
  char *v233; // rcx
  char *v234; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v235; // r12
  unsigned __int64 v236; // r15
  char v237; // bl
  unsigned __int64 v238; // r8
  char *v239; // rcx
  char *v240; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v241; // r15
  int v242; // er12
  unsigned __int64 v243; // rbx
  unsigned __int64 v244; // r8
  char *v245; // rcx
  char *v246; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v247; // r15
  int v248; // er12
  unsigned __int64 v249; // rbx
  unsigned __int64 v250; // r8
  char *v251; // rcx
  char *v252; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v253; // r15
  int v254; // er12
  unsigned __int64 v255; // rbx
  unsigned __int64 v256; // r8
  char *v257; // rcx
  char *v258; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v259; // r15
  unsigned __int64 v260; // rbx
  char v261; // si
  unsigned __int64 v262; // r8
  char *v263; // rcx
  char *v264; // rcx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v265; // rbx
  char *v266; // rdx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v267; // rbx
  char *v268; // rdx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v269; // rbx
  char *v270; // rdx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v271; // rbx
  char *v272; // rdx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v273; // rbx
  char *v274; // rdx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v275; // rbx
  char *v276; // rdx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *v277; // rbx
  char *v278; // rdx

  v5 = (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> **)this;
  v6 = cx;
  v7 = cx;
  v8 = ax;
  if ( cy < cx )
    v6 = cy;
  if ( cy > cx )
    v7 = cy;
  v9 = cy;
  v10 = cx;
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
    v11 = *v5;
    v12 = (*v5)->Size + 1;
    v13 = 16 * cx | 8;
    if ( v12 >= (*v5)->Size )
    {
      if ( v12 <= v11->Policy.Capacity )
        goto LABEL_21;
      v14 = v12 + (v12 >> 2);
    }
    else
    {
      if ( v12 >= v11->Policy.Capacity >> 1 )
        goto LABEL_21;
      v14 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v14);
LABEL_21:
    v15 = v11->Data;
    v11->Size = v12;
    v16 = &v15[v12 - 1];
    if ( v16 )
      *v16 = v13;
    v17 = *v5;
    v18 = 2 * v9 | (v10 >> 4) & 1;
    v19 = (*v5)->Size + 1;
    v20 = ((_BYTE)v8 << 6) | v18 & 0x3F;
    if ( v19 >= (*v5)->Size )
    {
      if ( v19 <= v17->Policy.Capacity )
        goto LABEL_29;
      v21 = v19 + (v19 >> 2);
    }
    else
    {
      if ( v19 >= v17->Policy.Capacity >> 1 )
        goto LABEL_29;
      v21 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v21);
LABEL_29:
    v22 = v17->Data;
    v17->Size = v19;
    v23 = &v22[v19 - 1];
    if ( v23 )
      *v23 = v20;
    v24 = *v5;
    v25 = (*v5)->Size + 1;
    v26 = 8 * ay | (v8 >> 2) & 7;
    if ( v25 >= (*v5)->Size )
    {
      if ( v25 > v24->Policy.Capacity )
      {
        v27 = v25 + (v25 >> 2);
        goto LABEL_36;
      }
    }
    else if ( v25 < v24->Policy.Capacity >> 1 )
    {
      v27 = (*v5)->Size + 1;
LABEL_36:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v5,
        (*v5)[1].Data,
        v27);
      goto LABEL_37;
    }
LABEL_37:
    v28 = v24->Data;
    v24->Size = v25;
    v29 = &v28[v25 - 1];
    if ( v29 )
      *v29 = v26;
    return 3i64;
  }
  if ( v6 >= -64 && v7 <= 63 )
  {
    v31 = *v5;
    v32 = (*v5)->Size + 1;
    v33 = 16 * cx | 9;
    if ( v32 >= (*v5)->Size )
    {
      if ( v32 <= v31->Policy.Capacity )
        goto LABEL_48;
      v34 = v32 + (v32 >> 2);
    }
    else
    {
      if ( v32 >= v31->Policy.Capacity >> 1 )
        goto LABEL_48;
      v34 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v34);
LABEL_48:
    v35 = v31->Data;
    v31->Size = v32;
    v36 = &v35[v32 - 1];
    if ( v36 )
      *v36 = v33;
    v37 = *v5;
    v38 = (*v5)->Size + 1;
    v39 = 8 * v9 | (v10 >> 4) & 7;
    if ( v38 >= (*v5)->Size )
    {
      if ( v38 <= v37->Policy.Capacity )
        goto LABEL_56;
      v40 = v38 + (v38 >> 2);
    }
    else
    {
      if ( v38 >= v37->Policy.Capacity >> 1 )
        goto LABEL_56;
      v40 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v40);
LABEL_56:
    v41 = v37->Data;
    v37->Size = v38;
    v42 = &v41[v38 - 1];
    if ( v42 )
      *v42 = v39;
    v43 = *v5;
    v44 = (*v5)->Size + 1;
    v45 = 4 * v8 | (v9 >> 5) & 3;
    if ( v44 >= (*v5)->Size )
    {
      if ( v44 <= v43->Policy.Capacity )
        goto LABEL_64;
      v46 = v44 + (v44 >> 2);
    }
    else
    {
      if ( v44 >= v43->Policy.Capacity >> 1 )
        goto LABEL_64;
      v46 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v46);
LABEL_64:
    v47 = v43->Data;
    v43->Size = v44;
    v48 = &v47[v44 - 1];
    if ( v48 )
      *v48 = v45;
    v49 = *v5;
    v50 = (*v5)->Size + 1;
    v51 = 2 * ay | (v8 >> 6) & 1;
    if ( v50 >= (*v5)->Size )
    {
      if ( v50 > v49->Policy.Capacity )
      {
        v52 = v50 + (v50 >> 2);
        goto LABEL_71;
      }
    }
    else if ( v50 < v49->Policy.Capacity >> 1 )
    {
      v52 = (*v5)->Size + 1;
LABEL_71:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v5,
        (*v5)[1].Data,
        v52);
      goto LABEL_72;
    }
LABEL_72:
    v53 = v49->Data;
    v49->Size = v50;
    v54 = &v53[v50 - 1];
    if ( v54 )
      *v54 = v51;
    return 4i64;
  }
  if ( v6 >= -256 && v7 <= 255 )
  {
    v55 = *v5;
    v56 = (*v5)->Size + 1;
    v57 = 16 * cx | 0xA;
    if ( v56 >= (*v5)->Size )
    {
      if ( v56 <= v55->Policy.Capacity )
        goto LABEL_83;
      v58 = v56 + (v56 >> 2);
    }
    else
    {
      if ( v56 >= v55->Policy.Capacity >> 1 )
        goto LABEL_83;
      v58 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v58);
LABEL_83:
    v59 = v55->Data;
    v55->Size = v56;
    v60 = &v59[v56 - 1];
    if ( v60 )
      *v60 = v57;
    v61 = *v5;
    v62 = (*v5)->Size + 1;
    v63 = 32 * v9 | (v10 >> 4) & 0x1F;
    if ( v62 >= (*v5)->Size )
    {
      if ( v62 <= v61->Policy.Capacity )
        goto LABEL_91;
      v64 = v62 + (v62 >> 2);
    }
    else
    {
      if ( v62 >= v61->Policy.Capacity >> 1 )
        goto LABEL_91;
      v64 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v64);
LABEL_91:
    v65 = v61->Data;
    v61->Size = v62;
    v66 = &v65[v62 - 1];
    if ( v66 )
      *v66 = v63;
    v67 = *v5;
    v68 = (*v5)->Size + 1;
    v69 = ((_BYTE)v8 << 6) | (v9 >> 3) & 0x3F;
    if ( v68 >= (*v5)->Size )
    {
      if ( v68 <= v67->Policy.Capacity )
        goto LABEL_99;
      v70 = v68 + (v68 >> 2);
    }
    else
    {
      if ( v68 >= v67->Policy.Capacity >> 1 )
        goto LABEL_99;
      v70 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v70);
LABEL_99:
    v71 = v67->Data;
    v67->Size = v68;
    v72 = &v71[v68 - 1];
    if ( v72 )
      *v72 = v69;
    v73 = *v5;
    v74 = (*v5)->Size + 1;
    v75 = ((_BYTE)ay << 7) | (v8 >> 2) & 0x7F;
    if ( v74 >= (*v5)->Size )
    {
      if ( v74 <= v73->Policy.Capacity )
        goto LABEL_107;
      v76 = v74 + (v74 >> 2);
    }
    else
    {
      if ( v74 >= v73->Policy.Capacity >> 1 )
        goto LABEL_107;
      v76 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v76);
LABEL_107:
    v77 = v73->Data;
    v73->Size = v74;
    v78 = &v77[v74 - 1];
    if ( v78 )
      *v78 = v75;
    v79 = *v5;
    v80 = ay >> 1;
    v81 = (*v5)->Size + 1;
    if ( v81 >= (*v5)->Size )
    {
      if ( v81 > v79->Policy.Capacity )
      {
        v82 = v81 + (v81 >> 2);
        goto LABEL_114;
      }
    }
    else if ( v81 < v79->Policy.Capacity >> 1 )
    {
      v82 = (*v5)->Size + 1;
LABEL_114:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v5,
        (*v5)[1].Data,
        v82);
      goto LABEL_115;
    }
LABEL_115:
    v83 = v79->Data;
    v79->Size = v81;
    v84 = &v83[v81 - 1];
    if ( v84 )
      *v84 = v80;
    return 5i64;
  }
  if ( v6 >= -1024 && v7 <= 1023 )
  {
    v85 = *v5;
    v86 = (*v5)->Size + 1;
    v87 = 16 * cx | 0xB;
    if ( v86 >= (*v5)->Size )
    {
      if ( v86 <= v85->Policy.Capacity )
        goto LABEL_126;
      v88 = v86 + (v86 >> 2);
    }
    else
    {
      if ( v86 >= v85->Policy.Capacity >> 1 )
        goto LABEL_126;
      v88 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v88);
LABEL_126:
    v89 = v85->Data;
    v85->Size = v86;
    v90 = &v89[v86 - 1];
    if ( v90 )
      *v90 = v87;
    v91 = *v5;
    v92 = (*v5)->Size + 1;
    v93 = ((_BYTE)v9 << 7) | (v10 >> 4) & 0x7F;
    if ( v92 >= (*v5)->Size )
    {
      if ( v92 <= v91->Policy.Capacity )
        goto LABEL_134;
      v94 = v92 + (v92 >> 2);
    }
    else
    {
      if ( v92 >= v91->Policy.Capacity >> 1 )
        goto LABEL_134;
      v94 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v94);
LABEL_134:
    v95 = v91->Data;
    v91->Size = v92;
    v96 = &v95[v92 - 1];
    if ( v96 )
      *v96 = v93;
    v97 = *v5;
    v98 = v9 >> 1;
    v99 = (*v5)->Size + 1;
    if ( v99 >= (*v5)->Size )
    {
      if ( v99 <= v97->Policy.Capacity )
        goto LABEL_142;
      v100 = v99 + (v99 >> 2);
    }
    else
    {
      if ( v99 >= v97->Policy.Capacity >> 1 )
        goto LABEL_142;
      v100 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v100);
LABEL_142:
    v101 = v97->Data;
    v97->Size = v99;
    v102 = &v101[v99 - 1];
    if ( v102 )
      *v102 = v98;
    v103 = *v5;
    v104 = (*v5)->Size + 1;
    v105 = 4 * v8 | (v9 >> 9) & 3;
    if ( v104 >= (*v5)->Size )
    {
      if ( v104 <= v103->Policy.Capacity )
        goto LABEL_150;
      v106 = v104 + (v104 >> 2);
    }
    else
    {
      if ( v104 >= v103->Policy.Capacity >> 1 )
        goto LABEL_150;
      v106 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v106);
LABEL_150:
    v107 = v103->Data;
    v103->Size = v104;
    v108 = &v107[v104 - 1];
    if ( v108 )
      *v108 = v105;
    v109 = *v5;
    v110 = (*v5)->Size + 1;
    v111 = 32 * ay | (v8 >> 6) & 0x1F;
    if ( v110 >= (*v5)->Size )
    {
      if ( v110 <= v109->Policy.Capacity )
        goto LABEL_158;
      v112 = v110 + (v110 >> 2);
    }
    else
    {
      if ( v110 >= v109->Policy.Capacity >> 1 )
        goto LABEL_158;
      v112 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v112);
LABEL_158:
    v113 = v109->Data;
    v109->Size = v110;
    v114 = &v113[v110 - 1];
    if ( v114 )
      *v114 = v111;
    v115 = *v5;
    v116 = ay >> 3;
    v117 = (*v5)->Size + 1;
    if ( v117 >= (*v5)->Size )
    {
      if ( v117 > v115->Policy.Capacity )
      {
        v118 = v117 + (v117 >> 2);
        goto LABEL_165;
      }
    }
    else if ( v117 < v115->Policy.Capacity >> 1 )
    {
      v118 = (*v5)->Size + 1;
LABEL_165:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v5,
        (*v5)[1].Data,
        v118);
      goto LABEL_166;
    }
LABEL_166:
    v119 = v115->Data;
    v115->Size = v117;
    v120 = &v119[v117 - 1];
    if ( v120 )
      *v120 = v116;
    return 6i64;
  }
  if ( v6 >= -4096 && v7 <= 4095 )
  {
    v121 = *v5;
    v122 = (*v5)->Size + 1;
    v123 = 16 * cx | 0xC;
    if ( v122 >= (*v5)->Size )
    {
      if ( v122 <= v121->Policy.Capacity )
        goto LABEL_177;
      v124 = v122 + (v122 >> 2);
    }
    else
    {
      if ( v122 >= v121->Policy.Capacity >> 1 )
        goto LABEL_177;
      v124 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v124);
LABEL_177:
    v125 = v121->Data;
    v121->Size = v122;
    v126 = &v125[v122 - 1];
    if ( v126 )
      *v126 = v123;
    v127 = *v5;
    v128 = v10 >> 4;
    v129 = (*v5)->Size + 1;
    if ( v129 >= (*v5)->Size )
    {
      if ( v129 <= v127->Policy.Capacity )
        goto LABEL_185;
      v130 = v129 + (v129 >> 2);
    }
    else
    {
      if ( v129 >= v127->Policy.Capacity >> 1 )
        goto LABEL_185;
      v130 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v130);
LABEL_185:
    v131 = v127->Data;
    v127->Size = v129;
    v132 = &v131[v129 - 1];
    if ( v132 )
      *v132 = v128;
    v133 = *v5;
    v134 = (*v5)->Size + 1;
    v135 = 2 * v9 | (v10 >> 12) & 1;
    if ( v134 >= (*v5)->Size )
    {
      if ( v134 <= v133->Policy.Capacity )
        goto LABEL_193;
      v136 = v134 + (v134 >> 2);
    }
    else
    {
      if ( v134 >= v133->Policy.Capacity >> 1 )
        goto LABEL_193;
      v136 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v136);
LABEL_193:
    v137 = v133->Data;
    v133->Size = v134;
    v138 = &v137[v134 - 1];
    if ( v138 )
      *v138 = v135;
    v139 = *v5;
    v140 = (*v5)->Size + 1;
    v141 = ((_BYTE)v8 << 6) | (v9 >> 7) & 0x3F;
    if ( v140 >= (*v5)->Size )
    {
      if ( v140 <= v139->Policy.Capacity )
        goto LABEL_201;
      v142 = v140 + (v140 >> 2);
    }
    else
    {
      if ( v140 >= v139->Policy.Capacity >> 1 )
        goto LABEL_201;
      v142 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v142);
LABEL_201:
    v143 = v139->Data;
    v139->Size = v140;
    v144 = &v143[v140 - 1];
    if ( v144 )
      *v144 = v141;
    v145 = *v5;
    v146 = v8 >> 2;
    v147 = (*v5)->Size + 1;
    if ( v147 >= (*v5)->Size )
    {
      if ( v147 <= v145->Policy.Capacity )
        goto LABEL_209;
      v148 = v147 + (v147 >> 2);
    }
    else
    {
      if ( v147 >= v145->Policy.Capacity >> 1 )
        goto LABEL_209;
      v148 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v148);
LABEL_209:
    v149 = v145->Data;
    v145->Size = v147;
    v150 = &v149[v147 - 1];
    if ( v150 )
      *v150 = v146;
    v151 = *v5;
    v152 = (*v5)->Size + 1;
    v153 = 8 * ay | (v8 >> 10) & 7;
    if ( v152 >= (*v5)->Size )
    {
      if ( v152 <= v151->Policy.Capacity )
        goto LABEL_217;
      v154 = v152 + (v152 >> 2);
    }
    else
    {
      if ( v152 >= v151->Policy.Capacity >> 1 )
        goto LABEL_217;
      v154 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v154);
LABEL_217:
    v155 = v151->Data;
    v151->Size = v152;
    v156 = &v155[v152 - 1];
    if ( v156 )
      *v156 = v153;
    v157 = *v5;
    v158 = ay >> 5;
    v159 = (*v5)->Size + 1;
    if ( v159 >= (*v5)->Size )
    {
      if ( v159 > v157->Policy.Capacity )
      {
        v160 = v159 + (v159 >> 2);
        goto LABEL_224;
      }
    }
    else if ( v159 < v157->Policy.Capacity >> 1 )
    {
      v160 = (*v5)->Size + 1;
LABEL_224:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v5,
        (*v5)[1].Data,
        v160);
      goto LABEL_225;
    }
LABEL_225:
    v161 = v157->Data;
    v157->Size = v159;
    v162 = &v161[v159 - 1];
    if ( v162 )
      *v162 = v158;
    return 7i64;
  }
  if ( v6 >= -16384 && v7 <= 0x3FFF )
  {
    v163 = *v5;
    v164 = (*v5)->Size + 1;
    v165 = 16 * cx | 0xD;
    if ( v164 >= (*v5)->Size )
    {
      if ( v164 <= v163->Policy.Capacity )
        goto LABEL_236;
      v166 = v164 + (v164 >> 2);
    }
    else
    {
      if ( v164 >= v163->Policy.Capacity >> 1 )
        goto LABEL_236;
      v166 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v166);
LABEL_236:
    v167 = v163->Data;
    v163->Size = v164;
    v168 = &v167[v164 - 1];
    if ( v168 )
      *v168 = v165;
    v169 = *v5;
    v170 = v10 >> 4;
    v171 = (*v5)->Size + 1;
    if ( v171 >= (*v5)->Size )
    {
      if ( v171 <= v169->Policy.Capacity )
        goto LABEL_244;
      v172 = v171 + (v171 >> 2);
    }
    else
    {
      if ( v171 >= v169->Policy.Capacity >> 1 )
        goto LABEL_244;
      v172 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v172);
LABEL_244:
    v173 = v169->Data;
    v169->Size = v171;
    v174 = &v173[v171 - 1];
    if ( v174 )
      *v174 = v170;
    v175 = *v5;
    v176 = (*v5)->Size + 1;
    v177 = 8 * v9 | (v10 >> 12) & 7;
    if ( v176 >= (*v5)->Size )
    {
      if ( v176 <= v175->Policy.Capacity )
        goto LABEL_252;
      v178 = v176 + (v176 >> 2);
    }
    else
    {
      if ( v176 >= v175->Policy.Capacity >> 1 )
        goto LABEL_252;
      v178 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v178);
LABEL_252:
    v179 = v175->Data;
    v175->Size = v176;
    v180 = &v179[v176 - 1];
    if ( v180 )
      *v180 = v177;
    v181 = *v5;
    v182 = v9 >> 5;
    v183 = (*v5)->Size + 1;
    if ( v183 >= (*v5)->Size )
    {
      if ( v183 <= v181->Policy.Capacity )
        goto LABEL_260;
      v184 = v183 + (v183 >> 2);
    }
    else
    {
      if ( v183 >= v181->Policy.Capacity >> 1 )
        goto LABEL_260;
      v184 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v184);
LABEL_260:
    v185 = v181->Data;
    v181->Size = v183;
    v186 = &v185[v183 - 1];
    if ( v186 )
      *v186 = v182;
    v187 = *v5;
    v188 = (*v5)->Size + 1;
    v189 = 4 * v8 | (v9 >> 13) & 3;
    if ( v188 >= (*v5)->Size )
    {
      if ( v188 <= v187->Policy.Capacity )
        goto LABEL_268;
      v190 = v188 + (v188 >> 2);
    }
    else
    {
      if ( v188 >= v187->Policy.Capacity >> 1 )
        goto LABEL_268;
      v190 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v190);
LABEL_268:
    v191 = v187->Data;
    v187->Size = v188;
    v192 = &v191[v188 - 1];
    if ( v192 )
      *v192 = v189;
    v193 = *v5;
    v194 = v8 >> 6;
    v195 = (*v5)->Size + 1;
    if ( v195 >= (*v5)->Size )
    {
      if ( v195 <= v193->Policy.Capacity )
        goto LABEL_276;
      v196 = v195 + (v195 >> 2);
    }
    else
    {
      if ( v195 >= v193->Policy.Capacity >> 1 )
        goto LABEL_276;
      v196 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v196);
LABEL_276:
    v197 = v193->Data;
    v193->Size = v195;
    v198 = &v197[v195 - 1];
    if ( v198 )
      *v198 = v194;
    v199 = *v5;
    v200 = (*v5)->Size + 1;
    v201 = 2 * ay | (v8 >> 14) & 1;
    if ( v200 >= (*v5)->Size )
    {
      if ( v200 <= v199->Policy.Capacity )
        goto LABEL_284;
      v202 = v200 + (v200 >> 2);
    }
    else
    {
      if ( v200 >= v199->Policy.Capacity >> 1 )
        goto LABEL_284;
      v202 = (*v5)->Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v202);
LABEL_284:
    v203 = v199->Data;
    v199->Size = v200;
    v204 = &v203[v200 - 1];
    if ( v204 )
      *v204 = v201;
    v205 = *v5;
    v206 = ay >> 7;
    v207 = (*v5)->Size + 1;
    if ( v207 >= (*v5)->Size )
    {
      if ( v207 > v205->Policy.Capacity )
      {
        v208 = v207 + (v207 >> 2);
        goto LABEL_291;
      }
    }
    else if ( v207 < v205->Policy.Capacity >> 1 )
    {
      v208 = (*v5)->Size + 1;
LABEL_291:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        *v5,
        (*v5)[1].Data,
        v208);
      goto LABEL_292;
    }
LABEL_292:
    v209 = v205->Data;
    v205->Size = v207;
    v210 = &v209[v207 - 1];
    if ( v210 )
      *v210 = v206;
    return 8i64;
  }
  v211 = *v5;
  v212 = (*v5)->Size + 1;
  v213 = 16 * cx | 0xE;
  if ( v212 >= (*v5)->Size )
  {
    if ( v212 <= v211->Policy.Capacity )
      goto LABEL_301;
    v214 = v212 + (v212 >> 2);
  }
  else
  {
    if ( v212 >= v211->Policy.Capacity >> 1 )
      goto LABEL_301;
    v214 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v214);
LABEL_301:
  v215 = v211->Data;
  v211->Size = v212;
  v216 = &v215[v212 - 1];
  if ( v216 )
    *v216 = v213;
  v217 = *v5;
  v218 = v10 >> 4;
  v219 = (*v5)->Size + 1;
  if ( v219 >= (*v5)->Size )
  {
    if ( v219 <= v217->Policy.Capacity )
      goto LABEL_309;
    v220 = v219 + (v219 >> 2);
  }
  else
  {
    if ( v219 >= v217->Policy.Capacity >> 1 )
      goto LABEL_309;
    v220 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v220);
LABEL_309:
  v221 = v217->Data;
  v217->Size = v219;
  v222 = &v221[v219 - 1];
  if ( v222 )
    *v222 = v218;
  v223 = *v5;
  v224 = v10 >> 12;
  v225 = (*v5)->Size + 1;
  if ( v225 >= (*v5)->Size )
  {
    if ( v225 <= v223->Policy.Capacity )
      goto LABEL_317;
    v226 = v225 + (v225 >> 2);
  }
  else
  {
    if ( v225 >= v223->Policy.Capacity >> 1 )
      goto LABEL_317;
    v226 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v226);
LABEL_317:
  v227 = v223->Data;
  v223->Size = v225;
  v228 = &v227[v225 - 1];
  if ( v228 )
    *v228 = v224;
  v229 = *v5;
  v230 = v10 >> 20;
  v231 = (*v5)->Size + 1;
  if ( v231 >= (*v5)->Size )
  {
    if ( v231 <= v229->Policy.Capacity )
      goto LABEL_325;
    v232 = v231 + (v231 >> 2);
  }
  else
  {
    if ( v231 >= v229->Policy.Capacity >> 1 )
      goto LABEL_325;
    v232 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v232);
LABEL_325:
  v233 = v229->Data;
  v229->Size = v231;
  v234 = &v233[v231 - 1];
  if ( v234 )
    *v234 = v230;
  v235 = *v5;
  v236 = (*v5)->Size + 1;
  v237 = 8 * v9 | (v10 >> 28) & 7;
  if ( v236 >= (*v5)->Size )
  {
    if ( v236 <= v235->Policy.Capacity )
      goto LABEL_333;
    v238 = v236 + (v236 >> 2);
  }
  else
  {
    if ( v236 >= v235->Policy.Capacity >> 1 )
      goto LABEL_333;
    v238 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v238);
LABEL_333:
  v239 = v235->Data;
  v235->Size = v236;
  v240 = &v239[v236 - 1];
  if ( v240 )
    *v240 = v237;
  v241 = *v5;
  v242 = v9 >> 5;
  v243 = (*v5)->Size + 1;
  if ( v243 >= (*v5)->Size )
  {
    if ( v243 <= v241->Policy.Capacity )
      goto LABEL_341;
    v244 = v243 + (v243 >> 2);
  }
  else
  {
    if ( v243 >= v241->Policy.Capacity >> 1 )
      goto LABEL_341;
    v244 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v244);
LABEL_341:
  v245 = v241->Data;
  v241->Size = v243;
  v246 = &v245[v243 - 1];
  if ( v246 )
    *v246 = v242;
  v247 = *v5;
  v248 = v9 >> 13;
  v249 = (*v5)->Size + 1;
  if ( v249 >= (*v5)->Size )
  {
    if ( v249 <= v247->Policy.Capacity )
      goto LABEL_349;
    v250 = v249 + (v249 >> 2);
  }
  else
  {
    if ( v249 >= v247->Policy.Capacity >> 1 )
      goto LABEL_349;
    v250 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v250);
LABEL_349:
  v251 = v247->Data;
  v247->Size = v249;
  v252 = &v251[v249 - 1];
  if ( v252 )
    *v252 = v248;
  v253 = *v5;
  v254 = v9 >> 21;
  v255 = (*v5)->Size + 1;
  if ( v255 >= (*v5)->Size )
  {
    if ( v255 <= v253->Policy.Capacity )
      goto LABEL_357;
    v256 = v255 + (v255 >> 2);
  }
  else
  {
    if ( v255 >= v253->Policy.Capacity >> 1 )
      goto LABEL_357;
    v256 = (*v5)->Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    *v5,
    (*v5)[1].Data,
    v256);
LABEL_357:
  v257 = v253->Data;
  v253->Size = v255;
  v258 = &v257[v255 - 1];
  if ( v258 )
    *v258 = v254;
  v259 = *v5;
  v260 = (*v5)->Size + 1;
  v261 = 4 * v8 | (v9 >> 29) & 3;
  if ( v260 >= (*v5)->Size )
  {
    if ( v260 > v259->Policy.Capacity )
    {
      v262 = v260 + (v260 >> 2);
      goto LABEL_364;
    }
  }
  else if ( v260 < v259->Policy.Capacity >> 1 )
  {
    v262 = (*v5)->Size + 1;
LABEL_364:
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      *v5,
      (*v5)[1].Data,
      v262);
    goto LABEL_365;
  }
LABEL_365:
  v263 = v259->Data;
  v259->Size = v260;
  v264 = &v263[v260 - 1];
  if ( v264 )
    *v264 = v261;
  v265 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v266 = &v265->Data[v265->Size - 1];
  if ( v266 )
    *v266 = v8 >> 6;
  v267 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v268 = &v267->Data[v267->Size - 1];
  if ( v268 )
    *v268 = v8 >> 14;
  v269 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v270 = &v269->Data[v269->Size - 1];
  if ( v270 )
    *v270 = v8 >> 22;
  v271 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v272 = &v271->Data[v271->Size - 1];
  if ( v272 )
    *v272 = 2 * ay | (v8 >> 30) & 1;
  v273 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v274 = &v273->Data[v273->Size - 1];
  if ( v274 )
    *v274 = ay >> 7;
  v275 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v276 = &v275->Data[v275->Size - 1];
  if ( v276 )
    *v276 = ay >> 15;
  v277 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v278 = &v277->Data[v277->Size - 1];
  if ( v278 )
    *v278 = ay >> 23;
  return 16i64;
}v268 = v8 >> 14;
  v269 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)[1].Data,
    (*v5)->Size + 1);
  v270 = &v269->Data[v269->Size - 1];
  if ( v270 )
    *v270 = v8 >> 22;
  v271 = *v5;
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    *v5,
    (*v5)

// File Line: 632
// RVA: 0x91A4D0
signed __int64 __fastcall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rdi
  unsigned __int64 v2; // rbx
  unsigned __int64 v3; // r8
  char *v4; // rcx
  signed __int64 result; // rax
  char *v6; // rcx

  v1 = this->Data;
  v2 = this->Data->Data.Size + 1;
  if ( v2 >= this->Data->Data.Size )
  {
    if ( v2 <= v1->Data.Policy.Capacity )
      goto LABEL_7;
    v3 = v2 + (v2 >> 2);
  }
  else
  {
    if ( v2 >= v1->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v3 = this->Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data->Data.Data,
    this->Data->Data.pHeap,
    v3);
LABEL_7:
  v4 = v1->Data.Data;
  v1->Data.Size = v2;
  result = 1i64;
  v6 = &v4[v2 - 1];
  if ( v6 )
    *v6 = 15;
  return result;
}

// File Line: 798
// RVA: 0x9A60C0
signed __int64 __fastcall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int pos, int *v)
{
  char *v3; // r11
  int v4; // er9
  int v5; // er9
  signed __int64 result; // rax
  int v7; // edx

  v3 = this->Data->Data.Data;
  v4 = v3[pos] >> 2;
  if ( v3[pos] & 3 )
  {
    v5 = v4 & 0x3F;
    if ( (v3[pos] & 3) == 1 )
    {
      *v = v5 | (this->Data->Data.Data[pos + 1] << 6);
      result = 2i64;
    }
    else
    {
      if ( (v3[pos] & 3) == 2 )
      {
        result = 3i64;
        v7 = v5 | (((unsigned __int8)this->Data->Data.Data[pos + 1] | (this->Data->Data.Data[pos + 2] << 8)) << 6);
      }
      else
      {
        result = 4i64;
        v7 = v5 | (((unsigned __int8)this->Data->Data.Data[pos + 1] | (((unsigned __int8)this->Data->Data.Data[pos + 2] | (this->Data->Data.Data[pos + 3] << 8)) << 8)) << 6);
      }
      *v = v7;
    }
  }
  else
  {
    *v = v4;
    result = 1i64;
  }
  return result;
}

// File Line: 827
// RVA: 0x9A4760
__int64 __fastcall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int pos, int *data)
{
  __int64 v3; // r9
  char *v4; // r11
  __int64 v5; // rdx
  int *v6; // r10
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // r8
  int v9; // ebx
  __int64 v10; // r9
  unsigned __int8 v11; // cl
  unsigned int v12; // eax
  __int64 result; // rax
  int v14; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // edx
  int v20; // er8
  unsigned int v21; // er8
  int v22; // eax
  int v23; // ecx
  unsigned int v24; // er8
  int v25; // eax
  int v26; // ecx
  unsigned int v27; // er8
  unsigned int v28; // edx
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  unsigned int v32; // er8
  int v33; // edx
  unsigned int v34; // er8
  unsigned int v35; // er9
  signed int v36; // eax
  unsigned int v37; // er8
  int v38; // ecx
  int v39; // eax
  unsigned int v40; // er8
  unsigned int v41; // edx
  int v42; // ecx
  unsigned int v43; // er8
  char v44; // al
  int v45; // ecx
  int v46; // eax
  int v47; // ecx
  unsigned int v48; // er8
  unsigned int v49; // er9
  unsigned __int8 v50; // cl
  unsigned int v51; // edx
  char v52; // al
  int v53; // ecx
  int v54; // eax
  int v55; // ecx
  unsigned int v56; // er8
  unsigned int v57; // er9
  unsigned __int8 v58; // cl
  unsigned int v59; // edx
  char v60; // al
  int v61; // ecx
  int v62; // eax
  int v63; // ecx
  unsigned int v64; // er8
  unsigned int v65; // er9
  unsigned __int8 v66; // cl
  unsigned int v67; // edx
  char v68; // al
  int v69; // ecx
  int v70; // eax
  int v71; // ecx
  unsigned int v72; // er8
  unsigned int v73; // er9
  unsigned __int8 v74; // cl
  unsigned int v75; // edx
  unsigned __int8 v76; // al
  int v77; // ecx
  int v78; // eax
  int v79; // ecx
  char v80; // [rsp+0h] [rbp-10h]
  unsigned __int8 v81; // [rsp+1h] [rbp-Fh]
  unsigned __int8 v82; // [rsp+2h] [rbp-Eh]
  unsigned __int8 v83; // [rsp+3h] [rbp-Dh]
  unsigned __int8 v84; // [rsp+4h] [rbp-Ch]
  unsigned __int8 v85; // [rsp+5h] [rbp-Bh]
  unsigned __int8 v86; // [rsp+6h] [rbp-Ah]
  unsigned __int8 v87; // [rsp+7h] [rbp-9h]
  unsigned __int8 v88; // [rsp+8h] [rbp-8h]
  unsigned __int8 v89; // [rsp+9h] [rbp-7h]
  unsigned __int8 v90; // [rsp+Ah] [rbp-6h]
  unsigned __int8 v91; // [rsp+Bh] [rbp-5h]
  unsigned __int8 v92; // [rsp+Ch] [rbp-4h]
  unsigned __int8 v93; // [rsp+Dh] [rbp-3h]
  unsigned __int8 v94; // [rsp+Eh] [rbp-2h]
  char v95; // [rsp+Fh] [rbp-1h]

  v3 = pos;
  v4 = this->Data->Data.Data;
  v5 = pos + 1;
  v6 = data;
  v8 = &v81;
  v80 = v4[v3];
  v7 = v80;
  v9 = (unsigned __int8)Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v80 & 0xF];
  if ( Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v80 & 0xF] )
  {
    v10 = (unsigned __int8)Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v80 & 0xF];
    do
    {
      v11 = v4[v5];
      ++v8;
      v5 = (unsigned int)(v5 + 1);
      *(v8 - 1) = v11;
      --v10;
    }
    while ( v10 );
    v7 = v80;
  }
  v12 = v7;
  switch ( v7 & 0xF )
  {
    case 0:
      *v6 = 0;
      goto LABEL_7;
    case 1:
      v14 = (char)v82;
      v15 = (char)v83 << 8;
      *v6 = 0;
      v16 = (v12 >> 4) | 16 * (v81 | ((v14 | v15) << 8));
      result = (unsigned int)(v9 + 1);
      v6[1] = v16;
      return result;
    case 2:
      *v6 = 1;
LABEL_7:
      v6[1] = 16 * (char)v81 | ((unsigned int)v7 >> 4);
      return (unsigned int)(v9 + 1);
    case 3:
      v17 = (char)v82;
      v18 = (char)v83 << 8;
      *v6 = 1;
      v19 = (v12 >> 4) | 16 * (v81 | ((v17 | v18) << 8));
      result = (unsigned int)(v9 + 1);
      v6[1] = v19;
      return result;
    case 4:
      v20 = (char)v81;
      *v6 = 2;
      v6[1] = (signed int)((char)((_BYTE)v20 << 6) | ((unsigned int)v7 >> 2)) >> 2;
      v6[2] = v20 >> 2;
      return (unsigned int)(v9 + 1);
    case 5:
      v21 = v81;
      *v6 = 2;
      v22 = 4 * (char)v82;
      v6[1] = ((unsigned int)v7 >> 4) | 4 * (char)(4 * v21);
      v23 = v22 | (v21 >> 6);
      result = (unsigned int)(v9 + 1);
      v6[2] = v23;
      return result;
    case 6:
      v24 = v82;
      *v6 = 2;
      v25 = (char)v83 << 6;
      v6[1] = ((unsigned int)v7 >> 4) | 16 * (v81 | 4 * (char)((_BYTE)v24 << 6));
      v26 = v25 | (v24 >> 2);
      result = (unsigned int)(v9 + 1);
      v6[2] = v26;
      return result;
    case 7:
      v27 = v84;
      *v6 = 2;
      v28 = ((unsigned int)v7 >> 4) | 16 * (v81 | ((v82 | ((v83 | 4 * (char)((_BYTE)v27 << 6)) << 8)) << 8));
      v29 = v86 | ((char)v87 << 8);
      v30 = v85;
      v6[1] = v28;
      v31 = (v27 >> 2) | ((v30 | (v29 << 8)) << 6);
      result = (unsigned int)(v9 + 1);
      v6[2] = v31;
      return result;
    case 8:
      v32 = v81;
      *v6 = 3;
      v33 = (char)v82;
      v6[1] = (signed int)((char)((_BYTE)v32 << 7) | ((unsigned int)v7 >> 1)) >> 3;
      v6[2] = (char)(4 * v32) >> 3;
      v6[4] = v33 >> 3;
      result = (unsigned int)(v9 + 1);
      v6[3] = (signed int)((char)(32 * v33) | (v32 >> 3)) >> 3;
      return result;
    case 9:
      v34 = v81;
      *v6 = 3;
      v35 = v34 >> 2;
      v36 = (signed int)((char)(32 * v34) | ((unsigned int)v7 >> 3)) >> 1;
      v37 = v82;
      v6[1] = v36;
      v38 = (char)(v83 << 7);
      v39 = (char)v83;
      v6[2] = (signed int)((char)((_BYTE)v37 << 6) | v35) >> 1;
      v6[4] = v39 >> 1;
      result = (unsigned int)(v9 + 1);
      v6[3] = (signed int)(v38 | (v37 >> 1)) >> 1;
      return result;
    case 0xA:
      v40 = v81;
      *v6 = 3;
      v6[1] = ((unsigned int)v7 >> 4) | 2 * (char)(8 * v40);
      v41 = v83;
      v42 = (v40 >> 5) | 2 * (char)(4 * v82);
      v43 = (unsigned int)v82 >> 6;
      v44 = 2 * v83;
      v6[2] = v42;
      v45 = v44;
      v46 = 2 * (char)v84;
      v6[3] = 2 * v45 | v43;
      v47 = v46 | (v41 >> 7);
      result = (unsigned int)(v9 + 1);
      v6[4] = v47;
      return result;
    case 0xB:
      v48 = v81;
      v49 = v83;
      v50 = v81;
      *v6 = 3;
      v6[1] = (v12 >> 4) | 8 * (char)(2 * v50);
      v51 = v84;
      v52 = 8 * v84;
      v6[2] = (v48 >> 7) | 2 * (v82 | 4 * (char)((_BYTE)v49 << 6));
      v53 = (v49 >> 2) | 8 * v52;
      v54 = (char)v85;
      v6[3] = v53;
      v55 = 8 * v54 | (v51 >> 5);
      result = (unsigned int)(v9 + 1);
      v6[4] = v55;
      return result;
    case 0xC:
      v56 = v82;
      v57 = v83;
      v58 = v82;
      *v6 = 3;
      v6[1] = (v12 >> 4) | 16 * (v81 | 2 * (char)(v58 << 7));
      v59 = v85;
      v60 = 32 * v85;
      v6[2] = (v56 >> 1) | 32 * (char)(4 * v57);
      v61 = (v57 >> 6) | 4 * (v84 | 8 * v60);
      v62 = (char)v86;
      v6[3] = v61;
      v63 = 32 * v62 | (v59 >> 3);
      result = (unsigned int)(v9 + 1);
      v6[4] = v63;
      return result;
    case 0xD:
      v64 = v82;
      v65 = v84;
      v66 = v82;
      *v6 = 3;
      v6[1] = (v12 >> 4) | 16 * (v81 | 8 * (char)(32 * v66));
      v67 = v86;
      v68 = v86 << 7;
      v6[2] = (v64 >> 3) | 32 * (v83 | 4 * (char)((_BYTE)v65 << 6));
      v69 = (v65 >> 2) | ((v85 | 2 * v68) << 6);
      v70 = (char)v87;
      v6[3] = v69;
      v71 = (v70 << 7) | (v67 >> 1);
      result = (unsigned int)(v9 + 1);
      v6[4] = v71;
      return result;
    case 0xE:
      v72 = v84;
      v73 = v88;
      v74 = v84;
      *v6 = 3;
      v6[1] = (v12 >> 4) | 16 * (v81 | ((v82 | ((v83 | 8 * (char)(32 * v74)) << 8)) << 8));
      v75 = v92;
      v76 = v92;
      v6[2] = (v72 >> 3) | 32 * (v85 | ((v86 | ((v87 | 4 * (char)((_BYTE)v73 << 6)) << 8)) << 8));
      v77 = (v73 >> 2) | ((v89 | ((v90 | ((v91 | 2 * (char)(v76 << 7)) << 8)) << 8)) << 6);
      v78 = v94;
      v6[3] = v77;
      v79 = (v75 >> 1) | ((v93 | ((v78 | (v95 << 8)) << 8)) << 7);
      result = (unsigned int)(v9 + 1);
      v6[4] = v79;
      return result;
    case 0xF:
      *v6 = 4;
      break;
    default:
      return (unsigned int)(v9 + 1);
  }
  return (unsigned int)(v9 + 1);
}

