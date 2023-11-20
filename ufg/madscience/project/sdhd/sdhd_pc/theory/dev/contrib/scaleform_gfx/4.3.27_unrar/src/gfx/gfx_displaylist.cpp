// File Line: 34
// RVA: 0x8CB750
unsigned __int64 __fastcall Scaleform::GFx::DisplayList::FindDisplayIndex(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned __int64 v2; // r8
  unsigned __int64 result; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // rcx

  v2 = this->DisplayObjectArray.Data.Size;
  result = 0i64;
  if ( !v2 )
    return -1i64;
  v4 = this->DisplayObjectArray.Data.Data;
  while ( v4->pCharacter != ch )
  {
    ++result;
    ++v4;
    if ( result >= v2 )
      return -1i64;
  }
  return result;
}

// File Line: 45
// RVA: 0x8D6CE0
unsigned __int64 __fastcall Scaleform::GFx::DisplayList::GetDisplayIndex(Scaleform::GFx::DisplayList *this, int depth)
{
  int v2; // edi
  Scaleform::GFx::DisplayList *v3; // rbx
  unsigned __int64 result; // rax

  v2 = depth;
  v3 = this;
  result = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  if ( result >= v3->DisplayObjectArray.Data.Size || v3->DisplayObjectArray.Data.Data[result].pCharacter->Depth != v2 )
    result = -1i64;
  return result;
}

// File Line: 58
// RVA: 0x8D6D20
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayList::GetDisplayObjectAtDepth(Scaleform::GFx::DisplayList *this, int depth, bool *pisMarkedForRemove)
{
  bool *v3; // rdi
  int v4; // ebx
  Scaleform::GFx::DisplayList *v5; // rsi
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // r10
  Scaleform::GFx::DisplayObjectBase *result; // rax

  v3 = pisMarkedForRemove;
  v4 = depth;
  v5 = this;
  v6 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  v7 = v6;
  if ( v6 >= v5->DisplayObjectArray.Data.Size )
    return 0i64;
  result = v5->DisplayObjectArray.Data.Data[v6].pCharacter;
  if ( result->Depth != v4 || v7 == -1i64 || result->Depth != v4 )
    return 0i64;
  if ( v3 )
    *v3 = (LOBYTE(result->Flags) >> 6) & 1;
  return result;
}

// File Line: 77
// RVA: 0x8D5F20
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayList::GetCharacterAtDepth(Scaleform::GFx::DisplayList *this, int depth, __int64 id, unsigned __int64 *pindex)
{
  unsigned __int64 *v4; // r13
  _DWORD *v5; // r12
  int v6; // er15
  Scaleform::GFx::DisplayList *v7; // r14
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rbp
  signed __int64 v11; // rsi
  bool i; // cf
  Scaleform::GFx::DisplayObjectBase *v13; // rbx

  v4 = pindex;
  v5 = (_DWORD *)id;
  v6 = depth;
  v7 = this;
  v8 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  v9 = v8;
  v10 = v7->DisplayObjectArray.Data.Size;
  if ( v8 < v10 )
  {
    v11 = v8;
    if ( v7->DisplayObjectArray.Data.Data[v8].pCharacter->Depth == v6 && v8 != -1i64 )
    {
      for ( i = v8 < v10; i; i = v9 < v10 )
      {
        v13 = v7->DisplayObjectArray.Data.Data[v11].pCharacter;
        if ( v13 )
          ++v13->RefCount;
        if ( v13->Depth == v6 && v13->Id.Id == *v5 )
        {
          if ( v4 )
            *v4 = v9;
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
          return v13;
        }
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
        ++v9;
        ++v11;
      }
    }
  }
  return 0i64;
}

// File Line: 123
// RVA: 0x912110
char __fastcall Scaleform::GFx::DisplayList::SwapDepths(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, int depth1, int depth2, unsigned int frame)
{
  int v5; // er13
  int v6; // er12
  Scaleform::GFx::DisplayObjectBase *v7; // r15
  Scaleform::GFx::DisplayList *v8; // rbx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rbp
  signed __int64 v11; // r14
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // r8
  Scaleform::GFx::DisplayObjectBase *v15; // rcx
  signed __int64 v16; // r15
  Scaleform::RefCountNTSImpl *v17; // rsi
  Scaleform::RefCountNTSImpl *v18; // r13
  Scaleform::GFx::DisplayObjectBase *v19; // rcx
  unsigned int v20; // edx
  Scaleform::GFx::DisplayList::DisplayEntry *v21; // rcx
  Scaleform::GFx::DisplayObjectBase *v22; // rsi
  Scaleform::GFx::DisplayObjectBase *v23; // rcx
  char v24; // al
  int v26; // [rsp+20h] [rbp-68h]
  Scaleform::GFx::DisplayList::DisplayEntry val; // [rsp+28h] [rbp-60h]
  __int64 v28; // [rsp+38h] [rbp-50h]
  Scaleform::RefCountNTSImpl *v29; // [rsp+40h] [rbp-48h]
  int v30; // [rsp+48h] [rbp-40h]
  int v31; // [rsp+4Ch] [rbp-3Ch]
  Scaleform::GFx::DisplayObjectBase *ownera; // [rsp+98h] [rbp+10h]
  int v33; // [rsp+A0h] [rbp+18h]
  int v34; // [rsp+A8h] [rbp+20h]

  v34 = depth2;
  ownera = owner;
  v28 = -2i64;
  v5 = depth2;
  v6 = depth1;
  v7 = owner;
  v8 = this;
  if ( depth1 == depth2 )
    return 1;
  v9 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth1);
  v10 = v9;
  if ( v9 < v8->DisplayObjectArray.Data.Size )
  {
    v11 = v9;
    if ( v8->DisplayObjectArray.Data.Data[v9].pCharacter->Depth == v6 && v9 != -1i64 )
    {
      v12 = Scaleform::GFx::DisplayList::FindDisplayIndex(v8, v5);
      v13 = v12;
      v14 = v8->DisplayObjectArray.Data.Size;
      if ( (v10 >= v14 || (v8->DisplayObjectArray.Data.Data[v11].pCharacter->Flags & 0x8000u) == 0)
        && (v12 >= v14 || (v8->DisplayObjectArray.Data.Data[v12].pCharacter->Flags & 0x8000u) == 0) )
      {
        v8->pCachedChar = 0i64;
        if ( v12 < v14 )
        {
          v15 = (Scaleform::GFx::DisplayObjectBase *)v8->DisplayObjectArray.Data.Data;
          val.pCharacter = v15;
          v16 = (signed __int64)v15 + 16 * v12;
          if ( *(_DWORD *)(*(_QWORD *)v16 + 44i64) == v5 )
          {
            v29 = 0i64;
            v17 = (Scaleform::RefCountNTSImpl *)(&v15->vfptr)[v11 * 2];
            v29 = v17;
            if ( v17 )
              ++v17->RefCount;
            v33 = *(&v15->RefCount + 1 * v11);
            v30 = *(&v15->RefCount + 1 * v11);
            v26 = *(&v15->RefCount + 1 * v11 + 1);
            v31 = *(&v15->RefCount + 1 * v11 + 1);
            v18 = *(Scaleform::RefCountNTSImpl **)v16;
            if ( (&v15->vfptr)[v11 * 2] )
            {
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)(&v15->vfptr)[v11 * 2]);
              v15 = val.pCharacter;
            }
            (&v15->vfptr)[v11 * 2] = (Scaleform::RefCountNTSImplCoreVtbl *)v18;
            if ( v18 )
              ++v18->RefCount;
            *(&v15->RefCount + 1 * v11) = *(_DWORD *)(v16 + 8);
            *(&v15->RefCount + 1 * v11 + 1) = *(_DWORD *)(v16 + 12);
            if ( *(_QWORD *)v16 )
              Scaleform::RefCountNTSImpl::Release(*(Scaleform::RefCountNTSImpl **)v16);
            *(_QWORD *)v16 = v17;
            if ( v17 )
              ++v17->RefCount;
            *(_DWORD *)(v16 + 8) = v33;
            *(_DWORD *)(v16 + 12) = v26;
            if ( v17 )
              Scaleform::RefCountNTSImpl::Release(v17);
            Scaleform::GFx::DisplayList::SwapRenderTreeNodes(v8, ownera, v10, v13);
            v19 = v8->DisplayObjectArray.Data.Data[v11].pCharacter;
            v20 = frame;
            v5 = v34;
            if ( v19 )
            {
              v19->Depth = v6;
              v19->CreateFrame = frame + 1;
            }
LABEL_33:
            v23 = v8->DisplayObjectArray.Data.Data[v13].pCharacter;
            if ( v23 )
            {
              v23->Depth = v5;
              v23->CreateFrame = v20 + 1;
            }
            ++v8->ModId;
            v24 = v8->Flags;
            if ( v24 & 2 )
              v8->Flags = v24 | 1;
            return 1;
          }
          v7 = ownera;
        }
        v21 = v8->DisplayObjectArray.Data.Data;
        val.pCharacter = 0i64;
        v22 = v21[v11].pCharacter;
        val.pCharacter = v22;
        if ( v22 )
          ++v22->RefCount;
        val.TreeIndex = v21[v11].TreeIndex;
        val.MaskTreeIndex = v21[v11].MaskTreeIndex;
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(v8, v7, v10);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v8->DisplayObjectArray.Data,
          v10);
        if ( v10 < v13 )
          --v13;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v8->DisplayObjectArray.Data,
          v13,
          &val);
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(v8, v7, v13);
        if ( v22 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v22->vfptr);
        v20 = frame;
        goto LABEL_33;
      }
    }
  }
  return 0;
}

// File Line: 181
// RVA: 0x9123C0
char __fastcall Scaleform::GFx::DisplayList::SwapEntriesAtIndexes(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 origIndex1, unsigned __int64 origIndex2)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // r14
  Scaleform::GFx::DisplayList *v6; // rdi
  Scaleform::GFx::DisplayList::DisplayEntry *v8; // rax
  Scaleform::GFx::DisplayObjectBase *v9; // rbx
  unsigned __int64 v10; // r12
  Scaleform::GFx::DisplayList::DisplayEntry *v11; // r13
  Scaleform::GFx::DisplayList::DisplayEntry *v12; // r15
  Scaleform::GFx::DisplayObjectBase *v13; // rbp
  Scaleform::GFx::DisplayList::DisplayEntry *v14; // r15
  bool v15; // di
  Scaleform::GFx::DisplayObjectBase *ownera; // [rsp+88h] [rbp+10h]
  unsigned int v17; // [rsp+90h] [rbp+18h]
  unsigned int v18; // [rsp+98h] [rbp+20h]

  ownera = owner;
  v4 = origIndex2;
  v5 = origIndex1;
  v6 = this;
  if ( origIndex1 == origIndex2 )
    return 1;
  v8 = this->DisplayObjectArray.Data.Data;
  v9 = this->DisplayObjectArray.Data.Data[origIndex1].pCharacter;
  if ( v9 )
    ++v9->RefCount;
  v17 = v8[origIndex1].TreeIndex;
  v18 = v8[origIndex1].MaskTreeIndex;
  if ( (v9->Flags & 0x8000u) != 0
    || origIndex2 < this->DisplayObjectArray.Data.Size
    && (this->DisplayObjectArray.Data.Data[origIndex2].pCharacter->Flags & 0x8000u) != 0 )
  {
    v15 = 0;
  }
  else
  {
    ++this->ModId;
    v10 = origIndex2;
    v11 = &this->DisplayObjectArray.Data.Data[origIndex2];
    v12 = &this->DisplayObjectArray.Data.Data[origIndex1];
    v13 = v11->pCharacter;
    if ( v12->pCharacter )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->pCharacter->vfptr);
    v12->pCharacter = v13;
    if ( v13 )
      ++v13->RefCount;
    v12->TreeIndex = v11->TreeIndex;
    v12->MaskTreeIndex = v11->MaskTreeIndex;
    v14 = &v6->DisplayObjectArray.Data.Data[v10];
    if ( v14->pCharacter )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v14->pCharacter->vfptr);
    v14->pCharacter = v9;
    ++v9->RefCount;
    v14->TreeIndex = v17;
    v14->MaskTreeIndex = v18;
    v15 = Scaleform::GFx::DisplayList::SwapRenderTreeNodes(v6, ownera, v5, v4);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
  return v15;
}

// File Line: 200
// RVA: 0x8DAAA0
signed __int64 __fastcall Scaleform::GFx::DisplayList::GetLargestDepthInUse(Scaleform::GFx::DisplayList *this)
{
  Scaleform::GFx::DisplayList *v1; // rax
  unsigned __int64 v2; // rcx
  signed __int64 result; // rax

  v1 = this;
  v2 = this->DisplayObjectArray.Data.Size;
  if ( v2 )
    result = (unsigned int)v1->DisplayObjectArray.Data.Data[v2 - 1].pCharacter->Depth;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 208
// RVA: 0x8D6DA0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::DisplayList::GetDisplayObjectByName(Scaleform::GFx::DisplayList *this, Scaleform::GFx::ASString *name, bool caseSensitive)
{
  Scaleform::GFx::ASString *v3; // r13
  Scaleform::GFx::DisplayList *v4; // r15
  signed int v5; // ebx
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::DisplayObject *v8; // rcx
  bool v9; // di
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned __int64 v12; // r12
  unsigned __int64 v13; // rbp
  __int64 v14; // r14
  Scaleform::GFx::DisplayObjectBase *v15; // rdi
  bool v16; // si
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::DisplayObject *v18; // rcx
  Scaleform::GFx::ASString *v19; // rdi
  char v20; // di
  Scaleform::GFx::ASStringNode *v21; // rcx
  unsigned __int64 v22; // r12
  unsigned __int64 v23; // rbp
  __int64 v24; // r14
  Scaleform::GFx::ASString *v25; // rsi
  char v26; // si
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]

  v3 = name;
  v4 = this;
  v5 = 0;
  v6 = name->pNode;
  if ( !name->pNode->Size )
    return 0i64;
  if ( caseSensitive )
  {
    v8 = v4->pCachedChar;
    v9 = 0;
    if ( v8 )
    {
      v5 = 1;
      if ( Scaleform::GFx::DisplayObject::GetName(v8, &result)->pNode == name->pNode )
        v9 = 1;
    }
    if ( v5 & 1 )
    {
      v5 &= 0xFFFFFFFE;
      v10 = result.pNode;
      v11 = result.pNode->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    if ( v9 )
      return v4->pCachedChar;
    v12 = v4->DisplayObjectArray.Data.Size;
    v13 = 0i64;
    if ( !v12 )
      goto LABEL_54;
    v14 = 0i64;
    while ( 1 )
    {
      v15 = v4->DisplayObjectArray.Data.Data[v14].pCharacter;
      v16 = 0;
      if ( v15 )
      {
        if ( v15->Flags & 0x100 )
        {
          v5 |= 2u;
          if ( Scaleform::GFx::DisplayObject::GetName(
                 (Scaleform::GFx::DisplayObject *)v4->DisplayObjectArray.Data.Data[v14].pCharacter,
                 &result)->pNode == v3->pNode )
            v16 = 1;
        }
      }
      if ( v5 & 2 )
      {
        v5 &= 0xFFFFFFFD;
        v17 = result.pNode;
        v11 = result.pNode->RefCount == 1;
        --v17->RefCount;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
      if ( v16 )
        break;
      ++v13;
      ++v14;
      if ( v13 >= v12 )
        goto LABEL_54;
    }
  }
  else
  {
    if ( !v6->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6);
    v18 = v4->pCachedChar;
    if ( !v18 )
      goto LABEL_58;
    v19 = Scaleform::GFx::DisplayObject::GetName(v18, &result);
    v5 = 4;
    if ( !v19->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v19->pNode);
    if ( v3->pNode->pLower == v19->pNode->pLower )
      v20 = 1;
    else
LABEL_58:
      v20 = 0;
    if ( v5 & 4 )
    {
      v5 &= 0xFFFFFFFB;
      v21 = result.pNode;
      v11 = result.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
    if ( v20 )
      return v4->pCachedChar;
    v22 = v4->DisplayObjectArray.Data.Size;
    v23 = 0i64;
    if ( !v22 )
      goto LABEL_54;
    v24 = 0i64;
    while ( 1 )
    {
      v15 = v4->DisplayObjectArray.Data.Data[v24].pCharacter;
      if ( !v15 || !(v15->Flags & 0x100) )
        goto LABEL_59;
      v25 = Scaleform::GFx::DisplayObject::GetName(
              (Scaleform::GFx::DisplayObject *)v4->DisplayObjectArray.Data.Data[v24].pCharacter,
              &result);
      v5 |= 8u;
      if ( !v25->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v25->pNode);
      if ( v3->pNode->pLower == v25->pNode->pLower )
        v26 = 1;
      else
LABEL_59:
        v26 = 0;
      if ( v5 & 8 )
      {
        v5 &= 0xFFFFFFF7;
        v27 = result.pNode;
        v11 = result.pNode->RefCount == 1;
        --v27->RefCount;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      if ( v26 )
        break;
      ++v23;
      ++v24;
      if ( v23 >= v22 )
        goto LABEL_54;
    }
  }
  if ( !v15 )
  {
LABEL_54:
    v4->pCachedChar = 0i64;
    return v4->pCachedChar;
  }
  v4->pCachedChar = (Scaleform::GFx::DisplayObject *)v15;
  return v4->pCachedChar;
}

// File Line: 264
// RVA: 0x8B05B0
void __fastcall Scaleform::GFx::DisplayList::AddDisplayObject(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::DisplayObjectBase *ch, unsigned int addFlags)
{
  int v5; // er14
  unsigned __int64 v6; // r12
  Scaleform::GFx::DisplayObjectBase *v7; // r15
  Scaleform::GFx::DisplayObjectBase *v8; // rbx
  Scaleform::GFx::CharPosInfo *v9; // rbp
  Scaleform::GFx::DisplayList *v10; // rdi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rsi
  Scaleform::Render::TreeNode *v13; // rax
  Scaleform::Render::ContextImpl::EntryData *v14; // rax
  __int128 v15; // xmm1
  __int64 v16; // rdx

  v5 = pos->Depth;
  v6 = this->DisplayObjectArray.Data.Size;
  v7 = owner;
  v8 = ch;
  v9 = pos;
  v10 = this;
  v11 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, pos->Depth);
  v12 = v11;
  v10->pCachedChar = 0i64;
  if ( addFlags & 1 && v11 < v6 && v10->DisplayObjectArray.Data.Data[v11].pCharacter->Depth == v5 )
  {
    Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(v10, v7, v11);
    v12 = Scaleform::GFx::DisplayList::FindDisplayIndex(v10, v5);
  }
  v8->Depth = v5;
  v13 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v8);
  v14 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v13->0, 2u);
  v14[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v9->ColorTransform.M[0][0];
  v14[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v9->ColorTransform.M[1][0];
  v8->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, (unsigned int)&v9->Matrix_1);
  v15 = LODWORD(v9->Ratio);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[18].__vecDelDtor)(v8);
  v8->ClipDepth = v9->ClipDepth;
  v8->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, (unsigned __int8)v9->BlendMode);
  v8->vfptr[56].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, (unsigned int)v9->pFilters.pObject);
  if ( (v9->Flags.Flags >> 9) & 1 )
  {
    LOBYTE(v16) = v9->Visible != 0;
    v8->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, v16);
  }
  ++v10->ModId;
  Scaleform::GFx::DisplayList::AddEntryAtIndex(v10, v7, v12, v8);
  v8->Flags &= 0xEFEFu;
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[73].__vecDelDtor)(v8);
}

// File Line: 352
// RVA: 0x8B0D50
void __fastcall Scaleform::GFx::DisplayList::AddEntryAtIndex(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayObjectBase *v4; // rbx
  unsigned __int64 v5; // rsi
  Scaleform::GFx::DisplayObjectBase *v6; // rbp
  Scaleform::GFx::DisplayList *v7; // rdi
  unsigned __int64 v8; // r8
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // rax
  char v10; // al

  v4 = ch;
  v5 = index;
  v6 = owner;
  v7 = this;
  if ( ch )
    ++ch->RefCount;
  ++this->ModId;
  Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->DisplayObjectArray.Data,
    this->DisplayObjectArray.Data.Size + 1);
  v8 = v7->DisplayObjectArray.Data.Size;
  if ( v5 < v8 - 1 )
    memmove(&v7->DisplayObjectArray.Data.Data[v5 + 1], &v7->DisplayObjectArray.Data.Data[v5], 16 * (v8 - v5 - 1));
  v9 = &v7->DisplayObjectArray.Data.Data[v5];
  if ( v9 )
  {
    v9->pCharacter = v4;
    if ( v4 )
      ++v4->RefCount;
    *(_QWORD *)&v9->TreeIndex = -1i64;
  }
  Scaleform::GFx::DisplayList::InsertIntoRenderTree(v7, v6, v5);
  v10 = v7->Flags;
  if ( v10 & 2 )
    v7->Flags = v10 | 1;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
}

// File Line: 368
// RVA: 0x8EB920
void __fastcall Scaleform::GFx::DisplayList::MoveDisplayObject(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, Scaleform::GFx::CharPosInfo *pos)
{
  int v3; // ebp
  unsigned __int64 v4; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // r14
  Scaleform::GFx::CharPosInfo *v6; // rdi
  Scaleform::GFx::DisplayList *v7; // rsi
  unsigned __int64 v8; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // r8
  Scaleform::GFx::DisplayObjectBase *v10; // rbx
  __int64 v11; // rdx
  __int64 v12; // rdx
  Scaleform::Render::TreeNode *v13; // rax
  Scaleform::Render::ContextImpl::EntryData *v14; // rax
  __int128 v15; // xmm1

  v3 = pos->Depth;
  v4 = this->DisplayObjectArray.Data.Size;
  v5 = owner;
  v6 = pos;
  v7 = this;
  v8 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, pos->Depth);
  if ( v8 < v4 )
  {
    v9 = &v7->DisplayObjectArray.Data.Data[v8];
    v10 = v9->pCharacter;
    if ( v9->pCharacter->Depth == v3 )
    {
      ++v7->ModId;
      v9->pCharacter->Flags &= 0xFFBFu;
      if ( v9->TreeIndex == -1 )
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(v7, v5, v8);
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v10->vfptr[51].__vecDelDtor)(v10) )
      {
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v10->vfptr[52].__vecDelDtor)(v10) )
          return;
        LOBYTE(v12) = 1;
        v10->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, v12);
      }
      if ( (LOBYTE(v6->Flags.Flags) >> 3) & 1 )
      {
        v13 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v10);
        v14 = Scaleform::Render::ContextImpl::Entry::getWritableData(
                (Scaleform::Render::ContextImpl::Entry *)&v13->0,
                2u);
        v14[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v6->ColorTransform.M[0][0];
        v14[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v6->ColorTransform.M[1][0];
      }
      if ( (LOBYTE(v6->Flags.Flags) >> 2) & 1 )
        v10->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, (unsigned int)&v6->Matrix_1);
      if ( SLOBYTE(v6->Flags.Flags) < 0 )
        v10->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, (unsigned __int8)v6->BlendMode);
      if ( (v6->Flags.Flags >> 9) & 1 )
      {
        LOBYTE(v11) = v6->Visible != 0;
        v10->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, v11);
      }
      v10->vfptr[56].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, (unsigned int)v6->pFilters.pObject);
      v15 = LODWORD(v6->Ratio);
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v10->vfptr[18].__vecDelDtor)(v10);
    }
  }
}

// File Line: 433
// RVA: 0x8FFE60
void __fastcall Scaleform::GFx::DisplayList::ReplaceDisplayObject(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayObjectBase *v4; // rdi
  Scaleform::GFx::CharPosInfo *v5; // r14
  Scaleform::GFx::DisplayObjectBase *v6; // r15
  Scaleform::GFx::DisplayList *v7; // rbp
  unsigned __int64 v8; // rbx
  int v9; // er12
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r13
  Scaleform::RefCountNTSImpl **v12; // rbx
  Scaleform::GFx::DisplayObjectBase *v13; // rsi
  Scaleform::Render::Cxform *v14; // rbx
  Scaleform::Render::TreeNode *v15; // rax
  Scaleform::Render::ContextImpl::EntryData *v16; // rax
  signed __int64 v17; // rax
  unsigned int v18; // eax
  __int128 v19; // xmm1
  __int64 v20; // rdx
  Scaleform::RefCountNTSImplCoreVtbl *v21; // rbx
  unsigned __int8 v22; // al
  char v23; // al

  v4 = ch;
  v5 = pos;
  v6 = owner;
  v7 = this;
  v8 = this->DisplayObjectArray.Data.Size;
  v9 = pos->Depth;
  v10 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, pos->Depth);
  v11 = v10;
  if ( v10 >= v8
    || (v12 = (Scaleform::RefCountNTSImpl **)&v7->DisplayObjectArray.Data.Data[v10], *(&(*v12)[2].RefCount + 1) != v9) )
  {
    Scaleform::GFx::DisplayList::AddDisplayObject(v7, v6, v5, v4, 1u);
  }
  else
  {
    ++v7->ModId;
    v13 = (Scaleform::GFx::DisplayObjectBase *)*v12;
    if ( *v12 )
      ++v13->RefCount;
    v4->Depth = v9;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->vfptr[70].__vecDelDtor)(v4);
    HIWORD((*v12)[6].RefCount) &= 0xFFBFu;
    if ( *((_DWORD *)v12 + 2) == -1 )
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(v7, v6, v11);
    if ( *v12 )
      Scaleform::RefCountNTSImpl::Release(*v12);
    *v12 = (Scaleform::RefCountNTSImpl *)&v4->vfptr;
    ++v4->RefCount;
    if ( (LOBYTE(v5->Flags.Flags) >> 3) & 1 )
      v14 = &v5->ColorTransform;
    else
      v14 = Scaleform::GFx::DisplayObjectBase::GetCxform(v13);
    v15 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4);
    v16 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v15->0, 2u);
    v16[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v14->M[0][0];
    v16[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v14->M[1][0];
    if ( (LOBYTE(v5->Flags.Flags) >> 2) & 1 )
      v17 = (signed __int64)&v5->Matrix_1;
    else
      v17 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v13->vfptr[2].__vecDelDtor)(v13);
    v4->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v17);
    if ( SLOBYTE(v5->Flags.Flags) >= 0 )
      v18 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v13->vfptr[15].__vecDelDtor)(v13);
    else
      v18 = (unsigned __int8)v5->BlendMode;
    v4->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v18);
    v19 = LODWORD(v5->Ratio);
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->vfptr[18].__vecDelDtor)(v4);
    v4->ClipDepth = v5->ClipDepth;
    v4->vfptr[56].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, (unsigned int)v5->pFilters.pObject);
    if ( (v5->Flags.Flags >> 9) & 1 )
    {
      LOBYTE(v20) = v5->Visible != 0;
      v4->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v20);
    }
    else
    {
      v21 = v4->vfptr;
      v22 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v13->vfptr[59].__vecDelDtor)(v13);
      v21[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v22);
    }
    Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(v7, v6, v11);
    v23 = v7->Flags;
    if ( v23 & 2 )
      v7->Flags = v23 | 1;
    v7->pCachedChar = 0i64;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v13->vfptr[75].__vecDelDtor)(v13);
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->vfptr[73].__vecDelDtor)(v4);
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
  }
}
    Scaleform::RefCountNTSImp

// File Line: 499
// RVA: 0x900120
void __fastcall Scaleform::GFx::DisplayList::ReplaceDisplayObjectAtIndex(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayObjectBase *v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::GFx::DisplayObjectBase *v6; // r14
  Scaleform::GFx::DisplayList *v7; // rbx
  Scaleform::GFx::DisplayList::DisplayEntry *v8; // rdi
  char v9; // al

  v4 = ch;
  v5 = index;
  v6 = owner;
  v7 = this;
  if ( index < this->DisplayObjectArray.Data.Size )
  {
    ++this->ModId;
    this->pCachedChar = 0i64;
    v8 = &this->DisplayObjectArray.Data.Data[index];
    if ( v8->pCharacter )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v8->pCharacter->vfptr);
    v8->pCharacter = v4;
    if ( v4 )
      ++v4->RefCount;
    if ( v8->TreeIndex == -1 )
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(v7, v6, v5);
    else
      Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(v7, v6, v5);
    v9 = v7->Flags;
    if ( v9 & 2 )
      v7->Flags = v9 | 1;
  }
}

// File Line: 523
// RVA: 0x8FF1A0
void __fastcall Scaleform::GFx::DisplayList::RemoveDisplayObject(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, int depth, __int64 id)
{
  int *v4; // r14
  int v5; // esi
  Scaleform::GFx::DisplayObjectBase *v6; // r15
  Scaleform::GFx::DisplayList *v7; // rdi
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r10
  signed __int64 v11; // rax
  Scaleform::GFx::DisplayObjectBase *v12; // rbx
  int v13; // edx
  Scaleform::GFx::DisplayList::DisplayEntry *v14; // rcx

  v4 = (int *)id;
  v5 = depth;
  v6 = owner;
  v7 = this;
  v8 = this->DisplayObjectArray.Data.Size;
  v9 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  v10 = v9;
  if ( v9 < v8 )
  {
    v11 = v9;
    v12 = v7->DisplayObjectArray.Data.Data[v11].pCharacter;
    if ( v12 )
      ++v12->RefCount;
    if ( v12->Depth == v5 )
    {
      v7->pCachedChar = 0i64;
      ++v7->ModId;
      v13 = *v4;
      if ( *v4 == 0x40000 || (v14 = &v7->DisplayObjectArray.Data.Data[v11], v14->pCharacter->Id.Id == v13) )
      {
LABEL_10:
        Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(v7, v6, v10);
      }
      else
      {
        while ( ++v10 < v8 && v14[1].pCharacter->Depth == v5 )
        {
          v14 = &v7->DisplayObjectArray.Data.Data[v10];
          if ( v14->pCharacter->Id.Id == v13 )
            goto LABEL_10;
        }
      }
    }
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
  }
}

// File Line: 617
// RVA: 0x8FF350
void __fastcall Scaleform::GFx::DisplayList::RemoveEntryAtIndex(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index)
{
  unsigned __int64 v3; // rbx
  Scaleform::GFx::DisplayList *v4; // rdi
  char v5; // al

  v3 = index;
  v4 = this;
  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->DisplayObjectArray.Data,
    v3);
  v5 = v4->Flags;
  ++v4->ModId;
  v4->pCachedChar = 0i64;
  if ( v5 & 2 )
    v4->Flags = v5 | 1;
}

// File Line: 670
// RVA: 0x8BBF70
void __fastcall Scaleform::GFx::DisplayList::Clear(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner)
{
  Scaleform::GFx::DisplayList *v2; // rbx
  Scaleform::GFx::MovieImpl *v3; // rdi
  Scaleform::GFx::DisplayObjectBase *v4; // rsi
  Scaleform::GFx::MovieDefImpl *v5; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // rdi
  Scaleform::RefCountNTSImpl *v7; // rcx

  v2 = this;
  v3 = owner->pASRoot->pMovieImpl;
  v4 = owner;
  v5 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->vfptr[66].__vecDelDtor)(owner);
  Scaleform::GFx::MovieImpl::AddMovieDefToKillList(v3, v5);
  while ( v2->DisplayObjectArray.Data.Size )
  {
    ++v2->ModId;
    v6 = v2->DisplayObjectArray.Data.Data;
    v2->pCachedChar = 0i64;
    ((void (*)(void))v6->pCharacter->vfptr[75].__vecDelDtor)();
    Scaleform::GFx::DisplayList::RemoveFromRenderTree(v2, v4, 0i64);
    v6->pCharacter->pParent = 0i64;
    if ( v2->DisplayObjectArray.Data.Size == 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> *)&v2->DisplayObjectArray.Data.Data,
        v2,
        0i64);
    }
    else
    {
      v7 = (Scaleform::RefCountNTSImpl *)&v2->DisplayObjectArray.Data.Data->pCharacter->vfptr;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      memmove(
        v2->DisplayObjectArray.Data.Data,
        &v2->DisplayObjectArray.Data.Data[1],
        16 * (v2->DisplayObjectArray.Data.Size - 1));
      --v2->DisplayObjectArray.Data.Size;
    }
  }
  v2->pCachedChar = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->DisplayObjectArray.Data,
    0i64);
}

// File Line: 690
// RVA: 0x9150B0
__int64 __fastcall Scaleform::GFx::DisplayList::UnloadAll(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner)
{
  Scaleform::GFx::DisplayList *v2; // rbx
  unsigned __int8 v3; // r13
  unsigned __int64 v4; // rbp
  __int64 v5; // rsi
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // r15
  Scaleform::GFx::DisplayObjectBase *v7; // rdi
  char v8; // r12
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  Scaleform::GFx::DisplayObjectBase *v10; // rdi
  int v11; // er14
  signed __int64 v12; // rax
  char v13; // al
  Scaleform::GFx::DisplayObjectBase *v14; // rcx
  Scaleform::RefCountNTSImpl *v15; // rcx
  char v16; // al
  Scaleform::GFx::DisplayList::DisplayEntry val; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::DisplayObjectBase *v19; // [rsp+78h] [rbp+10h]

  v19 = owner;
  v2 = this;
  this->pCachedChar = 0i64;
  v3 = 1;
  v4 = 0i64;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v5 = 0i64;
    do
    {
      ++v2->ModId;
      v6 = &v2->DisplayObjectArray.Data.Data[v5];
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(v2, owner, v4);
      v7 = v6->pCharacter;
      if ( (LOBYTE(v6->pCharacter->Flags) >> 6) & 1 )
        goto LABEL_33;
      if ( !v7 )
      {
        v14 = v2->DisplayObjectArray.Data.Data[v5].pCharacter;
        if ( v14 )
          v14->pParent = 0i64;
        if ( v2->DisplayObjectArray.Data.Size == 1 )
        {
          Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            &v2->DisplayObjectArray.Data,
            0i64);
        }
        else
        {
          v15 = (Scaleform::RefCountNTSImpl *)&v2->DisplayObjectArray.Data.Data[v5].pCharacter->vfptr;
          if ( v15 )
            Scaleform::RefCountNTSImpl::Release(v15);
          memmove(
            &v2->DisplayObjectArray.Data.Data[v5],
            &v2->DisplayObjectArray.Data.Data[v5 + 1],
            16 * (v2->DisplayObjectArray.Data.Size - v4 - 1));
          --v2->DisplayObjectArray.Data.Size;
        }
        v2->pCachedChar = 0i64;
        v16 = v2->Flags;
        if ( v16 & 2 )
          v2->Flags = v16 | 1;
        goto LABEL_29;
      }
      if ( v7->Flags & 0x1000 || v7->Depth < -1 )
        goto LABEL_33;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v7->vfptr[74].__vecDelDtor)(v6->pCharacter);
      v7->Flags |= 0x1000u;
      if ( v8 )
      {
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v7->vfptr[75].__vecDelDtor)(v7);
        v9 = v2->DisplayObjectArray.Data.Data[v5].pCharacter;
        if ( v9 )
          v9->pParent = 0i64;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v2->DisplayObjectArray.Data,
          v4);
      }
      else
      {
        v10 = v6->pCharacter;
        if ( v6->pCharacter->Depth >= 0 )
        {
          v11 = -1 - v10->Depth;
          val.pCharacter = v6->pCharacter;
          if ( v10 )
            ++v10->RefCount;
          val.TreeIndex = v6->TreeIndex;
          val.MaskTreeIndex = v6->MaskTreeIndex;
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v2->DisplayObjectArray.Data,
            v4);
          v10->Depth = v11;
          v12 = Scaleform::GFx::DisplayList::FindDisplayIndex(v2, v11);
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
            (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v2->DisplayObjectArray.Data,
            v12,
            &val);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
        }
      }
      v2->pCachedChar = 0i64;
      v13 = v2->Flags;
      if ( v13 & 2 )
        v2->Flags = v13 | 1;
      if ( !v8 )
      {
LABEL_33:
        ++v4;
        ++v5;
        v3 = 0;
      }
LABEL_29:
      owner = v19;
    }
    while ( v4 < v2->DisplayObjectArray.Data.Size );
  }
  return v3;
}

// File Line: 717
// RVA: 0x8EB780
void __fastcall Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned int targetFrame)
{
  unsigned int v3; // er15
  Scaleform::GFx::DisplayObjectBase *v4; // r12
  Scaleform::GFx::DisplayList *v5; // r14
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rdi
  __int64 v8; // rsi
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // rax
  Scaleform::GFx::DisplayObjectBase *v10; // rbx

  v3 = targetFrame;
  v4 = owner;
  v5 = this;
  v6 = this->DisplayObjectArray.Data.Size;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = 0i64;
    do
    {
      v9 = v5->DisplayObjectArray.Data.Data;
      v10 = v5->DisplayObjectArray.Data.Data[v8].pCharacter;
      if ( v10 )
        ++v10->RefCount;
      if ( v10->Depth <= 0x3FFFu && v10->CreateFrame > v3 )
      {
        v9[v8].pCharacter->Flags |= 0x40u;
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(v5, v4, v7);
      }
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
      ++v7;
      ++v8;
    }
    while ( v7 < v6 );
  }
}

// File Line: 749
// RVA: 0x9155B0
void __fastcall Scaleform::GFx::DisplayList::UnloadMarkedObjects(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner)
{
  unsigned __int64 v2; // rbx
  Scaleform::GFx::DisplayObjectBase *v3; // rbp
  Scaleform::GFx::DisplayList *v4; // rsi
  __int64 v5; // rdi
  Scaleform::GFx::DisplayObjectBase *v6; // rcx

  v2 = 0i64;
  v3 = owner;
  v4 = this;
  this->pCachedChar = 0i64;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( (LOBYTE(v6->Flags) >> 6) & 1 )
      {
        v6->Flags &= 0xFFBFu;
        if ( Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(v4, v3, v2) )
        {
          --v2;
          --v5;
        }
      }
      ++v2;
      ++v5;
    }
    while ( v2 < v4->DisplayObjectArray.Data.Size );
  }
  ++v4->ModId;
  v4->pCachedChar = 0i64;
}

// File Line: 777
// RVA: 0x9001C0
void __fastcall Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index)
{
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // rsi
  __int64 v5; // rax
  Scaleform::GFx::DisplayObjectBase *v6; // rdi
  __int64 v7; // rbp
  __int64 v8; // rbx
  Scaleform::GFx::MovieImpl *v9; // rbx
  Scaleform::GFx::MovieDefImpl *v10; // rax
  _QWORD *v11; // rdx
  Scaleform::Render::TreeContainer *v12; // rbx
  Scaleform::Render::TreeNode *v13; // rax
  Scaleform::Render::TreeNode *v14; // rax
  unsigned __int64 v15; // rdx
  Scaleform::Render::TreeContainer *v16; // rcx

  v3 = owner;
  v4 = &this->DisplayObjectArray.Data.Data[index];
  if ( (v4->pCharacter->Flags & 0x8000u) != 0 )
  {
    Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, v4->pCharacter, owner);
    return;
  }
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->vfptr[69].__vecDelDtor)(owner);
  v6 = v4->pCharacter;
  v7 = v5;
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[66].__vecDelDtor)(v3);
  if ( ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v6->vfptr[66].__vecDelDtor)(v6) != v8 )
  {
    v9 = v4->pCharacter->pASRoot->pMovieImpl;
    v10 = (Scaleform::GFx::MovieDefImpl *)((__int64 (*)(void))v4->pCharacter->vfptr[66].__vecDelDtor)();
    Scaleform::GFx::MovieImpl::AddMovieDefToKillList(v9, v10);
  }
  v11 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)((v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v7 - (v7 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)(v7
                                                                                       - (v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                                       - 56)
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( *(_BYTE *)v11 & 1 )
    v11 = (_QWORD *)((*v11 & 0xFFFFFFFFFFFFFFFEui64) + 16);
  v12 = (Scaleform::Render::TreeContainer *)v11[v4->TreeIndex];
  if ( v4->MaskTreeIndex == -1 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1]
                                                                                         - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40)
                   + 10i64) >> 4) & 1 )
    {
      v13 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
      Scaleform::Render::TreeNode::SetMaskNode((Scaleform::Render::TreeNode *)&v12->0, v13);
      return;
    }
    Scaleform::Render::TreeContainer::Remove((Scaleform::Render::TreeContainer *)v7, v4->TreeIndex, 1ui64);
    v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    v15 = v4->TreeIndex;
    v16 = (Scaleform::Render::TreeContainer *)v7;
  }
  else
  {
    Scaleform::Render::TreeContainer::Remove(v12, v4->MaskTreeIndex, 1ui64);
    v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    v15 = v4->MaskTreeIndex;
    v16 = v12;
  }
  Scaleform::Render::TreeContainer::Insert(v16, v15, v14);
}

// File Line: 826
// RVA: 0x8FF540
void __fastcall Scaleform::GFx::DisplayList::RemoveFromRenderTree(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index)
{
  unsigned __int64 v3; // r13
  Scaleform::GFx::DisplayObjectBase *v4; // r14
  Scaleform::GFx::DisplayList *v5; // rdi
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // rsi
  Scaleform::GFx::DisplayObjectBase *v7; // rcx
  Scaleform::GFx::MovieImpl *v8; // r8
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rdx
  Scaleform::GFx::MovieImpl::IndirectTransPair *v11; // r9
  Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *v12; // rax
  signed __int64 v13; // rbx
  Scaleform::Render::ContextImpl::Entry *v14; // rcx
  bool v15; // zf
  __int64 v16; // rbx
  Scaleform::GFx::MovieImpl *v17; // rbx
  Scaleform::GFx::MovieDefImpl *v18; // rax
  Scaleform::Render::TreeContainer *v19; // rax
  unsigned __int64 v20; // rdx
  Scaleform::Render::TreeContainer *v21; // r9
  signed int v22; // er12
  unsigned __int64 v23; // r14
  signed __int64 v24; // r15
  Scaleform::GFx::DisplayList::DisplayEntry *v25; // rbp
  unsigned int v26; // eax
  Scaleform::Render::TreeNode *v27; // rax
  Scaleform::Render::TreeNode *v28; // rbx
  unsigned int v29; // eax
  unsigned __int64 v30; // rdx
  signed __int64 v31; // rcx
  unsigned int v32; // eax
  unsigned __int64 v33; // rbx
  Scaleform::Render::TreeContainer *v34; // rax
  unsigned __int64 v35; // rdx
  signed __int64 v36; // rcx
  unsigned int v37; // er8
  Scaleform::Render::TreeContainer *v38; // [rsp+70h] [rbp+8h]
  Scaleform::Render::TreeContainer *v39; // [rsp+80h] [rbp+18h]

  v3 = index;
  v4 = owner;
  v5 = this;
  v6 = &this->DisplayObjectArray.Data.Data[index];
  v7 = v6->pCharacter;
  if ( v6->TreeIndex == -1 )
  {
    if ( (v7->Flags & 0x8000u) != 0 )
    {
      v8 = owner->pASRoot->pMovieImpl;
      v9 = 0i64;
      v10 = v8->IndirectTransformPairs.Data.Size;
      if ( v10 )
      {
        v11 = v8->IndirectTransformPairs.Data.Data;
        v12 = &v11->Obj;
        while ( v12->pObject != v7 )
        {
          ++v9;
          v12 += 4;
          if ( v9 >= v10 )
            return;
        }
        v13 = (signed __int64)&v11[v9];
        v14 = *(Scaleform::Render::ContextImpl::Entry **)v13;
        if ( *(_QWORD *)v13 )
        {
          v15 = v14->RefCount-- == 1;
          if ( v15 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v14);
        }
        *(_QWORD *)v13 = 0i64;
        *(_DWORD *)(v13 + 24) = -1;
      }
    }
  }
  else
  {
    v16 = ((__int64 (__cdecl *)(Scaleform::GFx::DisplayObjectBase *))v7->vfptr[66].__vecDelDtor)(v7);
    if ( v16 != ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->vfptr[66].__vecDelDtor)(v4) )
    {
      v17 = v6->pCharacter->pASRoot->pMovieImpl;
      v18 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__cdecl *)(Scaleform::GFx::DisplayObjectBase *))v6->pCharacter->vfptr[66].__vecDelDtor)(v6->pCharacter);
      Scaleform::GFx::MovieImpl::AddMovieDefToKillList(v17, v18);
    }
    v19 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->vfptr[69].__vecDelDtor)(v4);
    v39 = v19;
    v20 = v6->TreeIndex;
    if ( v6->MaskTreeIndex == -1 )
    {
      v21 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v19, v20);
      v38 = v21;
      v22 = -1;
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1]
                                                                                           - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40)
                     + 10i64) >> 4) & 1 )
      {
        v23 = v3 + 1;
        if ( v3 + 1 < v5->DisplayObjectArray.Data.Size )
        {
          v24 = v23;
          do
          {
            v25 = &v5->DisplayObjectArray.Data.Data[v24];
            v26 = v25->TreeIndex;
            if ( (v26 != v6->TreeIndex || v25->MaskTreeIndex == -1) && v26 != -1 )
              break;
            ++v3;
            if ( v26 != -1 )
            {
              v27 = Scaleform::Render::TreeContainer::GetAt(v21, 0i64);
              v28 = v27;
              if ( v27 )
                ++v27->RefCount;
              Scaleform::Render::TreeContainer::Remove(v38, 0i64, 1ui64);
              v29 = v6->TreeIndex + v25->MaskTreeIndex;
              v25->TreeIndex = v29;
              v25->MaskTreeIndex = -1;
              Scaleform::Render::TreeContainer::Insert(v39, v29, v28);
              ++v22;
              if ( v28 )
              {
                v15 = v28->RefCount-- == 1;
                if ( v15 )
                  Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v28->0);
              }
              v21 = v38;
            }
            ++v23;
            ++v24;
          }
          while ( v23 < v5->DisplayObjectArray.Data.Size );
        }
      }
      Scaleform::Render::TreeContainer::Remove(v39, v22 + v6->TreeIndex + 1, 1ui64);
      v30 = v3 + 1;
      if ( v3 + 1 < v5->DisplayObjectArray.Data.Size )
      {
        v31 = v30;
        do
        {
          v32 = v5->DisplayObjectArray.Data.Data[v31].TreeIndex;
          if ( v32 != -1 )
            v5->DisplayObjectArray.Data.Data[v31].TreeIndex = v22 + v32;
          ++v30;
          ++v31;
        }
        while ( v30 < v5->DisplayObjectArray.Data.Size );
      }
    }
    else
    {
      v33 = v6->MaskTreeIndex;
      v34 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v19, v20);
      Scaleform::Render::TreeContainer::Remove(v34, v33, 1ui64);
      v35 = v3 + 1;
      if ( v3 + 1 < v5->DisplayObjectArray.Data.Size )
      {
        v36 = v35;
        do
        {
          v37 = v5->DisplayObjectArray.Data.Data[v36].TreeIndex;
          if ( v37 != -1 )
          {
            if ( v37 != v6->TreeIndex )
              break;
            --v5->DisplayObjectArray.Data.Data[v36].MaskTreeIndex;
          }
          ++v35;
          ++v36;
        }
        while ( v35 < v5->DisplayObjectArray.Data.Size );
      }
    }
    *(_QWORD *)&v6->TreeIndex = -1i64;
  }
}

// File Line: 922
// RVA: 0x8E6300
void __fastcall Scaleform::GFx::DisplayList::InsertIntoRenderTree(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index)
{
  unsigned __int64 v3; // rbp
  Scaleform::GFx::DisplayObjectBase *v4; // r15
  Scaleform::GFx::DisplayList *v5; // rsi
  unsigned __int64 v6; // r14
  Scaleform::GFx::DisplayList::DisplayEntry *v7; // r12
  Scaleform::Render::TreeNode *v8; // rax
  Scaleform::Render::TreeNode *v9; // r13
  char v10; // r9
  signed __int64 v11; // rbx
  Scaleform::GFx::DisplayList::DisplayEntry *v12; // rdx
  unsigned int *v13; // rcx
  Scaleform::GFx::DisplayList::DisplayEntry *v14; // r8
  unsigned int v15; // edi
  unsigned int *v16; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *v17; // rbx
  signed int v18; // ecx
  Scaleform::Render::TreeContainer *v19; // r14
  Scaleform::Render::TreeNode *v20; // rdi
  bool v21; // zf
  unsigned __int64 v22; // rdx
  signed __int64 v23; // r8
  Scaleform::GFx::DisplayList::DisplayEntry *v24; // rcx
  int v25; // er12
  unsigned __int64 v26; // rbx
  Scaleform::Render::TreeNode *v27; // rdi
  unsigned __int64 v28; // r8
  unsigned int *v29; // rdx
  unsigned int v30; // er13
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // rbp
  signed __int64 v33; // r15
  Scaleform::GFx::DisplayObjectBase *v34; // rdx
  Scaleform::GFx::DisplayList::DisplayEntry *v35; // r14
  Scaleform::GFx::DisplayObjectBase *v36; // rcx
  Scaleform::Render::TreeNode *v37; // rax
  Scaleform::Render::TreeNode *v38; // rdi
  signed __int64 v39; // rcx
  unsigned int v40; // eax
  Scaleform::Render::TreeContainer *v41; // [rsp+20h] [rbp-78h]
  Scaleform::Render::TreeContainer *v42; // [rsp+28h] [rbp-70h]
  Scaleform::Render::TreeContainer *v43; // [rsp+28h] [rbp-70h]
  Scaleform::Render::TreeNode *v44; // [rsp+30h] [rbp-68h]
  Scaleform::GFx::DisplayList::DisplayEntry *v45; // [rsp+38h] [rbp-60h]
  signed int v46; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::DisplayObjectBase *v47; // [rsp+B0h] [rbp+18h]
  unsigned __int64 indexa; // [rsp+B8h] [rbp+20h]

  v3 = index;
  v4 = owner;
  v5 = this;
  v6 = 16 * index;
  v42 = (Scaleform::Render::TreeContainer *)(16 * index);
  v7 = &this->DisplayObjectArray.Data.Data[index];
  v45 = v7;
  if ( (v7->pCharacter->Flags & 0x8000u) == 0 )
  {
    v41 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->vfptr[69].__vecDelDtor)(owner);
    v47 = v7->pCharacter;
    v8 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v7->pCharacter);
    v9 = v8;
    v44 = v8;
    if ( v8 )
      ++v8->RefCount;
    v10 = 0;
    if ( v3 )
    {
      v11 = v5->DisplayObjectArray.Data.Size - 1;
      if ( v3 - 1 < v11 )
        v11 = v3 - 1;
      if ( v11 < 0 )
        goto LABEL_42;
      v12 = v5->DisplayObjectArray.Data.Data;
      v13 = &v5->DisplayObjectArray.Data.Data[v11].TreeIndex;
      while ( *v13 == -1 )
      {
        v13 -= 4;
        if ( --v11 < 0 )
          goto LABEL_42;
      }
      if ( v11 < 0 )
      {
LABEL_42:
        indexa = 0i64;
        v7->TreeIndex = 0;
      }
      else
      {
        v14 = &v12[v11];
        indexa = 0i64;
        if ( !v14->pCharacter->ClipDepth && v14->MaskTreeIndex == -1 )
          goto LABEL_81;
        v15 = 0;
        if ( v11 )
        {
          v16 = &v14->TreeIndex;
          do
          {
            if ( v16[1] == -1 )
            {
              if ( *v16 != -1 )
                break;
            }
            else if ( *v16 != -1 )
            {
              ++v15;
            }
            v16 -= 4;
            --v11;
          }
          while ( v11 );
        }
        v17 = &v12[v11];
        v18 = v47->Depth;
        if ( v18 > v17->pCharacter->ClipDepth )
          goto LABEL_81;
        if ( v18 > v17->pCharacter->Depth || v18 == -1 )
        {
          v7->TreeIndex = v17->TreeIndex;
          v7->MaskTreeIndex = v15;
          v19 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v41, v17->TreeIndex);
          if ( v47->ClipDepth )
          {
            v20 = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&v4->pASRoot->pMovieImpl->RenderContext);
            Scaleform::Render::TreeNode::SetMaskNode(v20, v9);
            Scaleform::Render::TreeContainer::Insert(v19, v7->MaskTreeIndex, v20);
            if ( v20 )
            {
              v21 = v20->RefCount-- == 1;
              if ( v21 )
                Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v20->0);
            }
          }
          else
          {
            Scaleform::Render::TreeContainer::Insert(v19, v15, v9);
          }
          v22 = v3 + 1;
          if ( v3 + 1 < v5->DisplayObjectArray.Data.Size )
          {
            v23 = v22;
            do
            {
              v24 = &v5->DisplayObjectArray.Data.Data[v23];
              if ( v24->pCharacter->Depth > v17->pCharacter->ClipDepth
                || v24->pCharacter->Depth <= v17->pCharacter->Depth )
              {
                break;
              }
              if ( v24->TreeIndex != -1 )
                ++v24->MaskTreeIndex;
              ++v22;
              ++v23;
            }
            while ( v22 < v5->DisplayObjectArray.Data.Size );
          }
          v10 = 1;
          v6 = (unsigned __int64)v42;
        }
        else
        {
LABEL_81:
          v7->TreeIndex = v14->TreeIndex + 1;
        }
      }
    }
    else
    {
      indexa = 0i64;
      v7->TreeIndex = 0;
    }
    v25 = 1;
    v46 = 1;
    if ( !v10 )
    {
      v26 = v3 + 1;
      if ( v47->ClipDepth )
      {
        v27 = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&v4->pASRoot->pMovieImpl->RenderContext);
        v43 = (Scaleform::Render::TreeContainer *)v27;
        Scaleform::Render::TreeNode::SetMaskNode(v27, v9);
        v28 = v5->DisplayObjectArray.Data.Size;
        if ( v26 < v28 )
        {
          v29 = (unsigned int *)((char *)&v5->DisplayObjectArray.Data.Data[1].TreeIndex + v6);
          v30 = *v29;
          if ( *v29 != -1 )
            goto LABEL_82;
          v31 = v3 + 1;
          do
          {
            ++v26;
            ++v3;
            ++v31;
            v29 += 4;
            if ( v31 >= v28 )
              break;
            v30 = *v29;
          }
          while ( *v29 == -1 );
          if ( v30 != -1 )
          {
LABEL_82:
            v32 = v3 + 1;
            if ( v32 < v28 )
            {
              v33 = v32;
              v34 = v47;
              do
              {
                v35 = &v5->DisplayObjectArray.Data.Data[v33];
                v36 = v35->pCharacter;
                if ( v35->pCharacter->Depth > v34->ClipDepth || v36->Depth <= v34->Depth )
                  break;
                ++v26;
                if ( v35->TreeIndex != -1 )
                {
                  if ( v36->ClipDepth )
                    break;
                  v37 = Scaleform::Render::TreeContainer::GetAt(v41, v30);
                  v38 = v37;
                  if ( v37 )
                    ++v37->RefCount;
                  Scaleform::Render::TreeContainer::Remove(v41, v30, 1ui64);
                  v35->TreeIndex = v45->TreeIndex;
                  v35->MaskTreeIndex = indexa;
                  Scaleform::Render::TreeContainer::Insert(v43, (unsigned int)indexa, v38);
                  v25 = v46-- - 1;
                  ++indexa;
                  if ( v38 )
                  {
                    v21 = v38->RefCount-- == 1;
                    if ( v21 )
                      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v38->0);
                  }
                  v34 = v47;
                }
                ++v32;
                ++v33;
              }
              while ( v32 < v5->DisplayObjectArray.Data.Size );
              v27 = (Scaleform::Render::TreeNode *)&v43->0;
            }
          }
          v9 = v44;
        }
        Scaleform::Render::TreeContainer::Insert(v41, v45->TreeIndex, v27);
        if ( v27 )
        {
          v21 = v27->RefCount-- == 1;
          if ( v21 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v27->0);
        }
      }
      else
      {
        Scaleform::Render::TreeContainer::Insert(v41, v45->TreeIndex, v9);
      }
      if ( v26 < v5->DisplayObjectArray.Data.Size )
      {
        v39 = v26;
        do
        {
          v40 = v5->DisplayObjectArray.Data.Data[v39].TreeIndex;
          if ( v40 != -1 )
            v5->DisplayObjectArray.Data.Data[v39].TreeIndex = v25 + v40;
          ++v26;
          ++v39;
        }
        while ( v26 < v5->DisplayObjectArray.Data.Size );
      }
    }
    if ( v9 )
    {
      v21 = v9->RefCount-- == 1;
      if ( v21 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v9->0);
    }
  }
  else
  {
    Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, v7->pCharacter, owner);
  }
}

// File Line: 1091
// RVA: 0x9125D0
char __fastcall Scaleform::GFx::DisplayList::SwapRenderTreeNodes(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index1, unsigned __int64 index2)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // rdi
  Scaleform::GFx::DisplayList::DisplayEntry *v5; // rbx
  Scaleform::Render::TreeNode *v6; // rax
  unsigned int v7; // ecx
  Scaleform::Render::TreeNode *v8; // r12
  Scaleform::Render::TreeContainer *v9; // r15
  unsigned __int64 v10; // r14
  Scaleform::Render::TreeNode *v11; // rax
  unsigned int v12; // ecx
  Scaleform::Render::TreeNode *v13; // r13
  Scaleform::Render::TreeContainer *v14; // rbp
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // rdx
  Scaleform::Render::TreeNode *v17; // r8
  unsigned __int64 v18; // rdx
  Scaleform::Render::TreeContainer *v19; // rcx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  Scaleform::GFx::DisplayList *v25; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::DisplayObjectBase *ownera; // [rsp+78h] [rbp+10h]
  unsigned __int64 index; // [rsp+80h] [rbp+18h]
  unsigned __int64 v28; // [rsp+88h] [rbp+20h]

  v28 = index2;
  index = index1;
  ownera = owner;
  v25 = this;
  v4 = &this->DisplayObjectArray.Data.Data[index1];
  v5 = &this->DisplayObjectArray.Data.Data[index2];
  if ( (v4->pCharacter->Flags & 0x8000u) == 0 && (v5->pCharacter->Flags & 0x8000u) == 0 )
  {
    v6 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    v7 = v4->MaskTreeIndex;
    v8 = v6;
    if ( v7 == -1 )
      v7 = v4->TreeIndex;
    v9 = (Scaleform::Render::TreeContainer *)v6->pParent;
    v10 = v7;
    v11 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5->pCharacter);
    v12 = v5->MaskTreeIndex;
    v13 = v11;
    if ( v12 == -1 )
      v12 = v5->TreeIndex;
    v14 = (Scaleform::Render::TreeContainer *)v11->pParent;
    v15 = v12;
    if ( v4->pCharacter->ClipDepth || v5->pCharacter->ClipDepth )
    {
      v22 = v4->TreeIndex;
      v4->TreeIndex = v5->TreeIndex;
      v5->TreeIndex = v22;
      v23 = v4->MaskTreeIndex;
      v4->MaskTreeIndex = v5->MaskTreeIndex;
      v5->MaskTreeIndex = v23;
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(v25, ownera, index);
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(v25, ownera, v28);
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(v25, ownera, index);
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(v25, ownera, v28);
      return 1;
    }
    if ( v9 == v14 )
    {
      if ( v10 >= v12 )
      {
        Scaleform::Render::TreeContainer::Remove(v14, v12, 1ui64);
        Scaleform::Render::TreeContainer::Remove(v9, v10 - 1, 1ui64);
        Scaleform::Render::TreeContainer::Insert(v14, v15, v8);
        v17 = v13;
        v18 = v10;
        v19 = v9;
LABEL_15:
        Scaleform::Render::TreeContainer::Insert(v19, v18, v17);
        v20 = v4->TreeIndex;
        v4->TreeIndex = v5->TreeIndex;
        v5->TreeIndex = v20;
        v21 = v4->MaskTreeIndex;
        v4->MaskTreeIndex = v5->MaskTreeIndex;
        v5->MaskTreeIndex = v21;
        return 1;
      }
      Scaleform::Render::TreeContainer::Remove(v9, v10, 1ui64);
      v16 = v15 - 1;
    }
    else
    {
      Scaleform::Render::TreeContainer::Remove(v9, v10, 1ui64);
      v16 = v15;
    }
    Scaleform::Render::TreeContainer::Remove(v14, v16, 1ui64);
    Scaleform::Render::TreeContainer::Insert(v9, v10, v13);
    v17 = v8;
    v18 = v15;
    v19 = v14;
    goto LABEL_15;
  }
  return 0;
}

// File Line: 1156
// RVA: 0x915430
char __fastcall Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayObjectBase *owner, unsigned __int64 index)
{
  unsigned __int64 v3; // rbp
  Scaleform::GFx::DisplayList *v4; // rbx
  unsigned __int64 v5; // r14
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // r12
  Scaleform::GFx::DisplayObjectBase *v7; // rdi
  char result; // al
  char v9; // r15
  Scaleform::GFx::DisplayObjectBase *v10; // rdx
  Scaleform::GFx::DisplayObjectBase *v11; // rdi
  int v12; // er14
  signed __int64 v13; // rax
  char v14; // al
  Scaleform::GFx::DisplayObjectBase *v15; // rcx
  char v16; // al
  Scaleform::GFx::DisplayList::DisplayEntry val; // [rsp+28h] [rbp-30h]

  v3 = index;
  v4 = this;
  v5 = index;
  v6 = &this->DisplayObjectArray.Data.Data[index];
  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index);
  v7 = v6->pCharacter;
  if ( (LOBYTE(v6->pCharacter->Flags) >> 6) & 1 )
    return 0;
  if ( v7 )
  {
    if ( v7->Flags & 0x1000 || v7->Depth < -1 )
      return 0;
    v9 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v7->vfptr[74].__vecDelDtor)(v6->pCharacter);
    v7->Flags |= 0x1000u;
    if ( v9 )
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v7->vfptr[75].__vecDelDtor)(v7);
      v10 = v4->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( v10 )
        v10->pParent = 0i64;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->DisplayObjectArray.Data,
        v3);
    }
    else
    {
      v11 = v6->pCharacter;
      if ( v6->pCharacter->Depth >= 0 )
      {
        v12 = -1 - v11->Depth;
        val.pCharacter = v6->pCharacter;
        if ( v11 )
          ++v11->RefCount;
        val.TreeIndex = v6->TreeIndex;
        val.MaskTreeIndex = v6->MaskTreeIndex;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->DisplayObjectArray.Data,
          v3);
        v11->Depth = v12;
        v13 = Scaleform::GFx::DisplayList::FindDisplayIndex(v4, v12);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->DisplayObjectArray.Data,
          v13,
          &val);
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v11->vfptr);
      }
    }
    v4->pCachedChar = 0i64;
    v14 = v4->Flags;
    if ( v14 & 2 )
      v4->Flags = v14 | 1;
    result = v9;
  }
  else
  {
    v15 = v4->DisplayObjectArray.Data.Data[v5].pCharacter;
    if ( v15 )
      v15->pParent = 0i64;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->DisplayObjectArray.Data,
      v3);
    v4->pCachedChar = 0i64;
    v16 = v4->Flags;
    if ( v16 & 2 )
      v4->Flags = v16 | 1;
    result = 1;
  }
  return result;
} if ( v16 & 2 )
      v4->Fla

// File Line: 1230
// RVA: 0x8F3E10
void __fastcall Scaleform::GFx::DisplayList::PropagateMouseEvent(Scaleform::GFx::DisplayList *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rbp
  Scaleform::GFx::DisplayList *v3; // rsi
  signed __int64 i; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // rdi

  v2 = id;
  v3 = this;
  for ( i = this->DisplayObjectArray.Data.Size - 1; i >= 0; --i )
  {
    v5 = v3->DisplayObjectArray.Data.Data[i].pCharacter;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5->vfptr[59].__vecDelDtor)(v5) )
    {
      if ( SLOBYTE(v5->Flags) < 0 )
        v5->vfptr[99].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)v2);
      if ( i >= (signed __int64)v3->DisplayObjectArray.Data.Size )
        i = v3->DisplayObjectArray.Data.Size;
    }
  }
}

// File Line: 1256
// RVA: 0x8F3CA0
void __fastcall Scaleform::GFx::DisplayList::PropagateKeyEvent(Scaleform::GFx::DisplayList *this, Scaleform::GFx::EventId *id, int *pkeyMask)
{
  int *v3; // rbp
  Scaleform::GFx::EventId *v4; // r15
  Scaleform::GFx::DisplayList *v5; // r14
  unsigned __int64 v6; // rdi
  __int64 v7; // rsi
  Scaleform::RefCountNTSImpl *v8; // rbx

  v3 = pkeyMask;
  v4 = id;
  v5 = this;
  v6 = 0i64;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v7 = 0i64;
    do
    {
      v8 = (Scaleform::RefCountNTSImpl *)&v5->DisplayObjectArray.Data.Data[v7].pCharacter->vfptr;
      if ( v8 )
        ++v8->RefCount;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::RefCountNTSImpl *))v8->vfptr[59].__vecDelDtor)(v8) )
      {
        if ( (v8[6].RefCount & 0x800000) != 0 )
          ((void (__fastcall *)(Scaleform::RefCountNTSImpl *, Scaleform::GFx::EventId *, int *))v8->vfptr[101].__vecDelDtor)(
            v8,
            v4,
            v3);
      }
      Scaleform::RefCountNTSImpl::Release(v8);
      ++v6;
      ++v7;
    }
    while ( v6 < v5->DisplayObjectArray.Data.Size );
  }
}

// File Line: 1283
// RVA: 0x919B10
void __fastcall Scaleform::GFx::DisplayList::VisitMembers(Scaleform::GFx::DisplayList *this, Scaleform::GFx::DisplayList::MemberVisitor *pvisitor)
{
  Scaleform::GFx::DisplayList::MemberVisitor *v2; // r14
  Scaleform::GFx::DisplayList *v3; // r15
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx
  Scaleform::GFx::DisplayObjectBase *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v2 = pvisitor;
  v3 = this;
  v4 = this->DisplayObjectArray.Data.Size;
  if ( v4 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( SLOBYTE(v6->Flags) < 0 )
      {
        Scaleform::GFx::DisplayObject::GetName(
          (Scaleform::GFx::DisplayObject *)v3->DisplayObjectArray.Data.Data[v5].pCharacter,
          &result);
        if ( result.pNode->Size )
          v2->vfptr->Visit(v2, &result, (Scaleform::GFx::InteractiveObject *)v6);
        v7 = result.pNode;
        v8 = result.pNode->RefCount == 1;
        --v7->RefCount;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      }
      ++v5;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 1305
// RVA: 0x8D4F80
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayList::GetBounds(Scaleform::GFx::DisplayList *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 v3; // r14
  __int64 v4; // rdi
  Scaleform::Render::Matrix2x4<float> *v5; // r12
  Scaleform::Render::Rect<float> *v6; // rbx
  Scaleform::GFx::DisplayList *v7; // r15
  Scaleform::GFx::DisplayObjectBase *v8; // rsi
  float v9; // xmm1_4
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float v11; // xmm0_4
  int v12; // xmm1_4
  float *v13; // rax
  __int64 v14; // kr00_8
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float *v19; // rax
  float v20; // xmm7_4
  float v21; // xmm9_4
  float v22; // xmm6_4
  float v23; // xmm8_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  char v27; // [rsp+8h] [rbp-29h]
  __int128 v28; // [rsp+18h] [rbp-19h]
  __m128 i; // [rsp+28h] [rbp-9h]

  v3 = this->DisplayObjectArray.Data.Size;
  v4 = 0i64;
  v5 = transform;
  v6 = result;
  v7 = this;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v28 = _xmm;
  for ( i = _xmm; v3; --v3 )
  {
    v8 = v7->DisplayObjectArray.Data.Data[v4].pCharacter;
    if ( v8 )
    {
      v9 = v5->M[0][1];
      v10 = v7->DisplayObjectArray.Data.Data[v4].pCharacter;
      *(float *)&v28 = v5->M[0][0];
      *(_QWORD *)((char *)&v28 + 4) = __PAIR__(LODWORD(v5->M[0][2]), LODWORD(v9));
      v11 = v5->M[1][0];
      HIDWORD(v28) = LODWORD(v5->M[0][3]);
      i.m128_u64[0] = __PAIR__(LODWORD(v5->M[1][1]), LODWORD(v11));
      v12 = LODWORD(v5->M[1][3]);
      i.m128_i32[2] = LODWORD(v5->M[1][2]);
      i.m128_i32[3] = v12;
      v13 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[2].__vecDelDtor)(v10);
      v14 = v28;
      v16 = i.m128_f32[1];
      v15 = i.m128_f32[0];
      *(float *)&v28 = (float)(*(float *)&v28 * *v13) + (float)(*((float *)&v28 + 1) * v13[4]);
      i.m128_f32[0] = (float)(i.m128_f32[0] * *v13) + (float)(i.m128_f32[1] * v13[4]);
      *((float *)&v28 + 1) = (float)(*(float *)&v14 * v13[1]) + (float)(*((float *)&v28 + 1) * v13[5]);
      v17 = v15 * v13[1];
      v18 = i.m128_f32[1] * v13[5];
      DWORD2(v28) = 0;
      *(unsigned __int64 *)((char *)i.m128_u64 + 4) = COERCE_UNSIGNED_INT(v18 + v17);
      *((float *)&v28 + 3) = *((float *)&v28 + 3)
                           + (float)((float)(*(float *)&v14 * v13[3]) + (float)(*((float *)&v14 + 1) * v13[7]));
      i.m128_f32[3] = i.m128_f32[3] + (float)((float)(v16 * v13[7]) + (float)(v15 * v13[3]));
      v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))v8->vfptr[61].__vecDelDtor)(
                       v8,
                       &v27,
                       &v28);
      v20 = *v19;
      v21 = v19[2];
      v22 = v19[1];
      v23 = v19[3];
      if ( *v19 < v21 && v22 < v23 )
      {
        if ( Scaleform::Render::Rect<float>::IsEmpty(v6) )
        {
          v6->x2 = v21;
          v6->y2 = v23;
        }
        else
        {
          if ( v6->x1 <= v20 )
            v20 = v6->x1;
          v24 = v6->x2;
          if ( v24 <= v21 )
            v24 = v21;
          if ( v6->y1 <= v22 )
            v22 = v6->y1;
          v25 = v6->y2;
          if ( v25 <= v23 )
            v25 = v23;
          v6->x2 = v24;
          v6->y2 = v25;
        }
        v6->y1 = v22;
        v6->x1 = v20;
      }
    }
    ++v4;
  }
  return v6;
}

// File Line: 1341
// RVA: 0x8DD1F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayList::GetRectBounds(Scaleform::GFx::DisplayList *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 v3; // r14
  __int64 v4; // rdi
  Scaleform::Render::Matrix2x4<float> *v5; // r12
  Scaleform::Render::Rect<float> *v6; // rbx
  Scaleform::GFx::DisplayList *v7; // r15
  Scaleform::GFx::DisplayObjectBase *v8; // rsi
  float v9; // xmm1_4
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float v11; // xmm0_4
  int v12; // xmm1_4
  float *v13; // rax
  __int64 v14; // kr00_8
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float *v19; // rax
  float v20; // xmm7_4
  float v21; // xmm9_4
  float v22; // xmm6_4
  float v23; // xmm8_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  char v27; // [rsp+8h] [rbp-29h]
  __int128 v28; // [rsp+18h] [rbp-19h]
  __m128 i; // [rsp+28h] [rbp-9h]

  v3 = this->DisplayObjectArray.Data.Size;
  v4 = 0i64;
  v5 = transform;
  v6 = result;
  v7 = this;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v28 = _xmm;
  for ( i = _xmm; v3; --v3 )
  {
    v8 = v7->DisplayObjectArray.Data.Data[v4].pCharacter;
    if ( v8 )
    {
      v9 = v5->M[0][1];
      v10 = v7->DisplayObjectArray.Data.Data[v4].pCharacter;
      *(float *)&v28 = v5->M[0][0];
      *(_QWORD *)((char *)&v28 + 4) = __PAIR__(LODWORD(v5->M[0][2]), LODWORD(v9));
      v11 = v5->M[1][0];
      HIDWORD(v28) = LODWORD(v5->M[0][3]);
      i.m128_u64[0] = __PAIR__(LODWORD(v5->M[1][1]), LODWORD(v11));
      v12 = LODWORD(v5->M[1][3]);
      i.m128_i32[2] = LODWORD(v5->M[1][2]);
      i.m128_i32[3] = v12;
      v13 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[2].__vecDelDtor)(v10);
      v14 = v28;
      v16 = i.m128_f32[1];
      v15 = i.m128_f32[0];
      *(float *)&v28 = (float)(*(float *)&v28 * *v13) + (float)(*((float *)&v28 + 1) * v13[4]);
      i.m128_f32[0] = (float)(i.m128_f32[0] * *v13) + (float)(i.m128_f32[1] * v13[4]);
      *((float *)&v28 + 1) = (float)(*(float *)&v14 * v13[1]) + (float)(*((float *)&v28 + 1) * v13[5]);
      v17 = v15 * v13[1];
      v18 = i.m128_f32[1] * v13[5];
      DWORD2(v28) = 0;
      *(unsigned __int64 *)((char *)i.m128_u64 + 4) = COERCE_UNSIGNED_INT(v18 + v17);
      *((float *)&v28 + 3) = *((float *)&v28 + 3)
                           + (float)((float)(*(float *)&v14 * v13[3]) + (float)(*((float *)&v14 + 1) * v13[7]));
      i.m128_f32[3] = i.m128_f32[3] + (float)((float)(v16 * v13[7]) + (float)(v15 * v13[3]));
      v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))v8->vfptr[62].__vecDelDtor)(
                       v8,
                       &v27,
                       &v28);
      v20 = *v19;
      v21 = v19[2];
      v22 = v19[1];
      v23 = v19[3];
      if ( *v19 < v21 && v22 < v23 )
      {
        if ( Scaleform::Render::Rect<float>::IsEmpty(v6) )
        {
          v6->x2 = v21;
          v6->y2 = v23;
        }
        else
        {
          if ( v6->x1 <= v20 )
            v20 = v6->x1;
          v24 = v6->x2;
          if ( v24 <= v21 )
            v24 = v21;
          if ( v6->y1 <= v22 )
            v22 = v6->y1;
          v25 = v6->y2;
          if ( v25 <= v23 )
            v25 = v23;
          v6->x2 = v24;
          v6->y2 = v25;
        }
        v6->y1 = v22;
        v6->x1 = v20;
      }
    }
    ++v4;
  }
  return v6;
}

// File Line: 1372
// RVA: 0x8CB780
signed __int64 __fastcall Scaleform::GFx::DisplayList::FindDisplayIndex(Scaleform::GFx::DisplayList *this, int depth)
{
  int v2; // er14
  Scaleform::GFx::DisplayList *v3; // rdi
  unsigned __int64 v4; // rbx
  signed __int64 v5; // rbp
  unsigned __int64 v6; // r12
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v7; // rax
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // r13
  __int64 v10; // r15
  Scaleform::GFx::DisplayList::DisplayEntry *v11; // rcx
  int v12; // er8
  unsigned __int64 v13; // rdx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v14; // rcx
  signed __int64 v16; // rcx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v17; // r8
  signed __int64 v18; // rdx
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdx
  Scaleform::GFx::DisplayList::DisplayEntry *v21; // rcx
  int v22; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v23; // [rsp+98h] [rbp+20h]

  v2 = depth;
  v3 = this;
  v4 = 0i64;
  if ( !(this->Flags & 1) )
    goto LABEL_22;
  v5 = -1i64;
  if ( this->DisplayObjectArray.Data.Size <= 0xA )
  {
    v14 = this->DepthToIndexMap;
    if ( !v14 )
      goto LABEL_20;
    v13 = 0i64;
  }
  else
  {
    v6 = 0i64;
    if ( !this->DepthToIndexMap )
    {
      v22 = 322;
      v7 = (Scaleform::GFx::DisplayList::DepthToIndexContainer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayList *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   24i64,
                                                                   &v22,
                                                                   -2i64);
      v23 = v7;
      if ( v7 )
      {
        v7->Array.Data.Data = 0i64;
        v7->Array.Data.Size = 0i64;
        v7->Array.Data.Policy.Capacity = 0i64;
      }
      else
      {
        v7 = 0i64;
      }
      v3->DepthToIndexMap = v7;
    }
    v8 = 0i64;
    v9 = v3->DisplayObjectArray.Data.Size;
    if ( v9 )
    {
      v10 = 0i64;
      do
      {
        v11 = v3->DisplayObjectArray.Data.Data;
        if ( v5 == -1 && v11[v10].pCharacter->Depth >= v2 )
          v5 = v8;
        v12 = v11[v10].pCharacter->Depth;
        if ( v12 != -1 )
          Scaleform::GFx::DisplayList::DepthToIndexContainer::SetElement(v3->DepthToIndexMap, v6++, v12, v8);
        ++v8;
        ++v10;
      }
      while ( v8 < v9 );
    }
    v13 = v6;
    v14 = v3->DepthToIndexMap;
  }
  Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v14->Array.Data,
    v13);
LABEL_20:
  v3->Flags &= 0xFEu;
  if ( v5 != -1 )
    return v5;
LABEL_22:
  if ( !(v3->Flags & 2) )
  {
    v16 = v3->DisplayObjectArray.Data.Size;
    while ( v16 > 0 )
    {
      if ( v3->DisplayObjectArray.Data.Data[(v16 >> 1) + v4].pCharacter->Depth >= v2 )
      {
        v16 >>= 1;
      }
      else
      {
        v4 += (v16 >> 1) + 1;
        v16 += -1 - (v16 >> 1);
      }
    }
    return v4;
  }
  v17 = v3->DepthToIndexMap;
  if ( v17 && v3->DisplayObjectArray.Data.Size > 0xA )
  {
    v18 = v17->Array.Data.Size;
    while ( v18 > 0 )
    {
      v19 = (v18 >> 1) + v4;
      if ( v17->Array.Data.Data[v19].Depth >= v2 )
      {
        v18 >>= 1;
      }
      else
      {
        v4 = v19 + 1;
        v18 += -1 - (v18 >> 1);
      }
    }
    if ( v4 == v17->Array.Data.Size )
      return v3->DisplayObjectArray.Data.Size;
    v20 = v17->Array.Data.Data[v4].Index;
  }
  else
  {
    v20 = v3->DisplayObjectArray.Data.Size;
    if ( v20 )
    {
      v21 = v3->DisplayObjectArray.Data.Data;
      while ( v21->pCharacter->Depth < v2 )
      {
        ++v4;
        ++v21;
        if ( v4 >= v20 )
          return v20;
      }
      return v4;
    }
  }
  return v20;
}

