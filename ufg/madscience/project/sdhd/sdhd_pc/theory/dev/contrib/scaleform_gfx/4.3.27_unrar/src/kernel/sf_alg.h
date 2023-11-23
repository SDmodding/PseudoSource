// File Line: 149
// RVA: 0x7B78C0
bool __fastcall Scaleform::Alg::OperatorLess<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::Compare(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *a,
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *b)
{
  return a->Frame < b->Frame;
}

// File Line: 169
// RVA: 0x886A80
void __fastcall Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AutoTabSortFunctor>(
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *arr,
        unsigned __int64 start,
        unsigned __int64 end,
        Scaleform::GFx::AutoTabSortFunctor less)
{
  signed __int64 v4; // r15
  unsigned __int64 v5; // r13
  char *v7; // rbp
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v8; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v9; // rsi
  Scaleform::RefCountNTSImpl *pObject; // rbx
  signed __int64 v11; // rsi
  signed __int64 v12; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v13; // r15
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v14; // r14
  Scaleform::RefCountNTSImpl *v15; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v16; // r14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v17; // r15
  Scaleform::RefCountNTSImpl *v18; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v19; // r14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v20; // r15
  Scaleform::RefCountNTSImpl *v21; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v23; // r14
  Scaleform::RefCountNTSImpl **p_pObject; // r15
  Scaleform::RefCountNTSImpl **v25; // r15
  Scaleform::RefCountNTSImpl *v26; // rbx
  unsigned __int64 v27; // rsi
  signed __int64 v28; // r14
  unsigned __int64 i; // rbp
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v30; // rbx
  Scaleform::GFx::InteractiveObject *v31; // rax
  Scaleform::RefCountNTSImpl *v32; // rdi
  Scaleform::GFx::InteractiveObject *v33; // rax
  Scaleform::RefCountNTSImpl *v34; // rcx
  Scaleform::RefCountNTSImpl *v35; // rcx
  Scaleform::RefCountNTSImpl *v36; // [rsp+50h] [rbp-2C8h]
  Scaleform::GFx::InteractiveObject *v37; // [rsp+58h] [rbp-2C0h]
  char v38[696]; // [rsp+60h] [rbp-2B8h] BYREF
  char *v39; // [rsp+328h] [rbp+10h]
  unsigned __int64 v40; // [rsp+330h] [rbp+18h]
  Scaleform::GFx::AutoTabSortFunctor v41; // [rsp+338h] [rbp+20h] BYREF

  v41 = less;
  v4 = end;
  v40 = end;
  v5 = start;
  if ( end - start >= 2 )
  {
    v7 = v38;
    while ( 1 )
    {
      while ( 1 )
      {
        v39 = v7;
        if ( (__int64)(v4 - v5) <= 9 )
          break;
        v8 = &arr->Data.Data[v5 + (__int64)(v4 - v5) / 2];
        v9 = &arr->Data.Data[v5];
        if ( v9->pObject )
          ++v9->pObject->RefCount;
        pObject = v9->pObject;
        if ( v8->pObject )
          ++v8->pObject->RefCount;
        if ( v9->pObject )
          Scaleform::RefCountNTSImpl::Release(v9->pObject);
        v9->pObject = v8->pObject;
        if ( pObject )
          ++pObject->RefCount;
        if ( v8->pObject )
          Scaleform::RefCountNTSImpl::Release(v8->pObject);
        v8->pObject = (Scaleform::GFx::InteractiveObject *)pObject;
        if ( pObject )
          Scaleform::RefCountNTSImpl::Release(pObject);
        v11 = v5 + 1;
        v12 = v4 - 1;
        if ( Scaleform::GFx::AutoTabSortFunctor::operator()(
               &v41,
               arr->Data.Data[v4 - 1].pObject,
               arr->Data.Data[v5 + 1].pObject) )
        {
          v13 = &arr->Data.Data[v11];
          v14 = &arr->Data.Data[v12];
          if ( v14->pObject )
            ++v14->pObject->RefCount;
          v15 = v14->pObject;
          if ( v13->pObject )
            ++v13->pObject->RefCount;
          if ( v14->pObject )
            Scaleform::RefCountNTSImpl::Release(v14->pObject);
          v14->pObject = v13->pObject;
          if ( v15 )
            ++v15->RefCount;
          if ( v13->pObject )
            Scaleform::RefCountNTSImpl::Release(v13->pObject);
          v13->pObject = (Scaleform::GFx::InteractiveObject *)v15;
          if ( v15 )
            Scaleform::RefCountNTSImpl::Release(v15);
        }
        if ( Scaleform::GFx::AutoTabSortFunctor::operator()(
               &v41,
               arr->Data.Data[v5].pObject,
               arr->Data.Data[v11].pObject) )
        {
          v16 = &arr->Data.Data[v11];
          v17 = &arr->Data.Data[v5];
          if ( v17->pObject )
            ++v17->pObject->RefCount;
          v18 = v17->pObject;
          v37 = v17->pObject;
          if ( v16->pObject )
            ++v16->pObject->RefCount;
          if ( v17->pObject )
            Scaleform::RefCountNTSImpl::Release(v17->pObject);
          v17->pObject = v16->pObject;
          if ( v18 )
            ++v18->RefCount;
          if ( v16->pObject )
            Scaleform::RefCountNTSImpl::Release(v16->pObject);
          v16->pObject = (Scaleform::GFx::InteractiveObject *)v18;
          if ( v18 )
            Scaleform::RefCountNTSImpl::Release(v18);
        }
        if ( Scaleform::GFx::AutoTabSortFunctor::operator()(
               &v41,
               arr->Data.Data[v12].pObject,
               arr->Data.Data[v5].pObject) )
        {
          v19 = &arr->Data.Data[v5];
          v20 = &arr->Data.Data[v12];
          if ( v20->pObject )
            ++v20->pObject->RefCount;
          v21 = v20->pObject;
          if ( v19->pObject )
            ++v19->pObject->RefCount;
          if ( v20->pObject )
            Scaleform::RefCountNTSImpl::Release(v20->pObject);
          v20->pObject = v19->pObject;
          if ( v21 )
            ++v21->RefCount;
          if ( v19->pObject )
            Scaleform::RefCountNTSImpl::Release(v19->pObject);
          v19->pObject = (Scaleform::GFx::InteractiveObject *)v21;
          goto LABEL_54;
        }
        while ( 1 )
        {
          do
            ++v11;
          while ( Scaleform::GFx::AutoTabSortFunctor::operator()(
                    &v41,
                    arr->Data.Data[v11].pObject,
                    arr->Data.Data[v5].pObject) );
          do
            --v12;
          while ( Scaleform::GFx::AutoTabSortFunctor::operator()(
                    &v41,
                    arr->Data.Data[v5].pObject,
                    arr->Data.Data[v12].pObject) );
          Data = arr->Data.Data;
          v23 = &arr->Data.Data[v12];
          if ( v11 > v12 )
            break;
          p_pObject = &Data[v11].pObject;
          if ( *p_pObject )
            ++(*p_pObject)->RefCount;
          v21 = *p_pObject;
          if ( v23->pObject )
            ++v23->pObject->RefCount;
          if ( *p_pObject )
            Scaleform::RefCountNTSImpl::Release(*p_pObject);
          *p_pObject = v23->pObject;
          if ( v21 )
            ++v21->RefCount;
          if ( v23->pObject )
            Scaleform::RefCountNTSImpl::Release(v23->pObject);
          v23->pObject = (Scaleform::GFx::InteractiveObject *)v21;
LABEL_54:
          if ( v21 )
            Scaleform::RefCountNTSImpl::Release(v21);
        }
        v25 = &Data[v5].pObject;
        if ( *v25 )
          ++(*v25)->RefCount;
        v26 = *v25;
        if ( v23->pObject )
          ++v23->pObject->RefCount;
        if ( *v25 )
          Scaleform::RefCountNTSImpl::Release(*v25);
        *v25 = v23->pObject;
        if ( v26 )
          ++v26->RefCount;
        if ( v23->pObject )
          Scaleform::RefCountNTSImpl::Release(v23->pObject);
        v23->pObject = (Scaleform::GFx::InteractiveObject *)v26;
        if ( v26 )
          Scaleform::RefCountNTSImpl::Release(v26);
        v4 = v40;
        if ( (__int64)(v12 - v5) <= (__int64)(v40 - v11) )
        {
          *(_QWORD *)v7 = v11;
          *((_QWORD *)v7 + 1) = v40;
          v4 = v12;
          v40 = v12;
        }
        else
        {
          *(_QWORD *)v7 = v5;
          *((_QWORD *)v7 + 1) = v12;
          v5 = v11;
        }
        v7 += 16;
      }
      v27 = v5;
      v28 = v5 + 1;
      if ( (__int64)(v5 + 1) < v4 )
      {
        do
        {
          for ( i = v27;
                Scaleform::GFx::AutoTabSortFunctor::operator()(
                  &v41,
                  arr->Data.Data[v27 + 1].pObject,
                  arr->Data.Data[v27].pObject);
                i = v27 )
          {
            v30 = arr->Data.Data;
            v31 = arr->Data.Data[i + 1].pObject;
            if ( v31 )
              ++v31->RefCount;
            v32 = v30[i + 1].pObject;
            v36 = v32;
            v33 = v30[i].pObject;
            if ( v33 )
              ++v33->RefCount;
            v34 = v30[i + 1].pObject;
            if ( v34 )
              Scaleform::RefCountNTSImpl::Release(v34);
            v30[i + 1] = v30[i];
            if ( v32 )
              ++v32->RefCount;
            v35 = v30[i].pObject;
            if ( v35 )
              Scaleform::RefCountNTSImpl::Release(v35);
            v30[i].pObject = (Scaleform::GFx::InteractiveObject *)v32;
            if ( v32 )
              Scaleform::RefCountNTSImpl::Release(v32);
            if ( v27 == v5 )
              break;
            --v27;
          }
          v27 = v28++;
        }
        while ( v28 < v4 );
        v7 = v39;
      }
      if ( v7 <= v38 )
        break;
      v7 -= 16;
      v5 = *(_QWORD *)v7;
      v4 = *((_QWORD *)v7 + 1);
      v40 = v4;
    }
  }
}

// File Line: 279
// RVA: 0x6C17F0
char __fastcall Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortOnFunctor>(
        Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> *arr,
        unsigned __int64 start,
        signed __int64 end,
        Scaleform::GFx::AS2::ArraySortOnFunctor *less)
{
  signed __int64 v5; // r14
  unsigned __int64 v6; // r13
  Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  char *i; // r12
  Scaleform::GFx::AS2::Value **v10; // r8
  Scaleform::GFx::AS2::Value *v11; // rdx
  signed __int64 v12; // rbx
  signed __int64 v13; // rdi
  Scaleform::GFx::AS2::Value **v14; // r8
  Scaleform::GFx::AS2::Value **v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rdx
  Scaleform::GFx::AS2::Value **v17; // r8
  Scaleform::GFx::AS2::Value **v18; // rcx
  Scaleform::GFx::AS2::Value *v19; // rdx
  Scaleform::GFx::AS2::Value **v20; // r8
  Scaleform::GFx::AS2::Value **v21; // rcx
  Scaleform::GFx::AS2::Value *v22; // rdx
  Scaleform::GFx::AS2::Value **Data; // rax
  Scaleform::GFx::AS2::Value **v24; // rcx
  Scaleform::GFx::AS2::Value *v25; // rdx
  unsigned __int64 v26; // rbx
  signed __int64 j; // r15
  unsigned __int64 k; // rdi
  Scaleform::GFx::AS2::Value **v29; // rdx
  Scaleform::GFx::AS2::Value *v30; // rcx
  Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *p_FunctorArray; // rbx
  __int64 v33; // [rsp+20h] [rbp-2C8h]
  char v34[696]; // [rsp+30h] [rbp-2B8h] BYREF

  v33 = -2i64;
  v5 = end;
  v6 = start;
  if ( end - start >= 2 )
  {
    for ( i = v34; ; v5 = *((_QWORD *)i + 1) )
    {
      while ( (__int64)(v5 - v6) > 9 )
      {
        v10 = &arr->Data[v6] + (__int64)(v5 - v6) / 2;
        v11 = arr->Data[v6];
        arr->Data[v6] = *v10;
        *v10 = v11;
        v12 = v6 + 1;
        v13 = v5 - 1;
        if ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(less, arr->Data[v5 - 1], arr->Data[v6 + 1]) < 0 )
        {
          v14 = &arr->Data[v12];
          v15 = &arr->Data[v13];
          v16 = *v15;
          *v15 = *v14;
          *v14 = v16;
        }
        if ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(less, arr->Data[v6], arr->Data[v12]) < 0 )
        {
          v17 = &arr->Data[v12];
          v18 = &arr->Data[v6];
          v19 = *v18;
          *v18 = *v17;
          *v17 = v19;
        }
        if ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(less, arr->Data[v13], arr->Data[v6]) < 0 )
        {
          v20 = &arr->Data[v6];
          v21 = &arr->Data[v13];
LABEL_11:
          v22 = *v21;
          *v21 = *v20;
          *v20 = v22;
        }
        do
        {
          if ( ++v12 >= v5 )
          {
            p_FunctorArray = &less->FunctorArray;
LABEL_31:
            Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
              p_FunctorArray->Data.Data,
              p_FunctorArray->Data.Size);
            if ( p_FunctorArray->Data.Data )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            return 0;
          }
        }
        while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(less, arr->Data[v12], arr->Data[v6]) < 0 );
        do
        {
          if ( --v13 < 0 )
          {
            p_FunctorArray = &less->FunctorArray;
            goto LABEL_31;
          }
        }
        while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(less, arr->Data[v6], arr->Data[v13]) < 0 );
        Data = arr->Data;
        v20 = &arr->Data[v13];
        if ( v12 <= v13 )
        {
          v21 = &Data[v12];
          goto LABEL_11;
        }
        v24 = &Data[v6];
        v25 = *v24;
        *v24 = *v20;
        *v20 = v25;
        if ( (__int64)(v13 - v6) <= v5 - v12 )
        {
          *(_QWORD *)i = v12;
          *((_QWORD *)i + 1) = v5;
          v5 = v13;
        }
        else
        {
          *(_QWORD *)i = v6;
          *((_QWORD *)i + 1) = v13;
          v6 = v12;
        }
        i += 16;
      }
      v26 = v6;
      for ( j = v6 + 1; j < v5; ++j )
      {
        for ( k = v26;
              Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(less, arr->Data[v26 + 1], arr->Data[v26]) < 0;
              k = v26 )
        {
          v29 = &arr->Data[k];
          v30 = v29[1];
          v29[1] = *v29;
          *v29 = v30;
          if ( v26 == v6 )
            break;
          --v26;
        }
        v26 = j;
      }
      if ( i <= v34 )
        break;
      i -= 16;
      v6 = *(_QWORD *)i;
    }
    v8 = &less->FunctorArray;
  }
  else
  {
    v8 = &less->FunctorArray;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(v8->Data.Data, v8->Data.Size);
  if ( v8->Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 1;
}

// File Line: 444
// RVA: 0x92DA40
void __fastcall Scaleform::Alg::InsertionSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4>,bool (*)(Scaleform::Render::Tessellator::IntersectionType const &,Scaleform::Render::Tessellator::IntersectionType const &)>(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4> *arr,
        unsigned __int64 start,
        unsigned __int64 end,
        bool (__fastcall *less)(Scaleform::Render::Tessellator::IntersectionType *, Scaleform::Render::Tessellator::IntersectionType *))
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // r14
  unsigned __int64 v10; // r15
  __int64 v11; // r12
  Scaleform::Render::Tessellator::IntersectionType **Pages; // rcx
  Scaleform::Render::Tessellator::IntersectionType *v13; // r10
  Scaleform::Render::Tessellator::IntersectionType *v14; // rcx
  unsigned int pos1; // edx
  unsigned int pos2; // r8d
  float y; // r9d
  unsigned __int64 i; // [rsp+20h] [rbp-48h]

  v4 = start + 1;
  v7 = start;
  for ( i = start + 1; v4 < end; i = v4 )
  {
    v8 = v7 >> 4;
    v9 = v7 & 0xF;
    v10 = (v7 + 1) >> 4;
    v11 = ((_DWORD)v7 + 1) & 0xF;
    if ( less(&arr->Pages[v10][v11], &arr->Pages[v8][v9]) )
    {
      do
      {
        Pages = arr->Pages;
        v13 = &Pages[v8][v9];
        v14 = &Pages[v10][v11];
        pos1 = v14->pos1;
        pos2 = v14->pos2;
        y = v14->y;
        v14->pos1 = v13->pos1;
        v14->pos2 = v13->pos2;
        v14->y = v13->y;
        v13->pos1 = pos1;
        v13->pos2 = pos2;
        v13->y = y;
        if ( v7 <= start )
          break;
        v8 = --v7 >> 4;
        v9 = v7 & 0xF;
        v10 = (v7 + 1) >> 4;
        v11 = ((_DWORD)v7 + 1) & 0xF;
      }
      while ( less(&arr->Pages[v10][v11], &arr->Pages[v8][v9]) );
      v4 = i;
    }
    v7 = v4++;
  }
}

// File Line: 652
// RVA: 0x88A5F0
void __fastcall Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy>>(
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  signed __int64 v2; // rsi
  signed __int64 v3; // rdi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // r14
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v5; // r15
  Scaleform::GFx::ASStringNode *pObject; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx

  v2 = 0i64;
  v3 = arr->Data.Size - 1;
  if ( v3 > 0 )
  {
    do
    {
      v4 = &arr->Data.Data[v3];
      v5 = &arr->Data.Data[v2];
      if ( v5->pObject )
        ++v5->pObject->RefCount;
      pObject = v5->pObject;
      if ( v4->pObject )
        ++v4->pObject->RefCount;
      v7 = v5->pObject;
      if ( v5->pObject )
      {
        v8 = v7->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      }
      v5->pObject = v4->pObject;
      if ( pObject )
        ++pObject->RefCount;
      v9 = v4->pObject;
      if ( v4->pObject )
      {
        v8 = v9->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
      v4->pObject = pObject;
      if ( pObject )
      {
        v8 = pObject->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
      }
      ++v2;
      --v3;
    }
    while ( v2 < v3 );
  }
}

// File Line: 724
// RVA: 0x723280
__int64 __fastcall Scaleform::Alg::UpperBit(unsigned __int64 val)
{
  if ( (val & 0xFFFFFFFF00000000ui64) != 0 )
  {
    if ( (val & 0xFFFF000000000000ui64) != 0 )
    {
      if ( (val & 0xFF00000000000000ui64) != 0 )
        return (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[HIBYTE(val)] + 56;
      else
        return (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[BYTE6(val)] + 48;
    }
    else if ( (val & 0xFF0000000000i64) != 0 )
    {
      return (unsigned __int8)(Scaleform::Alg::UpperBitTable[BYTE5(val)] + 40);
    }
    else
    {
      return (unsigned __int8)(Scaleform::Alg::UpperBitTable[BYTE4(val)] + 32);
    }
  }
  else if ( (val & 0xFFFF0000) != 0 )
  {
    if ( (val & 0xFF000000) != 0 )
      return (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[val >> 24] + 24;
    else
      return (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[BYTE2(val)] + 16;
  }
  else if ( (val & 0xFF00) != 0 )
  {
    return (unsigned __int8)(Scaleform::Alg::UpperBitTable[BYTE1(val)] + 8);
  }
  else
  {
    return (unsigned __int8)Scaleform::Alg::UpperBitTable[(unsigned __int8)val];
  }
}

// File Line: 769
// RVA: 0x998E30
__int64 __fastcall Scaleform::Alg::LowerBit(unsigned __int64 val)
{
  if ( (_DWORD)val )
  {
    if ( (_WORD)val )
    {
      if ( (_BYTE)val )
        return (unsigned __int8)Scaleform::Alg::LowerBitTable[(unsigned __int8)val];
      else
        return (unsigned int)(unsigned __int8)Scaleform::Alg::LowerBitTable[BYTE1(val)] + 8;
    }
    else if ( (val & 0xFF0000) != 0 )
    {
      return (unsigned __int8)(Scaleform::Alg::LowerBitTable[BYTE2(val)] + 16);
    }
    else
    {
      return (unsigned __int8)(Scaleform::Alg::LowerBitTable[BYTE3(val)] + 24);
    }
  }
  else if ( (val & 0xFFFF00000000i64) != 0 )
  {
    if ( (val & 0xFF00000000i64) != 0 )
      return (unsigned __int8)(Scaleform::Alg::LowerBitTable[BYTE4(val)] + 32);
    else
      return (unsigned __int8)(Scaleform::Alg::LowerBitTable[BYTE5(val)] + 40);
  }
  else if ( (val & 0xFF000000000000i64) != 0 )
  {
    return (unsigned __int8)(Scaleform::Alg::LowerBitTable[BYTE6(val)] + 48);
  }
  else
  {
    return (unsigned __int8)(Scaleform::Alg::LowerBitTable[HIBYTE(val)] + 56);
  }
}

// File Line: 937
// RVA: 0x912530
long double __fastcall Scaleform::Alg::ByteUtil::SwapOrder(long double p)
{
  long double result; // xmm0_8

  *(_QWORD *)&result = ((LODWORD(p) & 0xFF000000 | ((LODWORD(p) & 0xFF0000 | (((*(_QWORD *)&p << 16) | LOWORD(p) & 0xFF00) << 16)) << 16)) << 8) | ((*(_QWORD *)&p & 0xFF00000000i64 | ((*(_QWORD *)&p & 0xFF0000000000i64 | (((*(_QWORD *)&p >> 16) | *(_QWORD *)&p & 0xFF000000000000ui64) >> 16)) >> 16)) >> 8);
  return result;
}

// File Line: 1063
// RVA: 0x6DB5A0
__int64 __fastcall Scaleform::Alg::BitCount32(unsigned int value)
{
  if ( value >= 0x8000 )
  {
    if ( value >= 0x800000 )
    {
      if ( value >= 0x8000000 )
      {
        if ( value >= 0x20000000 )
        {
          if ( value >= 0x40000000 )
            return 32 - (unsigned int)(value < 0x80000000);
          else
            return 30i64;
        }
        else
        {
          return 29 - (unsigned int)(value < 0x10000000);
        }
      }
      else if ( value >= 0x2000000 )
      {
        return 27 - (unsigned int)(value < 0x4000000);
      }
      else
      {
        return 25 - (unsigned int)(value < 0x1000000);
      }
    }
    else if ( value >= 0x80000 )
    {
      if ( value >= 0x200000 )
        return 23 - (unsigned int)(value < 0x400000);
      else
        return 21 - (unsigned int)(value < 0x100000);
    }
    else if ( value >= 0x20000 )
    {
      return 19 - (unsigned int)(value < 0x40000);
    }
    else
    {
      return 17 - (unsigned int)(value < 0x10000);
    }
  }
  else if ( value >= 0x80 )
  {
    if ( value >= 0x800 )
    {
      if ( value >= 0x2000 )
        return 15 - (unsigned int)(value < 0x4000);
      else
        return 13 - (unsigned int)(value < 0x1000);
    }
    else if ( value >= 0x200 )
    {
      return 11 - (unsigned int)(value < 0x400);
    }
    else
    {
      return 9 - (unsigned int)(value < 0x100);
    }
  }
  else if ( value >= 8 )
  {
    if ( value >= 0x20 )
      return 7 - (unsigned int)(value < 0x40);
    else
      return 5 - (unsigned int)(value < 0x10);
  }
  else if ( value >= 2 )
  {
    return 3 - (unsigned int)(value < 4);
  }
  else
  {
    return value != 0;
  }
}

