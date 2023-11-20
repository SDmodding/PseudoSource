// File Line: 251
// RVA: 0x997750
bool __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *this)
{
  __int64 v1; // rdx

  v1 = this->Index;
  return v1 < 0 || v1 >= this->pArray->Ranges.Data.Size;
}

// File Line: 438
// RVA: 0x8FEB00
void __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *this)
{
  __int64 v1; // rdx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v2; // rbx
  unsigned __int64 v3; // r8

  v1 = this->Index;
  if ( v1 >= 0 )
  {
    v2 = this->pArray;
    if ( v1 < this->pArray->Ranges.Data.Size )
    {
      v3 = v2->Ranges.Data.Size;
      if ( v3 == 1 )
      {
        Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->pArray->Ranges.Data,
          0i64);
      }
      else
      {
        memmove(&v2->Ranges.Data.Data[v1], &v2->Ranges.Data.Data[v1 + 1], 24 * (v3 - v1 - 1));
        --v2->Ranges.Data.Size;
      }
    }
  }
}

// File Line: 445
// RVA: 0x8CD2F0
unsigned __int64 __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this, __int64 index)
{
  __int64 v2; // r8
  unsigned __int64 v3; // r11
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // r9
  __int64 v6; // rbx
  Scaleform::RangeData<void *> *v7; // r10
  int v8; // eax
  __int64 v9; // rdx
  Scaleform::RangeData<void *> *v10; // r9
  int v11; // eax

  v2 = index;
  v3 = 0i64;
  v4 = this->Ranges.Data.Size - 1;
  if ( this->Ranges.Data.Size != 1 )
  {
    while ( v4 != -1i64 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = this->Ranges.Data.Data[v5].Index;
      v7 = &this->Ranges.Data.Data[v5];
      if ( v2 < v6 )
        goto LABEL_25;
      if ( v2 <= (signed __int64)(v7->Length + v6 - 1) )
        return (v4 + v3) >> 1;
      if ( v2 >= v6 )
        v8 = LODWORD(v7->Length) - v2 + v6 - 1;
      else
LABEL_25:
        v8 = v6 - v2;
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
    if ( v2 < v9 )
      goto LABEL_26;
    if ( v2 <= (signed __int64)(v10->Length + v9 - 1) )
      return v3;
    if ( v2 >= v9 )
      v11 = LODWORD(v10->Length) - v2 + LODWORD(v10->Index) - 1;
    else
LABEL_26:
      v11 = v9 - v2;
    if ( !v11 )
      return v3;
  }
  return -1i64;
}

// File Line: 491
// RVA: 0x8CC450
unsigned __int64 __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this, __int64 index)
{
  unsigned __int64 v2; // r10
  __int64 v3; // r8
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

  v2 = this->Ranges.Data.Size;
  v3 = index;
  if ( !v2 )
    return 0i64;
  v5 = 0i64;
  v6 = 0i64;
  v7 = v2 - 1;
  if ( v7 )
  {
    while ( v7 != -1i64 )
    {
      v8 = (v7 + v5) >> 1;
      v9 = this->Ranges.Data.Data[v8].Index;
      v10 = &this->Ranges.Data.Data[v8];
      if ( v3 < v9 )
        goto LABEL_36;
      if ( v3 <= (signed __int64)(v10->Length + v9 - 1) )
        return (v7 + v5) >> 1;
      if ( v3 >= v9 )
        v11 = LODWORD(v10->Length) - v3 + v9 - 1;
      else
LABEL_36:
        v11 = v9 - v3;
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
    if ( v3 < v12 )
      goto LABEL_37;
    if ( v3 <= (signed __int64)(v13->Length + v12 - 1) )
      return v5;
    if ( v3 >= v12 )
      v14 = LODWORD(v13->Length) - v3 + LODWORD(v13->Index) - 1;
    else
LABEL_37:
      v14 = v12 - v3;
    if ( !v14 )
      return v5;
  }
  if ( v6 < v7 )
  {
    v15 = &this->Ranges.Data.Data[v6 + 1];
    do
    {
      v16 = v15->Index;
      if ( v3 < v15->Index )
        goto LABEL_38;
      if ( v3 <= (signed __int64)(v15->Length + v16 - 1) )
        return v6;
      if ( v3 >= v16 )
        v17 = LODWORD(v15->Length) - v3 + LODWORD(v15->Index) - 1;
      else
LABEL_38:
        v17 = v16 - v3;
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
void __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::RangeData<void *> *range)
{
  Scaleform::RangeData<void *> *v2; // r14
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v3; // rsi
  unsigned __int64 v4; // r15
  __int64 v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // rdi
  signed __int64 v8; // r10
  Scaleform::RangeData<void *> *v9; // rdx
  unsigned __int64 v10; // r8
  signed __int64 v11; // rax
  Scaleform::RangeData<void *> *v12; // rcx
  signed __int64 v13; // r15
  __int64 v14; // r12
  void *v15; // r13
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // r12
  unsigned __int64 v19; // r15
  signed __int64 v20; // rdx
  __int64 v21; // rbx
  unsigned __int64 v22; // r8
  Scaleform::RangeData<void *> *v23; // rdx
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rcx
  __int64 v28; // r8
  int v29; // eax
  signed __int64 v30; // rbx
  Scaleform::RangeData<void *> *v31; // r9
  unsigned __int64 v32; // rax
  unsigned __int64 v33; // rdx
  signed __int64 v34; // r9
  Scaleform::RangeData<void *> *v35; // r8
  __int64 v36; // rax
  __int64 v37; // rdx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v38; // rbx
  __int64 v39; // rdi
  unsigned __int64 v40; // rdx
  unsigned __int64 v41; // rcx
  Scaleform::RangeData<void *> *v42; // r9
  signed __int64 v43; // rdx
  __int64 v44; // rcx
  Scaleform::RangeData<void *> *v45; // r9
  unsigned __int64 v46; // r8
  Scaleform::RangeData<void *> *v47; // rcx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v48; // [rsp+30h] [rbp-20h]
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v49; // [rsp+40h] [rbp-10h]

  v2 = range;
  v3 = this;
  v4 = this->Ranges.Data.Size;
  if ( !v4 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Ranges.Data,
      0i64,
      range);
    return;
  }
  v5 = range->Index;
  v6 = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
         this,
         range->Index);
  v7 = v6;
  v48.pArray = v3;
  if ( v6 >= 0 )
  {
    if ( v6 < v4 )
    {
      v48.Index = v6;
    }
    else
    {
      v7 = v4 - 1;
      v48.Index = v4 - 1;
    }
  }
  else
  {
    v7 = 0i64;
    v48.Index = 0i64;
  }
  v8 = v7;
  v9 = &v3->Ranges.Data.Data[v7];
  if ( v5 < v9->Index
    || (v10 = v2->Length, (signed __int64)(v10 + v5 - 1) > (signed __int64)(v9->Length - 1 + v9->Index)) )
  {
    if ( v5 >= v9->Index )
    {
      v25 = v9->Length;
      if ( v5 <= (signed __int64)(v25 + v9->Index - 1) )
      {
        v26 = v9->Index + v25 - v5;
        v27 = v9->Length;
        if ( v26 <= v27 )
          v9->Length = v27 - v26;
        else
          v9->Length = 0i64;
LABEL_31:
        if ( v7 < (signed __int64)v3->Ranges.Data.Size )
          v48.Index = ++v7;
        _mm_store_si128((__m128i *)&v49, (__m128i)v48);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Ranges.Data,
          v7,
          v2);
        goto LABEL_50;
      }
    }
    v28 = v9->Index;
    if ( v5 < v9->Index )
      goto LABEL_93;
    if ( v5 <= (signed __int64)(v9->Length + v28 - 1) )
      goto LABEL_46;
    if ( v5 >= v28 )
      v29 = LODWORD(v9->Length) - v5 + v28 - 1;
    else
LABEL_93:
      v29 = v28 - v5;
    if ( v29 > 0 )
    {
LABEL_45:
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Ranges.Data,
        v7,
        v2);
      goto LABEL_49;
    }
LABEL_46:
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Ranges.Data,
      v7 + 1,
      v2);
    if ( v7 < (signed __int64)v3->Ranges.Data.Size )
      ++v7;
    v48.Index = v7;
    goto LABEL_49;
  }
  v11 = v9->Length;
  if ( v9->Index != v5 )
  {
    if ( v9->Index + v11 > (signed __int64)(v10 + v5) )
    {
      v13 = v9->Length;
      v14 = v9->Index;
      v15 = v9->Data;
      v16 = v9->Index + v13 - v5;
      if ( v16 <= v13 )
        v9->Length -= v16;
      else
        v9->Length = 0i64;
      v17 = v2->Length + v3->Ranges.Data.Data[v8].Length;
      if ( v17 > v13 )
        v17 = v13;
      v18 = v17 + v14;
      v19 = v13 - v17;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Ranges.Data,
        v7 + 1,
        v2);
      v20 = v3->Ranges.Data.Size;
      if ( v7 < v20 )
        ++v7;
      v48.Index = v7;
      _mm_store_si128((__m128i *)&v49, (__m128i)v48);
      v21 = v7 + 1;
      Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v3->Ranges.Data,
        v20 + 1);
      v22 = v3->Ranges.Data.Size;
      if ( v7 + 1 < v22 - 1 )
        memmove(&v3->Ranges.Data.Data[v21 + 1], &v3->Ranges.Data.Data[v21], 24 * (v22 - v21 - 1));
      v23 = &v3->Ranges.Data.Data[v21];
      if ( v23 )
      {
        v23->Index = v18;
        v23->Length = v19;
        v23->Data = v15;
      }
      if ( v7 < (signed __int64)v3->Ranges.Data.Size )
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
  if ( (signed __int64)v10 > v11 )
    v10 = v9->Length;
  v9->Index += v10;
  v9->Length = v11 - v10;
  v12 = &v3->Ranges.Data.Data[v8];
  if ( v12->Length )
    goto LABEL_45;
  v12->Index = v2->Index;
  v12->Length = v2->Length;
  v12->Data = v2->Data;
LABEL_49:
  _mm_store_si128((__m128i *)&v49, (__m128i)v48);
LABEL_50:
  if ( v7 < (signed __int64)v3->Ranges.Data.Size )
    v48.Index = ++v7;
LABEL_52:
  if ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v48) )
  {
    v30 = v7;
    do
    {
      v31 = &v3->Ranges.Data.Data[v30];
      if ( v31->Index < v2->Index
        || (signed __int64)(v31->Length + v31->Index - 1) > (signed __int64)(v2->Length + v2->Index - 1) )
      {
        break;
      }
      if ( v7 >= 0 )
      {
        v32 = v3->Ranges.Data.Size;
        if ( v7 < v32 )
        {
          if ( v32 == 1 )
          {
            Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &v3->Ranges.Data,
              0i64);
          }
          else
          {
            memmove(&v3->Ranges.Data.Data[v30], &v31[1], 24 * (v32 - v7 - 1));
            --v3->Ranges.Data.Size;
          }
        }
      }
    }
    while ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v48) );
  }
  if ( v7 >= 0 && v7 < v3->Ranges.Data.Size )
  {
    v33 = v2->Length;
    v34 = v33 + v2->Index - 1;
    v35 = &v3->Ranges.Data.Data[v7];
    if ( v34 >= v35->Index )
    {
      v36 = v35->Length;
      if ( v34 <= v36 + v35->Index - 1 )
      {
        v37 = v2->Index + v33 - v35->Index;
        if ( v37 > v36 )
          v37 = v35->Length;
        v35->Index += v37;
        v35->Length = v36 - v37;
      }
    }
  }
  v38 = v49.pArray;
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
          if ( v42->Index + v42->Length == v2->Index && v42->Data == v49.pArray->Ranges.Data.Data[v49.Index].Data )
          {
            v42->Length += v2->Length;
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(&v49);
            _mm_store_si128((__m128i *)&v49, (__m128i)v48);
            v39 = v49.Index;
            v38 = v49.pArray;
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
            --v38->Ranges.Data.Size;
          }
        }
      }
    }
  }
  v49.pArray = v38;
  v43 = v39;
  v49.Index = v39;
  v44 = v38->Ranges.Data.Size;
  if ( v39 < v44 )
  {
    v43 = v39 + 1;
    v49.Index = v39 + 1;
  }
  if ( v43 >= 0 && v43 < (unsigned __int64)v44 )
  {
    v45 = &v38->Ranges.Data.Data[v43];
    v46 = v45->Length;
    if ( v46 )
    {
      v47 = &v38->Ranges.Data.Data[v39];
      if ( v47->Index + v47->Length == v45->Index && v47->Data == v45->Data )
      {
        v47->Length += v46;
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(&v49);
      }
    }
    else if ( v44 == 1 )
    {
      Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v38->Ranges.Data,
        0i64);
    }
    else
    {
      memmove(v45, &v45[1], 24 * (v44 - v43 - 1));
      --v38->Ranges.Data.Size;
    }
  }
}

// File Line: 727
// RVA: 0x977E20
void __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *this, __int64 startPos, unsigned __int64 length)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  __int64 v5; // rsi
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v6; // rbx
  signed __int64 v7; // rax
  bool v8; // sf
  unsigned __int8 v9; // of
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v10; // r8
  __int64 v11; // r9
  __int64 v12; // rdx
  signed __int64 v13; // rcx
  signed __int64 v14; // rdx

  v3 = this->Ranges.Data.Size;
  v4 = length;
  v5 = startPos;
  v6 = this;
  if ( !v3 )
    return;
  v7 = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
         (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this,
         startPos);
  if ( v7 < 0 )
  {
    v7 = 0i64;
LABEL_6:
    v9 = __OFSUB__(v7, v3);
    v8 = (signed __int64)(v7 - v3) < 0;
    goto LABEL_7;
  }
  v9 = __OFSUB__(v7, v3);
  v8 = (signed __int64)(v7 - v3) < 0;
  if ( v7 >= v3 )
  {
    v7 = v3 - 1;
    goto LABEL_6;
  }
LABEL_7:
  if ( v8 ^ v9 )
  {
    v10 = &v6->Ranges.Data.Data[v7];
    if ( v10 )
    {
      if ( (v11 = v10->Index, v5 >= v10->Index) && (v12 = v10->Length, v5 <= v12 + v11 - 1)
        || (v12 = v10->Length, v12 + v11 == v5) )
      {
        v10->Length = v12 + v4;
      }
    }
  }
  v13 = v6->Ranges.Data.Size;
  if ( v7 < v13 )
    ++v7;
  v14 = v7;
  while ( v7 >= 0 && v7 < (unsigned __int64)v13 )
  {
    v6->Ranges.Data.Data[v14].Index += v4;
    v13 = v6->Ranges.Data.Size;
    if ( v7 < v13 )
    {
      ++v7;
      ++v14;
    }
  }
}

// File Line: 748
// RVA: 0x9AA110
void __fastcall Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *this, __int64 startPos, unsigned __int64 length)
{
  unsigned __int64 v3; // r14
  __int64 v4; // rsi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v5; // rdi
  unsigned __int64 v6; // r15
  __int64 v7; // rax
  signed __int64 v8; // rbx
  Scaleform::RangeData<void *> *v9; // rdx
  __int64 v10; // r9
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rcx
  bool v13; // zf
  signed __int64 v14; // rax
  unsigned __int64 v15; // rcx
  int v16; // eax
  signed __int64 v17; // r15
  __int64 v18; // rcx
  signed __int64 v19; // r8
  Scaleform::RangeData<void *> *v20; // rdx
  signed __int64 v21; // rax
  signed __int64 v22; // rsi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *v23; // rdi
  unsigned __int64 v24; // rbx
  char *v25; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *v26; // rcx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v27; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v28; // r8
  signed __int64 v29; // rcx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v30; // [rsp+30h] [rbp-40h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *v31[2]; // [rsp+40h] [rbp-30h]
  __int64 v32; // [rsp+50h] [rbp-20h]
  unsigned __int64 v33; // [rsp+58h] [rbp-18h]
  __int64 v34; // [rsp+60h] [rbp-10h]

  v3 = length;
  v4 = startPos;
  v5 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this;
  v6 = this->Ranges.Data.Size;
  if ( !v6 )
    return;
  v7 = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
         (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this,
         startPos);
  v8 = v7;
  v30.pArray = v5;
  if ( v7 >= 0 )
  {
    if ( v7 < v6 )
    {
      v30.Index = v7;
    }
    else
    {
      v8 = v6 - 1;
      v30.Index = v6 - 1;
    }
  }
  else
  {
    v8 = 0i64;
    v30.Index = 0i64;
  }
  if ( v3 == -1i64 )
    v3 = 0x7FFFFFFFFFFFFFFFi64 - v4;
  v32 = v4;
  v33 = v3;
  v34 = 0i64;
  v9 = &v5->Ranges.Data.Data[v8];
  v10 = v9->Index;
  if ( v4 < v9->Index )
    goto LABEL_77;
  v11 = v9->Length;
  if ( (signed __int64)(v4 + v3 - 1) <= (signed __int64)(v11 + v10 - 1) )
  {
    if ( v10 == v4 )
    {
      v12 = v3;
      if ( (signed __int64)v3 > (signed __int64)v11 )
        v12 = v9->Length;
      v9->Index = v10 + v12;
      v13 = v9->Length == v12;
      v9->Length -= v12;
      if ( !v13 )
        goto LABEL_46;
      goto LABEL_15;
    }
    if ( (signed __int64)(v11 + v10) <= (signed __int64)(v4 + v3) )
    {
      if ( v3 <= v11 )
        v9->Length = v11 - v3;
      else
        v9->Length = 0i64;
      v14 = v5->Ranges.Data.Size;
      if ( v8 < v14 )
        v30.Index = ++v8;
      _mm_store_si128((__m128i *)v31, (__m128i)v30);
      if ( v8 < v14 )
        v30.Index = ++v8;
      goto LABEL_47;
    }
    if ( v3 <= v11 )
      v9->Length = v11 - v3;
    else
      v9->Length = 0i64;
    if ( !v9->Length )
    {
LABEL_15:
      if ( v8 >= 0 && v8 < v5->Ranges.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *)v5,
          v8);
      goto LABEL_46;
    }
LABEL_44:
    if ( v8 < (signed __int64)v5->Ranges.Data.Size )
      v30.Index = ++v8;
    goto LABEL_46;
  }
  if ( v4 < v10 )
    goto LABEL_77;
  v15 = v9->Length;
  if ( v4 <= (signed __int64)(v15 + v10 - 1) )
  {
    if ( v10 + v15 - v4 <= v15 )
      v9->Length = v4 - v10;
    else
      v9->Length = 0i64;
    if ( !v9->Length )
      goto LABEL_15;
    goto LABEL_44;
  }
  if ( v4 < v10 )
    goto LABEL_77;
  if ( v4 <= (signed __int64)(v9->Length + v10 - 1) )
    goto LABEL_44;
  if ( v4 >= v10 )
    v16 = LODWORD(v9->Length) - v4 + v10 - 1;
  else
LABEL_77:
    v16 = v10 - v4;
  if ( v16 <= 0 )
    goto LABEL_44;
LABEL_46:
  _mm_store_si128((__m128i *)v31, (__m128i)v30);
LABEL_47:
  if ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v30) )
  {
    v17 = v8;
    do
    {
      v18 = v5->Ranges.Data.Data[v17].Index;
      if ( v18 < v4 || (signed __int64)(v5->Ranges.Data.Data[v17].Length + v18 - 1) > (signed __int64)(v3 + v4 - 1) )
        break;
      if ( v8 >= 0 && v8 < v5->Ranges.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *)v5,
          v8);
    }
    while ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v30) );
  }
  if ( v8 >= 0 && v8 < v5->Ranges.Data.Size )
  {
    v19 = v3 + v4 - 1;
    v20 = &v5->Ranges.Data.Data[v8];
    if ( v19 >= v20->Index )
    {
      v21 = v20->Length;
      if ( v19 <= v21 + v20->Index - 1 )
      {
        v22 = v3 + v4 - v20->Index;
        if ( v22 > v21 )
          v22 = v20->Length;
        v20->Index += v22;
        v20->Length = v21 - v22;
      }
    }
  }
  v23 = v31[0];
  v24 = (unsigned __int64)v31[1];
  if ( (_QWORD)v31[1] >= 0i64 )
  {
    v25 = (char *)&v31[1][-1].Data.Policy.Capacity + 7;
    if ( (_QWORD)v31[1] - 1 >= 0i64 )
    {
      v26 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2>,Scaleform::ArrayDefaultPolicy> > *)v31[0]->Data.Size;
      if ( v25 < (char *)v26 && v31[1] < v26 )
      {
        v27 = &v31[0]->Data.Data[(_QWORD)v25];
        v28 = &v31[0]->Data.Data[(_QWORD)v31[1]];
        if ( v27->Index + v27->Length == v28->Index - v3 && v27->Data.pObject == v28->Data.pObject )
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
  while ( (v24 & 0x8000000000000000ui64) == 0i64 && v24 < v23->Data.Size )
  {
    v23->Data.Data[v29].Index -= v3;
    if ( (signed __int64)v24 < (signed __int64)v23->Data.Size )
    {
      ++v24;
      ++v29;
    }
  }
}

// File Line: 872
// RVA: 0x8BC580
void __fastcall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::ClearRange(Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this, __int64 startPos, unsigned __int64 length)
{
  unsigned __int64 v3; // r14
  __int64 v4; // rsi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v5; // rdi
  unsigned __int64 v6; // rbp
  __int64 v7; // rax
  signed __int64 v8; // rbx
  signed __int64 v9; // r10
  signed __int64 v10; // r8
  __int64 v11; // rax
  signed __int64 v12; // rcx
  unsigned __int64 v13; // rax
  Scaleform::RangeData<void *> *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rbp
  __int64 v17; // r15
  void *v18; // r12
  unsigned __int64 v19; // rax
  signed __int64 v20; // rax
  __int64 v21; // r15
  unsigned __int64 v22; // rbp
  signed __int64 v23; // rdx
  unsigned __int64 v24; // r8
  Scaleform::RangeData<void *> *v25; // rdx
  bool v26; // sf
  unsigned __int8 v27; // of
  unsigned __int64 v28; // rax
  signed __int64 v29; // rax
  __int64 v30; // rax
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // rcx
  __int64 v33; // rdx
  __int64 v34; // rcx
  signed __int64 v35; // r15
  Scaleform::RangeData<void *> *v36; // r9
  unsigned __int64 v37; // rax
  signed __int64 v38; // r8
  Scaleform::RangeData<void *> *v39; // rdx
  signed __int64 v40; // rax
  signed __int64 v41; // rsi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v42; // [rsp+28h] [rbp-40h]

  v3 = length;
  v4 = startPos;
  v5 = this;
  v6 = this->Ranges.Data.Size;
  if ( !v6 )
    return;
  v7 = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
         this,
         startPos);
  v8 = v7;
  v42.pArray = v5;
  if ( v7 >= 0 )
  {
    if ( v7 < v6 )
    {
      v42.Index = v7;
    }
    else
    {
      v8 = v6 - 1;
      v42.Index = v6 - 1;
    }
  }
  else
  {
    v8 = 0i64;
    v42.Index = 0i64;
  }
  if ( v3 == -1i64 )
    v3 = 0x7FFFFFFFFFFFFFFFi64 - v4;
  v9 = v8;
  v10 = (signed __int64)&v5->Ranges.Data.Data[v8];
  if ( v4 < *(_QWORD *)v10 || (v11 = *(_QWORD *)(v10 + 8), (signed __int64)(v4 + v3 - 1) > v11 + *(_QWORD *)v10 - 1i64) )
  {
    if ( v4 < *(_QWORD *)v10 || (v30 = *(_QWORD *)(v10 + 8), v4 > v30 + *(_QWORD *)v10 - 1i64) )
    {
      v33 = *(_QWORD *)v10;
      if ( v4 >= *(_QWORD *)v10 && v4 > *(_QWORD *)(v10 + 8) + v33 - 1 && v4 >= v33 )
        v34 = (unsigned int)(*(_DWORD *)(v10 + 8) - v4);
      v27 = __OFSUB__(v8, v6);
      v26 = (signed __int64)(v8 - v6) < 0;
      goto LABEL_49;
    }
    v31 = *(_QWORD *)v10 + v30 - v4;
    v32 = *(_QWORD *)(v10 + 8);
    if ( v31 <= v32 )
      *(_QWORD *)(v10 + 8) = v32 - v31;
    else
      *(_QWORD *)(v10 + 8) = 0i64;
  }
  else
  {
    if ( *(_QWORD *)v10 == v4 )
    {
      v12 = *(_QWORD *)(v10 + 8);
      v13 = v3;
      if ( (signed __int64)v3 > v12 )
        v13 = *(_QWORD *)(v10 + 8);
      *(_QWORD *)v10 += v13;
      *(_QWORD *)(v10 + 8) = v12 - v13;
      v14 = &v5->Ranges.Data.Data[v9];
      if ( !v14->Length )
      {
        if ( v8 >= 0 )
        {
          v15 = v5->Ranges.Data.Size;
          if ( v8 < v15 )
          {
            if ( v15 == 1 )
            {
              Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                &v5->Ranges.Data,
                0i64);
            }
            else
            {
              memmove(v14, &v14[1], 24 * (v15 - v8 - 1));
              --v5->Ranges.Data.Size;
            }
          }
        }
        goto LABEL_51;
      }
      goto LABEL_32;
    }
    if ( *(_QWORD *)v10 + v11 > (signed __int64)(v4 + v3) )
    {
      v16 = *(_QWORD *)(v10 + 8);
      v17 = *(_QWORD *)v10;
      v18 = *(void **)(v10 + 16);
      v19 = *(_QWORD *)v10 + v16 - v4;
      if ( v19 <= v16 )
        *(_QWORD *)(v10 + 8) -= v19;
      else
        *(_QWORD *)(v10 + 8) = 0i64;
      v20 = v3 + v5->Ranges.Data.Data[v9].Length;
      if ( v20 > v16 )
        v20 = v16;
      v21 = v20 + v17;
      v22 = v16 - v20;
      v23 = v5->Ranges.Data.Size;
      if ( v8 < v23 )
        v42.Index = ++v8;
      Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v5->Ranges.Data,
        v23 + 1);
      v24 = v5->Ranges.Data.Size;
      if ( v8 < v24 - 1 )
        memmove(&v5->Ranges.Data.Data[v8 + 1], &v5->Ranges.Data.Data[v8], 24 * (v24 - v8 - 1));
      v25 = &v5->Ranges.Data.Data[v8];
      if ( v25 )
      {
        v25->Index = v21;
        v25->Length = v22;
        v25->Data = v18;
      }
LABEL_32:
      v27 = __OFSUB__(v8, v5->Ranges.Data.Size);
      v26 = (signed __int64)(v8 - v5->Ranges.Data.Size) < 0;
      goto LABEL_49;
    }
    v28 = *(_QWORD *)(v10 + 8);
    if ( v3 <= v28 )
      *(_QWORD *)(v10 + 8) = v28 - v3;
    else
      *(_QWORD *)(v10 + 8) = 0i64;
  }
  v29 = v5->Ranges.Data.Size;
  if ( v8 < v29 )
  {
    v42.Index = ++v8;
    v27 = __OFSUB__(v8, v29);
    v26 = v8 - v29 < 0;
LABEL_49:
    if ( v26 ^ v27 )
      v42.Index = ++v8;
  }
LABEL_51:
  if ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v42) )
  {
    v35 = v8;
    do
    {
      v36 = &v5->Ranges.Data.Data[v35];
      if ( v36->Index < v4 || (signed __int64)(v36->Length + v36->Index - 1) > (signed __int64)(v3 + v4 - 1) )
        break;
      if ( v8 >= 0 )
      {
        v37 = v5->Ranges.Data.Size;
        if ( v8 < v37 )
        {
          if ( v37 == 1 )
          {
            Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &v5->Ranges.Data,
              0i64);
          }
          else
          {
            memmove(&v5->Ranges.Data.Data[v35], &v36[1], 24 * (v37 - v8 - 1));
            --v5->Ranges.Data.Size;
          }
        }
      }
    }
    while ( !Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v42) );
  }
  if ( v8 >= 0 && v8 < v5->Ranges.Data.Size )
  {
    v38 = v3 + v4 - 1;
    v39 = &v5->Ranges.Data.Data[v8];
    if ( v38 >= v39->Index )
    {
      v40 = v39->Length;
      if ( v38 <= v40 + v39->Index - 1 )
      {
        v41 = v3 + v4 - v39->Index;
        if ( v41 > v40 )
          v41 = v39->Length;
        v39->Index += v41;
        v39->Length = v40 - v41;
      }
    }
  }
}

