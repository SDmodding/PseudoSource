// File Line: 251
// RVA: 0x997750
bool __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *this)
{
  __int64 Index; // rdx

  Index = this->Index;
  return Index < 0 || Index >= this->pArray->Ranges.Data.Size;
}

// File Line: 438
// RVA: 0x8FEB00
void __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *this)
{
  __int64 Index; // rdx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *pArray; // rbx
  unsigned __int64 Size; // r8

  Index = this->Index;
  if ( Index >= 0 )
  {
    pArray = this->pArray;
    if ( Index < this->pArray->Ranges.Data.Size )
    {
      Size = pArray->Ranges.Data.Size;
      if ( Size == 1 )
      {
        Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->pArray->Ranges.Data,
          0i64);
      }
      else
      {
        memmove(&pArray->Ranges.Data.Data[Index], &pArray->Ranges.Data.Data[Index + 1], 24 * (Size - Index - 1));
        --pArray->Ranges.Data.Size;
      }
    }
  }
}

// File Line: 445
// RVA: 0x8CD2F0
unsigned __int64 __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        __int64 index)
{
  unsigned __int64 v3; // r11
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // r9
  __int64 v6; // rbx
  Scaleform::RangeData<void *> *v7; // r10
  int v8; // eax
  __int64 v9; // rdx
  Scaleform::RangeData<void *> *v10; // r9
  int v11; // eax

  v3 = 0i64;
  v4 = this->Ranges.Data.Size - 1;
  if ( this->Ranges.Data.Size != 1 )
  {
    while ( v4 != -1i64 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = this->Ranges.Data.Data[v5].Index;
      v7 = &this->Ranges.Data.Data[v5];
      if ( index < v6 )
        goto LABEL_6;
      if ( index <= (signed __int64)(v7->Length + v6 - 1) )
        return (v4 + v3) >> 1;
      if ( index >= v6 )
        v8 = LODWORD(v7->Length) - index + v6 - 1;
      else
LABEL_6:
        v8 = v6 - index;
      if ( !v8 )
        return (v4 + v3) >> 1;
      if ( v8 >= 0 )
        v4 = v5 - 1;
      else
        v3 = v5 + 1;
      if ( v3 >= v4 )
        break;
    }
  }
  if ( v3 == v4 )
  {
    v9 = this->Ranges.Data.Data[v3].Index;
    v10 = &this->Ranges.Data.Data[v3];
    if ( index < v9 )
      goto LABEL_17;
    if ( index <= (signed __int64)(v10->Length + v9 - 1) )
      return v3;
    if ( index >= v9 )
      v11 = LODWORD(v10->Length) - index + LODWORD(v10->Index) - 1;
    else
LABEL_17:
      v11 = v9 - index;
    if ( !v11 )
      return v3;
  }
  return -1i64;
}

// File Line: 491
// RVA: 0x8CC450
unsigned __int64 __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        __int64 index)
{
  unsigned __int64 Size; // r10
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // r11
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // rdx
  __int64 v9; // rdi
  Scaleform::RangeData<void *> *v10; // rbx
  int v11; // eax
  __int64 v12; // rdx
  Scaleform::RangeData<void *> *v13; // rbx
  int v14; // eax
  Scaleform::RangeData<void *> *v15; // r9
  __int64 v16; // rdx
  int v17; // eax

  Size = this->Ranges.Data.Size;
  if ( !Size )
    return 0i64;
  v5 = 0i64;
  v6 = 0i64;
  v7 = Size - 1;
  if ( v7 )
  {
    while ( v7 != -1i64 )
    {
      v8 = (v7 + v5) >> 1;
      v9 = this->Ranges.Data.Data[v8].Index;
      v10 = &this->Ranges.Data.Data[v8];
      if ( index < v9 )
        goto LABEL_8;
      if ( index <= (signed __int64)(v10->Length + v9 - 1) )
        return (v7 + v5) >> 1;
      if ( index >= v9 )
        v11 = LODWORD(v10->Length) - index + v9 - 1;
      else
LABEL_8:
        v11 = v9 - index;
      if ( !v11 )
        return (v7 + v5) >> 1;
      if ( v11 >= 0 )
      {
        v7 = v8 - 1;
      }
      else
      {
        v6 = v5;
        v5 = v8 + 1;
      }
      if ( v5 >= v7 )
        break;
    }
  }
  if ( v5 == v7 )
  {
    v12 = this->Ranges.Data.Data[v5].Index;
    v13 = &this->Ranges.Data.Data[v5];
    if ( index < v12 )
      goto LABEL_19;
    if ( index <= (signed __int64)(v13->Length + v12 - 1) )
      return v5;
    if ( index >= v12 )
      v14 = LODWORD(v13->Length) - index + LODWORD(v13->Index) - 1;
    else
LABEL_19:
      v14 = v12 - index;
    if ( !v14 )
      return v5;
  }
  if ( v6 < v7 )
  {
    v15 = &this->Ranges.Data.Data[v6 + 1];
    do
    {
      v16 = v15->Index;
      if ( index < v15->Index )
        goto LABEL_29;
      if ( index <= (signed __int64)(v15->Length + v16 - 1) )
        return v6;
      if ( index >= v16 )
        v17 = LODWORD(v15->Length) - index + LODWORD(v15->Index) - 1;
      else
LABEL_29:
        v17 = v16 - index;
      if ( v17 >= 0 )
        break;
      ++v6;
      ++v15;
    }
    while ( v6 < v7 );
  }
  return v6;
}

// File Line: 539
// RVA: 0x90A7F0
void __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::RangeData<void *> *range)
{
  unsigned __int64 Size; // r15
  __int64 Index; // rbx
  __int64 NearestRangeIndex; // rax
  __int64 v7; // rdi
  __int64 v8; // r10
  Scaleform::RangeData<void *> *v9; // rdx
  unsigned __int64 v10; // r8
  signed __int64 v11; // rax
  Scaleform::RangeData<void *> *v12; // rcx
  signed __int64 v13; // r15
  __int64 v14; // r12
  void *Data; // r13
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // r12
  unsigned __int64 v19; // r15
  signed __int64 v20; // rdx
  __int64 v21; // rbx
  unsigned __int64 v22; // r8
  Scaleform::RangeData<void *> *v23; // rdx
  unsigned __int64 v24; // rax
  unsigned __int64 Length; // rax
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rcx
  __int64 v28; // r8
  int v29; // eax
  __int64 v30; // rbx
  Scaleform::RangeData<void *> *v31; // r9
  unsigned __int64 v32; // rax
  unsigned __int64 v33; // rdx
  __int64 v34; // r9
  Scaleform::RangeData<void *> *v35; // r8
  __int64 v36; // rax
  __int64 v37; // rdx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *pArray; // rbx
  __int64 v39; // rdi
  unsigned __int64 v40; // rdx
  unsigned __int64 v41; // rcx
  Scaleform::RangeData<void *> *v42; // r9
  __int64 v43; // rdx
  __int64 v44; // rcx
  Scaleform::RangeData<void *> *v45; // r9
  unsigned __int64 v46; // r8
  Scaleform::RangeData<void *> *v47; // rcx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v48; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v49; // [rsp+40h] [rbp-10h] BYREF

  Size = this->Ranges.Data.Size;
  if ( !Size )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Ranges,
      0i64,
      range);
    return;
  }
  Index = range->Index;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        this,
                        range->Index);
  v7 = NearestRangeIndex;
  v48.pArray = this;
  if ( NearestRangeIndex >= 0 )
  {
    if ( NearestRangeIndex < Size )
    {
      v48.Index = NearestRangeIndex;
    }
    else
    {
      v7 = Size - 1;
      v48.Index = Size - 1;
    }
  }
  else
  {
    v7 = 0i64;
    v48.Index = 0i64;
  }
  v8 = v7;
  v9 = &this->Ranges.Data.Data[v7];
  if ( Index < v9->Index
    || (v10 = range->Length, (__int64)(v10 + Index - 1) > (signed __int64)(v9->Length - 1 + v9->Index)) )
  {
    if ( Index >= v9->Index )
    {
      Length = v9->Length;
      if ( Index <= (__int64)(Length + v9->Index - 1) )
      {
        v26 = v9->Index + Length - Index;
        v27 = v9->Length;
        if ( v26 <= v27 )
          v9->Length = v27 - v26;
        else
          v9->Length = 0i64;
LABEL_31:
        if ( v7 < (signed __int64)this->Ranges.Data.Size )
          v48.Index = ++v7;
        v49 = v48;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &this->Ranges,
          v7,
          range);
        goto LABEL_50;
      }
    }
    v28 = v9->Index;
    if ( Index < v9->Index )
      goto LABEL_42;
    if ( Index <= (signed __int64)(v9->Length + v28 - 1) )
      goto LABEL_46;
    if ( Index >= v28 )
      v29 = LODWORD(v9->Length) - Index + v28 - 1;
    else
LABEL_42:
      v29 = v28 - Index;
    if ( v29 > 0 )
    {
LABEL_45:
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->Ranges,
        v7,
        range);
      goto LABEL_49;
    }
LABEL_46:
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Ranges,
      v7 + 1,
      range);
    if ( v7 < (signed __int64)this->Ranges.Data.Size )
      ++v7;
    v48.Index = v7;
    goto LABEL_49;
  }
  v11 = v9->Length;
  if ( v9->Index != Index )
  {
    if ( v9->Index + v11 > (__int64)(v10 + Index) )
    {
      v13 = v9->Length;
      v14 = v9->Index;
      Data = v9->Data;
      v16 = v9->Index + v13 - Index;
      if ( v16 <= v13 )
        v9->Length -= v16;
      else
        v9->Length = 0i64;
      v17 = range->Length + this->Ranges.Data.Data[v8].Length;
      if ( v17 > v13 )
        v17 = v13;
      v18 = v17 + v14;
      v19 = v13 - v17;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->Ranges,
        v7 + 1,
        range);
      v20 = this->Ranges.Data.Size;
      if ( v7 < v20 )
        ++v7;
      v48.Index = v7;
      v49 = v48;
      v21 = v7 + 1;
      Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Ranges.Data,
        v20 + 1);
      v22 = this->Ranges.Data.Size;
      if ( v7 + 1 < v22 - 1 )
        memmove(&this->Ranges.Data.Data[v21 + 1], &this->Ranges.Data.Data[v21], 24 * (v22 - v21 - 1));
      v23 = &this->Ranges.Data.Data[v21];
      if ( v23 )
      {
        v23->Index = v18;
        v23->Length = v19;
        v23->Data = Data;
      }
      if ( v7 < (signed __int64)this->Ranges.Data.Size )
      {
        ++v7;
        v48.Index = v21;
      }
      goto LABEL_52;
    }
    v24 = v9->Length;
    if ( v10 <= v24 )
      v9->Length = v24 - v10;
    else
      v9->Length = 0i64;
    goto LABEL_31;
  }
  if ( (__int64)v10 > v11 )
    v10 = v9->Length;
  v9->Index += v10;
  v9->Length = v11 - v10;
  v12 = &this->Ranges.Data.Data[v8];
  if ( v12->Length )
    goto LABEL_45;
  v12->Index = range->Index;
  v12->Length = range->Length;
  v12->Data = range->Data;
LABEL_49:
  v49 = v48;
LABEL_50:
  if ( v7 < (signed __int64)this->Ranges.Data.Size )
    v48.Index = ++v7;
LABEL_52:
  if ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v48) )
  {
    v30 = v7;
    do
    {
      v31 = &this->Ranges.Data.Data[v30];
      if ( v31->Index < range->Index
        || (signed __int64)(v31->Length + v31->Index - 1) > (signed __int64)(range->Length + range->Index - 1) )
      {
        break;
      }
      if ( v7 >= 0 )
      {
        v32 = this->Ranges.Data.Size;
        if ( v7 < v32 )
        {
          if ( v32 == 1 )
          {
            Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &this->Ranges.Data,
              0i64);
          }
          else
          {
            memmove(&this->Ranges.Data.Data[v30], &v31[1], 24 * (v32 - v7 - 1));
            --this->Ranges.Data.Size;
          }
        }
      }
    }
    while ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v48) );
  }
  if ( v7 >= 0 && v7 < this->Ranges.Data.Size )
  {
    v33 = range->Length;
    v34 = v33 + range->Index - 1;
    v35 = &this->Ranges.Data.Data[v7];
    if ( v34 >= v35->Index )
    {
      v36 = v35->Length;
      if ( v34 <= v36 + v35->Index - 1 )
      {
        v37 = range->Index + v33 - v35->Index;
        if ( v37 > v36 )
          v37 = v35->Length;
        v35->Index += v37;
        v35->Length = v36 - v37;
      }
    }
  }
  pArray = v49.pArray;
  v48 = v49;
  v39 = v49.Index;
  if ( v49.Index >= 0 )
  {
    v40 = v49.Index - 1;
    v48.Index = v49.Index - 1;
    if ( v49.Index - 1 >= 0 )
    {
      v41 = v49.pArray->Ranges.Data.Size;
      if ( v40 < v41 )
      {
        v42 = &v49.pArray->Ranges.Data.Data[v40];
        if ( v42->Length )
        {
          if ( v42->Index + v42->Length == range->Index && v42->Data == v49.pArray->Ranges.Data.Data[v49.Index].Data )
          {
            v42->Length += range->Length;
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(&v49);
            v49 = v48;
            v39 = v48.Index;
            pArray = v48.pArray;
          }
        }
        else
        {
          v39 = v49.Index - 1;
          if ( v41 == 1 )
          {
            Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &v49.pArray->Ranges.Data,
              0i64);
          }
          else
          {
            memmove(v42, &v42[1], 24 * (v41 - v49.Index));
            --pArray->Ranges.Data.Size;
          }
        }
      }
    }
  }
  v49.pArray = pArray;
  v43 = v39;
  v49.Index = v39;
  v44 = pArray->Ranges.Data.Size;
  if ( v39 < v44 )
  {
    v43 = v39 + 1;
    v49.Index = v39 + 1;
  }
  if ( v43 >= 0 && v43 < (unsigned __int64)v44 )
  {
    v45 = &pArray->Ranges.Data.Data[v43];
    v46 = v45->Length;
    if ( v46 )
    {
      v47 = &pArray->Ranges.Data.Data[v39];
      if ( v47->Index + v47->Length == v45->Index && v47->Data == v45->Data )
      {
        v47->Length += v46;
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(&v49);
      }
    }
    else if ( v44 == 1 )
    {
      Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &pArray->Ranges.Data,
        0i64);
    }
    else
    {
      memmove(v45, &v45[1], 24 * (v44 - v43 - 1));
      --pArray->Ranges.Data.Size;
    }
  }
}

// File Line: 727
// RVA: 0x977E20
void __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *this,
        __int64 startPos,
        unsigned __int64 length)
{
  unsigned __int64 Size; // rdi
  __int64 NearestRangeIndex; // rax
  bool v8; // sf
  bool v9; // of
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v10; // r8
  __int64 Index; // r9
  unsigned __int64 v12; // rdx
  signed __int64 v13; // rcx
  __int64 v14; // rdx

  Size = this->Ranges.Data.Size;
  if ( !Size )
    return;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this,
                        startPos);
  if ( NearestRangeIndex < 0 )
  {
    NearestRangeIndex = 0i64;
LABEL_6:
    v9 = __OFSUB__(NearestRangeIndex, Size);
    v8 = (__int64)(NearestRangeIndex - Size) < 0;
    goto LABEL_7;
  }
  v9 = __OFSUB__(NearestRangeIndex, Size);
  v8 = (__int64)(NearestRangeIndex - Size) < 0;
  if ( NearestRangeIndex >= Size )
  {
    NearestRangeIndex = Size - 1;
    goto LABEL_6;
  }
LABEL_7:
  if ( v8 != v9 )
  {
    v10 = &this->Ranges.Data.Data[NearestRangeIndex];
    if ( v10 )
    {
      if ( (Index = v10->Index, startPos >= v10->Index) && (v12 = v10->Length, startPos <= (__int64)(v12 + Index - 1))
        || (v12 = v10->Length, v12 + Index == startPos) )
      {
        v10->Length = v12 + length;
      }
    }
  }
  v13 = this->Ranges.Data.Size;
  if ( NearestRangeIndex < v13 )
    ++NearestRangeIndex;
  v14 = NearestRangeIndex;
  while ( NearestRangeIndex >= 0 && NearestRangeIndex < (unsigned __int64)v13 )
  {
    this->Ranges.Data.Data[v14].Index += length;
    v13 = this->Ranges.Data.Size;
    if ( NearestRangeIndex < v13 )
    {
      ++NearestRangeIndex;
      ++v14;
    }
  }
}

// File Line: 748
// RVA: 0x9AA110
void __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *this,
        __int64 startPos,
        signed __int64 length)
{
  unsigned __int64 Size; // r15
  __int64 NearestRangeIndex; // rax
  __int64 v8; // rbx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v9; // rdx
  __int64 Index; // r9
  unsigned __int64 v11; // r8
  signed __int64 v12; // rcx
  bool v13; // zf
  signed __int64 v14; // rax
  unsigned __int64 v15; // rcx
  int v16; // eax
  __int64 v17; // r15
  __int64 v18; // rcx
  __int64 v19; // r8
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v20; // rdx
  signed __int64 v21; // rax
  signed __int64 v22; // rsi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *v23; // rdi
  signed __int64 v24; // rbx
  char *v25; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *v26; // rcx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v27; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v28; // r8
  __int64 v29; // rcx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v30; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *v31[2]; // [rsp+40h] [rbp-30h]
  __int64 v32; // [rsp+50h] [rbp-20h]
  __int64 v33; // [rsp+58h] [rbp-18h]
  __int64 v34; // [rsp+60h] [rbp-10h]

  Size = this->Ranges.Data.Size;
  if ( !Size )
    return;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this,
                        startPos);
  v8 = NearestRangeIndex;
  v30.pArray = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this;
  if ( NearestRangeIndex >= 0 )
  {
    if ( NearestRangeIndex < Size )
    {
      v30.Index = NearestRangeIndex;
    }
    else
    {
      v8 = Size - 1;
      v30.Index = Size - 1;
    }
  }
  else
  {
    v8 = 0i64;
    v30.Index = 0i64;
  }
  if ( length == -1 )
    length = 0x7FFFFFFFFFFFFFFFi64 - startPos;
  v32 = startPos;
  v33 = length;
  v34 = 0i64;
  v9 = &this->Ranges.Data.Data[v8];
  Index = v9->Index;
  if ( startPos < v9->Index )
    goto LABEL_41;
  v11 = v9->Length;
  if ( startPos + length - 1 <= (__int64)(v11 + Index - 1) )
  {
    if ( Index == startPos )
    {
      v12 = length;
      if ( length > (__int64)v11 )
        v12 = v9->Length;
      v9->Index = Index + v12;
      v13 = v9->Length == v12;
      v9->Length -= v12;
      if ( !v13 )
        goto LABEL_46;
      goto LABEL_15;
    }
    if ( (__int64)(v11 + Index) <= startPos + length )
    {
      if ( length <= v11 )
        v9->Length = v11 - length;
      else
        v9->Length = 0i64;
      v14 = this->Ranges.Data.Size;
      if ( v8 < v14 )
        v30.Index = ++v8;
      *(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *)v31 = v30;
      if ( v8 < v14 )
        v30.Index = ++v8;
      goto LABEL_47;
    }
    if ( length <= v11 )
      v9->Length = v11 - length;
    else
      v9->Length = 0i64;
    if ( !v9->Length )
    {
LABEL_15:
      if ( v8 >= 0 && v8 < this->Ranges.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->Ranges,
          v8);
      goto LABEL_46;
    }
LABEL_44:
    if ( v8 < (signed __int64)this->Ranges.Data.Size )
      v30.Index = ++v8;
    goto LABEL_46;
  }
  if ( startPos < Index )
    goto LABEL_41;
  v15 = v9->Length;
  if ( startPos <= (__int64)(v15 + Index - 1) )
  {
    if ( Index + v15 - startPos <= v15 )
      v9->Length = startPos - Index;
    else
      v9->Length = 0i64;
    if ( !v9->Length )
      goto LABEL_15;
    goto LABEL_44;
  }
  if ( startPos < Index )
    goto LABEL_41;
  if ( startPos <= (signed __int64)(v9->Length + Index - 1) )
    goto LABEL_44;
  if ( startPos >= Index )
    v16 = LODWORD(v9->Length) - startPos + Index - 1;
  else
LABEL_41:
    v16 = Index - startPos;
  if ( v16 <= 0 )
    goto LABEL_44;
LABEL_46:
  *(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *)v31 = v30;
LABEL_47:
  if ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v30) )
  {
    v17 = v8;
    do
    {
      v18 = this->Ranges.Data.Data[v17].Index;
      if ( v18 < startPos || (signed __int64)(this->Ranges.Data.Data[v17].Length + v18 - 1) > length + startPos - 1 )
        break;
      if ( v8 >= 0 && v8 < this->Ranges.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->Ranges,
          v8);
    }
    while ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v30) );
  }
  if ( v8 >= 0 && v8 < this->Ranges.Data.Size )
  {
    v19 = length + startPos - 1;
    v20 = &this->Ranges.Data.Data[v8];
    if ( v19 >= v20->Index )
    {
      v21 = v20->Length;
      if ( v19 <= v21 + v20->Index - 1 )
      {
        v22 = length + startPos - v20->Index;
        if ( v22 > v21 )
          v22 = v20->Length;
        v20->Index += v22;
        v20->Length = v21 - v22;
      }
    }
  }
  v23 = v31[0];
  v24 = (signed __int64)v31[1];
  if ( (__int64)v31[1] >= 0 )
  {
    v25 = (char *)&v31[1][-1].Data.Policy.Capacity + 7;
    if ( (__int64)&v31[1][-1].Data.Policy.Capacity + 7 >= 0 )
    {
      v26 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *)v31[0]->Data.Size;
      if ( v25 < (char *)v26 && v31[1] < v26 )
      {
        v27 = &v31[0]->Data.Data[(_QWORD)v25];
        v28 = &v31[0]->Data.Data[(__int64)v31[1]];
        if ( v27->Index + v27->Length == v28->Index - length && v27->Data.pObject == v28->Data.pObject )
        {
          v27->Length += v28->Length;
          if ( v24 < v23->Data.Size )
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
              v23,
              v24);
        }
      }
    }
  }
  v29 = v24;
  while ( v24 >= 0 && v24 < v23->Data.Size )
  {
    v23->Data.Data[v29].Index -= length;
    if ( v24 < (signed __int64)v23->Data.Size )
    {
      ++v24;
      ++v29;
    }
  }
}

// File Line: 872
// RVA: 0x8BC580
void __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::ClearRange(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        __int64 startPos,
        signed __int64 length)
{
  unsigned __int64 Size; // rbp
  __int64 NearestRangeIndex; // rax
  signed __int64 v8; // rbx
  signed __int64 v9; // r10
  Scaleform::RangeData<void *> *v10; // r8
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // rax
  Scaleform::RangeData<void *> *v14; // rcx
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rbp
  __int64 Index; // r15
  void *Data; // r12
  unsigned __int64 v19; // rax
  signed __int64 v20; // rax
  __int64 v21; // r15
  unsigned __int64 v22; // rbp
  signed __int64 v23; // rdx
  unsigned __int64 v24; // r8
  Scaleform::RangeData<void *> *v25; // rdx
  bool v26; // cc
  unsigned __int64 v27; // rax
  signed __int64 v28; // rax
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // rax
  unsigned __int64 v31; // rcx
  signed __int64 v32; // r15
  Scaleform::RangeData<void *> *v33; // r9
  unsigned __int64 v34; // rax
  __int64 v35; // r8
  Scaleform::RangeData<void *> *v36; // rdx
  signed __int64 v37; // rax
  signed __int64 v38; // rsi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v39; // [rsp+28h] [rbp-40h] BYREF

  Size = this->Ranges.Data.Size;
  if ( !Size )
    return;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        this,
                        startPos);
  v8 = NearestRangeIndex;
  v39.pArray = this;
  if ( NearestRangeIndex >= 0 )
  {
    if ( NearestRangeIndex < Size )
    {
      v39.Index = NearestRangeIndex;
    }
    else
    {
      v8 = Size - 1;
      v39.Index = Size - 1;
    }
  }
  else
  {
    v8 = 0i64;
    v39.Index = 0i64;
  }
  if ( length == -1 )
    length = 0x7FFFFFFFFFFFFFFFi64 - startPos;
  v9 = v8;
  v10 = &this->Ranges.Data.Data[v8];
  if ( startPos < v10->Index || (v11 = v10->Length, startPos + length - 1 > (__int64)(v11 + v10->Index - 1)) )
  {
    if ( startPos < v10->Index || (v29 = v10->Length, startPos > (__int64)(v29 + v10->Index - 1)) )
    {
      v26 = v8 < (__int64)Size;
LABEL_44:
      if ( v26 )
        v39.Index = ++v8;
      goto LABEL_46;
    }
    v30 = v10->Index + v29 - startPos;
    v31 = v10->Length;
    if ( v30 <= v31 )
      v10->Length = v31 - v30;
    else
      v10->Length = 0i64;
  }
  else
  {
    if ( v10->Index == startPos )
    {
      v12 = v10->Length;
      v13 = length;
      if ( length > v12 )
        v13 = v10->Length;
      v10->Index += v13;
      v10->Length = v12 - v13;
      v14 = &this->Ranges.Data.Data[v9];
      if ( !v14->Length )
      {
        if ( v8 >= 0 )
        {
          v15 = this->Ranges.Data.Size;
          if ( v8 < v15 )
          {
            if ( v15 == 1 )
            {
              Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                &this->Ranges.Data,
                0i64);
            }
            else
            {
              memmove(v14, &v14[1], 24 * (v15 - v8 - 1));
              --this->Ranges.Data.Size;
            }
          }
        }
        goto LABEL_46;
      }
      goto LABEL_32;
    }
    if ( (__int64)(v10->Index + v11) > startPos + length )
    {
      v16 = v10->Length;
      Index = v10->Index;
      Data = v10->Data;
      v19 = v10->Index + v16 - startPos;
      if ( v19 <= v16 )
        v10->Length -= v19;
      else
        v10->Length = 0i64;
      v20 = length + this->Ranges.Data.Data[v9].Length;
      if ( v20 > (__int64)v16 )
        v20 = v16;
      v21 = v20 + Index;
      v22 = v16 - v20;
      v23 = this->Ranges.Data.Size;
      if ( v8 < v23 )
        v39.Index = ++v8;
      Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Ranges.Data,
        v23 + 1);
      v24 = this->Ranges.Data.Size;
      if ( v8 < v24 - 1 )
        memmove(&this->Ranges.Data.Data[v8 + 1], &this->Ranges.Data.Data[v8], 24 * (v24 - v8 - 1));
      v25 = &this->Ranges.Data.Data[v8];
      if ( v25 )
      {
        v25->Index = v21;
        v25->Length = v22;
        v25->Data = Data;
      }
LABEL_32:
      v26 = v8 < (signed __int64)this->Ranges.Data.Size;
      goto LABEL_44;
    }
    v27 = v10->Length;
    if ( length <= v27 )
      v10->Length = v27 - length;
    else
      v10->Length = 0i64;
  }
  v28 = this->Ranges.Data.Size;
  if ( v8 < v28 )
  {
    v39.Index = ++v8;
    v26 = v8 < v28;
    goto LABEL_44;
  }
LABEL_46:
  if ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v39) )
  {
    v32 = v8;
    do
    {
      v33 = &this->Ranges.Data.Data[v32];
      if ( v33->Index < startPos || (signed __int64)(v33->Length + v33->Index - 1) > length + startPos - 1 )
        break;
      if ( v8 >= 0 )
      {
        v34 = this->Ranges.Data.Size;
        if ( v8 < v34 )
        {
          if ( v34 == 1 )
          {
            Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &this->Ranges.Data,
              0i64);
          }
          else
          {
            memmove(&this->Ranges.Data.Data[v32], &v33[1], 24 * (v34 - v8 - 1));
            --this->Ranges.Data.Size;
          }
        }
      }
    }
    while ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v39) );
  }
  if ( v8 >= 0 && v8 < this->Ranges.Data.Size )
  {
    v35 = length + startPos - 1;
    v36 = &this->Ranges.Data.Data[v8];
    if ( v35 >= v36->Index )
    {
      v37 = v36->Length;
      if ( v35 <= v37 + v36->Index - 1 )
      {
        v38 = length + startPos - v36->Index;
        if ( v38 > v37 )
          v38 = v36->Length;
        v36->Index += v38;
        v36->Length = v37 - v38;
      }
    }
  }
}

