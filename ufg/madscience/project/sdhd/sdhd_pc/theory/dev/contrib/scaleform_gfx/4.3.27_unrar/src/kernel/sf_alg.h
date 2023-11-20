// File Line: 149
// RVA: 0x7B78C0
bool __fastcall Scaleform::Alg::OperatorLess<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::Compare(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *a, Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *b)
{
  return a->Frame < b->Frame;
}

// File Line: 169
// RVA: 0x886A80
void __fastcall Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AutoTabSortFunctor>(Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *arr, unsigned __int64 start, unsigned __int64 end, Scaleform::GFx::AutoTabSortFunctor less)
{
  signed __int64 v4; // r15
  unsigned __int64 v5; // r13
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v6; // r12
  char *i; // rbp
  Scaleform::RefCountNTSImpl **v8; // rdi
  Scaleform::RefCountNTSImpl **v9; // rsi
  Scaleform::RefCountNTSImpl *v10; // rbx
  signed __int64 v11; // rsi
  signed __int64 v12; // rdi
  Scaleform::RefCountNTSImpl **v13; // r15
  Scaleform::RefCountNTSImpl **v14; // r14
  Scaleform::RefCountNTSImpl *v15; // rbx
  Scaleform::RefCountNTSImpl **v16; // r14
  Scaleform::RefCountNTSImpl **v17; // r15
  Scaleform::RefCountNTSImpl *v18; // rbx
  Scaleform::RefCountNTSImpl **v19; // r14
  Scaleform::RefCountNTSImpl **v20; // r15
  Scaleform::RefCountNTSImpl *v21; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v22; // rax
  Scaleform::RefCountNTSImpl **v23; // r14
  Scaleform::RefCountNTSImpl **v24; // r15
  Scaleform::RefCountNTSImpl **v25; // r15
  Scaleform::RefCountNTSImpl *v26; // rbx
  unsigned __int64 v27; // rsi
  signed __int64 v28; // r14
  signed __int64 j; // rbp
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v30; // rbx
  Scaleform::GFx::InteractiveObject *v31; // rax
  Scaleform::RefCountNTSImpl *v32; // rdi
  Scaleform::GFx::InteractiveObject *v33; // rax
  Scaleform::RefCountNTSImpl *v34; // rcx
  Scaleform::RefCountNTSImpl *v35; // rcx
  Scaleform::GFx::InteractiveObject *v36; // [rsp+50h] [rbp-2C8h]
  Scaleform::RefCountNTSImpl *v37; // [rsp+58h] [rbp-2C0h]
  char v38; // [rsp+60h] [rbp-2B8h]
  char *v39; // [rsp+328h] [rbp+10h]
  unsigned __int64 v40; // [rsp+330h] [rbp+18h]
  Scaleform::GFx::AutoTabSortFunctor v41; // [rsp+338h] [rbp+20h]

  v41 = less;
  v4 = end;
  v40 = end;
  v5 = start;
  v6 = arr;
  if ( end - start >= 2 )
  {
    for ( i = &v38; ; v40 = *((_QWORD *)i + 1) )
    {
      while ( 1 )
      {
        v39 = i;
        if ( (signed __int64)(v4 - v5) <= 9 )
          break;
        v8 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v5 + (signed __int64)(v4 - v5) / 2];
        v9 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v5];
        if ( *v9 )
          ++(*v9)->RefCount;
        v10 = *v9;
        if ( *v8 )
          ++(*v8)->RefCount;
        if ( *v9 )
          Scaleform::RefCountNTSImpl::Release(*v9);
        *v9 = *v8;
        if ( v10 )
          ++v10->RefCount;
        if ( *v8 )
          Scaleform::RefCountNTSImpl::Release(*v8);
        *v8 = v10;
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release(v10);
        v11 = v5 + 1;
        v12 = v4 - 1;
        if ( Scaleform::GFx::AutoTabSortFunctor::operator()(
               &v41,
               v6->Data.Data[v4 - 1].pObject,
               v6->Data.Data[v5 + 1].pObject) )
        {
          v13 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v11];
          v14 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v12];
          if ( *v14 )
            ++(*v14)->RefCount;
          v15 = *v14;
          if ( *v13 )
            ++(*v13)->RefCount;
          if ( *v14 )
            Scaleform::RefCountNTSImpl::Release(*v14);
          *v14 = *v13;
          if ( v15 )
            ++v15->RefCount;
          if ( *v13 )
            Scaleform::RefCountNTSImpl::Release(*v13);
          *v13 = v15;
          if ( v15 )
            Scaleform::RefCountNTSImpl::Release(v15);
        }
        if ( Scaleform::GFx::AutoTabSortFunctor::operator()(&v41, v6->Data.Data[v5].pObject, v6->Data.Data[v11].pObject) )
        {
          v16 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v11];
          v17 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v5];
          if ( *v17 )
            ++(*v17)->RefCount;
          v18 = *v17;
          v37 = *v17;
          if ( *v16 )
            ++(*v16)->RefCount;
          if ( *v17 )
            Scaleform::RefCountNTSImpl::Release(*v17);
          *v17 = *v16;
          if ( v18 )
            ++v18->RefCount;
          if ( *v16 )
            Scaleform::RefCountNTSImpl::Release(*v16);
          *v16 = v18;
          if ( v18 )
            Scaleform::RefCountNTSImpl::Release(v18);
        }
        if ( Scaleform::GFx::AutoTabSortFunctor::operator()(&v41, v6->Data.Data[v12].pObject, v6->Data.Data[v5].pObject) )
        {
          v19 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v5];
          v20 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v12];
          if ( *v20 )
            ++(*v20)->RefCount;
          v21 = *v20;
          if ( *v19 )
            ++(*v19)->RefCount;
          if ( *v20 )
            Scaleform::RefCountNTSImpl::Release(*v20);
          *v20 = *v19;
          if ( v21 )
            ++v21->RefCount;
          if ( *v19 )
            Scaleform::RefCountNTSImpl::Release(*v19);
          *v19 = v21;
          goto LABEL_54;
        }
        while ( 1 )
        {
          do
            ++v11;
          while ( Scaleform::GFx::AutoTabSortFunctor::operator()(
                    &v41,
                    v6->Data.Data[v11].pObject,
                    v6->Data.Data[v5].pObject) );
          do
            --v12;
          while ( Scaleform::GFx::AutoTabSortFunctor::operator()(
                    &v41,
                    v6->Data.Data[v5].pObject,
                    v6->Data.Data[v12].pObject) );
          v22 = v6->Data.Data;
          v23 = (Scaleform::RefCountNTSImpl **)&v6->Data.Data[v12];
          if ( v11 > v12 )
            break;
          v24 = (Scaleform::RefCountNTSImpl **)&v22[v11];
          if ( *v24 )
            ++(*v24)->RefCount;
          v21 = *v24;
          if ( *v23 )
            ++(*v23)->RefCount;
          if ( *v24 )
            Scaleform::RefCountNTSImpl::Release(*v24);
          *v24 = *v23;
          if ( v21 )
            ++v21->RefCount;
          if ( *v23 )
            Scaleform::RefCountNTSImpl::Release(*v23);
          *v23 = v21;
LABEL_54:
          if ( v21 )
            Scaleform::RefCountNTSImpl::Release(v21);
        }
        v25 = (Scaleform::RefCountNTSImpl **)&v22[v5];
        if ( *v25 )
          ++(*v25)->RefCount;
        v26 = *v25;
        if ( *v23 )
          ++(*v23)->RefCount;
        if ( *v25 )
          Scaleform::RefCountNTSImpl::Release(*v25);
        *v25 = *v23;
        if ( v26 )
          ++v26->RefCount;
        if ( *v23 )
          Scaleform::RefCountNTSImpl::Release(*v23);
        *v23 = v26;
        if ( v26 )
          Scaleform::RefCountNTSImpl::Release(v26);
        v4 = v40;
        if ( (signed __int64)(v12 - v5) <= (signed __int64)(v40 - v11) )
        {
          *(_QWORD *)i = v11;
          *((_QWORD *)i + 1) = v40;
          v4 = v12;
          v40 = v12;
        }
        else
        {
          *(_QWORD *)i = v5;
          *((_QWORD *)i + 1) = v12;
          v5 = v11;
        }
        i += 16;
      }
      v27 = v5;
      v28 = v5 + 1;
      if ( (signed __int64)(v5 + 1) < v4 )
      {
        do
        {
          for ( j = v27;
                Scaleform::GFx::AutoTabSortFunctor::operator()(
                  &v41,
                  v6->Data.Data[v27 + 1].pObject,
                  v6->Data.Data[v27].pObject);
                j = --v27 )
          {
            v30 = v6->Data.Data;
            v31 = v6->Data.Data[j + 1].pObject;
            if ( v31 )
              ++v31->RefCount;
            v32 = (Scaleform::RefCountNTSImpl *)&v30[j + 1].pObject->vfptr;
            v36 = v30[j + 1].pObject;
            v33 = v30[j].pObject;
            if ( v33 )
              ++v33->RefCount;
            v34 = (Scaleform::RefCountNTSImpl *)&v30[j + 1].pObject->vfptr;
            if ( v34 )
              Scaleform::RefCountNTSImpl::Release(v34);
            v30[j + 1] = v30[j];
            if ( v32 )
              ++v32->RefCount;
            v35 = (Scaleform::RefCountNTSImpl *)&v30[j].pObject->vfptr;
            if ( v35 )
              Scaleform::RefCountNTSImpl::Release(v35);
            v30[j].pObject = (Scaleform::GFx::InteractiveObject *)v32;
            if ( v32 )
              Scaleform::RefCountNTSImpl::Release(v32);
            if ( v27 == v5 )
              break;
          }
          v27 = v28++;
        }
        while ( v28 < v4 );
        i = v39;
      }
      if ( i <= &v38 )
        break;
      i -= 16;
      v5 = *(_QWORD *)i;
      v4 = *((_QWORD *)i + 1);
    }
  }
}

// File Line: 279
// RVA: 0x6C17F0
char __fastcall Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortOnFunctor>(Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> *arr, unsigned __int64 start, unsigned __int64 end, Scaleform::GFx::AS2::ArraySortOnFunctor *less)
{
  Scaleform::GFx::AS2::ArraySortOnFunctor *v4; // rbp
  signed __int64 v5; // r14
  unsigned __int64 v6; // r13
  Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> *v7; // rsi
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
  Scaleform::GFx::AS2::Value **v23; // rax
  Scaleform::GFx::AS2::Value **v24; // rcx
  Scaleform::GFx::AS2::Value *v25; // rdx
  signed __int64 v26; // rbx
  signed __int64 j; // r15
  signed __int64 k; // rdi
  Scaleform::GFx::AS2::Value **v29; // rdx
  Scaleform::GFx::AS2::Value *v30; // rcx
  signed __int64 v31; // rbx
  __int64 v33; // [rsp+20h] [rbp-2C8h]
  char v34; // [rsp+30h] [rbp-2B8h]

  v33 = -2i64;
  v4 = less;
  v5 = end;
  v6 = start;
  v7 = arr;
  if ( end - start >= 2 )
  {
    for ( i = &v34; ; v5 = *((_QWORD *)i + 1) )
    {
      while ( (signed __int64)(v5 - v6) > 9 )
      {
        v10 = &v7->Data[v6 + (signed __int64)(v5 - v6) / 2];
        v11 = v7->Data[v6];
        v7->Data[v6] = *v10;
        *v10 = v11;
        v12 = v6 + 1;
        v13 = v5 - 1;
        if ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(v4, v7->Data[v5 - 1], v7->Data[v6 + 1]) < 0 )
        {
          v14 = &v7->Data[v12];
          v15 = &v7->Data[v13];
          v16 = *v15;
          *v15 = *v14;
          *v14 = v16;
        }
        if ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(v4, v7->Data[v6], v7->Data[v12]) < 0 )
        {
          v17 = &v7->Data[v12];
          v18 = &v7->Data[v6];
          v19 = *v18;
          *v18 = *v17;
          *v17 = v19;
        }
        if ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(v4, v7->Data[v13], v7->Data[v6]) < 0 )
        {
          v20 = &v7->Data[v6];
          v21 = &v7->Data[v13];
LABEL_11:
          v22 = *v21;
          *v21 = *v20;
          *v20 = v22;
        }
        do
        {
          if ( ++v12 >= v5 )
          {
            v31 = (signed __int64)&v4->FunctorArray;
LABEL_31:
            Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
              *(Scaleform::GFx::AS2::ArraySortFunctor **)v31,
              *(_QWORD *)(v31 + 8));
            if ( *(_QWORD *)v31 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            return 0;
          }
        }
        while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(v4, v7->Data[v12], v7->Data[v6]) < 0 );
        do
        {
          if ( --v13 < 0 )
          {
            v31 = (signed __int64)&v4->FunctorArray;
            goto LABEL_31;
          }
        }
        while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(v4, v7->Data[v6], v7->Data[v13]) < 0 );
        v23 = v7->Data;
        v20 = &v7->Data[v13];
        if ( v12 <= v13 )
        {
          v21 = &v23[v12];
          goto LABEL_11;
        }
        v24 = &v23[v6];
        v25 = *v24;
        *v24 = *v20;
        *v20 = v25;
        if ( (signed __int64)(v13 - v6) <= v5 - v12 )
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
        for ( k = v26; Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(v4, v7->Data[v26 + 1], v7->Data[v26]) < 0; k = --v26 )
        {
          v29 = &v7->Data[k];
          v30 = v29[1];
          v29[1] = *v29;
          *v29 = v30;
          if ( v26 == v6 )
            break;
        }
        v26 = j;
      }
      if ( i <= &v34 )
        break;
      i -= 16;
      v6 = *(_QWORD *)i;
    }
    v8 = &v4->FunctorArray;
  }
  else
  {
    v8 = &less->FunctorArray;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(v8->Data.Data, v8->Data.Size);
  if ( v8->Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 1;
}

// File Line: 444
// RVA: 0x92DA40
void __fastcall Scaleform::Alg::InsertionSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4>,bool (*)(Scaleform::Render::Tessellator::IntersectionType const &,Scaleform::Render::Tessellator::IntersectionType const &)>(Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4> *arr, unsigned __int64 start, unsigned __int64 end, bool (__fastcall *less)(Scaleform::Render::Tessellator::IntersectionType *, Scaleform::Render::Tessellator::IntersectionType *))
{
  unsigned __int64 v4; // rdi
  bool (__fastcall *v5)(Scaleform::Render::Tessellator::IntersectionType *, Scaleform::Render::Tessellator::IntersectionType *); // r13
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4> *v6; // rbp
  unsigned __int64 v7; // rbx
  signed __int64 v8; // rsi
  signed __int64 v9; // r14
  unsigned __int64 v10; // r15
  signed __int64 v11; // r12
  Scaleform::Render::Tessellator::IntersectionType **v12; // rcx
  Scaleform::Render::Tessellator::IntersectionType *v13; // r10
  Scaleform::Render::Tessellator::IntersectionType *v14; // rcx
  unsigned int v15; // edx
  unsigned int v16; // er8
  float v17; // er9
  unsigned __int64 i; // [rsp+20h] [rbp-48h]
  unsigned __int64 v19; // [rsp+78h] [rbp+10h]
  unsigned __int64 v20; // [rsp+80h] [rbp+18h]

  v20 = end;
  v19 = start;
  v4 = start + 1;
  v5 = less;
  v6 = arr;
  v7 = start;
  for ( i = start + 1; v4 < v20; i = v4 )
  {
    v8 = v7 >> 4;
    v9 = v7 & 0xF;
    v10 = (v7 + 1) >> 4;
    v11 = ((_DWORD)v7 + 1) & 0xF;
    if ( v5(&v6->Pages[v10][v11], &v6->Pages[v8][v9]) )
    {
      do
      {
        v12 = v6->Pages;
        v13 = &v12[v8][v9];
        v14 = &v12[v10][v11];
        v15 = v14->pos1;
        v16 = v14->pos2;
        v17 = v14->y;
        v14->pos1 = v13->pos1;
        v14->pos2 = v13->pos2;
        v14->y = v13->y;
        v13->pos1 = v15;
        v13->pos2 = v16;
        v13->y = v17;
        if ( v7 <= v19 )
          break;
        v8 = --v7 >> 4;
        v9 = v7 & 0xF;
        v10 = (v7 + 1) >> 4;
        v11 = ((_DWORD)v7 + 1) & 0xF;
      }
      while ( v5(&v6->Pages[v10][v11], &v6->Pages[v8][v9]) );
      v4 = i;
    }
    v7 = v4++;
  }
}

// File Line: 652
// RVA: 0x88A5F0
void __fastcall Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy>>(Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *v1; // rbp
  signed __int64 v2; // rsi
  signed __int64 v3; // rdi
  signed __int64 v4; // r14
  signed __int64 v5; // r15
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx

  v1 = arr;
  v2 = 0i64;
  v3 = arr->Data.Size - 1;
  if ( v3 > 0 )
  {
    do
    {
      v4 = (signed __int64)&v1->Data.Data[v3];
      v5 = (signed __int64)&v1->Data.Data[v2];
      if ( *(_QWORD *)v5 )
        ++*(_DWORD *)(*(_QWORD *)v5 + 24i64);
      v6 = *(Scaleform::GFx::ASStringNode **)v5;
      if ( *(_QWORD *)v4 )
        ++*(_DWORD *)(*(_QWORD *)v4 + 24i64);
      v7 = *(Scaleform::GFx::ASStringNode **)v5;
      if ( *(_QWORD *)v5 )
      {
        v8 = v7->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      }
      *(_QWORD *)v5 = *(_QWORD *)v4;
      if ( v6 )
        ++v6->RefCount;
      v9 = *(Scaleform::GFx::ASStringNode **)v4;
      if ( *(_QWORD *)v4 )
      {
        v8 = v9->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
      *(_QWORD *)v4 = v6;
      if ( v6 )
      {
        v8 = v6->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
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
  __int64 result; // rax
  unsigned __int8 v2; // cl
  unsigned __int8 v3; // cl

  if ( val & 0xFFFFFFFF00000000ui64 )
  {
    if ( val & 0xFFFF000000000000ui64 )
    {
      if ( val & 0xFF00000000000000ui64 )
        result = (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[val >> 56] + 56;
      else
        result = (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[BYTE6(val)] + 48;
    }
    else
    {
      if ( val & 0xFF0000000000i64 )
        v2 = Scaleform::Alg::UpperBitTable[BYTE5(val)] + 40;
      else
        v2 = Scaleform::Alg::UpperBitTable[BYTE4(val)] + 32;
      result = v2;
    }
  }
  else if ( val & 0xFFFF0000 )
  {
    if ( val & 0xFF000000 )
      result = (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[val >> 24] + 24;
    else
      result = (unsigned int)(unsigned __int8)Scaleform::Alg::UpperBitTable[BYTE2(val)] + 16;
  }
  else
  {
    if ( val & 0xFF00 )
      v3 = Scaleform::Alg::UpperBitTable[BYTE1(val)] + 8;
    else
      v3 = Scaleform::Alg::UpperBitTable[(unsigned __int8)val];
    result = v3;
  }
  return result;
}

// File Line: 769
// RVA: 0x998E30
__int64 __fastcall Scaleform::Alg::LowerBit(unsigned __int64 val)
{
  __int64 result; // rax
  unsigned __int8 v2; // cl
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // cl

  if ( (_DWORD)val )
  {
    if ( (_WORD)val )
    {
      if ( (_BYTE)val )
        result = (unsigned __int8)Scaleform::Alg::LowerBitTable[(unsigned __int8)val];
      else
        result = (unsigned int)(unsigned __int8)Scaleform::Alg::LowerBitTable[BYTE1(val)] + 8;
    }
    else
    {
      if ( val & 0xFF0000 )
        v2 = Scaleform::Alg::LowerBitTable[BYTE2(val)] + 16;
      else
        v2 = Scaleform::Alg::LowerBitTable[BYTE3(val)] + 24;
      result = v2;
    }
  }
  else if ( val & 0xFFFF00000000i64 )
  {
    if ( val & 0xFF00000000i64 )
      v3 = Scaleform::Alg::LowerBitTable[BYTE4(val)] + 32;
    else
      v3 = Scaleform::Alg::LowerBitTable[BYTE5(val)] + 40;
    result = v3;
  }
  else
  {
    if ( val & 0xFF000000000000i64 )
      v4 = Scaleform::Alg::LowerBitTable[BYTE6(val)] + 48;
    else
      v4 = Scaleform::Alg::LowerBitTable[val >> 56] + 56;
    result = v4;
  }
  return result;
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
signed __int64 __fastcall Scaleform::Alg::BitCount32(unsigned int value)
{
  signed __int64 result; // rax

  if ( value >= 0x8000 )
  {
    if ( value >= 0x800000 )
    {
      if ( value >= 0x8000000 )
      {
        if ( value >= 0x20000000 )
        {
          if ( value >= 0x40000000 )
            result = 32 - (unsigned int)(value < 0x80000000);
          else
            result = 30i64;
        }
        else
        {
          result = 29 - (unsigned int)(value < 0x10000000);
        }
      }
      else if ( value >= 0x2000000 )
      {
        result = 27 - (unsigned int)(value < 0x4000000);
      }
      else
      {
        result = 25 - (unsigned int)(value < 0x1000000);
      }
    }
    else if ( value >= 0x80000 )
    {
      if ( value >= 0x200000 )
        result = 23 - (unsigned int)(value < 0x400000);
      else
        result = 21 - (unsigned int)(value < 0x100000);
    }
    else if ( value >= 0x20000 )
    {
      result = 19 - (unsigned int)(value < 0x40000);
    }
    else
    {
      result = 17 - (unsigned int)(value < 0x10000);
    }
  }
  else if ( value >= 0x80 )
  {
    if ( value >= 0x800 )
    {
      if ( value >= 0x2000 )
        result = 15 - (unsigned int)(value < 0x4000);
      else
        result = 13 - (unsigned int)(value < 0x1000);
    }
    else if ( value >= 0x200 )
    {
      result = 11 - (unsigned int)(value < 0x400);
    }
    else
    {
      result = 9 - (unsigned int)(value < 0x100);
    }
  }
  else if ( value >= 8 )
  {
    if ( value >= 0x20 )
      result = 7 - (unsigned int)(value < 0x40);
    else
      result = 5 - (unsigned int)(value < 0x10);
  }
  else if ( value >= 2 )
  {
    result = 3 - (unsigned int)(value < 4);
  }
  else
  {
    result = value >= 1;
  }
  return result;
}

